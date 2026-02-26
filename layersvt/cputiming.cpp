/*
 * Copyright (C) 2015-2021 Valve Corporation
 * Copyright (C) 2015-2021 LunarG, Inc.
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
 * Author: Cody Northrop <cody@lunarg.com>
 * Author: David Pinedo <david@lunarg.com>
 * Author: Jon Ashburn <jon@lunarg.com>
 * Author: Tony Barbour <tony@lunarg.com>
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string>
#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <list>
#include <vector>
#include <mutex>
#include <fstream>

#include <vulkan/layer/vk_layer_settings.hpp>
#include "vk_layer_table.h"

#ifdef ANDROID
#include <android/log.h>
#include <sys/system_properties.h>
#endif

namespace cputiming {

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))

std::mutex globalLock;

VkuLayerSettingSet globalLayerSettingSet = VK_NULL_HANDLE;

// unordered map: associates Vulkan dispatchable objects to a dispatch table
typedef struct {
    VkuDeviceDispatchTable *device_dispatch_table;
    PFN_vkSetDeviceLoaderData pfn_dev_init;
} DispatchMapStruct;
static std::unordered_map<VkDevice, DispatchMapStruct *> dispatchMap;

// unordered map: associates a device with per device info -
//   wsi capability
//   set of queues created for this device
//   queue to queueFamilyIndex map
//   physical device
struct DeviceMapStruct {
    bool wsi_enabled;
    std::set<VkQueue> queues;
    std::unordered_map<VkQueue, uint32_t> queueIndexMap;
    VkPhysicalDevice physicalDevice;
};
static std::unordered_map<VkDevice, DeviceMapStruct *> deviceMap;

// unordered map: associates a physical device with an instance
typedef struct {
    VkInstance instance;
} PhysDeviceMapStruct;
static std::unordered_map<VkPhysicalDevice, PhysDeviceMapStruct> physDeviceMap;

static void LogMessage(const char* format, ...) {
    va_list args;
    va_start(args, format);
#ifdef ANDROID
    __android_log_vprint(ANDROID_LOG_INFO, "CPUTiming", format, args);
#else
    vprintf(format, args);
    printf("\n");
#endif
    va_end(args);
}

static DispatchMapStruct *get_dispatch_info(VkDevice dev) {
    auto it = dispatchMap.find(dev);
    if (it == dispatchMap.end())
        return NULL;
    else
        return it->second;
}

static DeviceMapStruct *get_device_info(VkDevice dev) {
    auto it = deviceMap.find(dev);
    if (it == deviceMap.end())
        return NULL;
    else
        return it->second;
}

static void init_cputiming(const VkInstanceCreateInfo *pCreateInfo, const VkAllocationCallbacks *pAllocator) {
    std::lock_guard<std::mutex> lg(globalLock);
    // keeping layer settings structure if we ever need it, but currently unused
    // logic simplified
}

static void shutdown_cputiming() {
    // cleanup if needed
}

VKAPI_ATTR VkResult VKAPI_CALL CreateInstance(const VkInstanceCreateInfo *pCreateInfo, const VkAllocationCallbacks *pAllocator,
                                              VkInstance *pInstance) {
    LogMessage("CreateInstance");
    VkLayerInstanceCreateInfo *chain_info = get_chain_info(pCreateInfo, VK_LAYER_LINK_INFO);

    assert(chain_info->u.pLayerInfo);
    PFN_vkGetInstanceProcAddr fpGetInstanceProcAddr = chain_info->u.pLayerInfo->pfnNextGetInstanceProcAddr;
    assert(fpGetInstanceProcAddr);
    PFN_vkCreateInstance fpCreateInstance = (PFN_vkCreateInstance)fpGetInstanceProcAddr(VK_NULL_HANDLE, "vkCreateInstance");
    if (fpCreateInstance == NULL) {
        return VK_ERROR_INITIALIZATION_FAILED;
    }

    // Advance the link info for the next element on the chain
    chain_info->u.pLayerInfo = chain_info->u.pLayerInfo->pNext;

    VkResult result = fpCreateInstance(pCreateInfo, pAllocator, pInstance);
    if (result != VK_SUCCESS) return result;

    initInstanceTable(*pInstance, fpGetInstanceProcAddr);
    init_cputiming(pCreateInfo, pAllocator);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyInstance(VkInstance instance, const VkAllocationCallbacks *pAllocator) {
    LogMessage("DestroyInstance");
    shutdown_cputiming();

    VkuInstanceDispatchTable *pTable = instance_dispatch_table(instance);
    pTable->DestroyInstance(instance, pAllocator);
}

static void createDeviceRegisterExtensions(const VkDeviceCreateInfo *pCreateInfo, VkDevice device) {
    uint32_t i;
    DispatchMapStruct *dispMap = get_dispatch_info(device);
    DeviceMapStruct *devMap = get_device_info(device);
    VkuDeviceDispatchTable *pDisp = dispMap->device_dispatch_table;
    PFN_vkGetDeviceProcAddr gpa = pDisp->GetDeviceProcAddr;
    pDisp->CreateSwapchainKHR = (PFN_vkCreateSwapchainKHR)gpa(device, "vkCreateSwapchainKHR");
    pDisp->GetSwapchainImagesKHR = (PFN_vkGetSwapchainImagesKHR)gpa(device, "vkGetSwapchainImagesKHR");
    pDisp->AcquireNextImageKHR = (PFN_vkAcquireNextImageKHR)gpa(device, "vkAcquireNextImageKHR");
    pDisp->QueuePresentKHR = (PFN_vkQueuePresentKHR)gpa(device, "vkQueuePresentKHR");
    devMap->wsi_enabled = false;
    for (i = 0; i < pCreateInfo->enabledExtensionCount; i++) {
        if (strcmp(pCreateInfo->ppEnabledExtensionNames[i], VK_KHR_SWAPCHAIN_EXTENSION_NAME) == 0) devMap->wsi_enabled = true;
    }
}

VKAPI_ATTR VkResult VKAPI_CALL CreateDevice(VkPhysicalDevice gpu, const VkDeviceCreateInfo *pCreateInfo,
                                            const VkAllocationCallbacks *pAllocator, VkDevice *pDevice) {
    LogMessage("CreateDevice");
    VkLayerDeviceCreateInfo *chain_info = get_chain_info(pCreateInfo, VK_LAYER_LINK_INFO);

    assert(chain_info->u.pLayerInfo);
    PFN_vkGetInstanceProcAddr fpGetInstanceProcAddr = chain_info->u.pLayerInfo->pfnNextGetInstanceProcAddr;
    PFN_vkGetDeviceProcAddr fpGetDeviceProcAddr = chain_info->u.pLayerInfo->pfnNextGetDeviceProcAddr;
    VkInstance instance = physDeviceMap[gpu].instance;
    PFN_vkCreateDevice fpCreateDevice = (PFN_vkCreateDevice)fpGetInstanceProcAddr(instance, "vkCreateDevice");
    if (fpCreateDevice == NULL) {
        return VK_ERROR_INITIALIZATION_FAILED;
    }

    // Advance the link info for the next element on the chain
    chain_info->u.pLayerInfo = chain_info->u.pLayerInfo->pNext;

    VkResult result = fpCreateDevice(gpu, pCreateInfo, pAllocator, pDevice);
    if (result != VK_SUCCESS) {
        return result;
    }

    assert(deviceMap.find(*pDevice) == deviceMap.end());
    DeviceMapStruct *deviceMapElem = new DeviceMapStruct;
    deviceMap[*pDevice] = deviceMapElem;
    assert(dispatchMap.find(*pDevice) == dispatchMap.end());
    DispatchMapStruct *dispatchMapElem = new DispatchMapStruct;
    dispatchMap[*pDevice] = dispatchMapElem;

    // Setup device dispatch table
    dispatchMapElem->device_dispatch_table = new VkuDeviceDispatchTable;
    vkuInitDeviceDispatchTable(*pDevice, dispatchMapElem->device_dispatch_table, fpGetDeviceProcAddr);

    createDeviceRegisterExtensions(pCreateInfo, *pDevice);
    // Create a mapping from a device to a physicalDevice
    deviceMapElem->physicalDevice = gpu;

    // store the loader callback for initializing created dispatchable objects
    chain_info = get_chain_info(pCreateInfo, VK_LOADER_DATA_CALLBACK);
    if (chain_info) {
        dispatchMapElem->pfn_dev_init = chain_info->u.pfnSetDeviceLoaderData;
    } else {
        dispatchMapElem->pfn_dev_init = NULL;
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL EnumeratePhysicalDevices(VkInstance instance, uint32_t *pPhysicalDeviceCount,
                                                        VkPhysicalDevice *pPhysicalDevices) {
    LogMessage("EnumeratePhysicalDevices");
    VkResult result;

    VkuInstanceDispatchTable *pTable = instance_dispatch_table(instance);
    result = pTable->EnumeratePhysicalDevices(instance, pPhysicalDeviceCount, pPhysicalDevices);
    if (result == VK_SUCCESS && *pPhysicalDeviceCount > 0 && pPhysicalDevices) {
        for (uint32_t i = 0; i < *pPhysicalDeviceCount; i++) {
            // Create a mapping from a physicalDevice to an instance
            physDeviceMap[pPhysicalDevices[i]].instance = instance;
        }
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL EnumeratePhysicalDeviceGroups(VkInstance instance, uint32_t *pPhysicalDeviceGroupCount,
                                                             VkPhysicalDeviceGroupProperties *pPhysicalDeviceGroupProperties) {
    LogMessage("EnumeratePhysicalDeviceGroups");
    VkResult result;
    VkuInstanceDispatchTable *pTable = instance_dispatch_table(instance);
    result = pTable->EnumeratePhysicalDeviceGroups(instance, pPhysicalDeviceGroupCount, pPhysicalDeviceGroupProperties);
    if (result == VK_SUCCESS && *pPhysicalDeviceGroupCount > 0 && pPhysicalDeviceGroupProperties) {
        for (uint32_t i = 0; i < *pPhysicalDeviceGroupCount; i++) {
            for (uint32_t j = 0; j < pPhysicalDeviceGroupProperties[i].physicalDeviceCount; j++) {
                // Create a mapping from each physicalDevice to an instance
                physDeviceMap[pPhysicalDeviceGroupProperties[i].physicalDevices[j]].instance = instance;
            }
        }
    }
    return VK_SUCCESS;
}

VKAPI_ATTR void VKAPI_CALL DestroyDevice(VkDevice device, const VkAllocationCallbacks *pAllocator) {
    LogMessage("DestroyDevice");
    DispatchMapStruct *dispMap = get_dispatch_info(device);
    DeviceMapStruct *devMap = get_device_info(device);
    assert(dispMap);
    assert(devMap);
    VkuDeviceDispatchTable *pDisp = dispMap->device_dispatch_table;
    pDisp->DestroyDevice(device, pAllocator);

    std::lock_guard<std::mutex> lg(globalLock);
    delete pDisp;
    delete dispMap;
    delete devMap;

    deviceMap.erase(device);
    dispatchMap.erase(device);
}

VKAPI_ATTR void VKAPI_CALL GetDeviceQueue(VkDevice device, uint32_t queueFamilyIndex, uint32_t queueIndex, VkQueue *pQueue) {
    LogMessage("GetDeviceQueue");
    DispatchMapStruct *dispMap = get_dispatch_info(device);
    assert(dispMap);
    VkuDeviceDispatchTable *pDisp = dispMap->device_dispatch_table;
    pDisp->GetDeviceQueue(device, queueFamilyIndex, queueIndex, pQueue);

    std::lock_guard<std::mutex> lg(globalLock);

    // Add this queue to deviceMap[device].queues, and queueFamilyIndex to deviceMap[device].queueIndexMap
    if (deviceMap.find(device) != deviceMap.end()) {
        deviceMap[device]->queues.emplace(*pQueue);

        if (deviceMap[device]->queueIndexMap.find(*pQueue) != deviceMap[device]->queueIndexMap.end())
            deviceMap[device]->queueIndexMap.erase(*pQueue);
        deviceMap[device]->queueIndexMap.emplace(*pQueue, queueFamilyIndex);
    }

    // queues are dispatchable objects.
    // Create dispatchMap entry with this queue as its key.
    // Copy the device dispatch table to the new dispatch table.
    VkDevice que = static_cast<VkDevice>(static_cast<void *>(*pQueue));
    dispatchMap[que] = dispMap;
}

VKAPI_ATTR void VKAPI_CALL GetDeviceQueue2(VkDevice device, const VkDeviceQueueInfo2 *pQueueInfo, VkQueue *pQueue) {
    LogMessage("GetDeviceQueue2");
    if (pQueueInfo) GetDeviceQueue(device, pQueueInfo->queueFamilyIndex, pQueueInfo->queueIndex, pQueue);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateSwapchainKHR(VkDevice device, const VkSwapchainCreateInfoKHR *pCreateInfo,
                                                  const VkAllocationCallbacks *pAllocator, VkSwapchainKHR *pSwapchain) {
    LogMessage("CreateSwapchainKHR");
    DispatchMapStruct *dispMap = get_dispatch_info(device);
    assert(dispMap);
    VkuDeviceDispatchTable *pDisp = dispMap->device_dispatch_table;

    VkResult result = pDisp->CreateSwapchainKHR(device, pCreateInfo, pAllocator, pSwapchain);
    return result;
}

VKAPI_ATTR void DestroySwapchainKHR(VkDevice device, VkSwapchainKHR swapchain, const VkAllocationCallbacks *pAllocator) {
    LogMessage("DestroySwapchainKHR");
    DispatchMapStruct *dispMap = get_dispatch_info(device);
    assert(dispMap);
    VkuDeviceDispatchTable *pDisp = dispMap->device_dispatch_table;
    pDisp->DestroySwapchainKHR(device, swapchain, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL GetSwapchainImagesKHR(VkDevice device, VkSwapchainKHR swapchain, uint32_t *pCount,
                                                     VkImage *pSwapchainImages) {
    LogMessage("GetSwapchainImagesKHR");
    DispatchMapStruct *dispMap = get_dispatch_info(device);
    assert(dispMap);
    VkuDeviceDispatchTable *pDisp = dispMap->device_dispatch_table;
    VkResult result = pDisp->GetSwapchainImagesKHR(device, swapchain, pCount, pSwapchainImages);
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL QueuePresentKHR(VkQueue queue, const VkPresentInfoKHR *pPresentInfo) {
    LogMessage("QueuePresentKHR");
    DispatchMapStruct *dispMap = get_dispatch_info((VkDevice)queue);
    VkuDeviceDispatchTable *pDisp = dispMap->device_dispatch_table;
    assert(dispMap);
    VkResult result = pDisp->QueuePresentKHR(queue, pPresentInfo);
    return result;
}

static const VkLayerProperties global_layer = {
    "CPUTiming",  // layerName
    VK_MAKE_VERSION(1, 0, 0),     // specVersion
    1,                             // implementationVersion
    "Layer: CPUTiming",           // description
};

VKAPI_ATTR VkResult VKAPI_CALL EnumerateInstanceLayerProperties(uint32_t *pCount, VkLayerProperties *pProperties) {
    return util_GetLayerProperties(1, &global_layer, pCount, pProperties);
}

VKAPI_ATTR VkResult VKAPI_CALL EnumerateDeviceLayerProperties(VkPhysicalDevice physicalDevice, uint32_t *pCount,
                                                              VkLayerProperties *pProperties) {
    return util_GetLayerProperties(1, &global_layer, pCount, pProperties);
}

VKAPI_ATTR VkResult VKAPI_CALL EnumerateInstanceExtensionProperties(const char *pLayerName, uint32_t *pCount,
                                                                    VkExtensionProperties *pProperties) {
    if (pLayerName && !strcmp(pLayerName, global_layer.layerName)) return util_GetExtensionProperties(0, NULL, pCount, pProperties);

    return VK_ERROR_LAYER_NOT_PRESENT;
}

VKAPI_ATTR VkResult VKAPI_CALL EnumerateDeviceExtensionProperties(VkPhysicalDevice physicalDevice, const char *pLayerName,
                                                                  uint32_t *pCount, VkExtensionProperties *pProperties) {
    if (pLayerName && !strcmp(pLayerName, global_layer.layerName)) return util_GetExtensionProperties(0, NULL, pCount, pProperties);

    assert(physicalDevice);

    VkuInstanceDispatchTable *pTable = instance_dispatch_table(physicalDevice);
    return pTable->EnumerateDeviceExtensionProperties(physicalDevice, pLayerName, pCount, pProperties);
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceToolPropertiesEXT(VkPhysicalDevice physicalDevice, uint32_t *pToolCount,
                                                                  VkPhysicalDeviceToolPropertiesEXT *pToolProperties) {
    LogMessage("GetPhysicalDeviceToolPropertiesEXT");
    static const VkPhysicalDeviceToolPropertiesEXT cputiming_layer_tool_props = {
        VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TOOL_PROPERTIES_EXT,
        nullptr,
        "CPUTiming Layer",
        "1",
        VK_TOOL_PURPOSE_PROFILING_BIT_EXT | VK_TOOL_PURPOSE_TRACING_BIT_EXT | VK_TOOL_PURPOSE_ADDITIONAL_FEATURES_BIT_EXT,
        "The VK_LAYER_CPUTiming layer prints API calls.",
        "VK_LAYER_CPUTiming"};

    auto original_pToolProperties = pToolProperties;
    if (pToolProperties != nullptr) {
        *pToolProperties = cputiming_layer_tool_props;
        pToolProperties = ((*pToolCount > 1) ? &pToolProperties[1] : nullptr);
        (*pToolCount)--;
    }

    VkuInstanceDispatchTable *pInstanceTable = instance_dispatch_table(physicalDevice);
    VkResult result = pInstanceTable->GetPhysicalDeviceToolPropertiesEXT(physicalDevice, pToolCount, pToolProperties);

    if (original_pToolProperties != nullptr) {
        pToolProperties = original_pToolProperties;
    }

    (*pToolCount)++;

    return result;
}

static PFN_vkVoidFunction intercept_core_instance_command(const char *name);

static PFN_vkVoidFunction intercept_core_device_command(const char *name);

static PFN_vkVoidFunction intercept_khr_swapchain_command(const char *name, VkDevice dev);

VKAPI_ATTR PFN_vkVoidFunction VKAPI_CALL GetDeviceProcAddr(VkDevice dev, const char *funcName) {
    PFN_vkVoidFunction proc = intercept_core_device_command(funcName);
    if (proc) return proc;

    if (dev == NULL) {
        return NULL;
    }

    proc = intercept_khr_swapchain_command(funcName, dev);
    if (proc) return proc;

    DispatchMapStruct *dispMap = get_dispatch_info(dev);
    assert(dispMap);
    VkuDeviceDispatchTable *pDisp = dispMap->device_dispatch_table;

    if (pDisp->GetDeviceProcAddr == NULL) return NULL;
    return pDisp->GetDeviceProcAddr(dev, funcName);
}

VKAPI_ATTR PFN_vkVoidFunction VKAPI_CALL GetInstanceProcAddr(VkInstance instance, const char *funcName) {
    PFN_vkVoidFunction proc = intercept_core_instance_command(funcName);
    if (proc) return proc;

    assert(instance);

    proc = intercept_core_device_command(funcName);
    if (!proc) proc = intercept_khr_swapchain_command(funcName, VK_NULL_HANDLE);
    if (proc) return proc;

    VkuInstanceDispatchTable *pTable = instance_dispatch_table(instance);
    if (pTable->GetInstanceProcAddr == NULL) return NULL;
    return pTable->GetInstanceProcAddr(instance, funcName);
}

static PFN_vkVoidFunction intercept_core_instance_command(const char *name) {
    static const struct {
        const char *name;
        PFN_vkVoidFunction proc;
    } core_instance_commands[] = {
        {"vkGetInstanceProcAddr", reinterpret_cast<PFN_vkVoidFunction>(GetInstanceProcAddr)},
        {"vkCreateInstance", reinterpret_cast<PFN_vkVoidFunction>(CreateInstance)},
        {"vkDestroyInstance", reinterpret_cast<PFN_vkVoidFunction>(DestroyInstance)},
        {"vkCreateDevice", reinterpret_cast<PFN_vkVoidFunction>(CreateDevice)},
        {"vkEnumeratePhysicalDevices", reinterpret_cast<PFN_vkVoidFunction>(EnumeratePhysicalDevices)},
        {"vkEnumeratePhysicalDeviceGroups", reinterpret_cast<PFN_vkVoidFunction>(EnumeratePhysicalDeviceGroups)},
        {"vkEnumerateInstanceLayerProperties", reinterpret_cast<PFN_vkVoidFunction>(EnumerateInstanceLayerProperties)},
        {"vkEnumerateDeviceLayerProperties", reinterpret_cast<PFN_vkVoidFunction>(EnumerateDeviceLayerProperties)},
        {"vkEnumerateInstanceExtensionProperties", reinterpret_cast<PFN_vkVoidFunction>(EnumerateInstanceExtensionProperties)},
        {"vkEnumerateDeviceExtensionProperties", reinterpret_cast<PFN_vkVoidFunction>(EnumerateDeviceExtensionProperties)},
        {"vkGetPhysicalDeviceToolPropertiesEXT", reinterpret_cast<PFN_vkVoidFunction>(GetPhysicalDeviceToolPropertiesEXT)}};

    for (size_t i = 0; i < ARRAY_SIZE(core_instance_commands); i++) {
        if (!strcmp(core_instance_commands[i].name, name)) return core_instance_commands[i].proc;
    }

    return nullptr;
}

static PFN_vkVoidFunction intercept_core_device_command(const char *name) {
    static const struct {
        const char *name;
        PFN_vkVoidFunction proc;
    } core_device_commands[] = {
        {"vkGetDeviceProcAddr", reinterpret_cast<PFN_vkVoidFunction>(GetDeviceProcAddr)},
        {"vkGetDeviceQueue", reinterpret_cast<PFN_vkVoidFunction>(GetDeviceQueue)},
        {"vkGetDeviceQueue2", reinterpret_cast<PFN_vkVoidFunction>(GetDeviceQueue2)},
        {"vkDestroyDevice", reinterpret_cast<PFN_vkVoidFunction>(DestroyDevice)},
    };

    for (size_t i = 0; i < ARRAY_SIZE(core_device_commands); i++) {
        if (!strcmp(core_device_commands[i].name, name)) return core_device_commands[i].proc;
    }

    return nullptr;
}

static PFN_vkVoidFunction intercept_khr_swapchain_command(const char *name, VkDevice dev) {
    static const struct {
        const char *name;
        PFN_vkVoidFunction proc;
    } khr_swapchain_commands[] = {
        {"vkCreateSwapchainKHR", reinterpret_cast<PFN_vkVoidFunction>(CreateSwapchainKHR)},
        {"vkDestroySwapchainKHR", reinterpret_cast<PFN_vkVoidFunction>(DestroySwapchainKHR)},
        {"vkQueuePresentKHR", reinterpret_cast<PFN_vkVoidFunction>(QueuePresentKHR)},
    };

    if (dev) {
        DeviceMapStruct *devMap = get_device_info(dev);
        if (!devMap->wsi_enabled) return nullptr;
    }

    for (size_t i = 0; i < ARRAY_SIZE(khr_swapchain_commands); i++) {
        if (!strcmp(khr_swapchain_commands[i].name, name)) return khr_swapchain_commands[i].proc;
    }

    return nullptr;
}

}  // namespace cputiming

#if defined(__GNUC__) && __GNUC__ >= 4
#define EXPORT_FUNCTION __attribute__((visibility("default")))
#elif defined(__SUNPRO_C) && (__SUNPRO_C >= 0x590)
#define EXPORT_FUNCTION __attribute__((visibility("default")))
#else
#define EXPORT_FUNCTION
#endif

EXPORT_FUNCTION VKAPI_ATTR VkResult VKAPI_CALL vkEnumerateInstanceLayerProperties(uint32_t *pCount,
                                                                                  VkLayerProperties *pProperties) {
    return cputiming::EnumerateInstanceLayerProperties(pCount, pProperties);
}

EXPORT_FUNCTION VKAPI_ATTR VkResult VKAPI_CALL vkEnumerateDeviceLayerProperties(VkPhysicalDevice physicalDevice, uint32_t *pCount,
                                                                                VkLayerProperties *pProperties) {
    assert(physicalDevice == VK_NULL_HANDLE);
    return cputiming::EnumerateDeviceLayerProperties(VK_NULL_HANDLE, pCount, pProperties);
}

EXPORT_FUNCTION VKAPI_ATTR VkResult VKAPI_CALL vkEnumerateInstanceExtensionProperties(const char *pLayerName, uint32_t *pCount,
                                                                                      VkExtensionProperties *pProperties) {
    return cputiming::EnumerateInstanceExtensionProperties(pLayerName, pCount, pProperties);
}

EXPORT_FUNCTION VKAPI_ATTR VkResult VKAPI_CALL vkEnumerateDeviceExtensionProperties(VkPhysicalDevice physicalDevice,
                                                                                    const char *pLayerName, uint32_t *pCount,
                                                                                    VkExtensionProperties *pProperties) {
    assert(physicalDevice == VK_NULL_HANDLE);
    return cputiming::EnumerateDeviceExtensionProperties(VK_NULL_HANDLE, pLayerName, pCount, pProperties);
}

EXPORT_FUNCTION VKAPI_ATTR PFN_vkVoidFunction VKAPI_CALL vkGetDeviceProcAddr(VkDevice dev, const char *funcName) {
    return cputiming::GetDeviceProcAddr(dev, funcName);
}

EXPORT_FUNCTION VKAPI_ATTR PFN_vkVoidFunction VKAPI_CALL vkGetInstanceProcAddr(VkInstance instance, const char *funcName) {
    return cputiming::GetInstanceProcAddr(instance, funcName);
}
