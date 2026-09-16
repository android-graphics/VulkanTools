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

#pragma once

#include <vulkan/vulkan.h>
#include <mutex>
#include <unordered_map>

namespace layersvt {

/**
 * Thread-safe manager for tracking associations between Vulkan physical
 * devices and their parent instances.
 */
class DeviceInstanceTracker final {
   public:
    DeviceInstanceTracker() = default;
    ~DeviceInstanceTracker() = default;

    DeviceInstanceTracker(const DeviceInstanceTracker&) = delete;
    DeviceInstanceTracker& operator=(const DeviceInstanceTracker&) = delete;
    DeviceInstanceTracker(DeviceInstanceTracker&&) = delete;
    DeviceInstanceTracker& operator=(DeviceInstanceTracker&&) = delete;

    /**
     * Associates a physical device handle with its parent VkInstance.
     */
    void SetVkInstance(VkPhysicalDevice physical_device, VkInstance instance);

    /**
     * Retrieves the VkInstance associated with a physical device.
     * Returns the parent VkInstance on success, or VK_NULL_HANDLE if not registered.
     */
    [[nodiscard]] VkInstance GetVkInstance(VkPhysicalDevice physical_device) const;

    /**
     * Enumerates and tracks all physical devices under an instance.
     */
    void MapPhysicalDevices(VkInstance instance, PFN_vkGetInstanceProcAddr get_instance_proc_addr);

    /**
     * Unmaps all physical devices associated with an instance.
     */
    void UnmapPhysicalDevices(VkInstance instance);

   private:
    mutable std::mutex mutex_;
    std::unordered_map<VkPhysicalDevice, VkInstance> physical_device_to_instance_map_;
};

}  // namespace layersvt
