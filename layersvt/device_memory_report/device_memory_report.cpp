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
#include <string>
#include <string_view>

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

void DeviceMemoryReport::ApplyUsageToHandle(uint64_t handle, const std::string& usage_str) {
    auto alloc_it = object_alloc_size_map_.find(handle);
    if (alloc_it == object_alloc_size_map_.end() || alloc_it->second == 0) return;

    bool is_driver = object_is_driver_map_[handle];
    std::string new_usage_track = (is_driver ? "vulkan.mem.driver.usage." : "vulkan.mem.app.usage.") + usage_str;

    auto& old_usage_track = object_usage_applied_map_[handle];
    if (old_usage_track == new_usage_track) return;

    if (!old_usage_track.empty()) {
        SubtractCounterBytes(old_usage_track, alloc_it->second);
    }
    old_usage_track = new_usage_track;
    AddCounterBytes(new_usage_track, alloc_it->second);
}

void DeviceMemoryReport::RemoveUsageFromHandle(uint64_t handle, uint64_t free_size) {
    auto it = object_usage_applied_map_.find(handle);
    if (it != object_usage_applied_map_.end()) {
        if (!it->second.empty()) {
            SubtractCounterBytes(it->second, free_size);
        }
        object_usage_applied_map_.erase(it);
    }
}

void DeviceMemoryReport::OnBindBufferMemory(uint64_t buffer_handle, uint64_t memory_handle) {
    std::lock_guard<std::mutex> lock(counter_mutex_);
    auto usage_it = object_usage_map_.find(buffer_handle);
    if (usage_it != object_usage_map_.end() && !usage_it->second.empty()) {
        object_usage_map_[memory_handle] = usage_it->second;
        ApplyUsageToHandle(memory_handle, usage_it->second);
    }
}

void DeviceMemoryReport::OnBindImageMemory(uint64_t image_handle, uint64_t memory_handle) {
    OnBindBufferMemory(image_handle, memory_handle);
}

void DeviceMemoryReport::OnCreateImage(uint64_t image_handle, VkImageUsageFlags usage) {
    std::lock_guard<std::mutex> lock(counter_mutex_);
    object_usage_map_[image_handle] = GetUsageCategoryName(true, usage);
}

void DeviceMemoryReport::OnCreateBuffer(uint64_t buffer_handle, VkBufferUsageFlags usage) {
    std::lock_guard<std::mutex> lock(counter_mutex_);
    object_usage_map_[buffer_handle] = GetUsageCategoryName(false, usage);
}

void DeviceMemoryReport::OnDestroyObject(uint64_t object_handle) {
    std::lock_guard<std::mutex> lock(counter_mutex_);
    object_usage_map_.erase(object_handle);
}

void DeviceMemoryReport::OnMemoryReportEvent(const VkDeviceMemoryReportCallbackDataEXT* pCallbackData) {
    std::lock_guard<std::mutex> lock(counter_mutex_);
    bool is_driver = (pCallbackData->flags & VK_DEVICE_MEMORY_REPORT_FLAG_INTERNAL_OBJECT_BIT_EXT) != 0;

    if (pCallbackData->type == VK_DEVICE_MEMORY_REPORT_EVENT_TYPE_ALLOCATE_EXT ||
        pCallbackData->type == VK_DEVICE_MEMORY_REPORT_EVENT_TYPE_IMPORT_EXT) {
        object_alloc_size_map_[pCallbackData->objectHandle] += pCallbackData->size;
        object_is_driver_map_[pCallbackData->objectHandle] = is_driver;

        auto usage_it = object_usage_map_.find(pCallbackData->objectHandle);
        const std::string& usage = (usage_it != object_usage_map_.end() && !usage_it->second.empty())
                                       ? usage_it->second
                                       : "unbound_memory";
        ApplyUsageToHandle(pCallbackData->objectHandle, usage);
    } else if (pCallbackData->type == VK_DEVICE_MEMORY_REPORT_EVENT_TYPE_FREE_EXT ||
               pCallbackData->type == VK_DEVICE_MEMORY_REPORT_EVENT_TYPE_UNIMPORT_EXT) {
        uint64_t free_size = pCallbackData->size;
        auto alloc_it = object_alloc_size_map_.find(pCallbackData->objectHandle);
        if (free_size == 0 && alloc_it != object_alloc_size_map_.end()) {
            free_size = alloc_it->second;
        }

        RemoveUsageFromHandle(pCallbackData->objectHandle, free_size);

        if (alloc_it != object_alloc_size_map_.end()) {
            object_alloc_size_map_.erase(alloc_it);
            object_is_driver_map_.erase(pCallbackData->objectHandle);
        }
    }
}

void DeviceMemoryReport::SetHasMemoryReportCallback(VkDevice device, bool has_callback) {
    std::lock_guard<std::mutex> lock(counter_mutex_);
    has_callback_map_[device] = has_callback;
}

void DeviceMemoryReport::OnAllocateMemory(VkDevice device, VkDeviceMemory memory, VkDeviceSize size) {
    std::lock_guard<std::mutex> lock(counter_mutex_);
    if (has_callback_map_[device]) return;
    memory_size_map_[memory] = size;

    uint64_t handle = reinterpret_cast<uint64_t>(memory);
    object_alloc_size_map_[handle] = size;
    object_is_driver_map_[handle] = false;
    ApplyUsageToHandle(handle, "unbound_memory");
}

void DeviceMemoryReport::OnFreeMemory(VkDevice device, VkDeviceMemory memory) {
    std::lock_guard<std::mutex> lock(counter_mutex_);
    if (has_callback_map_[device]) return;
    auto it = memory_size_map_.find(memory);
    if (it != memory_size_map_.end()) {
        VkDeviceSize size = it->second;
        memory_size_map_.erase(it);

        uint64_t handle = reinterpret_cast<uint64_t>(memory);
        RemoveUsageFromHandle(handle, size);
        object_alloc_size_map_.erase(handle);
        object_is_driver_map_.erase(handle);
    }
}
