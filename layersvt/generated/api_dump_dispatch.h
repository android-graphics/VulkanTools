
/* Copyright (c) 2015-2026 Valve Corporation
 * Copyright (c) 2015-2026 LunarG, Inc.
 * Copyright (c) 2015-2017, 2019, 2021 Google Inc.
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
 *
 */

/*
 * This file is generated from the Khronos Vulkan XML API Registry.
 */

#include "api_dump_handwritten_functions.h"

// Autogen instance functions

template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkDestroyInstance(VkInstance instance, const VkAllocationCallbacks* pAllocator) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkDestroyInstance\n";
    }
    auto dispatch_key = get_dispatch_key(instance);
    instance_dispatch_table(instance)->DestroyInstance(instance, pAllocator);
    destroy_instance_dispatch_table(dispatch_key);
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkEnumeratePhysicalDevices(VkInstance instance, uint32_t* pPhysicalDeviceCount, VkPhysicalDevice* pPhysicalDevices) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkEnumeratePhysicalDevices\n";
    }
    VkResult result = instance_dispatch_table(instance)->EnumeratePhysicalDevices(instance, pPhysicalDeviceCount, pPhysicalDevices);

    if (pPhysicalDeviceCount != nullptr && pPhysicalDevices != nullptr) {
        for (uint32_t i = 0; i < *pPhysicalDeviceCount; i++) {
            ApiDumpInstance::current().set_vk_instance(pPhysicalDevices[i], instance);
        }
    }
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceFeatures(VkPhysicalDevice physicalDevice, VkPhysicalDeviceFeatures* pFeatures) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetPhysicalDeviceFeatures\n";
    }
    instance_dispatch_table(physicalDevice)->GetPhysicalDeviceFeatures(physicalDevice, pFeatures);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceFormatProperties(VkPhysicalDevice physicalDevice, VkFormat format, VkFormatProperties* pFormatProperties) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetPhysicalDeviceFormatProperties\n";
    }
    instance_dispatch_table(physicalDevice)->GetPhysicalDeviceFormatProperties(physicalDevice, format, pFormatProperties);
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceImageFormatProperties(VkPhysicalDevice physicalDevice, VkFormat format, VkImageType type, VkImageTiling tiling, VkImageUsageFlags usage, VkImageCreateFlags flags, VkImageFormatProperties* pImageFormatProperties) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetPhysicalDeviceImageFormatProperties\n";
    }
    VkResult result = instance_dispatch_table(physicalDevice)->GetPhysicalDeviceImageFormatProperties(physicalDevice, format, type, tiling, usage, flags, pImageFormatProperties);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceProperties(VkPhysicalDevice physicalDevice, VkPhysicalDeviceProperties* pProperties) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetPhysicalDeviceProperties\n";
    }
    instance_dispatch_table(physicalDevice)->GetPhysicalDeviceProperties(physicalDevice, pProperties);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceQueueFamilyProperties(VkPhysicalDevice physicalDevice, uint32_t* pQueueFamilyPropertyCount, VkQueueFamilyProperties* pQueueFamilyProperties) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetPhysicalDeviceQueueFamilyProperties\n";
    }
    instance_dispatch_table(physicalDevice)->GetPhysicalDeviceQueueFamilyProperties(physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceMemoryProperties(VkPhysicalDevice physicalDevice, VkPhysicalDeviceMemoryProperties* pMemoryProperties) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetPhysicalDeviceMemoryProperties\n";
    }
    instance_dispatch_table(physicalDevice)->GetPhysicalDeviceMemoryProperties(physicalDevice, pMemoryProperties);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceSparseImageFormatProperties(VkPhysicalDevice physicalDevice, VkFormat format, VkImageType type, VkSampleCountFlagBits samples, VkImageUsageFlags usage, VkImageTiling tiling, uint32_t* pPropertyCount, VkSparseImageFormatProperties* pProperties) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetPhysicalDeviceSparseImageFormatProperties\n";
    }
    instance_dispatch_table(physicalDevice)->GetPhysicalDeviceSparseImageFormatProperties(physicalDevice, format, type, samples, usage, tiling, pPropertyCount, pProperties);
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkEnumeratePhysicalDeviceGroups(VkInstance instance, uint32_t* pPhysicalDeviceGroupCount, VkPhysicalDeviceGroupProperties* pPhysicalDeviceGroupProperties) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkEnumeratePhysicalDeviceGroups\n";
    }
    VkResult result = instance_dispatch_table(instance)->EnumeratePhysicalDeviceGroups(instance, pPhysicalDeviceGroupCount, pPhysicalDeviceGroupProperties);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceFeatures2(VkPhysicalDevice physicalDevice, VkPhysicalDeviceFeatures2* pFeatures) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetPhysicalDeviceFeatures2\n";
    }
    instance_dispatch_table(physicalDevice)->GetPhysicalDeviceFeatures2(physicalDevice, pFeatures);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceProperties2(VkPhysicalDevice physicalDevice, VkPhysicalDeviceProperties2* pProperties) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetPhysicalDeviceProperties2\n";
    }
    instance_dispatch_table(physicalDevice)->GetPhysicalDeviceProperties2(physicalDevice, pProperties);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceFormatProperties2(VkPhysicalDevice physicalDevice, VkFormat format, VkFormatProperties2* pFormatProperties) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetPhysicalDeviceFormatProperties2\n";
    }
    instance_dispatch_table(physicalDevice)->GetPhysicalDeviceFormatProperties2(physicalDevice, format, pFormatProperties);
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceImageFormatProperties2(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceImageFormatInfo2* pImageFormatInfo, VkImageFormatProperties2* pImageFormatProperties) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetPhysicalDeviceImageFormatProperties2\n";
    }
    VkResult result = instance_dispatch_table(physicalDevice)->GetPhysicalDeviceImageFormatProperties2(physicalDevice, pImageFormatInfo, pImageFormatProperties);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceQueueFamilyProperties2(VkPhysicalDevice physicalDevice, uint32_t* pQueueFamilyPropertyCount, VkQueueFamilyProperties2* pQueueFamilyProperties) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetPhysicalDeviceQueueFamilyProperties2\n";
    }
    instance_dispatch_table(physicalDevice)->GetPhysicalDeviceQueueFamilyProperties2(physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceMemoryProperties2(VkPhysicalDevice physicalDevice, VkPhysicalDeviceMemoryProperties2* pMemoryProperties) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetPhysicalDeviceMemoryProperties2\n";
    }
    instance_dispatch_table(physicalDevice)->GetPhysicalDeviceMemoryProperties2(physicalDevice, pMemoryProperties);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceSparseImageFormatProperties2(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceSparseImageFormatInfo2* pFormatInfo, uint32_t* pPropertyCount, VkSparseImageFormatProperties2* pProperties) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetPhysicalDeviceSparseImageFormatProperties2\n";
    }
    instance_dispatch_table(physicalDevice)->GetPhysicalDeviceSparseImageFormatProperties2(physicalDevice, pFormatInfo, pPropertyCount, pProperties);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceExternalBufferProperties(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalBufferInfo* pExternalBufferInfo, VkExternalBufferProperties* pExternalBufferProperties) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetPhysicalDeviceExternalBufferProperties\n";
    }
    instance_dispatch_table(physicalDevice)->GetPhysicalDeviceExternalBufferProperties(physicalDevice, pExternalBufferInfo, pExternalBufferProperties);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceExternalFenceProperties(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalFenceInfo* pExternalFenceInfo, VkExternalFenceProperties* pExternalFenceProperties) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetPhysicalDeviceExternalFenceProperties\n";
    }
    instance_dispatch_table(physicalDevice)->GetPhysicalDeviceExternalFenceProperties(physicalDevice, pExternalFenceInfo, pExternalFenceProperties);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceExternalSemaphoreProperties(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalSemaphoreInfo* pExternalSemaphoreInfo, VkExternalSemaphoreProperties* pExternalSemaphoreProperties) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetPhysicalDeviceExternalSemaphoreProperties\n";
    }
    instance_dispatch_table(physicalDevice)->GetPhysicalDeviceExternalSemaphoreProperties(physicalDevice, pExternalSemaphoreInfo, pExternalSemaphoreProperties);
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceToolProperties(VkPhysicalDevice physicalDevice, uint32_t* pToolCount, VkPhysicalDeviceToolProperties* pToolProperties) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetPhysicalDeviceToolProperties\n";
    }
    VkResult result = instance_dispatch_table(physicalDevice)->GetPhysicalDeviceToolProperties(physicalDevice, pToolCount, pToolProperties);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkDestroySurfaceKHR(VkInstance instance, VkSurfaceKHR surface, const VkAllocationCallbacks* pAllocator) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkDestroySurfaceKHR\n";
    }
    instance_dispatch_table(instance)->DestroySurfaceKHR(instance, surface, pAllocator);
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceSurfaceSupportKHR(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, VkSurfaceKHR surface, VkBool32* pSupported) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetPhysicalDeviceSurfaceSupportKHR\n";
    }
    VkResult result = instance_dispatch_table(physicalDevice)->GetPhysicalDeviceSurfaceSupportKHR(physicalDevice, queueFamilyIndex, surface, pSupported);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceSurfaceCapabilitiesKHR(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, VkSurfaceCapabilitiesKHR* pSurfaceCapabilities) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetPhysicalDeviceSurfaceCapabilitiesKHR\n";
    }
    VkResult result = instance_dispatch_table(physicalDevice)->GetPhysicalDeviceSurfaceCapabilitiesKHR(physicalDevice, surface, pSurfaceCapabilities);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceSurfaceFormatsKHR(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, uint32_t* pSurfaceFormatCount, VkSurfaceFormatKHR* pSurfaceFormats) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetPhysicalDeviceSurfaceFormatsKHR\n";
    }
    VkResult result = instance_dispatch_table(physicalDevice)->GetPhysicalDeviceSurfaceFormatsKHR(physicalDevice, surface, pSurfaceFormatCount, pSurfaceFormats);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceSurfacePresentModesKHR(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, uint32_t* pPresentModeCount, VkPresentModeKHR* pPresentModes) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetPhysicalDeviceSurfacePresentModesKHR\n";
    }
    VkResult result = instance_dispatch_table(physicalDevice)->GetPhysicalDeviceSurfacePresentModesKHR(physicalDevice, surface, pPresentModeCount, pPresentModes);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDevicePresentRectanglesKHR(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, uint32_t* pRectCount, VkRect2D* pRects) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetPhysicalDevicePresentRectanglesKHR\n";
    }
    VkResult result = instance_dispatch_table(physicalDevice)->GetPhysicalDevicePresentRectanglesKHR(physicalDevice, surface, pRectCount, pRects);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceDisplayPropertiesKHR(VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount, VkDisplayPropertiesKHR* pProperties) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetPhysicalDeviceDisplayPropertiesKHR\n";
    }
    VkResult result = instance_dispatch_table(physicalDevice)->GetPhysicalDeviceDisplayPropertiesKHR(physicalDevice, pPropertyCount, pProperties);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceDisplayPlanePropertiesKHR(VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount, VkDisplayPlanePropertiesKHR* pProperties) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetPhysicalDeviceDisplayPlanePropertiesKHR\n";
    }
    VkResult result = instance_dispatch_table(physicalDevice)->GetPhysicalDeviceDisplayPlanePropertiesKHR(physicalDevice, pPropertyCount, pProperties);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkGetDisplayPlaneSupportedDisplaysKHR(VkPhysicalDevice physicalDevice, uint32_t planeIndex, uint32_t* pDisplayCount, VkDisplayKHR* pDisplays) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetDisplayPlaneSupportedDisplaysKHR\n";
    }
    VkResult result = instance_dispatch_table(physicalDevice)->GetDisplayPlaneSupportedDisplaysKHR(physicalDevice, planeIndex, pDisplayCount, pDisplays);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkGetDisplayModePropertiesKHR(VkPhysicalDevice physicalDevice, VkDisplayKHR display, uint32_t* pPropertyCount, VkDisplayModePropertiesKHR* pProperties) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetDisplayModePropertiesKHR\n";
    }
    VkResult result = instance_dispatch_table(physicalDevice)->GetDisplayModePropertiesKHR(physicalDevice, display, pPropertyCount, pProperties);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkCreateDisplayModeKHR(VkPhysicalDevice physicalDevice, VkDisplayKHR display, const VkDisplayModeCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDisplayModeKHR* pMode) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCreateDisplayModeKHR\n";
    }
    VkResult result = instance_dispatch_table(physicalDevice)->CreateDisplayModeKHR(physicalDevice, display, pCreateInfo, pAllocator, pMode);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkGetDisplayPlaneCapabilitiesKHR(VkPhysicalDevice physicalDevice, VkDisplayModeKHR mode, uint32_t planeIndex, VkDisplayPlaneCapabilitiesKHR* pCapabilities) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetDisplayPlaneCapabilitiesKHR\n";
    }
    VkResult result = instance_dispatch_table(physicalDevice)->GetDisplayPlaneCapabilitiesKHR(physicalDevice, mode, planeIndex, pCapabilities);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkCreateDisplayPlaneSurfaceKHR(VkInstance instance, const VkDisplaySurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCreateDisplayPlaneSurfaceKHR\n";
    }
    VkResult result = instance_dispatch_table(instance)->CreateDisplayPlaneSurfaceKHR(instance, pCreateInfo, pAllocator, pSurface);
    return result;
}
#if defined(VK_USE_PLATFORM_XLIB_KHR)
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkCreateXlibSurfaceKHR(VkInstance instance, const VkXlibSurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCreateXlibSurfaceKHR\n";
    }
    VkResult result = instance_dispatch_table(instance)->CreateXlibSurfaceKHR(instance, pCreateInfo, pAllocator, pSurface);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkBool32 VKAPI_CALL vkGetPhysicalDeviceXlibPresentationSupportKHR(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, Display* dpy, VisualID visualID) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetPhysicalDeviceXlibPresentationSupportKHR\n";
    }
    VkBool32 result = instance_dispatch_table(physicalDevice)->GetPhysicalDeviceXlibPresentationSupportKHR(physicalDevice, queueFamilyIndex, dpy, visualID);
    return result;
}
#endif  // VK_USE_PLATFORM_XLIB_KHR
#if defined(VK_USE_PLATFORM_XCB_KHR)
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkCreateXcbSurfaceKHR(VkInstance instance, const VkXcbSurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCreateXcbSurfaceKHR\n";
    }
    VkResult result = instance_dispatch_table(instance)->CreateXcbSurfaceKHR(instance, pCreateInfo, pAllocator, pSurface);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkBool32 VKAPI_CALL vkGetPhysicalDeviceXcbPresentationSupportKHR(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, xcb_connection_t* connection, xcb_visualid_t visual_id) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetPhysicalDeviceXcbPresentationSupportKHR\n";
    }
    VkBool32 result = instance_dispatch_table(physicalDevice)->GetPhysicalDeviceXcbPresentationSupportKHR(physicalDevice, queueFamilyIndex, connection, visual_id);
    return result;
}
#endif  // VK_USE_PLATFORM_XCB_KHR
#if defined(VK_USE_PLATFORM_WAYLAND_KHR)
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkCreateWaylandSurfaceKHR(VkInstance instance, const VkWaylandSurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCreateWaylandSurfaceKHR\n";
    }
    VkResult result = instance_dispatch_table(instance)->CreateWaylandSurfaceKHR(instance, pCreateInfo, pAllocator, pSurface);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkBool32 VKAPI_CALL vkGetPhysicalDeviceWaylandPresentationSupportKHR(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, struct wl_display* display) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetPhysicalDeviceWaylandPresentationSupportKHR\n";
    }
    VkBool32 result = instance_dispatch_table(physicalDevice)->GetPhysicalDeviceWaylandPresentationSupportKHR(physicalDevice, queueFamilyIndex, display);
    return result;
}
#endif  // VK_USE_PLATFORM_WAYLAND_KHR
#if defined(VK_USE_PLATFORM_ANDROID_KHR)
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkCreateAndroidSurfaceKHR(VkInstance instance, const VkAndroidSurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCreateAndroidSurfaceKHR\n";
    }
    VkResult result = instance_dispatch_table(instance)->CreateAndroidSurfaceKHR(instance, pCreateInfo, pAllocator, pSurface);
    return result;
}
#endif  // VK_USE_PLATFORM_ANDROID_KHR
#if defined(VK_USE_PLATFORM_WIN32_KHR)
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkCreateWin32SurfaceKHR(VkInstance instance, const VkWin32SurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCreateWin32SurfaceKHR\n";
    }
    VkResult result = instance_dispatch_table(instance)->CreateWin32SurfaceKHR(instance, pCreateInfo, pAllocator, pSurface);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkBool32 VKAPI_CALL vkGetPhysicalDeviceWin32PresentationSupportKHR(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetPhysicalDeviceWin32PresentationSupportKHR\n";
    }
    VkBool32 result = instance_dispatch_table(physicalDevice)->GetPhysicalDeviceWin32PresentationSupportKHR(physicalDevice, queueFamilyIndex);
    return result;
}
#endif  // VK_USE_PLATFORM_WIN32_KHR
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceVideoCapabilitiesKHR(VkPhysicalDevice physicalDevice, const VkVideoProfileInfoKHR* pVideoProfile, VkVideoCapabilitiesKHR* pCapabilities) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetPhysicalDeviceVideoCapabilitiesKHR\n";
    }
    VkResult result = instance_dispatch_table(physicalDevice)->GetPhysicalDeviceVideoCapabilitiesKHR(physicalDevice, pVideoProfile, pCapabilities);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceVideoFormatPropertiesKHR(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceVideoFormatInfoKHR* pVideoFormatInfo, uint32_t* pVideoFormatPropertyCount, VkVideoFormatPropertiesKHR* pVideoFormatProperties) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetPhysicalDeviceVideoFormatPropertiesKHR\n";
    }
    VkResult result = instance_dispatch_table(physicalDevice)->GetPhysicalDeviceVideoFormatPropertiesKHR(physicalDevice, pVideoFormatInfo, pVideoFormatPropertyCount, pVideoFormatProperties);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceFeatures2KHR(VkPhysicalDevice physicalDevice, VkPhysicalDeviceFeatures2* pFeatures) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetPhysicalDeviceFeatures2KHR\n";
    }
    instance_dispatch_table(physicalDevice)->GetPhysicalDeviceFeatures2KHR(physicalDevice, pFeatures);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceProperties2KHR(VkPhysicalDevice physicalDevice, VkPhysicalDeviceProperties2* pProperties) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetPhysicalDeviceProperties2KHR\n";
    }
    instance_dispatch_table(physicalDevice)->GetPhysicalDeviceProperties2KHR(physicalDevice, pProperties);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceFormatProperties2KHR(VkPhysicalDevice physicalDevice, VkFormat format, VkFormatProperties2* pFormatProperties) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetPhysicalDeviceFormatProperties2KHR\n";
    }
    instance_dispatch_table(physicalDevice)->GetPhysicalDeviceFormatProperties2KHR(physicalDevice, format, pFormatProperties);
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceImageFormatProperties2KHR(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceImageFormatInfo2* pImageFormatInfo, VkImageFormatProperties2* pImageFormatProperties) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetPhysicalDeviceImageFormatProperties2KHR\n";
    }
    VkResult result = instance_dispatch_table(physicalDevice)->GetPhysicalDeviceImageFormatProperties2KHR(physicalDevice, pImageFormatInfo, pImageFormatProperties);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceQueueFamilyProperties2KHR(VkPhysicalDevice physicalDevice, uint32_t* pQueueFamilyPropertyCount, VkQueueFamilyProperties2* pQueueFamilyProperties) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetPhysicalDeviceQueueFamilyProperties2KHR\n";
    }
    instance_dispatch_table(physicalDevice)->GetPhysicalDeviceQueueFamilyProperties2KHR(physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceMemoryProperties2KHR(VkPhysicalDevice physicalDevice, VkPhysicalDeviceMemoryProperties2* pMemoryProperties) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetPhysicalDeviceMemoryProperties2KHR\n";
    }
    instance_dispatch_table(physicalDevice)->GetPhysicalDeviceMemoryProperties2KHR(physicalDevice, pMemoryProperties);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceSparseImageFormatProperties2KHR(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceSparseImageFormatInfo2* pFormatInfo, uint32_t* pPropertyCount, VkSparseImageFormatProperties2* pProperties) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetPhysicalDeviceSparseImageFormatProperties2KHR\n";
    }
    instance_dispatch_table(physicalDevice)->GetPhysicalDeviceSparseImageFormatProperties2KHR(physicalDevice, pFormatInfo, pPropertyCount, pProperties);
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkEnumeratePhysicalDeviceGroupsKHR(VkInstance instance, uint32_t* pPhysicalDeviceGroupCount, VkPhysicalDeviceGroupProperties* pPhysicalDeviceGroupProperties) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkEnumeratePhysicalDeviceGroupsKHR\n";
    }
    VkResult result = instance_dispatch_table(instance)->EnumeratePhysicalDeviceGroupsKHR(instance, pPhysicalDeviceGroupCount, pPhysicalDeviceGroupProperties);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceExternalBufferPropertiesKHR(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalBufferInfo* pExternalBufferInfo, VkExternalBufferProperties* pExternalBufferProperties) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetPhysicalDeviceExternalBufferPropertiesKHR\n";
    }
    instance_dispatch_table(physicalDevice)->GetPhysicalDeviceExternalBufferPropertiesKHR(physicalDevice, pExternalBufferInfo, pExternalBufferProperties);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceExternalSemaphorePropertiesKHR(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalSemaphoreInfo* pExternalSemaphoreInfo, VkExternalSemaphoreProperties* pExternalSemaphoreProperties) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetPhysicalDeviceExternalSemaphorePropertiesKHR\n";
    }
    instance_dispatch_table(physicalDevice)->GetPhysicalDeviceExternalSemaphorePropertiesKHR(physicalDevice, pExternalSemaphoreInfo, pExternalSemaphoreProperties);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceExternalFencePropertiesKHR(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalFenceInfo* pExternalFenceInfo, VkExternalFenceProperties* pExternalFenceProperties) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetPhysicalDeviceExternalFencePropertiesKHR\n";
    }
    instance_dispatch_table(physicalDevice)->GetPhysicalDeviceExternalFencePropertiesKHR(physicalDevice, pExternalFenceInfo, pExternalFenceProperties);
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, uint32_t* pCounterCount, VkPerformanceCounterKHR* pCounters, VkPerformanceCounterDescriptionKHR* pCounterDescriptions) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR\n";
    }
    VkResult result = instance_dispatch_table(physicalDevice)->EnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR(physicalDevice, queueFamilyIndex, pCounterCount, pCounters, pCounterDescriptions);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR(VkPhysicalDevice physicalDevice, const VkQueryPoolPerformanceCreateInfoKHR* pPerformanceQueryCreateInfo, uint32_t* pNumPasses) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR\n";
    }
    instance_dispatch_table(physicalDevice)->GetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR(physicalDevice, pPerformanceQueryCreateInfo, pNumPasses);
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceSurfaceCapabilities2KHR(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo, VkSurfaceCapabilities2KHR* pSurfaceCapabilities) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetPhysicalDeviceSurfaceCapabilities2KHR\n";
    }
    VkResult result = instance_dispatch_table(physicalDevice)->GetPhysicalDeviceSurfaceCapabilities2KHR(physicalDevice, pSurfaceInfo, pSurfaceCapabilities);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceSurfaceFormats2KHR(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo, uint32_t* pSurfaceFormatCount, VkSurfaceFormat2KHR* pSurfaceFormats) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetPhysicalDeviceSurfaceFormats2KHR\n";
    }
    VkResult result = instance_dispatch_table(physicalDevice)->GetPhysicalDeviceSurfaceFormats2KHR(physicalDevice, pSurfaceInfo, pSurfaceFormatCount, pSurfaceFormats);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceDisplayProperties2KHR(VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount, VkDisplayProperties2KHR* pProperties) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetPhysicalDeviceDisplayProperties2KHR\n";
    }
    VkResult result = instance_dispatch_table(physicalDevice)->GetPhysicalDeviceDisplayProperties2KHR(physicalDevice, pPropertyCount, pProperties);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceDisplayPlaneProperties2KHR(VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount, VkDisplayPlaneProperties2KHR* pProperties) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetPhysicalDeviceDisplayPlaneProperties2KHR\n";
    }
    VkResult result = instance_dispatch_table(physicalDevice)->GetPhysicalDeviceDisplayPlaneProperties2KHR(physicalDevice, pPropertyCount, pProperties);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkGetDisplayModeProperties2KHR(VkPhysicalDevice physicalDevice, VkDisplayKHR display, uint32_t* pPropertyCount, VkDisplayModeProperties2KHR* pProperties) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetDisplayModeProperties2KHR\n";
    }
    VkResult result = instance_dispatch_table(physicalDevice)->GetDisplayModeProperties2KHR(physicalDevice, display, pPropertyCount, pProperties);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkGetDisplayPlaneCapabilities2KHR(VkPhysicalDevice physicalDevice, const VkDisplayPlaneInfo2KHR* pDisplayPlaneInfo, VkDisplayPlaneCapabilities2KHR* pCapabilities) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetDisplayPlaneCapabilities2KHR\n";
    }
    VkResult result = instance_dispatch_table(physicalDevice)->GetDisplayPlaneCapabilities2KHR(physicalDevice, pDisplayPlaneInfo, pCapabilities);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceFragmentShadingRatesKHR(VkPhysicalDevice physicalDevice, uint32_t* pFragmentShadingRateCount, VkPhysicalDeviceFragmentShadingRateKHR* pFragmentShadingRates) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetPhysicalDeviceFragmentShadingRatesKHR\n";
    }
    VkResult result = instance_dispatch_table(physicalDevice)->GetPhysicalDeviceFragmentShadingRatesKHR(physicalDevice, pFragmentShadingRateCount, pFragmentShadingRates);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceVideoEncodeQualityLevelInfoKHR* pQualityLevelInfo, VkVideoEncodeQualityLevelPropertiesKHR* pQualityLevelProperties) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR\n";
    }
    VkResult result = instance_dispatch_table(physicalDevice)->GetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR(physicalDevice, pQualityLevelInfo, pQualityLevelProperties);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceCooperativeMatrixPropertiesKHR(VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount, VkCooperativeMatrixPropertiesKHR* pProperties) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetPhysicalDeviceCooperativeMatrixPropertiesKHR\n";
    }
    VkResult result = instance_dispatch_table(physicalDevice)->GetPhysicalDeviceCooperativeMatrixPropertiesKHR(physicalDevice, pPropertyCount, pProperties);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceCalibrateableTimeDomainsKHR(VkPhysicalDevice physicalDevice, uint32_t* pTimeDomainCount, VkTimeDomainKHR* pTimeDomains) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetPhysicalDeviceCalibrateableTimeDomainsKHR\n";
    }
    VkResult result = instance_dispatch_table(physicalDevice)->GetPhysicalDeviceCalibrateableTimeDomainsKHR(physicalDevice, pTimeDomainCount, pTimeDomains);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkCreateDebugReportCallbackEXT(VkInstance instance, const VkDebugReportCallbackCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDebugReportCallbackEXT* pCallback) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCreateDebugReportCallbackEXT\n";
    }
    VkResult result = instance_dispatch_table(instance)->CreateDebugReportCallbackEXT(instance, pCreateInfo, pAllocator, pCallback);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkDestroyDebugReportCallbackEXT(VkInstance instance, VkDebugReportCallbackEXT callback, const VkAllocationCallbacks* pAllocator) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkDestroyDebugReportCallbackEXT\n";
    }
    instance_dispatch_table(instance)->DestroyDebugReportCallbackEXT(instance, callback, pAllocator);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkDebugReportMessageEXT(VkInstance instance, VkDebugReportFlagsEXT flags, VkDebugReportObjectTypeEXT objectType, uint64_t object, size_t location, int32_t messageCode, const char* pLayerPrefix, const char* pMessage) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkDebugReportMessageEXT\n";
    }
    instance_dispatch_table(instance)->DebugReportMessageEXT(instance, flags, objectType, object, location, messageCode, pLayerPrefix, pMessage);
}
#if defined(VK_USE_PLATFORM_GGP)
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkCreateStreamDescriptorSurfaceGGP(VkInstance instance, const VkStreamDescriptorSurfaceCreateInfoGGP* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCreateStreamDescriptorSurfaceGGP\n";
    }
    VkResult result = instance_dispatch_table(instance)->CreateStreamDescriptorSurfaceGGP(instance, pCreateInfo, pAllocator, pSurface);
    return result;
}
#endif  // VK_USE_PLATFORM_GGP
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceExternalImageFormatPropertiesNV(VkPhysicalDevice physicalDevice, VkFormat format, VkImageType type, VkImageTiling tiling, VkImageUsageFlags usage, VkImageCreateFlags flags, VkExternalMemoryHandleTypeFlagsNV externalHandleType, VkExternalImageFormatPropertiesNV* pExternalImageFormatProperties) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetPhysicalDeviceExternalImageFormatPropertiesNV\n";
    }
    VkResult result = instance_dispatch_table(physicalDevice)->GetPhysicalDeviceExternalImageFormatPropertiesNV(physicalDevice, format, type, tiling, usage, flags, externalHandleType, pExternalImageFormatProperties);
    return result;
}
#if defined(VK_USE_PLATFORM_VI_NN)
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkCreateViSurfaceNN(VkInstance instance, const VkViSurfaceCreateInfoNN* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCreateViSurfaceNN\n";
    }
    VkResult result = instance_dispatch_table(instance)->CreateViSurfaceNN(instance, pCreateInfo, pAllocator, pSurface);
    return result;
}
#endif  // VK_USE_PLATFORM_VI_NN
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkReleaseDisplayEXT(VkPhysicalDevice physicalDevice, VkDisplayKHR display) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkReleaseDisplayEXT\n";
    }
    VkResult result = instance_dispatch_table(physicalDevice)->ReleaseDisplayEXT(physicalDevice, display);
    return result;
}
#if defined(VK_USE_PLATFORM_XLIB_XRANDR_EXT)
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkAcquireXlibDisplayEXT(VkPhysicalDevice physicalDevice, Display* dpy, VkDisplayKHR display) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkAcquireXlibDisplayEXT\n";
    }
    VkResult result = instance_dispatch_table(physicalDevice)->AcquireXlibDisplayEXT(physicalDevice, dpy, display);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkGetRandROutputDisplayEXT(VkPhysicalDevice physicalDevice, Display* dpy, RROutput rrOutput, VkDisplayKHR* pDisplay) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetRandROutputDisplayEXT\n";
    }
    VkResult result = instance_dispatch_table(physicalDevice)->GetRandROutputDisplayEXT(physicalDevice, dpy, rrOutput, pDisplay);
    return result;
}
#endif  // VK_USE_PLATFORM_XLIB_XRANDR_EXT
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceSurfaceCapabilities2EXT(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, VkSurfaceCapabilities2EXT* pSurfaceCapabilities) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetPhysicalDeviceSurfaceCapabilities2EXT\n";
    }
    VkResult result = instance_dispatch_table(physicalDevice)->GetPhysicalDeviceSurfaceCapabilities2EXT(physicalDevice, surface, pSurfaceCapabilities);
    return result;
}
#if defined(VK_USE_PLATFORM_IOS_MVK)
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkCreateIOSSurfaceMVK(VkInstance instance, const VkIOSSurfaceCreateInfoMVK* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCreateIOSSurfaceMVK\n";
    }
    VkResult result = instance_dispatch_table(instance)->CreateIOSSurfaceMVK(instance, pCreateInfo, pAllocator, pSurface);
    return result;
}
#endif  // VK_USE_PLATFORM_IOS_MVK
#if defined(VK_USE_PLATFORM_MACOS_MVK)
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkCreateMacOSSurfaceMVK(VkInstance instance, const VkMacOSSurfaceCreateInfoMVK* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCreateMacOSSurfaceMVK\n";
    }
    VkResult result = instance_dispatch_table(instance)->CreateMacOSSurfaceMVK(instance, pCreateInfo, pAllocator, pSurface);
    return result;
}
#endif  // VK_USE_PLATFORM_MACOS_MVK
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkCreateDebugUtilsMessengerEXT(VkInstance instance, const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDebugUtilsMessengerEXT* pMessenger) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCreateDebugUtilsMessengerEXT\n";
    }
    VkResult result = instance_dispatch_table(instance)->CreateDebugUtilsMessengerEXT(instance, pCreateInfo, pAllocator, pMessenger);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkDestroyDebugUtilsMessengerEXT(VkInstance instance, VkDebugUtilsMessengerEXT messenger, const VkAllocationCallbacks* pAllocator) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkDestroyDebugUtilsMessengerEXT\n";
    }
    instance_dispatch_table(instance)->DestroyDebugUtilsMessengerEXT(instance, messenger, pAllocator);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkSubmitDebugUtilsMessageEXT(VkInstance instance, VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity, VkDebugUtilsMessageTypeFlagsEXT messageTypes, const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkSubmitDebugUtilsMessageEXT\n";
    }
    instance_dispatch_table(instance)->SubmitDebugUtilsMessageEXT(instance, messageSeverity, messageTypes, pCallbackData);
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkDeviceSize VKAPI_CALL vkGetPhysicalDeviceDescriptorSizeEXT(VkPhysicalDevice physicalDevice, VkDescriptorType descriptorType) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetPhysicalDeviceDescriptorSizeEXT\n";
    }
    VkDeviceSize result = instance_dispatch_table(physicalDevice)->GetPhysicalDeviceDescriptorSizeEXT(physicalDevice, descriptorType);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceMultisamplePropertiesEXT(VkPhysicalDevice physicalDevice, VkSampleCountFlagBits samples, VkMultisamplePropertiesEXT* pMultisampleProperties) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetPhysicalDeviceMultisamplePropertiesEXT\n";
    }
    instance_dispatch_table(physicalDevice)->GetPhysicalDeviceMultisamplePropertiesEXT(physicalDevice, samples, pMultisampleProperties);
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceCalibrateableTimeDomainsEXT(VkPhysicalDevice physicalDevice, uint32_t* pTimeDomainCount, VkTimeDomainKHR* pTimeDomains) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetPhysicalDeviceCalibrateableTimeDomainsEXT\n";
    }
    VkResult result = instance_dispatch_table(physicalDevice)->GetPhysicalDeviceCalibrateableTimeDomainsEXT(physicalDevice, pTimeDomainCount, pTimeDomains);
    return result;
}
#if defined(VK_USE_PLATFORM_FUCHSIA)
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkCreateImagePipeSurfaceFUCHSIA(VkInstance instance, const VkImagePipeSurfaceCreateInfoFUCHSIA* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCreateImagePipeSurfaceFUCHSIA\n";
    }
    VkResult result = instance_dispatch_table(instance)->CreateImagePipeSurfaceFUCHSIA(instance, pCreateInfo, pAllocator, pSurface);
    return result;
}
#endif  // VK_USE_PLATFORM_FUCHSIA
#if defined(VK_USE_PLATFORM_METAL_EXT)
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkCreateMetalSurfaceEXT(VkInstance instance, const VkMetalSurfaceCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCreateMetalSurfaceEXT\n";
    }
    VkResult result = instance_dispatch_table(instance)->CreateMetalSurfaceEXT(instance, pCreateInfo, pAllocator, pSurface);
    return result;
}
#endif  // VK_USE_PLATFORM_METAL_EXT
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceToolPropertiesEXT(VkPhysicalDevice physicalDevice, uint32_t* pToolCount, VkPhysicalDeviceToolProperties* pToolProperties) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetPhysicalDeviceToolPropertiesEXT\n";
    }

    static const VkPhysicalDeviceToolPropertiesEXT api_dump_layer_tool_props = {
        VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TOOL_PROPERTIES_EXT,
        nullptr,
        "API Dump Layer",
        "2",
        VK_TOOL_PURPOSE_PROFILING_BIT_EXT | VK_TOOL_PURPOSE_TRACING_BIT_EXT,
        "The VK_LAYER_LUNARG_api_dump utility layer prints API calls, parameters, and values to the identified output stream.",
        "VK_LAYER_LUNARG_api_dump"};

    auto original_pToolProperties = pToolProperties;
    if (pToolProperties != nullptr) {
        *pToolProperties = api_dump_layer_tool_props;
        pToolProperties = ((*pToolCount > 1) ? &pToolProperties[1] : nullptr);
        (*pToolCount)--;
    }
    VkResult result = instance_dispatch_table(physicalDevice)->GetPhysicalDeviceToolPropertiesEXT(physicalDevice, pToolCount, pToolProperties);
    if (original_pToolProperties != nullptr) {
        pToolProperties = original_pToolProperties;
    }

    (*pToolCount)++;
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceCooperativeMatrixPropertiesNV(VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount, VkCooperativeMatrixPropertiesNV* pProperties) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetPhysicalDeviceCooperativeMatrixPropertiesNV\n";
    }
    VkResult result = instance_dispatch_table(physicalDevice)->GetPhysicalDeviceCooperativeMatrixPropertiesNV(physicalDevice, pPropertyCount, pProperties);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV(VkPhysicalDevice physicalDevice, uint32_t* pCombinationCount, VkFramebufferMixedSamplesCombinationNV* pCombinations) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV\n";
    }
    VkResult result = instance_dispatch_table(physicalDevice)->GetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV(physicalDevice, pCombinationCount, pCombinations);
    return result;
}
#if defined(VK_USE_PLATFORM_WIN32_KHR)
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceSurfacePresentModes2EXT(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo, uint32_t* pPresentModeCount, VkPresentModeKHR* pPresentModes) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetPhysicalDeviceSurfacePresentModes2EXT\n";
    }
    VkResult result = instance_dispatch_table(physicalDevice)->GetPhysicalDeviceSurfacePresentModes2EXT(physicalDevice, pSurfaceInfo, pPresentModeCount, pPresentModes);
    return result;
}
#endif  // VK_USE_PLATFORM_WIN32_KHR
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkCreateHeadlessSurfaceEXT(VkInstance instance, const VkHeadlessSurfaceCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCreateHeadlessSurfaceEXT\n";
    }
    VkResult result = instance_dispatch_table(instance)->CreateHeadlessSurfaceEXT(instance, pCreateInfo, pAllocator, pSurface);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkAcquireDrmDisplayEXT(VkPhysicalDevice physicalDevice, int32_t drmFd, VkDisplayKHR display) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkAcquireDrmDisplayEXT\n";
    }
    VkResult result = instance_dispatch_table(physicalDevice)->AcquireDrmDisplayEXT(physicalDevice, drmFd, display);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkGetDrmDisplayEXT(VkPhysicalDevice physicalDevice, int32_t drmFd, uint32_t connectorId, VkDisplayKHR* display) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetDrmDisplayEXT\n";
    }
    VkResult result = instance_dispatch_table(physicalDevice)->GetDrmDisplayEXT(physicalDevice, drmFd, connectorId, display);
    return result;
}
#if defined(VK_USE_PLATFORM_WIN32_KHR)
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkAcquireWinrtDisplayNV(VkPhysicalDevice physicalDevice, VkDisplayKHR display) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkAcquireWinrtDisplayNV\n";
    }
    VkResult result = instance_dispatch_table(physicalDevice)->AcquireWinrtDisplayNV(physicalDevice, display);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkGetWinrtDisplayNV(VkPhysicalDevice physicalDevice, uint32_t deviceRelativeId, VkDisplayKHR* pDisplay) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetWinrtDisplayNV\n";
    }
    VkResult result = instance_dispatch_table(physicalDevice)->GetWinrtDisplayNV(physicalDevice, deviceRelativeId, pDisplay);
    return result;
}
#endif  // VK_USE_PLATFORM_WIN32_KHR
#if defined(VK_USE_PLATFORM_DIRECTFB_EXT)
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkCreateDirectFBSurfaceEXT(VkInstance instance, const VkDirectFBSurfaceCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCreateDirectFBSurfaceEXT\n";
    }
    VkResult result = instance_dispatch_table(instance)->CreateDirectFBSurfaceEXT(instance, pCreateInfo, pAllocator, pSurface);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkBool32 VKAPI_CALL vkGetPhysicalDeviceDirectFBPresentationSupportEXT(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, IDirectFB* dfb) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetPhysicalDeviceDirectFBPresentationSupportEXT\n";
    }
    VkBool32 result = instance_dispatch_table(physicalDevice)->GetPhysicalDeviceDirectFBPresentationSupportEXT(physicalDevice, queueFamilyIndex, dfb);
    return result;
}
#endif  // VK_USE_PLATFORM_DIRECTFB_EXT
#if defined(VK_USE_PLATFORM_SCREEN_QNX)
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkCreateScreenSurfaceQNX(VkInstance instance, const VkScreenSurfaceCreateInfoQNX* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCreateScreenSurfaceQNX\n";
    }
    VkResult result = instance_dispatch_table(instance)->CreateScreenSurfaceQNX(instance, pCreateInfo, pAllocator, pSurface);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkBool32 VKAPI_CALL vkGetPhysicalDeviceScreenPresentationSupportQNX(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, struct _screen_window* window) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetPhysicalDeviceScreenPresentationSupportQNX\n";
    }
    VkBool32 result = instance_dispatch_table(physicalDevice)->GetPhysicalDeviceScreenPresentationSupportQNX(physicalDevice, queueFamilyIndex, window);
    return result;
}
#endif  // VK_USE_PLATFORM_SCREEN_QNX
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceExternalTensorPropertiesARM(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalTensorInfoARM* pExternalTensorInfo, VkExternalTensorPropertiesARM* pExternalTensorProperties) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetPhysicalDeviceExternalTensorPropertiesARM\n";
    }
    instance_dispatch_table(physicalDevice)->GetPhysicalDeviceExternalTensorPropertiesARM(physicalDevice, pExternalTensorInfo, pExternalTensorProperties);
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceOpticalFlowImageFormatsNV(VkPhysicalDevice physicalDevice, const VkOpticalFlowImageFormatInfoNV* pOpticalFlowImageFormatInfo, uint32_t* pFormatCount, VkOpticalFlowImageFormatPropertiesNV* pImageFormatProperties) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetPhysicalDeviceOpticalFlowImageFormatsNV\n";
    }
    VkResult result = instance_dispatch_table(physicalDevice)->GetPhysicalDeviceOpticalFlowImageFormatsNV(physicalDevice, pOpticalFlowImageFormatInfo, pFormatCount, pImageFormatProperties);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceCooperativeVectorPropertiesNV(VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount, VkCooperativeVectorPropertiesNV* pProperties) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetPhysicalDeviceCooperativeVectorPropertiesNV\n";
    }
    VkResult result = instance_dispatch_table(physicalDevice)->GetPhysicalDeviceCooperativeVectorPropertiesNV(physicalDevice, pPropertyCount, pProperties);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceQueueFamilyDataGraphPropertiesARM(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, uint32_t* pQueueFamilyDataGraphPropertyCount, VkQueueFamilyDataGraphPropertiesARM* pQueueFamilyDataGraphProperties) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetPhysicalDeviceQueueFamilyDataGraphPropertiesARM\n";
    }
    VkResult result = instance_dispatch_table(physicalDevice)->GetPhysicalDeviceQueueFamilyDataGraphPropertiesARM(physicalDevice, queueFamilyIndex, pQueueFamilyDataGraphPropertyCount, pQueueFamilyDataGraphProperties);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceQueueFamilyDataGraphProcessingEnginePropertiesARM(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceQueueFamilyDataGraphProcessingEngineInfoARM* pQueueFamilyDataGraphProcessingEngineInfo, VkQueueFamilyDataGraphProcessingEnginePropertiesARM* pQueueFamilyDataGraphProcessingEngineProperties) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetPhysicalDeviceQueueFamilyDataGraphProcessingEnginePropertiesARM\n";
    }
    instance_dispatch_table(physicalDevice)->GetPhysicalDeviceQueueFamilyDataGraphProcessingEnginePropertiesARM(physicalDevice, pQueueFamilyDataGraphProcessingEngineInfo, pQueueFamilyDataGraphProcessingEngineProperties);
}
#if defined(VK_USE_PLATFORM_OHOS)
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkCreateSurfaceOHOS(VkInstance instance, const VkSurfaceCreateInfoOHOS* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCreateSurfaceOHOS\n";
    }
    VkResult result = instance_dispatch_table(instance)->CreateSurfaceOHOS(instance, pCreateInfo, pAllocator, pSurface);
    return result;
}
#endif  // VK_USE_PLATFORM_OHOS
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceCooperativeMatrixFlexibleDimensionsPropertiesNV(VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount, VkCooperativeMatrixFlexibleDimensionsPropertiesNV* pProperties) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetPhysicalDeviceCooperativeMatrixFlexibleDimensionsPropertiesNV\n";
    }
    VkResult result = instance_dispatch_table(physicalDevice)->GetPhysicalDeviceCooperativeMatrixFlexibleDimensionsPropertiesNV(physicalDevice, pPropertyCount, pProperties);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkEnumeratePhysicalDeviceQueueFamilyPerformanceCountersByRegionARM(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, uint32_t* pCounterCount, VkPerformanceCounterARM* pCounters, VkPerformanceCounterDescriptionARM* pCounterDescriptions) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkEnumeratePhysicalDeviceQueueFamilyPerformanceCountersByRegionARM\n";
    }
    VkResult result = instance_dispatch_table(physicalDevice)->EnumeratePhysicalDeviceQueueFamilyPerformanceCountersByRegionARM(physicalDevice, queueFamilyIndex, pCounterCount, pCounters, pCounterDescriptions);
    return result;
}

// Autogen device functions

template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkDestroyDevice(VkDevice device, const VkAllocationCallbacks* pAllocator) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkDestroyDevice\n";
    }
    device_dispatch_table(device)->DestroyDevice(device, pAllocator);
    destroy_device_dispatch_table(get_dispatch_key(device));
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkGetDeviceQueue(VkDevice device, uint32_t queueFamilyIndex, uint32_t queueIndex, VkQueue* pQueue) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetDeviceQueue\n";
    }
    device_dispatch_table(device)->GetDeviceQueue(device, queueFamilyIndex, queueIndex, pQueue);
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkQueueSubmit(VkQueue queue, uint32_t submitCount, const VkSubmitInfo* pSubmits, VkFence fence) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkQueueSubmit\n";
    }
    VkResult result = device_dispatch_table(queue)->QueueSubmit(queue, submitCount, pSubmits, fence);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkQueueWaitIdle(VkQueue queue) {
    VkResult result = device_dispatch_table(queue)->QueueWaitIdle(queue);
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkQueueWaitIdle\n";
    }
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkDeviceWaitIdle(VkDevice device) {
    VkResult result = device_dispatch_table(device)->DeviceWaitIdle(device);
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkDeviceWaitIdle\n";
    }
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkAllocateMemory(VkDevice device, const VkMemoryAllocateInfo* pAllocateInfo, const VkAllocationCallbacks* pAllocator, VkDeviceMemory* pMemory) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkAllocateMemory\n";
    }
    VkResult result = device_dispatch_table(device)->AllocateMemory(device, pAllocateInfo, pAllocator, pMemory);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkFreeMemory(VkDevice device, VkDeviceMemory memory, const VkAllocationCallbacks* pAllocator) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkFreeMemory\n";
    }
    device_dispatch_table(device)->FreeMemory(device, memory, pAllocator);
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkMapMemory(VkDevice device, VkDeviceMemory memory, VkDeviceSize offset, VkDeviceSize size, VkMemoryMapFlags flags, void** ppData) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkMapMemory\n";
    }
    VkResult result = device_dispatch_table(device)->MapMemory(device, memory, offset, size, flags, ppData);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkUnmapMemory(VkDevice device, VkDeviceMemory memory) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkUnmapMemory\n";
    }
    device_dispatch_table(device)->UnmapMemory(device, memory);
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkFlushMappedMemoryRanges(VkDevice device, uint32_t memoryRangeCount, const VkMappedMemoryRange* pMemoryRanges) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkFlushMappedMemoryRanges\n";
    }
    VkResult result = device_dispatch_table(device)->FlushMappedMemoryRanges(device, memoryRangeCount, pMemoryRanges);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkInvalidateMappedMemoryRanges(VkDevice device, uint32_t memoryRangeCount, const VkMappedMemoryRange* pMemoryRanges) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkInvalidateMappedMemoryRanges\n";
    }
    VkResult result = device_dispatch_table(device)->InvalidateMappedMemoryRanges(device, memoryRangeCount, pMemoryRanges);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkGetDeviceMemoryCommitment(VkDevice device, VkDeviceMemory memory, VkDeviceSize* pCommittedMemoryInBytes) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetDeviceMemoryCommitment\n";
    }
    device_dispatch_table(device)->GetDeviceMemoryCommitment(device, memory, pCommittedMemoryInBytes);
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkBindBufferMemory(VkDevice device, VkBuffer buffer, VkDeviceMemory memory, VkDeviceSize memoryOffset) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkBindBufferMemory\n";
    }
    VkResult result = device_dispatch_table(device)->BindBufferMemory(device, buffer, memory, memoryOffset);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkBindImageMemory(VkDevice device, VkImage image, VkDeviceMemory memory, VkDeviceSize memoryOffset) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkBindImageMemory\n";
    }
    VkResult result = device_dispatch_table(device)->BindImageMemory(device, image, memory, memoryOffset);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkGetBufferMemoryRequirements(VkDevice device, VkBuffer buffer, VkMemoryRequirements* pMemoryRequirements) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetBufferMemoryRequirements\n";
    }
    device_dispatch_table(device)->GetBufferMemoryRequirements(device, buffer, pMemoryRequirements);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkGetImageMemoryRequirements(VkDevice device, VkImage image, VkMemoryRequirements* pMemoryRequirements) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetImageMemoryRequirements\n";
    }
    device_dispatch_table(device)->GetImageMemoryRequirements(device, image, pMemoryRequirements);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkGetImageSparseMemoryRequirements(VkDevice device, VkImage image, uint32_t* pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements* pSparseMemoryRequirements) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetImageSparseMemoryRequirements\n";
    }
    device_dispatch_table(device)->GetImageSparseMemoryRequirements(device, image, pSparseMemoryRequirementCount, pSparseMemoryRequirements);
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkQueueBindSparse(VkQueue queue, uint32_t bindInfoCount, const VkBindSparseInfo* pBindInfo, VkFence fence) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkQueueBindSparse\n";
    }
    VkResult result = device_dispatch_table(queue)->QueueBindSparse(queue, bindInfoCount, pBindInfo, fence);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkCreateFence(VkDevice device, const VkFenceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkFence* pFence) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCreateFence\n";
    }
    VkResult result = device_dispatch_table(device)->CreateFence(device, pCreateInfo, pAllocator, pFence);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkDestroyFence(VkDevice device, VkFence fence, const VkAllocationCallbacks* pAllocator) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkDestroyFence\n";
    }
    device_dispatch_table(device)->DestroyFence(device, fence, pAllocator);
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkResetFences(VkDevice device, uint32_t fenceCount, const VkFence* pFences) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkResetFences\n";
    }
    VkResult result = device_dispatch_table(device)->ResetFences(device, fenceCount, pFences);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkGetFenceStatus(VkDevice device, VkFence fence) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetFenceStatus\n";
    }
    VkResult result = device_dispatch_table(device)->GetFenceStatus(device, fence);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkWaitForFences(VkDevice device, uint32_t fenceCount, const VkFence* pFences, VkBool32 waitAll, uint64_t timeout) {
    VkResult result = device_dispatch_table(device)->WaitForFences(device, fenceCount, pFences, waitAll, timeout);
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkWaitForFences\n";
    }
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkCreateSemaphore(VkDevice device, const VkSemaphoreCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSemaphore* pSemaphore) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCreateSemaphore\n";
    }
    VkResult result = device_dispatch_table(device)->CreateSemaphore(device, pCreateInfo, pAllocator, pSemaphore);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkDestroySemaphore(VkDevice device, VkSemaphore semaphore, const VkAllocationCallbacks* pAllocator) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkDestroySemaphore\n";
    }
    device_dispatch_table(device)->DestroySemaphore(device, semaphore, pAllocator);
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkCreateQueryPool(VkDevice device, const VkQueryPoolCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkQueryPool* pQueryPool) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCreateQueryPool\n";
    }
    VkResult result = device_dispatch_table(device)->CreateQueryPool(device, pCreateInfo, pAllocator, pQueryPool);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkDestroyQueryPool(VkDevice device, VkQueryPool queryPool, const VkAllocationCallbacks* pAllocator) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkDestroyQueryPool\n";
    }
    device_dispatch_table(device)->DestroyQueryPool(device, queryPool, pAllocator);
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkGetQueryPoolResults(VkDevice device, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount, size_t dataSize, void* pData, VkDeviceSize stride, VkQueryResultFlags flags) {
    VkResult result = device_dispatch_table(device)->GetQueryPoolResults(device, queryPool, firstQuery, queryCount, dataSize, pData, stride, flags);
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetQueryPoolResults\n";
    }
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkCreateBuffer(VkDevice device, const VkBufferCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkBuffer* pBuffer) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCreateBuffer\n";
    }
    VkResult result = device_dispatch_table(device)->CreateBuffer(device, pCreateInfo, pAllocator, pBuffer);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkDestroyBuffer(VkDevice device, VkBuffer buffer, const VkAllocationCallbacks* pAllocator) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkDestroyBuffer\n";
    }
    device_dispatch_table(device)->DestroyBuffer(device, buffer, pAllocator);
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkCreateImage(VkDevice device, const VkImageCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkImage* pImage) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCreateImage\n";
    }
    VkResult result = device_dispatch_table(device)->CreateImage(device, pCreateInfo, pAllocator, pImage);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkDestroyImage(VkDevice device, VkImage image, const VkAllocationCallbacks* pAllocator) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkDestroyImage\n";
    }
    device_dispatch_table(device)->DestroyImage(device, image, pAllocator);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkGetImageSubresourceLayout(VkDevice device, VkImage image, const VkImageSubresource* pSubresource, VkSubresourceLayout* pLayout) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetImageSubresourceLayout\n";
    }
    device_dispatch_table(device)->GetImageSubresourceLayout(device, image, pSubresource, pLayout);
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkCreateImageView(VkDevice device, const VkImageViewCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkImageView* pView) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCreateImageView\n";
    }
    VkResult result = device_dispatch_table(device)->CreateImageView(device, pCreateInfo, pAllocator, pView);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkDestroyImageView(VkDevice device, VkImageView imageView, const VkAllocationCallbacks* pAllocator) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkDestroyImageView\n";
    }
    device_dispatch_table(device)->DestroyImageView(device, imageView, pAllocator);
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkCreateCommandPool(VkDevice device, const VkCommandPoolCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkCommandPool* pCommandPool) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCreateCommandPool\n";
    }
    VkResult result = device_dispatch_table(device)->CreateCommandPool(device, pCreateInfo, pAllocator, pCommandPool);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkDestroyCommandPool(VkDevice device, VkCommandPool commandPool, const VkAllocationCallbacks* pAllocator) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkDestroyCommandPool\n";
    }
    device_dispatch_table(device)->DestroyCommandPool(device, commandPool, pAllocator);
    ApiDumpInstance::current().eraseCmdBufferPool(device, commandPool);
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkResetCommandPool(VkDevice device, VkCommandPool commandPool, VkCommandPoolResetFlags flags) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkResetCommandPool\n";
    }
    VkResult result = device_dispatch_table(device)->ResetCommandPool(device, commandPool, flags);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkAllocateCommandBuffers(VkDevice device, const VkCommandBufferAllocateInfo* pAllocateInfo, VkCommandBuffer* pCommandBuffers) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkAllocateCommandBuffers\n";
    }
    VkResult result = device_dispatch_table(device)->AllocateCommandBuffers(device, pAllocateInfo, pCommandBuffers);
    if (result == VK_SUCCESS)
        ApiDumpInstance::current().addCmdBuffers(
            device,
            pAllocateInfo->commandPool,
            std::vector<VkCommandBuffer>(pCommandBuffers, pCommandBuffers + pAllocateInfo->commandBufferCount),
            pAllocateInfo->level);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkFreeCommandBuffers(VkDevice device, VkCommandPool commandPool, uint32_t commandBufferCount, const VkCommandBuffer* pCommandBuffers) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkFreeCommandBuffers\n";
    }
    device_dispatch_table(device)->FreeCommandBuffers(device, commandPool, commandBufferCount, pCommandBuffers);
    ApiDumpInstance::current().eraseCmdBuffers(device, commandPool, std::vector<VkCommandBuffer>(pCommandBuffers, pCommandBuffers + commandBufferCount));
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkBeginCommandBuffer(VkCommandBuffer commandBuffer, const VkCommandBufferBeginInfo* pBeginInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkBeginCommandBuffer\n";
    }
    VkResult result = device_dispatch_table(commandBuffer)->BeginCommandBuffer(commandBuffer, pBeginInfo);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkEndCommandBuffer(VkCommandBuffer commandBuffer) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkEndCommandBuffer\n";
    }
    VkResult result = device_dispatch_table(commandBuffer)->EndCommandBuffer(commandBuffer);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkResetCommandBuffer(VkCommandBuffer commandBuffer, VkCommandBufferResetFlags flags) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkResetCommandBuffer\n";
    }
    VkResult result = device_dispatch_table(commandBuffer)->ResetCommandBuffer(commandBuffer, flags);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdCopyBuffer(VkCommandBuffer commandBuffer, VkBuffer srcBuffer, VkBuffer dstBuffer, uint32_t regionCount, const VkBufferCopy* pRegions) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdCopyBuffer\n";
    }
    device_dispatch_table(commandBuffer)->CmdCopyBuffer(commandBuffer, srcBuffer, dstBuffer, regionCount, pRegions);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdCopyImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkImageCopy* pRegions) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdCopyImage\n";
    }
    device_dispatch_table(commandBuffer)->CmdCopyImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdCopyBufferToImage(VkCommandBuffer commandBuffer, VkBuffer srcBuffer, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkBufferImageCopy* pRegions) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdCopyBufferToImage\n";
    }
    device_dispatch_table(commandBuffer)->CmdCopyBufferToImage(commandBuffer, srcBuffer, dstImage, dstImageLayout, regionCount, pRegions);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdCopyImageToBuffer(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkBuffer dstBuffer, uint32_t regionCount, const VkBufferImageCopy* pRegions) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdCopyImageToBuffer\n";
    }
    device_dispatch_table(commandBuffer)->CmdCopyImageToBuffer(commandBuffer, srcImage, srcImageLayout, dstBuffer, regionCount, pRegions);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdUpdateBuffer(VkCommandBuffer commandBuffer, VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize dataSize, const void* pData) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdUpdateBuffer\n";
    }
    device_dispatch_table(commandBuffer)->CmdUpdateBuffer(commandBuffer, dstBuffer, dstOffset, dataSize, pData);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdFillBuffer(VkCommandBuffer commandBuffer, VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize size, uint32_t data) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdFillBuffer\n";
    }
    device_dispatch_table(commandBuffer)->CmdFillBuffer(commandBuffer, dstBuffer, dstOffset, size, data);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdPipelineBarrier(VkCommandBuffer commandBuffer, VkPipelineStageFlags srcStageMask, VkPipelineStageFlags dstStageMask, VkDependencyFlags dependencyFlags, uint32_t memoryBarrierCount, const VkMemoryBarrier* pMemoryBarriers, uint32_t bufferMemoryBarrierCount, const VkBufferMemoryBarrier* pBufferMemoryBarriers, uint32_t imageMemoryBarrierCount, const VkImageMemoryBarrier* pImageMemoryBarriers) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdPipelineBarrier\n";
    }
    device_dispatch_table(commandBuffer)->CmdPipelineBarrier(commandBuffer, srcStageMask, dstStageMask, dependencyFlags, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdBeginQuery(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query, VkQueryControlFlags flags) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdBeginQuery\n";
    }
    device_dispatch_table(commandBuffer)->CmdBeginQuery(commandBuffer, queryPool, query, flags);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdEndQuery(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdEndQuery\n";
    }
    device_dispatch_table(commandBuffer)->CmdEndQuery(commandBuffer, queryPool, query);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdResetQueryPool(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdResetQueryPool\n";
    }
    device_dispatch_table(commandBuffer)->CmdResetQueryPool(commandBuffer, queryPool, firstQuery, queryCount);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdWriteTimestamp(VkCommandBuffer commandBuffer, VkPipelineStageFlagBits pipelineStage, VkQueryPool queryPool, uint32_t query) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdWriteTimestamp\n";
    }
    device_dispatch_table(commandBuffer)->CmdWriteTimestamp(commandBuffer, pipelineStage, queryPool, query);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdCopyQueryPoolResults(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount, VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize stride, VkQueryResultFlags flags) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdCopyQueryPoolResults\n";
    }
    device_dispatch_table(commandBuffer)->CmdCopyQueryPoolResults(commandBuffer, queryPool, firstQuery, queryCount, dstBuffer, dstOffset, stride, flags);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdExecuteCommands(VkCommandBuffer commandBuffer, uint32_t commandBufferCount, const VkCommandBuffer* pCommandBuffers) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdExecuteCommands\n";
    }
    device_dispatch_table(commandBuffer)->CmdExecuteCommands(commandBuffer, commandBufferCount, pCommandBuffers);
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkCreateEvent(VkDevice device, const VkEventCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkEvent* pEvent) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCreateEvent\n";
    }
    VkResult result = device_dispatch_table(device)->CreateEvent(device, pCreateInfo, pAllocator, pEvent);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkDestroyEvent(VkDevice device, VkEvent event, const VkAllocationCallbacks* pAllocator) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkDestroyEvent\n";
    }
    device_dispatch_table(device)->DestroyEvent(device, event, pAllocator);
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkGetEventStatus(VkDevice device, VkEvent event) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetEventStatus\n";
    }
    VkResult result = device_dispatch_table(device)->GetEventStatus(device, event);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkSetEvent(VkDevice device, VkEvent event) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkSetEvent\n";
    }
    VkResult result = device_dispatch_table(device)->SetEvent(device, event);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkResetEvent(VkDevice device, VkEvent event) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkResetEvent\n";
    }
    VkResult result = device_dispatch_table(device)->ResetEvent(device, event);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkCreateBufferView(VkDevice device, const VkBufferViewCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkBufferView* pView) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCreateBufferView\n";
    }
    VkResult result = device_dispatch_table(device)->CreateBufferView(device, pCreateInfo, pAllocator, pView);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkDestroyBufferView(VkDevice device, VkBufferView bufferView, const VkAllocationCallbacks* pAllocator) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkDestroyBufferView\n";
    }
    device_dispatch_table(device)->DestroyBufferView(device, bufferView, pAllocator);
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkCreateShaderModule(VkDevice device, const VkShaderModuleCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkShaderModule* pShaderModule) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCreateShaderModule\n";
    }
    VkResult result = device_dispatch_table(device)->CreateShaderModule(device, pCreateInfo, pAllocator, pShaderModule);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkDestroyShaderModule(VkDevice device, VkShaderModule shaderModule, const VkAllocationCallbacks* pAllocator) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkDestroyShaderModule\n";
    }
    device_dispatch_table(device)->DestroyShaderModule(device, shaderModule, pAllocator);
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkCreatePipelineCache(VkDevice device, const VkPipelineCacheCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkPipelineCache* pPipelineCache) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCreatePipelineCache\n";
    }
    VkResult result = device_dispatch_table(device)->CreatePipelineCache(device, pCreateInfo, pAllocator, pPipelineCache);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkDestroyPipelineCache(VkDevice device, VkPipelineCache pipelineCache, const VkAllocationCallbacks* pAllocator) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkDestroyPipelineCache\n";
    }
    device_dispatch_table(device)->DestroyPipelineCache(device, pipelineCache, pAllocator);
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkGetPipelineCacheData(VkDevice device, VkPipelineCache pipelineCache, size_t* pDataSize, void* pData) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetPipelineCacheData\n";
    }
    VkResult result = device_dispatch_table(device)->GetPipelineCacheData(device, pipelineCache, pDataSize, pData);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkMergePipelineCaches(VkDevice device, VkPipelineCache dstCache, uint32_t srcCacheCount, const VkPipelineCache* pSrcCaches) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkMergePipelineCaches\n";
    }
    VkResult result = device_dispatch_table(device)->MergePipelineCaches(device, dstCache, srcCacheCount, pSrcCaches);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkCreateComputePipelines(VkDevice device, VkPipelineCache pipelineCache, uint32_t createInfoCount, const VkComputePipelineCreateInfo* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCreateComputePipelines\n";
    }
    VkResult result = device_dispatch_table(device)->CreateComputePipelines(device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkDestroyPipeline(VkDevice device, VkPipeline pipeline, const VkAllocationCallbacks* pAllocator) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkDestroyPipeline\n";
    }
    device_dispatch_table(device)->DestroyPipeline(device, pipeline, pAllocator);
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkCreatePipelineLayout(VkDevice device, const VkPipelineLayoutCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkPipelineLayout* pPipelineLayout) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCreatePipelineLayout\n";
    }
    VkResult result = device_dispatch_table(device)->CreatePipelineLayout(device, pCreateInfo, pAllocator, pPipelineLayout);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkDestroyPipelineLayout(VkDevice device, VkPipelineLayout pipelineLayout, const VkAllocationCallbacks* pAllocator) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkDestroyPipelineLayout\n";
    }
    device_dispatch_table(device)->DestroyPipelineLayout(device, pipelineLayout, pAllocator);
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkCreateSampler(VkDevice device, const VkSamplerCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSampler* pSampler) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCreateSampler\n";
    }
    VkResult result = device_dispatch_table(device)->CreateSampler(device, pCreateInfo, pAllocator, pSampler);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkDestroySampler(VkDevice device, VkSampler sampler, const VkAllocationCallbacks* pAllocator) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkDestroySampler\n";
    }
    device_dispatch_table(device)->DestroySampler(device, sampler, pAllocator);
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkCreateDescriptorSetLayout(VkDevice device, const VkDescriptorSetLayoutCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDescriptorSetLayout* pSetLayout) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCreateDescriptorSetLayout\n";
    }
    VkResult result = device_dispatch_table(device)->CreateDescriptorSetLayout(device, pCreateInfo, pAllocator, pSetLayout);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkDestroyDescriptorSetLayout(VkDevice device, VkDescriptorSetLayout descriptorSetLayout, const VkAllocationCallbacks* pAllocator) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkDestroyDescriptorSetLayout\n";
    }
    device_dispatch_table(device)->DestroyDescriptorSetLayout(device, descriptorSetLayout, pAllocator);
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkCreateDescriptorPool(VkDevice device, const VkDescriptorPoolCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDescriptorPool* pDescriptorPool) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCreateDescriptorPool\n";
    }
    VkResult result = device_dispatch_table(device)->CreateDescriptorPool(device, pCreateInfo, pAllocator, pDescriptorPool);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkDestroyDescriptorPool(VkDevice device, VkDescriptorPool descriptorPool, const VkAllocationCallbacks* pAllocator) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkDestroyDescriptorPool\n";
    }
    device_dispatch_table(device)->DestroyDescriptorPool(device, descriptorPool, pAllocator);
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkResetDescriptorPool(VkDevice device, VkDescriptorPool descriptorPool, VkDescriptorPoolResetFlags flags) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkResetDescriptorPool\n";
    }
    VkResult result = device_dispatch_table(device)->ResetDescriptorPool(device, descriptorPool, flags);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkAllocateDescriptorSets(VkDevice device, const VkDescriptorSetAllocateInfo* pAllocateInfo, VkDescriptorSet* pDescriptorSets) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkAllocateDescriptorSets\n";
    }
    VkResult result = device_dispatch_table(device)->AllocateDescriptorSets(device, pAllocateInfo, pDescriptorSets);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkFreeDescriptorSets(VkDevice device, VkDescriptorPool descriptorPool, uint32_t descriptorSetCount, const VkDescriptorSet* pDescriptorSets) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkFreeDescriptorSets\n";
    }
    VkResult result = device_dispatch_table(device)->FreeDescriptorSets(device, descriptorPool, descriptorSetCount, pDescriptorSets);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkUpdateDescriptorSets(VkDevice device, uint32_t descriptorWriteCount, const VkWriteDescriptorSet* pDescriptorWrites, uint32_t descriptorCopyCount, const VkCopyDescriptorSet* pDescriptorCopies) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkUpdateDescriptorSets\n";
    }
    device_dispatch_table(device)->UpdateDescriptorSets(device, descriptorWriteCount, pDescriptorWrites, descriptorCopyCount, pDescriptorCopies);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdBindPipeline(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipeline pipeline) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdBindPipeline\n";
    }
    device_dispatch_table(commandBuffer)->CmdBindPipeline(commandBuffer, pipelineBindPoint, pipeline);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdBindDescriptorSets(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipelineLayout layout, uint32_t firstSet, uint32_t descriptorSetCount, const VkDescriptorSet* pDescriptorSets, uint32_t dynamicOffsetCount, const uint32_t* pDynamicOffsets) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdBindDescriptorSets\n";
    }
    device_dispatch_table(commandBuffer)->CmdBindDescriptorSets(commandBuffer, pipelineBindPoint, layout, firstSet, descriptorSetCount, pDescriptorSets, dynamicOffsetCount, pDynamicOffsets);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdClearColorImage(VkCommandBuffer commandBuffer, VkImage image, VkImageLayout imageLayout, const VkClearColorValue* pColor, uint32_t rangeCount, const VkImageSubresourceRange* pRanges) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdClearColorImage\n";
    }
    device_dispatch_table(commandBuffer)->CmdClearColorImage(commandBuffer, image, imageLayout, pColor, rangeCount, pRanges);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdDispatch(VkCommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdDispatch\n";
    }
    device_dispatch_table(commandBuffer)->CmdDispatch(commandBuffer, groupCountX, groupCountY, groupCountZ);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdDispatchIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdDispatchIndirect\n";
    }
    device_dispatch_table(commandBuffer)->CmdDispatchIndirect(commandBuffer, buffer, offset);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdSetEvent(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags stageMask) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdSetEvent\n";
    }
    device_dispatch_table(commandBuffer)->CmdSetEvent(commandBuffer, event, stageMask);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdResetEvent(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags stageMask) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdResetEvent\n";
    }
    device_dispatch_table(commandBuffer)->CmdResetEvent(commandBuffer, event, stageMask);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdWaitEvents(VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents, VkPipelineStageFlags srcStageMask, VkPipelineStageFlags dstStageMask, uint32_t memoryBarrierCount, const VkMemoryBarrier* pMemoryBarriers, uint32_t bufferMemoryBarrierCount, const VkBufferMemoryBarrier* pBufferMemoryBarriers, uint32_t imageMemoryBarrierCount, const VkImageMemoryBarrier* pImageMemoryBarriers) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdWaitEvents\n";
    }
    device_dispatch_table(commandBuffer)->CmdWaitEvents(commandBuffer, eventCount, pEvents, srcStageMask, dstStageMask, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdPushConstants(VkCommandBuffer commandBuffer, VkPipelineLayout layout, VkShaderStageFlags stageFlags, uint32_t offset, uint32_t size, const void* pValues) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdPushConstants\n";
    }
    device_dispatch_table(commandBuffer)->CmdPushConstants(commandBuffer, layout, stageFlags, offset, size, pValues);
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkCreateGraphicsPipelines(VkDevice device, VkPipelineCache pipelineCache, uint32_t createInfoCount, const VkGraphicsPipelineCreateInfo* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCreateGraphicsPipelines\n";
    }
    VkResult result = device_dispatch_table(device)->CreateGraphicsPipelines(device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkCreateFramebuffer(VkDevice device, const VkFramebufferCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkFramebuffer* pFramebuffer) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCreateFramebuffer\n";
    }
    VkResult result = device_dispatch_table(device)->CreateFramebuffer(device, pCreateInfo, pAllocator, pFramebuffer);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkDestroyFramebuffer(VkDevice device, VkFramebuffer framebuffer, const VkAllocationCallbacks* pAllocator) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkDestroyFramebuffer\n";
    }
    device_dispatch_table(device)->DestroyFramebuffer(device, framebuffer, pAllocator);
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkCreateRenderPass(VkDevice device, const VkRenderPassCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkRenderPass* pRenderPass) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCreateRenderPass\n";
    }
    VkResult result = device_dispatch_table(device)->CreateRenderPass(device, pCreateInfo, pAllocator, pRenderPass);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkDestroyRenderPass(VkDevice device, VkRenderPass renderPass, const VkAllocationCallbacks* pAllocator) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkDestroyRenderPass\n";
    }
    device_dispatch_table(device)->DestroyRenderPass(device, renderPass, pAllocator);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkGetRenderAreaGranularity(VkDevice device, VkRenderPass renderPass, VkExtent2D* pGranularity) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetRenderAreaGranularity\n";
    }
    device_dispatch_table(device)->GetRenderAreaGranularity(device, renderPass, pGranularity);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdSetViewport(VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount, const VkViewport* pViewports) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdSetViewport\n";
    }
    device_dispatch_table(commandBuffer)->CmdSetViewport(commandBuffer, firstViewport, viewportCount, pViewports);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdSetScissor(VkCommandBuffer commandBuffer, uint32_t firstScissor, uint32_t scissorCount, const VkRect2D* pScissors) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdSetScissor\n";
    }
    device_dispatch_table(commandBuffer)->CmdSetScissor(commandBuffer, firstScissor, scissorCount, pScissors);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdSetLineWidth(VkCommandBuffer commandBuffer, float lineWidth) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdSetLineWidth\n";
    }
    device_dispatch_table(commandBuffer)->CmdSetLineWidth(commandBuffer, lineWidth);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdSetDepthBias(VkCommandBuffer commandBuffer, float depthBiasConstantFactor, float depthBiasClamp, float depthBiasSlopeFactor) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdSetDepthBias\n";
    }
    device_dispatch_table(commandBuffer)->CmdSetDepthBias(commandBuffer, depthBiasConstantFactor, depthBiasClamp, depthBiasSlopeFactor);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdSetBlendConstants(VkCommandBuffer commandBuffer, const float blendConstants[4]) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdSetBlendConstants\n";
    }
    device_dispatch_table(commandBuffer)->CmdSetBlendConstants(commandBuffer, blendConstants);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdSetDepthBounds(VkCommandBuffer commandBuffer, float minDepthBounds, float maxDepthBounds) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdSetDepthBounds\n";
    }
    device_dispatch_table(commandBuffer)->CmdSetDepthBounds(commandBuffer, minDepthBounds, maxDepthBounds);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdSetStencilCompareMask(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, uint32_t compareMask) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdSetStencilCompareMask\n";
    }
    device_dispatch_table(commandBuffer)->CmdSetStencilCompareMask(commandBuffer, faceMask, compareMask);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdSetStencilWriteMask(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, uint32_t writeMask) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdSetStencilWriteMask\n";
    }
    device_dispatch_table(commandBuffer)->CmdSetStencilWriteMask(commandBuffer, faceMask, writeMask);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdSetStencilReference(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, uint32_t reference) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdSetStencilReference\n";
    }
    device_dispatch_table(commandBuffer)->CmdSetStencilReference(commandBuffer, faceMask, reference);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdBindIndexBuffer(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkIndexType indexType) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdBindIndexBuffer\n";
    }
    device_dispatch_table(commandBuffer)->CmdBindIndexBuffer(commandBuffer, buffer, offset, indexType);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdBindVertexBuffers(VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount, const VkBuffer* pBuffers, const VkDeviceSize* pOffsets) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdBindVertexBuffers\n";
    }
    device_dispatch_table(commandBuffer)->CmdBindVertexBuffers(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdDraw(VkCommandBuffer commandBuffer, uint32_t vertexCount, uint32_t instanceCount, uint32_t firstVertex, uint32_t firstInstance) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdDraw\n";
    }
    device_dispatch_table(commandBuffer)->CmdDraw(commandBuffer, vertexCount, instanceCount, firstVertex, firstInstance);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdDrawIndexed(VkCommandBuffer commandBuffer, uint32_t indexCount, uint32_t instanceCount, uint32_t firstIndex, int32_t vertexOffset, uint32_t firstInstance) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdDrawIndexed\n";
    }
    device_dispatch_table(commandBuffer)->CmdDrawIndexed(commandBuffer, indexCount, instanceCount, firstIndex, vertexOffset, firstInstance);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdDrawIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdDrawIndirect\n";
    }
    device_dispatch_table(commandBuffer)->CmdDrawIndirect(commandBuffer, buffer, offset, drawCount, stride);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdDrawIndexedIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdDrawIndexedIndirect\n";
    }
    device_dispatch_table(commandBuffer)->CmdDrawIndexedIndirect(commandBuffer, buffer, offset, drawCount, stride);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdBlitImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkImageBlit* pRegions, VkFilter filter) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdBlitImage\n";
    }
    device_dispatch_table(commandBuffer)->CmdBlitImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions, filter);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdClearDepthStencilImage(VkCommandBuffer commandBuffer, VkImage image, VkImageLayout imageLayout, const VkClearDepthStencilValue* pDepthStencil, uint32_t rangeCount, const VkImageSubresourceRange* pRanges) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdClearDepthStencilImage\n";
    }
    device_dispatch_table(commandBuffer)->CmdClearDepthStencilImage(commandBuffer, image, imageLayout, pDepthStencil, rangeCount, pRanges);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdClearAttachments(VkCommandBuffer commandBuffer, uint32_t attachmentCount, const VkClearAttachment* pAttachments, uint32_t rectCount, const VkClearRect* pRects) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdClearAttachments\n";
    }
    device_dispatch_table(commandBuffer)->CmdClearAttachments(commandBuffer, attachmentCount, pAttachments, rectCount, pRects);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdResolveImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkImageResolve* pRegions) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdResolveImage\n";
    }
    device_dispatch_table(commandBuffer)->CmdResolveImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdBeginRenderPass(VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo* pRenderPassBegin, VkSubpassContents contents) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdBeginRenderPass\n";
    }
    device_dispatch_table(commandBuffer)->CmdBeginRenderPass(commandBuffer, pRenderPassBegin, contents);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdNextSubpass(VkCommandBuffer commandBuffer, VkSubpassContents contents) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdNextSubpass\n";
    }
    device_dispatch_table(commandBuffer)->CmdNextSubpass(commandBuffer, contents);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdEndRenderPass(VkCommandBuffer commandBuffer) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdEndRenderPass\n";
    }
    device_dispatch_table(commandBuffer)->CmdEndRenderPass(commandBuffer);
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkBindBufferMemory2(VkDevice device, uint32_t bindInfoCount, const VkBindBufferMemoryInfo* pBindInfos) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkBindBufferMemory2\n";
    }
    VkResult result = device_dispatch_table(device)->BindBufferMemory2(device, bindInfoCount, pBindInfos);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkBindImageMemory2(VkDevice device, uint32_t bindInfoCount, const VkBindImageMemoryInfo* pBindInfos) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkBindImageMemory2\n";
    }
    VkResult result = device_dispatch_table(device)->BindImageMemory2(device, bindInfoCount, pBindInfos);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkGetDeviceGroupPeerMemoryFeatures(VkDevice device, uint32_t heapIndex, uint32_t localDeviceIndex, uint32_t remoteDeviceIndex, VkPeerMemoryFeatureFlags* pPeerMemoryFeatures) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetDeviceGroupPeerMemoryFeatures\n";
    }
    device_dispatch_table(device)->GetDeviceGroupPeerMemoryFeatures(device, heapIndex, localDeviceIndex, remoteDeviceIndex, pPeerMemoryFeatures);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdSetDeviceMask(VkCommandBuffer commandBuffer, uint32_t deviceMask) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdSetDeviceMask\n";
    }
    device_dispatch_table(commandBuffer)->CmdSetDeviceMask(commandBuffer, deviceMask);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkGetImageMemoryRequirements2(VkDevice device, const VkImageMemoryRequirementsInfo2* pInfo, VkMemoryRequirements2* pMemoryRequirements) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetImageMemoryRequirements2\n";
    }
    device_dispatch_table(device)->GetImageMemoryRequirements2(device, pInfo, pMemoryRequirements);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkGetBufferMemoryRequirements2(VkDevice device, const VkBufferMemoryRequirementsInfo2* pInfo, VkMemoryRequirements2* pMemoryRequirements) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetBufferMemoryRequirements2\n";
    }
    device_dispatch_table(device)->GetBufferMemoryRequirements2(device, pInfo, pMemoryRequirements);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkGetImageSparseMemoryRequirements2(VkDevice device, const VkImageSparseMemoryRequirementsInfo2* pInfo, uint32_t* pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements2* pSparseMemoryRequirements) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetImageSparseMemoryRequirements2\n";
    }
    device_dispatch_table(device)->GetImageSparseMemoryRequirements2(device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkTrimCommandPool(VkDevice device, VkCommandPool commandPool, VkCommandPoolTrimFlags flags) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkTrimCommandPool\n";
    }
    device_dispatch_table(device)->TrimCommandPool(device, commandPool, flags);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkGetDeviceQueue2(VkDevice device, const VkDeviceQueueInfo2* pQueueInfo, VkQueue* pQueue) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetDeviceQueue2\n";
    }
    device_dispatch_table(device)->GetDeviceQueue2(device, pQueueInfo, pQueue);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdDispatchBase(VkCommandBuffer commandBuffer, uint32_t baseGroupX, uint32_t baseGroupY, uint32_t baseGroupZ, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdDispatchBase\n";
    }
    device_dispatch_table(commandBuffer)->CmdDispatchBase(commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkCreateDescriptorUpdateTemplate(VkDevice device, const VkDescriptorUpdateTemplateCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDescriptorUpdateTemplate* pDescriptorUpdateTemplate) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCreateDescriptorUpdateTemplate\n";
    }
    VkResult result = device_dispatch_table(device)->CreateDescriptorUpdateTemplate(device, pCreateInfo, pAllocator, pDescriptorUpdateTemplate);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkDestroyDescriptorUpdateTemplate(VkDevice device, VkDescriptorUpdateTemplate descriptorUpdateTemplate, const VkAllocationCallbacks* pAllocator) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkDestroyDescriptorUpdateTemplate\n";
    }
    device_dispatch_table(device)->DestroyDescriptorUpdateTemplate(device, descriptorUpdateTemplate, pAllocator);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkUpdateDescriptorSetWithTemplate(VkDevice device, VkDescriptorSet descriptorSet, VkDescriptorUpdateTemplate descriptorUpdateTemplate, const void* pData) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkUpdateDescriptorSetWithTemplate\n";
    }
    device_dispatch_table(device)->UpdateDescriptorSetWithTemplate(device, descriptorSet, descriptorUpdateTemplate, pData);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkGetDescriptorSetLayoutSupport(VkDevice device, const VkDescriptorSetLayoutCreateInfo* pCreateInfo, VkDescriptorSetLayoutSupport* pSupport) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetDescriptorSetLayoutSupport\n";
    }
    device_dispatch_table(device)->GetDescriptorSetLayoutSupport(device, pCreateInfo, pSupport);
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkCreateSamplerYcbcrConversion(VkDevice device, const VkSamplerYcbcrConversionCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSamplerYcbcrConversion* pYcbcrConversion) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCreateSamplerYcbcrConversion\n";
    }
    VkResult result = device_dispatch_table(device)->CreateSamplerYcbcrConversion(device, pCreateInfo, pAllocator, pYcbcrConversion);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkDestroySamplerYcbcrConversion(VkDevice device, VkSamplerYcbcrConversion ycbcrConversion, const VkAllocationCallbacks* pAllocator) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkDestroySamplerYcbcrConversion\n";
    }
    device_dispatch_table(device)->DestroySamplerYcbcrConversion(device, ycbcrConversion, pAllocator);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkResetQueryPool(VkDevice device, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkResetQueryPool\n";
    }
    device_dispatch_table(device)->ResetQueryPool(device, queryPool, firstQuery, queryCount);
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkGetSemaphoreCounterValue(VkDevice device, VkSemaphore semaphore, uint64_t* pValue) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetSemaphoreCounterValue\n";
    }
    VkResult result = device_dispatch_table(device)->GetSemaphoreCounterValue(device, semaphore, pValue);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkWaitSemaphores(VkDevice device, const VkSemaphoreWaitInfo* pWaitInfo, uint64_t timeout) {
    VkResult result = device_dispatch_table(device)->WaitSemaphores(device, pWaitInfo, timeout);
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkWaitSemaphores\n";
    }
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkSignalSemaphore(VkDevice device, const VkSemaphoreSignalInfo* pSignalInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkSignalSemaphore\n";
    }
    VkResult result = device_dispatch_table(device)->SignalSemaphore(device, pSignalInfo);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkDeviceAddress VKAPI_CALL vkGetBufferDeviceAddress(VkDevice device, const VkBufferDeviceAddressInfo* pInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetBufferDeviceAddress\n";
    }
    VkDeviceAddress result = device_dispatch_table(device)->GetBufferDeviceAddress(device, pInfo);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR uint64_t VKAPI_CALL vkGetBufferOpaqueCaptureAddress(VkDevice device, const VkBufferDeviceAddressInfo* pInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetBufferOpaqueCaptureAddress\n";
    }
    uint64_t result = device_dispatch_table(device)->GetBufferOpaqueCaptureAddress(device, pInfo);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR uint64_t VKAPI_CALL vkGetDeviceMemoryOpaqueCaptureAddress(VkDevice device, const VkDeviceMemoryOpaqueCaptureAddressInfo* pInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetDeviceMemoryOpaqueCaptureAddress\n";
    }
    uint64_t result = device_dispatch_table(device)->GetDeviceMemoryOpaqueCaptureAddress(device, pInfo);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdDrawIndirectCount(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdDrawIndirectCount\n";
    }
    device_dispatch_table(commandBuffer)->CmdDrawIndirectCount(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdDrawIndexedIndirectCount(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdDrawIndexedIndirectCount\n";
    }
    device_dispatch_table(commandBuffer)->CmdDrawIndexedIndirectCount(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkCreateRenderPass2(VkDevice device, const VkRenderPassCreateInfo2* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkRenderPass* pRenderPass) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCreateRenderPass2\n";
    }
    VkResult result = device_dispatch_table(device)->CreateRenderPass2(device, pCreateInfo, pAllocator, pRenderPass);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdBeginRenderPass2(VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo* pRenderPassBegin, const VkSubpassBeginInfo* pSubpassBeginInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdBeginRenderPass2\n";
    }
    device_dispatch_table(commandBuffer)->CmdBeginRenderPass2(commandBuffer, pRenderPassBegin, pSubpassBeginInfo);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdNextSubpass2(VkCommandBuffer commandBuffer, const VkSubpassBeginInfo* pSubpassBeginInfo, const VkSubpassEndInfo* pSubpassEndInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdNextSubpass2\n";
    }
    device_dispatch_table(commandBuffer)->CmdNextSubpass2(commandBuffer, pSubpassBeginInfo, pSubpassEndInfo);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdEndRenderPass2(VkCommandBuffer commandBuffer, const VkSubpassEndInfo* pSubpassEndInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdEndRenderPass2\n";
    }
    device_dispatch_table(commandBuffer)->CmdEndRenderPass2(commandBuffer, pSubpassEndInfo);
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkCreatePrivateDataSlot(VkDevice device, const VkPrivateDataSlotCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkPrivateDataSlot* pPrivateDataSlot) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCreatePrivateDataSlot\n";
    }
    VkResult result = device_dispatch_table(device)->CreatePrivateDataSlot(device, pCreateInfo, pAllocator, pPrivateDataSlot);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkDestroyPrivateDataSlot(VkDevice device, VkPrivateDataSlot privateDataSlot, const VkAllocationCallbacks* pAllocator) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkDestroyPrivateDataSlot\n";
    }
    device_dispatch_table(device)->DestroyPrivateDataSlot(device, privateDataSlot, pAllocator);
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkSetPrivateData(VkDevice device, VkObjectType objectType, uint64_t objectHandle, VkPrivateDataSlot privateDataSlot, uint64_t data) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkSetPrivateData\n";
    }
    VkResult result = device_dispatch_table(device)->SetPrivateData(device, objectType, objectHandle, privateDataSlot, data);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkGetPrivateData(VkDevice device, VkObjectType objectType, uint64_t objectHandle, VkPrivateDataSlot privateDataSlot, uint64_t* pData) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetPrivateData\n";
    }
    device_dispatch_table(device)->GetPrivateData(device, objectType, objectHandle, privateDataSlot, pData);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdPipelineBarrier2(VkCommandBuffer commandBuffer, const VkDependencyInfo* pDependencyInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdPipelineBarrier2\n";
    }
    device_dispatch_table(commandBuffer)->CmdPipelineBarrier2(commandBuffer, pDependencyInfo);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdWriteTimestamp2(VkCommandBuffer commandBuffer, VkPipelineStageFlags2 stage, VkQueryPool queryPool, uint32_t query) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdWriteTimestamp2\n";
    }
    device_dispatch_table(commandBuffer)->CmdWriteTimestamp2(commandBuffer, stage, queryPool, query);
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkQueueSubmit2(VkQueue queue, uint32_t submitCount, const VkSubmitInfo2* pSubmits, VkFence fence) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkQueueSubmit2\n";
    }
    VkResult result = device_dispatch_table(queue)->QueueSubmit2(queue, submitCount, pSubmits, fence);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdCopyBuffer2(VkCommandBuffer commandBuffer, const VkCopyBufferInfo2* pCopyBufferInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdCopyBuffer2\n";
    }
    device_dispatch_table(commandBuffer)->CmdCopyBuffer2(commandBuffer, pCopyBufferInfo);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdCopyImage2(VkCommandBuffer commandBuffer, const VkCopyImageInfo2* pCopyImageInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdCopyImage2\n";
    }
    device_dispatch_table(commandBuffer)->CmdCopyImage2(commandBuffer, pCopyImageInfo);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdCopyBufferToImage2(VkCommandBuffer commandBuffer, const VkCopyBufferToImageInfo2* pCopyBufferToImageInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdCopyBufferToImage2\n";
    }
    device_dispatch_table(commandBuffer)->CmdCopyBufferToImage2(commandBuffer, pCopyBufferToImageInfo);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdCopyImageToBuffer2(VkCommandBuffer commandBuffer, const VkCopyImageToBufferInfo2* pCopyImageToBufferInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdCopyImageToBuffer2\n";
    }
    device_dispatch_table(commandBuffer)->CmdCopyImageToBuffer2(commandBuffer, pCopyImageToBufferInfo);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkGetDeviceBufferMemoryRequirements(VkDevice device, const VkDeviceBufferMemoryRequirements* pInfo, VkMemoryRequirements2* pMemoryRequirements) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetDeviceBufferMemoryRequirements\n";
    }
    device_dispatch_table(device)->GetDeviceBufferMemoryRequirements(device, pInfo, pMemoryRequirements);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkGetDeviceImageMemoryRequirements(VkDevice device, const VkDeviceImageMemoryRequirements* pInfo, VkMemoryRequirements2* pMemoryRequirements) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetDeviceImageMemoryRequirements\n";
    }
    device_dispatch_table(device)->GetDeviceImageMemoryRequirements(device, pInfo, pMemoryRequirements);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkGetDeviceImageSparseMemoryRequirements(VkDevice device, const VkDeviceImageMemoryRequirements* pInfo, uint32_t* pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements2* pSparseMemoryRequirements) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetDeviceImageSparseMemoryRequirements\n";
    }
    device_dispatch_table(device)->GetDeviceImageSparseMemoryRequirements(device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdSetEvent2(VkCommandBuffer commandBuffer, VkEvent event, const VkDependencyInfo* pDependencyInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdSetEvent2\n";
    }
    device_dispatch_table(commandBuffer)->CmdSetEvent2(commandBuffer, event, pDependencyInfo);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdResetEvent2(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags2 stageMask) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdResetEvent2\n";
    }
    device_dispatch_table(commandBuffer)->CmdResetEvent2(commandBuffer, event, stageMask);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdWaitEvents2(VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents, const VkDependencyInfo* pDependencyInfos) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdWaitEvents2\n";
    }
    device_dispatch_table(commandBuffer)->CmdWaitEvents2(commandBuffer, eventCount, pEvents, pDependencyInfos);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdBlitImage2(VkCommandBuffer commandBuffer, const VkBlitImageInfo2* pBlitImageInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdBlitImage2\n";
    }
    device_dispatch_table(commandBuffer)->CmdBlitImage2(commandBuffer, pBlitImageInfo);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdResolveImage2(VkCommandBuffer commandBuffer, const VkResolveImageInfo2* pResolveImageInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdResolveImage2\n";
    }
    device_dispatch_table(commandBuffer)->CmdResolveImage2(commandBuffer, pResolveImageInfo);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdBeginRendering(VkCommandBuffer commandBuffer, const VkRenderingInfo* pRenderingInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdBeginRendering\n";
    }
    device_dispatch_table(commandBuffer)->CmdBeginRendering(commandBuffer, pRenderingInfo);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdEndRendering(VkCommandBuffer commandBuffer) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdEndRendering\n";
    }
    device_dispatch_table(commandBuffer)->CmdEndRendering(commandBuffer);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdSetCullMode(VkCommandBuffer commandBuffer, VkCullModeFlags cullMode) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdSetCullMode\n";
    }
    device_dispatch_table(commandBuffer)->CmdSetCullMode(commandBuffer, cullMode);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdSetFrontFace(VkCommandBuffer commandBuffer, VkFrontFace frontFace) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdSetFrontFace\n";
    }
    device_dispatch_table(commandBuffer)->CmdSetFrontFace(commandBuffer, frontFace);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdSetPrimitiveTopology(VkCommandBuffer commandBuffer, VkPrimitiveTopology primitiveTopology) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdSetPrimitiveTopology\n";
    }
    device_dispatch_table(commandBuffer)->CmdSetPrimitiveTopology(commandBuffer, primitiveTopology);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdSetViewportWithCount(VkCommandBuffer commandBuffer, uint32_t viewportCount, const VkViewport* pViewports) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdSetViewportWithCount\n";
    }
    device_dispatch_table(commandBuffer)->CmdSetViewportWithCount(commandBuffer, viewportCount, pViewports);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdSetScissorWithCount(VkCommandBuffer commandBuffer, uint32_t scissorCount, const VkRect2D* pScissors) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdSetScissorWithCount\n";
    }
    device_dispatch_table(commandBuffer)->CmdSetScissorWithCount(commandBuffer, scissorCount, pScissors);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdBindVertexBuffers2(VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount, const VkBuffer* pBuffers, const VkDeviceSize* pOffsets, const VkDeviceSize* pSizes, const VkDeviceSize* pStrides) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdBindVertexBuffers2\n";
    }
    device_dispatch_table(commandBuffer)->CmdBindVertexBuffers2(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes, pStrides);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdSetDepthTestEnable(VkCommandBuffer commandBuffer, VkBool32 depthTestEnable) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdSetDepthTestEnable\n";
    }
    device_dispatch_table(commandBuffer)->CmdSetDepthTestEnable(commandBuffer, depthTestEnable);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdSetDepthWriteEnable(VkCommandBuffer commandBuffer, VkBool32 depthWriteEnable) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdSetDepthWriteEnable\n";
    }
    device_dispatch_table(commandBuffer)->CmdSetDepthWriteEnable(commandBuffer, depthWriteEnable);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdSetDepthCompareOp(VkCommandBuffer commandBuffer, VkCompareOp depthCompareOp) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdSetDepthCompareOp\n";
    }
    device_dispatch_table(commandBuffer)->CmdSetDepthCompareOp(commandBuffer, depthCompareOp);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdSetDepthBoundsTestEnable(VkCommandBuffer commandBuffer, VkBool32 depthBoundsTestEnable) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdSetDepthBoundsTestEnable\n";
    }
    device_dispatch_table(commandBuffer)->CmdSetDepthBoundsTestEnable(commandBuffer, depthBoundsTestEnable);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdSetStencilTestEnable(VkCommandBuffer commandBuffer, VkBool32 stencilTestEnable) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdSetStencilTestEnable\n";
    }
    device_dispatch_table(commandBuffer)->CmdSetStencilTestEnable(commandBuffer, stencilTestEnable);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdSetStencilOp(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, VkStencilOp failOp, VkStencilOp passOp, VkStencilOp depthFailOp, VkCompareOp compareOp) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdSetStencilOp\n";
    }
    device_dispatch_table(commandBuffer)->CmdSetStencilOp(commandBuffer, faceMask, failOp, passOp, depthFailOp, compareOp);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdSetRasterizerDiscardEnable(VkCommandBuffer commandBuffer, VkBool32 rasterizerDiscardEnable) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdSetRasterizerDiscardEnable\n";
    }
    device_dispatch_table(commandBuffer)->CmdSetRasterizerDiscardEnable(commandBuffer, rasterizerDiscardEnable);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdSetDepthBiasEnable(VkCommandBuffer commandBuffer, VkBool32 depthBiasEnable) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdSetDepthBiasEnable\n";
    }
    device_dispatch_table(commandBuffer)->CmdSetDepthBiasEnable(commandBuffer, depthBiasEnable);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdSetPrimitiveRestartEnable(VkCommandBuffer commandBuffer, VkBool32 primitiveRestartEnable) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdSetPrimitiveRestartEnable\n";
    }
    device_dispatch_table(commandBuffer)->CmdSetPrimitiveRestartEnable(commandBuffer, primitiveRestartEnable);
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkMapMemory2(VkDevice device, const VkMemoryMapInfo* pMemoryMapInfo, void** ppData) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkMapMemory2\n";
    }
    VkResult result = device_dispatch_table(device)->MapMemory2(device, pMemoryMapInfo, ppData);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkUnmapMemory2(VkDevice device, const VkMemoryUnmapInfo* pMemoryUnmapInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkUnmapMemory2\n";
    }
    VkResult result = device_dispatch_table(device)->UnmapMemory2(device, pMemoryUnmapInfo);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkGetDeviceImageSubresourceLayout(VkDevice device, const VkDeviceImageSubresourceInfo* pInfo, VkSubresourceLayout2* pLayout) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetDeviceImageSubresourceLayout\n";
    }
    device_dispatch_table(device)->GetDeviceImageSubresourceLayout(device, pInfo, pLayout);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkGetImageSubresourceLayout2(VkDevice device, VkImage image, const VkImageSubresource2* pSubresource, VkSubresourceLayout2* pLayout) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetImageSubresourceLayout2\n";
    }
    device_dispatch_table(device)->GetImageSubresourceLayout2(device, image, pSubresource, pLayout);
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkCopyMemoryToImage(VkDevice device, const VkCopyMemoryToImageInfo* pCopyMemoryToImageInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCopyMemoryToImage\n";
    }
    VkResult result = device_dispatch_table(device)->CopyMemoryToImage(device, pCopyMemoryToImageInfo);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkCopyImageToMemory(VkDevice device, const VkCopyImageToMemoryInfo* pCopyImageToMemoryInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCopyImageToMemory\n";
    }
    VkResult result = device_dispatch_table(device)->CopyImageToMemory(device, pCopyImageToMemoryInfo);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkCopyImageToImage(VkDevice device, const VkCopyImageToImageInfo* pCopyImageToImageInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCopyImageToImage\n";
    }
    VkResult result = device_dispatch_table(device)->CopyImageToImage(device, pCopyImageToImageInfo);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkTransitionImageLayout(VkDevice device, uint32_t transitionCount, const VkHostImageLayoutTransitionInfo* pTransitions) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkTransitionImageLayout\n";
    }
    VkResult result = device_dispatch_table(device)->TransitionImageLayout(device, transitionCount, pTransitions);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdPushDescriptorSet(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipelineLayout layout, uint32_t set, uint32_t descriptorWriteCount, const VkWriteDescriptorSet* pDescriptorWrites) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdPushDescriptorSet\n";
    }
    device_dispatch_table(commandBuffer)->CmdPushDescriptorSet(commandBuffer, pipelineBindPoint, layout, set, descriptorWriteCount, pDescriptorWrites);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdPushDescriptorSetWithTemplate(VkCommandBuffer commandBuffer, VkDescriptorUpdateTemplate descriptorUpdateTemplate, VkPipelineLayout layout, uint32_t set, const void* pData) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdPushDescriptorSetWithTemplate\n";
    }
    device_dispatch_table(commandBuffer)->CmdPushDescriptorSetWithTemplate(commandBuffer, descriptorUpdateTemplate, layout, set, pData);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdBindDescriptorSets2(VkCommandBuffer commandBuffer, const VkBindDescriptorSetsInfo* pBindDescriptorSetsInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdBindDescriptorSets2\n";
    }
    device_dispatch_table(commandBuffer)->CmdBindDescriptorSets2(commandBuffer, pBindDescriptorSetsInfo);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdPushConstants2(VkCommandBuffer commandBuffer, const VkPushConstantsInfo* pPushConstantsInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdPushConstants2\n";
    }
    device_dispatch_table(commandBuffer)->CmdPushConstants2(commandBuffer, pPushConstantsInfo);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdPushDescriptorSet2(VkCommandBuffer commandBuffer, const VkPushDescriptorSetInfo* pPushDescriptorSetInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdPushDescriptorSet2\n";
    }
    device_dispatch_table(commandBuffer)->CmdPushDescriptorSet2(commandBuffer, pPushDescriptorSetInfo);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdPushDescriptorSetWithTemplate2(VkCommandBuffer commandBuffer, const VkPushDescriptorSetWithTemplateInfo* pPushDescriptorSetWithTemplateInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdPushDescriptorSetWithTemplate2\n";
    }
    device_dispatch_table(commandBuffer)->CmdPushDescriptorSetWithTemplate2(commandBuffer, pPushDescriptorSetWithTemplateInfo);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdSetLineStipple(VkCommandBuffer commandBuffer, uint32_t lineStippleFactor, uint16_t lineStipplePattern) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdSetLineStipple\n";
    }
    device_dispatch_table(commandBuffer)->CmdSetLineStipple(commandBuffer, lineStippleFactor, lineStipplePattern);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdBindIndexBuffer2(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkDeviceSize size, VkIndexType indexType) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdBindIndexBuffer2\n";
    }
    device_dispatch_table(commandBuffer)->CmdBindIndexBuffer2(commandBuffer, buffer, offset, size, indexType);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkGetRenderingAreaGranularity(VkDevice device, const VkRenderingAreaInfo* pRenderingAreaInfo, VkExtent2D* pGranularity) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetRenderingAreaGranularity\n";
    }
    device_dispatch_table(device)->GetRenderingAreaGranularity(device, pRenderingAreaInfo, pGranularity);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdSetRenderingAttachmentLocations(VkCommandBuffer commandBuffer, const VkRenderingAttachmentLocationInfo* pLocationInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdSetRenderingAttachmentLocations\n";
    }
    device_dispatch_table(commandBuffer)->CmdSetRenderingAttachmentLocations(commandBuffer, pLocationInfo);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdSetRenderingInputAttachmentIndices(VkCommandBuffer commandBuffer, const VkRenderingInputAttachmentIndexInfo* pInputAttachmentIndexInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdSetRenderingInputAttachmentIndices\n";
    }
    device_dispatch_table(commandBuffer)->CmdSetRenderingInputAttachmentIndices(commandBuffer, pInputAttachmentIndexInfo);
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkCreateSwapchainKHR(VkDevice device, const VkSwapchainCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSwapchainKHR* pSwapchain) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCreateSwapchainKHR\n";
    }
    VkResult result = device_dispatch_table(device)->CreateSwapchainKHR(device, pCreateInfo, pAllocator, pSwapchain);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkDestroySwapchainKHR(VkDevice device, VkSwapchainKHR swapchain, const VkAllocationCallbacks* pAllocator) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkDestroySwapchainKHR\n";
    }
    device_dispatch_table(device)->DestroySwapchainKHR(device, swapchain, pAllocator);
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkGetSwapchainImagesKHR(VkDevice device, VkSwapchainKHR swapchain, uint32_t* pSwapchainImageCount, VkImage* pSwapchainImages) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetSwapchainImagesKHR\n";
    }
    VkResult result = device_dispatch_table(device)->GetSwapchainImagesKHR(device, swapchain, pSwapchainImageCount, pSwapchainImages);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkAcquireNextImageKHR(VkDevice device, VkSwapchainKHR swapchain, uint64_t timeout, VkSemaphore semaphore, VkFence fence, uint32_t* pImageIndex) {
    VkResult result = device_dispatch_table(device)->AcquireNextImageKHR(device, swapchain, timeout, semaphore, fence, pImageIndex);
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkAcquireNextImageKHR\n";
    }
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkQueuePresentKHR(VkQueue queue, const VkPresentInfoKHR* pPresentInfo) {
    VkResult result = device_dispatch_table(queue)->QueuePresentKHR(queue, pPresentInfo);
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkQueuePresentKHR\n";
    }
    ApiDumpInstance::current().nextFrame();
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkGetDeviceGroupPresentCapabilitiesKHR(VkDevice device, VkDeviceGroupPresentCapabilitiesKHR* pDeviceGroupPresentCapabilities) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetDeviceGroupPresentCapabilitiesKHR\n";
    }
    VkResult result = device_dispatch_table(device)->GetDeviceGroupPresentCapabilitiesKHR(device, pDeviceGroupPresentCapabilities);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkGetDeviceGroupSurfacePresentModesKHR(VkDevice device, VkSurfaceKHR surface, VkDeviceGroupPresentModeFlagsKHR* pModes) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetDeviceGroupSurfacePresentModesKHR\n";
    }
    VkResult result = device_dispatch_table(device)->GetDeviceGroupSurfacePresentModesKHR(device, surface, pModes);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkAcquireNextImage2KHR(VkDevice device, const VkAcquireNextImageInfoKHR* pAcquireInfo, uint32_t* pImageIndex) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkAcquireNextImage2KHR\n";
    }
    VkResult result = device_dispatch_table(device)->AcquireNextImage2KHR(device, pAcquireInfo, pImageIndex);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkCreateSharedSwapchainsKHR(VkDevice device, uint32_t swapchainCount, const VkSwapchainCreateInfoKHR* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkSwapchainKHR* pSwapchains) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCreateSharedSwapchainsKHR\n";
    }
    VkResult result = device_dispatch_table(device)->CreateSharedSwapchainsKHR(device, swapchainCount, pCreateInfos, pAllocator, pSwapchains);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkCreateVideoSessionKHR(VkDevice device, const VkVideoSessionCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkVideoSessionKHR* pVideoSession) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCreateVideoSessionKHR\n";
    }
    VkResult result = device_dispatch_table(device)->CreateVideoSessionKHR(device, pCreateInfo, pAllocator, pVideoSession);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkDestroyVideoSessionKHR(VkDevice device, VkVideoSessionKHR videoSession, const VkAllocationCallbacks* pAllocator) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkDestroyVideoSessionKHR\n";
    }
    device_dispatch_table(device)->DestroyVideoSessionKHR(device, videoSession, pAllocator);
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkGetVideoSessionMemoryRequirementsKHR(VkDevice device, VkVideoSessionKHR videoSession, uint32_t* pMemoryRequirementsCount, VkVideoSessionMemoryRequirementsKHR* pMemoryRequirements) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetVideoSessionMemoryRequirementsKHR\n";
    }
    VkResult result = device_dispatch_table(device)->GetVideoSessionMemoryRequirementsKHR(device, videoSession, pMemoryRequirementsCount, pMemoryRequirements);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkBindVideoSessionMemoryKHR(VkDevice device, VkVideoSessionKHR videoSession, uint32_t bindSessionMemoryInfoCount, const VkBindVideoSessionMemoryInfoKHR* pBindSessionMemoryInfos) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkBindVideoSessionMemoryKHR\n";
    }
    VkResult result = device_dispatch_table(device)->BindVideoSessionMemoryKHR(device, videoSession, bindSessionMemoryInfoCount, pBindSessionMemoryInfos);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkCreateVideoSessionParametersKHR(VkDevice device, const VkVideoSessionParametersCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkVideoSessionParametersKHR* pVideoSessionParameters) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCreateVideoSessionParametersKHR\n";
    }
    VkResult result = device_dispatch_table(device)->CreateVideoSessionParametersKHR(device, pCreateInfo, pAllocator, pVideoSessionParameters);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkUpdateVideoSessionParametersKHR(VkDevice device, VkVideoSessionParametersKHR videoSessionParameters, const VkVideoSessionParametersUpdateInfoKHR* pUpdateInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkUpdateVideoSessionParametersKHR\n";
    }
    VkResult result = device_dispatch_table(device)->UpdateVideoSessionParametersKHR(device, videoSessionParameters, pUpdateInfo);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkDestroyVideoSessionParametersKHR(VkDevice device, VkVideoSessionParametersKHR videoSessionParameters, const VkAllocationCallbacks* pAllocator) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkDestroyVideoSessionParametersKHR\n";
    }
    device_dispatch_table(device)->DestroyVideoSessionParametersKHR(device, videoSessionParameters, pAllocator);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdBeginVideoCodingKHR(VkCommandBuffer commandBuffer, const VkVideoBeginCodingInfoKHR* pBeginInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdBeginVideoCodingKHR\n";
    }
    device_dispatch_table(commandBuffer)->CmdBeginVideoCodingKHR(commandBuffer, pBeginInfo);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdEndVideoCodingKHR(VkCommandBuffer commandBuffer, const VkVideoEndCodingInfoKHR* pEndCodingInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdEndVideoCodingKHR\n";
    }
    device_dispatch_table(commandBuffer)->CmdEndVideoCodingKHR(commandBuffer, pEndCodingInfo);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdControlVideoCodingKHR(VkCommandBuffer commandBuffer, const VkVideoCodingControlInfoKHR* pCodingControlInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdControlVideoCodingKHR\n";
    }
    device_dispatch_table(commandBuffer)->CmdControlVideoCodingKHR(commandBuffer, pCodingControlInfo);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdDecodeVideoKHR(VkCommandBuffer commandBuffer, const VkVideoDecodeInfoKHR* pDecodeInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdDecodeVideoKHR\n";
    }
    device_dispatch_table(commandBuffer)->CmdDecodeVideoKHR(commandBuffer, pDecodeInfo);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdBeginRenderingKHR(VkCommandBuffer commandBuffer, const VkRenderingInfo* pRenderingInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdBeginRenderingKHR\n";
    }
    device_dispatch_table(commandBuffer)->CmdBeginRenderingKHR(commandBuffer, pRenderingInfo);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdEndRenderingKHR(VkCommandBuffer commandBuffer) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdEndRenderingKHR\n";
    }
    device_dispatch_table(commandBuffer)->CmdEndRenderingKHR(commandBuffer);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkGetDeviceGroupPeerMemoryFeaturesKHR(VkDevice device, uint32_t heapIndex, uint32_t localDeviceIndex, uint32_t remoteDeviceIndex, VkPeerMemoryFeatureFlags* pPeerMemoryFeatures) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetDeviceGroupPeerMemoryFeaturesKHR\n";
    }
    device_dispatch_table(device)->GetDeviceGroupPeerMemoryFeaturesKHR(device, heapIndex, localDeviceIndex, remoteDeviceIndex, pPeerMemoryFeatures);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdSetDeviceMaskKHR(VkCommandBuffer commandBuffer, uint32_t deviceMask) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdSetDeviceMaskKHR\n";
    }
    device_dispatch_table(commandBuffer)->CmdSetDeviceMaskKHR(commandBuffer, deviceMask);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdDispatchBaseKHR(VkCommandBuffer commandBuffer, uint32_t baseGroupX, uint32_t baseGroupY, uint32_t baseGroupZ, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdDispatchBaseKHR\n";
    }
    device_dispatch_table(commandBuffer)->CmdDispatchBaseKHR(commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkTrimCommandPoolKHR(VkDevice device, VkCommandPool commandPool, VkCommandPoolTrimFlags flags) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkTrimCommandPoolKHR\n";
    }
    device_dispatch_table(device)->TrimCommandPoolKHR(device, commandPool, flags);
}
#if defined(VK_USE_PLATFORM_WIN32_KHR)
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkGetMemoryWin32HandleKHR(VkDevice device, const VkMemoryGetWin32HandleInfoKHR* pGetWin32HandleInfo, HANDLE* pHandle) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetMemoryWin32HandleKHR\n";
    }
    VkResult result = device_dispatch_table(device)->GetMemoryWin32HandleKHR(device, pGetWin32HandleInfo, pHandle);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkGetMemoryWin32HandlePropertiesKHR(VkDevice device, VkExternalMemoryHandleTypeFlagBits handleType, HANDLE handle, VkMemoryWin32HandlePropertiesKHR* pMemoryWin32HandleProperties) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetMemoryWin32HandlePropertiesKHR\n";
    }
    VkResult result = device_dispatch_table(device)->GetMemoryWin32HandlePropertiesKHR(device, handleType, handle, pMemoryWin32HandleProperties);
    return result;
}
#endif  // VK_USE_PLATFORM_WIN32_KHR
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkGetMemoryFdKHR(VkDevice device, const VkMemoryGetFdInfoKHR* pGetFdInfo, int* pFd) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetMemoryFdKHR\n";
    }
    VkResult result = device_dispatch_table(device)->GetMemoryFdKHR(device, pGetFdInfo, pFd);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkGetMemoryFdPropertiesKHR(VkDevice device, VkExternalMemoryHandleTypeFlagBits handleType, int fd, VkMemoryFdPropertiesKHR* pMemoryFdProperties) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetMemoryFdPropertiesKHR\n";
    }
    VkResult result = device_dispatch_table(device)->GetMemoryFdPropertiesKHR(device, handleType, fd, pMemoryFdProperties);
    return result;
}
#if defined(VK_USE_PLATFORM_WIN32_KHR)
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkImportSemaphoreWin32HandleKHR(VkDevice device, const VkImportSemaphoreWin32HandleInfoKHR* pImportSemaphoreWin32HandleInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkImportSemaphoreWin32HandleKHR\n";
    }
    VkResult result = device_dispatch_table(device)->ImportSemaphoreWin32HandleKHR(device, pImportSemaphoreWin32HandleInfo);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkGetSemaphoreWin32HandleKHR(VkDevice device, const VkSemaphoreGetWin32HandleInfoKHR* pGetWin32HandleInfo, HANDLE* pHandle) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetSemaphoreWin32HandleKHR\n";
    }
    VkResult result = device_dispatch_table(device)->GetSemaphoreWin32HandleKHR(device, pGetWin32HandleInfo, pHandle);
    return result;
}
#endif  // VK_USE_PLATFORM_WIN32_KHR
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkImportSemaphoreFdKHR(VkDevice device, const VkImportSemaphoreFdInfoKHR* pImportSemaphoreFdInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkImportSemaphoreFdKHR\n";
    }
    VkResult result = device_dispatch_table(device)->ImportSemaphoreFdKHR(device, pImportSemaphoreFdInfo);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkGetSemaphoreFdKHR(VkDevice device, const VkSemaphoreGetFdInfoKHR* pGetFdInfo, int* pFd) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetSemaphoreFdKHR\n";
    }
    VkResult result = device_dispatch_table(device)->GetSemaphoreFdKHR(device, pGetFdInfo, pFd);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdPushDescriptorSetKHR(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipelineLayout layout, uint32_t set, uint32_t descriptorWriteCount, const VkWriteDescriptorSet* pDescriptorWrites) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdPushDescriptorSetKHR\n";
    }
    device_dispatch_table(commandBuffer)->CmdPushDescriptorSetKHR(commandBuffer, pipelineBindPoint, layout, set, descriptorWriteCount, pDescriptorWrites);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdPushDescriptorSetWithTemplateKHR(VkCommandBuffer commandBuffer, VkDescriptorUpdateTemplate descriptorUpdateTemplate, VkPipelineLayout layout, uint32_t set, const void* pData) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdPushDescriptorSetWithTemplateKHR\n";
    }
    device_dispatch_table(commandBuffer)->CmdPushDescriptorSetWithTemplateKHR(commandBuffer, descriptorUpdateTemplate, layout, set, pData);
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkCreateDescriptorUpdateTemplateKHR(VkDevice device, const VkDescriptorUpdateTemplateCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDescriptorUpdateTemplate* pDescriptorUpdateTemplate) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCreateDescriptorUpdateTemplateKHR\n";
    }
    VkResult result = device_dispatch_table(device)->CreateDescriptorUpdateTemplateKHR(device, pCreateInfo, pAllocator, pDescriptorUpdateTemplate);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkDestroyDescriptorUpdateTemplateKHR(VkDevice device, VkDescriptorUpdateTemplate descriptorUpdateTemplate, const VkAllocationCallbacks* pAllocator) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkDestroyDescriptorUpdateTemplateKHR\n";
    }
    device_dispatch_table(device)->DestroyDescriptorUpdateTemplateKHR(device, descriptorUpdateTemplate, pAllocator);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkUpdateDescriptorSetWithTemplateKHR(VkDevice device, VkDescriptorSet descriptorSet, VkDescriptorUpdateTemplate descriptorUpdateTemplate, const void* pData) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkUpdateDescriptorSetWithTemplateKHR\n";
    }
    device_dispatch_table(device)->UpdateDescriptorSetWithTemplateKHR(device, descriptorSet, descriptorUpdateTemplate, pData);
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkCreateRenderPass2KHR(VkDevice device, const VkRenderPassCreateInfo2* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkRenderPass* pRenderPass) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCreateRenderPass2KHR\n";
    }
    VkResult result = device_dispatch_table(device)->CreateRenderPass2KHR(device, pCreateInfo, pAllocator, pRenderPass);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdBeginRenderPass2KHR(VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo* pRenderPassBegin, const VkSubpassBeginInfo* pSubpassBeginInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdBeginRenderPass2KHR\n";
    }
    device_dispatch_table(commandBuffer)->CmdBeginRenderPass2KHR(commandBuffer, pRenderPassBegin, pSubpassBeginInfo);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdNextSubpass2KHR(VkCommandBuffer commandBuffer, const VkSubpassBeginInfo* pSubpassBeginInfo, const VkSubpassEndInfo* pSubpassEndInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdNextSubpass2KHR\n";
    }
    device_dispatch_table(commandBuffer)->CmdNextSubpass2KHR(commandBuffer, pSubpassBeginInfo, pSubpassEndInfo);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdEndRenderPass2KHR(VkCommandBuffer commandBuffer, const VkSubpassEndInfo* pSubpassEndInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdEndRenderPass2KHR\n";
    }
    device_dispatch_table(commandBuffer)->CmdEndRenderPass2KHR(commandBuffer, pSubpassEndInfo);
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkGetSwapchainStatusKHR(VkDevice device, VkSwapchainKHR swapchain) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetSwapchainStatusKHR\n";
    }
    VkResult result = device_dispatch_table(device)->GetSwapchainStatusKHR(device, swapchain);
    return result;
}
#if defined(VK_USE_PLATFORM_WIN32_KHR)
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkImportFenceWin32HandleKHR(VkDevice device, const VkImportFenceWin32HandleInfoKHR* pImportFenceWin32HandleInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkImportFenceWin32HandleKHR\n";
    }
    VkResult result = device_dispatch_table(device)->ImportFenceWin32HandleKHR(device, pImportFenceWin32HandleInfo);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkGetFenceWin32HandleKHR(VkDevice device, const VkFenceGetWin32HandleInfoKHR* pGetWin32HandleInfo, HANDLE* pHandle) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetFenceWin32HandleKHR\n";
    }
    VkResult result = device_dispatch_table(device)->GetFenceWin32HandleKHR(device, pGetWin32HandleInfo, pHandle);
    return result;
}
#endif  // VK_USE_PLATFORM_WIN32_KHR
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkImportFenceFdKHR(VkDevice device, const VkImportFenceFdInfoKHR* pImportFenceFdInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkImportFenceFdKHR\n";
    }
    VkResult result = device_dispatch_table(device)->ImportFenceFdKHR(device, pImportFenceFdInfo);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkGetFenceFdKHR(VkDevice device, const VkFenceGetFdInfoKHR* pGetFdInfo, int* pFd) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetFenceFdKHR\n";
    }
    VkResult result = device_dispatch_table(device)->GetFenceFdKHR(device, pGetFdInfo, pFd);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkAcquireProfilingLockKHR(VkDevice device, const VkAcquireProfilingLockInfoKHR* pInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkAcquireProfilingLockKHR\n";
    }
    VkResult result = device_dispatch_table(device)->AcquireProfilingLockKHR(device, pInfo);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkReleaseProfilingLockKHR(VkDevice device) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkReleaseProfilingLockKHR\n";
    }
    device_dispatch_table(device)->ReleaseProfilingLockKHR(device);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkGetImageMemoryRequirements2KHR(VkDevice device, const VkImageMemoryRequirementsInfo2* pInfo, VkMemoryRequirements2* pMemoryRequirements) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetImageMemoryRequirements2KHR\n";
    }
    device_dispatch_table(device)->GetImageMemoryRequirements2KHR(device, pInfo, pMemoryRequirements);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkGetBufferMemoryRequirements2KHR(VkDevice device, const VkBufferMemoryRequirementsInfo2* pInfo, VkMemoryRequirements2* pMemoryRequirements) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetBufferMemoryRequirements2KHR\n";
    }
    device_dispatch_table(device)->GetBufferMemoryRequirements2KHR(device, pInfo, pMemoryRequirements);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkGetImageSparseMemoryRequirements2KHR(VkDevice device, const VkImageSparseMemoryRequirementsInfo2* pInfo, uint32_t* pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements2* pSparseMemoryRequirements) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetImageSparseMemoryRequirements2KHR\n";
    }
    device_dispatch_table(device)->GetImageSparseMemoryRequirements2KHR(device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements);
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkCreateSamplerYcbcrConversionKHR(VkDevice device, const VkSamplerYcbcrConversionCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSamplerYcbcrConversion* pYcbcrConversion) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCreateSamplerYcbcrConversionKHR\n";
    }
    VkResult result = device_dispatch_table(device)->CreateSamplerYcbcrConversionKHR(device, pCreateInfo, pAllocator, pYcbcrConversion);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkDestroySamplerYcbcrConversionKHR(VkDevice device, VkSamplerYcbcrConversion ycbcrConversion, const VkAllocationCallbacks* pAllocator) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkDestroySamplerYcbcrConversionKHR\n";
    }
    device_dispatch_table(device)->DestroySamplerYcbcrConversionKHR(device, ycbcrConversion, pAllocator);
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkBindBufferMemory2KHR(VkDevice device, uint32_t bindInfoCount, const VkBindBufferMemoryInfo* pBindInfos) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkBindBufferMemory2KHR\n";
    }
    VkResult result = device_dispatch_table(device)->BindBufferMemory2KHR(device, bindInfoCount, pBindInfos);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkBindImageMemory2KHR(VkDevice device, uint32_t bindInfoCount, const VkBindImageMemoryInfo* pBindInfos) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkBindImageMemory2KHR\n";
    }
    VkResult result = device_dispatch_table(device)->BindImageMemory2KHR(device, bindInfoCount, pBindInfos);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkGetDescriptorSetLayoutSupportKHR(VkDevice device, const VkDescriptorSetLayoutCreateInfo* pCreateInfo, VkDescriptorSetLayoutSupport* pSupport) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetDescriptorSetLayoutSupportKHR\n";
    }
    device_dispatch_table(device)->GetDescriptorSetLayoutSupportKHR(device, pCreateInfo, pSupport);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdDrawIndirectCountKHR(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdDrawIndirectCountKHR\n";
    }
    device_dispatch_table(commandBuffer)->CmdDrawIndirectCountKHR(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdDrawIndexedIndirectCountKHR(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdDrawIndexedIndirectCountKHR\n";
    }
    device_dispatch_table(commandBuffer)->CmdDrawIndexedIndirectCountKHR(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkGetSemaphoreCounterValueKHR(VkDevice device, VkSemaphore semaphore, uint64_t* pValue) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetSemaphoreCounterValueKHR\n";
    }
    VkResult result = device_dispatch_table(device)->GetSemaphoreCounterValueKHR(device, semaphore, pValue);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkWaitSemaphoresKHR(VkDevice device, const VkSemaphoreWaitInfo* pWaitInfo, uint64_t timeout) {
    VkResult result = device_dispatch_table(device)->WaitSemaphoresKHR(device, pWaitInfo, timeout);
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkWaitSemaphoresKHR\n";
    }
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkSignalSemaphoreKHR(VkDevice device, const VkSemaphoreSignalInfo* pSignalInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkSignalSemaphoreKHR\n";
    }
    VkResult result = device_dispatch_table(device)->SignalSemaphoreKHR(device, pSignalInfo);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdSetFragmentShadingRateKHR(VkCommandBuffer commandBuffer, const VkExtent2D* pFragmentSize, const VkFragmentShadingRateCombinerOpKHR combinerOps[2]) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdSetFragmentShadingRateKHR\n";
    }
    device_dispatch_table(commandBuffer)->CmdSetFragmentShadingRateKHR(commandBuffer, pFragmentSize, combinerOps);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdSetRenderingAttachmentLocationsKHR(VkCommandBuffer commandBuffer, const VkRenderingAttachmentLocationInfo* pLocationInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdSetRenderingAttachmentLocationsKHR\n";
    }
    device_dispatch_table(commandBuffer)->CmdSetRenderingAttachmentLocationsKHR(commandBuffer, pLocationInfo);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdSetRenderingInputAttachmentIndicesKHR(VkCommandBuffer commandBuffer, const VkRenderingInputAttachmentIndexInfo* pInputAttachmentIndexInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdSetRenderingInputAttachmentIndicesKHR\n";
    }
    device_dispatch_table(commandBuffer)->CmdSetRenderingInputAttachmentIndicesKHR(commandBuffer, pInputAttachmentIndexInfo);
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkWaitForPresentKHR(VkDevice device, VkSwapchainKHR swapchain, uint64_t presentId, uint64_t timeout) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkWaitForPresentKHR\n";
    }
    VkResult result = device_dispatch_table(device)->WaitForPresentKHR(device, swapchain, presentId, timeout);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkDeviceAddress VKAPI_CALL vkGetBufferDeviceAddressKHR(VkDevice device, const VkBufferDeviceAddressInfo* pInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetBufferDeviceAddressKHR\n";
    }
    VkDeviceAddress result = device_dispatch_table(device)->GetBufferDeviceAddressKHR(device, pInfo);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR uint64_t VKAPI_CALL vkGetBufferOpaqueCaptureAddressKHR(VkDevice device, const VkBufferDeviceAddressInfo* pInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetBufferOpaqueCaptureAddressKHR\n";
    }
    uint64_t result = device_dispatch_table(device)->GetBufferOpaqueCaptureAddressKHR(device, pInfo);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR uint64_t VKAPI_CALL vkGetDeviceMemoryOpaqueCaptureAddressKHR(VkDevice device, const VkDeviceMemoryOpaqueCaptureAddressInfo* pInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetDeviceMemoryOpaqueCaptureAddressKHR\n";
    }
    uint64_t result = device_dispatch_table(device)->GetDeviceMemoryOpaqueCaptureAddressKHR(device, pInfo);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkCreateDeferredOperationKHR(VkDevice device, const VkAllocationCallbacks* pAllocator, VkDeferredOperationKHR* pDeferredOperation) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCreateDeferredOperationKHR\n";
    }
    VkResult result = device_dispatch_table(device)->CreateDeferredOperationKHR(device, pAllocator, pDeferredOperation);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkDestroyDeferredOperationKHR(VkDevice device, VkDeferredOperationKHR operation, const VkAllocationCallbacks* pAllocator) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkDestroyDeferredOperationKHR\n";
    }
    device_dispatch_table(device)->DestroyDeferredOperationKHR(device, operation, pAllocator);
}
template <ApiDumpFormat Format>
VKAPI_ATTR uint32_t VKAPI_CALL vkGetDeferredOperationMaxConcurrencyKHR(VkDevice device, VkDeferredOperationKHR operation) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetDeferredOperationMaxConcurrencyKHR\n";
    }
    uint32_t result = device_dispatch_table(device)->GetDeferredOperationMaxConcurrencyKHR(device, operation);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkGetDeferredOperationResultKHR(VkDevice device, VkDeferredOperationKHR operation) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetDeferredOperationResultKHR\n";
    }
    VkResult result = device_dispatch_table(device)->GetDeferredOperationResultKHR(device, operation);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkDeferredOperationJoinKHR(VkDevice device, VkDeferredOperationKHR operation) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkDeferredOperationJoinKHR\n";
    }
    VkResult result = device_dispatch_table(device)->DeferredOperationJoinKHR(device, operation);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkGetPipelineExecutablePropertiesKHR(VkDevice device, const VkPipelineInfoKHR* pPipelineInfo, uint32_t* pExecutableCount, VkPipelineExecutablePropertiesKHR* pProperties) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetPipelineExecutablePropertiesKHR\n";
    }
    VkResult result = device_dispatch_table(device)->GetPipelineExecutablePropertiesKHR(device, pPipelineInfo, pExecutableCount, pProperties);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkGetPipelineExecutableStatisticsKHR(VkDevice device, const VkPipelineExecutableInfoKHR* pExecutableInfo, uint32_t* pStatisticCount, VkPipelineExecutableStatisticKHR* pStatistics) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetPipelineExecutableStatisticsKHR\n";
    }
    VkResult result = device_dispatch_table(device)->GetPipelineExecutableStatisticsKHR(device, pExecutableInfo, pStatisticCount, pStatistics);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkGetPipelineExecutableInternalRepresentationsKHR(VkDevice device, const VkPipelineExecutableInfoKHR* pExecutableInfo, uint32_t* pInternalRepresentationCount, VkPipelineExecutableInternalRepresentationKHR* pInternalRepresentations) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetPipelineExecutableInternalRepresentationsKHR\n";
    }
    VkResult result = device_dispatch_table(device)->GetPipelineExecutableInternalRepresentationsKHR(device, pExecutableInfo, pInternalRepresentationCount, pInternalRepresentations);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkMapMemory2KHR(VkDevice device, const VkMemoryMapInfo* pMemoryMapInfo, void** ppData) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkMapMemory2KHR\n";
    }
    VkResult result = device_dispatch_table(device)->MapMemory2KHR(device, pMemoryMapInfo, ppData);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkUnmapMemory2KHR(VkDevice device, const VkMemoryUnmapInfo* pMemoryUnmapInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkUnmapMemory2KHR\n";
    }
    VkResult result = device_dispatch_table(device)->UnmapMemory2KHR(device, pMemoryUnmapInfo);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkGetEncodedVideoSessionParametersKHR(VkDevice device, const VkVideoEncodeSessionParametersGetInfoKHR* pVideoSessionParametersInfo, VkVideoEncodeSessionParametersFeedbackInfoKHR* pFeedbackInfo, size_t* pDataSize, void* pData) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetEncodedVideoSessionParametersKHR\n";
    }
    VkResult result = device_dispatch_table(device)->GetEncodedVideoSessionParametersKHR(device, pVideoSessionParametersInfo, pFeedbackInfo, pDataSize, pData);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdEncodeVideoKHR(VkCommandBuffer commandBuffer, const VkVideoEncodeInfoKHR* pEncodeInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdEncodeVideoKHR\n";
    }
    device_dispatch_table(commandBuffer)->CmdEncodeVideoKHR(commandBuffer, pEncodeInfo);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdSetEvent2KHR(VkCommandBuffer commandBuffer, VkEvent event, const VkDependencyInfo* pDependencyInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdSetEvent2KHR\n";
    }
    device_dispatch_table(commandBuffer)->CmdSetEvent2KHR(commandBuffer, event, pDependencyInfo);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdResetEvent2KHR(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags2 stageMask) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdResetEvent2KHR\n";
    }
    device_dispatch_table(commandBuffer)->CmdResetEvent2KHR(commandBuffer, event, stageMask);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdWaitEvents2KHR(VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents, const VkDependencyInfo* pDependencyInfos) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdWaitEvents2KHR\n";
    }
    device_dispatch_table(commandBuffer)->CmdWaitEvents2KHR(commandBuffer, eventCount, pEvents, pDependencyInfos);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdPipelineBarrier2KHR(VkCommandBuffer commandBuffer, const VkDependencyInfo* pDependencyInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdPipelineBarrier2KHR\n";
    }
    device_dispatch_table(commandBuffer)->CmdPipelineBarrier2KHR(commandBuffer, pDependencyInfo);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdWriteTimestamp2KHR(VkCommandBuffer commandBuffer, VkPipelineStageFlags2 stage, VkQueryPool queryPool, uint32_t query) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdWriteTimestamp2KHR\n";
    }
    device_dispatch_table(commandBuffer)->CmdWriteTimestamp2KHR(commandBuffer, stage, queryPool, query);
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkQueueSubmit2KHR(VkQueue queue, uint32_t submitCount, const VkSubmitInfo2* pSubmits, VkFence fence) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkQueueSubmit2KHR\n";
    }
    VkResult result = device_dispatch_table(queue)->QueueSubmit2KHR(queue, submitCount, pSubmits, fence);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdCopyBuffer2KHR(VkCommandBuffer commandBuffer, const VkCopyBufferInfo2* pCopyBufferInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdCopyBuffer2KHR\n";
    }
    device_dispatch_table(commandBuffer)->CmdCopyBuffer2KHR(commandBuffer, pCopyBufferInfo);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdCopyImage2KHR(VkCommandBuffer commandBuffer, const VkCopyImageInfo2* pCopyImageInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdCopyImage2KHR\n";
    }
    device_dispatch_table(commandBuffer)->CmdCopyImage2KHR(commandBuffer, pCopyImageInfo);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdCopyBufferToImage2KHR(VkCommandBuffer commandBuffer, const VkCopyBufferToImageInfo2* pCopyBufferToImageInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdCopyBufferToImage2KHR\n";
    }
    device_dispatch_table(commandBuffer)->CmdCopyBufferToImage2KHR(commandBuffer, pCopyBufferToImageInfo);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdCopyImageToBuffer2KHR(VkCommandBuffer commandBuffer, const VkCopyImageToBufferInfo2* pCopyImageToBufferInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdCopyImageToBuffer2KHR\n";
    }
    device_dispatch_table(commandBuffer)->CmdCopyImageToBuffer2KHR(commandBuffer, pCopyImageToBufferInfo);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdBlitImage2KHR(VkCommandBuffer commandBuffer, const VkBlitImageInfo2* pBlitImageInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdBlitImage2KHR\n";
    }
    device_dispatch_table(commandBuffer)->CmdBlitImage2KHR(commandBuffer, pBlitImageInfo);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdResolveImage2KHR(VkCommandBuffer commandBuffer, const VkResolveImageInfo2* pResolveImageInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdResolveImage2KHR\n";
    }
    device_dispatch_table(commandBuffer)->CmdResolveImage2KHR(commandBuffer, pResolveImageInfo);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdTraceRaysIndirect2KHR(VkCommandBuffer commandBuffer, VkDeviceAddress indirectDeviceAddress) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdTraceRaysIndirect2KHR\n";
    }
    device_dispatch_table(commandBuffer)->CmdTraceRaysIndirect2KHR(commandBuffer, indirectDeviceAddress);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkGetDeviceBufferMemoryRequirementsKHR(VkDevice device, const VkDeviceBufferMemoryRequirements* pInfo, VkMemoryRequirements2* pMemoryRequirements) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetDeviceBufferMemoryRequirementsKHR\n";
    }
    device_dispatch_table(device)->GetDeviceBufferMemoryRequirementsKHR(device, pInfo, pMemoryRequirements);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkGetDeviceImageMemoryRequirementsKHR(VkDevice device, const VkDeviceImageMemoryRequirements* pInfo, VkMemoryRequirements2* pMemoryRequirements) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetDeviceImageMemoryRequirementsKHR\n";
    }
    device_dispatch_table(device)->GetDeviceImageMemoryRequirementsKHR(device, pInfo, pMemoryRequirements);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkGetDeviceImageSparseMemoryRequirementsKHR(VkDevice device, const VkDeviceImageMemoryRequirements* pInfo, uint32_t* pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements2* pSparseMemoryRequirements) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetDeviceImageSparseMemoryRequirementsKHR\n";
    }
    device_dispatch_table(device)->GetDeviceImageSparseMemoryRequirementsKHR(device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdBindIndexBuffer2KHR(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkDeviceSize size, VkIndexType indexType) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdBindIndexBuffer2KHR\n";
    }
    device_dispatch_table(commandBuffer)->CmdBindIndexBuffer2KHR(commandBuffer, buffer, offset, size, indexType);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkGetRenderingAreaGranularityKHR(VkDevice device, const VkRenderingAreaInfo* pRenderingAreaInfo, VkExtent2D* pGranularity) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetRenderingAreaGranularityKHR\n";
    }
    device_dispatch_table(device)->GetRenderingAreaGranularityKHR(device, pRenderingAreaInfo, pGranularity);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkGetDeviceImageSubresourceLayoutKHR(VkDevice device, const VkDeviceImageSubresourceInfo* pInfo, VkSubresourceLayout2* pLayout) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetDeviceImageSubresourceLayoutKHR\n";
    }
    device_dispatch_table(device)->GetDeviceImageSubresourceLayoutKHR(device, pInfo, pLayout);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkGetImageSubresourceLayout2KHR(VkDevice device, VkImage image, const VkImageSubresource2* pSubresource, VkSubresourceLayout2* pLayout) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetImageSubresourceLayout2KHR\n";
    }
    device_dispatch_table(device)->GetImageSubresourceLayout2KHR(device, image, pSubresource, pLayout);
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkWaitForPresent2KHR(VkDevice device, VkSwapchainKHR swapchain, const VkPresentWait2InfoKHR* pPresentWait2Info) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkWaitForPresent2KHR\n";
    }
    VkResult result = device_dispatch_table(device)->WaitForPresent2KHR(device, swapchain, pPresentWait2Info);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkCreatePipelineBinariesKHR(VkDevice device, const VkPipelineBinaryCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkPipelineBinaryHandlesInfoKHR* pBinaries) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCreatePipelineBinariesKHR\n";
    }
    VkResult result = device_dispatch_table(device)->CreatePipelineBinariesKHR(device, pCreateInfo, pAllocator, pBinaries);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkDestroyPipelineBinaryKHR(VkDevice device, VkPipelineBinaryKHR pipelineBinary, const VkAllocationCallbacks* pAllocator) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkDestroyPipelineBinaryKHR\n";
    }
    device_dispatch_table(device)->DestroyPipelineBinaryKHR(device, pipelineBinary, pAllocator);
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkGetPipelineKeyKHR(VkDevice device, const VkPipelineCreateInfoKHR* pPipelineCreateInfo, VkPipelineBinaryKeyKHR* pPipelineKey) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetPipelineKeyKHR\n";
    }
    VkResult result = device_dispatch_table(device)->GetPipelineKeyKHR(device, pPipelineCreateInfo, pPipelineKey);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkGetPipelineBinaryDataKHR(VkDevice device, const VkPipelineBinaryDataInfoKHR* pInfo, VkPipelineBinaryKeyKHR* pPipelineBinaryKey, size_t* pPipelineBinaryDataSize, void* pPipelineBinaryData) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetPipelineBinaryDataKHR\n";
    }
    VkResult result = device_dispatch_table(device)->GetPipelineBinaryDataKHR(device, pInfo, pPipelineBinaryKey, pPipelineBinaryDataSize, pPipelineBinaryData);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkReleaseCapturedPipelineDataKHR(VkDevice device, const VkReleaseCapturedPipelineDataInfoKHR* pInfo, const VkAllocationCallbacks* pAllocator) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkReleaseCapturedPipelineDataKHR\n";
    }
    VkResult result = device_dispatch_table(device)->ReleaseCapturedPipelineDataKHR(device, pInfo, pAllocator);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkReleaseSwapchainImagesKHR(VkDevice device, const VkReleaseSwapchainImagesInfoKHR* pReleaseInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkReleaseSwapchainImagesKHR\n";
    }
    VkResult result = device_dispatch_table(device)->ReleaseSwapchainImagesKHR(device, pReleaseInfo);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdSetLineStippleKHR(VkCommandBuffer commandBuffer, uint32_t lineStippleFactor, uint16_t lineStipplePattern) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdSetLineStippleKHR\n";
    }
    device_dispatch_table(commandBuffer)->CmdSetLineStippleKHR(commandBuffer, lineStippleFactor, lineStipplePattern);
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkGetCalibratedTimestampsKHR(VkDevice device, uint32_t timestampCount, const VkCalibratedTimestampInfoKHR* pTimestampInfos, uint64_t* pTimestamps, uint64_t* pMaxDeviation) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetCalibratedTimestampsKHR\n";
    }
    VkResult result = device_dispatch_table(device)->GetCalibratedTimestampsKHR(device, timestampCount, pTimestampInfos, pTimestamps, pMaxDeviation);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdBindDescriptorSets2KHR(VkCommandBuffer commandBuffer, const VkBindDescriptorSetsInfo* pBindDescriptorSetsInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdBindDescriptorSets2KHR\n";
    }
    device_dispatch_table(commandBuffer)->CmdBindDescriptorSets2KHR(commandBuffer, pBindDescriptorSetsInfo);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdPushConstants2KHR(VkCommandBuffer commandBuffer, const VkPushConstantsInfo* pPushConstantsInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdPushConstants2KHR\n";
    }
    device_dispatch_table(commandBuffer)->CmdPushConstants2KHR(commandBuffer, pPushConstantsInfo);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdPushDescriptorSet2KHR(VkCommandBuffer commandBuffer, const VkPushDescriptorSetInfo* pPushDescriptorSetInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdPushDescriptorSet2KHR\n";
    }
    device_dispatch_table(commandBuffer)->CmdPushDescriptorSet2KHR(commandBuffer, pPushDescriptorSetInfo);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdPushDescriptorSetWithTemplate2KHR(VkCommandBuffer commandBuffer, const VkPushDescriptorSetWithTemplateInfo* pPushDescriptorSetWithTemplateInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdPushDescriptorSetWithTemplate2KHR\n";
    }
    device_dispatch_table(commandBuffer)->CmdPushDescriptorSetWithTemplate2KHR(commandBuffer, pPushDescriptorSetWithTemplateInfo);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdSetDescriptorBufferOffsets2EXT(VkCommandBuffer commandBuffer, const VkSetDescriptorBufferOffsetsInfoEXT* pSetDescriptorBufferOffsetsInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdSetDescriptorBufferOffsets2EXT\n";
    }
    device_dispatch_table(commandBuffer)->CmdSetDescriptorBufferOffsets2EXT(commandBuffer, pSetDescriptorBufferOffsetsInfo);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdBindDescriptorBufferEmbeddedSamplers2EXT(VkCommandBuffer commandBuffer, const VkBindDescriptorBufferEmbeddedSamplersInfoEXT* pBindDescriptorBufferEmbeddedSamplersInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdBindDescriptorBufferEmbeddedSamplers2EXT\n";
    }
    device_dispatch_table(commandBuffer)->CmdBindDescriptorBufferEmbeddedSamplers2EXT(commandBuffer, pBindDescriptorBufferEmbeddedSamplersInfo);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdCopyMemoryIndirectKHR(VkCommandBuffer commandBuffer, const VkCopyMemoryIndirectInfoKHR* pCopyMemoryIndirectInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdCopyMemoryIndirectKHR\n";
    }
    device_dispatch_table(commandBuffer)->CmdCopyMemoryIndirectKHR(commandBuffer, pCopyMemoryIndirectInfo);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdCopyMemoryToImageIndirectKHR(VkCommandBuffer commandBuffer, const VkCopyMemoryToImageIndirectInfoKHR* pCopyMemoryToImageIndirectInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdCopyMemoryToImageIndirectKHR\n";
    }
    device_dispatch_table(commandBuffer)->CmdCopyMemoryToImageIndirectKHR(commandBuffer, pCopyMemoryToImageIndirectInfo);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdEndRendering2KHR(VkCommandBuffer commandBuffer, const VkRenderingEndInfoKHR* pRenderingEndInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdEndRendering2KHR\n";
    }
    device_dispatch_table(commandBuffer)->CmdEndRendering2KHR(commandBuffer, pRenderingEndInfo);
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkDebugMarkerSetObjectTagEXT(VkDevice device, const VkDebugMarkerObjectTagInfoEXT* pTagInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkDebugMarkerSetObjectTagEXT\n";
    }
    VkResult result = device_dispatch_table(device)->DebugMarkerSetObjectTagEXT(device, pTagInfo);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkDebugMarkerSetObjectNameEXT(VkDevice device, const VkDebugMarkerObjectNameInfoEXT* pNameInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    ApiDumpInstance::current().update_object_name_map(pNameInfo);

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkDebugMarkerSetObjectNameEXT\n";
    }
    VkResult result = device_dispatch_table(device)->DebugMarkerSetObjectNameEXT(device, pNameInfo);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdDebugMarkerBeginEXT(VkCommandBuffer commandBuffer, const VkDebugMarkerMarkerInfoEXT* pMarkerInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdDebugMarkerBeginEXT\n";
    }
    device_dispatch_table(commandBuffer)->CmdDebugMarkerBeginEXT(commandBuffer, pMarkerInfo);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdDebugMarkerEndEXT(VkCommandBuffer commandBuffer) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdDebugMarkerEndEXT\n";
    }
    device_dispatch_table(commandBuffer)->CmdDebugMarkerEndEXT(commandBuffer);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdDebugMarkerInsertEXT(VkCommandBuffer commandBuffer, const VkDebugMarkerMarkerInfoEXT* pMarkerInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdDebugMarkerInsertEXT\n";
    }
    device_dispatch_table(commandBuffer)->CmdDebugMarkerInsertEXT(commandBuffer, pMarkerInfo);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdBindTransformFeedbackBuffersEXT(VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount, const VkBuffer* pBuffers, const VkDeviceSize* pOffsets, const VkDeviceSize* pSizes) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdBindTransformFeedbackBuffersEXT\n";
    }
    device_dispatch_table(commandBuffer)->CmdBindTransformFeedbackBuffersEXT(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdBeginTransformFeedbackEXT(VkCommandBuffer commandBuffer, uint32_t firstCounterBuffer, uint32_t counterBufferCount, const VkBuffer* pCounterBuffers, const VkDeviceSize* pCounterBufferOffsets) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdBeginTransformFeedbackEXT\n";
    }
    device_dispatch_table(commandBuffer)->CmdBeginTransformFeedbackEXT(commandBuffer, firstCounterBuffer, counterBufferCount, pCounterBuffers, pCounterBufferOffsets);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdEndTransformFeedbackEXT(VkCommandBuffer commandBuffer, uint32_t firstCounterBuffer, uint32_t counterBufferCount, const VkBuffer* pCounterBuffers, const VkDeviceSize* pCounterBufferOffsets) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdEndTransformFeedbackEXT\n";
    }
    device_dispatch_table(commandBuffer)->CmdEndTransformFeedbackEXT(commandBuffer, firstCounterBuffer, counterBufferCount, pCounterBuffers, pCounterBufferOffsets);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdBeginQueryIndexedEXT(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query, VkQueryControlFlags flags, uint32_t index) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdBeginQueryIndexedEXT\n";
    }
    device_dispatch_table(commandBuffer)->CmdBeginQueryIndexedEXT(commandBuffer, queryPool, query, flags, index);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdEndQueryIndexedEXT(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query, uint32_t index) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdEndQueryIndexedEXT\n";
    }
    device_dispatch_table(commandBuffer)->CmdEndQueryIndexedEXT(commandBuffer, queryPool, query, index);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdDrawIndirectByteCountEXT(VkCommandBuffer commandBuffer, uint32_t instanceCount, uint32_t firstInstance, VkBuffer counterBuffer, VkDeviceSize counterBufferOffset, uint32_t counterOffset, uint32_t vertexStride) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdDrawIndirectByteCountEXT\n";
    }
    device_dispatch_table(commandBuffer)->CmdDrawIndirectByteCountEXT(commandBuffer, instanceCount, firstInstance, counterBuffer, counterBufferOffset, counterOffset, vertexStride);
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkCreateCuModuleNVX(VkDevice device, const VkCuModuleCreateInfoNVX* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkCuModuleNVX* pModule) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCreateCuModuleNVX\n";
    }
    VkResult result = device_dispatch_table(device)->CreateCuModuleNVX(device, pCreateInfo, pAllocator, pModule);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkCreateCuFunctionNVX(VkDevice device, const VkCuFunctionCreateInfoNVX* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkCuFunctionNVX* pFunction) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCreateCuFunctionNVX\n";
    }
    VkResult result = device_dispatch_table(device)->CreateCuFunctionNVX(device, pCreateInfo, pAllocator, pFunction);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkDestroyCuModuleNVX(VkDevice device, VkCuModuleNVX module, const VkAllocationCallbacks* pAllocator) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkDestroyCuModuleNVX\n";
    }
    device_dispatch_table(device)->DestroyCuModuleNVX(device, module, pAllocator);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkDestroyCuFunctionNVX(VkDevice device, VkCuFunctionNVX function, const VkAllocationCallbacks* pAllocator) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkDestroyCuFunctionNVX\n";
    }
    device_dispatch_table(device)->DestroyCuFunctionNVX(device, function, pAllocator);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdCuLaunchKernelNVX(VkCommandBuffer commandBuffer, const VkCuLaunchInfoNVX* pLaunchInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdCuLaunchKernelNVX\n";
    }
    device_dispatch_table(commandBuffer)->CmdCuLaunchKernelNVX(commandBuffer, pLaunchInfo);
}
template <ApiDumpFormat Format>
VKAPI_ATTR uint32_t VKAPI_CALL vkGetImageViewHandleNVX(VkDevice device, const VkImageViewHandleInfoNVX* pInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetImageViewHandleNVX\n";
    }
    uint32_t result = device_dispatch_table(device)->GetImageViewHandleNVX(device, pInfo);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR uint64_t VKAPI_CALL vkGetImageViewHandle64NVX(VkDevice device, const VkImageViewHandleInfoNVX* pInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetImageViewHandle64NVX\n";
    }
    uint64_t result = device_dispatch_table(device)->GetImageViewHandle64NVX(device, pInfo);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkGetImageViewAddressNVX(VkDevice device, VkImageView imageView, VkImageViewAddressPropertiesNVX* pProperties) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetImageViewAddressNVX\n";
    }
    VkResult result = device_dispatch_table(device)->GetImageViewAddressNVX(device, imageView, pProperties);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR uint64_t VKAPI_CALL vkGetDeviceCombinedImageSamplerIndexNVX(VkDevice device, uint64_t imageViewIndex, uint64_t samplerIndex) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetDeviceCombinedImageSamplerIndexNVX\n";
    }
    uint64_t result = device_dispatch_table(device)->GetDeviceCombinedImageSamplerIndexNVX(device, imageViewIndex, samplerIndex);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdDrawIndirectCountAMD(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdDrawIndirectCountAMD\n";
    }
    device_dispatch_table(commandBuffer)->CmdDrawIndirectCountAMD(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdDrawIndexedIndirectCountAMD(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdDrawIndexedIndirectCountAMD\n";
    }
    device_dispatch_table(commandBuffer)->CmdDrawIndexedIndirectCountAMD(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkGetShaderInfoAMD(VkDevice device, VkPipeline pipeline, VkShaderStageFlagBits shaderStage, VkShaderInfoTypeAMD infoType, size_t* pInfoSize, void* pInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetShaderInfoAMD\n";
    }
    VkResult result = device_dispatch_table(device)->GetShaderInfoAMD(device, pipeline, shaderStage, infoType, pInfoSize, pInfo);
    return result;
}
#if defined(VK_USE_PLATFORM_WIN32_KHR)
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkGetMemoryWin32HandleNV(VkDevice device, VkDeviceMemory memory, VkExternalMemoryHandleTypeFlagsNV handleType, HANDLE* pHandle) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetMemoryWin32HandleNV\n";
    }
    VkResult result = device_dispatch_table(device)->GetMemoryWin32HandleNV(device, memory, handleType, pHandle);
    return result;
}
#endif  // VK_USE_PLATFORM_WIN32_KHR
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdBeginConditionalRenderingEXT(VkCommandBuffer commandBuffer, const VkConditionalRenderingBeginInfoEXT* pConditionalRenderingBegin) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdBeginConditionalRenderingEXT\n";
    }
    device_dispatch_table(commandBuffer)->CmdBeginConditionalRenderingEXT(commandBuffer, pConditionalRenderingBegin);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdEndConditionalRenderingEXT(VkCommandBuffer commandBuffer) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdEndConditionalRenderingEXT\n";
    }
    device_dispatch_table(commandBuffer)->CmdEndConditionalRenderingEXT(commandBuffer);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdSetViewportWScalingNV(VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount, const VkViewportWScalingNV* pViewportWScalings) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdSetViewportWScalingNV\n";
    }
    device_dispatch_table(commandBuffer)->CmdSetViewportWScalingNV(commandBuffer, firstViewport, viewportCount, pViewportWScalings);
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkDisplayPowerControlEXT(VkDevice device, VkDisplayKHR display, const VkDisplayPowerInfoEXT* pDisplayPowerInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkDisplayPowerControlEXT\n";
    }
    VkResult result = device_dispatch_table(device)->DisplayPowerControlEXT(device, display, pDisplayPowerInfo);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkRegisterDeviceEventEXT(VkDevice device, const VkDeviceEventInfoEXT* pDeviceEventInfo, const VkAllocationCallbacks* pAllocator, VkFence* pFence) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkRegisterDeviceEventEXT\n";
    }
    VkResult result = device_dispatch_table(device)->RegisterDeviceEventEXT(device, pDeviceEventInfo, pAllocator, pFence);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkRegisterDisplayEventEXT(VkDevice device, VkDisplayKHR display, const VkDisplayEventInfoEXT* pDisplayEventInfo, const VkAllocationCallbacks* pAllocator, VkFence* pFence) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkRegisterDisplayEventEXT\n";
    }
    VkResult result = device_dispatch_table(device)->RegisterDisplayEventEXT(device, display, pDisplayEventInfo, pAllocator, pFence);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkGetSwapchainCounterEXT(VkDevice device, VkSwapchainKHR swapchain, VkSurfaceCounterFlagBitsEXT counter, uint64_t* pCounterValue) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetSwapchainCounterEXT\n";
    }
    VkResult result = device_dispatch_table(device)->GetSwapchainCounterEXT(device, swapchain, counter, pCounterValue);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkGetRefreshCycleDurationGOOGLE(VkDevice device, VkSwapchainKHR swapchain, VkRefreshCycleDurationGOOGLE* pDisplayTimingProperties) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetRefreshCycleDurationGOOGLE\n";
    }
    VkResult result = device_dispatch_table(device)->GetRefreshCycleDurationGOOGLE(device, swapchain, pDisplayTimingProperties);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkGetPastPresentationTimingGOOGLE(VkDevice device, VkSwapchainKHR swapchain, uint32_t* pPresentationTimingCount, VkPastPresentationTimingGOOGLE* pPresentationTimings) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetPastPresentationTimingGOOGLE\n";
    }
    VkResult result = device_dispatch_table(device)->GetPastPresentationTimingGOOGLE(device, swapchain, pPresentationTimingCount, pPresentationTimings);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdSetDiscardRectangleEXT(VkCommandBuffer commandBuffer, uint32_t firstDiscardRectangle, uint32_t discardRectangleCount, const VkRect2D* pDiscardRectangles) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdSetDiscardRectangleEXT\n";
    }
    device_dispatch_table(commandBuffer)->CmdSetDiscardRectangleEXT(commandBuffer, firstDiscardRectangle, discardRectangleCount, pDiscardRectangles);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdSetDiscardRectangleEnableEXT(VkCommandBuffer commandBuffer, VkBool32 discardRectangleEnable) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdSetDiscardRectangleEnableEXT\n";
    }
    device_dispatch_table(commandBuffer)->CmdSetDiscardRectangleEnableEXT(commandBuffer, discardRectangleEnable);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdSetDiscardRectangleModeEXT(VkCommandBuffer commandBuffer, VkDiscardRectangleModeEXT discardRectangleMode) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdSetDiscardRectangleModeEXT\n";
    }
    device_dispatch_table(commandBuffer)->CmdSetDiscardRectangleModeEXT(commandBuffer, discardRectangleMode);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkSetHdrMetadataEXT(VkDevice device, uint32_t swapchainCount, const VkSwapchainKHR* pSwapchains, const VkHdrMetadataEXT* pMetadata) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkSetHdrMetadataEXT\n";
    }
    device_dispatch_table(device)->SetHdrMetadataEXT(device, swapchainCount, pSwapchains, pMetadata);
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkSetDebugUtilsObjectNameEXT(VkDevice device, const VkDebugUtilsObjectNameInfoEXT* pNameInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    ApiDumpInstance::current().update_object_name_map(pNameInfo);

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkSetDebugUtilsObjectNameEXT\n";
    }
    VkResult result = device_dispatch_table(device)->SetDebugUtilsObjectNameEXT(device, pNameInfo);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkSetDebugUtilsObjectTagEXT(VkDevice device, const VkDebugUtilsObjectTagInfoEXT* pTagInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkSetDebugUtilsObjectTagEXT\n";
    }
    VkResult result = device_dispatch_table(device)->SetDebugUtilsObjectTagEXT(device, pTagInfo);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkQueueBeginDebugUtilsLabelEXT(VkQueue queue, const VkDebugUtilsLabelEXT* pLabelInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkQueueBeginDebugUtilsLabelEXT\n";
    }
    device_dispatch_table(queue)->QueueBeginDebugUtilsLabelEXT(queue, pLabelInfo);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkQueueEndDebugUtilsLabelEXT(VkQueue queue) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkQueueEndDebugUtilsLabelEXT\n";
    }
    device_dispatch_table(queue)->QueueEndDebugUtilsLabelEXT(queue);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkQueueInsertDebugUtilsLabelEXT(VkQueue queue, const VkDebugUtilsLabelEXT* pLabelInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkQueueInsertDebugUtilsLabelEXT\n";
    }
    device_dispatch_table(queue)->QueueInsertDebugUtilsLabelEXT(queue, pLabelInfo);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdBeginDebugUtilsLabelEXT(VkCommandBuffer commandBuffer, const VkDebugUtilsLabelEXT* pLabelInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdBeginDebugUtilsLabelEXT\n";
    }
    device_dispatch_table(commandBuffer)->CmdBeginDebugUtilsLabelEXT(commandBuffer, pLabelInfo);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdEndDebugUtilsLabelEXT(VkCommandBuffer commandBuffer) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdEndDebugUtilsLabelEXT\n";
    }
    device_dispatch_table(commandBuffer)->CmdEndDebugUtilsLabelEXT(commandBuffer);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdInsertDebugUtilsLabelEXT(VkCommandBuffer commandBuffer, const VkDebugUtilsLabelEXT* pLabelInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdInsertDebugUtilsLabelEXT\n";
    }
    device_dispatch_table(commandBuffer)->CmdInsertDebugUtilsLabelEXT(commandBuffer, pLabelInfo);
}
#if defined(VK_USE_PLATFORM_ANDROID_KHR)
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkGetAndroidHardwareBufferPropertiesANDROID(VkDevice device, const struct AHardwareBuffer* buffer, VkAndroidHardwareBufferPropertiesANDROID* pProperties) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetAndroidHardwareBufferPropertiesANDROID\n";
    }
    VkResult result = device_dispatch_table(device)->GetAndroidHardwareBufferPropertiesANDROID(device, buffer, pProperties);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkGetMemoryAndroidHardwareBufferANDROID(VkDevice device, const VkMemoryGetAndroidHardwareBufferInfoANDROID* pInfo, struct AHardwareBuffer** pBuffer) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetMemoryAndroidHardwareBufferANDROID\n";
    }
    VkResult result = device_dispatch_table(device)->GetMemoryAndroidHardwareBufferANDROID(device, pInfo, pBuffer);
    return result;
}
#endif  // VK_USE_PLATFORM_ANDROID_KHR
#if defined(VK_ENABLE_BETA_EXTENSIONS)
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkCreateExecutionGraphPipelinesAMDX(VkDevice device, VkPipelineCache pipelineCache, uint32_t createInfoCount, const VkExecutionGraphPipelineCreateInfoAMDX* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCreateExecutionGraphPipelinesAMDX\n";
    }
    VkResult result = device_dispatch_table(device)->CreateExecutionGraphPipelinesAMDX(device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkGetExecutionGraphPipelineScratchSizeAMDX(VkDevice device, VkPipeline executionGraph, VkExecutionGraphPipelineScratchSizeAMDX* pSizeInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetExecutionGraphPipelineScratchSizeAMDX\n";
    }
    VkResult result = device_dispatch_table(device)->GetExecutionGraphPipelineScratchSizeAMDX(device, executionGraph, pSizeInfo);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkGetExecutionGraphPipelineNodeIndexAMDX(VkDevice device, VkPipeline executionGraph, const VkPipelineShaderStageNodeCreateInfoAMDX* pNodeInfo, uint32_t* pNodeIndex) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetExecutionGraphPipelineNodeIndexAMDX\n";
    }
    VkResult result = device_dispatch_table(device)->GetExecutionGraphPipelineNodeIndexAMDX(device, executionGraph, pNodeInfo, pNodeIndex);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdInitializeGraphScratchMemoryAMDX(VkCommandBuffer commandBuffer, VkPipeline executionGraph, VkDeviceAddress scratch, VkDeviceSize scratchSize) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdInitializeGraphScratchMemoryAMDX\n";
    }
    device_dispatch_table(commandBuffer)->CmdInitializeGraphScratchMemoryAMDX(commandBuffer, executionGraph, scratch, scratchSize);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdDispatchGraphAMDX(VkCommandBuffer commandBuffer, VkDeviceAddress scratch, VkDeviceSize scratchSize, const VkDispatchGraphCountInfoAMDX* pCountInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdDispatchGraphAMDX\n";
    }
    device_dispatch_table(commandBuffer)->CmdDispatchGraphAMDX(commandBuffer, scratch, scratchSize, pCountInfo);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdDispatchGraphIndirectAMDX(VkCommandBuffer commandBuffer, VkDeviceAddress scratch, VkDeviceSize scratchSize, const VkDispatchGraphCountInfoAMDX* pCountInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdDispatchGraphIndirectAMDX\n";
    }
    device_dispatch_table(commandBuffer)->CmdDispatchGraphIndirectAMDX(commandBuffer, scratch, scratchSize, pCountInfo);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdDispatchGraphIndirectCountAMDX(VkCommandBuffer commandBuffer, VkDeviceAddress scratch, VkDeviceSize scratchSize, VkDeviceAddress countInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdDispatchGraphIndirectCountAMDX\n";
    }
    device_dispatch_table(commandBuffer)->CmdDispatchGraphIndirectCountAMDX(commandBuffer, scratch, scratchSize, countInfo);
}
#endif  // VK_ENABLE_BETA_EXTENSIONS
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkWriteSamplerDescriptorsEXT(VkDevice device, uint32_t samplerCount, const VkSamplerCreateInfo* pSamplers, const VkHostAddressRangeEXT* pDescriptors) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkWriteSamplerDescriptorsEXT\n";
    }
    VkResult result = device_dispatch_table(device)->WriteSamplerDescriptorsEXT(device, samplerCount, pSamplers, pDescriptors);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkWriteResourceDescriptorsEXT(VkDevice device, uint32_t resourceCount, const VkResourceDescriptorInfoEXT* pResources, const VkHostAddressRangeEXT* pDescriptors) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkWriteResourceDescriptorsEXT\n";
    }
    VkResult result = device_dispatch_table(device)->WriteResourceDescriptorsEXT(device, resourceCount, pResources, pDescriptors);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdBindSamplerHeapEXT(VkCommandBuffer commandBuffer, const VkBindHeapInfoEXT* pBindInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdBindSamplerHeapEXT\n";
    }
    device_dispatch_table(commandBuffer)->CmdBindSamplerHeapEXT(commandBuffer, pBindInfo);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdBindResourceHeapEXT(VkCommandBuffer commandBuffer, const VkBindHeapInfoEXT* pBindInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdBindResourceHeapEXT\n";
    }
    device_dispatch_table(commandBuffer)->CmdBindResourceHeapEXT(commandBuffer, pBindInfo);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdPushDataEXT(VkCommandBuffer commandBuffer, const VkPushDataInfoEXT* pPushDataInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdPushDataEXT\n";
    }
    device_dispatch_table(commandBuffer)->CmdPushDataEXT(commandBuffer, pPushDataInfo);
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkGetImageOpaqueCaptureDataEXT(VkDevice device, uint32_t imageCount, const VkImage* pImages, VkHostAddressRangeEXT* pDatas) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetImageOpaqueCaptureDataEXT\n";
    }
    VkResult result = device_dispatch_table(device)->GetImageOpaqueCaptureDataEXT(device, imageCount, pImages, pDatas);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkRegisterCustomBorderColorEXT(VkDevice device, const VkSamplerCustomBorderColorCreateInfoEXT* pBorderColor, VkBool32 requestIndex, uint32_t* pIndex) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkRegisterCustomBorderColorEXT\n";
    }
    VkResult result = device_dispatch_table(device)->RegisterCustomBorderColorEXT(device, pBorderColor, requestIndex, pIndex);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkUnregisterCustomBorderColorEXT(VkDevice device, uint32_t index) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkUnregisterCustomBorderColorEXT\n";
    }
    device_dispatch_table(device)->UnregisterCustomBorderColorEXT(device, index);
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkGetTensorOpaqueCaptureDataARM(VkDevice device, uint32_t tensorCount, const VkTensorARM* pTensors, VkHostAddressRangeEXT* pDatas) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetTensorOpaqueCaptureDataARM\n";
    }
    VkResult result = device_dispatch_table(device)->GetTensorOpaqueCaptureDataARM(device, tensorCount, pTensors, pDatas);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdSetSampleLocationsEXT(VkCommandBuffer commandBuffer, const VkSampleLocationsInfoEXT* pSampleLocationsInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdSetSampleLocationsEXT\n";
    }
    device_dispatch_table(commandBuffer)->CmdSetSampleLocationsEXT(commandBuffer, pSampleLocationsInfo);
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkGetImageDrmFormatModifierPropertiesEXT(VkDevice device, VkImage image, VkImageDrmFormatModifierPropertiesEXT* pProperties) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetImageDrmFormatModifierPropertiesEXT\n";
    }
    VkResult result = device_dispatch_table(device)->GetImageDrmFormatModifierPropertiesEXT(device, image, pProperties);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkCreateValidationCacheEXT(VkDevice device, const VkValidationCacheCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkValidationCacheEXT* pValidationCache) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCreateValidationCacheEXT\n";
    }
    VkResult result = device_dispatch_table(device)->CreateValidationCacheEXT(device, pCreateInfo, pAllocator, pValidationCache);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkDestroyValidationCacheEXT(VkDevice device, VkValidationCacheEXT validationCache, const VkAllocationCallbacks* pAllocator) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkDestroyValidationCacheEXT\n";
    }
    device_dispatch_table(device)->DestroyValidationCacheEXT(device, validationCache, pAllocator);
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkMergeValidationCachesEXT(VkDevice device, VkValidationCacheEXT dstCache, uint32_t srcCacheCount, const VkValidationCacheEXT* pSrcCaches) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkMergeValidationCachesEXT\n";
    }
    VkResult result = device_dispatch_table(device)->MergeValidationCachesEXT(device, dstCache, srcCacheCount, pSrcCaches);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkGetValidationCacheDataEXT(VkDevice device, VkValidationCacheEXT validationCache, size_t* pDataSize, void* pData) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetValidationCacheDataEXT\n";
    }
    VkResult result = device_dispatch_table(device)->GetValidationCacheDataEXT(device, validationCache, pDataSize, pData);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdBindShadingRateImageNV(VkCommandBuffer commandBuffer, VkImageView imageView, VkImageLayout imageLayout) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdBindShadingRateImageNV\n";
    }
    device_dispatch_table(commandBuffer)->CmdBindShadingRateImageNV(commandBuffer, imageView, imageLayout);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdSetViewportShadingRatePaletteNV(VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount, const VkShadingRatePaletteNV* pShadingRatePalettes) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdSetViewportShadingRatePaletteNV\n";
    }
    device_dispatch_table(commandBuffer)->CmdSetViewportShadingRatePaletteNV(commandBuffer, firstViewport, viewportCount, pShadingRatePalettes);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdSetCoarseSampleOrderNV(VkCommandBuffer commandBuffer, VkCoarseSampleOrderTypeNV sampleOrderType, uint32_t customSampleOrderCount, const VkCoarseSampleOrderCustomNV* pCustomSampleOrders) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdSetCoarseSampleOrderNV\n";
    }
    device_dispatch_table(commandBuffer)->CmdSetCoarseSampleOrderNV(commandBuffer, sampleOrderType, customSampleOrderCount, pCustomSampleOrders);
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkCreateAccelerationStructureNV(VkDevice device, const VkAccelerationStructureCreateInfoNV* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkAccelerationStructureNV* pAccelerationStructure) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCreateAccelerationStructureNV\n";
    }
    VkResult result = device_dispatch_table(device)->CreateAccelerationStructureNV(device, pCreateInfo, pAllocator, pAccelerationStructure);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkDestroyAccelerationStructureNV(VkDevice device, VkAccelerationStructureNV accelerationStructure, const VkAllocationCallbacks* pAllocator) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkDestroyAccelerationStructureNV\n";
    }
    device_dispatch_table(device)->DestroyAccelerationStructureNV(device, accelerationStructure, pAllocator);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkGetAccelerationStructureMemoryRequirementsNV(VkDevice device, const VkAccelerationStructureMemoryRequirementsInfoNV* pInfo, VkMemoryRequirements2KHR* pMemoryRequirements) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetAccelerationStructureMemoryRequirementsNV\n";
    }
    device_dispatch_table(device)->GetAccelerationStructureMemoryRequirementsNV(device, pInfo, pMemoryRequirements);
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkBindAccelerationStructureMemoryNV(VkDevice device, uint32_t bindInfoCount, const VkBindAccelerationStructureMemoryInfoNV* pBindInfos) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkBindAccelerationStructureMemoryNV\n";
    }
    VkResult result = device_dispatch_table(device)->BindAccelerationStructureMemoryNV(device, bindInfoCount, pBindInfos);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdBuildAccelerationStructureNV(VkCommandBuffer commandBuffer, const VkAccelerationStructureInfoNV* pInfo, VkBuffer instanceData, VkDeviceSize instanceOffset, VkBool32 update, VkAccelerationStructureNV dst, VkAccelerationStructureNV src, VkBuffer scratch, VkDeviceSize scratchOffset) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdBuildAccelerationStructureNV\n";
    }
    device_dispatch_table(commandBuffer)->CmdBuildAccelerationStructureNV(commandBuffer, pInfo, instanceData, instanceOffset, update, dst, src, scratch, scratchOffset);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdCopyAccelerationStructureNV(VkCommandBuffer commandBuffer, VkAccelerationStructureNV dst, VkAccelerationStructureNV src, VkCopyAccelerationStructureModeKHR mode) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdCopyAccelerationStructureNV\n";
    }
    device_dispatch_table(commandBuffer)->CmdCopyAccelerationStructureNV(commandBuffer, dst, src, mode);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdTraceRaysNV(VkCommandBuffer commandBuffer, VkBuffer raygenShaderBindingTableBuffer, VkDeviceSize raygenShaderBindingOffset, VkBuffer missShaderBindingTableBuffer, VkDeviceSize missShaderBindingOffset, VkDeviceSize missShaderBindingStride, VkBuffer hitShaderBindingTableBuffer, VkDeviceSize hitShaderBindingOffset, VkDeviceSize hitShaderBindingStride, VkBuffer callableShaderBindingTableBuffer, VkDeviceSize callableShaderBindingOffset, VkDeviceSize callableShaderBindingStride, uint32_t width, uint32_t height, uint32_t depth) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdTraceRaysNV\n";
    }
    device_dispatch_table(commandBuffer)->CmdTraceRaysNV(commandBuffer, raygenShaderBindingTableBuffer, raygenShaderBindingOffset, missShaderBindingTableBuffer, missShaderBindingOffset, missShaderBindingStride, hitShaderBindingTableBuffer, hitShaderBindingOffset, hitShaderBindingStride, callableShaderBindingTableBuffer, callableShaderBindingOffset, callableShaderBindingStride, width, height, depth);
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkCreateRayTracingPipelinesNV(VkDevice device, VkPipelineCache pipelineCache, uint32_t createInfoCount, const VkRayTracingPipelineCreateInfoNV* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCreateRayTracingPipelinesNV\n";
    }
    VkResult result = device_dispatch_table(device)->CreateRayTracingPipelinesNV(device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkGetRayTracingShaderGroupHandlesKHR(VkDevice device, VkPipeline pipeline, uint32_t firstGroup, uint32_t groupCount, size_t dataSize, void* pData) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetRayTracingShaderGroupHandlesKHR\n";
    }
    VkResult result = device_dispatch_table(device)->GetRayTracingShaderGroupHandlesKHR(device, pipeline, firstGroup, groupCount, dataSize, pData);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkGetRayTracingShaderGroupHandlesNV(VkDevice device, VkPipeline pipeline, uint32_t firstGroup, uint32_t groupCount, size_t dataSize, void* pData) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetRayTracingShaderGroupHandlesNV\n";
    }
    VkResult result = device_dispatch_table(device)->GetRayTracingShaderGroupHandlesNV(device, pipeline, firstGroup, groupCount, dataSize, pData);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkGetAccelerationStructureHandleNV(VkDevice device, VkAccelerationStructureNV accelerationStructure, size_t dataSize, void* pData) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetAccelerationStructureHandleNV\n";
    }
    VkResult result = device_dispatch_table(device)->GetAccelerationStructureHandleNV(device, accelerationStructure, dataSize, pData);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdWriteAccelerationStructuresPropertiesNV(VkCommandBuffer commandBuffer, uint32_t accelerationStructureCount, const VkAccelerationStructureNV* pAccelerationStructures, VkQueryType queryType, VkQueryPool queryPool, uint32_t firstQuery) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdWriteAccelerationStructuresPropertiesNV\n";
    }
    device_dispatch_table(commandBuffer)->CmdWriteAccelerationStructuresPropertiesNV(commandBuffer, accelerationStructureCount, pAccelerationStructures, queryType, queryPool, firstQuery);
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkCompileDeferredNV(VkDevice device, VkPipeline pipeline, uint32_t shader) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCompileDeferredNV\n";
    }
    VkResult result = device_dispatch_table(device)->CompileDeferredNV(device, pipeline, shader);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkGetMemoryHostPointerPropertiesEXT(VkDevice device, VkExternalMemoryHandleTypeFlagBits handleType, const void* pHostPointer, VkMemoryHostPointerPropertiesEXT* pMemoryHostPointerProperties) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetMemoryHostPointerPropertiesEXT\n";
    }
    VkResult result = device_dispatch_table(device)->GetMemoryHostPointerPropertiesEXT(device, handleType, pHostPointer, pMemoryHostPointerProperties);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdWriteBufferMarkerAMD(VkCommandBuffer commandBuffer, VkPipelineStageFlagBits pipelineStage, VkBuffer dstBuffer, VkDeviceSize dstOffset, uint32_t marker) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdWriteBufferMarkerAMD\n";
    }
    device_dispatch_table(commandBuffer)->CmdWriteBufferMarkerAMD(commandBuffer, pipelineStage, dstBuffer, dstOffset, marker);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdWriteBufferMarker2AMD(VkCommandBuffer commandBuffer, VkPipelineStageFlags2 stage, VkBuffer dstBuffer, VkDeviceSize dstOffset, uint32_t marker) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdWriteBufferMarker2AMD\n";
    }
    device_dispatch_table(commandBuffer)->CmdWriteBufferMarker2AMD(commandBuffer, stage, dstBuffer, dstOffset, marker);
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkGetCalibratedTimestampsEXT(VkDevice device, uint32_t timestampCount, const VkCalibratedTimestampInfoKHR* pTimestampInfos, uint64_t* pTimestamps, uint64_t* pMaxDeviation) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetCalibratedTimestampsEXT\n";
    }
    VkResult result = device_dispatch_table(device)->GetCalibratedTimestampsEXT(device, timestampCount, pTimestampInfos, pTimestamps, pMaxDeviation);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdDrawMeshTasksNV(VkCommandBuffer commandBuffer, uint32_t taskCount, uint32_t firstTask) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdDrawMeshTasksNV\n";
    }
    device_dispatch_table(commandBuffer)->CmdDrawMeshTasksNV(commandBuffer, taskCount, firstTask);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdDrawMeshTasksIndirectNV(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdDrawMeshTasksIndirectNV\n";
    }
    device_dispatch_table(commandBuffer)->CmdDrawMeshTasksIndirectNV(commandBuffer, buffer, offset, drawCount, stride);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdDrawMeshTasksIndirectCountNV(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdDrawMeshTasksIndirectCountNV\n";
    }
    device_dispatch_table(commandBuffer)->CmdDrawMeshTasksIndirectCountNV(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdSetExclusiveScissorEnableNV(VkCommandBuffer commandBuffer, uint32_t firstExclusiveScissor, uint32_t exclusiveScissorCount, const VkBool32* pExclusiveScissorEnables) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdSetExclusiveScissorEnableNV\n";
    }
    device_dispatch_table(commandBuffer)->CmdSetExclusiveScissorEnableNV(commandBuffer, firstExclusiveScissor, exclusiveScissorCount, pExclusiveScissorEnables);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdSetExclusiveScissorNV(VkCommandBuffer commandBuffer, uint32_t firstExclusiveScissor, uint32_t exclusiveScissorCount, const VkRect2D* pExclusiveScissors) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdSetExclusiveScissorNV\n";
    }
    device_dispatch_table(commandBuffer)->CmdSetExclusiveScissorNV(commandBuffer, firstExclusiveScissor, exclusiveScissorCount, pExclusiveScissors);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdSetCheckpointNV(VkCommandBuffer commandBuffer, const void* pCheckpointMarker) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdSetCheckpointNV\n";
    }
    device_dispatch_table(commandBuffer)->CmdSetCheckpointNV(commandBuffer, pCheckpointMarker);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkGetQueueCheckpointDataNV(VkQueue queue, uint32_t* pCheckpointDataCount, VkCheckpointDataNV* pCheckpointData) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetQueueCheckpointDataNV\n";
    }
    device_dispatch_table(queue)->GetQueueCheckpointDataNV(queue, pCheckpointDataCount, pCheckpointData);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkGetQueueCheckpointData2NV(VkQueue queue, uint32_t* pCheckpointDataCount, VkCheckpointData2NV* pCheckpointData) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetQueueCheckpointData2NV\n";
    }
    device_dispatch_table(queue)->GetQueueCheckpointData2NV(queue, pCheckpointDataCount, pCheckpointData);
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkSetSwapchainPresentTimingQueueSizeEXT(VkDevice device, VkSwapchainKHR swapchain, uint32_t size) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkSetSwapchainPresentTimingQueueSizeEXT\n";
    }
    VkResult result = device_dispatch_table(device)->SetSwapchainPresentTimingQueueSizeEXT(device, swapchain, size);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkGetSwapchainTimingPropertiesEXT(VkDevice device, VkSwapchainKHR swapchain, VkSwapchainTimingPropertiesEXT* pSwapchainTimingProperties, uint64_t* pSwapchainTimingPropertiesCounter) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetSwapchainTimingPropertiesEXT\n";
    }
    VkResult result = device_dispatch_table(device)->GetSwapchainTimingPropertiesEXT(device, swapchain, pSwapchainTimingProperties, pSwapchainTimingPropertiesCounter);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkGetSwapchainTimeDomainPropertiesEXT(VkDevice device, VkSwapchainKHR swapchain, VkSwapchainTimeDomainPropertiesEXT* pSwapchainTimeDomainProperties, uint64_t* pTimeDomainsCounter) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetSwapchainTimeDomainPropertiesEXT\n";
    }
    VkResult result = device_dispatch_table(device)->GetSwapchainTimeDomainPropertiesEXT(device, swapchain, pSwapchainTimeDomainProperties, pTimeDomainsCounter);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkGetPastPresentationTimingEXT(VkDevice device, const VkPastPresentationTimingInfoEXT* pPastPresentationTimingInfo, VkPastPresentationTimingPropertiesEXT* pPastPresentationTimingProperties) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetPastPresentationTimingEXT\n";
    }
    VkResult result = device_dispatch_table(device)->GetPastPresentationTimingEXT(device, pPastPresentationTimingInfo, pPastPresentationTimingProperties);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkInitializePerformanceApiINTEL(VkDevice device, const VkInitializePerformanceApiInfoINTEL* pInitializeInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkInitializePerformanceApiINTEL\n";
    }
    VkResult result = device_dispatch_table(device)->InitializePerformanceApiINTEL(device, pInitializeInfo);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkUninitializePerformanceApiINTEL(VkDevice device) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkUninitializePerformanceApiINTEL\n";
    }
    device_dispatch_table(device)->UninitializePerformanceApiINTEL(device);
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkCmdSetPerformanceMarkerINTEL(VkCommandBuffer commandBuffer, const VkPerformanceMarkerInfoINTEL* pMarkerInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdSetPerformanceMarkerINTEL\n";
    }
    VkResult result = device_dispatch_table(commandBuffer)->CmdSetPerformanceMarkerINTEL(commandBuffer, pMarkerInfo);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkCmdSetPerformanceStreamMarkerINTEL(VkCommandBuffer commandBuffer, const VkPerformanceStreamMarkerInfoINTEL* pMarkerInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdSetPerformanceStreamMarkerINTEL\n";
    }
    VkResult result = device_dispatch_table(commandBuffer)->CmdSetPerformanceStreamMarkerINTEL(commandBuffer, pMarkerInfo);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkCmdSetPerformanceOverrideINTEL(VkCommandBuffer commandBuffer, const VkPerformanceOverrideInfoINTEL* pOverrideInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdSetPerformanceOverrideINTEL\n";
    }
    VkResult result = device_dispatch_table(commandBuffer)->CmdSetPerformanceOverrideINTEL(commandBuffer, pOverrideInfo);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkAcquirePerformanceConfigurationINTEL(VkDevice device, const VkPerformanceConfigurationAcquireInfoINTEL* pAcquireInfo, VkPerformanceConfigurationINTEL* pConfiguration) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkAcquirePerformanceConfigurationINTEL\n";
    }
    VkResult result = device_dispatch_table(device)->AcquirePerformanceConfigurationINTEL(device, pAcquireInfo, pConfiguration);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkReleasePerformanceConfigurationINTEL(VkDevice device, VkPerformanceConfigurationINTEL configuration) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkReleasePerformanceConfigurationINTEL\n";
    }
    VkResult result = device_dispatch_table(device)->ReleasePerformanceConfigurationINTEL(device, configuration);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkQueueSetPerformanceConfigurationINTEL(VkQueue queue, VkPerformanceConfigurationINTEL configuration) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkQueueSetPerformanceConfigurationINTEL\n";
    }
    VkResult result = device_dispatch_table(queue)->QueueSetPerformanceConfigurationINTEL(queue, configuration);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkGetPerformanceParameterINTEL(VkDevice device, VkPerformanceParameterTypeINTEL parameter, VkPerformanceValueINTEL* pValue) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetPerformanceParameterINTEL\n";
    }
    VkResult result = device_dispatch_table(device)->GetPerformanceParameterINTEL(device, parameter, pValue);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkSetLocalDimmingAMD(VkDevice device, VkSwapchainKHR swapChain, VkBool32 localDimmingEnable) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkSetLocalDimmingAMD\n";
    }
    device_dispatch_table(device)->SetLocalDimmingAMD(device, swapChain, localDimmingEnable);
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkDeviceAddress VKAPI_CALL vkGetBufferDeviceAddressEXT(VkDevice device, const VkBufferDeviceAddressInfo* pInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetBufferDeviceAddressEXT\n";
    }
    VkDeviceAddress result = device_dispatch_table(device)->GetBufferDeviceAddressEXT(device, pInfo);
    return result;
}
#if defined(VK_USE_PLATFORM_WIN32_KHR)
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkAcquireFullScreenExclusiveModeEXT(VkDevice device, VkSwapchainKHR swapchain) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkAcquireFullScreenExclusiveModeEXT\n";
    }
    VkResult result = device_dispatch_table(device)->AcquireFullScreenExclusiveModeEXT(device, swapchain);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkReleaseFullScreenExclusiveModeEXT(VkDevice device, VkSwapchainKHR swapchain) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkReleaseFullScreenExclusiveModeEXT\n";
    }
    VkResult result = device_dispatch_table(device)->ReleaseFullScreenExclusiveModeEXT(device, swapchain);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkGetDeviceGroupSurfacePresentModes2EXT(VkDevice device, const VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo, VkDeviceGroupPresentModeFlagsKHR* pModes) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetDeviceGroupSurfacePresentModes2EXT\n";
    }
    VkResult result = device_dispatch_table(device)->GetDeviceGroupSurfacePresentModes2EXT(device, pSurfaceInfo, pModes);
    return result;
}
#endif  // VK_USE_PLATFORM_WIN32_KHR
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdSetLineStippleEXT(VkCommandBuffer commandBuffer, uint32_t lineStippleFactor, uint16_t lineStipplePattern) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdSetLineStippleEXT\n";
    }
    device_dispatch_table(commandBuffer)->CmdSetLineStippleEXT(commandBuffer, lineStippleFactor, lineStipplePattern);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkResetQueryPoolEXT(VkDevice device, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkResetQueryPoolEXT\n";
    }
    device_dispatch_table(device)->ResetQueryPoolEXT(device, queryPool, firstQuery, queryCount);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdSetCullModeEXT(VkCommandBuffer commandBuffer, VkCullModeFlags cullMode) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdSetCullModeEXT\n";
    }
    device_dispatch_table(commandBuffer)->CmdSetCullModeEXT(commandBuffer, cullMode);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdSetFrontFaceEXT(VkCommandBuffer commandBuffer, VkFrontFace frontFace) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdSetFrontFaceEXT\n";
    }
    device_dispatch_table(commandBuffer)->CmdSetFrontFaceEXT(commandBuffer, frontFace);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdSetPrimitiveTopologyEXT(VkCommandBuffer commandBuffer, VkPrimitiveTopology primitiveTopology) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdSetPrimitiveTopologyEXT\n";
    }
    device_dispatch_table(commandBuffer)->CmdSetPrimitiveTopologyEXT(commandBuffer, primitiveTopology);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdSetViewportWithCountEXT(VkCommandBuffer commandBuffer, uint32_t viewportCount, const VkViewport* pViewports) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdSetViewportWithCountEXT\n";
    }
    device_dispatch_table(commandBuffer)->CmdSetViewportWithCountEXT(commandBuffer, viewportCount, pViewports);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdSetScissorWithCountEXT(VkCommandBuffer commandBuffer, uint32_t scissorCount, const VkRect2D* pScissors) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdSetScissorWithCountEXT\n";
    }
    device_dispatch_table(commandBuffer)->CmdSetScissorWithCountEXT(commandBuffer, scissorCount, pScissors);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdBindVertexBuffers2EXT(VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount, const VkBuffer* pBuffers, const VkDeviceSize* pOffsets, const VkDeviceSize* pSizes, const VkDeviceSize* pStrides) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdBindVertexBuffers2EXT\n";
    }
    device_dispatch_table(commandBuffer)->CmdBindVertexBuffers2EXT(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes, pStrides);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdSetDepthTestEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthTestEnable) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdSetDepthTestEnableEXT\n";
    }
    device_dispatch_table(commandBuffer)->CmdSetDepthTestEnableEXT(commandBuffer, depthTestEnable);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdSetDepthWriteEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthWriteEnable) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdSetDepthWriteEnableEXT\n";
    }
    device_dispatch_table(commandBuffer)->CmdSetDepthWriteEnableEXT(commandBuffer, depthWriteEnable);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdSetDepthCompareOpEXT(VkCommandBuffer commandBuffer, VkCompareOp depthCompareOp) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdSetDepthCompareOpEXT\n";
    }
    device_dispatch_table(commandBuffer)->CmdSetDepthCompareOpEXT(commandBuffer, depthCompareOp);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdSetDepthBoundsTestEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthBoundsTestEnable) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdSetDepthBoundsTestEnableEXT\n";
    }
    device_dispatch_table(commandBuffer)->CmdSetDepthBoundsTestEnableEXT(commandBuffer, depthBoundsTestEnable);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdSetStencilTestEnableEXT(VkCommandBuffer commandBuffer, VkBool32 stencilTestEnable) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdSetStencilTestEnableEXT\n";
    }
    device_dispatch_table(commandBuffer)->CmdSetStencilTestEnableEXT(commandBuffer, stencilTestEnable);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdSetStencilOpEXT(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, VkStencilOp failOp, VkStencilOp passOp, VkStencilOp depthFailOp, VkCompareOp compareOp) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdSetStencilOpEXT\n";
    }
    device_dispatch_table(commandBuffer)->CmdSetStencilOpEXT(commandBuffer, faceMask, failOp, passOp, depthFailOp, compareOp);
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkCopyMemoryToImageEXT(VkDevice device, const VkCopyMemoryToImageInfo* pCopyMemoryToImageInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCopyMemoryToImageEXT\n";
    }
    VkResult result = device_dispatch_table(device)->CopyMemoryToImageEXT(device, pCopyMemoryToImageInfo);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkCopyImageToMemoryEXT(VkDevice device, const VkCopyImageToMemoryInfo* pCopyImageToMemoryInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCopyImageToMemoryEXT\n";
    }
    VkResult result = device_dispatch_table(device)->CopyImageToMemoryEXT(device, pCopyImageToMemoryInfo);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkCopyImageToImageEXT(VkDevice device, const VkCopyImageToImageInfo* pCopyImageToImageInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCopyImageToImageEXT\n";
    }
    VkResult result = device_dispatch_table(device)->CopyImageToImageEXT(device, pCopyImageToImageInfo);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkTransitionImageLayoutEXT(VkDevice device, uint32_t transitionCount, const VkHostImageLayoutTransitionInfo* pTransitions) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkTransitionImageLayoutEXT\n";
    }
    VkResult result = device_dispatch_table(device)->TransitionImageLayoutEXT(device, transitionCount, pTransitions);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkGetImageSubresourceLayout2EXT(VkDevice device, VkImage image, const VkImageSubresource2* pSubresource, VkSubresourceLayout2* pLayout) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetImageSubresourceLayout2EXT\n";
    }
    device_dispatch_table(device)->GetImageSubresourceLayout2EXT(device, image, pSubresource, pLayout);
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkReleaseSwapchainImagesEXT(VkDevice device, const VkReleaseSwapchainImagesInfoKHR* pReleaseInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkReleaseSwapchainImagesEXT\n";
    }
    VkResult result = device_dispatch_table(device)->ReleaseSwapchainImagesEXT(device, pReleaseInfo);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkGetGeneratedCommandsMemoryRequirementsNV(VkDevice device, const VkGeneratedCommandsMemoryRequirementsInfoNV* pInfo, VkMemoryRequirements2* pMemoryRequirements) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetGeneratedCommandsMemoryRequirementsNV\n";
    }
    device_dispatch_table(device)->GetGeneratedCommandsMemoryRequirementsNV(device, pInfo, pMemoryRequirements);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdPreprocessGeneratedCommandsNV(VkCommandBuffer commandBuffer, const VkGeneratedCommandsInfoNV* pGeneratedCommandsInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdPreprocessGeneratedCommandsNV\n";
    }
    device_dispatch_table(commandBuffer)->CmdPreprocessGeneratedCommandsNV(commandBuffer, pGeneratedCommandsInfo);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdExecuteGeneratedCommandsNV(VkCommandBuffer commandBuffer, VkBool32 isPreprocessed, const VkGeneratedCommandsInfoNV* pGeneratedCommandsInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdExecuteGeneratedCommandsNV\n";
    }
    device_dispatch_table(commandBuffer)->CmdExecuteGeneratedCommandsNV(commandBuffer, isPreprocessed, pGeneratedCommandsInfo);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdBindPipelineShaderGroupNV(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipeline pipeline, uint32_t groupIndex) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdBindPipelineShaderGroupNV\n";
    }
    device_dispatch_table(commandBuffer)->CmdBindPipelineShaderGroupNV(commandBuffer, pipelineBindPoint, pipeline, groupIndex);
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkCreateIndirectCommandsLayoutNV(VkDevice device, const VkIndirectCommandsLayoutCreateInfoNV* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkIndirectCommandsLayoutNV* pIndirectCommandsLayout) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCreateIndirectCommandsLayoutNV\n";
    }
    VkResult result = device_dispatch_table(device)->CreateIndirectCommandsLayoutNV(device, pCreateInfo, pAllocator, pIndirectCommandsLayout);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkDestroyIndirectCommandsLayoutNV(VkDevice device, VkIndirectCommandsLayoutNV indirectCommandsLayout, const VkAllocationCallbacks* pAllocator) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkDestroyIndirectCommandsLayoutNV\n";
    }
    device_dispatch_table(device)->DestroyIndirectCommandsLayoutNV(device, indirectCommandsLayout, pAllocator);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdSetDepthBias2EXT(VkCommandBuffer commandBuffer, const VkDepthBiasInfoEXT* pDepthBiasInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdSetDepthBias2EXT\n";
    }
    device_dispatch_table(commandBuffer)->CmdSetDepthBias2EXT(commandBuffer, pDepthBiasInfo);
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkCreatePrivateDataSlotEXT(VkDevice device, const VkPrivateDataSlotCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkPrivateDataSlot* pPrivateDataSlot) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCreatePrivateDataSlotEXT\n";
    }
    VkResult result = device_dispatch_table(device)->CreatePrivateDataSlotEXT(device, pCreateInfo, pAllocator, pPrivateDataSlot);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkDestroyPrivateDataSlotEXT(VkDevice device, VkPrivateDataSlot privateDataSlot, const VkAllocationCallbacks* pAllocator) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkDestroyPrivateDataSlotEXT\n";
    }
    device_dispatch_table(device)->DestroyPrivateDataSlotEXT(device, privateDataSlot, pAllocator);
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkSetPrivateDataEXT(VkDevice device, VkObjectType objectType, uint64_t objectHandle, VkPrivateDataSlot privateDataSlot, uint64_t data) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkSetPrivateDataEXT\n";
    }
    VkResult result = device_dispatch_table(device)->SetPrivateDataEXT(device, objectType, objectHandle, privateDataSlot, data);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkGetPrivateDataEXT(VkDevice device, VkObjectType objectType, uint64_t objectHandle, VkPrivateDataSlot privateDataSlot, uint64_t* pData) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetPrivateDataEXT\n";
    }
    device_dispatch_table(device)->GetPrivateDataEXT(device, objectType, objectHandle, privateDataSlot, pData);
}
#if defined(VK_ENABLE_BETA_EXTENSIONS)
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkCreateCudaModuleNV(VkDevice device, const VkCudaModuleCreateInfoNV* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkCudaModuleNV* pModule) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCreateCudaModuleNV\n";
    }
    VkResult result = device_dispatch_table(device)->CreateCudaModuleNV(device, pCreateInfo, pAllocator, pModule);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkGetCudaModuleCacheNV(VkDevice device, VkCudaModuleNV module, size_t* pCacheSize, void* pCacheData) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetCudaModuleCacheNV\n";
    }
    VkResult result = device_dispatch_table(device)->GetCudaModuleCacheNV(device, module, pCacheSize, pCacheData);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkCreateCudaFunctionNV(VkDevice device, const VkCudaFunctionCreateInfoNV* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkCudaFunctionNV* pFunction) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCreateCudaFunctionNV\n";
    }
    VkResult result = device_dispatch_table(device)->CreateCudaFunctionNV(device, pCreateInfo, pAllocator, pFunction);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkDestroyCudaModuleNV(VkDevice device, VkCudaModuleNV module, const VkAllocationCallbacks* pAllocator) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkDestroyCudaModuleNV\n";
    }
    device_dispatch_table(device)->DestroyCudaModuleNV(device, module, pAllocator);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkDestroyCudaFunctionNV(VkDevice device, VkCudaFunctionNV function, const VkAllocationCallbacks* pAllocator) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkDestroyCudaFunctionNV\n";
    }
    device_dispatch_table(device)->DestroyCudaFunctionNV(device, function, pAllocator);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdCudaLaunchKernelNV(VkCommandBuffer commandBuffer, const VkCudaLaunchInfoNV* pLaunchInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdCudaLaunchKernelNV\n";
    }
    device_dispatch_table(commandBuffer)->CmdCudaLaunchKernelNV(commandBuffer, pLaunchInfo);
}
#endif  // VK_ENABLE_BETA_EXTENSIONS
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdDispatchTileQCOM(VkCommandBuffer commandBuffer, const VkDispatchTileInfoQCOM* pDispatchTileInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdDispatchTileQCOM\n";
    }
    device_dispatch_table(commandBuffer)->CmdDispatchTileQCOM(commandBuffer, pDispatchTileInfo);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdBeginPerTileExecutionQCOM(VkCommandBuffer commandBuffer, const VkPerTileBeginInfoQCOM* pPerTileBeginInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdBeginPerTileExecutionQCOM\n";
    }
    device_dispatch_table(commandBuffer)->CmdBeginPerTileExecutionQCOM(commandBuffer, pPerTileBeginInfo);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdEndPerTileExecutionQCOM(VkCommandBuffer commandBuffer, const VkPerTileEndInfoQCOM* pPerTileEndInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdEndPerTileExecutionQCOM\n";
    }
    device_dispatch_table(commandBuffer)->CmdEndPerTileExecutionQCOM(commandBuffer, pPerTileEndInfo);
}
#if defined(VK_USE_PLATFORM_METAL_EXT)
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkExportMetalObjectsEXT(VkDevice device, VkExportMetalObjectsInfoEXT* pMetalObjectsInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkExportMetalObjectsEXT\n";
    }
    device_dispatch_table(device)->ExportMetalObjectsEXT(device, pMetalObjectsInfo);
}
#endif  // VK_USE_PLATFORM_METAL_EXT
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkGetDescriptorSetLayoutSizeEXT(VkDevice device, VkDescriptorSetLayout layout, VkDeviceSize* pLayoutSizeInBytes) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetDescriptorSetLayoutSizeEXT\n";
    }
    device_dispatch_table(device)->GetDescriptorSetLayoutSizeEXT(device, layout, pLayoutSizeInBytes);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkGetDescriptorSetLayoutBindingOffsetEXT(VkDevice device, VkDescriptorSetLayout layout, uint32_t binding, VkDeviceSize* pOffset) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetDescriptorSetLayoutBindingOffsetEXT\n";
    }
    device_dispatch_table(device)->GetDescriptorSetLayoutBindingOffsetEXT(device, layout, binding, pOffset);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkGetDescriptorEXT(VkDevice device, const VkDescriptorGetInfoEXT* pDescriptorInfo, size_t dataSize, void* pDescriptor) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetDescriptorEXT\n";
    }
    device_dispatch_table(device)->GetDescriptorEXT(device, pDescriptorInfo, dataSize, pDescriptor);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdBindDescriptorBuffersEXT(VkCommandBuffer commandBuffer, uint32_t bufferCount, const VkDescriptorBufferBindingInfoEXT* pBindingInfos) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdBindDescriptorBuffersEXT\n";
    }
    device_dispatch_table(commandBuffer)->CmdBindDescriptorBuffersEXT(commandBuffer, bufferCount, pBindingInfos);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdSetDescriptorBufferOffsetsEXT(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipelineLayout layout, uint32_t firstSet, uint32_t setCount, const uint32_t* pBufferIndices, const VkDeviceSize* pOffsets) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdSetDescriptorBufferOffsetsEXT\n";
    }
    device_dispatch_table(commandBuffer)->CmdSetDescriptorBufferOffsetsEXT(commandBuffer, pipelineBindPoint, layout, firstSet, setCount, pBufferIndices, pOffsets);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdBindDescriptorBufferEmbeddedSamplersEXT(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipelineLayout layout, uint32_t set) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdBindDescriptorBufferEmbeddedSamplersEXT\n";
    }
    device_dispatch_table(commandBuffer)->CmdBindDescriptorBufferEmbeddedSamplersEXT(commandBuffer, pipelineBindPoint, layout, set);
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkGetBufferOpaqueCaptureDescriptorDataEXT(VkDevice device, const VkBufferCaptureDescriptorDataInfoEXT* pInfo, void* pData) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetBufferOpaqueCaptureDescriptorDataEXT\n";
    }
    VkResult result = device_dispatch_table(device)->GetBufferOpaqueCaptureDescriptorDataEXT(device, pInfo, pData);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkGetImageOpaqueCaptureDescriptorDataEXT(VkDevice device, const VkImageCaptureDescriptorDataInfoEXT* pInfo, void* pData) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetImageOpaqueCaptureDescriptorDataEXT\n";
    }
    VkResult result = device_dispatch_table(device)->GetImageOpaqueCaptureDescriptorDataEXT(device, pInfo, pData);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkGetImageViewOpaqueCaptureDescriptorDataEXT(VkDevice device, const VkImageViewCaptureDescriptorDataInfoEXT* pInfo, void* pData) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetImageViewOpaqueCaptureDescriptorDataEXT\n";
    }
    VkResult result = device_dispatch_table(device)->GetImageViewOpaqueCaptureDescriptorDataEXT(device, pInfo, pData);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkGetSamplerOpaqueCaptureDescriptorDataEXT(VkDevice device, const VkSamplerCaptureDescriptorDataInfoEXT* pInfo, void* pData) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetSamplerOpaqueCaptureDescriptorDataEXT\n";
    }
    VkResult result = device_dispatch_table(device)->GetSamplerOpaqueCaptureDescriptorDataEXT(device, pInfo, pData);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkGetAccelerationStructureOpaqueCaptureDescriptorDataEXT(VkDevice device, const VkAccelerationStructureCaptureDescriptorDataInfoEXT* pInfo, void* pData) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetAccelerationStructureOpaqueCaptureDescriptorDataEXT\n";
    }
    VkResult result = device_dispatch_table(device)->GetAccelerationStructureOpaqueCaptureDescriptorDataEXT(device, pInfo, pData);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdSetFragmentShadingRateEnumNV(VkCommandBuffer commandBuffer, VkFragmentShadingRateNV shadingRate, const VkFragmentShadingRateCombinerOpKHR combinerOps[2]) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdSetFragmentShadingRateEnumNV\n";
    }
    device_dispatch_table(commandBuffer)->CmdSetFragmentShadingRateEnumNV(commandBuffer, shadingRate, combinerOps);
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkGetDeviceFaultInfoEXT(VkDevice device, VkDeviceFaultCountsEXT* pFaultCounts, VkDeviceFaultInfoEXT* pFaultInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetDeviceFaultInfoEXT\n";
    }
    VkResult result = device_dispatch_table(device)->GetDeviceFaultInfoEXT(device, pFaultCounts, pFaultInfo);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdSetVertexInputEXT(VkCommandBuffer commandBuffer, uint32_t vertexBindingDescriptionCount, const VkVertexInputBindingDescription2EXT* pVertexBindingDescriptions, uint32_t vertexAttributeDescriptionCount, const VkVertexInputAttributeDescription2EXT* pVertexAttributeDescriptions) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdSetVertexInputEXT\n";
    }
    device_dispatch_table(commandBuffer)->CmdSetVertexInputEXT(commandBuffer, vertexBindingDescriptionCount, pVertexBindingDescriptions, vertexAttributeDescriptionCount, pVertexAttributeDescriptions);
}
#if defined(VK_USE_PLATFORM_FUCHSIA)
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkGetMemoryZirconHandleFUCHSIA(VkDevice device, const VkMemoryGetZirconHandleInfoFUCHSIA* pGetZirconHandleInfo, zx_handle_t* pZirconHandle) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetMemoryZirconHandleFUCHSIA\n";
    }
    VkResult result = device_dispatch_table(device)->GetMemoryZirconHandleFUCHSIA(device, pGetZirconHandleInfo, pZirconHandle);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkGetMemoryZirconHandlePropertiesFUCHSIA(VkDevice device, VkExternalMemoryHandleTypeFlagBits handleType, zx_handle_t zirconHandle, VkMemoryZirconHandlePropertiesFUCHSIA* pMemoryZirconHandleProperties) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetMemoryZirconHandlePropertiesFUCHSIA\n";
    }
    VkResult result = device_dispatch_table(device)->GetMemoryZirconHandlePropertiesFUCHSIA(device, handleType, zirconHandle, pMemoryZirconHandleProperties);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkImportSemaphoreZirconHandleFUCHSIA(VkDevice device, const VkImportSemaphoreZirconHandleInfoFUCHSIA* pImportSemaphoreZirconHandleInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkImportSemaphoreZirconHandleFUCHSIA\n";
    }
    VkResult result = device_dispatch_table(device)->ImportSemaphoreZirconHandleFUCHSIA(device, pImportSemaphoreZirconHandleInfo);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkGetSemaphoreZirconHandleFUCHSIA(VkDevice device, const VkSemaphoreGetZirconHandleInfoFUCHSIA* pGetZirconHandleInfo, zx_handle_t* pZirconHandle) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetSemaphoreZirconHandleFUCHSIA\n";
    }
    VkResult result = device_dispatch_table(device)->GetSemaphoreZirconHandleFUCHSIA(device, pGetZirconHandleInfo, pZirconHandle);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkCreateBufferCollectionFUCHSIA(VkDevice device, const VkBufferCollectionCreateInfoFUCHSIA* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkBufferCollectionFUCHSIA* pCollection) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCreateBufferCollectionFUCHSIA\n";
    }
    VkResult result = device_dispatch_table(device)->CreateBufferCollectionFUCHSIA(device, pCreateInfo, pAllocator, pCollection);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkSetBufferCollectionImageConstraintsFUCHSIA(VkDevice device, VkBufferCollectionFUCHSIA collection, const VkImageConstraintsInfoFUCHSIA* pImageConstraintsInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkSetBufferCollectionImageConstraintsFUCHSIA\n";
    }
    VkResult result = device_dispatch_table(device)->SetBufferCollectionImageConstraintsFUCHSIA(device, collection, pImageConstraintsInfo);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkSetBufferCollectionBufferConstraintsFUCHSIA(VkDevice device, VkBufferCollectionFUCHSIA collection, const VkBufferConstraintsInfoFUCHSIA* pBufferConstraintsInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkSetBufferCollectionBufferConstraintsFUCHSIA\n";
    }
    VkResult result = device_dispatch_table(device)->SetBufferCollectionBufferConstraintsFUCHSIA(device, collection, pBufferConstraintsInfo);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkDestroyBufferCollectionFUCHSIA(VkDevice device, VkBufferCollectionFUCHSIA collection, const VkAllocationCallbacks* pAllocator) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkDestroyBufferCollectionFUCHSIA\n";
    }
    device_dispatch_table(device)->DestroyBufferCollectionFUCHSIA(device, collection, pAllocator);
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkGetBufferCollectionPropertiesFUCHSIA(VkDevice device, VkBufferCollectionFUCHSIA collection, VkBufferCollectionPropertiesFUCHSIA* pProperties) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetBufferCollectionPropertiesFUCHSIA\n";
    }
    VkResult result = device_dispatch_table(device)->GetBufferCollectionPropertiesFUCHSIA(device, collection, pProperties);
    return result;
}
#endif  // VK_USE_PLATFORM_FUCHSIA
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkGetDeviceSubpassShadingMaxWorkgroupSizeHUAWEI(VkDevice device, VkRenderPass renderpass, VkExtent2D* pMaxWorkgroupSize) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetDeviceSubpassShadingMaxWorkgroupSizeHUAWEI\n";
    }
    VkResult result = device_dispatch_table(device)->GetDeviceSubpassShadingMaxWorkgroupSizeHUAWEI(device, renderpass, pMaxWorkgroupSize);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdSubpassShadingHUAWEI(VkCommandBuffer commandBuffer) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdSubpassShadingHUAWEI\n";
    }
    device_dispatch_table(commandBuffer)->CmdSubpassShadingHUAWEI(commandBuffer);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdBindInvocationMaskHUAWEI(VkCommandBuffer commandBuffer, VkImageView imageView, VkImageLayout imageLayout) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdBindInvocationMaskHUAWEI\n";
    }
    device_dispatch_table(commandBuffer)->CmdBindInvocationMaskHUAWEI(commandBuffer, imageView, imageLayout);
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkGetMemoryRemoteAddressNV(VkDevice device, const VkMemoryGetRemoteAddressInfoNV* pMemoryGetRemoteAddressInfo, VkRemoteAddressNV* pAddress) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetMemoryRemoteAddressNV\n";
    }
    VkResult result = device_dispatch_table(device)->GetMemoryRemoteAddressNV(device, pMemoryGetRemoteAddressInfo, pAddress);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkGetPipelinePropertiesEXT(VkDevice device, const VkPipelineInfoEXT* pPipelineInfo, VkBaseOutStructure* pPipelineProperties) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetPipelinePropertiesEXT\n";
    }
    VkResult result = device_dispatch_table(device)->GetPipelinePropertiesEXT(device, pPipelineInfo, pPipelineProperties);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdSetPatchControlPointsEXT(VkCommandBuffer commandBuffer, uint32_t patchControlPoints) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdSetPatchControlPointsEXT\n";
    }
    device_dispatch_table(commandBuffer)->CmdSetPatchControlPointsEXT(commandBuffer, patchControlPoints);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdSetRasterizerDiscardEnableEXT(VkCommandBuffer commandBuffer, VkBool32 rasterizerDiscardEnable) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdSetRasterizerDiscardEnableEXT\n";
    }
    device_dispatch_table(commandBuffer)->CmdSetRasterizerDiscardEnableEXT(commandBuffer, rasterizerDiscardEnable);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdSetDepthBiasEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthBiasEnable) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdSetDepthBiasEnableEXT\n";
    }
    device_dispatch_table(commandBuffer)->CmdSetDepthBiasEnableEXT(commandBuffer, depthBiasEnable);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdSetLogicOpEXT(VkCommandBuffer commandBuffer, VkLogicOp logicOp) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdSetLogicOpEXT\n";
    }
    device_dispatch_table(commandBuffer)->CmdSetLogicOpEXT(commandBuffer, logicOp);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdSetPrimitiveRestartEnableEXT(VkCommandBuffer commandBuffer, VkBool32 primitiveRestartEnable) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdSetPrimitiveRestartEnableEXT\n";
    }
    device_dispatch_table(commandBuffer)->CmdSetPrimitiveRestartEnableEXT(commandBuffer, primitiveRestartEnable);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdSetColorWriteEnableEXT(VkCommandBuffer commandBuffer, uint32_t attachmentCount, const VkBool32* pColorWriteEnables) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdSetColorWriteEnableEXT\n";
    }
    device_dispatch_table(commandBuffer)->CmdSetColorWriteEnableEXT(commandBuffer, attachmentCount, pColorWriteEnables);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdDrawMultiEXT(VkCommandBuffer commandBuffer, uint32_t drawCount, const VkMultiDrawInfoEXT* pVertexInfo, uint32_t instanceCount, uint32_t firstInstance, uint32_t stride) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdDrawMultiEXT\n";
    }
    device_dispatch_table(commandBuffer)->CmdDrawMultiEXT(commandBuffer, drawCount, pVertexInfo, instanceCount, firstInstance, stride);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdDrawMultiIndexedEXT(VkCommandBuffer commandBuffer, uint32_t drawCount, const VkMultiDrawIndexedInfoEXT* pIndexInfo, uint32_t instanceCount, uint32_t firstInstance, uint32_t stride, const int32_t* pVertexOffset) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdDrawMultiIndexedEXT\n";
    }
    device_dispatch_table(commandBuffer)->CmdDrawMultiIndexedEXT(commandBuffer, drawCount, pIndexInfo, instanceCount, firstInstance, stride, pVertexOffset);
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkCreateMicromapEXT(VkDevice device, const VkMicromapCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkMicromapEXT* pMicromap) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCreateMicromapEXT\n";
    }
    VkResult result = device_dispatch_table(device)->CreateMicromapEXT(device, pCreateInfo, pAllocator, pMicromap);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkDestroyMicromapEXT(VkDevice device, VkMicromapEXT micromap, const VkAllocationCallbacks* pAllocator) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkDestroyMicromapEXT\n";
    }
    device_dispatch_table(device)->DestroyMicromapEXT(device, micromap, pAllocator);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdBuildMicromapsEXT(VkCommandBuffer commandBuffer, uint32_t infoCount, const VkMicromapBuildInfoEXT* pInfos) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdBuildMicromapsEXT\n";
    }
    device_dispatch_table(commandBuffer)->CmdBuildMicromapsEXT(commandBuffer, infoCount, pInfos);
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkBuildMicromapsEXT(VkDevice device, VkDeferredOperationKHR deferredOperation, uint32_t infoCount, const VkMicromapBuildInfoEXT* pInfos) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkBuildMicromapsEXT\n";
    }
    VkResult result = device_dispatch_table(device)->BuildMicromapsEXT(device, deferredOperation, infoCount, pInfos);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkCopyMicromapEXT(VkDevice device, VkDeferredOperationKHR deferredOperation, const VkCopyMicromapInfoEXT* pInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCopyMicromapEXT\n";
    }
    VkResult result = device_dispatch_table(device)->CopyMicromapEXT(device, deferredOperation, pInfo);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkCopyMicromapToMemoryEXT(VkDevice device, VkDeferredOperationKHR deferredOperation, const VkCopyMicromapToMemoryInfoEXT* pInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCopyMicromapToMemoryEXT\n";
    }
    VkResult result = device_dispatch_table(device)->CopyMicromapToMemoryEXT(device, deferredOperation, pInfo);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkCopyMemoryToMicromapEXT(VkDevice device, VkDeferredOperationKHR deferredOperation, const VkCopyMemoryToMicromapInfoEXT* pInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCopyMemoryToMicromapEXT\n";
    }
    VkResult result = device_dispatch_table(device)->CopyMemoryToMicromapEXT(device, deferredOperation, pInfo);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkWriteMicromapsPropertiesEXT(VkDevice device, uint32_t micromapCount, const VkMicromapEXT* pMicromaps, VkQueryType queryType, size_t dataSize, void* pData, size_t stride) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkWriteMicromapsPropertiesEXT\n";
    }
    VkResult result = device_dispatch_table(device)->WriteMicromapsPropertiesEXT(device, micromapCount, pMicromaps, queryType, dataSize, pData, stride);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdCopyMicromapEXT(VkCommandBuffer commandBuffer, const VkCopyMicromapInfoEXT* pInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdCopyMicromapEXT\n";
    }
    device_dispatch_table(commandBuffer)->CmdCopyMicromapEXT(commandBuffer, pInfo);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdCopyMicromapToMemoryEXT(VkCommandBuffer commandBuffer, const VkCopyMicromapToMemoryInfoEXT* pInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdCopyMicromapToMemoryEXT\n";
    }
    device_dispatch_table(commandBuffer)->CmdCopyMicromapToMemoryEXT(commandBuffer, pInfo);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdCopyMemoryToMicromapEXT(VkCommandBuffer commandBuffer, const VkCopyMemoryToMicromapInfoEXT* pInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdCopyMemoryToMicromapEXT\n";
    }
    device_dispatch_table(commandBuffer)->CmdCopyMemoryToMicromapEXT(commandBuffer, pInfo);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdWriteMicromapsPropertiesEXT(VkCommandBuffer commandBuffer, uint32_t micromapCount, const VkMicromapEXT* pMicromaps, VkQueryType queryType, VkQueryPool queryPool, uint32_t firstQuery) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdWriteMicromapsPropertiesEXT\n";
    }
    device_dispatch_table(commandBuffer)->CmdWriteMicromapsPropertiesEXT(commandBuffer, micromapCount, pMicromaps, queryType, queryPool, firstQuery);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkGetDeviceMicromapCompatibilityEXT(VkDevice device, const VkMicromapVersionInfoEXT* pVersionInfo, VkAccelerationStructureCompatibilityKHR* pCompatibility) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetDeviceMicromapCompatibilityEXT\n";
    }
    device_dispatch_table(device)->GetDeviceMicromapCompatibilityEXT(device, pVersionInfo, pCompatibility);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkGetMicromapBuildSizesEXT(VkDevice device, VkAccelerationStructureBuildTypeKHR buildType, const VkMicromapBuildInfoEXT* pBuildInfo, VkMicromapBuildSizesInfoEXT* pSizeInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetMicromapBuildSizesEXT\n";
    }
    device_dispatch_table(device)->GetMicromapBuildSizesEXT(device, buildType, pBuildInfo, pSizeInfo);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdDrawClusterHUAWEI(VkCommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdDrawClusterHUAWEI\n";
    }
    device_dispatch_table(commandBuffer)->CmdDrawClusterHUAWEI(commandBuffer, groupCountX, groupCountY, groupCountZ);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdDrawClusterIndirectHUAWEI(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdDrawClusterIndirectHUAWEI\n";
    }
    device_dispatch_table(commandBuffer)->CmdDrawClusterIndirectHUAWEI(commandBuffer, buffer, offset);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkSetDeviceMemoryPriorityEXT(VkDevice device, VkDeviceMemory memory, float priority) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkSetDeviceMemoryPriorityEXT\n";
    }
    device_dispatch_table(device)->SetDeviceMemoryPriorityEXT(device, memory, priority);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkGetDescriptorSetLayoutHostMappingInfoVALVE(VkDevice device, const VkDescriptorSetBindingReferenceVALVE* pBindingReference, VkDescriptorSetLayoutHostMappingInfoVALVE* pHostMapping) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetDescriptorSetLayoutHostMappingInfoVALVE\n";
    }
    device_dispatch_table(device)->GetDescriptorSetLayoutHostMappingInfoVALVE(device, pBindingReference, pHostMapping);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkGetDescriptorSetHostMappingVALVE(VkDevice device, VkDescriptorSet descriptorSet, void** ppData) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetDescriptorSetHostMappingVALVE\n";
    }
    device_dispatch_table(device)->GetDescriptorSetHostMappingVALVE(device, descriptorSet, ppData);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdCopyMemoryIndirectNV(VkCommandBuffer commandBuffer, VkDeviceAddress copyBufferAddress, uint32_t copyCount, uint32_t stride) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdCopyMemoryIndirectNV\n";
    }
    device_dispatch_table(commandBuffer)->CmdCopyMemoryIndirectNV(commandBuffer, copyBufferAddress, copyCount, stride);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdCopyMemoryToImageIndirectNV(VkCommandBuffer commandBuffer, VkDeviceAddress copyBufferAddress, uint32_t copyCount, uint32_t stride, VkImage dstImage, VkImageLayout dstImageLayout, const VkImageSubresourceLayers* pImageSubresources) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdCopyMemoryToImageIndirectNV\n";
    }
    device_dispatch_table(commandBuffer)->CmdCopyMemoryToImageIndirectNV(commandBuffer, copyBufferAddress, copyCount, stride, dstImage, dstImageLayout, pImageSubresources);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdDecompressMemoryNV(VkCommandBuffer commandBuffer, uint32_t decompressRegionCount, const VkDecompressMemoryRegionNV* pDecompressMemoryRegions) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdDecompressMemoryNV\n";
    }
    device_dispatch_table(commandBuffer)->CmdDecompressMemoryNV(commandBuffer, decompressRegionCount, pDecompressMemoryRegions);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdDecompressMemoryIndirectCountNV(VkCommandBuffer commandBuffer, VkDeviceAddress indirectCommandsAddress, VkDeviceAddress indirectCommandsCountAddress, uint32_t stride) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdDecompressMemoryIndirectCountNV\n";
    }
    device_dispatch_table(commandBuffer)->CmdDecompressMemoryIndirectCountNV(commandBuffer, indirectCommandsAddress, indirectCommandsCountAddress, stride);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkGetPipelineIndirectMemoryRequirementsNV(VkDevice device, const VkComputePipelineCreateInfo* pCreateInfo, VkMemoryRequirements2* pMemoryRequirements) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetPipelineIndirectMemoryRequirementsNV\n";
    }
    device_dispatch_table(device)->GetPipelineIndirectMemoryRequirementsNV(device, pCreateInfo, pMemoryRequirements);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdUpdatePipelineIndirectBufferNV(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipeline pipeline) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdUpdatePipelineIndirectBufferNV\n";
    }
    device_dispatch_table(commandBuffer)->CmdUpdatePipelineIndirectBufferNV(commandBuffer, pipelineBindPoint, pipeline);
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkDeviceAddress VKAPI_CALL vkGetPipelineIndirectDeviceAddressNV(VkDevice device, const VkPipelineIndirectDeviceAddressInfoNV* pInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetPipelineIndirectDeviceAddressNV\n";
    }
    VkDeviceAddress result = device_dispatch_table(device)->GetPipelineIndirectDeviceAddressNV(device, pInfo);
    return result;
}
#if defined(VK_USE_PLATFORM_OHOS)
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkGetNativeBufferPropertiesOHOS(VkDevice device, const struct OH_NativeBuffer* buffer, VkNativeBufferPropertiesOHOS* pProperties) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetNativeBufferPropertiesOHOS\n";
    }
    VkResult result = device_dispatch_table(device)->GetNativeBufferPropertiesOHOS(device, buffer, pProperties);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkGetMemoryNativeBufferOHOS(VkDevice device, const VkMemoryGetNativeBufferInfoOHOS* pInfo, struct OH_NativeBuffer** pBuffer) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetMemoryNativeBufferOHOS\n";
    }
    VkResult result = device_dispatch_table(device)->GetMemoryNativeBufferOHOS(device, pInfo, pBuffer);
    return result;
}
#endif  // VK_USE_PLATFORM_OHOS
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdSetDepthClampEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthClampEnable) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdSetDepthClampEnableEXT\n";
    }
    device_dispatch_table(commandBuffer)->CmdSetDepthClampEnableEXT(commandBuffer, depthClampEnable);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdSetPolygonModeEXT(VkCommandBuffer commandBuffer, VkPolygonMode polygonMode) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdSetPolygonModeEXT\n";
    }
    device_dispatch_table(commandBuffer)->CmdSetPolygonModeEXT(commandBuffer, polygonMode);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdSetRasterizationSamplesEXT(VkCommandBuffer commandBuffer, VkSampleCountFlagBits rasterizationSamples) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdSetRasterizationSamplesEXT\n";
    }
    device_dispatch_table(commandBuffer)->CmdSetRasterizationSamplesEXT(commandBuffer, rasterizationSamples);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdSetSampleMaskEXT(VkCommandBuffer commandBuffer, VkSampleCountFlagBits samples, const VkSampleMask* pSampleMask) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdSetSampleMaskEXT\n";
    }
    device_dispatch_table(commandBuffer)->CmdSetSampleMaskEXT(commandBuffer, samples, pSampleMask);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdSetAlphaToCoverageEnableEXT(VkCommandBuffer commandBuffer, VkBool32 alphaToCoverageEnable) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdSetAlphaToCoverageEnableEXT\n";
    }
    device_dispatch_table(commandBuffer)->CmdSetAlphaToCoverageEnableEXT(commandBuffer, alphaToCoverageEnable);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdSetAlphaToOneEnableEXT(VkCommandBuffer commandBuffer, VkBool32 alphaToOneEnable) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdSetAlphaToOneEnableEXT\n";
    }
    device_dispatch_table(commandBuffer)->CmdSetAlphaToOneEnableEXT(commandBuffer, alphaToOneEnable);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdSetLogicOpEnableEXT(VkCommandBuffer commandBuffer, VkBool32 logicOpEnable) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdSetLogicOpEnableEXT\n";
    }
    device_dispatch_table(commandBuffer)->CmdSetLogicOpEnableEXT(commandBuffer, logicOpEnable);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdSetColorBlendEnableEXT(VkCommandBuffer commandBuffer, uint32_t firstAttachment, uint32_t attachmentCount, const VkBool32* pColorBlendEnables) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdSetColorBlendEnableEXT\n";
    }
    device_dispatch_table(commandBuffer)->CmdSetColorBlendEnableEXT(commandBuffer, firstAttachment, attachmentCount, pColorBlendEnables);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdSetColorBlendEquationEXT(VkCommandBuffer commandBuffer, uint32_t firstAttachment, uint32_t attachmentCount, const VkColorBlendEquationEXT* pColorBlendEquations) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdSetColorBlendEquationEXT\n";
    }
    device_dispatch_table(commandBuffer)->CmdSetColorBlendEquationEXT(commandBuffer, firstAttachment, attachmentCount, pColorBlendEquations);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdSetColorWriteMaskEXT(VkCommandBuffer commandBuffer, uint32_t firstAttachment, uint32_t attachmentCount, const VkColorComponentFlags* pColorWriteMasks) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdSetColorWriteMaskEXT\n";
    }
    device_dispatch_table(commandBuffer)->CmdSetColorWriteMaskEXT(commandBuffer, firstAttachment, attachmentCount, pColorWriteMasks);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdSetTessellationDomainOriginEXT(VkCommandBuffer commandBuffer, VkTessellationDomainOrigin domainOrigin) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdSetTessellationDomainOriginEXT\n";
    }
    device_dispatch_table(commandBuffer)->CmdSetTessellationDomainOriginEXT(commandBuffer, domainOrigin);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdSetRasterizationStreamEXT(VkCommandBuffer commandBuffer, uint32_t rasterizationStream) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdSetRasterizationStreamEXT\n";
    }
    device_dispatch_table(commandBuffer)->CmdSetRasterizationStreamEXT(commandBuffer, rasterizationStream);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdSetConservativeRasterizationModeEXT(VkCommandBuffer commandBuffer, VkConservativeRasterizationModeEXT conservativeRasterizationMode) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdSetConservativeRasterizationModeEXT\n";
    }
    device_dispatch_table(commandBuffer)->CmdSetConservativeRasterizationModeEXT(commandBuffer, conservativeRasterizationMode);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdSetExtraPrimitiveOverestimationSizeEXT(VkCommandBuffer commandBuffer, float extraPrimitiveOverestimationSize) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdSetExtraPrimitiveOverestimationSizeEXT\n";
    }
    device_dispatch_table(commandBuffer)->CmdSetExtraPrimitiveOverestimationSizeEXT(commandBuffer, extraPrimitiveOverestimationSize);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdSetDepthClipEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthClipEnable) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdSetDepthClipEnableEXT\n";
    }
    device_dispatch_table(commandBuffer)->CmdSetDepthClipEnableEXT(commandBuffer, depthClipEnable);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdSetSampleLocationsEnableEXT(VkCommandBuffer commandBuffer, VkBool32 sampleLocationsEnable) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdSetSampleLocationsEnableEXT\n";
    }
    device_dispatch_table(commandBuffer)->CmdSetSampleLocationsEnableEXT(commandBuffer, sampleLocationsEnable);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdSetColorBlendAdvancedEXT(VkCommandBuffer commandBuffer, uint32_t firstAttachment, uint32_t attachmentCount, const VkColorBlendAdvancedEXT* pColorBlendAdvanced) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdSetColorBlendAdvancedEXT\n";
    }
    device_dispatch_table(commandBuffer)->CmdSetColorBlendAdvancedEXT(commandBuffer, firstAttachment, attachmentCount, pColorBlendAdvanced);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdSetProvokingVertexModeEXT(VkCommandBuffer commandBuffer, VkProvokingVertexModeEXT provokingVertexMode) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdSetProvokingVertexModeEXT\n";
    }
    device_dispatch_table(commandBuffer)->CmdSetProvokingVertexModeEXT(commandBuffer, provokingVertexMode);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdSetLineRasterizationModeEXT(VkCommandBuffer commandBuffer, VkLineRasterizationModeEXT lineRasterizationMode) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdSetLineRasterizationModeEXT\n";
    }
    device_dispatch_table(commandBuffer)->CmdSetLineRasterizationModeEXT(commandBuffer, lineRasterizationMode);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdSetLineStippleEnableEXT(VkCommandBuffer commandBuffer, VkBool32 stippledLineEnable) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdSetLineStippleEnableEXT\n";
    }
    device_dispatch_table(commandBuffer)->CmdSetLineStippleEnableEXT(commandBuffer, stippledLineEnable);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdSetDepthClipNegativeOneToOneEXT(VkCommandBuffer commandBuffer, VkBool32 negativeOneToOne) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdSetDepthClipNegativeOneToOneEXT\n";
    }
    device_dispatch_table(commandBuffer)->CmdSetDepthClipNegativeOneToOneEXT(commandBuffer, negativeOneToOne);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdSetViewportWScalingEnableNV(VkCommandBuffer commandBuffer, VkBool32 viewportWScalingEnable) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdSetViewportWScalingEnableNV\n";
    }
    device_dispatch_table(commandBuffer)->CmdSetViewportWScalingEnableNV(commandBuffer, viewportWScalingEnable);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdSetViewportSwizzleNV(VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount, const VkViewportSwizzleNV* pViewportSwizzles) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdSetViewportSwizzleNV\n";
    }
    device_dispatch_table(commandBuffer)->CmdSetViewportSwizzleNV(commandBuffer, firstViewport, viewportCount, pViewportSwizzles);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdSetCoverageToColorEnableNV(VkCommandBuffer commandBuffer, VkBool32 coverageToColorEnable) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdSetCoverageToColorEnableNV\n";
    }
    device_dispatch_table(commandBuffer)->CmdSetCoverageToColorEnableNV(commandBuffer, coverageToColorEnable);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdSetCoverageToColorLocationNV(VkCommandBuffer commandBuffer, uint32_t coverageToColorLocation) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdSetCoverageToColorLocationNV\n";
    }
    device_dispatch_table(commandBuffer)->CmdSetCoverageToColorLocationNV(commandBuffer, coverageToColorLocation);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdSetCoverageModulationModeNV(VkCommandBuffer commandBuffer, VkCoverageModulationModeNV coverageModulationMode) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdSetCoverageModulationModeNV\n";
    }
    device_dispatch_table(commandBuffer)->CmdSetCoverageModulationModeNV(commandBuffer, coverageModulationMode);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdSetCoverageModulationTableEnableNV(VkCommandBuffer commandBuffer, VkBool32 coverageModulationTableEnable) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdSetCoverageModulationTableEnableNV\n";
    }
    device_dispatch_table(commandBuffer)->CmdSetCoverageModulationTableEnableNV(commandBuffer, coverageModulationTableEnable);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdSetCoverageModulationTableNV(VkCommandBuffer commandBuffer, uint32_t coverageModulationTableCount, const float* pCoverageModulationTable) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdSetCoverageModulationTableNV\n";
    }
    device_dispatch_table(commandBuffer)->CmdSetCoverageModulationTableNV(commandBuffer, coverageModulationTableCount, pCoverageModulationTable);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdSetShadingRateImageEnableNV(VkCommandBuffer commandBuffer, VkBool32 shadingRateImageEnable) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdSetShadingRateImageEnableNV\n";
    }
    device_dispatch_table(commandBuffer)->CmdSetShadingRateImageEnableNV(commandBuffer, shadingRateImageEnable);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdSetRepresentativeFragmentTestEnableNV(VkCommandBuffer commandBuffer, VkBool32 representativeFragmentTestEnable) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdSetRepresentativeFragmentTestEnableNV\n";
    }
    device_dispatch_table(commandBuffer)->CmdSetRepresentativeFragmentTestEnableNV(commandBuffer, representativeFragmentTestEnable);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdSetCoverageReductionModeNV(VkCommandBuffer commandBuffer, VkCoverageReductionModeNV coverageReductionMode) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdSetCoverageReductionModeNV\n";
    }
    device_dispatch_table(commandBuffer)->CmdSetCoverageReductionModeNV(commandBuffer, coverageReductionMode);
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkCreateTensorARM(VkDevice device, const VkTensorCreateInfoARM* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkTensorARM* pTensor) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCreateTensorARM\n";
    }
    VkResult result = device_dispatch_table(device)->CreateTensorARM(device, pCreateInfo, pAllocator, pTensor);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkDestroyTensorARM(VkDevice device, VkTensorARM tensor, const VkAllocationCallbacks* pAllocator) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkDestroyTensorARM\n";
    }
    device_dispatch_table(device)->DestroyTensorARM(device, tensor, pAllocator);
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkCreateTensorViewARM(VkDevice device, const VkTensorViewCreateInfoARM* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkTensorViewARM* pView) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCreateTensorViewARM\n";
    }
    VkResult result = device_dispatch_table(device)->CreateTensorViewARM(device, pCreateInfo, pAllocator, pView);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkDestroyTensorViewARM(VkDevice device, VkTensorViewARM tensorView, const VkAllocationCallbacks* pAllocator) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkDestroyTensorViewARM\n";
    }
    device_dispatch_table(device)->DestroyTensorViewARM(device, tensorView, pAllocator);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkGetTensorMemoryRequirementsARM(VkDevice device, const VkTensorMemoryRequirementsInfoARM* pInfo, VkMemoryRequirements2* pMemoryRequirements) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetTensorMemoryRequirementsARM\n";
    }
    device_dispatch_table(device)->GetTensorMemoryRequirementsARM(device, pInfo, pMemoryRequirements);
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkBindTensorMemoryARM(VkDevice device, uint32_t bindInfoCount, const VkBindTensorMemoryInfoARM* pBindInfos) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkBindTensorMemoryARM\n";
    }
    VkResult result = device_dispatch_table(device)->BindTensorMemoryARM(device, bindInfoCount, pBindInfos);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkGetDeviceTensorMemoryRequirementsARM(VkDevice device, const VkDeviceTensorMemoryRequirementsARM* pInfo, VkMemoryRequirements2* pMemoryRequirements) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetDeviceTensorMemoryRequirementsARM\n";
    }
    device_dispatch_table(device)->GetDeviceTensorMemoryRequirementsARM(device, pInfo, pMemoryRequirements);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdCopyTensorARM(VkCommandBuffer commandBuffer, const VkCopyTensorInfoARM* pCopyTensorInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdCopyTensorARM\n";
    }
    device_dispatch_table(commandBuffer)->CmdCopyTensorARM(commandBuffer, pCopyTensorInfo);
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkGetTensorOpaqueCaptureDescriptorDataARM(VkDevice device, const VkTensorCaptureDescriptorDataInfoARM* pInfo, void* pData) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetTensorOpaqueCaptureDescriptorDataARM\n";
    }
    VkResult result = device_dispatch_table(device)->GetTensorOpaqueCaptureDescriptorDataARM(device, pInfo, pData);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkGetTensorViewOpaqueCaptureDescriptorDataARM(VkDevice device, const VkTensorViewCaptureDescriptorDataInfoARM* pInfo, void* pData) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetTensorViewOpaqueCaptureDescriptorDataARM\n";
    }
    VkResult result = device_dispatch_table(device)->GetTensorViewOpaqueCaptureDescriptorDataARM(device, pInfo, pData);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkGetShaderModuleIdentifierEXT(VkDevice device, VkShaderModule shaderModule, VkShaderModuleIdentifierEXT* pIdentifier) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetShaderModuleIdentifierEXT\n";
    }
    device_dispatch_table(device)->GetShaderModuleIdentifierEXT(device, shaderModule, pIdentifier);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkGetShaderModuleCreateInfoIdentifierEXT(VkDevice device, const VkShaderModuleCreateInfo* pCreateInfo, VkShaderModuleIdentifierEXT* pIdentifier) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetShaderModuleCreateInfoIdentifierEXT\n";
    }
    device_dispatch_table(device)->GetShaderModuleCreateInfoIdentifierEXT(device, pCreateInfo, pIdentifier);
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkCreateOpticalFlowSessionNV(VkDevice device, const VkOpticalFlowSessionCreateInfoNV* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkOpticalFlowSessionNV* pSession) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCreateOpticalFlowSessionNV\n";
    }
    VkResult result = device_dispatch_table(device)->CreateOpticalFlowSessionNV(device, pCreateInfo, pAllocator, pSession);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkDestroyOpticalFlowSessionNV(VkDevice device, VkOpticalFlowSessionNV session, const VkAllocationCallbacks* pAllocator) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkDestroyOpticalFlowSessionNV\n";
    }
    device_dispatch_table(device)->DestroyOpticalFlowSessionNV(device, session, pAllocator);
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkBindOpticalFlowSessionImageNV(VkDevice device, VkOpticalFlowSessionNV session, VkOpticalFlowSessionBindingPointNV bindingPoint, VkImageView view, VkImageLayout layout) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkBindOpticalFlowSessionImageNV\n";
    }
    VkResult result = device_dispatch_table(device)->BindOpticalFlowSessionImageNV(device, session, bindingPoint, view, layout);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdOpticalFlowExecuteNV(VkCommandBuffer commandBuffer, VkOpticalFlowSessionNV session, const VkOpticalFlowExecuteInfoNV* pExecuteInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdOpticalFlowExecuteNV\n";
    }
    device_dispatch_table(commandBuffer)->CmdOpticalFlowExecuteNV(commandBuffer, session, pExecuteInfo);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkAntiLagUpdateAMD(VkDevice device, const VkAntiLagDataAMD* pData) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkAntiLagUpdateAMD\n";
    }
    device_dispatch_table(device)->AntiLagUpdateAMD(device, pData);
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkCreateShadersEXT(VkDevice device, uint32_t createInfoCount, const VkShaderCreateInfoEXT* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkShaderEXT* pShaders) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCreateShadersEXT\n";
    }
    VkResult result = device_dispatch_table(device)->CreateShadersEXT(device, createInfoCount, pCreateInfos, pAllocator, pShaders);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkDestroyShaderEXT(VkDevice device, VkShaderEXT shader, const VkAllocationCallbacks* pAllocator) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkDestroyShaderEXT\n";
    }
    device_dispatch_table(device)->DestroyShaderEXT(device, shader, pAllocator);
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkGetShaderBinaryDataEXT(VkDevice device, VkShaderEXT shader, size_t* pDataSize, void* pData) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetShaderBinaryDataEXT\n";
    }
    VkResult result = device_dispatch_table(device)->GetShaderBinaryDataEXT(device, shader, pDataSize, pData);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdBindShadersEXT(VkCommandBuffer commandBuffer, uint32_t stageCount, const VkShaderStageFlagBits* pStages, const VkShaderEXT* pShaders) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdBindShadersEXT\n";
    }
    device_dispatch_table(commandBuffer)->CmdBindShadersEXT(commandBuffer, stageCount, pStages, pShaders);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdSetDepthClampRangeEXT(VkCommandBuffer commandBuffer, VkDepthClampModeEXT depthClampMode, const VkDepthClampRangeEXT* pDepthClampRange) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdSetDepthClampRangeEXT\n";
    }
    device_dispatch_table(commandBuffer)->CmdSetDepthClampRangeEXT(commandBuffer, depthClampMode, pDepthClampRange);
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkGetFramebufferTilePropertiesQCOM(VkDevice device, VkFramebuffer framebuffer, uint32_t* pPropertiesCount, VkTilePropertiesQCOM* pProperties) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetFramebufferTilePropertiesQCOM\n";
    }
    VkResult result = device_dispatch_table(device)->GetFramebufferTilePropertiesQCOM(device, framebuffer, pPropertiesCount, pProperties);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkGetDynamicRenderingTilePropertiesQCOM(VkDevice device, const VkRenderingInfo* pRenderingInfo, VkTilePropertiesQCOM* pProperties) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetDynamicRenderingTilePropertiesQCOM\n";
    }
    VkResult result = device_dispatch_table(device)->GetDynamicRenderingTilePropertiesQCOM(device, pRenderingInfo, pProperties);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkConvertCooperativeVectorMatrixNV(VkDevice device, const VkConvertCooperativeVectorMatrixInfoNV* pInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkConvertCooperativeVectorMatrixNV\n";
    }
    VkResult result = device_dispatch_table(device)->ConvertCooperativeVectorMatrixNV(device, pInfo);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdConvertCooperativeVectorMatrixNV(VkCommandBuffer commandBuffer, uint32_t infoCount, const VkConvertCooperativeVectorMatrixInfoNV* pInfos) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdConvertCooperativeVectorMatrixNV\n";
    }
    device_dispatch_table(commandBuffer)->CmdConvertCooperativeVectorMatrixNV(commandBuffer, infoCount, pInfos);
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkSetLatencySleepModeNV(VkDevice device, VkSwapchainKHR swapchain, const VkLatencySleepModeInfoNV* pSleepModeInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkSetLatencySleepModeNV\n";
    }
    VkResult result = device_dispatch_table(device)->SetLatencySleepModeNV(device, swapchain, pSleepModeInfo);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkLatencySleepNV(VkDevice device, VkSwapchainKHR swapchain, const VkLatencySleepInfoNV* pSleepInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkLatencySleepNV\n";
    }
    VkResult result = device_dispatch_table(device)->LatencySleepNV(device, swapchain, pSleepInfo);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkSetLatencyMarkerNV(VkDevice device, VkSwapchainKHR swapchain, const VkSetLatencyMarkerInfoNV* pLatencyMarkerInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkSetLatencyMarkerNV\n";
    }
    device_dispatch_table(device)->SetLatencyMarkerNV(device, swapchain, pLatencyMarkerInfo);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkGetLatencyTimingsNV(VkDevice device, VkSwapchainKHR swapchain, VkGetLatencyMarkerInfoNV* pLatencyMarkerInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetLatencyTimingsNV\n";
    }
    device_dispatch_table(device)->GetLatencyTimingsNV(device, swapchain, pLatencyMarkerInfo);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkQueueNotifyOutOfBandNV(VkQueue queue, const VkOutOfBandQueueTypeInfoNV* pQueueTypeInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkQueueNotifyOutOfBandNV\n";
    }
    device_dispatch_table(queue)->QueueNotifyOutOfBandNV(queue, pQueueTypeInfo);
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkCreateDataGraphPipelinesARM(VkDevice device, VkDeferredOperationKHR deferredOperation, VkPipelineCache pipelineCache, uint32_t createInfoCount, const VkDataGraphPipelineCreateInfoARM* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCreateDataGraphPipelinesARM\n";
    }
    VkResult result = device_dispatch_table(device)->CreateDataGraphPipelinesARM(device, deferredOperation, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkCreateDataGraphPipelineSessionARM(VkDevice device, const VkDataGraphPipelineSessionCreateInfoARM* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDataGraphPipelineSessionARM* pSession) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCreateDataGraphPipelineSessionARM\n";
    }
    VkResult result = device_dispatch_table(device)->CreateDataGraphPipelineSessionARM(device, pCreateInfo, pAllocator, pSession);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkGetDataGraphPipelineSessionBindPointRequirementsARM(VkDevice device, const VkDataGraphPipelineSessionBindPointRequirementsInfoARM* pInfo, uint32_t* pBindPointRequirementCount, VkDataGraphPipelineSessionBindPointRequirementARM* pBindPointRequirements) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetDataGraphPipelineSessionBindPointRequirementsARM\n";
    }
    VkResult result = device_dispatch_table(device)->GetDataGraphPipelineSessionBindPointRequirementsARM(device, pInfo, pBindPointRequirementCount, pBindPointRequirements);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkGetDataGraphPipelineSessionMemoryRequirementsARM(VkDevice device, const VkDataGraphPipelineSessionMemoryRequirementsInfoARM* pInfo, VkMemoryRequirements2* pMemoryRequirements) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetDataGraphPipelineSessionMemoryRequirementsARM\n";
    }
    device_dispatch_table(device)->GetDataGraphPipelineSessionMemoryRequirementsARM(device, pInfo, pMemoryRequirements);
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkBindDataGraphPipelineSessionMemoryARM(VkDevice device, uint32_t bindInfoCount, const VkBindDataGraphPipelineSessionMemoryInfoARM* pBindInfos) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkBindDataGraphPipelineSessionMemoryARM\n";
    }
    VkResult result = device_dispatch_table(device)->BindDataGraphPipelineSessionMemoryARM(device, bindInfoCount, pBindInfos);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkDestroyDataGraphPipelineSessionARM(VkDevice device, VkDataGraphPipelineSessionARM session, const VkAllocationCallbacks* pAllocator) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkDestroyDataGraphPipelineSessionARM\n";
    }
    device_dispatch_table(device)->DestroyDataGraphPipelineSessionARM(device, session, pAllocator);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdDispatchDataGraphARM(VkCommandBuffer commandBuffer, VkDataGraphPipelineSessionARM session, const VkDataGraphPipelineDispatchInfoARM* pInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdDispatchDataGraphARM\n";
    }
    device_dispatch_table(commandBuffer)->CmdDispatchDataGraphARM(commandBuffer, session, pInfo);
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkGetDataGraphPipelineAvailablePropertiesARM(VkDevice device, const VkDataGraphPipelineInfoARM* pPipelineInfo, uint32_t* pPropertiesCount, VkDataGraphPipelinePropertyARM* pProperties) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetDataGraphPipelineAvailablePropertiesARM\n";
    }
    VkResult result = device_dispatch_table(device)->GetDataGraphPipelineAvailablePropertiesARM(device, pPipelineInfo, pPropertiesCount, pProperties);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkGetDataGraphPipelinePropertiesARM(VkDevice device, const VkDataGraphPipelineInfoARM* pPipelineInfo, uint32_t propertiesCount, VkDataGraphPipelinePropertyQueryResultARM* pProperties) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetDataGraphPipelinePropertiesARM\n";
    }
    VkResult result = device_dispatch_table(device)->GetDataGraphPipelinePropertiesARM(device, pPipelineInfo, propertiesCount, pProperties);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdSetAttachmentFeedbackLoopEnableEXT(VkCommandBuffer commandBuffer, VkImageAspectFlags aspectMask) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdSetAttachmentFeedbackLoopEnableEXT\n";
    }
    device_dispatch_table(commandBuffer)->CmdSetAttachmentFeedbackLoopEnableEXT(commandBuffer, aspectMask);
}
#if defined(VK_USE_PLATFORM_SCREEN_QNX)
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkGetScreenBufferPropertiesQNX(VkDevice device, const struct _screen_buffer* buffer, VkScreenBufferPropertiesQNX* pProperties) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetScreenBufferPropertiesQNX\n";
    }
    VkResult result = device_dispatch_table(device)->GetScreenBufferPropertiesQNX(device, buffer, pProperties);
    return result;
}
#endif  // VK_USE_PLATFORM_SCREEN_QNX
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdBindTileMemoryQCOM(VkCommandBuffer commandBuffer, const VkTileMemoryBindInfoQCOM* pTileMemoryBindInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdBindTileMemoryQCOM\n";
    }
    device_dispatch_table(commandBuffer)->CmdBindTileMemoryQCOM(commandBuffer, pTileMemoryBindInfo);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdDecompressMemoryEXT(VkCommandBuffer commandBuffer, const VkDecompressMemoryInfoEXT* pDecompressMemoryInfoEXT) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdDecompressMemoryEXT\n";
    }
    device_dispatch_table(commandBuffer)->CmdDecompressMemoryEXT(commandBuffer, pDecompressMemoryInfoEXT);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdDecompressMemoryIndirectCountEXT(VkCommandBuffer commandBuffer, VkMemoryDecompressionMethodFlagsEXT decompressionMethod, VkDeviceAddress indirectCommandsAddress, VkDeviceAddress indirectCommandsCountAddress, uint32_t maxDecompressionCount, uint32_t stride) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdDecompressMemoryIndirectCountEXT\n";
    }
    device_dispatch_table(commandBuffer)->CmdDecompressMemoryIndirectCountEXT(commandBuffer, decompressionMethod, indirectCommandsAddress, indirectCommandsCountAddress, maxDecompressionCount, stride);
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkCreateExternalComputeQueueNV(VkDevice device, const VkExternalComputeQueueCreateInfoNV* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkExternalComputeQueueNV* pExternalQueue) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCreateExternalComputeQueueNV\n";
    }
    VkResult result = device_dispatch_table(device)->CreateExternalComputeQueueNV(device, pCreateInfo, pAllocator, pExternalQueue);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkDestroyExternalComputeQueueNV(VkDevice device, VkExternalComputeQueueNV externalQueue, const VkAllocationCallbacks* pAllocator) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkDestroyExternalComputeQueueNV\n";
    }
    device_dispatch_table(device)->DestroyExternalComputeQueueNV(device, externalQueue, pAllocator);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkGetExternalComputeQueueDataNV(VkExternalComputeQueueNV externalQueue, VkExternalComputeQueueDataParamsNV* params, void* pData) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetExternalComputeQueueDataNV\n";
    }
    device_dispatch_table(externalQueue)->GetExternalComputeQueueDataNV(externalQueue, params, pData);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkGetClusterAccelerationStructureBuildSizesNV(VkDevice device, const VkClusterAccelerationStructureInputInfoNV* pInfo, VkAccelerationStructureBuildSizesInfoKHR* pSizeInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetClusterAccelerationStructureBuildSizesNV\n";
    }
    device_dispatch_table(device)->GetClusterAccelerationStructureBuildSizesNV(device, pInfo, pSizeInfo);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdBuildClusterAccelerationStructureIndirectNV(VkCommandBuffer commandBuffer, const VkClusterAccelerationStructureCommandsInfoNV* pCommandInfos) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdBuildClusterAccelerationStructureIndirectNV\n";
    }
    device_dispatch_table(commandBuffer)->CmdBuildClusterAccelerationStructureIndirectNV(commandBuffer, pCommandInfos);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkGetPartitionedAccelerationStructuresBuildSizesNV(VkDevice device, const VkPartitionedAccelerationStructureInstancesInputNV* pInfo, VkAccelerationStructureBuildSizesInfoKHR* pSizeInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetPartitionedAccelerationStructuresBuildSizesNV\n";
    }
    device_dispatch_table(device)->GetPartitionedAccelerationStructuresBuildSizesNV(device, pInfo, pSizeInfo);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdBuildPartitionedAccelerationStructuresNV(VkCommandBuffer commandBuffer, const VkBuildPartitionedAccelerationStructureInfoNV* pBuildInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdBuildPartitionedAccelerationStructuresNV\n";
    }
    device_dispatch_table(commandBuffer)->CmdBuildPartitionedAccelerationStructuresNV(commandBuffer, pBuildInfo);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkGetGeneratedCommandsMemoryRequirementsEXT(VkDevice device, const VkGeneratedCommandsMemoryRequirementsInfoEXT* pInfo, VkMemoryRequirements2* pMemoryRequirements) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetGeneratedCommandsMemoryRequirementsEXT\n";
    }
    device_dispatch_table(device)->GetGeneratedCommandsMemoryRequirementsEXT(device, pInfo, pMemoryRequirements);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdPreprocessGeneratedCommandsEXT(VkCommandBuffer commandBuffer, const VkGeneratedCommandsInfoEXT* pGeneratedCommandsInfo, VkCommandBuffer stateCommandBuffer) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdPreprocessGeneratedCommandsEXT\n";
    }
    device_dispatch_table(commandBuffer)->CmdPreprocessGeneratedCommandsEXT(commandBuffer, pGeneratedCommandsInfo, stateCommandBuffer);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdExecuteGeneratedCommandsEXT(VkCommandBuffer commandBuffer, VkBool32 isPreprocessed, const VkGeneratedCommandsInfoEXT* pGeneratedCommandsInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdExecuteGeneratedCommandsEXT\n";
    }
    device_dispatch_table(commandBuffer)->CmdExecuteGeneratedCommandsEXT(commandBuffer, isPreprocessed, pGeneratedCommandsInfo);
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkCreateIndirectCommandsLayoutEXT(VkDevice device, const VkIndirectCommandsLayoutCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkIndirectCommandsLayoutEXT* pIndirectCommandsLayout) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCreateIndirectCommandsLayoutEXT\n";
    }
    VkResult result = device_dispatch_table(device)->CreateIndirectCommandsLayoutEXT(device, pCreateInfo, pAllocator, pIndirectCommandsLayout);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkDestroyIndirectCommandsLayoutEXT(VkDevice device, VkIndirectCommandsLayoutEXT indirectCommandsLayout, const VkAllocationCallbacks* pAllocator) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkDestroyIndirectCommandsLayoutEXT\n";
    }
    device_dispatch_table(device)->DestroyIndirectCommandsLayoutEXT(device, indirectCommandsLayout, pAllocator);
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkCreateIndirectExecutionSetEXT(VkDevice device, const VkIndirectExecutionSetCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkIndirectExecutionSetEXT* pIndirectExecutionSet) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCreateIndirectExecutionSetEXT\n";
    }
    VkResult result = device_dispatch_table(device)->CreateIndirectExecutionSetEXT(device, pCreateInfo, pAllocator, pIndirectExecutionSet);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkDestroyIndirectExecutionSetEXT(VkDevice device, VkIndirectExecutionSetEXT indirectExecutionSet, const VkAllocationCallbacks* pAllocator) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkDestroyIndirectExecutionSetEXT\n";
    }
    device_dispatch_table(device)->DestroyIndirectExecutionSetEXT(device, indirectExecutionSet, pAllocator);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkUpdateIndirectExecutionSetPipelineEXT(VkDevice device, VkIndirectExecutionSetEXT indirectExecutionSet, uint32_t executionSetWriteCount, const VkWriteIndirectExecutionSetPipelineEXT* pExecutionSetWrites) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkUpdateIndirectExecutionSetPipelineEXT\n";
    }
    device_dispatch_table(device)->UpdateIndirectExecutionSetPipelineEXT(device, indirectExecutionSet, executionSetWriteCount, pExecutionSetWrites);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkUpdateIndirectExecutionSetShaderEXT(VkDevice device, VkIndirectExecutionSetEXT indirectExecutionSet, uint32_t executionSetWriteCount, const VkWriteIndirectExecutionSetShaderEXT* pExecutionSetWrites) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkUpdateIndirectExecutionSetShaderEXT\n";
    }
    device_dispatch_table(device)->UpdateIndirectExecutionSetShaderEXT(device, indirectExecutionSet, executionSetWriteCount, pExecutionSetWrites);
}
#if defined(VK_USE_PLATFORM_METAL_EXT)
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkGetMemoryMetalHandleEXT(VkDevice device, const VkMemoryGetMetalHandleInfoEXT* pGetMetalHandleInfo, void** pHandle) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetMemoryMetalHandleEXT\n";
    }
    VkResult result = device_dispatch_table(device)->GetMemoryMetalHandleEXT(device, pGetMetalHandleInfo, pHandle);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkGetMemoryMetalHandlePropertiesEXT(VkDevice device, VkExternalMemoryHandleTypeFlagBits handleType, const void* pHandle, VkMemoryMetalHandlePropertiesEXT* pMemoryMetalHandleProperties) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetMemoryMetalHandlePropertiesEXT\n";
    }
    VkResult result = device_dispatch_table(device)->GetMemoryMetalHandlePropertiesEXT(device, handleType, pHandle, pMemoryMetalHandleProperties);
    return result;
}
#endif  // VK_USE_PLATFORM_METAL_EXT
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdEndRendering2EXT(VkCommandBuffer commandBuffer, const VkRenderingEndInfoKHR* pRenderingEndInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdEndRendering2EXT\n";
    }
    device_dispatch_table(commandBuffer)->CmdEndRendering2EXT(commandBuffer, pRenderingEndInfo);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdBeginCustomResolveEXT(VkCommandBuffer commandBuffer, const VkBeginCustomResolveInfoEXT* pBeginCustomResolveInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdBeginCustomResolveEXT\n";
    }
    device_dispatch_table(commandBuffer)->CmdBeginCustomResolveEXT(commandBuffer, pBeginCustomResolveInfo);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdSetComputeOccupancyPriorityNV(VkCommandBuffer commandBuffer, const VkComputeOccupancyPriorityParametersNV* pParameters) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdSetComputeOccupancyPriorityNV\n";
    }
    device_dispatch_table(commandBuffer)->CmdSetComputeOccupancyPriorityNV(commandBuffer, pParameters);
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkCreateAccelerationStructureKHR(VkDevice device, const VkAccelerationStructureCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkAccelerationStructureKHR* pAccelerationStructure) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCreateAccelerationStructureKHR\n";
    }
    VkResult result = device_dispatch_table(device)->CreateAccelerationStructureKHR(device, pCreateInfo, pAllocator, pAccelerationStructure);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkDestroyAccelerationStructureKHR(VkDevice device, VkAccelerationStructureKHR accelerationStructure, const VkAllocationCallbacks* pAllocator) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkDestroyAccelerationStructureKHR\n";
    }
    device_dispatch_table(device)->DestroyAccelerationStructureKHR(device, accelerationStructure, pAllocator);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdBuildAccelerationStructuresKHR(VkCommandBuffer commandBuffer, uint32_t infoCount, const VkAccelerationStructureBuildGeometryInfoKHR* pInfos, const VkAccelerationStructureBuildRangeInfoKHR* const* ppBuildRangeInfos) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdBuildAccelerationStructuresKHR\n";
    }
    device_dispatch_table(commandBuffer)->CmdBuildAccelerationStructuresKHR(commandBuffer, infoCount, pInfos, ppBuildRangeInfos);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdBuildAccelerationStructuresIndirectKHR(VkCommandBuffer commandBuffer, uint32_t infoCount, const VkAccelerationStructureBuildGeometryInfoKHR* pInfos, const VkDeviceAddress* pIndirectDeviceAddresses, const uint32_t* pIndirectStrides, const uint32_t* const* ppMaxPrimitiveCounts) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdBuildAccelerationStructuresIndirectKHR\n";
    }
    device_dispatch_table(commandBuffer)->CmdBuildAccelerationStructuresIndirectKHR(commandBuffer, infoCount, pInfos, pIndirectDeviceAddresses, pIndirectStrides, ppMaxPrimitiveCounts);
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkBuildAccelerationStructuresKHR(VkDevice device, VkDeferredOperationKHR deferredOperation, uint32_t infoCount, const VkAccelerationStructureBuildGeometryInfoKHR* pInfos, const VkAccelerationStructureBuildRangeInfoKHR* const* ppBuildRangeInfos) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkBuildAccelerationStructuresKHR\n";
    }
    VkResult result = device_dispatch_table(device)->BuildAccelerationStructuresKHR(device, deferredOperation, infoCount, pInfos, ppBuildRangeInfos);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkCopyAccelerationStructureKHR(VkDevice device, VkDeferredOperationKHR deferredOperation, const VkCopyAccelerationStructureInfoKHR* pInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCopyAccelerationStructureKHR\n";
    }
    VkResult result = device_dispatch_table(device)->CopyAccelerationStructureKHR(device, deferredOperation, pInfo);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkCopyAccelerationStructureToMemoryKHR(VkDevice device, VkDeferredOperationKHR deferredOperation, const VkCopyAccelerationStructureToMemoryInfoKHR* pInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCopyAccelerationStructureToMemoryKHR\n";
    }
    VkResult result = device_dispatch_table(device)->CopyAccelerationStructureToMemoryKHR(device, deferredOperation, pInfo);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkCopyMemoryToAccelerationStructureKHR(VkDevice device, VkDeferredOperationKHR deferredOperation, const VkCopyMemoryToAccelerationStructureInfoKHR* pInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCopyMemoryToAccelerationStructureKHR\n";
    }
    VkResult result = device_dispatch_table(device)->CopyMemoryToAccelerationStructureKHR(device, deferredOperation, pInfo);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkWriteAccelerationStructuresPropertiesKHR(VkDevice device, uint32_t accelerationStructureCount, const VkAccelerationStructureKHR* pAccelerationStructures, VkQueryType queryType, size_t dataSize, void* pData, size_t stride) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkWriteAccelerationStructuresPropertiesKHR\n";
    }
    VkResult result = device_dispatch_table(device)->WriteAccelerationStructuresPropertiesKHR(device, accelerationStructureCount, pAccelerationStructures, queryType, dataSize, pData, stride);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdCopyAccelerationStructureKHR(VkCommandBuffer commandBuffer, const VkCopyAccelerationStructureInfoKHR* pInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdCopyAccelerationStructureKHR\n";
    }
    device_dispatch_table(commandBuffer)->CmdCopyAccelerationStructureKHR(commandBuffer, pInfo);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdCopyAccelerationStructureToMemoryKHR(VkCommandBuffer commandBuffer, const VkCopyAccelerationStructureToMemoryInfoKHR* pInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdCopyAccelerationStructureToMemoryKHR\n";
    }
    device_dispatch_table(commandBuffer)->CmdCopyAccelerationStructureToMemoryKHR(commandBuffer, pInfo);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdCopyMemoryToAccelerationStructureKHR(VkCommandBuffer commandBuffer, const VkCopyMemoryToAccelerationStructureInfoKHR* pInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdCopyMemoryToAccelerationStructureKHR\n";
    }
    device_dispatch_table(commandBuffer)->CmdCopyMemoryToAccelerationStructureKHR(commandBuffer, pInfo);
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkDeviceAddress VKAPI_CALL vkGetAccelerationStructureDeviceAddressKHR(VkDevice device, const VkAccelerationStructureDeviceAddressInfoKHR* pInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetAccelerationStructureDeviceAddressKHR\n";
    }
    VkDeviceAddress result = device_dispatch_table(device)->GetAccelerationStructureDeviceAddressKHR(device, pInfo);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdWriteAccelerationStructuresPropertiesKHR(VkCommandBuffer commandBuffer, uint32_t accelerationStructureCount, const VkAccelerationStructureKHR* pAccelerationStructures, VkQueryType queryType, VkQueryPool queryPool, uint32_t firstQuery) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdWriteAccelerationStructuresPropertiesKHR\n";
    }
    device_dispatch_table(commandBuffer)->CmdWriteAccelerationStructuresPropertiesKHR(commandBuffer, accelerationStructureCount, pAccelerationStructures, queryType, queryPool, firstQuery);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkGetDeviceAccelerationStructureCompatibilityKHR(VkDevice device, const VkAccelerationStructureVersionInfoKHR* pVersionInfo, VkAccelerationStructureCompatibilityKHR* pCompatibility) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetDeviceAccelerationStructureCompatibilityKHR\n";
    }
    device_dispatch_table(device)->GetDeviceAccelerationStructureCompatibilityKHR(device, pVersionInfo, pCompatibility);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkGetAccelerationStructureBuildSizesKHR(VkDevice device, VkAccelerationStructureBuildTypeKHR buildType, const VkAccelerationStructureBuildGeometryInfoKHR* pBuildInfo, const uint32_t* pMaxPrimitiveCounts, VkAccelerationStructureBuildSizesInfoKHR* pSizeInfo) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetAccelerationStructureBuildSizesKHR\n";
    }
    device_dispatch_table(device)->GetAccelerationStructureBuildSizesKHR(device, buildType, pBuildInfo, pMaxPrimitiveCounts, pSizeInfo);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdTraceRaysKHR(VkCommandBuffer commandBuffer, const VkStridedDeviceAddressRegionKHR* pRaygenShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pMissShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pHitShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pCallableShaderBindingTable, uint32_t width, uint32_t height, uint32_t depth) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdTraceRaysKHR\n";
    }
    device_dispatch_table(commandBuffer)->CmdTraceRaysKHR(commandBuffer, pRaygenShaderBindingTable, pMissShaderBindingTable, pHitShaderBindingTable, pCallableShaderBindingTable, width, height, depth);
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkCreateRayTracingPipelinesKHR(VkDevice device, VkDeferredOperationKHR deferredOperation, VkPipelineCache pipelineCache, uint32_t createInfoCount, const VkRayTracingPipelineCreateInfoKHR* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCreateRayTracingPipelinesKHR\n";
    }
    VkResult result = device_dispatch_table(device)->CreateRayTracingPipelinesKHR(device, deferredOperation, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkResult VKAPI_CALL vkGetRayTracingCaptureReplayShaderGroupHandlesKHR(VkDevice device, VkPipeline pipeline, uint32_t firstGroup, uint32_t groupCount, size_t dataSize, void* pData) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetRayTracingCaptureReplayShaderGroupHandlesKHR\n";
    }
    VkResult result = device_dispatch_table(device)->GetRayTracingCaptureReplayShaderGroupHandlesKHR(device, pipeline, firstGroup, groupCount, dataSize, pData);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdTraceRaysIndirectKHR(VkCommandBuffer commandBuffer, const VkStridedDeviceAddressRegionKHR* pRaygenShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pMissShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pHitShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pCallableShaderBindingTable, VkDeviceAddress indirectDeviceAddress) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdTraceRaysIndirectKHR\n";
    }
    device_dispatch_table(commandBuffer)->CmdTraceRaysIndirectKHR(commandBuffer, pRaygenShaderBindingTable, pMissShaderBindingTable, pHitShaderBindingTable, pCallableShaderBindingTable, indirectDeviceAddress);
}
template <ApiDumpFormat Format>
VKAPI_ATTR VkDeviceSize VKAPI_CALL vkGetRayTracingShaderGroupStackSizeKHR(VkDevice device, VkPipeline pipeline, uint32_t group, VkShaderGroupShaderKHR groupShader) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkGetRayTracingShaderGroupStackSizeKHR\n";
    }
    VkDeviceSize result = device_dispatch_table(device)->GetRayTracingShaderGroupStackSizeKHR(device, pipeline, group, groupShader);
    return result;
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdSetRayTracingPipelineStackSizeKHR(VkCommandBuffer commandBuffer, uint32_t pipelineStackSize) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdSetRayTracingPipelineStackSizeKHR\n";
    }
    device_dispatch_table(commandBuffer)->CmdSetRayTracingPipelineStackSizeKHR(commandBuffer, pipelineStackSize);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdDrawMeshTasksEXT(VkCommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdDrawMeshTasksEXT\n";
    }
    device_dispatch_table(commandBuffer)->CmdDrawMeshTasksEXT(commandBuffer, groupCountX, groupCountY, groupCountZ);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdDrawMeshTasksIndirectEXT(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdDrawMeshTasksIndirectEXT\n";
    }
    device_dispatch_table(commandBuffer)->CmdDrawMeshTasksIndirectEXT(commandBuffer, buffer, offset, drawCount, stride);
}
template <ApiDumpFormat Format>
VKAPI_ATTR void VKAPI_CALL vkCmdDrawMeshTasksIndirectCountEXT(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) {
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());

    if (ApiDumpInstance::current().shouldDumpOutput()) {
        ApiDumpInstance::current().settings().stream() << "vkCmdDrawMeshTasksIndirectCountEXT\n";
    }
    device_dispatch_table(commandBuffer)->CmdDrawMeshTasksIndirectCountEXT(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
}

template <ApiDumpFormat Format>
VKAPI_ATTR PFN_vkVoidFunction VKAPI_CALL api_dump_known_instance_functions(VkInstance instance, const char* pName) {
    if (strcmp(pName, "vkCreateInstance") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateInstance);
    if (strcmp(pName, "vkDestroyInstance") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyInstance<Format>);
    if (strcmp(pName, "vkEnumeratePhysicalDevices") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkEnumeratePhysicalDevices<Format>);
    if (strcmp(pName, "vkGetPhysicalDeviceFeatures") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceFeatures<Format>);
    if (strcmp(pName, "vkGetPhysicalDeviceFormatProperties") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceFormatProperties<Format>);
    if (strcmp(pName, "vkGetPhysicalDeviceImageFormatProperties") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceImageFormatProperties<Format>);
    if (strcmp(pName, "vkGetPhysicalDeviceProperties") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceProperties<Format>);
    if (strcmp(pName, "vkGetPhysicalDeviceQueueFamilyProperties") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceQueueFamilyProperties<Format>);
    if (strcmp(pName, "vkGetPhysicalDeviceMemoryProperties") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceMemoryProperties<Format>);
    if (strcmp(pName, "vkGetInstanceProcAddr") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetInstanceProcAddr);
    if (strcmp(pName, "vkCreateDevice") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateDevice<Format>);
    if (strcmp(pName, "vkEnumerateInstanceExtensionProperties") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkEnumerateInstanceExtensionProperties);
    if (strcmp(pName, "vkEnumerateInstanceLayerProperties") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkEnumerateInstanceLayerProperties);
    if (strcmp(pName, "vkEnumerateDeviceLayerProperties") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkEnumerateDeviceLayerProperties);
    if (strcmp(pName, "vkGetPhysicalDeviceSparseImageFormatProperties") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceSparseImageFormatProperties<Format>);
    if (strcmp(pName, "vkEnumeratePhysicalDeviceGroups") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkEnumeratePhysicalDeviceGroups<Format>);
    if (strcmp(pName, "vkGetPhysicalDeviceFeatures2") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceFeatures2<Format>);
    if (strcmp(pName, "vkGetPhysicalDeviceProperties2") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceProperties2<Format>);
    if (strcmp(pName, "vkGetPhysicalDeviceFormatProperties2") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceFormatProperties2<Format>);
    if (strcmp(pName, "vkGetPhysicalDeviceImageFormatProperties2") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceImageFormatProperties2<Format>);
    if (strcmp(pName, "vkGetPhysicalDeviceQueueFamilyProperties2") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceQueueFamilyProperties2<Format>);
    if (strcmp(pName, "vkGetPhysicalDeviceMemoryProperties2") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceMemoryProperties2<Format>);
    if (strcmp(pName, "vkGetPhysicalDeviceSparseImageFormatProperties2") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceSparseImageFormatProperties2<Format>);
    if (strcmp(pName, "vkGetPhysicalDeviceExternalBufferProperties") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceExternalBufferProperties<Format>);
    if (strcmp(pName, "vkGetPhysicalDeviceExternalFenceProperties") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceExternalFenceProperties<Format>);
    if (strcmp(pName, "vkGetPhysicalDeviceExternalSemaphoreProperties") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceExternalSemaphoreProperties<Format>);
    if (strcmp(pName, "vkGetPhysicalDeviceToolProperties") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceToolProperties<Format>);
    if (strcmp(pName, "vkDestroySurfaceKHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroySurfaceKHR<Format>);
    if (strcmp(pName, "vkGetPhysicalDeviceSurfaceSupportKHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceSurfaceSupportKHR<Format>);
    if (strcmp(pName, "vkGetPhysicalDeviceSurfaceCapabilitiesKHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceSurfaceCapabilitiesKHR<Format>);
    if (strcmp(pName, "vkGetPhysicalDeviceSurfaceFormatsKHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceSurfaceFormatsKHR<Format>);
    if (strcmp(pName, "vkGetPhysicalDeviceSurfacePresentModesKHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceSurfacePresentModesKHR<Format>);
    if (strcmp(pName, "vkGetPhysicalDevicePresentRectanglesKHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDevicePresentRectanglesKHR<Format>);
    if (strcmp(pName, "vkGetPhysicalDeviceDisplayPropertiesKHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceDisplayPropertiesKHR<Format>);
    if (strcmp(pName, "vkGetPhysicalDeviceDisplayPlanePropertiesKHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceDisplayPlanePropertiesKHR<Format>);
    if (strcmp(pName, "vkGetDisplayPlaneSupportedDisplaysKHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetDisplayPlaneSupportedDisplaysKHR<Format>);
    if (strcmp(pName, "vkGetDisplayModePropertiesKHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetDisplayModePropertiesKHR<Format>);
    if (strcmp(pName, "vkCreateDisplayModeKHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateDisplayModeKHR<Format>);
    if (strcmp(pName, "vkGetDisplayPlaneCapabilitiesKHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetDisplayPlaneCapabilitiesKHR<Format>);
    if (strcmp(pName, "vkCreateDisplayPlaneSurfaceKHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateDisplayPlaneSurfaceKHR<Format>);
#if defined(VK_USE_PLATFORM_XLIB_KHR)
    if (strcmp(pName, "vkCreateXlibSurfaceKHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateXlibSurfaceKHR<Format>);
    if (strcmp(pName, "vkGetPhysicalDeviceXlibPresentationSupportKHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceXlibPresentationSupportKHR<Format>);
#endif  // VK_USE_PLATFORM_XLIB_KHR
#if defined(VK_USE_PLATFORM_XCB_KHR)
    if (strcmp(pName, "vkCreateXcbSurfaceKHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateXcbSurfaceKHR<Format>);
    if (strcmp(pName, "vkGetPhysicalDeviceXcbPresentationSupportKHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceXcbPresentationSupportKHR<Format>);
#endif  // VK_USE_PLATFORM_XCB_KHR
#if defined(VK_USE_PLATFORM_WAYLAND_KHR)
    if (strcmp(pName, "vkCreateWaylandSurfaceKHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateWaylandSurfaceKHR<Format>);
    if (strcmp(pName, "vkGetPhysicalDeviceWaylandPresentationSupportKHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceWaylandPresentationSupportKHR<Format>);
#endif  // VK_USE_PLATFORM_WAYLAND_KHR
#if defined(VK_USE_PLATFORM_ANDROID_KHR)
    if (strcmp(pName, "vkCreateAndroidSurfaceKHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateAndroidSurfaceKHR<Format>);
#endif  // VK_USE_PLATFORM_ANDROID_KHR
#if defined(VK_USE_PLATFORM_WIN32_KHR)
    if (strcmp(pName, "vkCreateWin32SurfaceKHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateWin32SurfaceKHR<Format>);
    if (strcmp(pName, "vkGetPhysicalDeviceWin32PresentationSupportKHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceWin32PresentationSupportKHR<Format>);
#endif  // VK_USE_PLATFORM_WIN32_KHR
    if (strcmp(pName, "vkGetPhysicalDeviceVideoCapabilitiesKHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceVideoCapabilitiesKHR<Format>);
    if (strcmp(pName, "vkGetPhysicalDeviceVideoFormatPropertiesKHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceVideoFormatPropertiesKHR<Format>);
    if (strcmp(pName, "vkGetPhysicalDeviceFeatures2KHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceFeatures2KHR<Format>);
    if (strcmp(pName, "vkGetPhysicalDeviceProperties2KHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceProperties2KHR<Format>);
    if (strcmp(pName, "vkGetPhysicalDeviceFormatProperties2KHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceFormatProperties2KHR<Format>);
    if (strcmp(pName, "vkGetPhysicalDeviceImageFormatProperties2KHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceImageFormatProperties2KHR<Format>);
    if (strcmp(pName, "vkGetPhysicalDeviceQueueFamilyProperties2KHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceQueueFamilyProperties2KHR<Format>);
    if (strcmp(pName, "vkGetPhysicalDeviceMemoryProperties2KHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceMemoryProperties2KHR<Format>);
    if (strcmp(pName, "vkGetPhysicalDeviceSparseImageFormatProperties2KHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceSparseImageFormatProperties2KHR<Format>);
    if (strcmp(pName, "vkEnumeratePhysicalDeviceGroupsKHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkEnumeratePhysicalDeviceGroupsKHR<Format>);
    if (strcmp(pName, "vkGetPhysicalDeviceExternalBufferPropertiesKHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceExternalBufferPropertiesKHR<Format>);
    if (strcmp(pName, "vkGetPhysicalDeviceExternalSemaphorePropertiesKHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceExternalSemaphorePropertiesKHR<Format>);
    if (strcmp(pName, "vkGetPhysicalDeviceExternalFencePropertiesKHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceExternalFencePropertiesKHR<Format>);
    if (strcmp(pName, "vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR<Format>);
    if (strcmp(pName, "vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR<Format>);
    if (strcmp(pName, "vkGetPhysicalDeviceSurfaceCapabilities2KHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceSurfaceCapabilities2KHR<Format>);
    if (strcmp(pName, "vkGetPhysicalDeviceSurfaceFormats2KHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceSurfaceFormats2KHR<Format>);
    if (strcmp(pName, "vkGetPhysicalDeviceDisplayProperties2KHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceDisplayProperties2KHR<Format>);
    if (strcmp(pName, "vkGetPhysicalDeviceDisplayPlaneProperties2KHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceDisplayPlaneProperties2KHR<Format>);
    if (strcmp(pName, "vkGetDisplayModeProperties2KHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetDisplayModeProperties2KHR<Format>);
    if (strcmp(pName, "vkGetDisplayPlaneCapabilities2KHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetDisplayPlaneCapabilities2KHR<Format>);
    if (strcmp(pName, "vkGetPhysicalDeviceFragmentShadingRatesKHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceFragmentShadingRatesKHR<Format>);
    if (strcmp(pName, "vkGetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR<Format>);
    if (strcmp(pName, "vkGetPhysicalDeviceCooperativeMatrixPropertiesKHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceCooperativeMatrixPropertiesKHR<Format>);
    if (strcmp(pName, "vkGetPhysicalDeviceCalibrateableTimeDomainsKHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceCalibrateableTimeDomainsKHR<Format>);
    if (strcmp(pName, "vkCreateDebugReportCallbackEXT") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateDebugReportCallbackEXT<Format>);
    if (strcmp(pName, "vkDestroyDebugReportCallbackEXT") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyDebugReportCallbackEXT<Format>);
    if (strcmp(pName, "vkDebugReportMessageEXT") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkDebugReportMessageEXT<Format>);
#if defined(VK_USE_PLATFORM_GGP)
    if (strcmp(pName, "vkCreateStreamDescriptorSurfaceGGP") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateStreamDescriptorSurfaceGGP<Format>);
#endif  // VK_USE_PLATFORM_GGP
    if (strcmp(pName, "vkGetPhysicalDeviceExternalImageFormatPropertiesNV") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceExternalImageFormatPropertiesNV<Format>);
#if defined(VK_USE_PLATFORM_VI_NN)
    if (strcmp(pName, "vkCreateViSurfaceNN") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateViSurfaceNN<Format>);
#endif  // VK_USE_PLATFORM_VI_NN
    if (strcmp(pName, "vkReleaseDisplayEXT") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkReleaseDisplayEXT<Format>);
#if defined(VK_USE_PLATFORM_XLIB_XRANDR_EXT)
    if (strcmp(pName, "vkAcquireXlibDisplayEXT") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkAcquireXlibDisplayEXT<Format>);
    if (strcmp(pName, "vkGetRandROutputDisplayEXT") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetRandROutputDisplayEXT<Format>);
#endif  // VK_USE_PLATFORM_XLIB_XRANDR_EXT
    if (strcmp(pName, "vkGetPhysicalDeviceSurfaceCapabilities2EXT") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceSurfaceCapabilities2EXT<Format>);
#if defined(VK_USE_PLATFORM_IOS_MVK)
    if (strcmp(pName, "vkCreateIOSSurfaceMVK") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateIOSSurfaceMVK<Format>);
#endif  // VK_USE_PLATFORM_IOS_MVK
#if defined(VK_USE_PLATFORM_MACOS_MVK)
    if (strcmp(pName, "vkCreateMacOSSurfaceMVK") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateMacOSSurfaceMVK<Format>);
#endif  // VK_USE_PLATFORM_MACOS_MVK
    if (strcmp(pName, "vkSetDebugUtilsObjectNameEXT") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkSetDebugUtilsObjectNameEXT<Format>);
    if (strcmp(pName, "vkSetDebugUtilsObjectTagEXT") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkSetDebugUtilsObjectTagEXT<Format>);
    if (strcmp(pName, "vkQueueBeginDebugUtilsLabelEXT") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkQueueBeginDebugUtilsLabelEXT<Format>);
    if (strcmp(pName, "vkQueueEndDebugUtilsLabelEXT") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkQueueEndDebugUtilsLabelEXT<Format>);
    if (strcmp(pName, "vkQueueInsertDebugUtilsLabelEXT") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkQueueInsertDebugUtilsLabelEXT<Format>);
    if (strcmp(pName, "vkCmdBeginDebugUtilsLabelEXT") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdBeginDebugUtilsLabelEXT<Format>);
    if (strcmp(pName, "vkCmdEndDebugUtilsLabelEXT") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdEndDebugUtilsLabelEXT<Format>);
    if (strcmp(pName, "vkCmdInsertDebugUtilsLabelEXT") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdInsertDebugUtilsLabelEXT<Format>);
    if (strcmp(pName, "vkCreateDebugUtilsMessengerEXT") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateDebugUtilsMessengerEXT<Format>);
    if (strcmp(pName, "vkDestroyDebugUtilsMessengerEXT") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyDebugUtilsMessengerEXT<Format>);
    if (strcmp(pName, "vkSubmitDebugUtilsMessageEXT") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkSubmitDebugUtilsMessageEXT<Format>);
    if (strcmp(pName, "vkGetPhysicalDeviceDescriptorSizeEXT") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceDescriptorSizeEXT<Format>);
    if (strcmp(pName, "vkGetPhysicalDeviceMultisamplePropertiesEXT") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceMultisamplePropertiesEXT<Format>);
    if (strcmp(pName, "vkGetPhysicalDeviceCalibrateableTimeDomainsEXT") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceCalibrateableTimeDomainsEXT<Format>);
#if defined(VK_USE_PLATFORM_FUCHSIA)
    if (strcmp(pName, "vkCreateImagePipeSurfaceFUCHSIA") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateImagePipeSurfaceFUCHSIA<Format>);
#endif  // VK_USE_PLATFORM_FUCHSIA
#if defined(VK_USE_PLATFORM_METAL_EXT)
    if (strcmp(pName, "vkCreateMetalSurfaceEXT") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateMetalSurfaceEXT<Format>);
#endif  // VK_USE_PLATFORM_METAL_EXT
    if (strcmp(pName, "vkGetPhysicalDeviceToolPropertiesEXT") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceToolPropertiesEXT<Format>);
    if (strcmp(pName, "vkGetPhysicalDeviceCooperativeMatrixPropertiesNV") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceCooperativeMatrixPropertiesNV<Format>);
    if (strcmp(pName, "vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV<Format>);
#if defined(VK_USE_PLATFORM_WIN32_KHR)
    if (strcmp(pName, "vkGetPhysicalDeviceSurfacePresentModes2EXT") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceSurfacePresentModes2EXT<Format>);
#endif  // VK_USE_PLATFORM_WIN32_KHR
    if (strcmp(pName, "vkCreateHeadlessSurfaceEXT") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateHeadlessSurfaceEXT<Format>);
    if (strcmp(pName, "vkAcquireDrmDisplayEXT") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkAcquireDrmDisplayEXT<Format>);
    if (strcmp(pName, "vkGetDrmDisplayEXT") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetDrmDisplayEXT<Format>);
#if defined(VK_USE_PLATFORM_WIN32_KHR)
    if (strcmp(pName, "vkAcquireWinrtDisplayNV") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkAcquireWinrtDisplayNV<Format>);
    if (strcmp(pName, "vkGetWinrtDisplayNV") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetWinrtDisplayNV<Format>);
#endif  // VK_USE_PLATFORM_WIN32_KHR
#if defined(VK_USE_PLATFORM_DIRECTFB_EXT)
    if (strcmp(pName, "vkCreateDirectFBSurfaceEXT") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateDirectFBSurfaceEXT<Format>);
    if (strcmp(pName, "vkGetPhysicalDeviceDirectFBPresentationSupportEXT") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceDirectFBPresentationSupportEXT<Format>);
#endif  // VK_USE_PLATFORM_DIRECTFB_EXT
#if defined(VK_USE_PLATFORM_SCREEN_QNX)
    if (strcmp(pName, "vkCreateScreenSurfaceQNX") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateScreenSurfaceQNX<Format>);
    if (strcmp(pName, "vkGetPhysicalDeviceScreenPresentationSupportQNX") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceScreenPresentationSupportQNX<Format>);
#endif  // VK_USE_PLATFORM_SCREEN_QNX
    if (strcmp(pName, "vkGetPhysicalDeviceExternalTensorPropertiesARM") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceExternalTensorPropertiesARM<Format>);
    if (strcmp(pName, "vkGetPhysicalDeviceOpticalFlowImageFormatsNV") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceOpticalFlowImageFormatsNV<Format>);
    if (strcmp(pName, "vkGetPhysicalDeviceCooperativeVectorPropertiesNV") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceCooperativeVectorPropertiesNV<Format>);
    if (strcmp(pName, "vkGetPhysicalDeviceQueueFamilyDataGraphPropertiesARM") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceQueueFamilyDataGraphPropertiesARM<Format>);
    if (strcmp(pName, "vkGetPhysicalDeviceQueueFamilyDataGraphProcessingEnginePropertiesARM") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceQueueFamilyDataGraphProcessingEnginePropertiesARM<Format>);
#if defined(VK_USE_PLATFORM_OHOS)
    if (strcmp(pName, "vkCreateSurfaceOHOS") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateSurfaceOHOS<Format>);
#endif  // VK_USE_PLATFORM_OHOS
    if (strcmp(pName, "vkGetPhysicalDeviceCooperativeMatrixFlexibleDimensionsPropertiesNV") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceCooperativeMatrixFlexibleDimensionsPropertiesNV<Format>);
    if (strcmp(pName, "vkEnumeratePhysicalDeviceQueueFamilyPerformanceCountersByRegionARM") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkEnumeratePhysicalDeviceQueueFamilyPerformanceCountersByRegionARM<Format>);

    return nullptr;
}

template <ApiDumpFormat Format>
VKAPI_ATTR PFN_vkVoidFunction VKAPI_CALL api_dump_known_device_functions(VkDevice device, const char* pName) {
    if (strcmp(pName, "vkGetDeviceProcAddr") == 0 && (!device || device_dispatch_table(device)->GetDeviceProcAddr))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetDeviceProcAddr);
    if (strcmp(pName, "vkDestroyDevice") == 0 && (!device || device_dispatch_table(device)->DestroyDevice))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyDevice<Format>);
    if (strcmp(pName, "vkGetDeviceQueue") == 0 && (!device || device_dispatch_table(device)->GetDeviceQueue))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetDeviceQueue<Format>);
    if (strcmp(pName, "vkQueueSubmit") == 0 && (!device || device_dispatch_table(device)->QueueSubmit))
        return reinterpret_cast<PFN_vkVoidFunction>(vkQueueSubmit<Format>);
    if (strcmp(pName, "vkQueueWaitIdle") == 0 && (!device || device_dispatch_table(device)->QueueWaitIdle))
        return reinterpret_cast<PFN_vkVoidFunction>(vkQueueWaitIdle<Format>);
    if (strcmp(pName, "vkDeviceWaitIdle") == 0 && (!device || device_dispatch_table(device)->DeviceWaitIdle))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDeviceWaitIdle<Format>);
    if (strcmp(pName, "vkAllocateMemory") == 0 && (!device || device_dispatch_table(device)->AllocateMemory))
        return reinterpret_cast<PFN_vkVoidFunction>(vkAllocateMemory<Format>);
    if (strcmp(pName, "vkFreeMemory") == 0 && (!device || device_dispatch_table(device)->FreeMemory))
        return reinterpret_cast<PFN_vkVoidFunction>(vkFreeMemory<Format>);
    if (strcmp(pName, "vkMapMemory") == 0 && (!device || device_dispatch_table(device)->MapMemory))
        return reinterpret_cast<PFN_vkVoidFunction>(vkMapMemory<Format>);
    if (strcmp(pName, "vkUnmapMemory") == 0 && (!device || device_dispatch_table(device)->UnmapMemory))
        return reinterpret_cast<PFN_vkVoidFunction>(vkUnmapMemory<Format>);
    if (strcmp(pName, "vkFlushMappedMemoryRanges") == 0 && (!device || device_dispatch_table(device)->FlushMappedMemoryRanges))
        return reinterpret_cast<PFN_vkVoidFunction>(vkFlushMappedMemoryRanges<Format>);
    if (strcmp(pName, "vkInvalidateMappedMemoryRanges") == 0 && (!device || device_dispatch_table(device)->InvalidateMappedMemoryRanges))
        return reinterpret_cast<PFN_vkVoidFunction>(vkInvalidateMappedMemoryRanges<Format>);
    if (strcmp(pName, "vkGetDeviceMemoryCommitment") == 0 && (!device || device_dispatch_table(device)->GetDeviceMemoryCommitment))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetDeviceMemoryCommitment<Format>);
    if (strcmp(pName, "vkBindBufferMemory") == 0 && (!device || device_dispatch_table(device)->BindBufferMemory))
        return reinterpret_cast<PFN_vkVoidFunction>(vkBindBufferMemory<Format>);
    if (strcmp(pName, "vkBindImageMemory") == 0 && (!device || device_dispatch_table(device)->BindImageMemory))
        return reinterpret_cast<PFN_vkVoidFunction>(vkBindImageMemory<Format>);
    if (strcmp(pName, "vkGetBufferMemoryRequirements") == 0 && (!device || device_dispatch_table(device)->GetBufferMemoryRequirements))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetBufferMemoryRequirements<Format>);
    if (strcmp(pName, "vkGetImageMemoryRequirements") == 0 && (!device || device_dispatch_table(device)->GetImageMemoryRequirements))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetImageMemoryRequirements<Format>);
    if (strcmp(pName, "vkGetImageSparseMemoryRequirements") == 0 && (!device || device_dispatch_table(device)->GetImageSparseMemoryRequirements))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetImageSparseMemoryRequirements<Format>);
    if (strcmp(pName, "vkQueueBindSparse") == 0 && (!device || device_dispatch_table(device)->QueueBindSparse))
        return reinterpret_cast<PFN_vkVoidFunction>(vkQueueBindSparse<Format>);
    if (strcmp(pName, "vkCreateFence") == 0 && (!device || device_dispatch_table(device)->CreateFence))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateFence<Format>);
    if (strcmp(pName, "vkDestroyFence") == 0 && (!device || device_dispatch_table(device)->DestroyFence))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyFence<Format>);
    if (strcmp(pName, "vkResetFences") == 0 && (!device || device_dispatch_table(device)->ResetFences))
        return reinterpret_cast<PFN_vkVoidFunction>(vkResetFences<Format>);
    if (strcmp(pName, "vkGetFenceStatus") == 0 && (!device || device_dispatch_table(device)->GetFenceStatus))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetFenceStatus<Format>);
    if (strcmp(pName, "vkWaitForFences") == 0 && (!device || device_dispatch_table(device)->WaitForFences))
        return reinterpret_cast<PFN_vkVoidFunction>(vkWaitForFences<Format>);
    if (strcmp(pName, "vkCreateSemaphore") == 0 && (!device || device_dispatch_table(device)->CreateSemaphore))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateSemaphore<Format>);
    if (strcmp(pName, "vkDestroySemaphore") == 0 && (!device || device_dispatch_table(device)->DestroySemaphore))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroySemaphore<Format>);
    if (strcmp(pName, "vkCreateQueryPool") == 0 && (!device || device_dispatch_table(device)->CreateQueryPool))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateQueryPool<Format>);
    if (strcmp(pName, "vkDestroyQueryPool") == 0 && (!device || device_dispatch_table(device)->DestroyQueryPool))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyQueryPool<Format>);
    if (strcmp(pName, "vkGetQueryPoolResults") == 0 && (!device || device_dispatch_table(device)->GetQueryPoolResults))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetQueryPoolResults<Format>);
    if (strcmp(pName, "vkCreateBuffer") == 0 && (!device || device_dispatch_table(device)->CreateBuffer))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateBuffer<Format>);
    if (strcmp(pName, "vkDestroyBuffer") == 0 && (!device || device_dispatch_table(device)->DestroyBuffer))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyBuffer<Format>);
    if (strcmp(pName, "vkCreateImage") == 0 && (!device || device_dispatch_table(device)->CreateImage))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateImage<Format>);
    if (strcmp(pName, "vkDestroyImage") == 0 && (!device || device_dispatch_table(device)->DestroyImage))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyImage<Format>);
    if (strcmp(pName, "vkGetImageSubresourceLayout") == 0 && (!device || device_dispatch_table(device)->GetImageSubresourceLayout))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetImageSubresourceLayout<Format>);
    if (strcmp(pName, "vkCreateImageView") == 0 && (!device || device_dispatch_table(device)->CreateImageView))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateImageView<Format>);
    if (strcmp(pName, "vkDestroyImageView") == 0 && (!device || device_dispatch_table(device)->DestroyImageView))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyImageView<Format>);
    if (strcmp(pName, "vkCreateCommandPool") == 0 && (!device || device_dispatch_table(device)->CreateCommandPool))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateCommandPool<Format>);
    if (strcmp(pName, "vkDestroyCommandPool") == 0 && (!device || device_dispatch_table(device)->DestroyCommandPool))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyCommandPool<Format>);
    if (strcmp(pName, "vkResetCommandPool") == 0 && (!device || device_dispatch_table(device)->ResetCommandPool))
        return reinterpret_cast<PFN_vkVoidFunction>(vkResetCommandPool<Format>);
    if (strcmp(pName, "vkAllocateCommandBuffers") == 0 && (!device || device_dispatch_table(device)->AllocateCommandBuffers))
        return reinterpret_cast<PFN_vkVoidFunction>(vkAllocateCommandBuffers<Format>);
    if (strcmp(pName, "vkFreeCommandBuffers") == 0 && (!device || device_dispatch_table(device)->FreeCommandBuffers))
        return reinterpret_cast<PFN_vkVoidFunction>(vkFreeCommandBuffers<Format>);
    if (strcmp(pName, "vkBeginCommandBuffer") == 0 && (!device || device_dispatch_table(device)->BeginCommandBuffer))
        return reinterpret_cast<PFN_vkVoidFunction>(vkBeginCommandBuffer<Format>);
    if (strcmp(pName, "vkEndCommandBuffer") == 0 && (!device || device_dispatch_table(device)->EndCommandBuffer))
        return reinterpret_cast<PFN_vkVoidFunction>(vkEndCommandBuffer<Format>);
    if (strcmp(pName, "vkResetCommandBuffer") == 0 && (!device || device_dispatch_table(device)->ResetCommandBuffer))
        return reinterpret_cast<PFN_vkVoidFunction>(vkResetCommandBuffer<Format>);
    if (strcmp(pName, "vkCmdCopyBuffer") == 0 && (!device || device_dispatch_table(device)->CmdCopyBuffer))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdCopyBuffer<Format>);
    if (strcmp(pName, "vkCmdCopyImage") == 0 && (!device || device_dispatch_table(device)->CmdCopyImage))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdCopyImage<Format>);
    if (strcmp(pName, "vkCmdCopyBufferToImage") == 0 && (!device || device_dispatch_table(device)->CmdCopyBufferToImage))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdCopyBufferToImage<Format>);
    if (strcmp(pName, "vkCmdCopyImageToBuffer") == 0 && (!device || device_dispatch_table(device)->CmdCopyImageToBuffer))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdCopyImageToBuffer<Format>);
    if (strcmp(pName, "vkCmdUpdateBuffer") == 0 && (!device || device_dispatch_table(device)->CmdUpdateBuffer))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdUpdateBuffer<Format>);
    if (strcmp(pName, "vkCmdFillBuffer") == 0 && (!device || device_dispatch_table(device)->CmdFillBuffer))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdFillBuffer<Format>);
    if (strcmp(pName, "vkCmdPipelineBarrier") == 0 && (!device || device_dispatch_table(device)->CmdPipelineBarrier))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdPipelineBarrier<Format>);
    if (strcmp(pName, "vkCmdBeginQuery") == 0 && (!device || device_dispatch_table(device)->CmdBeginQuery))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdBeginQuery<Format>);
    if (strcmp(pName, "vkCmdEndQuery") == 0 && (!device || device_dispatch_table(device)->CmdEndQuery))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdEndQuery<Format>);
    if (strcmp(pName, "vkCmdResetQueryPool") == 0 && (!device || device_dispatch_table(device)->CmdResetQueryPool))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdResetQueryPool<Format>);
    if (strcmp(pName, "vkCmdWriteTimestamp") == 0 && (!device || device_dispatch_table(device)->CmdWriteTimestamp))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdWriteTimestamp<Format>);
    if (strcmp(pName, "vkCmdCopyQueryPoolResults") == 0 && (!device || device_dispatch_table(device)->CmdCopyQueryPoolResults))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdCopyQueryPoolResults<Format>);
    if (strcmp(pName, "vkCmdExecuteCommands") == 0 && (!device || device_dispatch_table(device)->CmdExecuteCommands))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdExecuteCommands<Format>);
    if (strcmp(pName, "vkCreateEvent") == 0 && (!device || device_dispatch_table(device)->CreateEvent))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateEvent<Format>);
    if (strcmp(pName, "vkDestroyEvent") == 0 && (!device || device_dispatch_table(device)->DestroyEvent))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyEvent<Format>);
    if (strcmp(pName, "vkGetEventStatus") == 0 && (!device || device_dispatch_table(device)->GetEventStatus))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetEventStatus<Format>);
    if (strcmp(pName, "vkSetEvent") == 0 && (!device || device_dispatch_table(device)->SetEvent))
        return reinterpret_cast<PFN_vkVoidFunction>(vkSetEvent<Format>);
    if (strcmp(pName, "vkResetEvent") == 0 && (!device || device_dispatch_table(device)->ResetEvent))
        return reinterpret_cast<PFN_vkVoidFunction>(vkResetEvent<Format>);
    if (strcmp(pName, "vkCreateBufferView") == 0 && (!device || device_dispatch_table(device)->CreateBufferView))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateBufferView<Format>);
    if (strcmp(pName, "vkDestroyBufferView") == 0 && (!device || device_dispatch_table(device)->DestroyBufferView))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyBufferView<Format>);
    if (strcmp(pName, "vkCreateShaderModule") == 0 && (!device || device_dispatch_table(device)->CreateShaderModule))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateShaderModule<Format>);
    if (strcmp(pName, "vkDestroyShaderModule") == 0 && (!device || device_dispatch_table(device)->DestroyShaderModule))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyShaderModule<Format>);
    if (strcmp(pName, "vkCreatePipelineCache") == 0 && (!device || device_dispatch_table(device)->CreatePipelineCache))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreatePipelineCache<Format>);
    if (strcmp(pName, "vkDestroyPipelineCache") == 0 && (!device || device_dispatch_table(device)->DestroyPipelineCache))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyPipelineCache<Format>);
    if (strcmp(pName, "vkGetPipelineCacheData") == 0 && (!device || device_dispatch_table(device)->GetPipelineCacheData))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPipelineCacheData<Format>);
    if (strcmp(pName, "vkMergePipelineCaches") == 0 && (!device || device_dispatch_table(device)->MergePipelineCaches))
        return reinterpret_cast<PFN_vkVoidFunction>(vkMergePipelineCaches<Format>);
    if (strcmp(pName, "vkCreateComputePipelines") == 0 && (!device || device_dispatch_table(device)->CreateComputePipelines))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateComputePipelines<Format>);
    if (strcmp(pName, "vkDestroyPipeline") == 0 && (!device || device_dispatch_table(device)->DestroyPipeline))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyPipeline<Format>);
    if (strcmp(pName, "vkCreatePipelineLayout") == 0 && (!device || device_dispatch_table(device)->CreatePipelineLayout))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreatePipelineLayout<Format>);
    if (strcmp(pName, "vkDestroyPipelineLayout") == 0 && (!device || device_dispatch_table(device)->DestroyPipelineLayout))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyPipelineLayout<Format>);
    if (strcmp(pName, "vkCreateSampler") == 0 && (!device || device_dispatch_table(device)->CreateSampler))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateSampler<Format>);
    if (strcmp(pName, "vkDestroySampler") == 0 && (!device || device_dispatch_table(device)->DestroySampler))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroySampler<Format>);
    if (strcmp(pName, "vkCreateDescriptorSetLayout") == 0 && (!device || device_dispatch_table(device)->CreateDescriptorSetLayout))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateDescriptorSetLayout<Format>);
    if (strcmp(pName, "vkDestroyDescriptorSetLayout") == 0 && (!device || device_dispatch_table(device)->DestroyDescriptorSetLayout))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyDescriptorSetLayout<Format>);
    if (strcmp(pName, "vkCreateDescriptorPool") == 0 && (!device || device_dispatch_table(device)->CreateDescriptorPool))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateDescriptorPool<Format>);
    if (strcmp(pName, "vkDestroyDescriptorPool") == 0 && (!device || device_dispatch_table(device)->DestroyDescriptorPool))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyDescriptorPool<Format>);
    if (strcmp(pName, "vkResetDescriptorPool") == 0 && (!device || device_dispatch_table(device)->ResetDescriptorPool))
        return reinterpret_cast<PFN_vkVoidFunction>(vkResetDescriptorPool<Format>);
    if (strcmp(pName, "vkAllocateDescriptorSets") == 0 && (!device || device_dispatch_table(device)->AllocateDescriptorSets))
        return reinterpret_cast<PFN_vkVoidFunction>(vkAllocateDescriptorSets<Format>);
    if (strcmp(pName, "vkFreeDescriptorSets") == 0 && (!device || device_dispatch_table(device)->FreeDescriptorSets))
        return reinterpret_cast<PFN_vkVoidFunction>(vkFreeDescriptorSets<Format>);
    if (strcmp(pName, "vkUpdateDescriptorSets") == 0 && (!device || device_dispatch_table(device)->UpdateDescriptorSets))
        return reinterpret_cast<PFN_vkVoidFunction>(vkUpdateDescriptorSets<Format>);
    if (strcmp(pName, "vkCmdBindPipeline") == 0 && (!device || device_dispatch_table(device)->CmdBindPipeline))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdBindPipeline<Format>);
    if (strcmp(pName, "vkCmdBindDescriptorSets") == 0 && (!device || device_dispatch_table(device)->CmdBindDescriptorSets))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdBindDescriptorSets<Format>);
    if (strcmp(pName, "vkCmdClearColorImage") == 0 && (!device || device_dispatch_table(device)->CmdClearColorImage))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdClearColorImage<Format>);
    if (strcmp(pName, "vkCmdDispatch") == 0 && (!device || device_dispatch_table(device)->CmdDispatch))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdDispatch<Format>);
    if (strcmp(pName, "vkCmdDispatchIndirect") == 0 && (!device || device_dispatch_table(device)->CmdDispatchIndirect))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdDispatchIndirect<Format>);
    if (strcmp(pName, "vkCmdSetEvent") == 0 && (!device || device_dispatch_table(device)->CmdSetEvent))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetEvent<Format>);
    if (strcmp(pName, "vkCmdResetEvent") == 0 && (!device || device_dispatch_table(device)->CmdResetEvent))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdResetEvent<Format>);
    if (strcmp(pName, "vkCmdWaitEvents") == 0 && (!device || device_dispatch_table(device)->CmdWaitEvents))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdWaitEvents<Format>);
    if (strcmp(pName, "vkCmdPushConstants") == 0 && (!device || device_dispatch_table(device)->CmdPushConstants))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdPushConstants<Format>);
    if (strcmp(pName, "vkCreateGraphicsPipelines") == 0 && (!device || device_dispatch_table(device)->CreateGraphicsPipelines))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateGraphicsPipelines<Format>);
    if (strcmp(pName, "vkCreateFramebuffer") == 0 && (!device || device_dispatch_table(device)->CreateFramebuffer))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateFramebuffer<Format>);
    if (strcmp(pName, "vkDestroyFramebuffer") == 0 && (!device || device_dispatch_table(device)->DestroyFramebuffer))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyFramebuffer<Format>);
    if (strcmp(pName, "vkCreateRenderPass") == 0 && (!device || device_dispatch_table(device)->CreateRenderPass))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateRenderPass<Format>);
    if (strcmp(pName, "vkDestroyRenderPass") == 0 && (!device || device_dispatch_table(device)->DestroyRenderPass))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyRenderPass<Format>);
    if (strcmp(pName, "vkGetRenderAreaGranularity") == 0 && (!device || device_dispatch_table(device)->GetRenderAreaGranularity))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetRenderAreaGranularity<Format>);
    if (strcmp(pName, "vkCmdSetViewport") == 0 && (!device || device_dispatch_table(device)->CmdSetViewport))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetViewport<Format>);
    if (strcmp(pName, "vkCmdSetScissor") == 0 && (!device || device_dispatch_table(device)->CmdSetScissor))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetScissor<Format>);
    if (strcmp(pName, "vkCmdSetLineWidth") == 0 && (!device || device_dispatch_table(device)->CmdSetLineWidth))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetLineWidth<Format>);
    if (strcmp(pName, "vkCmdSetDepthBias") == 0 && (!device || device_dispatch_table(device)->CmdSetDepthBias))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetDepthBias<Format>);
    if (strcmp(pName, "vkCmdSetBlendConstants") == 0 && (!device || device_dispatch_table(device)->CmdSetBlendConstants))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetBlendConstants<Format>);
    if (strcmp(pName, "vkCmdSetDepthBounds") == 0 && (!device || device_dispatch_table(device)->CmdSetDepthBounds))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetDepthBounds<Format>);
    if (strcmp(pName, "vkCmdSetStencilCompareMask") == 0 && (!device || device_dispatch_table(device)->CmdSetStencilCompareMask))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetStencilCompareMask<Format>);
    if (strcmp(pName, "vkCmdSetStencilWriteMask") == 0 && (!device || device_dispatch_table(device)->CmdSetStencilWriteMask))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetStencilWriteMask<Format>);
    if (strcmp(pName, "vkCmdSetStencilReference") == 0 && (!device || device_dispatch_table(device)->CmdSetStencilReference))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetStencilReference<Format>);
    if (strcmp(pName, "vkCmdBindIndexBuffer") == 0 && (!device || device_dispatch_table(device)->CmdBindIndexBuffer))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdBindIndexBuffer<Format>);
    if (strcmp(pName, "vkCmdBindVertexBuffers") == 0 && (!device || device_dispatch_table(device)->CmdBindVertexBuffers))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdBindVertexBuffers<Format>);
    if (strcmp(pName, "vkCmdDraw") == 0 && (!device || device_dispatch_table(device)->CmdDraw))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdDraw<Format>);
    if (strcmp(pName, "vkCmdDrawIndexed") == 0 && (!device || device_dispatch_table(device)->CmdDrawIndexed))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdDrawIndexed<Format>);
    if (strcmp(pName, "vkCmdDrawIndirect") == 0 && (!device || device_dispatch_table(device)->CmdDrawIndirect))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdDrawIndirect<Format>);
    if (strcmp(pName, "vkCmdDrawIndexedIndirect") == 0 && (!device || device_dispatch_table(device)->CmdDrawIndexedIndirect))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdDrawIndexedIndirect<Format>);
    if (strcmp(pName, "vkCmdBlitImage") == 0 && (!device || device_dispatch_table(device)->CmdBlitImage))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdBlitImage<Format>);
    if (strcmp(pName, "vkCmdClearDepthStencilImage") == 0 && (!device || device_dispatch_table(device)->CmdClearDepthStencilImage))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdClearDepthStencilImage<Format>);
    if (strcmp(pName, "vkCmdClearAttachments") == 0 && (!device || device_dispatch_table(device)->CmdClearAttachments))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdClearAttachments<Format>);
    if (strcmp(pName, "vkCmdResolveImage") == 0 && (!device || device_dispatch_table(device)->CmdResolveImage))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdResolveImage<Format>);
    if (strcmp(pName, "vkCmdBeginRenderPass") == 0 && (!device || device_dispatch_table(device)->CmdBeginRenderPass))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdBeginRenderPass<Format>);
    if (strcmp(pName, "vkCmdNextSubpass") == 0 && (!device || device_dispatch_table(device)->CmdNextSubpass))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdNextSubpass<Format>);
    if (strcmp(pName, "vkCmdEndRenderPass") == 0 && (!device || device_dispatch_table(device)->CmdEndRenderPass))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdEndRenderPass<Format>);
    if (strcmp(pName, "vkBindBufferMemory2") == 0 && (!device || device_dispatch_table(device)->BindBufferMemory2))
        return reinterpret_cast<PFN_vkVoidFunction>(vkBindBufferMemory2<Format>);
    if (strcmp(pName, "vkBindImageMemory2") == 0 && (!device || device_dispatch_table(device)->BindImageMemory2))
        return reinterpret_cast<PFN_vkVoidFunction>(vkBindImageMemory2<Format>);
    if (strcmp(pName, "vkGetDeviceGroupPeerMemoryFeatures") == 0 && (!device || device_dispatch_table(device)->GetDeviceGroupPeerMemoryFeatures))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetDeviceGroupPeerMemoryFeatures<Format>);
    if (strcmp(pName, "vkCmdSetDeviceMask") == 0 && (!device || device_dispatch_table(device)->CmdSetDeviceMask))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetDeviceMask<Format>);
    if (strcmp(pName, "vkGetImageMemoryRequirements2") == 0 && (!device || device_dispatch_table(device)->GetImageMemoryRequirements2))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetImageMemoryRequirements2<Format>);
    if (strcmp(pName, "vkGetBufferMemoryRequirements2") == 0 && (!device || device_dispatch_table(device)->GetBufferMemoryRequirements2))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetBufferMemoryRequirements2<Format>);
    if (strcmp(pName, "vkGetImageSparseMemoryRequirements2") == 0 && (!device || device_dispatch_table(device)->GetImageSparseMemoryRequirements2))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetImageSparseMemoryRequirements2<Format>);
    if (strcmp(pName, "vkTrimCommandPool") == 0 && (!device || device_dispatch_table(device)->TrimCommandPool))
        return reinterpret_cast<PFN_vkVoidFunction>(vkTrimCommandPool<Format>);
    if (strcmp(pName, "vkGetDeviceQueue2") == 0 && (!device || device_dispatch_table(device)->GetDeviceQueue2))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetDeviceQueue2<Format>);
    if (strcmp(pName, "vkCmdDispatchBase") == 0 && (!device || device_dispatch_table(device)->CmdDispatchBase))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdDispatchBase<Format>);
    if (strcmp(pName, "vkCreateDescriptorUpdateTemplate") == 0 && (!device || device_dispatch_table(device)->CreateDescriptorUpdateTemplate))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateDescriptorUpdateTemplate<Format>);
    if (strcmp(pName, "vkDestroyDescriptorUpdateTemplate") == 0 && (!device || device_dispatch_table(device)->DestroyDescriptorUpdateTemplate))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyDescriptorUpdateTemplate<Format>);
    if (strcmp(pName, "vkUpdateDescriptorSetWithTemplate") == 0 && (!device || device_dispatch_table(device)->UpdateDescriptorSetWithTemplate))
        return reinterpret_cast<PFN_vkVoidFunction>(vkUpdateDescriptorSetWithTemplate<Format>);
    if (strcmp(pName, "vkGetDescriptorSetLayoutSupport") == 0 && (!device || device_dispatch_table(device)->GetDescriptorSetLayoutSupport))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetDescriptorSetLayoutSupport<Format>);
    if (strcmp(pName, "vkCreateSamplerYcbcrConversion") == 0 && (!device || device_dispatch_table(device)->CreateSamplerYcbcrConversion))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateSamplerYcbcrConversion<Format>);
    if (strcmp(pName, "vkDestroySamplerYcbcrConversion") == 0 && (!device || device_dispatch_table(device)->DestroySamplerYcbcrConversion))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroySamplerYcbcrConversion<Format>);
    if (strcmp(pName, "vkResetQueryPool") == 0 && (!device || device_dispatch_table(device)->ResetQueryPool))
        return reinterpret_cast<PFN_vkVoidFunction>(vkResetQueryPool<Format>);
    if (strcmp(pName, "vkGetSemaphoreCounterValue") == 0 && (!device || device_dispatch_table(device)->GetSemaphoreCounterValue))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetSemaphoreCounterValue<Format>);
    if (strcmp(pName, "vkWaitSemaphores") == 0 && (!device || device_dispatch_table(device)->WaitSemaphores))
        return reinterpret_cast<PFN_vkVoidFunction>(vkWaitSemaphores<Format>);
    if (strcmp(pName, "vkSignalSemaphore") == 0 && (!device || device_dispatch_table(device)->SignalSemaphore))
        return reinterpret_cast<PFN_vkVoidFunction>(vkSignalSemaphore<Format>);
    if (strcmp(pName, "vkGetBufferDeviceAddress") == 0 && (!device || device_dispatch_table(device)->GetBufferDeviceAddress))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetBufferDeviceAddress<Format>);
    if (strcmp(pName, "vkGetBufferOpaqueCaptureAddress") == 0 && (!device || device_dispatch_table(device)->GetBufferOpaqueCaptureAddress))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetBufferOpaqueCaptureAddress<Format>);
    if (strcmp(pName, "vkGetDeviceMemoryOpaqueCaptureAddress") == 0 && (!device || device_dispatch_table(device)->GetDeviceMemoryOpaqueCaptureAddress))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetDeviceMemoryOpaqueCaptureAddress<Format>);
    if (strcmp(pName, "vkCmdDrawIndirectCount") == 0 && (!device || device_dispatch_table(device)->CmdDrawIndirectCount))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdDrawIndirectCount<Format>);
    if (strcmp(pName, "vkCmdDrawIndexedIndirectCount") == 0 && (!device || device_dispatch_table(device)->CmdDrawIndexedIndirectCount))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdDrawIndexedIndirectCount<Format>);
    if (strcmp(pName, "vkCreateRenderPass2") == 0 && (!device || device_dispatch_table(device)->CreateRenderPass2))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateRenderPass2<Format>);
    if (strcmp(pName, "vkCmdBeginRenderPass2") == 0 && (!device || device_dispatch_table(device)->CmdBeginRenderPass2))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdBeginRenderPass2<Format>);
    if (strcmp(pName, "vkCmdNextSubpass2") == 0 && (!device || device_dispatch_table(device)->CmdNextSubpass2))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdNextSubpass2<Format>);
    if (strcmp(pName, "vkCmdEndRenderPass2") == 0 && (!device || device_dispatch_table(device)->CmdEndRenderPass2))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdEndRenderPass2<Format>);
    if (strcmp(pName, "vkCreatePrivateDataSlot") == 0 && (!device || device_dispatch_table(device)->CreatePrivateDataSlot))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreatePrivateDataSlot<Format>);
    if (strcmp(pName, "vkDestroyPrivateDataSlot") == 0 && (!device || device_dispatch_table(device)->DestroyPrivateDataSlot))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyPrivateDataSlot<Format>);
    if (strcmp(pName, "vkSetPrivateData") == 0 && (!device || device_dispatch_table(device)->SetPrivateData))
        return reinterpret_cast<PFN_vkVoidFunction>(vkSetPrivateData<Format>);
    if (strcmp(pName, "vkGetPrivateData") == 0 && (!device || device_dispatch_table(device)->GetPrivateData))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPrivateData<Format>);
    if (strcmp(pName, "vkCmdPipelineBarrier2") == 0 && (!device || device_dispatch_table(device)->CmdPipelineBarrier2))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdPipelineBarrier2<Format>);
    if (strcmp(pName, "vkCmdWriteTimestamp2") == 0 && (!device || device_dispatch_table(device)->CmdWriteTimestamp2))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdWriteTimestamp2<Format>);
    if (strcmp(pName, "vkQueueSubmit2") == 0 && (!device || device_dispatch_table(device)->QueueSubmit2))
        return reinterpret_cast<PFN_vkVoidFunction>(vkQueueSubmit2<Format>);
    if (strcmp(pName, "vkCmdCopyBuffer2") == 0 && (!device || device_dispatch_table(device)->CmdCopyBuffer2))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdCopyBuffer2<Format>);
    if (strcmp(pName, "vkCmdCopyImage2") == 0 && (!device || device_dispatch_table(device)->CmdCopyImage2))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdCopyImage2<Format>);
    if (strcmp(pName, "vkCmdCopyBufferToImage2") == 0 && (!device || device_dispatch_table(device)->CmdCopyBufferToImage2))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdCopyBufferToImage2<Format>);
    if (strcmp(pName, "vkCmdCopyImageToBuffer2") == 0 && (!device || device_dispatch_table(device)->CmdCopyImageToBuffer2))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdCopyImageToBuffer2<Format>);
    if (strcmp(pName, "vkGetDeviceBufferMemoryRequirements") == 0 && (!device || device_dispatch_table(device)->GetDeviceBufferMemoryRequirements))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetDeviceBufferMemoryRequirements<Format>);
    if (strcmp(pName, "vkGetDeviceImageMemoryRequirements") == 0 && (!device || device_dispatch_table(device)->GetDeviceImageMemoryRequirements))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetDeviceImageMemoryRequirements<Format>);
    if (strcmp(pName, "vkGetDeviceImageSparseMemoryRequirements") == 0 && (!device || device_dispatch_table(device)->GetDeviceImageSparseMemoryRequirements))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetDeviceImageSparseMemoryRequirements<Format>);
    if (strcmp(pName, "vkCmdSetEvent2") == 0 && (!device || device_dispatch_table(device)->CmdSetEvent2))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetEvent2<Format>);
    if (strcmp(pName, "vkCmdResetEvent2") == 0 && (!device || device_dispatch_table(device)->CmdResetEvent2))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdResetEvent2<Format>);
    if (strcmp(pName, "vkCmdWaitEvents2") == 0 && (!device || device_dispatch_table(device)->CmdWaitEvents2))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdWaitEvents2<Format>);
    if (strcmp(pName, "vkCmdBlitImage2") == 0 && (!device || device_dispatch_table(device)->CmdBlitImage2))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdBlitImage2<Format>);
    if (strcmp(pName, "vkCmdResolveImage2") == 0 && (!device || device_dispatch_table(device)->CmdResolveImage2))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdResolveImage2<Format>);
    if (strcmp(pName, "vkCmdBeginRendering") == 0 && (!device || device_dispatch_table(device)->CmdBeginRendering))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdBeginRendering<Format>);
    if (strcmp(pName, "vkCmdEndRendering") == 0 && (!device || device_dispatch_table(device)->CmdEndRendering))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdEndRendering<Format>);
    if (strcmp(pName, "vkCmdSetCullMode") == 0 && (!device || device_dispatch_table(device)->CmdSetCullMode))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetCullMode<Format>);
    if (strcmp(pName, "vkCmdSetFrontFace") == 0 && (!device || device_dispatch_table(device)->CmdSetFrontFace))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetFrontFace<Format>);
    if (strcmp(pName, "vkCmdSetPrimitiveTopology") == 0 && (!device || device_dispatch_table(device)->CmdSetPrimitiveTopology))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetPrimitiveTopology<Format>);
    if (strcmp(pName, "vkCmdSetViewportWithCount") == 0 && (!device || device_dispatch_table(device)->CmdSetViewportWithCount))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetViewportWithCount<Format>);
    if (strcmp(pName, "vkCmdSetScissorWithCount") == 0 && (!device || device_dispatch_table(device)->CmdSetScissorWithCount))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetScissorWithCount<Format>);
    if (strcmp(pName, "vkCmdBindVertexBuffers2") == 0 && (!device || device_dispatch_table(device)->CmdBindVertexBuffers2))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdBindVertexBuffers2<Format>);
    if (strcmp(pName, "vkCmdSetDepthTestEnable") == 0 && (!device || device_dispatch_table(device)->CmdSetDepthTestEnable))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetDepthTestEnable<Format>);
    if (strcmp(pName, "vkCmdSetDepthWriteEnable") == 0 && (!device || device_dispatch_table(device)->CmdSetDepthWriteEnable))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetDepthWriteEnable<Format>);
    if (strcmp(pName, "vkCmdSetDepthCompareOp") == 0 && (!device || device_dispatch_table(device)->CmdSetDepthCompareOp))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetDepthCompareOp<Format>);
    if (strcmp(pName, "vkCmdSetDepthBoundsTestEnable") == 0 && (!device || device_dispatch_table(device)->CmdSetDepthBoundsTestEnable))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetDepthBoundsTestEnable<Format>);
    if (strcmp(pName, "vkCmdSetStencilTestEnable") == 0 && (!device || device_dispatch_table(device)->CmdSetStencilTestEnable))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetStencilTestEnable<Format>);
    if (strcmp(pName, "vkCmdSetStencilOp") == 0 && (!device || device_dispatch_table(device)->CmdSetStencilOp))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetStencilOp<Format>);
    if (strcmp(pName, "vkCmdSetRasterizerDiscardEnable") == 0 && (!device || device_dispatch_table(device)->CmdSetRasterizerDiscardEnable))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetRasterizerDiscardEnable<Format>);
    if (strcmp(pName, "vkCmdSetDepthBiasEnable") == 0 && (!device || device_dispatch_table(device)->CmdSetDepthBiasEnable))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetDepthBiasEnable<Format>);
    if (strcmp(pName, "vkCmdSetPrimitiveRestartEnable") == 0 && (!device || device_dispatch_table(device)->CmdSetPrimitiveRestartEnable))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetPrimitiveRestartEnable<Format>);
    if (strcmp(pName, "vkMapMemory2") == 0 && (!device || device_dispatch_table(device)->MapMemory2))
        return reinterpret_cast<PFN_vkVoidFunction>(vkMapMemory2<Format>);
    if (strcmp(pName, "vkUnmapMemory2") == 0 && (!device || device_dispatch_table(device)->UnmapMemory2))
        return reinterpret_cast<PFN_vkVoidFunction>(vkUnmapMemory2<Format>);
    if (strcmp(pName, "vkGetDeviceImageSubresourceLayout") == 0 && (!device || device_dispatch_table(device)->GetDeviceImageSubresourceLayout))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetDeviceImageSubresourceLayout<Format>);
    if (strcmp(pName, "vkGetImageSubresourceLayout2") == 0 && (!device || device_dispatch_table(device)->GetImageSubresourceLayout2))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetImageSubresourceLayout2<Format>);
    if (strcmp(pName, "vkCopyMemoryToImage") == 0 && (!device || device_dispatch_table(device)->CopyMemoryToImage))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCopyMemoryToImage<Format>);
    if (strcmp(pName, "vkCopyImageToMemory") == 0 && (!device || device_dispatch_table(device)->CopyImageToMemory))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCopyImageToMemory<Format>);
    if (strcmp(pName, "vkCopyImageToImage") == 0 && (!device || device_dispatch_table(device)->CopyImageToImage))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCopyImageToImage<Format>);
    if (strcmp(pName, "vkTransitionImageLayout") == 0 && (!device || device_dispatch_table(device)->TransitionImageLayout))
        return reinterpret_cast<PFN_vkVoidFunction>(vkTransitionImageLayout<Format>);
    if (strcmp(pName, "vkCmdPushDescriptorSet") == 0 && (!device || device_dispatch_table(device)->CmdPushDescriptorSet))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdPushDescriptorSet<Format>);
    if (strcmp(pName, "vkCmdPushDescriptorSetWithTemplate") == 0 && (!device || device_dispatch_table(device)->CmdPushDescriptorSetWithTemplate))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdPushDescriptorSetWithTemplate<Format>);
    if (strcmp(pName, "vkCmdBindDescriptorSets2") == 0 && (!device || device_dispatch_table(device)->CmdBindDescriptorSets2))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdBindDescriptorSets2<Format>);
    if (strcmp(pName, "vkCmdPushConstants2") == 0 && (!device || device_dispatch_table(device)->CmdPushConstants2))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdPushConstants2<Format>);
    if (strcmp(pName, "vkCmdPushDescriptorSet2") == 0 && (!device || device_dispatch_table(device)->CmdPushDescriptorSet2))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdPushDescriptorSet2<Format>);
    if (strcmp(pName, "vkCmdPushDescriptorSetWithTemplate2") == 0 && (!device || device_dispatch_table(device)->CmdPushDescriptorSetWithTemplate2))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdPushDescriptorSetWithTemplate2<Format>);
    if (strcmp(pName, "vkCmdSetLineStipple") == 0 && (!device || device_dispatch_table(device)->CmdSetLineStipple))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetLineStipple<Format>);
    if (strcmp(pName, "vkCmdBindIndexBuffer2") == 0 && (!device || device_dispatch_table(device)->CmdBindIndexBuffer2))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdBindIndexBuffer2<Format>);
    if (strcmp(pName, "vkGetRenderingAreaGranularity") == 0 && (!device || device_dispatch_table(device)->GetRenderingAreaGranularity))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetRenderingAreaGranularity<Format>);
    if (strcmp(pName, "vkCmdSetRenderingAttachmentLocations") == 0 && (!device || device_dispatch_table(device)->CmdSetRenderingAttachmentLocations))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetRenderingAttachmentLocations<Format>);
    if (strcmp(pName, "vkCmdSetRenderingInputAttachmentIndices") == 0 && (!device || device_dispatch_table(device)->CmdSetRenderingInputAttachmentIndices))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetRenderingInputAttachmentIndices<Format>);
    if (strcmp(pName, "vkCreateSwapchainKHR") == 0 && (!device || device_dispatch_table(device)->CreateSwapchainKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateSwapchainKHR<Format>);
    if (strcmp(pName, "vkDestroySwapchainKHR") == 0 && (!device || device_dispatch_table(device)->DestroySwapchainKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroySwapchainKHR<Format>);
    if (strcmp(pName, "vkGetSwapchainImagesKHR") == 0 && (!device || device_dispatch_table(device)->GetSwapchainImagesKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetSwapchainImagesKHR<Format>);
    if (strcmp(pName, "vkAcquireNextImageKHR") == 0 && (!device || device_dispatch_table(device)->AcquireNextImageKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkAcquireNextImageKHR<Format>);
    if (strcmp(pName, "vkQueuePresentKHR") == 0 && (!device || device_dispatch_table(device)->QueuePresentKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkQueuePresentKHR<Format>);
    if (strcmp(pName, "vkGetDeviceGroupPresentCapabilitiesKHR") == 0 && (!device || device_dispatch_table(device)->GetDeviceGroupPresentCapabilitiesKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetDeviceGroupPresentCapabilitiesKHR<Format>);
    if (strcmp(pName, "vkGetDeviceGroupSurfacePresentModesKHR") == 0 && (!device || device_dispatch_table(device)->GetDeviceGroupSurfacePresentModesKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetDeviceGroupSurfacePresentModesKHR<Format>);
    if (strcmp(pName, "vkAcquireNextImage2KHR") == 0 && (!device || device_dispatch_table(device)->AcquireNextImage2KHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkAcquireNextImage2KHR<Format>);
    if (strcmp(pName, "vkCreateSharedSwapchainsKHR") == 0 && (!device || device_dispatch_table(device)->CreateSharedSwapchainsKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateSharedSwapchainsKHR<Format>);
    if (strcmp(pName, "vkCreateVideoSessionKHR") == 0 && (!device || device_dispatch_table(device)->CreateVideoSessionKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateVideoSessionKHR<Format>);
    if (strcmp(pName, "vkDestroyVideoSessionKHR") == 0 && (!device || device_dispatch_table(device)->DestroyVideoSessionKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyVideoSessionKHR<Format>);
    if (strcmp(pName, "vkGetVideoSessionMemoryRequirementsKHR") == 0 && (!device || device_dispatch_table(device)->GetVideoSessionMemoryRequirementsKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetVideoSessionMemoryRequirementsKHR<Format>);
    if (strcmp(pName, "vkBindVideoSessionMemoryKHR") == 0 && (!device || device_dispatch_table(device)->BindVideoSessionMemoryKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkBindVideoSessionMemoryKHR<Format>);
    if (strcmp(pName, "vkCreateVideoSessionParametersKHR") == 0 && (!device || device_dispatch_table(device)->CreateVideoSessionParametersKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateVideoSessionParametersKHR<Format>);
    if (strcmp(pName, "vkUpdateVideoSessionParametersKHR") == 0 && (!device || device_dispatch_table(device)->UpdateVideoSessionParametersKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkUpdateVideoSessionParametersKHR<Format>);
    if (strcmp(pName, "vkDestroyVideoSessionParametersKHR") == 0 && (!device || device_dispatch_table(device)->DestroyVideoSessionParametersKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyVideoSessionParametersKHR<Format>);
    if (strcmp(pName, "vkCmdBeginVideoCodingKHR") == 0 && (!device || device_dispatch_table(device)->CmdBeginVideoCodingKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdBeginVideoCodingKHR<Format>);
    if (strcmp(pName, "vkCmdEndVideoCodingKHR") == 0 && (!device || device_dispatch_table(device)->CmdEndVideoCodingKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdEndVideoCodingKHR<Format>);
    if (strcmp(pName, "vkCmdControlVideoCodingKHR") == 0 && (!device || device_dispatch_table(device)->CmdControlVideoCodingKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdControlVideoCodingKHR<Format>);
    if (strcmp(pName, "vkCmdDecodeVideoKHR") == 0 && (!device || device_dispatch_table(device)->CmdDecodeVideoKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdDecodeVideoKHR<Format>);
    if (strcmp(pName, "vkCmdBeginRenderingKHR") == 0 && (!device || device_dispatch_table(device)->CmdBeginRenderingKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdBeginRenderingKHR<Format>);
    if (strcmp(pName, "vkCmdEndRenderingKHR") == 0 && (!device || device_dispatch_table(device)->CmdEndRenderingKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdEndRenderingKHR<Format>);
    if (strcmp(pName, "vkGetDeviceGroupPeerMemoryFeaturesKHR") == 0 && (!device || device_dispatch_table(device)->GetDeviceGroupPeerMemoryFeaturesKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetDeviceGroupPeerMemoryFeaturesKHR<Format>);
    if (strcmp(pName, "vkCmdSetDeviceMaskKHR") == 0 && (!device || device_dispatch_table(device)->CmdSetDeviceMaskKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetDeviceMaskKHR<Format>);
    if (strcmp(pName, "vkCmdDispatchBaseKHR") == 0 && (!device || device_dispatch_table(device)->CmdDispatchBaseKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdDispatchBaseKHR<Format>);
    if (strcmp(pName, "vkTrimCommandPoolKHR") == 0 && (!device || device_dispatch_table(device)->TrimCommandPoolKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkTrimCommandPoolKHR<Format>);
#if defined(VK_USE_PLATFORM_WIN32_KHR)
    if (strcmp(pName, "vkGetMemoryWin32HandleKHR") == 0 && (!device || device_dispatch_table(device)->GetMemoryWin32HandleKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetMemoryWin32HandleKHR<Format>);
    if (strcmp(pName, "vkGetMemoryWin32HandlePropertiesKHR") == 0 && (!device || device_dispatch_table(device)->GetMemoryWin32HandlePropertiesKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetMemoryWin32HandlePropertiesKHR<Format>);
#endif  // VK_USE_PLATFORM_WIN32_KHR
    if (strcmp(pName, "vkGetMemoryFdKHR") == 0 && (!device || device_dispatch_table(device)->GetMemoryFdKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetMemoryFdKHR<Format>);
    if (strcmp(pName, "vkGetMemoryFdPropertiesKHR") == 0 && (!device || device_dispatch_table(device)->GetMemoryFdPropertiesKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetMemoryFdPropertiesKHR<Format>);
#if defined(VK_USE_PLATFORM_WIN32_KHR)
    if (strcmp(pName, "vkImportSemaphoreWin32HandleKHR") == 0 && (!device || device_dispatch_table(device)->ImportSemaphoreWin32HandleKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkImportSemaphoreWin32HandleKHR<Format>);
    if (strcmp(pName, "vkGetSemaphoreWin32HandleKHR") == 0 && (!device || device_dispatch_table(device)->GetSemaphoreWin32HandleKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetSemaphoreWin32HandleKHR<Format>);
#endif  // VK_USE_PLATFORM_WIN32_KHR
    if (strcmp(pName, "vkImportSemaphoreFdKHR") == 0 && (!device || device_dispatch_table(device)->ImportSemaphoreFdKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkImportSemaphoreFdKHR<Format>);
    if (strcmp(pName, "vkGetSemaphoreFdKHR") == 0 && (!device || device_dispatch_table(device)->GetSemaphoreFdKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetSemaphoreFdKHR<Format>);
    if (strcmp(pName, "vkCmdPushDescriptorSetKHR") == 0 && (!device || device_dispatch_table(device)->CmdPushDescriptorSetKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdPushDescriptorSetKHR<Format>);
    if (strcmp(pName, "vkCmdPushDescriptorSetWithTemplateKHR") == 0 && (!device || device_dispatch_table(device)->CmdPushDescriptorSetWithTemplateKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdPushDescriptorSetWithTemplateKHR<Format>);
    if (strcmp(pName, "vkCreateDescriptorUpdateTemplateKHR") == 0 && (!device || device_dispatch_table(device)->CreateDescriptorUpdateTemplateKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateDescriptorUpdateTemplateKHR<Format>);
    if (strcmp(pName, "vkDestroyDescriptorUpdateTemplateKHR") == 0 && (!device || device_dispatch_table(device)->DestroyDescriptorUpdateTemplateKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyDescriptorUpdateTemplateKHR<Format>);
    if (strcmp(pName, "vkUpdateDescriptorSetWithTemplateKHR") == 0 && (!device || device_dispatch_table(device)->UpdateDescriptorSetWithTemplateKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkUpdateDescriptorSetWithTemplateKHR<Format>);
    if (strcmp(pName, "vkCreateRenderPass2KHR") == 0 && (!device || device_dispatch_table(device)->CreateRenderPass2KHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateRenderPass2KHR<Format>);
    if (strcmp(pName, "vkCmdBeginRenderPass2KHR") == 0 && (!device || device_dispatch_table(device)->CmdBeginRenderPass2KHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdBeginRenderPass2KHR<Format>);
    if (strcmp(pName, "vkCmdNextSubpass2KHR") == 0 && (!device || device_dispatch_table(device)->CmdNextSubpass2KHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdNextSubpass2KHR<Format>);
    if (strcmp(pName, "vkCmdEndRenderPass2KHR") == 0 && (!device || device_dispatch_table(device)->CmdEndRenderPass2KHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdEndRenderPass2KHR<Format>);
    if (strcmp(pName, "vkGetSwapchainStatusKHR") == 0 && (!device || device_dispatch_table(device)->GetSwapchainStatusKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetSwapchainStatusKHR<Format>);
#if defined(VK_USE_PLATFORM_WIN32_KHR)
    if (strcmp(pName, "vkImportFenceWin32HandleKHR") == 0 && (!device || device_dispatch_table(device)->ImportFenceWin32HandleKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkImportFenceWin32HandleKHR<Format>);
    if (strcmp(pName, "vkGetFenceWin32HandleKHR") == 0 && (!device || device_dispatch_table(device)->GetFenceWin32HandleKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetFenceWin32HandleKHR<Format>);
#endif  // VK_USE_PLATFORM_WIN32_KHR
    if (strcmp(pName, "vkImportFenceFdKHR") == 0 && (!device || device_dispatch_table(device)->ImportFenceFdKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkImportFenceFdKHR<Format>);
    if (strcmp(pName, "vkGetFenceFdKHR") == 0 && (!device || device_dispatch_table(device)->GetFenceFdKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetFenceFdKHR<Format>);
    if (strcmp(pName, "vkAcquireProfilingLockKHR") == 0 && (!device || device_dispatch_table(device)->AcquireProfilingLockKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkAcquireProfilingLockKHR<Format>);
    if (strcmp(pName, "vkReleaseProfilingLockKHR") == 0 && (!device || device_dispatch_table(device)->ReleaseProfilingLockKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkReleaseProfilingLockKHR<Format>);
    if (strcmp(pName, "vkGetImageMemoryRequirements2KHR") == 0 && (!device || device_dispatch_table(device)->GetImageMemoryRequirements2KHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetImageMemoryRequirements2KHR<Format>);
    if (strcmp(pName, "vkGetBufferMemoryRequirements2KHR") == 0 && (!device || device_dispatch_table(device)->GetBufferMemoryRequirements2KHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetBufferMemoryRequirements2KHR<Format>);
    if (strcmp(pName, "vkGetImageSparseMemoryRequirements2KHR") == 0 && (!device || device_dispatch_table(device)->GetImageSparseMemoryRequirements2KHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetImageSparseMemoryRequirements2KHR<Format>);
    if (strcmp(pName, "vkCreateSamplerYcbcrConversionKHR") == 0 && (!device || device_dispatch_table(device)->CreateSamplerYcbcrConversionKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateSamplerYcbcrConversionKHR<Format>);
    if (strcmp(pName, "vkDestroySamplerYcbcrConversionKHR") == 0 && (!device || device_dispatch_table(device)->DestroySamplerYcbcrConversionKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroySamplerYcbcrConversionKHR<Format>);
    if (strcmp(pName, "vkBindBufferMemory2KHR") == 0 && (!device || device_dispatch_table(device)->BindBufferMemory2KHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkBindBufferMemory2KHR<Format>);
    if (strcmp(pName, "vkBindImageMemory2KHR") == 0 && (!device || device_dispatch_table(device)->BindImageMemory2KHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkBindImageMemory2KHR<Format>);
    if (strcmp(pName, "vkGetDescriptorSetLayoutSupportKHR") == 0 && (!device || device_dispatch_table(device)->GetDescriptorSetLayoutSupportKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetDescriptorSetLayoutSupportKHR<Format>);
    if (strcmp(pName, "vkCmdDrawIndirectCountKHR") == 0 && (!device || device_dispatch_table(device)->CmdDrawIndirectCountKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdDrawIndirectCountKHR<Format>);
    if (strcmp(pName, "vkCmdDrawIndexedIndirectCountKHR") == 0 && (!device || device_dispatch_table(device)->CmdDrawIndexedIndirectCountKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdDrawIndexedIndirectCountKHR<Format>);
    if (strcmp(pName, "vkGetSemaphoreCounterValueKHR") == 0 && (!device || device_dispatch_table(device)->GetSemaphoreCounterValueKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetSemaphoreCounterValueKHR<Format>);
    if (strcmp(pName, "vkWaitSemaphoresKHR") == 0 && (!device || device_dispatch_table(device)->WaitSemaphoresKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkWaitSemaphoresKHR<Format>);
    if (strcmp(pName, "vkSignalSemaphoreKHR") == 0 && (!device || device_dispatch_table(device)->SignalSemaphoreKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkSignalSemaphoreKHR<Format>);
    if (strcmp(pName, "vkCmdSetFragmentShadingRateKHR") == 0 && (!device || device_dispatch_table(device)->CmdSetFragmentShadingRateKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetFragmentShadingRateKHR<Format>);
    if (strcmp(pName, "vkCmdSetRenderingAttachmentLocationsKHR") == 0 && (!device || device_dispatch_table(device)->CmdSetRenderingAttachmentLocationsKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetRenderingAttachmentLocationsKHR<Format>);
    if (strcmp(pName, "vkCmdSetRenderingInputAttachmentIndicesKHR") == 0 && (!device || device_dispatch_table(device)->CmdSetRenderingInputAttachmentIndicesKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetRenderingInputAttachmentIndicesKHR<Format>);
    if (strcmp(pName, "vkWaitForPresentKHR") == 0 && (!device || device_dispatch_table(device)->WaitForPresentKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkWaitForPresentKHR<Format>);
    if (strcmp(pName, "vkGetBufferDeviceAddressKHR") == 0 && (!device || device_dispatch_table(device)->GetBufferDeviceAddressKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetBufferDeviceAddressKHR<Format>);
    if (strcmp(pName, "vkGetBufferOpaqueCaptureAddressKHR") == 0 && (!device || device_dispatch_table(device)->GetBufferOpaqueCaptureAddressKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetBufferOpaqueCaptureAddressKHR<Format>);
    if (strcmp(pName, "vkGetDeviceMemoryOpaqueCaptureAddressKHR") == 0 && (!device || device_dispatch_table(device)->GetDeviceMemoryOpaqueCaptureAddressKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetDeviceMemoryOpaqueCaptureAddressKHR<Format>);
    if (strcmp(pName, "vkCreateDeferredOperationKHR") == 0 && (!device || device_dispatch_table(device)->CreateDeferredOperationKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateDeferredOperationKHR<Format>);
    if (strcmp(pName, "vkDestroyDeferredOperationKHR") == 0 && (!device || device_dispatch_table(device)->DestroyDeferredOperationKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyDeferredOperationKHR<Format>);
    if (strcmp(pName, "vkGetDeferredOperationMaxConcurrencyKHR") == 0 && (!device || device_dispatch_table(device)->GetDeferredOperationMaxConcurrencyKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetDeferredOperationMaxConcurrencyKHR<Format>);
    if (strcmp(pName, "vkGetDeferredOperationResultKHR") == 0 && (!device || device_dispatch_table(device)->GetDeferredOperationResultKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetDeferredOperationResultKHR<Format>);
    if (strcmp(pName, "vkDeferredOperationJoinKHR") == 0 && (!device || device_dispatch_table(device)->DeferredOperationJoinKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDeferredOperationJoinKHR<Format>);
    if (strcmp(pName, "vkGetPipelineExecutablePropertiesKHR") == 0 && (!device || device_dispatch_table(device)->GetPipelineExecutablePropertiesKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPipelineExecutablePropertiesKHR<Format>);
    if (strcmp(pName, "vkGetPipelineExecutableStatisticsKHR") == 0 && (!device || device_dispatch_table(device)->GetPipelineExecutableStatisticsKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPipelineExecutableStatisticsKHR<Format>);
    if (strcmp(pName, "vkGetPipelineExecutableInternalRepresentationsKHR") == 0 && (!device || device_dispatch_table(device)->GetPipelineExecutableInternalRepresentationsKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPipelineExecutableInternalRepresentationsKHR<Format>);
    if (strcmp(pName, "vkMapMemory2KHR") == 0 && (!device || device_dispatch_table(device)->MapMemory2KHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkMapMemory2KHR<Format>);
    if (strcmp(pName, "vkUnmapMemory2KHR") == 0 && (!device || device_dispatch_table(device)->UnmapMemory2KHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkUnmapMemory2KHR<Format>);
    if (strcmp(pName, "vkGetEncodedVideoSessionParametersKHR") == 0 && (!device || device_dispatch_table(device)->GetEncodedVideoSessionParametersKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetEncodedVideoSessionParametersKHR<Format>);
    if (strcmp(pName, "vkCmdEncodeVideoKHR") == 0 && (!device || device_dispatch_table(device)->CmdEncodeVideoKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdEncodeVideoKHR<Format>);
    if (strcmp(pName, "vkCmdSetEvent2KHR") == 0 && (!device || device_dispatch_table(device)->CmdSetEvent2KHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetEvent2KHR<Format>);
    if (strcmp(pName, "vkCmdResetEvent2KHR") == 0 && (!device || device_dispatch_table(device)->CmdResetEvent2KHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdResetEvent2KHR<Format>);
    if (strcmp(pName, "vkCmdWaitEvents2KHR") == 0 && (!device || device_dispatch_table(device)->CmdWaitEvents2KHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdWaitEvents2KHR<Format>);
    if (strcmp(pName, "vkCmdPipelineBarrier2KHR") == 0 && (!device || device_dispatch_table(device)->CmdPipelineBarrier2KHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdPipelineBarrier2KHR<Format>);
    if (strcmp(pName, "vkCmdWriteTimestamp2KHR") == 0 && (!device || device_dispatch_table(device)->CmdWriteTimestamp2KHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdWriteTimestamp2KHR<Format>);
    if (strcmp(pName, "vkQueueSubmit2KHR") == 0 && (!device || device_dispatch_table(device)->QueueSubmit2KHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkQueueSubmit2KHR<Format>);
    if (strcmp(pName, "vkCmdCopyBuffer2KHR") == 0 && (!device || device_dispatch_table(device)->CmdCopyBuffer2KHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdCopyBuffer2KHR<Format>);
    if (strcmp(pName, "vkCmdCopyImage2KHR") == 0 && (!device || device_dispatch_table(device)->CmdCopyImage2KHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdCopyImage2KHR<Format>);
    if (strcmp(pName, "vkCmdCopyBufferToImage2KHR") == 0 && (!device || device_dispatch_table(device)->CmdCopyBufferToImage2KHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdCopyBufferToImage2KHR<Format>);
    if (strcmp(pName, "vkCmdCopyImageToBuffer2KHR") == 0 && (!device || device_dispatch_table(device)->CmdCopyImageToBuffer2KHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdCopyImageToBuffer2KHR<Format>);
    if (strcmp(pName, "vkCmdBlitImage2KHR") == 0 && (!device || device_dispatch_table(device)->CmdBlitImage2KHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdBlitImage2KHR<Format>);
    if (strcmp(pName, "vkCmdResolveImage2KHR") == 0 && (!device || device_dispatch_table(device)->CmdResolveImage2KHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdResolveImage2KHR<Format>);
    if (strcmp(pName, "vkCmdTraceRaysIndirect2KHR") == 0 && (!device || device_dispatch_table(device)->CmdTraceRaysIndirect2KHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdTraceRaysIndirect2KHR<Format>);
    if (strcmp(pName, "vkGetDeviceBufferMemoryRequirementsKHR") == 0 && (!device || device_dispatch_table(device)->GetDeviceBufferMemoryRequirementsKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetDeviceBufferMemoryRequirementsKHR<Format>);
    if (strcmp(pName, "vkGetDeviceImageMemoryRequirementsKHR") == 0 && (!device || device_dispatch_table(device)->GetDeviceImageMemoryRequirementsKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetDeviceImageMemoryRequirementsKHR<Format>);
    if (strcmp(pName, "vkGetDeviceImageSparseMemoryRequirementsKHR") == 0 && (!device || device_dispatch_table(device)->GetDeviceImageSparseMemoryRequirementsKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetDeviceImageSparseMemoryRequirementsKHR<Format>);
    if (strcmp(pName, "vkCmdBindIndexBuffer2KHR") == 0 && (!device || device_dispatch_table(device)->CmdBindIndexBuffer2KHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdBindIndexBuffer2KHR<Format>);
    if (strcmp(pName, "vkGetRenderingAreaGranularityKHR") == 0 && (!device || device_dispatch_table(device)->GetRenderingAreaGranularityKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetRenderingAreaGranularityKHR<Format>);
    if (strcmp(pName, "vkGetDeviceImageSubresourceLayoutKHR") == 0 && (!device || device_dispatch_table(device)->GetDeviceImageSubresourceLayoutKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetDeviceImageSubresourceLayoutKHR<Format>);
    if (strcmp(pName, "vkGetImageSubresourceLayout2KHR") == 0 && (!device || device_dispatch_table(device)->GetImageSubresourceLayout2KHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetImageSubresourceLayout2KHR<Format>);
    if (strcmp(pName, "vkWaitForPresent2KHR") == 0 && (!device || device_dispatch_table(device)->WaitForPresent2KHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkWaitForPresent2KHR<Format>);
    if (strcmp(pName, "vkCreatePipelineBinariesKHR") == 0 && (!device || device_dispatch_table(device)->CreatePipelineBinariesKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreatePipelineBinariesKHR<Format>);
    if (strcmp(pName, "vkDestroyPipelineBinaryKHR") == 0 && (!device || device_dispatch_table(device)->DestroyPipelineBinaryKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyPipelineBinaryKHR<Format>);
    if (strcmp(pName, "vkGetPipelineKeyKHR") == 0 && (!device || device_dispatch_table(device)->GetPipelineKeyKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPipelineKeyKHR<Format>);
    if (strcmp(pName, "vkGetPipelineBinaryDataKHR") == 0 && (!device || device_dispatch_table(device)->GetPipelineBinaryDataKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPipelineBinaryDataKHR<Format>);
    if (strcmp(pName, "vkReleaseCapturedPipelineDataKHR") == 0 && (!device || device_dispatch_table(device)->ReleaseCapturedPipelineDataKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkReleaseCapturedPipelineDataKHR<Format>);
    if (strcmp(pName, "vkReleaseSwapchainImagesKHR") == 0 && (!device || device_dispatch_table(device)->ReleaseSwapchainImagesKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkReleaseSwapchainImagesKHR<Format>);
    if (strcmp(pName, "vkCmdSetLineStippleKHR") == 0 && (!device || device_dispatch_table(device)->CmdSetLineStippleKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetLineStippleKHR<Format>);
    if (strcmp(pName, "vkGetCalibratedTimestampsKHR") == 0 && (!device || device_dispatch_table(device)->GetCalibratedTimestampsKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetCalibratedTimestampsKHR<Format>);
    if (strcmp(pName, "vkCmdBindDescriptorSets2KHR") == 0 && (!device || device_dispatch_table(device)->CmdBindDescriptorSets2KHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdBindDescriptorSets2KHR<Format>);
    if (strcmp(pName, "vkCmdPushConstants2KHR") == 0 && (!device || device_dispatch_table(device)->CmdPushConstants2KHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdPushConstants2KHR<Format>);
    if (strcmp(pName, "vkCmdPushDescriptorSet2KHR") == 0 && (!device || device_dispatch_table(device)->CmdPushDescriptorSet2KHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdPushDescriptorSet2KHR<Format>);
    if (strcmp(pName, "vkCmdPushDescriptorSetWithTemplate2KHR") == 0 && (!device || device_dispatch_table(device)->CmdPushDescriptorSetWithTemplate2KHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdPushDescriptorSetWithTemplate2KHR<Format>);
    if (strcmp(pName, "vkCmdSetDescriptorBufferOffsets2EXT") == 0 && (!device || device_dispatch_table(device)->CmdSetDescriptorBufferOffsets2EXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetDescriptorBufferOffsets2EXT<Format>);
    if (strcmp(pName, "vkCmdBindDescriptorBufferEmbeddedSamplers2EXT") == 0 && (!device || device_dispatch_table(device)->CmdBindDescriptorBufferEmbeddedSamplers2EXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdBindDescriptorBufferEmbeddedSamplers2EXT<Format>);
    if (strcmp(pName, "vkCmdCopyMemoryIndirectKHR") == 0 && (!device || device_dispatch_table(device)->CmdCopyMemoryIndirectKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdCopyMemoryIndirectKHR<Format>);
    if (strcmp(pName, "vkCmdCopyMemoryToImageIndirectKHR") == 0 && (!device || device_dispatch_table(device)->CmdCopyMemoryToImageIndirectKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdCopyMemoryToImageIndirectKHR<Format>);
    if (strcmp(pName, "vkCmdEndRendering2KHR") == 0 && (!device || device_dispatch_table(device)->CmdEndRendering2KHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdEndRendering2KHR<Format>);
    if (strcmp(pName, "vkDebugMarkerSetObjectTagEXT") == 0 && (!device || device_dispatch_table(device)->DebugMarkerSetObjectTagEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDebugMarkerSetObjectTagEXT<Format>);
    if (strcmp(pName, "vkDebugMarkerSetObjectNameEXT") == 0 && (!device || device_dispatch_table(device)->DebugMarkerSetObjectNameEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDebugMarkerSetObjectNameEXT<Format>);
    if (strcmp(pName, "vkCmdDebugMarkerBeginEXT") == 0 && (!device || device_dispatch_table(device)->CmdDebugMarkerBeginEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdDebugMarkerBeginEXT<Format>);
    if (strcmp(pName, "vkCmdDebugMarkerEndEXT") == 0 && (!device || device_dispatch_table(device)->CmdDebugMarkerEndEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdDebugMarkerEndEXT<Format>);
    if (strcmp(pName, "vkCmdDebugMarkerInsertEXT") == 0 && (!device || device_dispatch_table(device)->CmdDebugMarkerInsertEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdDebugMarkerInsertEXT<Format>);
    if (strcmp(pName, "vkCmdBindTransformFeedbackBuffersEXT") == 0 && (!device || device_dispatch_table(device)->CmdBindTransformFeedbackBuffersEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdBindTransformFeedbackBuffersEXT<Format>);
    if (strcmp(pName, "vkCmdBeginTransformFeedbackEXT") == 0 && (!device || device_dispatch_table(device)->CmdBeginTransformFeedbackEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdBeginTransformFeedbackEXT<Format>);
    if (strcmp(pName, "vkCmdEndTransformFeedbackEXT") == 0 && (!device || device_dispatch_table(device)->CmdEndTransformFeedbackEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdEndTransformFeedbackEXT<Format>);
    if (strcmp(pName, "vkCmdBeginQueryIndexedEXT") == 0 && (!device || device_dispatch_table(device)->CmdBeginQueryIndexedEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdBeginQueryIndexedEXT<Format>);
    if (strcmp(pName, "vkCmdEndQueryIndexedEXT") == 0 && (!device || device_dispatch_table(device)->CmdEndQueryIndexedEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdEndQueryIndexedEXT<Format>);
    if (strcmp(pName, "vkCmdDrawIndirectByteCountEXT") == 0 && (!device || device_dispatch_table(device)->CmdDrawIndirectByteCountEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdDrawIndirectByteCountEXT<Format>);
    if (strcmp(pName, "vkCreateCuModuleNVX") == 0 && (!device || device_dispatch_table(device)->CreateCuModuleNVX))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateCuModuleNVX<Format>);
    if (strcmp(pName, "vkCreateCuFunctionNVX") == 0 && (!device || device_dispatch_table(device)->CreateCuFunctionNVX))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateCuFunctionNVX<Format>);
    if (strcmp(pName, "vkDestroyCuModuleNVX") == 0 && (!device || device_dispatch_table(device)->DestroyCuModuleNVX))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyCuModuleNVX<Format>);
    if (strcmp(pName, "vkDestroyCuFunctionNVX") == 0 && (!device || device_dispatch_table(device)->DestroyCuFunctionNVX))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyCuFunctionNVX<Format>);
    if (strcmp(pName, "vkCmdCuLaunchKernelNVX") == 0 && (!device || device_dispatch_table(device)->CmdCuLaunchKernelNVX))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdCuLaunchKernelNVX<Format>);
    if (strcmp(pName, "vkGetImageViewHandleNVX") == 0 && (!device || device_dispatch_table(device)->GetImageViewHandleNVX))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetImageViewHandleNVX<Format>);
    if (strcmp(pName, "vkGetImageViewHandle64NVX") == 0 && (!device || device_dispatch_table(device)->GetImageViewHandle64NVX))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetImageViewHandle64NVX<Format>);
    if (strcmp(pName, "vkGetImageViewAddressNVX") == 0 && (!device || device_dispatch_table(device)->GetImageViewAddressNVX))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetImageViewAddressNVX<Format>);
    if (strcmp(pName, "vkGetDeviceCombinedImageSamplerIndexNVX") == 0 && (!device || device_dispatch_table(device)->GetDeviceCombinedImageSamplerIndexNVX))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetDeviceCombinedImageSamplerIndexNVX<Format>);
    if (strcmp(pName, "vkCmdDrawIndirectCountAMD") == 0 && (!device || device_dispatch_table(device)->CmdDrawIndirectCountAMD))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdDrawIndirectCountAMD<Format>);
    if (strcmp(pName, "vkCmdDrawIndexedIndirectCountAMD") == 0 && (!device || device_dispatch_table(device)->CmdDrawIndexedIndirectCountAMD))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdDrawIndexedIndirectCountAMD<Format>);
    if (strcmp(pName, "vkGetShaderInfoAMD") == 0 && (!device || device_dispatch_table(device)->GetShaderInfoAMD))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetShaderInfoAMD<Format>);
#if defined(VK_USE_PLATFORM_WIN32_KHR)
    if (strcmp(pName, "vkGetMemoryWin32HandleNV") == 0 && (!device || device_dispatch_table(device)->GetMemoryWin32HandleNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetMemoryWin32HandleNV<Format>);
#endif  // VK_USE_PLATFORM_WIN32_KHR
    if (strcmp(pName, "vkCmdBeginConditionalRenderingEXT") == 0 && (!device || device_dispatch_table(device)->CmdBeginConditionalRenderingEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdBeginConditionalRenderingEXT<Format>);
    if (strcmp(pName, "vkCmdEndConditionalRenderingEXT") == 0 && (!device || device_dispatch_table(device)->CmdEndConditionalRenderingEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdEndConditionalRenderingEXT<Format>);
    if (strcmp(pName, "vkCmdSetViewportWScalingNV") == 0 && (!device || device_dispatch_table(device)->CmdSetViewportWScalingNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetViewportWScalingNV<Format>);
    if (strcmp(pName, "vkDisplayPowerControlEXT") == 0 && (!device || device_dispatch_table(device)->DisplayPowerControlEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDisplayPowerControlEXT<Format>);
    if (strcmp(pName, "vkRegisterDeviceEventEXT") == 0 && (!device || device_dispatch_table(device)->RegisterDeviceEventEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkRegisterDeviceEventEXT<Format>);
    if (strcmp(pName, "vkRegisterDisplayEventEXT") == 0 && (!device || device_dispatch_table(device)->RegisterDisplayEventEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkRegisterDisplayEventEXT<Format>);
    if (strcmp(pName, "vkGetSwapchainCounterEXT") == 0 && (!device || device_dispatch_table(device)->GetSwapchainCounterEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetSwapchainCounterEXT<Format>);
    if (strcmp(pName, "vkGetRefreshCycleDurationGOOGLE") == 0 && (!device || device_dispatch_table(device)->GetRefreshCycleDurationGOOGLE))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetRefreshCycleDurationGOOGLE<Format>);
    if (strcmp(pName, "vkGetPastPresentationTimingGOOGLE") == 0 && (!device || device_dispatch_table(device)->GetPastPresentationTimingGOOGLE))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPastPresentationTimingGOOGLE<Format>);
    if (strcmp(pName, "vkCmdSetDiscardRectangleEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetDiscardRectangleEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetDiscardRectangleEXT<Format>);
    if (strcmp(pName, "vkCmdSetDiscardRectangleEnableEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetDiscardRectangleEnableEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetDiscardRectangleEnableEXT<Format>);
    if (strcmp(pName, "vkCmdSetDiscardRectangleModeEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetDiscardRectangleModeEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetDiscardRectangleModeEXT<Format>);
    if (strcmp(pName, "vkSetHdrMetadataEXT") == 0 && (!device || device_dispatch_table(device)->SetHdrMetadataEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkSetHdrMetadataEXT<Format>);
    if (strcmp(pName, "vkSetDebugUtilsObjectNameEXT") == 0 && (!device || device_dispatch_table(device)->SetDebugUtilsObjectNameEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkSetDebugUtilsObjectNameEXT<Format>);
    if (strcmp(pName, "vkSetDebugUtilsObjectTagEXT") == 0 && (!device || device_dispatch_table(device)->SetDebugUtilsObjectTagEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkSetDebugUtilsObjectTagEXT<Format>);
    if (strcmp(pName, "vkQueueBeginDebugUtilsLabelEXT") == 0 && (!device || device_dispatch_table(device)->QueueBeginDebugUtilsLabelEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkQueueBeginDebugUtilsLabelEXT<Format>);
    if (strcmp(pName, "vkQueueEndDebugUtilsLabelEXT") == 0 && (!device || device_dispatch_table(device)->QueueEndDebugUtilsLabelEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkQueueEndDebugUtilsLabelEXT<Format>);
    if (strcmp(pName, "vkQueueInsertDebugUtilsLabelEXT") == 0 && (!device || device_dispatch_table(device)->QueueInsertDebugUtilsLabelEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkQueueInsertDebugUtilsLabelEXT<Format>);
    if (strcmp(pName, "vkCmdBeginDebugUtilsLabelEXT") == 0 && (!device || device_dispatch_table(device)->CmdBeginDebugUtilsLabelEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdBeginDebugUtilsLabelEXT<Format>);
    if (strcmp(pName, "vkCmdEndDebugUtilsLabelEXT") == 0 && (!device || device_dispatch_table(device)->CmdEndDebugUtilsLabelEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdEndDebugUtilsLabelEXT<Format>);
    if (strcmp(pName, "vkCmdInsertDebugUtilsLabelEXT") == 0 && (!device || device_dispatch_table(device)->CmdInsertDebugUtilsLabelEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdInsertDebugUtilsLabelEXT<Format>);
#if defined(VK_USE_PLATFORM_ANDROID_KHR)
    if (strcmp(pName, "vkGetAndroidHardwareBufferPropertiesANDROID") == 0 && (!device || device_dispatch_table(device)->GetAndroidHardwareBufferPropertiesANDROID))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetAndroidHardwareBufferPropertiesANDROID<Format>);
    if (strcmp(pName, "vkGetMemoryAndroidHardwareBufferANDROID") == 0 && (!device || device_dispatch_table(device)->GetMemoryAndroidHardwareBufferANDROID))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetMemoryAndroidHardwareBufferANDROID<Format>);
#endif  // VK_USE_PLATFORM_ANDROID_KHR
#if defined(VK_ENABLE_BETA_EXTENSIONS)
    if (strcmp(pName, "vkCreateExecutionGraphPipelinesAMDX") == 0 && (!device || device_dispatch_table(device)->CreateExecutionGraphPipelinesAMDX))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateExecutionGraphPipelinesAMDX<Format>);
    if (strcmp(pName, "vkGetExecutionGraphPipelineScratchSizeAMDX") == 0 && (!device || device_dispatch_table(device)->GetExecutionGraphPipelineScratchSizeAMDX))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetExecutionGraphPipelineScratchSizeAMDX<Format>);
    if (strcmp(pName, "vkGetExecutionGraphPipelineNodeIndexAMDX") == 0 && (!device || device_dispatch_table(device)->GetExecutionGraphPipelineNodeIndexAMDX))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetExecutionGraphPipelineNodeIndexAMDX<Format>);
    if (strcmp(pName, "vkCmdInitializeGraphScratchMemoryAMDX") == 0 && (!device || device_dispatch_table(device)->CmdInitializeGraphScratchMemoryAMDX))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdInitializeGraphScratchMemoryAMDX<Format>);
    if (strcmp(pName, "vkCmdDispatchGraphAMDX") == 0 && (!device || device_dispatch_table(device)->CmdDispatchGraphAMDX))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdDispatchGraphAMDX<Format>);
    if (strcmp(pName, "vkCmdDispatchGraphIndirectAMDX") == 0 && (!device || device_dispatch_table(device)->CmdDispatchGraphIndirectAMDX))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdDispatchGraphIndirectAMDX<Format>);
    if (strcmp(pName, "vkCmdDispatchGraphIndirectCountAMDX") == 0 && (!device || device_dispatch_table(device)->CmdDispatchGraphIndirectCountAMDX))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdDispatchGraphIndirectCountAMDX<Format>);
#endif  // VK_ENABLE_BETA_EXTENSIONS
    if (strcmp(pName, "vkWriteSamplerDescriptorsEXT") == 0 && (!device || device_dispatch_table(device)->WriteSamplerDescriptorsEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkWriteSamplerDescriptorsEXT<Format>);
    if (strcmp(pName, "vkWriteResourceDescriptorsEXT") == 0 && (!device || device_dispatch_table(device)->WriteResourceDescriptorsEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkWriteResourceDescriptorsEXT<Format>);
    if (strcmp(pName, "vkCmdBindSamplerHeapEXT") == 0 && (!device || device_dispatch_table(device)->CmdBindSamplerHeapEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdBindSamplerHeapEXT<Format>);
    if (strcmp(pName, "vkCmdBindResourceHeapEXT") == 0 && (!device || device_dispatch_table(device)->CmdBindResourceHeapEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdBindResourceHeapEXT<Format>);
    if (strcmp(pName, "vkCmdPushDataEXT") == 0 && (!device || device_dispatch_table(device)->CmdPushDataEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdPushDataEXT<Format>);
    if (strcmp(pName, "vkGetImageOpaqueCaptureDataEXT") == 0 && (!device || device_dispatch_table(device)->GetImageOpaqueCaptureDataEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetImageOpaqueCaptureDataEXT<Format>);
    if (strcmp(pName, "vkRegisterCustomBorderColorEXT") == 0 && (!device || device_dispatch_table(device)->RegisterCustomBorderColorEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkRegisterCustomBorderColorEXT<Format>);
    if (strcmp(pName, "vkUnregisterCustomBorderColorEXT") == 0 && (!device || device_dispatch_table(device)->UnregisterCustomBorderColorEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkUnregisterCustomBorderColorEXT<Format>);
    if (strcmp(pName, "vkGetTensorOpaqueCaptureDataARM") == 0 && (!device || device_dispatch_table(device)->GetTensorOpaqueCaptureDataARM))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetTensorOpaqueCaptureDataARM<Format>);
    if (strcmp(pName, "vkCmdSetSampleLocationsEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetSampleLocationsEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetSampleLocationsEXT<Format>);
    if (strcmp(pName, "vkGetImageDrmFormatModifierPropertiesEXT") == 0 && (!device || device_dispatch_table(device)->GetImageDrmFormatModifierPropertiesEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetImageDrmFormatModifierPropertiesEXT<Format>);
    if (strcmp(pName, "vkCreateValidationCacheEXT") == 0 && (!device || device_dispatch_table(device)->CreateValidationCacheEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateValidationCacheEXT<Format>);
    if (strcmp(pName, "vkDestroyValidationCacheEXT") == 0 && (!device || device_dispatch_table(device)->DestroyValidationCacheEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyValidationCacheEXT<Format>);
    if (strcmp(pName, "vkMergeValidationCachesEXT") == 0 && (!device || device_dispatch_table(device)->MergeValidationCachesEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkMergeValidationCachesEXT<Format>);
    if (strcmp(pName, "vkGetValidationCacheDataEXT") == 0 && (!device || device_dispatch_table(device)->GetValidationCacheDataEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetValidationCacheDataEXT<Format>);
    if (strcmp(pName, "vkCmdBindShadingRateImageNV") == 0 && (!device || device_dispatch_table(device)->CmdBindShadingRateImageNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdBindShadingRateImageNV<Format>);
    if (strcmp(pName, "vkCmdSetViewportShadingRatePaletteNV") == 0 && (!device || device_dispatch_table(device)->CmdSetViewportShadingRatePaletteNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetViewportShadingRatePaletteNV<Format>);
    if (strcmp(pName, "vkCmdSetCoarseSampleOrderNV") == 0 && (!device || device_dispatch_table(device)->CmdSetCoarseSampleOrderNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetCoarseSampleOrderNV<Format>);
    if (strcmp(pName, "vkCreateAccelerationStructureNV") == 0 && (!device || device_dispatch_table(device)->CreateAccelerationStructureNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateAccelerationStructureNV<Format>);
    if (strcmp(pName, "vkDestroyAccelerationStructureNV") == 0 && (!device || device_dispatch_table(device)->DestroyAccelerationStructureNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyAccelerationStructureNV<Format>);
    if (strcmp(pName, "vkGetAccelerationStructureMemoryRequirementsNV") == 0 && (!device || device_dispatch_table(device)->GetAccelerationStructureMemoryRequirementsNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetAccelerationStructureMemoryRequirementsNV<Format>);
    if (strcmp(pName, "vkBindAccelerationStructureMemoryNV") == 0 && (!device || device_dispatch_table(device)->BindAccelerationStructureMemoryNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkBindAccelerationStructureMemoryNV<Format>);
    if (strcmp(pName, "vkCmdBuildAccelerationStructureNV") == 0 && (!device || device_dispatch_table(device)->CmdBuildAccelerationStructureNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdBuildAccelerationStructureNV<Format>);
    if (strcmp(pName, "vkCmdCopyAccelerationStructureNV") == 0 && (!device || device_dispatch_table(device)->CmdCopyAccelerationStructureNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdCopyAccelerationStructureNV<Format>);
    if (strcmp(pName, "vkCmdTraceRaysNV") == 0 && (!device || device_dispatch_table(device)->CmdTraceRaysNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdTraceRaysNV<Format>);
    if (strcmp(pName, "vkCreateRayTracingPipelinesNV") == 0 && (!device || device_dispatch_table(device)->CreateRayTracingPipelinesNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateRayTracingPipelinesNV<Format>);
    if (strcmp(pName, "vkGetRayTracingShaderGroupHandlesKHR") == 0 && (!device || device_dispatch_table(device)->GetRayTracingShaderGroupHandlesKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetRayTracingShaderGroupHandlesKHR<Format>);
    if (strcmp(pName, "vkGetRayTracingShaderGroupHandlesNV") == 0 && (!device || device_dispatch_table(device)->GetRayTracingShaderGroupHandlesNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetRayTracingShaderGroupHandlesNV<Format>);
    if (strcmp(pName, "vkGetAccelerationStructureHandleNV") == 0 && (!device || device_dispatch_table(device)->GetAccelerationStructureHandleNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetAccelerationStructureHandleNV<Format>);
    if (strcmp(pName, "vkCmdWriteAccelerationStructuresPropertiesNV") == 0 && (!device || device_dispatch_table(device)->CmdWriteAccelerationStructuresPropertiesNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdWriteAccelerationStructuresPropertiesNV<Format>);
    if (strcmp(pName, "vkCompileDeferredNV") == 0 && (!device || device_dispatch_table(device)->CompileDeferredNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCompileDeferredNV<Format>);
    if (strcmp(pName, "vkGetMemoryHostPointerPropertiesEXT") == 0 && (!device || device_dispatch_table(device)->GetMemoryHostPointerPropertiesEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetMemoryHostPointerPropertiesEXT<Format>);
    if (strcmp(pName, "vkCmdWriteBufferMarkerAMD") == 0 && (!device || device_dispatch_table(device)->CmdWriteBufferMarkerAMD))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdWriteBufferMarkerAMD<Format>);
    if (strcmp(pName, "vkCmdWriteBufferMarker2AMD") == 0 && (!device || device_dispatch_table(device)->CmdWriteBufferMarker2AMD))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdWriteBufferMarker2AMD<Format>);
    if (strcmp(pName, "vkGetCalibratedTimestampsEXT") == 0 && (!device || device_dispatch_table(device)->GetCalibratedTimestampsEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetCalibratedTimestampsEXT<Format>);
    if (strcmp(pName, "vkCmdDrawMeshTasksNV") == 0 && (!device || device_dispatch_table(device)->CmdDrawMeshTasksNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdDrawMeshTasksNV<Format>);
    if (strcmp(pName, "vkCmdDrawMeshTasksIndirectNV") == 0 && (!device || device_dispatch_table(device)->CmdDrawMeshTasksIndirectNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdDrawMeshTasksIndirectNV<Format>);
    if (strcmp(pName, "vkCmdDrawMeshTasksIndirectCountNV") == 0 && (!device || device_dispatch_table(device)->CmdDrawMeshTasksIndirectCountNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdDrawMeshTasksIndirectCountNV<Format>);
    if (strcmp(pName, "vkCmdSetExclusiveScissorEnableNV") == 0 && (!device || device_dispatch_table(device)->CmdSetExclusiveScissorEnableNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetExclusiveScissorEnableNV<Format>);
    if (strcmp(pName, "vkCmdSetExclusiveScissorNV") == 0 && (!device || device_dispatch_table(device)->CmdSetExclusiveScissorNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetExclusiveScissorNV<Format>);
    if (strcmp(pName, "vkCmdSetCheckpointNV") == 0 && (!device || device_dispatch_table(device)->CmdSetCheckpointNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetCheckpointNV<Format>);
    if (strcmp(pName, "vkGetQueueCheckpointDataNV") == 0 && (!device || device_dispatch_table(device)->GetQueueCheckpointDataNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetQueueCheckpointDataNV<Format>);
    if (strcmp(pName, "vkGetQueueCheckpointData2NV") == 0 && (!device || device_dispatch_table(device)->GetQueueCheckpointData2NV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetQueueCheckpointData2NV<Format>);
    if (strcmp(pName, "vkSetSwapchainPresentTimingQueueSizeEXT") == 0 && (!device || device_dispatch_table(device)->SetSwapchainPresentTimingQueueSizeEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkSetSwapchainPresentTimingQueueSizeEXT<Format>);
    if (strcmp(pName, "vkGetSwapchainTimingPropertiesEXT") == 0 && (!device || device_dispatch_table(device)->GetSwapchainTimingPropertiesEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetSwapchainTimingPropertiesEXT<Format>);
    if (strcmp(pName, "vkGetSwapchainTimeDomainPropertiesEXT") == 0 && (!device || device_dispatch_table(device)->GetSwapchainTimeDomainPropertiesEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetSwapchainTimeDomainPropertiesEXT<Format>);
    if (strcmp(pName, "vkGetPastPresentationTimingEXT") == 0 && (!device || device_dispatch_table(device)->GetPastPresentationTimingEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPastPresentationTimingEXT<Format>);
    if (strcmp(pName, "vkInitializePerformanceApiINTEL") == 0 && (!device || device_dispatch_table(device)->InitializePerformanceApiINTEL))
        return reinterpret_cast<PFN_vkVoidFunction>(vkInitializePerformanceApiINTEL<Format>);
    if (strcmp(pName, "vkUninitializePerformanceApiINTEL") == 0 && (!device || device_dispatch_table(device)->UninitializePerformanceApiINTEL))
        return reinterpret_cast<PFN_vkVoidFunction>(vkUninitializePerformanceApiINTEL<Format>);
    if (strcmp(pName, "vkCmdSetPerformanceMarkerINTEL") == 0 && (!device || device_dispatch_table(device)->CmdSetPerformanceMarkerINTEL))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetPerformanceMarkerINTEL<Format>);
    if (strcmp(pName, "vkCmdSetPerformanceStreamMarkerINTEL") == 0 && (!device || device_dispatch_table(device)->CmdSetPerformanceStreamMarkerINTEL))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetPerformanceStreamMarkerINTEL<Format>);
    if (strcmp(pName, "vkCmdSetPerformanceOverrideINTEL") == 0 && (!device || device_dispatch_table(device)->CmdSetPerformanceOverrideINTEL))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetPerformanceOverrideINTEL<Format>);
    if (strcmp(pName, "vkAcquirePerformanceConfigurationINTEL") == 0 && (!device || device_dispatch_table(device)->AcquirePerformanceConfigurationINTEL))
        return reinterpret_cast<PFN_vkVoidFunction>(vkAcquirePerformanceConfigurationINTEL<Format>);
    if (strcmp(pName, "vkReleasePerformanceConfigurationINTEL") == 0 && (!device || device_dispatch_table(device)->ReleasePerformanceConfigurationINTEL))
        return reinterpret_cast<PFN_vkVoidFunction>(vkReleasePerformanceConfigurationINTEL<Format>);
    if (strcmp(pName, "vkQueueSetPerformanceConfigurationINTEL") == 0 && (!device || device_dispatch_table(device)->QueueSetPerformanceConfigurationINTEL))
        return reinterpret_cast<PFN_vkVoidFunction>(vkQueueSetPerformanceConfigurationINTEL<Format>);
    if (strcmp(pName, "vkGetPerformanceParameterINTEL") == 0 && (!device || device_dispatch_table(device)->GetPerformanceParameterINTEL))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPerformanceParameterINTEL<Format>);
    if (strcmp(pName, "vkSetLocalDimmingAMD") == 0 && (!device || device_dispatch_table(device)->SetLocalDimmingAMD))
        return reinterpret_cast<PFN_vkVoidFunction>(vkSetLocalDimmingAMD<Format>);
    if (strcmp(pName, "vkGetBufferDeviceAddressEXT") == 0 && (!device || device_dispatch_table(device)->GetBufferDeviceAddressEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetBufferDeviceAddressEXT<Format>);
#if defined(VK_USE_PLATFORM_WIN32_KHR)
    if (strcmp(pName, "vkAcquireFullScreenExclusiveModeEXT") == 0 && (!device || device_dispatch_table(device)->AcquireFullScreenExclusiveModeEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkAcquireFullScreenExclusiveModeEXT<Format>);
    if (strcmp(pName, "vkReleaseFullScreenExclusiveModeEXT") == 0 && (!device || device_dispatch_table(device)->ReleaseFullScreenExclusiveModeEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkReleaseFullScreenExclusiveModeEXT<Format>);
    if (strcmp(pName, "vkGetDeviceGroupSurfacePresentModes2EXT") == 0 && (!device || device_dispatch_table(device)->GetDeviceGroupSurfacePresentModes2EXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetDeviceGroupSurfacePresentModes2EXT<Format>);
#endif  // VK_USE_PLATFORM_WIN32_KHR
    if (strcmp(pName, "vkCmdSetLineStippleEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetLineStippleEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetLineStippleEXT<Format>);
    if (strcmp(pName, "vkResetQueryPoolEXT") == 0 && (!device || device_dispatch_table(device)->ResetQueryPoolEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkResetQueryPoolEXT<Format>);
    if (strcmp(pName, "vkCmdSetCullModeEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetCullModeEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetCullModeEXT<Format>);
    if (strcmp(pName, "vkCmdSetFrontFaceEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetFrontFaceEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetFrontFaceEXT<Format>);
    if (strcmp(pName, "vkCmdSetPrimitiveTopologyEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetPrimitiveTopologyEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetPrimitiveTopologyEXT<Format>);
    if (strcmp(pName, "vkCmdSetViewportWithCountEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetViewportWithCountEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetViewportWithCountEXT<Format>);
    if (strcmp(pName, "vkCmdSetScissorWithCountEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetScissorWithCountEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetScissorWithCountEXT<Format>);
    if (strcmp(pName, "vkCmdBindVertexBuffers2EXT") == 0 && (!device || device_dispatch_table(device)->CmdBindVertexBuffers2EXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdBindVertexBuffers2EXT<Format>);
    if (strcmp(pName, "vkCmdSetDepthTestEnableEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetDepthTestEnableEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetDepthTestEnableEXT<Format>);
    if (strcmp(pName, "vkCmdSetDepthWriteEnableEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetDepthWriteEnableEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetDepthWriteEnableEXT<Format>);
    if (strcmp(pName, "vkCmdSetDepthCompareOpEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetDepthCompareOpEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetDepthCompareOpEXT<Format>);
    if (strcmp(pName, "vkCmdSetDepthBoundsTestEnableEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetDepthBoundsTestEnableEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetDepthBoundsTestEnableEXT<Format>);
    if (strcmp(pName, "vkCmdSetStencilTestEnableEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetStencilTestEnableEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetStencilTestEnableEXT<Format>);
    if (strcmp(pName, "vkCmdSetStencilOpEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetStencilOpEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetStencilOpEXT<Format>);
    if (strcmp(pName, "vkCopyMemoryToImageEXT") == 0 && (!device || device_dispatch_table(device)->CopyMemoryToImageEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCopyMemoryToImageEXT<Format>);
    if (strcmp(pName, "vkCopyImageToMemoryEXT") == 0 && (!device || device_dispatch_table(device)->CopyImageToMemoryEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCopyImageToMemoryEXT<Format>);
    if (strcmp(pName, "vkCopyImageToImageEXT") == 0 && (!device || device_dispatch_table(device)->CopyImageToImageEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCopyImageToImageEXT<Format>);
    if (strcmp(pName, "vkTransitionImageLayoutEXT") == 0 && (!device || device_dispatch_table(device)->TransitionImageLayoutEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkTransitionImageLayoutEXT<Format>);
    if (strcmp(pName, "vkGetImageSubresourceLayout2EXT") == 0 && (!device || device_dispatch_table(device)->GetImageSubresourceLayout2EXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetImageSubresourceLayout2EXT<Format>);
    if (strcmp(pName, "vkReleaseSwapchainImagesEXT") == 0 && (!device || device_dispatch_table(device)->ReleaseSwapchainImagesEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkReleaseSwapchainImagesEXT<Format>);
    if (strcmp(pName, "vkGetGeneratedCommandsMemoryRequirementsNV") == 0 && (!device || device_dispatch_table(device)->GetGeneratedCommandsMemoryRequirementsNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetGeneratedCommandsMemoryRequirementsNV<Format>);
    if (strcmp(pName, "vkCmdPreprocessGeneratedCommandsNV") == 0 && (!device || device_dispatch_table(device)->CmdPreprocessGeneratedCommandsNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdPreprocessGeneratedCommandsNV<Format>);
    if (strcmp(pName, "vkCmdExecuteGeneratedCommandsNV") == 0 && (!device || device_dispatch_table(device)->CmdExecuteGeneratedCommandsNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdExecuteGeneratedCommandsNV<Format>);
    if (strcmp(pName, "vkCmdBindPipelineShaderGroupNV") == 0 && (!device || device_dispatch_table(device)->CmdBindPipelineShaderGroupNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdBindPipelineShaderGroupNV<Format>);
    if (strcmp(pName, "vkCreateIndirectCommandsLayoutNV") == 0 && (!device || device_dispatch_table(device)->CreateIndirectCommandsLayoutNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateIndirectCommandsLayoutNV<Format>);
    if (strcmp(pName, "vkDestroyIndirectCommandsLayoutNV") == 0 && (!device || device_dispatch_table(device)->DestroyIndirectCommandsLayoutNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyIndirectCommandsLayoutNV<Format>);
    if (strcmp(pName, "vkCmdSetDepthBias2EXT") == 0 && (!device || device_dispatch_table(device)->CmdSetDepthBias2EXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetDepthBias2EXT<Format>);
    if (strcmp(pName, "vkCreatePrivateDataSlotEXT") == 0 && (!device || device_dispatch_table(device)->CreatePrivateDataSlotEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreatePrivateDataSlotEXT<Format>);
    if (strcmp(pName, "vkDestroyPrivateDataSlotEXT") == 0 && (!device || device_dispatch_table(device)->DestroyPrivateDataSlotEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyPrivateDataSlotEXT<Format>);
    if (strcmp(pName, "vkSetPrivateDataEXT") == 0 && (!device || device_dispatch_table(device)->SetPrivateDataEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkSetPrivateDataEXT<Format>);
    if (strcmp(pName, "vkGetPrivateDataEXT") == 0 && (!device || device_dispatch_table(device)->GetPrivateDataEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPrivateDataEXT<Format>);
#if defined(VK_ENABLE_BETA_EXTENSIONS)
    if (strcmp(pName, "vkCreateCudaModuleNV") == 0 && (!device || device_dispatch_table(device)->CreateCudaModuleNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateCudaModuleNV<Format>);
    if (strcmp(pName, "vkGetCudaModuleCacheNV") == 0 && (!device || device_dispatch_table(device)->GetCudaModuleCacheNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetCudaModuleCacheNV<Format>);
    if (strcmp(pName, "vkCreateCudaFunctionNV") == 0 && (!device || device_dispatch_table(device)->CreateCudaFunctionNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateCudaFunctionNV<Format>);
    if (strcmp(pName, "vkDestroyCudaModuleNV") == 0 && (!device || device_dispatch_table(device)->DestroyCudaModuleNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyCudaModuleNV<Format>);
    if (strcmp(pName, "vkDestroyCudaFunctionNV") == 0 && (!device || device_dispatch_table(device)->DestroyCudaFunctionNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyCudaFunctionNV<Format>);
    if (strcmp(pName, "vkCmdCudaLaunchKernelNV") == 0 && (!device || device_dispatch_table(device)->CmdCudaLaunchKernelNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdCudaLaunchKernelNV<Format>);
#endif  // VK_ENABLE_BETA_EXTENSIONS
    if (strcmp(pName, "vkCmdDispatchTileQCOM") == 0 && (!device || device_dispatch_table(device)->CmdDispatchTileQCOM))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdDispatchTileQCOM<Format>);
    if (strcmp(pName, "vkCmdBeginPerTileExecutionQCOM") == 0 && (!device || device_dispatch_table(device)->CmdBeginPerTileExecutionQCOM))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdBeginPerTileExecutionQCOM<Format>);
    if (strcmp(pName, "vkCmdEndPerTileExecutionQCOM") == 0 && (!device || device_dispatch_table(device)->CmdEndPerTileExecutionQCOM))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdEndPerTileExecutionQCOM<Format>);
#if defined(VK_USE_PLATFORM_METAL_EXT)
    if (strcmp(pName, "vkExportMetalObjectsEXT") == 0 && (!device || device_dispatch_table(device)->ExportMetalObjectsEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkExportMetalObjectsEXT<Format>);
#endif  // VK_USE_PLATFORM_METAL_EXT
    if (strcmp(pName, "vkGetDescriptorSetLayoutSizeEXT") == 0 && (!device || device_dispatch_table(device)->GetDescriptorSetLayoutSizeEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetDescriptorSetLayoutSizeEXT<Format>);
    if (strcmp(pName, "vkGetDescriptorSetLayoutBindingOffsetEXT") == 0 && (!device || device_dispatch_table(device)->GetDescriptorSetLayoutBindingOffsetEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetDescriptorSetLayoutBindingOffsetEXT<Format>);
    if (strcmp(pName, "vkGetDescriptorEXT") == 0 && (!device || device_dispatch_table(device)->GetDescriptorEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetDescriptorEXT<Format>);
    if (strcmp(pName, "vkCmdBindDescriptorBuffersEXT") == 0 && (!device || device_dispatch_table(device)->CmdBindDescriptorBuffersEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdBindDescriptorBuffersEXT<Format>);
    if (strcmp(pName, "vkCmdSetDescriptorBufferOffsetsEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetDescriptorBufferOffsetsEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetDescriptorBufferOffsetsEXT<Format>);
    if (strcmp(pName, "vkCmdBindDescriptorBufferEmbeddedSamplersEXT") == 0 && (!device || device_dispatch_table(device)->CmdBindDescriptorBufferEmbeddedSamplersEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdBindDescriptorBufferEmbeddedSamplersEXT<Format>);
    if (strcmp(pName, "vkGetBufferOpaqueCaptureDescriptorDataEXT") == 0 && (!device || device_dispatch_table(device)->GetBufferOpaqueCaptureDescriptorDataEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetBufferOpaqueCaptureDescriptorDataEXT<Format>);
    if (strcmp(pName, "vkGetImageOpaqueCaptureDescriptorDataEXT") == 0 && (!device || device_dispatch_table(device)->GetImageOpaqueCaptureDescriptorDataEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetImageOpaqueCaptureDescriptorDataEXT<Format>);
    if (strcmp(pName, "vkGetImageViewOpaqueCaptureDescriptorDataEXT") == 0 && (!device || device_dispatch_table(device)->GetImageViewOpaqueCaptureDescriptorDataEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetImageViewOpaqueCaptureDescriptorDataEXT<Format>);
    if (strcmp(pName, "vkGetSamplerOpaqueCaptureDescriptorDataEXT") == 0 && (!device || device_dispatch_table(device)->GetSamplerOpaqueCaptureDescriptorDataEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetSamplerOpaqueCaptureDescriptorDataEXT<Format>);
    if (strcmp(pName, "vkGetAccelerationStructureOpaqueCaptureDescriptorDataEXT") == 0 && (!device || device_dispatch_table(device)->GetAccelerationStructureOpaqueCaptureDescriptorDataEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetAccelerationStructureOpaqueCaptureDescriptorDataEXT<Format>);
    if (strcmp(pName, "vkCmdSetFragmentShadingRateEnumNV") == 0 && (!device || device_dispatch_table(device)->CmdSetFragmentShadingRateEnumNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetFragmentShadingRateEnumNV<Format>);
    if (strcmp(pName, "vkGetDeviceFaultInfoEXT") == 0 && (!device || device_dispatch_table(device)->GetDeviceFaultInfoEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetDeviceFaultInfoEXT<Format>);
    if (strcmp(pName, "vkCmdSetVertexInputEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetVertexInputEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetVertexInputEXT<Format>);
#if defined(VK_USE_PLATFORM_FUCHSIA)
    if (strcmp(pName, "vkGetMemoryZirconHandleFUCHSIA") == 0 && (!device || device_dispatch_table(device)->GetMemoryZirconHandleFUCHSIA))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetMemoryZirconHandleFUCHSIA<Format>);
    if (strcmp(pName, "vkGetMemoryZirconHandlePropertiesFUCHSIA") == 0 && (!device || device_dispatch_table(device)->GetMemoryZirconHandlePropertiesFUCHSIA))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetMemoryZirconHandlePropertiesFUCHSIA<Format>);
    if (strcmp(pName, "vkImportSemaphoreZirconHandleFUCHSIA") == 0 && (!device || device_dispatch_table(device)->ImportSemaphoreZirconHandleFUCHSIA))
        return reinterpret_cast<PFN_vkVoidFunction>(vkImportSemaphoreZirconHandleFUCHSIA<Format>);
    if (strcmp(pName, "vkGetSemaphoreZirconHandleFUCHSIA") == 0 && (!device || device_dispatch_table(device)->GetSemaphoreZirconHandleFUCHSIA))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetSemaphoreZirconHandleFUCHSIA<Format>);
    if (strcmp(pName, "vkCreateBufferCollectionFUCHSIA") == 0 && (!device || device_dispatch_table(device)->CreateBufferCollectionFUCHSIA))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateBufferCollectionFUCHSIA<Format>);
    if (strcmp(pName, "vkSetBufferCollectionImageConstraintsFUCHSIA") == 0 && (!device || device_dispatch_table(device)->SetBufferCollectionImageConstraintsFUCHSIA))
        return reinterpret_cast<PFN_vkVoidFunction>(vkSetBufferCollectionImageConstraintsFUCHSIA<Format>);
    if (strcmp(pName, "vkSetBufferCollectionBufferConstraintsFUCHSIA") == 0 && (!device || device_dispatch_table(device)->SetBufferCollectionBufferConstraintsFUCHSIA))
        return reinterpret_cast<PFN_vkVoidFunction>(vkSetBufferCollectionBufferConstraintsFUCHSIA<Format>);
    if (strcmp(pName, "vkDestroyBufferCollectionFUCHSIA") == 0 && (!device || device_dispatch_table(device)->DestroyBufferCollectionFUCHSIA))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyBufferCollectionFUCHSIA<Format>);
    if (strcmp(pName, "vkGetBufferCollectionPropertiesFUCHSIA") == 0 && (!device || device_dispatch_table(device)->GetBufferCollectionPropertiesFUCHSIA))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetBufferCollectionPropertiesFUCHSIA<Format>);
#endif  // VK_USE_PLATFORM_FUCHSIA
    if (strcmp(pName, "vkGetDeviceSubpassShadingMaxWorkgroupSizeHUAWEI") == 0 && (!device || device_dispatch_table(device)->GetDeviceSubpassShadingMaxWorkgroupSizeHUAWEI))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetDeviceSubpassShadingMaxWorkgroupSizeHUAWEI<Format>);
    if (strcmp(pName, "vkCmdSubpassShadingHUAWEI") == 0 && (!device || device_dispatch_table(device)->CmdSubpassShadingHUAWEI))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSubpassShadingHUAWEI<Format>);
    if (strcmp(pName, "vkCmdBindInvocationMaskHUAWEI") == 0 && (!device || device_dispatch_table(device)->CmdBindInvocationMaskHUAWEI))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdBindInvocationMaskHUAWEI<Format>);
    if (strcmp(pName, "vkGetMemoryRemoteAddressNV") == 0 && (!device || device_dispatch_table(device)->GetMemoryRemoteAddressNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetMemoryRemoteAddressNV<Format>);
    if (strcmp(pName, "vkGetPipelinePropertiesEXT") == 0 && (!device || device_dispatch_table(device)->GetPipelinePropertiesEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPipelinePropertiesEXT<Format>);
    if (strcmp(pName, "vkCmdSetPatchControlPointsEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetPatchControlPointsEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetPatchControlPointsEXT<Format>);
    if (strcmp(pName, "vkCmdSetRasterizerDiscardEnableEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetRasterizerDiscardEnableEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetRasterizerDiscardEnableEXT<Format>);
    if (strcmp(pName, "vkCmdSetDepthBiasEnableEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetDepthBiasEnableEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetDepthBiasEnableEXT<Format>);
    if (strcmp(pName, "vkCmdSetLogicOpEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetLogicOpEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetLogicOpEXT<Format>);
    if (strcmp(pName, "vkCmdSetPrimitiveRestartEnableEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetPrimitiveRestartEnableEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetPrimitiveRestartEnableEXT<Format>);
    if (strcmp(pName, "vkCmdSetColorWriteEnableEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetColorWriteEnableEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetColorWriteEnableEXT<Format>);
    if (strcmp(pName, "vkCmdDrawMultiEXT") == 0 && (!device || device_dispatch_table(device)->CmdDrawMultiEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdDrawMultiEXT<Format>);
    if (strcmp(pName, "vkCmdDrawMultiIndexedEXT") == 0 && (!device || device_dispatch_table(device)->CmdDrawMultiIndexedEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdDrawMultiIndexedEXT<Format>);
    if (strcmp(pName, "vkCreateMicromapEXT") == 0 && (!device || device_dispatch_table(device)->CreateMicromapEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateMicromapEXT<Format>);
    if (strcmp(pName, "vkDestroyMicromapEXT") == 0 && (!device || device_dispatch_table(device)->DestroyMicromapEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyMicromapEXT<Format>);
    if (strcmp(pName, "vkCmdBuildMicromapsEXT") == 0 && (!device || device_dispatch_table(device)->CmdBuildMicromapsEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdBuildMicromapsEXT<Format>);
    if (strcmp(pName, "vkBuildMicromapsEXT") == 0 && (!device || device_dispatch_table(device)->BuildMicromapsEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkBuildMicromapsEXT<Format>);
    if (strcmp(pName, "vkCopyMicromapEXT") == 0 && (!device || device_dispatch_table(device)->CopyMicromapEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCopyMicromapEXT<Format>);
    if (strcmp(pName, "vkCopyMicromapToMemoryEXT") == 0 && (!device || device_dispatch_table(device)->CopyMicromapToMemoryEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCopyMicromapToMemoryEXT<Format>);
    if (strcmp(pName, "vkCopyMemoryToMicromapEXT") == 0 && (!device || device_dispatch_table(device)->CopyMemoryToMicromapEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCopyMemoryToMicromapEXT<Format>);
    if (strcmp(pName, "vkWriteMicromapsPropertiesEXT") == 0 && (!device || device_dispatch_table(device)->WriteMicromapsPropertiesEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkWriteMicromapsPropertiesEXT<Format>);
    if (strcmp(pName, "vkCmdCopyMicromapEXT") == 0 && (!device || device_dispatch_table(device)->CmdCopyMicromapEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdCopyMicromapEXT<Format>);
    if (strcmp(pName, "vkCmdCopyMicromapToMemoryEXT") == 0 && (!device || device_dispatch_table(device)->CmdCopyMicromapToMemoryEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdCopyMicromapToMemoryEXT<Format>);
    if (strcmp(pName, "vkCmdCopyMemoryToMicromapEXT") == 0 && (!device || device_dispatch_table(device)->CmdCopyMemoryToMicromapEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdCopyMemoryToMicromapEXT<Format>);
    if (strcmp(pName, "vkCmdWriteMicromapsPropertiesEXT") == 0 && (!device || device_dispatch_table(device)->CmdWriteMicromapsPropertiesEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdWriteMicromapsPropertiesEXT<Format>);
    if (strcmp(pName, "vkGetDeviceMicromapCompatibilityEXT") == 0 && (!device || device_dispatch_table(device)->GetDeviceMicromapCompatibilityEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetDeviceMicromapCompatibilityEXT<Format>);
    if (strcmp(pName, "vkGetMicromapBuildSizesEXT") == 0 && (!device || device_dispatch_table(device)->GetMicromapBuildSizesEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetMicromapBuildSizesEXT<Format>);
    if (strcmp(pName, "vkCmdDrawClusterHUAWEI") == 0 && (!device || device_dispatch_table(device)->CmdDrawClusterHUAWEI))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdDrawClusterHUAWEI<Format>);
    if (strcmp(pName, "vkCmdDrawClusterIndirectHUAWEI") == 0 && (!device || device_dispatch_table(device)->CmdDrawClusterIndirectHUAWEI))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdDrawClusterIndirectHUAWEI<Format>);
    if (strcmp(pName, "vkSetDeviceMemoryPriorityEXT") == 0 && (!device || device_dispatch_table(device)->SetDeviceMemoryPriorityEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkSetDeviceMemoryPriorityEXT<Format>);
    if (strcmp(pName, "vkGetDescriptorSetLayoutHostMappingInfoVALVE") == 0 && (!device || device_dispatch_table(device)->GetDescriptorSetLayoutHostMappingInfoVALVE))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetDescriptorSetLayoutHostMappingInfoVALVE<Format>);
    if (strcmp(pName, "vkGetDescriptorSetHostMappingVALVE") == 0 && (!device || device_dispatch_table(device)->GetDescriptorSetHostMappingVALVE))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetDescriptorSetHostMappingVALVE<Format>);
    if (strcmp(pName, "vkCmdCopyMemoryIndirectNV") == 0 && (!device || device_dispatch_table(device)->CmdCopyMemoryIndirectNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdCopyMemoryIndirectNV<Format>);
    if (strcmp(pName, "vkCmdCopyMemoryToImageIndirectNV") == 0 && (!device || device_dispatch_table(device)->CmdCopyMemoryToImageIndirectNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdCopyMemoryToImageIndirectNV<Format>);
    if (strcmp(pName, "vkCmdDecompressMemoryNV") == 0 && (!device || device_dispatch_table(device)->CmdDecompressMemoryNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdDecompressMemoryNV<Format>);
    if (strcmp(pName, "vkCmdDecompressMemoryIndirectCountNV") == 0 && (!device || device_dispatch_table(device)->CmdDecompressMemoryIndirectCountNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdDecompressMemoryIndirectCountNV<Format>);
    if (strcmp(pName, "vkGetPipelineIndirectMemoryRequirementsNV") == 0 && (!device || device_dispatch_table(device)->GetPipelineIndirectMemoryRequirementsNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPipelineIndirectMemoryRequirementsNV<Format>);
    if (strcmp(pName, "vkCmdUpdatePipelineIndirectBufferNV") == 0 && (!device || device_dispatch_table(device)->CmdUpdatePipelineIndirectBufferNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdUpdatePipelineIndirectBufferNV<Format>);
    if (strcmp(pName, "vkGetPipelineIndirectDeviceAddressNV") == 0 && (!device || device_dispatch_table(device)->GetPipelineIndirectDeviceAddressNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPipelineIndirectDeviceAddressNV<Format>);
#if defined(VK_USE_PLATFORM_OHOS)
    if (strcmp(pName, "vkGetNativeBufferPropertiesOHOS") == 0 && (!device || device_dispatch_table(device)->GetNativeBufferPropertiesOHOS))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetNativeBufferPropertiesOHOS<Format>);
    if (strcmp(pName, "vkGetMemoryNativeBufferOHOS") == 0 && (!device || device_dispatch_table(device)->GetMemoryNativeBufferOHOS))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetMemoryNativeBufferOHOS<Format>);
#endif  // VK_USE_PLATFORM_OHOS
    if (strcmp(pName, "vkCmdSetDepthClampEnableEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetDepthClampEnableEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetDepthClampEnableEXT<Format>);
    if (strcmp(pName, "vkCmdSetPolygonModeEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetPolygonModeEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetPolygonModeEXT<Format>);
    if (strcmp(pName, "vkCmdSetRasterizationSamplesEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetRasterizationSamplesEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetRasterizationSamplesEXT<Format>);
    if (strcmp(pName, "vkCmdSetSampleMaskEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetSampleMaskEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetSampleMaskEXT<Format>);
    if (strcmp(pName, "vkCmdSetAlphaToCoverageEnableEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetAlphaToCoverageEnableEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetAlphaToCoverageEnableEXT<Format>);
    if (strcmp(pName, "vkCmdSetAlphaToOneEnableEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetAlphaToOneEnableEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetAlphaToOneEnableEXT<Format>);
    if (strcmp(pName, "vkCmdSetLogicOpEnableEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetLogicOpEnableEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetLogicOpEnableEXT<Format>);
    if (strcmp(pName, "vkCmdSetColorBlendEnableEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetColorBlendEnableEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetColorBlendEnableEXT<Format>);
    if (strcmp(pName, "vkCmdSetColorBlendEquationEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetColorBlendEquationEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetColorBlendEquationEXT<Format>);
    if (strcmp(pName, "vkCmdSetColorWriteMaskEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetColorWriteMaskEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetColorWriteMaskEXT<Format>);
    if (strcmp(pName, "vkCmdSetTessellationDomainOriginEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetTessellationDomainOriginEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetTessellationDomainOriginEXT<Format>);
    if (strcmp(pName, "vkCmdSetRasterizationStreamEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetRasterizationStreamEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetRasterizationStreamEXT<Format>);
    if (strcmp(pName, "vkCmdSetConservativeRasterizationModeEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetConservativeRasterizationModeEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetConservativeRasterizationModeEXT<Format>);
    if (strcmp(pName, "vkCmdSetExtraPrimitiveOverestimationSizeEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetExtraPrimitiveOverestimationSizeEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetExtraPrimitiveOverestimationSizeEXT<Format>);
    if (strcmp(pName, "vkCmdSetDepthClipEnableEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetDepthClipEnableEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetDepthClipEnableEXT<Format>);
    if (strcmp(pName, "vkCmdSetSampleLocationsEnableEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetSampleLocationsEnableEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetSampleLocationsEnableEXT<Format>);
    if (strcmp(pName, "vkCmdSetColorBlendAdvancedEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetColorBlendAdvancedEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetColorBlendAdvancedEXT<Format>);
    if (strcmp(pName, "vkCmdSetProvokingVertexModeEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetProvokingVertexModeEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetProvokingVertexModeEXT<Format>);
    if (strcmp(pName, "vkCmdSetLineRasterizationModeEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetLineRasterizationModeEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetLineRasterizationModeEXT<Format>);
    if (strcmp(pName, "vkCmdSetLineStippleEnableEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetLineStippleEnableEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetLineStippleEnableEXT<Format>);
    if (strcmp(pName, "vkCmdSetDepthClipNegativeOneToOneEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetDepthClipNegativeOneToOneEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetDepthClipNegativeOneToOneEXT<Format>);
    if (strcmp(pName, "vkCmdSetViewportWScalingEnableNV") == 0 && (!device || device_dispatch_table(device)->CmdSetViewportWScalingEnableNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetViewportWScalingEnableNV<Format>);
    if (strcmp(pName, "vkCmdSetViewportSwizzleNV") == 0 && (!device || device_dispatch_table(device)->CmdSetViewportSwizzleNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetViewportSwizzleNV<Format>);
    if (strcmp(pName, "vkCmdSetCoverageToColorEnableNV") == 0 && (!device || device_dispatch_table(device)->CmdSetCoverageToColorEnableNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetCoverageToColorEnableNV<Format>);
    if (strcmp(pName, "vkCmdSetCoverageToColorLocationNV") == 0 && (!device || device_dispatch_table(device)->CmdSetCoverageToColorLocationNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetCoverageToColorLocationNV<Format>);
    if (strcmp(pName, "vkCmdSetCoverageModulationModeNV") == 0 && (!device || device_dispatch_table(device)->CmdSetCoverageModulationModeNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetCoverageModulationModeNV<Format>);
    if (strcmp(pName, "vkCmdSetCoverageModulationTableEnableNV") == 0 && (!device || device_dispatch_table(device)->CmdSetCoverageModulationTableEnableNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetCoverageModulationTableEnableNV<Format>);
    if (strcmp(pName, "vkCmdSetCoverageModulationTableNV") == 0 && (!device || device_dispatch_table(device)->CmdSetCoverageModulationTableNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetCoverageModulationTableNV<Format>);
    if (strcmp(pName, "vkCmdSetShadingRateImageEnableNV") == 0 && (!device || device_dispatch_table(device)->CmdSetShadingRateImageEnableNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetShadingRateImageEnableNV<Format>);
    if (strcmp(pName, "vkCmdSetRepresentativeFragmentTestEnableNV") == 0 && (!device || device_dispatch_table(device)->CmdSetRepresentativeFragmentTestEnableNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetRepresentativeFragmentTestEnableNV<Format>);
    if (strcmp(pName, "vkCmdSetCoverageReductionModeNV") == 0 && (!device || device_dispatch_table(device)->CmdSetCoverageReductionModeNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetCoverageReductionModeNV<Format>);
    if (strcmp(pName, "vkCreateTensorARM") == 0 && (!device || device_dispatch_table(device)->CreateTensorARM))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateTensorARM<Format>);
    if (strcmp(pName, "vkDestroyTensorARM") == 0 && (!device || device_dispatch_table(device)->DestroyTensorARM))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyTensorARM<Format>);
    if (strcmp(pName, "vkCreateTensorViewARM") == 0 && (!device || device_dispatch_table(device)->CreateTensorViewARM))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateTensorViewARM<Format>);
    if (strcmp(pName, "vkDestroyTensorViewARM") == 0 && (!device || device_dispatch_table(device)->DestroyTensorViewARM))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyTensorViewARM<Format>);
    if (strcmp(pName, "vkGetTensorMemoryRequirementsARM") == 0 && (!device || device_dispatch_table(device)->GetTensorMemoryRequirementsARM))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetTensorMemoryRequirementsARM<Format>);
    if (strcmp(pName, "vkBindTensorMemoryARM") == 0 && (!device || device_dispatch_table(device)->BindTensorMemoryARM))
        return reinterpret_cast<PFN_vkVoidFunction>(vkBindTensorMemoryARM<Format>);
    if (strcmp(pName, "vkGetDeviceTensorMemoryRequirementsARM") == 0 && (!device || device_dispatch_table(device)->GetDeviceTensorMemoryRequirementsARM))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetDeviceTensorMemoryRequirementsARM<Format>);
    if (strcmp(pName, "vkCmdCopyTensorARM") == 0 && (!device || device_dispatch_table(device)->CmdCopyTensorARM))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdCopyTensorARM<Format>);
    if (strcmp(pName, "vkGetTensorOpaqueCaptureDescriptorDataARM") == 0 && (!device || device_dispatch_table(device)->GetTensorOpaqueCaptureDescriptorDataARM))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetTensorOpaqueCaptureDescriptorDataARM<Format>);
    if (strcmp(pName, "vkGetTensorViewOpaqueCaptureDescriptorDataARM") == 0 && (!device || device_dispatch_table(device)->GetTensorViewOpaqueCaptureDescriptorDataARM))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetTensorViewOpaqueCaptureDescriptorDataARM<Format>);
    if (strcmp(pName, "vkGetShaderModuleIdentifierEXT") == 0 && (!device || device_dispatch_table(device)->GetShaderModuleIdentifierEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetShaderModuleIdentifierEXT<Format>);
    if (strcmp(pName, "vkGetShaderModuleCreateInfoIdentifierEXT") == 0 && (!device || device_dispatch_table(device)->GetShaderModuleCreateInfoIdentifierEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetShaderModuleCreateInfoIdentifierEXT<Format>);
    if (strcmp(pName, "vkCreateOpticalFlowSessionNV") == 0 && (!device || device_dispatch_table(device)->CreateOpticalFlowSessionNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateOpticalFlowSessionNV<Format>);
    if (strcmp(pName, "vkDestroyOpticalFlowSessionNV") == 0 && (!device || device_dispatch_table(device)->DestroyOpticalFlowSessionNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyOpticalFlowSessionNV<Format>);
    if (strcmp(pName, "vkBindOpticalFlowSessionImageNV") == 0 && (!device || device_dispatch_table(device)->BindOpticalFlowSessionImageNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkBindOpticalFlowSessionImageNV<Format>);
    if (strcmp(pName, "vkCmdOpticalFlowExecuteNV") == 0 && (!device || device_dispatch_table(device)->CmdOpticalFlowExecuteNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdOpticalFlowExecuteNV<Format>);
    if (strcmp(pName, "vkAntiLagUpdateAMD") == 0 && (!device || device_dispatch_table(device)->AntiLagUpdateAMD))
        return reinterpret_cast<PFN_vkVoidFunction>(vkAntiLagUpdateAMD<Format>);
    if (strcmp(pName, "vkCreateShadersEXT") == 0 && (!device || device_dispatch_table(device)->CreateShadersEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateShadersEXT<Format>);
    if (strcmp(pName, "vkDestroyShaderEXT") == 0 && (!device || device_dispatch_table(device)->DestroyShaderEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyShaderEXT<Format>);
    if (strcmp(pName, "vkGetShaderBinaryDataEXT") == 0 && (!device || device_dispatch_table(device)->GetShaderBinaryDataEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetShaderBinaryDataEXT<Format>);
    if (strcmp(pName, "vkCmdBindShadersEXT") == 0 && (!device || device_dispatch_table(device)->CmdBindShadersEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdBindShadersEXT<Format>);
    if (strcmp(pName, "vkCmdSetDepthClampRangeEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetDepthClampRangeEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetDepthClampRangeEXT<Format>);
    if (strcmp(pName, "vkGetFramebufferTilePropertiesQCOM") == 0 && (!device || device_dispatch_table(device)->GetFramebufferTilePropertiesQCOM))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetFramebufferTilePropertiesQCOM<Format>);
    if (strcmp(pName, "vkGetDynamicRenderingTilePropertiesQCOM") == 0 && (!device || device_dispatch_table(device)->GetDynamicRenderingTilePropertiesQCOM))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetDynamicRenderingTilePropertiesQCOM<Format>);
    if (strcmp(pName, "vkConvertCooperativeVectorMatrixNV") == 0 && (!device || device_dispatch_table(device)->ConvertCooperativeVectorMatrixNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkConvertCooperativeVectorMatrixNV<Format>);
    if (strcmp(pName, "vkCmdConvertCooperativeVectorMatrixNV") == 0 && (!device || device_dispatch_table(device)->CmdConvertCooperativeVectorMatrixNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdConvertCooperativeVectorMatrixNV<Format>);
    if (strcmp(pName, "vkSetLatencySleepModeNV") == 0 && (!device || device_dispatch_table(device)->SetLatencySleepModeNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkSetLatencySleepModeNV<Format>);
    if (strcmp(pName, "vkLatencySleepNV") == 0 && (!device || device_dispatch_table(device)->LatencySleepNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkLatencySleepNV<Format>);
    if (strcmp(pName, "vkSetLatencyMarkerNV") == 0 && (!device || device_dispatch_table(device)->SetLatencyMarkerNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkSetLatencyMarkerNV<Format>);
    if (strcmp(pName, "vkGetLatencyTimingsNV") == 0 && (!device || device_dispatch_table(device)->GetLatencyTimingsNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetLatencyTimingsNV<Format>);
    if (strcmp(pName, "vkQueueNotifyOutOfBandNV") == 0 && (!device || device_dispatch_table(device)->QueueNotifyOutOfBandNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkQueueNotifyOutOfBandNV<Format>);
    if (strcmp(pName, "vkCreateDataGraphPipelinesARM") == 0 && (!device || device_dispatch_table(device)->CreateDataGraphPipelinesARM))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateDataGraphPipelinesARM<Format>);
    if (strcmp(pName, "vkCreateDataGraphPipelineSessionARM") == 0 && (!device || device_dispatch_table(device)->CreateDataGraphPipelineSessionARM))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateDataGraphPipelineSessionARM<Format>);
    if (strcmp(pName, "vkGetDataGraphPipelineSessionBindPointRequirementsARM") == 0 && (!device || device_dispatch_table(device)->GetDataGraphPipelineSessionBindPointRequirementsARM))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetDataGraphPipelineSessionBindPointRequirementsARM<Format>);
    if (strcmp(pName, "vkGetDataGraphPipelineSessionMemoryRequirementsARM") == 0 && (!device || device_dispatch_table(device)->GetDataGraphPipelineSessionMemoryRequirementsARM))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetDataGraphPipelineSessionMemoryRequirementsARM<Format>);
    if (strcmp(pName, "vkBindDataGraphPipelineSessionMemoryARM") == 0 && (!device || device_dispatch_table(device)->BindDataGraphPipelineSessionMemoryARM))
        return reinterpret_cast<PFN_vkVoidFunction>(vkBindDataGraphPipelineSessionMemoryARM<Format>);
    if (strcmp(pName, "vkDestroyDataGraphPipelineSessionARM") == 0 && (!device || device_dispatch_table(device)->DestroyDataGraphPipelineSessionARM))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyDataGraphPipelineSessionARM<Format>);
    if (strcmp(pName, "vkCmdDispatchDataGraphARM") == 0 && (!device || device_dispatch_table(device)->CmdDispatchDataGraphARM))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdDispatchDataGraphARM<Format>);
    if (strcmp(pName, "vkGetDataGraphPipelineAvailablePropertiesARM") == 0 && (!device || device_dispatch_table(device)->GetDataGraphPipelineAvailablePropertiesARM))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetDataGraphPipelineAvailablePropertiesARM<Format>);
    if (strcmp(pName, "vkGetDataGraphPipelinePropertiesARM") == 0 && (!device || device_dispatch_table(device)->GetDataGraphPipelinePropertiesARM))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetDataGraphPipelinePropertiesARM<Format>);
    if (strcmp(pName, "vkCmdSetAttachmentFeedbackLoopEnableEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetAttachmentFeedbackLoopEnableEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetAttachmentFeedbackLoopEnableEXT<Format>);
#if defined(VK_USE_PLATFORM_SCREEN_QNX)
    if (strcmp(pName, "vkGetScreenBufferPropertiesQNX") == 0 && (!device || device_dispatch_table(device)->GetScreenBufferPropertiesQNX))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetScreenBufferPropertiesQNX<Format>);
#endif  // VK_USE_PLATFORM_SCREEN_QNX
    if (strcmp(pName, "vkCmdBindTileMemoryQCOM") == 0 && (!device || device_dispatch_table(device)->CmdBindTileMemoryQCOM))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdBindTileMemoryQCOM<Format>);
    if (strcmp(pName, "vkCmdDecompressMemoryEXT") == 0 && (!device || device_dispatch_table(device)->CmdDecompressMemoryEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdDecompressMemoryEXT<Format>);
    if (strcmp(pName, "vkCmdDecompressMemoryIndirectCountEXT") == 0 && (!device || device_dispatch_table(device)->CmdDecompressMemoryIndirectCountEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdDecompressMemoryIndirectCountEXT<Format>);
    if (strcmp(pName, "vkCreateExternalComputeQueueNV") == 0 && (!device || device_dispatch_table(device)->CreateExternalComputeQueueNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateExternalComputeQueueNV<Format>);
    if (strcmp(pName, "vkDestroyExternalComputeQueueNV") == 0 && (!device || device_dispatch_table(device)->DestroyExternalComputeQueueNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyExternalComputeQueueNV<Format>);
    if (strcmp(pName, "vkGetExternalComputeQueueDataNV") == 0 && (!device || device_dispatch_table(device)->GetExternalComputeQueueDataNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetExternalComputeQueueDataNV<Format>);
    if (strcmp(pName, "vkGetClusterAccelerationStructureBuildSizesNV") == 0 && (!device || device_dispatch_table(device)->GetClusterAccelerationStructureBuildSizesNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetClusterAccelerationStructureBuildSizesNV<Format>);
    if (strcmp(pName, "vkCmdBuildClusterAccelerationStructureIndirectNV") == 0 && (!device || device_dispatch_table(device)->CmdBuildClusterAccelerationStructureIndirectNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdBuildClusterAccelerationStructureIndirectNV<Format>);
    if (strcmp(pName, "vkGetPartitionedAccelerationStructuresBuildSizesNV") == 0 && (!device || device_dispatch_table(device)->GetPartitionedAccelerationStructuresBuildSizesNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPartitionedAccelerationStructuresBuildSizesNV<Format>);
    if (strcmp(pName, "vkCmdBuildPartitionedAccelerationStructuresNV") == 0 && (!device || device_dispatch_table(device)->CmdBuildPartitionedAccelerationStructuresNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdBuildPartitionedAccelerationStructuresNV<Format>);
    if (strcmp(pName, "vkGetGeneratedCommandsMemoryRequirementsEXT") == 0 && (!device || device_dispatch_table(device)->GetGeneratedCommandsMemoryRequirementsEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetGeneratedCommandsMemoryRequirementsEXT<Format>);
    if (strcmp(pName, "vkCmdPreprocessGeneratedCommandsEXT") == 0 && (!device || device_dispatch_table(device)->CmdPreprocessGeneratedCommandsEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdPreprocessGeneratedCommandsEXT<Format>);
    if (strcmp(pName, "vkCmdExecuteGeneratedCommandsEXT") == 0 && (!device || device_dispatch_table(device)->CmdExecuteGeneratedCommandsEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdExecuteGeneratedCommandsEXT<Format>);
    if (strcmp(pName, "vkCreateIndirectCommandsLayoutEXT") == 0 && (!device || device_dispatch_table(device)->CreateIndirectCommandsLayoutEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateIndirectCommandsLayoutEXT<Format>);
    if (strcmp(pName, "vkDestroyIndirectCommandsLayoutEXT") == 0 && (!device || device_dispatch_table(device)->DestroyIndirectCommandsLayoutEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyIndirectCommandsLayoutEXT<Format>);
    if (strcmp(pName, "vkCreateIndirectExecutionSetEXT") == 0 && (!device || device_dispatch_table(device)->CreateIndirectExecutionSetEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateIndirectExecutionSetEXT<Format>);
    if (strcmp(pName, "vkDestroyIndirectExecutionSetEXT") == 0 && (!device || device_dispatch_table(device)->DestroyIndirectExecutionSetEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyIndirectExecutionSetEXT<Format>);
    if (strcmp(pName, "vkUpdateIndirectExecutionSetPipelineEXT") == 0 && (!device || device_dispatch_table(device)->UpdateIndirectExecutionSetPipelineEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkUpdateIndirectExecutionSetPipelineEXT<Format>);
    if (strcmp(pName, "vkUpdateIndirectExecutionSetShaderEXT") == 0 && (!device || device_dispatch_table(device)->UpdateIndirectExecutionSetShaderEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkUpdateIndirectExecutionSetShaderEXT<Format>);
#if defined(VK_USE_PLATFORM_METAL_EXT)
    if (strcmp(pName, "vkGetMemoryMetalHandleEXT") == 0 && (!device || device_dispatch_table(device)->GetMemoryMetalHandleEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetMemoryMetalHandleEXT<Format>);
    if (strcmp(pName, "vkGetMemoryMetalHandlePropertiesEXT") == 0 && (!device || device_dispatch_table(device)->GetMemoryMetalHandlePropertiesEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetMemoryMetalHandlePropertiesEXT<Format>);
#endif  // VK_USE_PLATFORM_METAL_EXT
    if (strcmp(pName, "vkCmdEndRendering2EXT") == 0 && (!device || device_dispatch_table(device)->CmdEndRendering2EXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdEndRendering2EXT<Format>);
    if (strcmp(pName, "vkCmdBeginCustomResolveEXT") == 0 && (!device || device_dispatch_table(device)->CmdBeginCustomResolveEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdBeginCustomResolveEXT<Format>);
    if (strcmp(pName, "vkCmdSetComputeOccupancyPriorityNV") == 0 && (!device || device_dispatch_table(device)->CmdSetComputeOccupancyPriorityNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetComputeOccupancyPriorityNV<Format>);
    if (strcmp(pName, "vkCreateAccelerationStructureKHR") == 0 && (!device || device_dispatch_table(device)->CreateAccelerationStructureKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateAccelerationStructureKHR<Format>);
    if (strcmp(pName, "vkDestroyAccelerationStructureKHR") == 0 && (!device || device_dispatch_table(device)->DestroyAccelerationStructureKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyAccelerationStructureKHR<Format>);
    if (strcmp(pName, "vkCmdBuildAccelerationStructuresKHR") == 0 && (!device || device_dispatch_table(device)->CmdBuildAccelerationStructuresKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdBuildAccelerationStructuresKHR<Format>);
    if (strcmp(pName, "vkCmdBuildAccelerationStructuresIndirectKHR") == 0 && (!device || device_dispatch_table(device)->CmdBuildAccelerationStructuresIndirectKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdBuildAccelerationStructuresIndirectKHR<Format>);
    if (strcmp(pName, "vkBuildAccelerationStructuresKHR") == 0 && (!device || device_dispatch_table(device)->BuildAccelerationStructuresKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkBuildAccelerationStructuresKHR<Format>);
    if (strcmp(pName, "vkCopyAccelerationStructureKHR") == 0 && (!device || device_dispatch_table(device)->CopyAccelerationStructureKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCopyAccelerationStructureKHR<Format>);
    if (strcmp(pName, "vkCopyAccelerationStructureToMemoryKHR") == 0 && (!device || device_dispatch_table(device)->CopyAccelerationStructureToMemoryKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCopyAccelerationStructureToMemoryKHR<Format>);
    if (strcmp(pName, "vkCopyMemoryToAccelerationStructureKHR") == 0 && (!device || device_dispatch_table(device)->CopyMemoryToAccelerationStructureKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCopyMemoryToAccelerationStructureKHR<Format>);
    if (strcmp(pName, "vkWriteAccelerationStructuresPropertiesKHR") == 0 && (!device || device_dispatch_table(device)->WriteAccelerationStructuresPropertiesKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkWriteAccelerationStructuresPropertiesKHR<Format>);
    if (strcmp(pName, "vkCmdCopyAccelerationStructureKHR") == 0 && (!device || device_dispatch_table(device)->CmdCopyAccelerationStructureKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdCopyAccelerationStructureKHR<Format>);
    if (strcmp(pName, "vkCmdCopyAccelerationStructureToMemoryKHR") == 0 && (!device || device_dispatch_table(device)->CmdCopyAccelerationStructureToMemoryKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdCopyAccelerationStructureToMemoryKHR<Format>);
    if (strcmp(pName, "vkCmdCopyMemoryToAccelerationStructureKHR") == 0 && (!device || device_dispatch_table(device)->CmdCopyMemoryToAccelerationStructureKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdCopyMemoryToAccelerationStructureKHR<Format>);
    if (strcmp(pName, "vkGetAccelerationStructureDeviceAddressKHR") == 0 && (!device || device_dispatch_table(device)->GetAccelerationStructureDeviceAddressKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetAccelerationStructureDeviceAddressKHR<Format>);
    if (strcmp(pName, "vkCmdWriteAccelerationStructuresPropertiesKHR") == 0 && (!device || device_dispatch_table(device)->CmdWriteAccelerationStructuresPropertiesKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdWriteAccelerationStructuresPropertiesKHR<Format>);
    if (strcmp(pName, "vkGetDeviceAccelerationStructureCompatibilityKHR") == 0 && (!device || device_dispatch_table(device)->GetDeviceAccelerationStructureCompatibilityKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetDeviceAccelerationStructureCompatibilityKHR<Format>);
    if (strcmp(pName, "vkGetAccelerationStructureBuildSizesKHR") == 0 && (!device || device_dispatch_table(device)->GetAccelerationStructureBuildSizesKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetAccelerationStructureBuildSizesKHR<Format>);
    if (strcmp(pName, "vkCmdTraceRaysKHR") == 0 && (!device || device_dispatch_table(device)->CmdTraceRaysKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdTraceRaysKHR<Format>);
    if (strcmp(pName, "vkCreateRayTracingPipelinesKHR") == 0 && (!device || device_dispatch_table(device)->CreateRayTracingPipelinesKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateRayTracingPipelinesKHR<Format>);
    if (strcmp(pName, "vkGetRayTracingCaptureReplayShaderGroupHandlesKHR") == 0 && (!device || device_dispatch_table(device)->GetRayTracingCaptureReplayShaderGroupHandlesKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetRayTracingCaptureReplayShaderGroupHandlesKHR<Format>);
    if (strcmp(pName, "vkCmdTraceRaysIndirectKHR") == 0 && (!device || device_dispatch_table(device)->CmdTraceRaysIndirectKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdTraceRaysIndirectKHR<Format>);
    if (strcmp(pName, "vkGetRayTracingShaderGroupStackSizeKHR") == 0 && (!device || device_dispatch_table(device)->GetRayTracingShaderGroupStackSizeKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetRayTracingShaderGroupStackSizeKHR<Format>);
    if (strcmp(pName, "vkCmdSetRayTracingPipelineStackSizeKHR") == 0 && (!device || device_dispatch_table(device)->CmdSetRayTracingPipelineStackSizeKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetRayTracingPipelineStackSizeKHR<Format>);
    if (strcmp(pName, "vkCmdDrawMeshTasksEXT") == 0 && (!device || device_dispatch_table(device)->CmdDrawMeshTasksEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdDrawMeshTasksEXT<Format>);
    if (strcmp(pName, "vkCmdDrawMeshTasksIndirectEXT") == 0 && (!device || device_dispatch_table(device)->CmdDrawMeshTasksIndirectEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdDrawMeshTasksIndirectEXT<Format>);
    if (strcmp(pName, "vkCmdDrawMeshTasksIndirectCountEXT") == 0 && (!device || device_dispatch_table(device)->CmdDrawMeshTasksIndirectCountEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdDrawMeshTasksIndirectCountEXT<Format>);

    return nullptr;
}
