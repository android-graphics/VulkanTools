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
#include <vector>
#include <assert.h>
#include <string.h>
#include "vk_layer_table.h"
#include "debug_marker.h"
#include "debug_marker_perfetto.h"



#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))

#if defined(__GNUC__) && __GNUC__ >= 4
#define EXPORT_FUNCTION __attribute__((visibility("default")))
#elif defined(__SUNPRO_C) && (__SUNPRO_C >= 0x590)
#define EXPORT_FUNCTION __attribute__((visibility("default")))
#else
#define EXPORT_FUNCTION
#endif

static std::once_flag g_perfetto_init_flag;

static inline VkObjectType getVkObjectType(VkDebugReportObjectTypeEXT vk_debug_report_object_type) {
    switch (vk_debug_report_object_type) {
        case VK_DEBUG_REPORT_OBJECT_TYPE_UNKNOWN_EXT: return VK_OBJECT_TYPE_UNKNOWN;
        case VK_DEBUG_REPORT_OBJECT_TYPE_INSTANCE_EXT: return VK_OBJECT_TYPE_INSTANCE;
        case VK_DEBUG_REPORT_OBJECT_TYPE_PHYSICAL_DEVICE_EXT: return VK_OBJECT_TYPE_PHYSICAL_DEVICE;
        case VK_DEBUG_REPORT_OBJECT_TYPE_DEVICE_EXT: return VK_OBJECT_TYPE_DEVICE;
        case VK_DEBUG_REPORT_OBJECT_TYPE_QUEUE_EXT: return VK_OBJECT_TYPE_QUEUE;
        case VK_DEBUG_REPORT_OBJECT_TYPE_SEMAPHORE_EXT: return VK_OBJECT_TYPE_SEMAPHORE;
        case VK_DEBUG_REPORT_OBJECT_TYPE_COMMAND_BUFFER_EXT: return VK_OBJECT_TYPE_COMMAND_BUFFER;
        case VK_DEBUG_REPORT_OBJECT_TYPE_FENCE_EXT: return VK_OBJECT_TYPE_FENCE;
        case VK_DEBUG_REPORT_OBJECT_TYPE_DEVICE_MEMORY_EXT: return VK_OBJECT_TYPE_DEVICE_MEMORY;
        case VK_DEBUG_REPORT_OBJECT_TYPE_BUFFER_EXT: return VK_OBJECT_TYPE_BUFFER;
        case VK_DEBUG_REPORT_OBJECT_TYPE_IMAGE_EXT: return VK_OBJECT_TYPE_IMAGE;
        case VK_DEBUG_REPORT_OBJECT_TYPE_EVENT_EXT: return VK_OBJECT_TYPE_EVENT;
        case VK_DEBUG_REPORT_OBJECT_TYPE_QUERY_POOL_EXT: return VK_OBJECT_TYPE_QUERY_POOL;
        case VK_DEBUG_REPORT_OBJECT_TYPE_BUFFER_VIEW_EXT: return VK_OBJECT_TYPE_BUFFER_VIEW;
        case VK_DEBUG_REPORT_OBJECT_TYPE_IMAGE_VIEW_EXT: return VK_OBJECT_TYPE_IMAGE_VIEW;
        case VK_DEBUG_REPORT_OBJECT_TYPE_SHADER_MODULE_EXT: return VK_OBJECT_TYPE_SHADER_MODULE;
        case VK_DEBUG_REPORT_OBJECT_TYPE_PIPELINE_CACHE_EXT: return VK_OBJECT_TYPE_PIPELINE_CACHE;
        case VK_DEBUG_REPORT_OBJECT_TYPE_PIPELINE_LAYOUT_EXT: return VK_OBJECT_TYPE_PIPELINE_LAYOUT;
        case VK_DEBUG_REPORT_OBJECT_TYPE_RENDER_PASS_EXT: return VK_OBJECT_TYPE_RENDER_PASS;
        case VK_DEBUG_REPORT_OBJECT_TYPE_PIPELINE_EXT: return VK_OBJECT_TYPE_PIPELINE;
        case VK_DEBUG_REPORT_OBJECT_TYPE_DESCRIPTOR_SET_LAYOUT_EXT: return VK_OBJECT_TYPE_DESCRIPTOR_SET_LAYOUT;
        case VK_DEBUG_REPORT_OBJECT_TYPE_SAMPLER_EXT: return VK_OBJECT_TYPE_SAMPLER;
        case VK_DEBUG_REPORT_OBJECT_TYPE_DESCRIPTOR_POOL_EXT: return VK_OBJECT_TYPE_DESCRIPTOR_POOL;
        case VK_DEBUG_REPORT_OBJECT_TYPE_DESCRIPTOR_SET_EXT: return VK_OBJECT_TYPE_DESCRIPTOR_SET;
        case VK_DEBUG_REPORT_OBJECT_TYPE_FRAMEBUFFER_EXT: return VK_OBJECT_TYPE_FRAMEBUFFER;
        case VK_DEBUG_REPORT_OBJECT_TYPE_COMMAND_POOL_EXT: return VK_OBJECT_TYPE_COMMAND_POOL;
        case VK_DEBUG_REPORT_OBJECT_TYPE_SURFACE_KHR_EXT: return VK_OBJECT_TYPE_SURFACE_KHR;
        case VK_DEBUG_REPORT_OBJECT_TYPE_SWAPCHAIN_KHR_EXT: return VK_OBJECT_TYPE_SWAPCHAIN_KHR;
        case VK_DEBUG_REPORT_OBJECT_TYPE_DEBUG_REPORT_CALLBACK_EXT_EXT: return VK_OBJECT_TYPE_DEBUG_REPORT_CALLBACK_EXT;
        case VK_DEBUG_REPORT_OBJECT_TYPE_DISPLAY_KHR_EXT: return VK_OBJECT_TYPE_DISPLAY_KHR;
        case VK_DEBUG_REPORT_OBJECT_TYPE_DISPLAY_MODE_KHR_EXT: return VK_OBJECT_TYPE_DISPLAY_MODE_KHR;
        case VK_DEBUG_REPORT_OBJECT_TYPE_VALIDATION_CACHE_EXT_EXT: return VK_OBJECT_TYPE_VALIDATION_CACHE_EXT;
        case VK_DEBUG_REPORT_OBJECT_TYPE_SAMPLER_YCBCR_CONVERSION_EXT: return VK_OBJECT_TYPE_SAMPLER_YCBCR_CONVERSION;
        case VK_DEBUG_REPORT_OBJECT_TYPE_DESCRIPTOR_UPDATE_TEMPLATE_EXT: return VK_OBJECT_TYPE_DESCRIPTOR_UPDATE_TEMPLATE;
        case VK_DEBUG_REPORT_OBJECT_TYPE_ACCELERATION_STRUCTURE_NV_EXT: return VK_OBJECT_TYPE_ACCELERATION_STRUCTURE_NV;
        case VK_DEBUG_REPORT_OBJECT_TYPE_CU_MODULE_NVX_EXT: return VK_OBJECT_TYPE_CU_MODULE_NVX;
        case VK_DEBUG_REPORT_OBJECT_TYPE_CU_FUNCTION_NVX_EXT: return VK_OBJECT_TYPE_CU_FUNCTION_NVX;
        case VK_DEBUG_REPORT_OBJECT_TYPE_ACCELERATION_STRUCTURE_KHR_EXT: return VK_OBJECT_TYPE_ACCELERATION_STRUCTURE_KHR;
        case VK_DEBUG_REPORT_OBJECT_TYPE_BUFFER_COLLECTION_FUCHSIA_EXT: return VK_OBJECT_TYPE_BUFFER_COLLECTION_FUCHSIA;
        default:
            return VK_OBJECT_TYPE_UNKNOWN;
    }
}

extern "C" {

VKAPI_ATTR VkResult VKAPI_CALL vkCreateInstance(const VkInstanceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator,
                                                VkInstance* pInstance) {
    printf("Inside vkCreateInstance\n");
    std::call_once(g_perfetto_init_flag, []() { InitializeDebugMarkerPerfetto(); });

    // Get the function pointer
    VkLayerInstanceCreateInfo* chain_info = get_chain_info(pCreateInfo, VK_LAYER_LINK_INFO);
    assert(chain_info->u.pLayerInfo != 0);
    PFN_vkGetInstanceProcAddr fpGetInstanceProcAddr = chain_info->u.pLayerInfo->pfnNextGetInstanceProcAddr;
    assert(fpGetInstanceProcAddr != 0);
    PFN_vkCreateInstance fpCreateInstance = (PFN_vkCreateInstance)fpGetInstanceProcAddr(NULL, "vkCreateInstance");
    if (fpCreateInstance == NULL) {
        return VK_ERROR_INITIALIZATION_FAILED;
    }

    // Call the function and create the dispatch table
    chain_info->u.pLayerInfo = chain_info->u.pLayerInfo->pNext;
    VkResult result = fpCreateInstance(pCreateInfo, pAllocator, pInstance);
    if (result == VK_SUCCESS) {
        initInstanceTable(*pInstance, fpGetInstanceProcAddr);
        
        // Eagerly enumerate physical devices and map them to the instance.
        // This ensures we have the mapping even if the app bypasses our enumeration hooks.
        // Disabled for testing to avoid deadlock.
        /*
        PFN_vkEnumeratePhysicalDevices fpEnumeratePhysicalDevices = (PFN_vkEnumeratePhysicalDevices)fpGetInstanceProcAddr(*pInstance, "vkEnumeratePhysicalDevices");
        if (fpEnumeratePhysicalDevices) {
            uint32_t count = 0;
            fpEnumeratePhysicalDevices(*pInstance, &count, nullptr);
            if (count > 0) {
                std::vector<VkPhysicalDevice> devices(count);
                fpEnumeratePhysicalDevices(*pInstance, &count, devices.data());
                for (uint32_t i = 0; i < count; ++i) {
                    DebugMarker::Get().SetVkInstance(devices[i], *pInstance);
                }
            }
        }
        */
    }

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL vkEnumeratePhysicalDevices(VkInstance instance, uint32_t* pPhysicalDeviceCount, VkPhysicalDevice* pPhysicalDevices) {
    if (instance_dispatch_table(instance)->EnumeratePhysicalDevices == NULL) {
        return VK_ERROR_INITIALIZATION_FAILED;
    }
    
    VkResult result = instance_dispatch_table(instance)->EnumeratePhysicalDevices(instance, pPhysicalDeviceCount, pPhysicalDevices);
    
    if ((result == VK_SUCCESS || result == VK_INCOMPLETE) && pPhysicalDevices != nullptr) {
        for (uint32_t i = 0; i < *pPhysicalDeviceCount; ++i) {
            DebugMarker::Get().SetVkInstance(pPhysicalDevices[i], instance);
        }
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL vkEnumeratePhysicalDeviceGroups(VkInstance instance, uint32_t* pPhysicalDeviceGroupCount, VkPhysicalDeviceGroupProperties* pPhysicalDeviceGroupProperties) {
    if (instance_dispatch_table(instance)->EnumeratePhysicalDeviceGroups == NULL) {
        return VK_ERROR_INITIALIZATION_FAILED;
    }
    
    VkResult result = instance_dispatch_table(instance)->EnumeratePhysicalDeviceGroups(instance, pPhysicalDeviceGroupCount, pPhysicalDeviceGroupProperties);
    
    if ((result == VK_SUCCESS || result == VK_INCOMPLETE) && pPhysicalDeviceGroupProperties != nullptr) {
        for (uint32_t i = 0; i < *pPhysicalDeviceGroupCount; ++i) {
            for (uint32_t j = 0; j < pPhysicalDeviceGroupProperties[i].physicalDeviceCount; ++j) {
                DebugMarker::Get().SetVkInstance(pPhysicalDeviceGroupProperties[i].physicalDevices[j], instance);
            }
        }
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL vkCreateDevice(VkPhysicalDevice physicalDevice, const VkDeviceCreateInfo* pCreateInfo,
                                              const VkAllocationCallbacks* pAllocator, VkDevice* pDevice) {
    // Get the function pointer
    VkLayerDeviceCreateInfo* chain_info = get_chain_info(pCreateInfo, VK_LAYER_LINK_INFO);
    assert(chain_info->u.pLayerInfo != 0);
    PFN_vkGetInstanceProcAddr fpGetInstanceProcAddr = chain_info->u.pLayerInfo->pfnNextGetInstanceProcAddr;
    PFN_vkGetDeviceProcAddr fpGetDeviceProcAddr = chain_info->u.pLayerInfo->pfnNextGetDeviceProcAddr;
    VkInstance vk_instance = DebugMarker::Get().GetVkInstance(physicalDevice);
    PFN_vkCreateDevice fpCreateDevice = (PFN_vkCreateDevice)fpGetInstanceProcAddr(vk_instance, "vkCreateDevice");
    if (fpCreateDevice == NULL) {
        return VK_ERROR_INITIALIZATION_FAILED;
    }

    // Call the function and create the dispatch table
    chain_info->u.pLayerInfo = chain_info->u.pLayerInfo->pNext;
    VkResult result = fpCreateDevice(physicalDevice, pCreateInfo, pAllocator, pDevice);
    if (result == VK_SUCCESS) {
        initDeviceTable(*pDevice, fpGetDeviceProcAddr);
    }

    return result;
}

EXPORT_FUNCTION VKAPI_ATTR VkResult VKAPI_CALL vkEnumerateInstanceExtensionProperties(const char* pLayerName,
                                                                                      uint32_t* pPropertyCount,
                                                                                      VkExtensionProperties* pProperties) {
    static const VkExtensionProperties instanceExtensions[] = {
        {VK_EXT_DEBUG_UTILS_EXTENSION_NAME, VK_EXT_DEBUG_UTILS_SPEC_VERSION},
    };

    if (pLayerName != nullptr && strcmp(pLayerName, "VK_LAYER_GOOGLE_DebugMarker") == 0) {
        return util_GetExtensionProperties(ARRAY_SIZE(instanceExtensions), instanceExtensions, pPropertyCount, pProperties);
    }

    return VK_ERROR_LAYER_NOT_PRESENT;
}

EXPORT_FUNCTION VKAPI_ATTR VkResult VKAPI_CALL vkEnumerateInstanceLayerProperties(uint32_t* pPropertyCount,
                                                                                  VkLayerProperties* pProperties) {
    static const VkLayerProperties layerProperties[] = {{
        "VK_LAYER_GOOGLE_DebugMarker",
        VK_MAKE_VERSION(1, 4, VK_HEADER_VERSION),  // specVersion
        VK_MAKE_VERSION(0, 1, 0),                  // implementationVersion
        "layer: DebugMarker",
    }};

    return util_GetLayerProperties(ARRAY_SIZE(layerProperties), layerProperties, pPropertyCount, pProperties);
}

EXPORT_FUNCTION VKAPI_ATTR VkResult VKAPI_CALL vkEnumerateDeviceLayerProperties(VkPhysicalDevice physicalDevice,
                                                                                uint32_t* pPropertyCount,
                                                                                VkLayerProperties* pProperties) {
    static const VkLayerProperties layerProperties[] = {{
        "VK_LAYER_GOOGLE_DebugMarker",
        VK_MAKE_VERSION(1, 4, VK_HEADER_VERSION),
        VK_MAKE_VERSION(0, 1, 0),
        "layer: DebugMarker",
    }};

    return util_GetLayerProperties(ARRAY_SIZE(layerProperties), layerProperties, pPropertyCount, pProperties);
}

EXPORT_FUNCTION VKAPI_ATTR VkResult VKAPI_CALL vkEnumerateDeviceExtensionProperties(VkPhysicalDevice physicalDevice,
                                                                                    const char* pLayerName,
                                                                                    uint32_t* pPropertyCount,
                                                                                    VkExtensionProperties* pProperties) {
    static const VkExtensionProperties deviceExtensions[] = {
        {VK_EXT_DEBUG_MARKER_EXTENSION_NAME, VK_EXT_DEBUG_MARKER_SPEC_VERSION},
    };

    if (pLayerName != nullptr && strcmp(pLayerName, "VK_LAYER_GOOGLE_DebugMarker") == 0) {
        return util_GetExtensionProperties(ARRAY_SIZE(deviceExtensions), deviceExtensions, pPropertyCount, pProperties);
    }

    VkInstance vk_instance = DebugMarker::Get().GetVkInstance(physicalDevice);

    // Manually append device extension.  This should not be necessary, but the Android vulkan
    // loader does not expose extensions from implicit layer (b/143293104).
    if (pProperties == nullptr) {
        VkResult res = instance_dispatch_table(vk_instance)->EnumerateDeviceExtensionProperties(physicalDevice, pLayerName, pPropertyCount, pProperties);
        if (res == VK_SUCCESS) {
            (*pPropertyCount) += 1;
        }
        return res;
    }
    
    if (*pPropertyCount > 0) {
        uint32_t requestedCount = *pPropertyCount;
        VkResult res = instance_dispatch_table(vk_instance)->EnumerateDeviceExtensionProperties(physicalDevice, pLayerName, pPropertyCount, pProperties);
        if (res == VK_SUCCESS) {
            uint32_t originalCount = *pPropertyCount;
            *pPropertyCount = std::min(originalCount + 1, requestedCount);
            if (*pPropertyCount > originalCount) {
                pProperties[originalCount] = deviceExtensions[0];
            }
        }
        return res;
    }
    return VK_SUCCESS;
}

// Debug Marker Functions

VKAPI_ATTR void VKAPI_CALL vkCmdDebugMarkerBeginEXT(VkCommandBuffer commandBuffer, const VkDebugMarkerMarkerInfoEXT* pMarkerInfo) {
    if (device_dispatch_table(commandBuffer)->CmdDebugMarkerBeginEXT) {
        device_dispatch_table(commandBuffer)->CmdDebugMarkerBeginEXT(commandBuffer, pMarkerInfo);
    }
}

VKAPI_ATTR void VKAPI_CALL vkCmdDebugMarkerEndEXT(VkCommandBuffer commandBuffer) {
    if (device_dispatch_table(commandBuffer)->CmdDebugMarkerEndEXT) {
        device_dispatch_table(commandBuffer)->CmdDebugMarkerEndEXT(commandBuffer);
    }
}

VKAPI_ATTR void VKAPI_CALL vkCmdDebugMarkerInsertEXT(VkCommandBuffer commandBuffer, const VkDebugMarkerMarkerInfoEXT* pMarkerInfo) {
    if (device_dispatch_table(commandBuffer)->CmdDebugMarkerInsertEXT) {
        device_dispatch_table(commandBuffer)->CmdDebugMarkerInsertEXT(commandBuffer, pMarkerInfo);
    }
}

VKAPI_ATTR VkResult VKAPI_CALL vkDebugMarkerSetObjectNameEXT(VkDevice device, const VkDebugMarkerObjectNameInfoEXT* pNameInfo) {
    DebugMarker::Get().AddDebugMarker((uint64_t)device, (int32_t)getVkObjectType(pNameInfo->objectType), pNameInfo->object, pNameInfo->pObjectName);
    if (device_dispatch_table(device)->DebugMarkerSetObjectNameEXT) {
        VkResult result = device_dispatch_table(device)->DebugMarkerSetObjectNameEXT(device, pNameInfo);
        return result;
    }
    return VK_SUCCESS;
}

VKAPI_ATTR VkResult VKAPI_CALL vkDebugMarkerSetObjectTagEXT(VkDevice device, const VkDebugMarkerObjectTagInfoEXT* pTagInfo) {
    if (device_dispatch_table(device)->DebugMarkerSetObjectTagEXT) {
        return device_dispatch_table(device)->DebugMarkerSetObjectTagEXT(device, pTagInfo);
    }
    return VK_SUCCESS;
}

// Debug Utils Functions

VKAPI_ATTR void VKAPI_CALL vkCmdBeginDebugUtilsLabelEXT(VkCommandBuffer commandBuffer, const VkDebugUtilsLabelEXT* pLabelInfo) {
    if (device_dispatch_table(commandBuffer)->CmdBeginDebugUtilsLabelEXT) {
        device_dispatch_table(commandBuffer)->CmdBeginDebugUtilsLabelEXT(commandBuffer, pLabelInfo);
    }
}

VKAPI_ATTR void VKAPI_CALL vkCmdEndDebugUtilsLabelEXT(VkCommandBuffer commandBuffer) {
    if (device_dispatch_table(commandBuffer)->CmdEndDebugUtilsLabelEXT) {
        device_dispatch_table(commandBuffer)->CmdEndDebugUtilsLabelEXT(commandBuffer);
    }
}

VKAPI_ATTR void VKAPI_CALL vkCmdInsertDebugUtilsLabelEXT(VkCommandBuffer commandBuffer, const VkDebugUtilsLabelEXT* pLabelInfo) {
    if (device_dispatch_table(commandBuffer)->CmdInsertDebugUtilsLabelEXT) {
        device_dispatch_table(commandBuffer)->CmdInsertDebugUtilsLabelEXT(commandBuffer, pLabelInfo);
    }
}

VKAPI_ATTR VkResult VKAPI_CALL vkSetDebugUtilsObjectNameEXT(VkDevice device, const VkDebugUtilsObjectNameInfoEXT* pNameInfo) {
    DebugMarker::Get().AddDebugMarker((uint64_t)device, (int32_t)pNameInfo->objectType, pNameInfo->objectHandle, pNameInfo->pObjectName);
    if (device_dispatch_table(device)->SetDebugUtilsObjectNameEXT) {
        VkResult result = device_dispatch_table(device)->SetDebugUtilsObjectNameEXT(device, pNameInfo);
        return result;
    }
    return VK_SUCCESS;
}

VKAPI_ATTR VkResult VKAPI_CALL vkSetDebugUtilsObjectTagEXT(VkDevice device, const VkDebugUtilsObjectTagInfoEXT* pTagInfo) {
    if (device_dispatch_table(device)->SetDebugUtilsObjectTagEXT) {
        return device_dispatch_table(device)->SetDebugUtilsObjectTagEXT(device, pTagInfo);
    }
    return VK_SUCCESS;
}

VKAPI_ATTR void VKAPI_CALL vkQueueBeginDebugUtilsLabelEXT(VkQueue queue, const VkDebugUtilsLabelEXT* pLabelInfo) {
    if (device_dispatch_table(queue)->QueueBeginDebugUtilsLabelEXT) {
        device_dispatch_table(queue)->QueueBeginDebugUtilsLabelEXT(queue, pLabelInfo);
    }
}

VKAPI_ATTR void VKAPI_CALL vkQueueEndDebugUtilsLabelEXT(VkQueue queue) {
    if (device_dispatch_table(queue)->QueueEndDebugUtilsLabelEXT) {
        device_dispatch_table(queue)->QueueEndDebugUtilsLabelEXT(queue);
    }
}

VKAPI_ATTR void VKAPI_CALL vkQueueInsertDebugUtilsLabelEXT(VkQueue queue, const VkDebugUtilsLabelEXT* pLabelInfo) {
    if (device_dispatch_table(queue)->QueueInsertDebugUtilsLabelEXT) {
        device_dispatch_table(queue)->QueueInsertDebugUtilsLabelEXT(queue, pLabelInfo);
    }
}

VKAPI_ATTR VkResult VKAPI_CALL vkCreateDebugUtilsMessengerEXT(VkInstance instance, const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDebugUtilsMessengerEXT* pMessenger) {
    if (instance_dispatch_table(instance)->CreateDebugUtilsMessengerEXT) {
        return instance_dispatch_table(instance)->CreateDebugUtilsMessengerEXT(instance, pCreateInfo, pAllocator, pMessenger);
    }
    return VK_SUCCESS;
}

VKAPI_ATTR void VKAPI_CALL vkDestroyDebugUtilsMessengerEXT(VkInstance instance, VkDebugUtilsMessengerEXT messenger, const VkAllocationCallbacks* pAllocator) {
    if (instance_dispatch_table(instance)->DestroyDebugUtilsMessengerEXT) {
        instance_dispatch_table(instance)->DestroyDebugUtilsMessengerEXT(instance, messenger, pAllocator);
    }
}

VKAPI_ATTR void VKAPI_CALL vkSubmitDebugUtilsMessageEXT(VkInstance instance, VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity, VkDebugUtilsMessageTypeFlagsEXT messageTypes, const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData) {
    if (instance_dispatch_table(instance)->SubmitDebugUtilsMessageEXT) {
        instance_dispatch_table(instance)->SubmitDebugUtilsMessageEXT(instance, messageSeverity, messageTypes, pCallbackData);
    }
}

} // extern "C"
