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



/**
 * The DebugMarker class is responsible for storing and managing debug marker
 * information associated with Vulkan objects.
 *
 * This class is a singleton and provides thread-safe access to its state.
 */
class DebugMarker {
   public:
    /**
     * @brief Returns the singleton instance of the DebugMarker class.
     * @return Reference to the DebugMarker singleton.
     */
    static DebugMarker& Get();

    /**
     * @brief Sets or updates the name associated with a Vulkan object.
     * @param device The handle of the Vulkan device that owns the object.
     * @param type The type of the Vulkan object (represented as int32_t).
     * @param handle The handle of the Vulkan object.
     * @param name The name to associate with the object.
     */
    void SetDebugObjectName(uint64_t device, int32_t type, uint64_t handle, const char* name);
    
    /**
     * @brief Emits all stored debug markers to the tracing system.
     */
    void EmitAllDebugMarkers();

    /**
     * @brief Clears all stored debug markers and instance mappings.
     */
    void Clear();
    
    /**
     * @brief Checks if a debug name is stored for a given object.
     */
    bool HasDebugObjectName(int32_t type, uint64_t handle, const std::string& name);

    /**
     * @brief Associates a Vulkan physical device with its corresponding instance.
     * @param phys_dev The Vulkan physical device.
     * @param instance The Vulkan instance.
     */
    void SetVkInstance(VkPhysicalDevice phys_dev, VkInstance instance);

    /**
     * @brief Retrieves the Vulkan instance associated with a given physical device.
     * @param phys_dev The Vulkan physical device.
     * @return The associated Vulkan instance.
     */
    VkInstance GetVkInstance(VkPhysicalDevice phys_dev);


   private:
    struct DebugObjectName {
        uint64_t vk_device;
        int32_t object_type;
        uint64_t handle;
        std::string name;

        DebugObjectName() = default;
        DebugObjectName(uint64_t dev, int32_t type, uint64_t h, const std::string& n)
            : vk_device(dev), object_type(type), handle(h), name(n) {}
    };

    std::mutex mutex_;
    /**
     * @brief Maps a physical device handle to its corresponding Vulkan instance handle.
     */
    std::unordered_map<VkPhysicalDevice, VkInstance> vk_instance_map_;
    /**
     * @brief Maps a pair of (object_type, object_handle) to its debug name information.
     * We use a pair as the key because handles are not guaranteed to be unique across different object types.
     */
    std::map<std::pair<int32_t, uint64_t>, DebugObjectName> debug_object_names_;
};
