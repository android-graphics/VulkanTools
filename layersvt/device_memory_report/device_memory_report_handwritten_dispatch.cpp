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

#include "device_memory_report_handwritten_functions.h"
#include "vk_layer_table.h"
#include <string.h>

extern "C" {

static PFN_vkVoidFunction devmemreport_known_instance_functions(const char* pName) {
    if (strcmp(pName, "vkGetInstanceProcAddr") == 0) return reinterpret_cast<PFN_vkVoidFunction>(vkGetInstanceProcAddr);
    if (strcmp(pName, "vkCreateInstance") == 0) return reinterpret_cast<PFN_vkVoidFunction>(vkCreateInstance);
    if (strcmp(pName, "vkDestroyInstance") == 0) return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyInstance);
    if (strcmp(pName, "vkEnumeratePhysicalDevices") == 0) return reinterpret_cast<PFN_vkVoidFunction>(vkEnumeratePhysicalDevices);
    if (strcmp(pName, "vkEnumeratePhysicalDeviceGroups") == 0) return reinterpret_cast<PFN_vkVoidFunction>(vkEnumeratePhysicalDeviceGroups);
    if (strcmp(pName, "vkEnumerateInstanceExtensionProperties") == 0) return reinterpret_cast<PFN_vkVoidFunction>(vkEnumerateInstanceExtensionProperties);
    if (strcmp(pName, "vkEnumerateInstanceLayerProperties") == 0) return reinterpret_cast<PFN_vkVoidFunction>(vkEnumerateInstanceLayerProperties);
    return nullptr;
}

static PFN_vkVoidFunction devmemreport_known_device_functions(const char* pName) {
    if (strcmp(pName, "vkGetDeviceProcAddr") == 0) return reinterpret_cast<PFN_vkVoidFunction>(vkGetDeviceProcAddr);
    if (strcmp(pName, "vkCreateDevice") == 0) return reinterpret_cast<PFN_vkVoidFunction>(vkCreateDevice);
    if (strcmp(pName, "vkDestroyDevice") == 0) return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyDevice);
    if (strcmp(pName, "vkEnumerateDeviceLayerProperties") == 0) return reinterpret_cast<PFN_vkVoidFunction>(vkEnumerateDeviceLayerProperties);
    if (strcmp(pName, "vkEnumerateDeviceExtensionProperties") == 0) return reinterpret_cast<PFN_vkVoidFunction>(vkEnumerateDeviceExtensionProperties);
    if (strcmp(pName, "vkAllocateMemory") == 0) return reinterpret_cast<PFN_vkVoidFunction>(vkAllocateMemory);
    if (strcmp(pName, "vkFreeMemory") == 0) return reinterpret_cast<PFN_vkVoidFunction>(vkFreeMemory);
    if (strcmp(pName, "vkBindBufferMemory") == 0) return reinterpret_cast<PFN_vkVoidFunction>(vkBindBufferMemory);
    if (strcmp(pName, "vkBindImageMemory") == 0) return reinterpret_cast<PFN_vkVoidFunction>(vkBindImageMemory);
    if (strcmp(pName, "vkCreateImage") == 0) return reinterpret_cast<PFN_vkVoidFunction>(vkCreateImage);
    if (strcmp(pName, "vkDestroyImage") == 0) return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyImage);
    if (strcmp(pName, "vkCreateBuffer") == 0) return reinterpret_cast<PFN_vkVoidFunction>(vkCreateBuffer);
    if (strcmp(pName, "vkDestroyBuffer") == 0) return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyBuffer);
    return nullptr;
}

EXPORT_FUNCTION VKAPI_ATTR PFN_vkVoidFunction VKAPI_CALL vkGetInstanceProcAddr(VkInstance instance, const char* pName) {
    PFN_vkVoidFunction func = devmemreport_known_instance_functions(pName);
    if (func) {
        return func;
    }
    
    // If it's a device function, we can also return it here if we want to support GIPA for device functions.
    func = devmemreport_known_device_functions(pName);
    if (func) {
        return func;
    }

    if (instance == nullptr) {
        return nullptr;
    }

    auto table = instance_dispatch_table(instance);
    if (table == NULL || table->GetInstanceProcAddr == NULL) {
        return nullptr;
    }

    return table->GetInstanceProcAddr(instance, pName);
}

EXPORT_FUNCTION VKAPI_ATTR PFN_vkVoidFunction VKAPI_CALL vkGetDeviceProcAddr(VkDevice device, const char* pName) {
    PFN_vkVoidFunction func = devmemreport_known_device_functions(pName);
    if (func) {
        return func;
    }

    if (device == nullptr) {
        return nullptr;
    }

    if (device_dispatch_table(device)->GetDeviceProcAddr == NULL) {
        return nullptr;
    }
    
    return device_dispatch_table(device)->GetDeviceProcAddr(device, pName);
}

} // extern "C"
