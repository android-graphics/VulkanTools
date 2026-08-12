/* Copyright (C) 2026 Google Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "device_memory_report.h"
#include "device_memory_report_perfetto.h"
#include "perfetto/perfetto.h"
#include <algorithm>
#include <string>
#include <string_view>
#include <vector>

DeviceMemoryReport& DeviceMemoryReport::Get() {
    static DeviceMemoryReport instance;
    return instance;
}

void DeviceMemoryReport::SetVkInstance(VkPhysicalDevice phys_dev, VkInstance instance) {
    std::lock_guard<std::mutex> lock(map_mutex_);
    vk_instance_map_[phys_dev] = instance;
}

VkInstance DeviceMemoryReport::GetVkInstance(VkPhysicalDevice phys_dev) {
    std::lock_guard<std::mutex> lock(map_mutex_);
    auto it = vk_instance_map_.find(phys_dev);
    if (it != vk_instance_map_.end()) return it->second;
    return VK_NULL_HANDLE;
}

void VKAPI_PTR DeviceMemoryReport::MemoryReportCallback(const VkDeviceMemoryReportCallbackDataEXT* pCallbackData, void* pUserData) {
    DeviceMemoryReport::Get().OnMemoryReportEvent(pCallbackData);
}

// Maps Vulkan image or buffer usage flags to a Perfetto memory track usage category name.
static const char* GetUsageCategoryName(bool is_image, uint32_t usage_flags) {
    if (is_image) {
        if (usage_flags & VK_IMAGE_USAGE_DEPTH_STENCIL_ATTACHMENT_BIT) return "depth_stencil_attachment";
        if (usage_flags & VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT) return "color_attachment";
        if (usage_flags & VK_IMAGE_USAGE_SAMPLED_BIT) return "texture";
        if (usage_flags & (VK_IMAGE_USAGE_TRANSFER_SRC_BIT | VK_IMAGE_USAGE_TRANSFER_DST_BIT)) return "transfer_image";
        return "image";
    }
    if (usage_flags & VK_BUFFER_USAGE_VERTEX_BUFFER_BIT) return "vertex_buffer";
    if (usage_flags & VK_BUFFER_USAGE_INDEX_BUFFER_BIT) return "index_buffer";
    if (usage_flags & VK_BUFFER_USAGE_UNIFORM_BUFFER_BIT) return "uniform_buffer";
    if (usage_flags & (VK_BUFFER_USAGE_TRANSFER_SRC_BIT | VK_BUFFER_USAGE_TRANSFER_DST_BIT)) return "staging_buffer";
    return "buffer";
}

// Construct a Perfetto track name for visualizing memory usage by category in the UI.
static std::string GetUsageTrackName(bool is_driver, std::string_view usage) {
    std::string track = is_driver ? "vulkan.mem.driver.usage." : "vulkan.mem.app.usage.";
    track += usage;
    return track;
}

void DeviceMemoryReport::AddCounterBytes(const std::string& track, uint64_t size) {
    uint64_t& bytes = usage_memory_bytes_[track];
    bytes += size;
    TRACE_COUNTER("vulkan", GetCounterTrack(track.c_str()), bytes);
}

void DeviceMemoryReport::SubtractCounterBytes(const std::string& track, uint64_t size) {
    uint64_t& bytes = usage_memory_bytes_[track];
    bytes = (bytes >= size) ? (bytes - size) : 0;
    TRACE_COUNTER("vulkan", GetCounterTrack(track.c_str()), bytes);
}

void DeviceMemoryReport::UpdateAllocationUnboundCounter(uint64_t memory_handle) {
    auto allocation_it = memory_allocations_.find(memory_handle);
    if (allocation_it == memory_allocations_.end()) return;
    auto& allocation = allocation_it->second;

    uint64_t bound_size = 0;
    std::vector<std::pair<VkDeviceSize, VkDeviceSize>> intervals;
    intervals.reserve(allocation.sub_allocations.size());
    for (const auto& suballocation : allocation.sub_allocations) {
        if (suballocation.size > 0) {
            VkDeviceSize end = (suballocation.offset + suballocation.size < suballocation.offset) ? UINT64_MAX : (suballocation.offset + suballocation.size);
            intervals.emplace_back(suballocation.offset, end);
        }
    }
    if (!intervals.empty()) {
        std::sort(intervals.begin(), intervals.end());

        // Overlapping and adjacent intervals are merged:
        // bound_size is calculated as the mathematical union (distinct physical footprint) of all intervals.
        VkDeviceSize current_start = intervals[0].first;
        VkDeviceSize current_end = intervals[0].second;
        for (size_t i = 1; i < intervals.size(); ++i) {
            if (intervals[i].first <= current_end) {
                // Overlapping or adjacent interval: extend current merged range
                current_end = std::max(current_end, intervals[i].second);
            } else {
                // Disjoint interval: add previous merged interval size and begin next range
                bound_size += (current_end - current_start);
                current_start = intervals[i].first;
                current_end = intervals[i].second;
            }
        }
        bound_size += (current_end - current_start);
    }

    uint64_t new_unbound = (allocation.total_size > bound_size) ? (allocation.total_size - bound_size) : 0;
    
    std::string track_name = "unbound_memory";
    auto res_it = resources_.find(allocation.object_handle);
    // If the memory object has an associated resource with a specific usage, use it as the track name.
    if (res_it != resources_.end() && !res_it->second.usage.empty()) {
        track_name = res_it->second.usage;
    }
    std::string new_unbound_track = GetUsageTrackName(allocation.is_driver, track_name);

    // If the unbound memory usage track name or the number of unbound bytes has changed,
    // update the global counters by subtracting the old bytes from the old track 
    // and adding the new bytes to the new track.
    if (allocation.unbound_usage_track != new_unbound_track || allocation.applied_unbound_bytes != new_unbound) {
        if (allocation.applied_unbound_bytes > 0) {
            SubtractCounterBytes(allocation.unbound_usage_track, allocation.applied_unbound_bytes);
        }
        if (new_unbound > 0) {
            AddCounterBytes(new_unbound_track, new_unbound);
        }
    }
    allocation.unbound_usage_track = new_unbound_track;
    allocation.applied_unbound_bytes = new_unbound;
}

void DeviceMemoryReport::RemoveResourceBinding(uint64_t resource_handle) {
    auto mem_it = resource_to_memory_map_.find(resource_handle);
    if (mem_it == resource_to_memory_map_.end()) return;

    uint64_t memory_handle = mem_it->second;
    resource_to_memory_map_.erase(mem_it);

    auto allocation_it = memory_allocations_.find(memory_handle);
    if (allocation_it != memory_allocations_.end()) {
        auto& suballocations = allocation_it->second.sub_allocations;
        // Search by resource handle to identify which specific suballocation to remove,
        // since a single memory block can have multiple resources bound to it.
        for (auto it = suballocations.begin(); it != suballocations.end(); ++it) {
            if (it->resource_handle == resource_handle) {
                SubtractCounterBytes(it->usage_track, it->size);
                suballocations.erase(it);
                break;
            }
        }
        UpdateAllocationUnboundCounter(memory_handle);
    }
}

void DeviceMemoryReport::OnBindBufferMemory(uint64_t buffer_handle, uint64_t memory_handle, VkDeviceSize memory_offset) {
    std::lock_guard<std::mutex> lock(counter_mutex_);
    auto res_it = resources_.find(buffer_handle);
    if (res_it == resources_.end() || res_it->second.usage.empty() || res_it->second.size == 0) return;

    // If the same resource handle is passed more than once, remove stale bindings first.
    RemoveResourceBinding(buffer_handle);

    auto& allocation = memory_allocations_[memory_handle];
    VkDeviceSize res_size = res_it->second.size;
    std::string new_usage_track = GetUsageTrackName(allocation.is_driver, res_it->second.usage);

    // Suballocations represent individual resources (like buffers or images) that are bound 
    // to specific offset regions within a single large memory allocation. 
    // We add a record here to track this specific resource's footprint within the larger memory block.
    allocation.sub_allocations.push_back({ buffer_handle, memory_offset, res_size, new_usage_track });
    resource_to_memory_map_[buffer_handle] = memory_handle;

    // Each distinct virtual resource handle adds its virtual size to its specific category track upon binding.
    AddCounterBytes(new_usage_track, res_size);
    UpdateAllocationUnboundCounter(memory_handle);
}

void DeviceMemoryReport::RemoveAllocationTracking(uint64_t memory_handle) {
    auto allocation_it = memory_allocations_.find(memory_handle);
    if (allocation_it == memory_allocations_.end()) return;

    auto& allocation = allocation_it->second;
    for (const auto& suballocation : allocation.sub_allocations) {
        SubtractCounterBytes(suballocation.usage_track, suballocation.size);
        resource_to_memory_map_.erase(suballocation.resource_handle);
    }
    if (allocation.applied_unbound_bytes > 0) {
        SubtractCounterBytes(allocation.unbound_usage_track, allocation.applied_unbound_bytes);
    }
    memory_allocations_.erase(allocation_it);
}

void DeviceMemoryReport::OnBindImageMemory(uint64_t image_handle, uint64_t memory_handle, VkDeviceSize memory_offset) {
    OnBindBufferMemory(image_handle, memory_handle, memory_offset);
}

void DeviceMemoryReport::OnRecordResourceSize(uint64_t resource_handle, VkDeviceSize size) {
    std::lock_guard<std::mutex> lock(counter_mutex_);
    resources_[resource_handle].size = size;
}

VkDeviceSize DeviceMemoryReport::GetRecordedResourceSize(uint64_t resource_handle) {
    std::lock_guard<std::mutex> lock(counter_mutex_);
    auto it = resources_.find(resource_handle);
    return it != resources_.end() ? it->second.size : 0;
}

void DeviceMemoryReport::OnCreateImage(uint64_t image_handle, VkImageUsageFlags usage) {
    std::lock_guard<std::mutex> lock(counter_mutex_);
    resources_[image_handle].usage = GetUsageCategoryName(true, usage);
    for (const auto& pair : memory_allocations_) {
        if (pair.second.object_handle == image_handle) {
            UpdateAllocationUnboundCounter(pair.first);
        }
    }
}

void DeviceMemoryReport::OnCreateBuffer(uint64_t buffer_handle, VkBufferUsageFlags usage, VkDeviceSize size) {
    std::lock_guard<std::mutex> lock(counter_mutex_);
    resources_[buffer_handle] = { GetUsageCategoryName(false, usage), size };
    for (const auto& pair : memory_allocations_) {
        if (pair.second.object_handle == buffer_handle) {
            UpdateAllocationUnboundCounter(pair.first);
        }
    }
}

void DeviceMemoryReport::OnDestroyObject(uint64_t object_handle) {
    std::lock_guard<std::mutex> lock(counter_mutex_);
    RemoveResourceBinding(object_handle);
    resources_.erase(object_handle);
}

void DeviceMemoryReport::OnMemoryReportEvent(const VkDeviceMemoryReportCallbackDataEXT* pCallbackData) {
    std::lock_guard<std::mutex> lock(counter_mutex_);
    // For internal driver allocations, a single object (e.g. VkImage) might have multiple distinct memory allocations.
    // We must use memoryObjectId as the key so each allocation is tracked separately and can be individually freed.
    // For device memory allocations, objectHandle is the VkDeviceMemory handle, which we use as the key for compatibility.
    uint64_t key = (pCallbackData->objectType == VK_OBJECT_TYPE_DEVICE_MEMORY) ? pCallbackData->objectHandle : pCallbackData->memoryObjectId;

    if (pCallbackData->type == VK_DEVICE_MEMORY_REPORT_EVENT_TYPE_ALLOCATE_EXT ||
        pCallbackData->type == VK_DEVICE_MEMORY_REPORT_EVENT_TYPE_IMPORT_EXT) {
        auto& allocation = memory_allocations_[key];
        allocation.total_size = pCallbackData->size;
        allocation.is_driver = (pCallbackData->flags & VK_DEVICE_MEMORY_REPORT_FLAG_INTERNAL_OBJECT_BIT_EXT) != 0;
        allocation.object_handle = pCallbackData->objectHandle;
        UpdateAllocationUnboundCounter(key);
    } else if (pCallbackData->type == VK_DEVICE_MEMORY_REPORT_EVENT_TYPE_FREE_EXT ||
               pCallbackData->type == VK_DEVICE_MEMORY_REPORT_EVENT_TYPE_UNIMPORT_EXT) {
        RemoveAllocationTracking(key);
    }
}

void DeviceMemoryReport::SetHasMemoryReportCallback(VkDevice device, bool has_callback) {
    std::lock_guard<std::mutex> lock(counter_mutex_);
    has_callback_map_[device] = has_callback;
}

void DeviceMemoryReport::OnAllocateMemory(VkDevice device, VkDeviceMemory memory, VkDeviceSize size) {
    std::lock_guard<std::mutex> lock(counter_mutex_);
    if (has_callback_map_[device]) return;
    uint64_t handle = reinterpret_cast<uint64_t>(memory);
    auto& allocation = memory_allocations_[handle];
    allocation.total_size = size;
    allocation.is_driver = false;
    UpdateAllocationUnboundCounter(handle);
}

void DeviceMemoryReport::OnFreeMemory(VkDevice device, VkDeviceMemory memory) {
    std::lock_guard<std::mutex> lock(counter_mutex_);
    if (has_callback_map_[device]) return;
    RemoveAllocationTracking(reinterpret_cast<uint64_t>(memory));
}
