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

#include "device_instance_tracker.h"
#include <algorithm>
#include <cassert>
#include <mutex>
#include <vector>

namespace layersvt {

void DeviceInstanceTracker::SetVkInstance(VkPhysicalDevice physical_device, VkInstance instance) {
    assert(physical_device != VK_NULL_HANDLE);
    assert(instance != VK_NULL_HANDLE);
    std::lock_guard<std::mutex> lock(mutex_);
    physical_device_to_instance_map_[physical_device] = instance;
}

VkInstance DeviceInstanceTracker::GetVkInstance(VkPhysicalDevice physical_device) const {
    assert(physical_device != VK_NULL_HANDLE);
    std::lock_guard<std::mutex> lock(mutex_);
    auto device_iterator = physical_device_to_instance_map_.find(physical_device);
    if (device_iterator != physical_device_to_instance_map_.end()) {
        return device_iterator->second;
    }
    return VK_NULL_HANDLE;
}

void DeviceInstanceTracker::MapPhysicalDevices(VkInstance instance, PFN_vkGetInstanceProcAddr get_instance_proc_addr) {
    assert(instance != VK_NULL_HANDLE);
    assert(get_instance_proc_addr != nullptr);
    auto enumerate_physical_devices =
        reinterpret_cast<PFN_vkEnumeratePhysicalDevices>(get_instance_proc_addr(instance, "vkEnumeratePhysicalDevices"));
    if (!enumerate_physical_devices) {
        return;
    }

    uint32_t physical_device_count = 0;
    VkResult result = enumerate_physical_devices(instance, &physical_device_count, nullptr);
    if (result == VK_SUCCESS && physical_device_count > 0) {
        std::vector<VkPhysicalDevice> physical_devices(physical_device_count);
        result = enumerate_physical_devices(instance, &physical_device_count, physical_devices.data());
        if (result == VK_SUCCESS || result == VK_INCOMPLETE) {
            std::lock_guard<std::mutex> lock(mutex_);
            uint32_t valid_device_count = std::min(physical_device_count, static_cast<uint32_t>(physical_devices.size()));
            for (uint32_t i = 0; i < valid_device_count; ++i) {
                // Ensure enumerated handles are valid before insertion to match SetVkInstance invariants.
                assert(physical_devices[i] != VK_NULL_HANDLE);
                physical_device_to_instance_map_[physical_devices[i]] = instance;
            }
        }
    }
}

void DeviceInstanceTracker::UnmapPhysicalDevices(VkInstance instance) {
    assert(instance != VK_NULL_HANDLE);
    std::lock_guard<std::mutex> lock(mutex_);
    std::erase_if(physical_device_to_instance_map_,
                  [instance](const auto& entry) { return entry.second == instance; });
}

}  // namespace layersvt
