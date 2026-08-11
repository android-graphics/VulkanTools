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
#include <string>

#ifndef VK_DEVICE_MEMORY_REPORT_FLAG_INTERNAL_OBJECT_BIT_EXT
#define VK_DEVICE_MEMORY_REPORT_FLAG_INTERNAL_OBJECT_BIT_EXT 0x00000001
#endif

/**
 * The DeviceMemoryReport class is responsible for tracking Vulkan device memory
 * allocations and object associations, sending live memory usage counters to Perfetto traces.
 *
 * It tracks allocations per object handle, categorizing memory by usage
 * types (e.g., textures, surfaces, buffers).
 *
 * How it works:
 * The layer intercepts Vulkan memory allocation and object creation events, using either
 * VK_EXT_device_memory_report callbacks (when supported by the underlying driver) or falling back
 * to direct allocation intercepts (vkAllocateMemory/vkFreeMemory).
 * Object bindings (vkBindBufferMemory, vkBindImageMemory) are tracked to attribute memory allocations to usage categories.
 *
 * Track Categories:
 * Memory usage counters are reported to Perfetto under:
 * - Driver vs Application allocations (e.g., vulkan.mem.driver.* vs vulkan.mem.app.*)
 * - Usages (vulkan.mem.*.usage.<category>)
 *
 * This class is a singleton and provides thread-safe access to its state.
 */
class DeviceMemoryReport {
   public:
    /**
     * @brief Returns the singleton instance of the DeviceMemoryReport class.
     * @return Reference to the DeviceMemoryReport singleton.
     */
    static DeviceMemoryReport& Get();

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

    /**
     * @brief Static callback invoked by the VK_EXT_device_memory_report extension.
     * @param pCallbackData Pointer to the memory report callback data structure.
     * @param pUserData User data pointer (unused).
     */
    static void VKAPI_PTR MemoryReportCallback(const VkDeviceMemoryReportCallbackDataEXT* pCallbackData, void* pUserData);

    /**
     * @brief Processes a device memory report event received from the Vulkan driver callback.
     * @param pCallbackData Pointer to the memory report callback data structure.
     */
    void OnMemoryReportEvent(const VkDeviceMemoryReportCallbackDataEXT* pCallbackData);

    /**
     * @brief Sets whether a Vulkan device active callback is installed for VK_EXT_device_memory_report.
     * @param device The Vulkan device handle.
     * @param has_callback True if driver callback is active for the device, false otherwise.
     */
    void SetHasMemoryReportCallback(VkDevice device, bool has_callback);

    /**
     * @brief Handles fallback memory allocation tracking when driver callback is unavailable.
     * @param device The Vulkan device handle.
     * @param memory The VkDeviceMemory handle being allocated.
     * @param size The size of the allocation in bytes.
     */
    void OnAllocateMemory(VkDevice device, VkDeviceMemory memory, VkDeviceSize size);

    /**
     * @brief Handles fallback memory free tracking when driver callback is unavailable.
     * @param device The Vulkan device handle.
     * @param memory The VkDeviceMemory handle being freed.
     */
    void OnFreeMemory(VkDevice device, VkDeviceMemory memory);

    /**
     * @brief Tracks binding of buffer memory to correlate buffer usage with memory allocations.
     * @param buffer_handle The 64-bit handle of the Vulkan buffer.
     * @param memory_handle The 64-bit handle of the Vulkan device memory.
     */
    void OnBindBufferMemory(uint64_t buffer_handle, uint64_t memory_handle);

    /**
     * @brief Tracks binding of image memory to correlate image usage with memory allocations.
     * @param image_handle The 64-bit handle of the Vulkan image.
     * @param memory_handle The 64-bit handle of the Vulkan device memory.
     */
    void OnBindImageMemory(uint64_t image_handle, uint64_t memory_handle);

    /**
     * @brief Tracks creation of a Vulkan image and its usage flags.
     * @param image_handle The 64-bit handle of the Vulkan image.
     * @param usage Usage flags for the created image.
     */
    void OnCreateImage(uint64_t image_handle, VkImageUsageFlags usage);

    /**
     * @brief Tracks creation of a Vulkan buffer and its usage flags.
     * @param buffer_handle The 64-bit handle of the Vulkan buffer.
     * @param usage Usage flags for the created buffer.
     */
    void OnCreateBuffer(uint64_t buffer_handle, VkBufferUsageFlags usage);

    /**
     * @brief Handles destruction of a Vulkan object, cleaning up tracked usage state.
     * @param object_handle The 64-bit handle of the destroyed Vulkan object.
     */
    void OnDestroyObject(uint64_t object_handle);

   private:
    /**
     * @brief Applies a usage category track counter update for an object allocation handle.
     * @param handle The 64-bit handle of the object or memory allocation.
     * @param usage_str The usage category string.
     */
    void ApplyUsageToHandle(uint64_t handle, const std::string& usage_str);

    /**
     * @brief Removes a usage category track counter update for a freed object allocation handle.
     * @param handle The 64-bit handle of the object or memory allocation.
     * @param free_size The number of bytes being freed.
     */
    void RemoveUsageFromHandle(uint64_t handle, uint64_t free_size);

    /**
     * @brief Increments trace counter for a memory track.
     */
    void AddCounterBytes(const std::string& track, uint64_t size);

    /**
     * @brief Decrements trace counter for a memory track with underflow protection.
     */
    void SubtractCounterBytes(const std::string& track, uint64_t size);

    /**
     * @brief Mutex protecting access to the physical device to instance mapping table.
     */
    std::mutex map_mutex_;

    /**
     * @brief Maps a physical device handle to its corresponding Vulkan instance handle.
     */
    std::unordered_map<VkPhysicalDevice, VkInstance> vk_instance_map_;

    /**
     * @brief Mutex protecting access to memory tracking tables and counter states.
     */
    std::mutex counter_mutex_;

    /**
     * @brief Maps a Vulkan device handle to a boolean indicating if driver memory report callback is active.
     */
    std::unordered_map<VkDevice, bool> has_callback_map_;

    /**
     * @brief Maps a device memory handle to its allocation size in bytes for fallback tracking.
     */
    std::unordered_map<VkDeviceMemory, VkDeviceSize> memory_size_map_;

    /**
     * @brief Maps an object handle to its total allocated memory size in bytes.
     */
    std::unordered_map<uint64_t, uint64_t> object_alloc_size_map_;

    /**
     * @brief Maps an object handle to a boolean indicating if it is a driver-internal allocation.
     */
    std::unordered_map<uint64_t, bool> object_is_driver_map_;

    /**
     * @brief Maps an object handle to its determined usage category string.
     */
    std::unordered_map<uint64_t, std::string> object_usage_map_;

    /**
     * @brief Maps an object handle to the usage track string currently applied to it.
     */
    std::unordered_map<uint64_t, std::string> object_usage_applied_map_;

    /**
     * @brief Maps a usage track name to its current total memory usage in bytes.
     */
    std::unordered_map<std::string, uint64_t> usage_memory_bytes_;
};
