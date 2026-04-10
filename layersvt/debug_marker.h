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

#include <map>
#include <string>

struct DebugMarkerInfo {
    uint64_t vk_device;
    int32_t object_type;
    uint64_t handle;
    std::string name;

    DebugMarkerInfo() = default;
    DebugMarkerInfo(uint64_t dev, int32_t type, uint64_t h, const char* n)
        : vk_device(dev), object_type(type), handle(h), name(n) {}
};

class DebugMarker {
   public:
    static DebugMarker& Get();

    void SetVkInstance(VkPhysicalDevice phys_dev, VkInstance instance);
    VkInstance GetVkInstance(VkPhysicalDevice phys_dev);

    void AddDebugMarker(uint64_t device, int32_t type, uint64_t handle, const char* name);
    void EmitAllDebugMarkers();

   private:
    std::mutex map_mutex_;
    std::unordered_map<VkPhysicalDevice, VkInstance> vk_instance_map_;
    std::map<std::pair<int32_t, uint64_t>, DebugMarkerInfo> debug_markers_;
};
