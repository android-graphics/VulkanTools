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

#include "common/dispatch_downstream.h"
#include "common/layer_base.h"
#include "layer_base_test_peer.h"
#include <gtest/gtest.h>

using namespace layersvt;

TEST(DispatchDownstreamTest, DispatchDownstream) {
    LayerBase layer;
    auto& dispatch_table_manager = LayerBaseTestPeer::GetDispatchTableManager(layer);

    void* mock_instance_vtable = reinterpret_cast<void*>(static_cast<uintptr_t>(0x1111));
    auto mock_instance = reinterpret_cast<VkInstance>(&mock_instance_vtable);

    void* mock_device_vtable = reinterpret_cast<void*>(static_cast<uintptr_t>(0x2222));
    auto mock_device = reinterpret_cast<VkDevice>(&mock_device_vtable);

    // 1. Unregistered handles (no dispatch table present)
    // DispatchDownstreamOrSuccess returns VK_SUCCESS fallback for VkResult commands
    uint32_t count = 0;
    VkResult instance_result =
        DispatchDownstreamOrSuccess<&VkuInstanceDispatchTable::EnumeratePhysicalDevices>(mock_instance, &count, nullptr);
    EXPECT_EQ(instance_result, VK_SUCCESS);

    VkResult device_result = DispatchDownstreamOrSuccess<&VkuDeviceDispatchTable::DeviceWaitIdle>(mock_device);
    EXPECT_EQ(device_result, VK_SUCCESS);

    // void return type safely no-ops with DispatchDownstreamOr
    DispatchDownstreamOr<&VkuInstanceDispatchTable::DestroyInstance>([] {}, mock_instance, nullptr);
    DispatchDownstreamOr<&VkuDeviceDispatchTable::DestroyDevice>([] {}, mock_device, nullptr);

    // DispatchDownstreamOr returns custom fallback value or lambda
    EXPECT_EQ((DispatchDownstreamOr<&VkuDeviceDispatchTable::DeviceWaitIdle>(VK_TIMEOUT, mock_device)), VK_TIMEOUT);
    EXPECT_EQ((DispatchDownstreamOr<&VkuDeviceDispatchTable::DeviceWaitIdle>([] { return VK_NOT_READY; }, mock_device)),
              VK_NOT_READY);

    // 2. Initialized tables with null function pointers (fallback behavior)
    dispatch_table_manager.InitInstanceTable(mock_instance, [](VkInstance, const char*) -> PFN_vkVoidFunction { return nullptr; });
    dispatch_table_manager.InitDeviceTable(mock_device, [](VkDevice, const char*) -> PFN_vkVoidFunction { return nullptr; });

    EXPECT_EQ((DispatchDownstreamOrSuccess<&VkuInstanceDispatchTable::EnumeratePhysicalDevices>(mock_instance, &count, nullptr)),
              VK_SUCCESS);
    EXPECT_EQ((DispatchDownstreamOrSuccess<&VkuDeviceDispatchTable::DeviceWaitIdle>(mock_device)), VK_SUCCESS);
    DispatchDownstreamOr<&VkuInstanceDispatchTable::DestroyInstance>([] {}, mock_instance, nullptr);
    DispatchDownstreamOr<&VkuDeviceDispatchTable::DestroyDevice>([] {}, mock_device, nullptr);

    EXPECT_EQ((DispatchDownstreamOr<&VkuDeviceDispatchTable::DeviceWaitIdle>(VK_TIMEOUT, mock_device)), VK_TIMEOUT);

    // 3. Initialized tables with valid mock function pointers (downstream forwarding)
    static bool instance_function_called = false;
    static bool device_function_called = false;
    instance_function_called = false;
    device_function_called = false;

    auto* instance_table = dispatch_table_manager.GetInstanceDispatchTable(mock_instance);
    ASSERT_NE(instance_table, nullptr);
    instance_table->EnumeratePhysicalDevices = [](VkInstance, uint32_t* physical_device_count, VkPhysicalDevice*) -> VkResult {
        instance_function_called = true;
        if (physical_device_count) *physical_device_count = 42;
        return VK_INCOMPLETE;
    };

    count = 0;
    EXPECT_EQ((DispatchDownstream<&VkuInstanceDispatchTable::EnumeratePhysicalDevices>(mock_instance, &count, nullptr)),
              VK_INCOMPLETE);
    EXPECT_TRUE(instance_function_called);
    EXPECT_EQ(count, 42u);

    auto* device_table = dispatch_table_manager.GetDeviceDispatchTable(mock_device);
    ASSERT_NE(device_table, nullptr);
    device_table->DeviceWaitIdle = [](VkDevice) -> VkResult {
        device_function_called = true;
        return VK_NOT_READY;
    };

    EXPECT_EQ((DispatchDownstream<&VkuDeviceDispatchTable::DeviceWaitIdle>(mock_device)), VK_NOT_READY);
    EXPECT_TRUE(device_function_called);

    // 4. Physical device dispatch and fallback behavior
    void* unknown_physical_device_vtable = reinterpret_cast<void*>(static_cast<uintptr_t>(0x3333));
    auto unknown_physical_device = reinterpret_cast<VkPhysicalDevice>(&unknown_physical_device_vtable);

    // Physical device with an unknown dispatch key must return fallback rather than crashing
    VkPhysicalDeviceProperties properties{};
    DispatchDownstreamOr<&VkuInstanceDispatchTable::GetPhysicalDeviceProperties>([] {}, unknown_physical_device, &properties);

    // Physical device sharing the instance dispatch key forwards downstream through instance table
    void* mock_physical_device_object = mock_instance_vtable;
    auto mock_physical_device = reinterpret_cast<VkPhysicalDevice>(&mock_physical_device_object);

    static bool physical_device_function_called = false;
    physical_device_function_called = false;
    instance_table->GetPhysicalDeviceProperties = [](VkPhysicalDevice, VkPhysicalDeviceProperties* physical_device_properties) {
        physical_device_function_called = true;
        if (physical_device_properties) physical_device_properties->apiVersion = VK_API_VERSION_1_3;
    };

    DispatchDownstream<&VkuInstanceDispatchTable::GetPhysicalDeviceProperties>(mock_physical_device, &properties);
    EXPECT_TRUE(physical_device_function_called);
    EXPECT_EQ(properties.apiVersion, static_cast<uint32_t>(VK_API_VERSION_1_3));
}

TEST(DispatchDownstreamTest, DispatchDownstreamIfAvailable) {
    LayerBase layer;
    auto& dispatch_table_manager = LayerBaseTestPeer::GetDispatchTableManager(layer);

    void* mock_device_vtable = reinterpret_cast<void*>(static_cast<uintptr_t>(0x4444));
    auto mock_device = reinterpret_cast<VkDevice>(&mock_device_vtable);

    // Table exists but the entry point is null: no-op, no crash
    dispatch_table_manager.InitDeviceTable(mock_device, [](VkDevice, const char*) -> PFN_vkVoidFunction { return nullptr; });
    auto* device_table = dispatch_table_manager.GetDeviceDispatchTable(mock_device);
    ASSERT_NE(device_table, nullptr);
    ASSERT_EQ(device_table->DestroyDevice, nullptr);
    DispatchDownstreamIfAvailable<&VkuDeviceDispatchTable::DestroyDevice>(mock_device, nullptr);

    // Entry point set: forwards downstream with the given arguments
    static VkDevice called_device = VK_NULL_HANDLE;
    static const VkAllocationCallbacks* called_allocator = nullptr;
    called_device = VK_NULL_HANDLE;
    called_allocator = nullptr;
    device_table->DestroyDevice = [](VkDevice device, const VkAllocationCallbacks* allocator) {
        called_device = device;
        called_allocator = allocator;
    };

    VkAllocationCallbacks allocator{};
    DispatchDownstreamIfAvailable<&VkuDeviceDispatchTable::DestroyDevice>(mock_device, &allocator);
    EXPECT_EQ(called_device, mock_device);
    EXPECT_EQ(called_allocator, &allocator);
}

TEST(DispatchDownstreamTest, GetDownstream) {
    LayerBase layer;
    auto& dispatch_table_manager = LayerBaseTestPeer::GetDispatchTableManager(layer);

    void* mock_instance_vtable = reinterpret_cast<void*>(static_cast<uintptr_t>(0xA111));
    auto mock_instance = reinterpret_cast<VkInstance>(&mock_instance_vtable);
    void* mock_physical_device_object = mock_instance_vtable;
    auto mock_physical_device = reinterpret_cast<VkPhysicalDevice>(&mock_physical_device_object);

    void* mock_device_vtable = reinterpret_cast<void*>(static_cast<uintptr_t>(0xB222));
    auto mock_device = reinterpret_cast<VkDevice>(&mock_device_vtable);
    void* mock_queue_object = mock_device_vtable;
    auto mock_queue = reinterpret_cast<VkQueue>(&mock_queue_object);
    void* mock_command_buffer_object = mock_device_vtable;
    auto mock_command_buffer = reinterpret_cast<VkCommandBuffer>(&mock_command_buffer_object);

    // Typed null handles return nullptr for both instance and device commands.
    EXPECT_EQ(GetDownstream<&VkuInstanceDispatchTable::EnumeratePhysicalDevices>(VkInstance{VK_NULL_HANDLE}), nullptr);
    EXPECT_EQ(GetDownstream<&VkuInstanceDispatchTable::EnumerateDeviceExtensionProperties>(VkPhysicalDevice{VK_NULL_HANDLE}),
              nullptr);
    EXPECT_EQ(GetDownstream<&VkuDeviceDispatchTable::DeviceWaitIdle>(VkDevice{VK_NULL_HANDLE}), nullptr);
    EXPECT_EQ(GetDownstream<&VkuDeviceDispatchTable::QueueWaitIdle>(VkQueue{VK_NULL_HANDLE}), nullptr);
    EXPECT_EQ(GetDownstream<&VkuDeviceDispatchTable::EndCommandBuffer>(VkCommandBuffer{VK_NULL_HANDLE}), nullptr);

    // Unregistered handles return nullptr.
    EXPECT_EQ(GetDownstream<&VkuInstanceDispatchTable::EnumeratePhysicalDevices>(mock_instance), nullptr);
    EXPECT_EQ(GetDownstream<&VkuInstanceDispatchTable::EnumerateDeviceExtensionProperties>(mock_physical_device), nullptr);
    EXPECT_EQ(GetDownstream<&VkuDeviceDispatchTable::DeviceWaitIdle>(mock_device), nullptr);
    EXPECT_EQ(GetDownstream<&VkuDeviceDispatchTable::QueueWaitIdle>(mock_queue), nullptr);
    EXPECT_EQ(GetDownstream<&VkuDeviceDispatchTable::EndCommandBuffer>(mock_command_buffer), nullptr);

    // Registered handles with null entry points return nullptr.
    dispatch_table_manager.InitInstanceTable(mock_instance, [](VkInstance, const char*) -> PFN_vkVoidFunction { return nullptr; });
    dispatch_table_manager.InitDeviceTable(mock_device, [](VkDevice, const char*) -> PFN_vkVoidFunction { return nullptr; });

    EXPECT_EQ(GetDownstream<&VkuInstanceDispatchTable::EnumeratePhysicalDevices>(mock_instance), nullptr);
    EXPECT_EQ(GetDownstream<&VkuInstanceDispatchTable::EnumerateDeviceExtensionProperties>(mock_physical_device), nullptr);
    EXPECT_EQ(GetDownstream<&VkuDeviceDispatchTable::DeviceWaitIdle>(mock_device), nullptr);
    EXPECT_EQ(GetDownstream<&VkuDeviceDispatchTable::QueueWaitIdle>(mock_queue), nullptr);
    EXPECT_EQ(GetDownstream<&VkuDeviceDispatchTable::EndCommandBuffer>(mock_command_buffer), nullptr);

    // Registered handles with populated entry points return the expected function pointers.
    const PFN_vkEnumeratePhysicalDevices enumerate_physical_devices = [](VkInstance, uint32_t*, VkPhysicalDevice*) -> VkResult {
        return VK_SUCCESS;
    };
    const PFN_vkEnumerateDeviceExtensionProperties enumerate_device_extensions =
        [](VkPhysicalDevice, const char*, uint32_t*, VkExtensionProperties*) -> VkResult { return VK_SUCCESS; };
    const PFN_vkDeviceWaitIdle device_wait_idle = [](VkDevice) -> VkResult { return VK_SUCCESS; };
    const PFN_vkQueueWaitIdle queue_wait_idle = [](VkQueue) -> VkResult { return VK_SUCCESS; };
    const PFN_vkEndCommandBuffer end_command_buffer = [](VkCommandBuffer) -> VkResult { return VK_SUCCESS; };

    auto* instance_table = dispatch_table_manager.GetInstanceDispatchTable(mock_instance);
    auto* device_table = dispatch_table_manager.GetDeviceDispatchTable(mock_device);
    ASSERT_NE(instance_table, nullptr);
    ASSERT_NE(device_table, nullptr);
    instance_table->EnumeratePhysicalDevices = enumerate_physical_devices;
    instance_table->EnumerateDeviceExtensionProperties = enumerate_device_extensions;
    device_table->DeviceWaitIdle = device_wait_idle;
    device_table->QueueWaitIdle = queue_wait_idle;
    device_table->EndCommandBuffer = end_command_buffer;

    EXPECT_EQ(GetDownstream<&VkuInstanceDispatchTable::EnumeratePhysicalDevices>(mock_instance), enumerate_physical_devices);
    EXPECT_EQ(GetDownstream<&VkuInstanceDispatchTable::EnumerateDeviceExtensionProperties>(mock_instance),
              enumerate_device_extensions);
    EXPECT_EQ(GetDownstream<&VkuInstanceDispatchTable::EnumerateDeviceExtensionProperties>(mock_physical_device),
              enumerate_device_extensions);
    EXPECT_EQ(GetDownstream<&VkuDeviceDispatchTable::DeviceWaitIdle>(mock_device), device_wait_idle);
    EXPECT_EQ(GetDownstream<&VkuDeviceDispatchTable::QueueWaitIdle>(mock_device), queue_wait_idle);
    EXPECT_EQ(GetDownstream<&VkuDeviceDispatchTable::QueueWaitIdle>(mock_queue), queue_wait_idle);
    EXPECT_EQ(GetDownstream<&VkuDeviceDispatchTable::EndCommandBuffer>(mock_command_buffer), end_command_buffer);
}
