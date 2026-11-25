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

#include "common/layer_base.h"
#include "common/layer_manifest.h"
#include <gtest/gtest.h>
#include <vulkan/vk_layer.h>
#include <vulkan/vulkan.h>

#include <cstdint>
#include <cstring>

namespace layersvt {
namespace {

class EntrypointsTestLayer : public LayerBase {
   public:
    explicit EntrypointsTestLayer(const LayerManifest* manifest) : manifest_(manifest) {}
    ~EntrypointsTestLayer() override = default;

    [[nodiscard]] const LayerManifest* GetLayerManifest() const override { return manifest_; }

   private:
    const LayerManifest* manifest_;
};

TEST(LayerEntrypointsTest, ForwardingCalls) {
    LayerManifest manifest{
        .layer_name = "VK_LAYER_TEST_Entrypoints",
    };
    EntrypointsTestLayer test_layer(&manifest);
    uint32_t property_count = 0;

    EXPECT_EQ(::vkEnumerateInstanceLayerProperties(&property_count, nullptr), VK_SUCCESS);
    EXPECT_EQ(::vkEnumerateInstanceExtensionProperties("VK_LAYER_TEST_Entrypoints", &property_count, nullptr), VK_SUCCESS);
    EXPECT_EQ(::vkEnumerateInstanceExtensionProperties(nullptr, &property_count, nullptr), VK_ERROR_LAYER_NOT_PRESENT);
    EXPECT_EQ(::vkEnumerateDeviceLayerProperties(VK_NULL_HANDLE, &property_count, nullptr), VK_SUCCESS);
    EXPECT_EQ(::vkEnumerateDeviceExtensionProperties(VK_NULL_HANDLE, nullptr, &property_count, nullptr), VK_SUCCESS);

    EXPECT_NE(::vkGetInstanceProcAddr(VK_NULL_HANDLE, "vkGetInstanceProcAddr"), nullptr);
    EXPECT_EQ(::vkGetInstanceProcAddr(VK_NULL_HANDLE, "vkUnknownFunction"), nullptr);
    EXPECT_EQ(::vkGetDeviceProcAddr(VK_NULL_HANDLE, "vkUnknownFunction"), nullptr);

    VkNegotiateLayerInterface version_interface{
        .sType = LAYER_NEGOTIATE_INTERFACE_STRUCT,
        .pNext = nullptr,
        .loaderLayerInterfaceVersion = 2,
    };
    EXPECT_EQ(::vkNegotiateLoaderLayerInterfaceVersion(&version_interface), VK_SUCCESS);
    EXPECT_EQ(version_interface.loaderLayerInterfaceVersion, 2u);
    EXPECT_NE(version_interface.pfnGetInstanceProcAddr, nullptr);
    EXPECT_NE(version_interface.pfnGetDeviceProcAddr, nullptr);

    VkNegotiateLayerInterface version_one_interface{
        .sType = LAYER_NEGOTIATE_INTERFACE_STRUCT,
        .pNext = nullptr,
        .loaderLayerInterfaceVersion = 1,
    };
    EXPECT_EQ(::vkNegotiateLoaderLayerInterfaceVersion(&version_one_interface), VK_SUCCESS);
    EXPECT_EQ(version_one_interface.loaderLayerInterfaceVersion, 1u);

    VkNegotiateLayerInterface unsupported_version_interface{
        .sType = LAYER_NEGOTIATE_INTERFACE_STRUCT,
        .pNext = nullptr,
        .loaderLayerInterfaceVersion = 0,
    };
    EXPECT_EQ(::vkNegotiateLoaderLayerInterfaceVersion(&unsupported_version_interface), VK_ERROR_INITIALIZATION_FAILED);
}

class OverriddenEntrypointsTestLayer : public LayerBase {
   public:
    explicit OverriddenEntrypointsTestLayer(const LayerManifest* manifest) : manifest_(manifest) {}
    ~OverriddenEntrypointsTestLayer() override = default;

    [[nodiscard]] const LayerManifest* GetLayerManifest() const override { return manifest_; }

    int override_calls = 0;
    VkInstance last_instance = VK_NULL_HANDLE;
    VkDevice last_device = VK_NULL_HANDLE;
    VkPhysicalDevice last_physical_device = VK_NULL_HANDLE;

   protected:
    PFN_vkVoidFunction GetInstanceProcAddr(VkInstance instance, const char* command_name) override {
        ++override_calls;
        last_instance = instance;
        if (command_name && std::strcmp(command_name, "vkInterceptedGipaSentinel") == 0) {
            return nullptr;
        }
        return LayerBase::GetInstanceProcAddr(instance, command_name);
    }

    PFN_vkVoidFunction GetDeviceProcAddr(VkDevice device, const char* command_name) override {
        ++override_calls;
        last_device = device;
        if (command_name && std::strcmp(command_name, "vkInterceptedGdpaSentinel") == 0) {
            return nullptr;
        }
        return LayerBase::GetDeviceProcAddr(device, command_name);
    }

    VkResult CreateInstance(const VkInstanceCreateInfo*, const VkAllocationCallbacks*, VkInstance*) override {
        ++override_calls;
        return VK_EVENT_SET;
    }

    void DestroyInstance(VkInstance instance, const VkAllocationCallbacks*) override {
        ++override_calls;
        last_instance = instance;
    }

    VkResult CreateDevice(VkPhysicalDevice physical_device, const VkDeviceCreateInfo*, const VkAllocationCallbacks*,
                          VkDevice*) override {
        ++override_calls;
        last_physical_device = physical_device;
        return VK_EVENT_SET;
    }

    void DestroyDevice(VkDevice device, const VkAllocationCallbacks*) override {
        ++override_calls;
        last_device = device;
    }

    VkResult EnumerateInstanceLayerProperties(uint32_t*, VkLayerProperties*) override {
        ++override_calls;
        return VK_INCOMPLETE;
    }

    VkResult EnumerateInstanceExtensionProperties(const char*, uint32_t*, VkExtensionProperties*) override {
        ++override_calls;
        return VK_INCOMPLETE;
    }

    VkResult EnumerateDeviceLayerProperties(VkPhysicalDevice physical_device, uint32_t*, VkLayerProperties*) override {
        ++override_calls;
        last_physical_device = physical_device;
        return VK_INCOMPLETE;
    }

    VkResult EnumerateDeviceExtensionProperties(VkPhysicalDevice physical_device, const char*, uint32_t*,
                                                VkExtensionProperties*) override {
        ++override_calls;
        last_physical_device = physical_device;
        return VK_INCOMPLETE;
    }

    VkResult GetPhysicalDeviceToolProperties(VkPhysicalDevice physical_device, uint32_t*,
                                             VkPhysicalDeviceToolPropertiesEXT*) override {
        ++override_calls;
        last_physical_device = physical_device;
        return VK_INCOMPLETE;
    }

   private:
    const LayerManifest* manifest_;
};

TEST(LayerEntrypointsTest, ExportedSymbolsRouteThroughVirtualOverrides) {
    LayerManifest manifest{
        .layer_name = "VK_LAYER_TEST_Entrypoints",
        .tool_properties = VkPhysicalDeviceToolPropertiesEXT{
            .sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TOOL_PROPERTIES_EXT,
        },
    };
    OverriddenEntrypointsTestLayer test_layer(&manifest);
    uint32_t count = 0;

    auto instance = reinterpret_cast<VkInstance>(static_cast<uintptr_t>(0x1234));
    auto device = reinterpret_cast<VkDevice>(static_cast<uintptr_t>(0x5678));
    // The physical device is not registered. The override must receive it unchanged.
    auto physical_device = reinterpret_cast<VkPhysicalDevice>(static_cast<uintptr_t>(0x9ABC));

    EXPECT_EQ(::vkGetInstanceProcAddr(instance, "vkInterceptedGipaSentinel"), nullptr);
    EXPECT_EQ(test_layer.last_instance, instance);
    EXPECT_EQ(::vkGetDeviceProcAddr(device, "vkInterceptedGdpaSentinel"), nullptr);
    EXPECT_EQ(test_layer.last_device, device);
    EXPECT_EQ(::vkEnumerateInstanceLayerProperties(&count, nullptr), VK_INCOMPLETE);
    EXPECT_EQ(::vkEnumerateInstanceExtensionProperties(nullptr, &count, nullptr), VK_INCOMPLETE);
    EXPECT_EQ(::vkEnumerateDeviceLayerProperties(physical_device, &count, nullptr), VK_INCOMPLETE);
    EXPECT_EQ(test_layer.last_physical_device, physical_device);
    test_layer.last_physical_device = VK_NULL_HANDLE;
    EXPECT_EQ(::vkEnumerateDeviceExtensionProperties(physical_device, nullptr, &count, nullptr), VK_INCOMPLETE);
    EXPECT_EQ(test_layer.last_physical_device, physical_device);
    EXPECT_EQ(test_layer.override_calls, 6);
}

// Built-in commands queried via GIPA return Dispatch* thunks and invoke the virtual overrides when called.
TEST(LayerEntrypointsTest, InstanceProcAddrThunksRouteThroughVirtualOverrides) {
    LayerManifest manifest{
        .layer_name = "VK_LAYER_TEST_Entrypoints",
        .tool_properties = VkPhysicalDeviceToolPropertiesEXT{
            .sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TOOL_PROPERTIES_EXT,
        },
    };
    OverriddenEntrypointsTestLayer test_layer(&manifest);
    uint32_t count = 0;

    auto instance = reinterpret_cast<VkInstance>(static_cast<uintptr_t>(0x1234));
    // The physical device is not registered. The override must receive it unchanged.
    auto physical_device = reinterpret_cast<VkPhysicalDevice>(static_cast<uintptr_t>(0x9ABC));

    auto pfn_create_instance =
        reinterpret_cast<PFN_vkCreateInstance>(::vkGetInstanceProcAddr(VK_NULL_HANDLE, "vkCreateInstance"));
    ASSERT_NE(pfn_create_instance, nullptr);
    EXPECT_EQ(pfn_create_instance(nullptr, nullptr, nullptr), VK_EVENT_SET);

    auto pfn_destroy_instance =
        reinterpret_cast<PFN_vkDestroyInstance>(::vkGetInstanceProcAddr(instance, "vkDestroyInstance"));
    ASSERT_NE(pfn_destroy_instance, nullptr);
    test_layer.last_instance = VK_NULL_HANDLE;
    pfn_destroy_instance(instance, nullptr);
    EXPECT_EQ(test_layer.last_instance, instance);

    auto pfn_create_device = reinterpret_cast<PFN_vkCreateDevice>(::vkGetInstanceProcAddr(instance, "vkCreateDevice"));
    ASSERT_NE(pfn_create_device, nullptr);
    test_layer.last_physical_device = VK_NULL_HANDLE;
    EXPECT_EQ(pfn_create_device(physical_device, nullptr, nullptr, nullptr), VK_EVENT_SET);
    EXPECT_EQ(test_layer.last_physical_device, physical_device);

    auto pfn_tool_props = reinterpret_cast<PFN_vkGetPhysicalDeviceToolPropertiesEXT>(
        ::vkGetInstanceProcAddr(instance, "vkGetPhysicalDeviceToolPropertiesEXT"));
    ASSERT_NE(pfn_tool_props, nullptr);
    test_layer.last_physical_device = VK_NULL_HANDLE;
    EXPECT_EQ(pfn_tool_props(physical_device, &count, nullptr), VK_INCOMPLETE);
    EXPECT_EQ(test_layer.last_physical_device, physical_device);
}

// Built-in commands queried via GDPA return Dispatch* thunks and invoke the virtual overrides when called.
TEST(LayerEntrypointsTest, DeviceProcAddrThunksRouteThroughVirtualOverrides) {
    LayerManifest manifest{
        .layer_name = "VK_LAYER_TEST_Entrypoints",
        .tool_properties = VkPhysicalDeviceToolPropertiesEXT{
            .sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TOOL_PROPERTIES_EXT,
        },
    };
    OverriddenEntrypointsTestLayer test_layer(&manifest);

    auto device = reinterpret_cast<VkDevice>(static_cast<uintptr_t>(0x5678));

    auto pfn_gdpa = reinterpret_cast<PFN_vkGetDeviceProcAddr>(::vkGetDeviceProcAddr(device, "vkGetDeviceProcAddr"));
    ASSERT_NE(pfn_gdpa, nullptr);
    test_layer.last_device = VK_NULL_HANDLE;
    EXPECT_EQ(pfn_gdpa(device, "vkInterceptedGdpaSentinel"), nullptr);
    EXPECT_EQ(test_layer.last_device, device);

    auto pfn_destroy_device = reinterpret_cast<PFN_vkDestroyDevice>(::vkGetDeviceProcAddr(device, "vkDestroyDevice"));
    ASSERT_NE(pfn_destroy_device, nullptr);
    test_layer.last_device = VK_NULL_HANDLE;
    pfn_destroy_device(device, nullptr);
    EXPECT_EQ(test_layer.last_device, device);
}

class InstanceLayerPropertiesOnlyTestLayer : public LayerBase {
   public:
    explicit InstanceLayerPropertiesOnlyTestLayer(const LayerManifest* manifest) : manifest_(manifest) {}
    ~InstanceLayerPropertiesOnlyTestLayer() override = default;

    [[nodiscard]] const LayerManifest* GetLayerManifest() const override { return manifest_; }

   protected:
    VkResult EnumerateInstanceLayerProperties(uint32_t*, VkLayerProperties*) override { return VK_INCOMPLETE; }

   private:
    const LayerManifest* manifest_;
};

TEST(LayerEntrypointsTest, DeviceLayerPropertiesUseInstanceLayerPropertiesOverride) {
    LayerManifest manifest{.layer_name = "VK_LAYER_TEST_Entrypoints"};
    InstanceLayerPropertiesOnlyTestLayer test_layer(&manifest);
    uint32_t count = 0;

    auto physical_device = reinterpret_cast<VkPhysicalDevice>(static_cast<uintptr_t>(0x9ABC));

    EXPECT_EQ(::vkEnumerateDeviceLayerProperties(physical_device, &count, nullptr), VK_INCOMPLETE);
}

}  // namespace
}  // namespace layersvt
