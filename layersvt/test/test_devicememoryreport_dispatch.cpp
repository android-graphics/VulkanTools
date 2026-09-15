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

// Unit tests for the memory binding entry points of the DeviceMemoryReport layer.
//
// The layer's vk* entry points are linked directly into this test binary (the Vulkan loader is
// deliberately not linked), and every fake VkDevice is given a dispatch table built from the stub
// driver below. That makes it possible to exercise the layer's interception logic without a real
// Vulkan implementation, including the case where the driver underneath the layer does not
// implement an entry point at all and its dispatch table slot is therefore null.

#include "device_memory_report.h"
#include "vk_layer_table.h"

#include <vulkan/vulkan.h>

#include <gtest/gtest.h>

#include <cstdint>
#include <set>
#include <string>

namespace {

// Sizes returned by the stub driver's memory requirement queries.
VkDeviceSize g_buffer_requirements_size = 0;
VkDeviceSize g_image_requirements_size = 0;

// Number of times the stub driver's memory requirement queries were called.
int g_buffer_requirements_queries = 0;
int g_image_requirements_queries = 0;

// Entry points the stub driver does not implement. Their dispatch table slots stay null, which is
// what the layer sees when the driver (or an ICD without the relevant extension) lacks a command.
std::set<std::string> g_unimplemented;

template <typename HandleType>
HandleType MakeHandle(uintptr_t value) {
    return reinterpret_cast<HandleType>(value);
}

template <typename HandleType>
uint64_t AsObjectHandle(HandleType handle) {
    return reinterpret_cast<uint64_t>(handle);
}

uintptr_t g_next_handle = 0x10000;

VKAPI_ATTR VkResult VKAPI_CALL StubCreateImage(VkDevice, const VkImageCreateInfo*, const VkAllocationCallbacks*, VkImage* pImage) {
    if (pImage != nullptr) {
        *pImage = MakeHandle<VkImage>(++g_next_handle);
    }
    return VK_SUCCESS;
}

VKAPI_ATTR void VKAPI_CALL StubDestroyImage(VkDevice, VkImage, const VkAllocationCallbacks*) {}

VKAPI_ATTR VkResult VKAPI_CALL StubAllocateMemory(VkDevice, const VkMemoryAllocateInfo*, const VkAllocationCallbacks*, VkDeviceMemory* pMemory) {
    if (pMemory != nullptr) {
        *pMemory = MakeHandle<VkDeviceMemory>(++g_next_handle);
    }
    return VK_SUCCESS;
}

VKAPI_ATTR void VKAPI_CALL StubFreeMemory(VkDevice, VkDeviceMemory, const VkAllocationCallbacks*) {}

VKAPI_ATTR VkResult VKAPI_CALL StubBindBufferMemory(VkDevice, VkBuffer, VkDeviceMemory, VkDeviceSize) { return VK_SUCCESS; }

VKAPI_ATTR VkResult VKAPI_CALL StubBindImageMemory(VkDevice, VkImage, VkDeviceMemory, VkDeviceSize) { return VK_SUCCESS; }

VKAPI_ATTR VkResult VKAPI_CALL StubBindBufferMemory2(VkDevice, uint32_t, const VkBindBufferMemoryInfo*) { return VK_SUCCESS; }

VKAPI_ATTR VkResult VKAPI_CALL StubBindImageMemory2(VkDevice, uint32_t, const VkBindImageMemoryInfo*) { return VK_SUCCESS; }

VKAPI_ATTR void VKAPI_CALL StubGetBufferMemoryRequirements(VkDevice, VkBuffer, VkMemoryRequirements* pMemoryRequirements) {
    ++g_buffer_requirements_queries;
    pMemoryRequirements->size = g_buffer_requirements_size;
    pMemoryRequirements->alignment = 256;
    pMemoryRequirements->memoryTypeBits = 1;
}

VKAPI_ATTR void VKAPI_CALL StubGetImageMemoryRequirements(VkDevice, VkImage, VkMemoryRequirements* pMemoryRequirements) {
    ++g_image_requirements_queries;
    pMemoryRequirements->size = g_image_requirements_size;
    pMemoryRequirements->alignment = 256;
    pMemoryRequirements->memoryTypeBits = 1;
}

VKAPI_ATTR PFN_vkVoidFunction VKAPI_CALL StubGetDeviceProcAddr(VkDevice, const char* pName) {
    if (pName == nullptr) return nullptr;
    const std::string name(pName);
    if (g_unimplemented.count(name) != 0) return nullptr;

    if (name == "vkCreateImage") return reinterpret_cast<PFN_vkVoidFunction>(StubCreateImage);
    if (name == "vkDestroyImage") return reinterpret_cast<PFN_vkVoidFunction>(StubDestroyImage);
    if (name == "vkAllocateMemory") return reinterpret_cast<PFN_vkVoidFunction>(StubAllocateMemory);
    if (name == "vkFreeMemory") return reinterpret_cast<PFN_vkVoidFunction>(StubFreeMemory);
    if (name == "vkBindBufferMemory") return reinterpret_cast<PFN_vkVoidFunction>(StubBindBufferMemory);
    if (name == "vkBindImageMemory") return reinterpret_cast<PFN_vkVoidFunction>(StubBindImageMemory);
    if (name == "vkBindBufferMemory2" || name == "vkBindBufferMemory2KHR") {
        return reinterpret_cast<PFN_vkVoidFunction>(StubBindBufferMemory2);
    }
    if (name == "vkBindImageMemory2" || name == "vkBindImageMemory2KHR") {
        return reinterpret_cast<PFN_vkVoidFunction>(StubBindImageMemory2);
    }
    if (name == "vkGetBufferMemoryRequirements") return reinterpret_cast<PFN_vkVoidFunction>(StubGetBufferMemoryRequirements);
    if (name == "vkGetImageMemoryRequirements") return reinterpret_cast<PFN_vkVoidFunction>(StubGetImageMemoryRequirements);

    // Everything else is not implemented by the stub driver.
    return nullptr;
}

// A dispatchable Vulkan object begins with a pointer to its dispatch table, and the layer uses that
// pointer as the key into its own dispatch table map. This fake device therefore just points at
// itself, which also gives every instance a distinct key.
class FakeDevice {
   public:
    FakeDevice() {
        dispatch_key_ = this;
        initDeviceTable(handle(), StubGetDeviceProcAddr);
    }

    ~FakeDevice() { destroy_device_dispatch_table(get_dispatch_key(handle())); }

    FakeDevice(const FakeDevice&) = delete;
    FakeDevice& operator=(const FakeDevice&) = delete;

    VkDevice handle() { return reinterpret_cast<VkDevice>(this); }

   private:
    void* dispatch_key_ = nullptr;
};

class DeviceMemoryReportDispatchTests : public ::testing::Test {
   protected:
    void SetUp() override {
        g_buffer_requirements_size = 0;
        g_image_requirements_size = 0;
        g_buffer_requirements_queries = 0;
        g_image_requirements_queries = 0;
        g_unimplemented.clear();
    }
};

TEST_F(DeviceMemoryReportDispatchTests, BindBufferMemoryQueriesUnknownResourceSize) {
    // A buffer whose size was never recorded (for example when the application created it before
    // the layer was active) must have its size queried from the driver at bind time, otherwise the
    // suballocation cannot be sized and the binding is dropped.
    FakeDevice device;
    VkBuffer buffer = MakeHandle<VkBuffer>(0xB1000);
    VkDeviceMemory memory = MakeHandle<VkDeviceMemory>(0xB1001);

    ASSERT_EQ(DeviceMemoryReport::Get().GetRecordedResourceSize(AsObjectHandle(buffer)), 0u);

    g_buffer_requirements_size = 4096;
    EXPECT_EQ(vkBindBufferMemory(device.handle(), buffer, memory, 0), VK_SUCCESS);

    EXPECT_EQ(g_buffer_requirements_queries, 1);
    EXPECT_EQ(DeviceMemoryReport::Get().GetRecordedResourceSize(AsObjectHandle(buffer)), 4096u);
}

TEST_F(DeviceMemoryReportDispatchTests, BindImageMemoryQueriesUnknownResourceSize) {
    FakeDevice device;
    VkImage image = MakeHandle<VkImage>(0xB2000);
    VkDeviceMemory memory = MakeHandle<VkDeviceMemory>(0xB2001);

    ASSERT_EQ(DeviceMemoryReport::Get().GetRecordedResourceSize(AsObjectHandle(image)), 0u);

    g_image_requirements_size = 65536;
    EXPECT_EQ(vkBindImageMemory(device.handle(), image, memory, 0), VK_SUCCESS);

    EXPECT_EQ(g_image_requirements_queries, 1);
    EXPECT_EQ(DeviceMemoryReport::Get().GetRecordedResourceSize(AsObjectHandle(image)), 65536u);
}

TEST_F(DeviceMemoryReportDispatchTests, BindMemory2QueriesUnknownResourceSizes) {
    FakeDevice device;
    VkDeviceMemory memory = MakeHandle<VkDeviceMemory>(0xB3000);

    VkBuffer buffer = MakeHandle<VkBuffer>(0xB3001);
    VkBuffer buffer_khr = MakeHandle<VkBuffer>(0xB3002);
    VkImage image = MakeHandle<VkImage>(0xB3003);
    VkImage image_khr = MakeHandle<VkImage>(0xB3004);

    g_buffer_requirements_size = 1024;
    g_image_requirements_size = 8192;

    VkBindBufferMemoryInfo buffer_bind = {};
    buffer_bind.sType = VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_INFO;
    buffer_bind.buffer = buffer;
    buffer_bind.memory = memory;
    buffer_bind.memoryOffset = 0;
    EXPECT_EQ(vkBindBufferMemory2(device.handle(), 1, &buffer_bind), VK_SUCCESS);

    buffer_bind.buffer = buffer_khr;
    buffer_bind.memoryOffset = 1024;
    EXPECT_EQ(vkBindBufferMemory2KHR(device.handle(), 1, &buffer_bind), VK_SUCCESS);

    VkBindImageMemoryInfo image_bind = {};
    image_bind.sType = VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_INFO;
    image_bind.image = image;
    image_bind.memory = memory;
    image_bind.memoryOffset = 8192;
    EXPECT_EQ(vkBindImageMemory2(device.handle(), 1, &image_bind), VK_SUCCESS);

    image_bind.image = image_khr;
    image_bind.memoryOffset = 16384;
    EXPECT_EQ(vkBindImageMemory2KHR(device.handle(), 1, &image_bind), VK_SUCCESS);

    EXPECT_EQ(g_buffer_requirements_queries, 2);
    EXPECT_EQ(g_image_requirements_queries, 2);
    EXPECT_EQ(DeviceMemoryReport::Get().GetRecordedResourceSize(AsObjectHandle(buffer)), 1024u);
    EXPECT_EQ(DeviceMemoryReport::Get().GetRecordedResourceSize(AsObjectHandle(buffer_khr)), 1024u);
    EXPECT_EQ(DeviceMemoryReport::Get().GetRecordedResourceSize(AsObjectHandle(image)), 8192u);
    EXPECT_EQ(DeviceMemoryReport::Get().GetRecordedResourceSize(AsObjectHandle(image_khr)), 8192u);
}

TEST_F(DeviceMemoryReportDispatchTests, BindMemoryKeepsAlreadyRecordedSizes) {
    // Sizes that are already known must not be re-queried or overwritten at bind time.
    FakeDevice device;
    VkBuffer buffer = MakeHandle<VkBuffer>(0xB4000);
    VkImage image = MakeHandle<VkImage>(0xB4001);
    VkDeviceMemory memory = MakeHandle<VkDeviceMemory>(0xB4002);

    DeviceMemoryReport::Get().OnRecordResourceSize(AsObjectHandle(buffer), 2048);
    DeviceMemoryReport::Get().OnRecordResourceSize(AsObjectHandle(image), 4096);

    g_buffer_requirements_size = 999;
    g_image_requirements_size = 999;

    EXPECT_EQ(vkBindBufferMemory(device.handle(), buffer, memory, 0), VK_SUCCESS);
    EXPECT_EQ(vkBindImageMemory(device.handle(), image, memory, 2048), VK_SUCCESS);

    EXPECT_EQ(g_buffer_requirements_queries, 0);
    EXPECT_EQ(g_image_requirements_queries, 0);
    EXPECT_EQ(DeviceMemoryReport::Get().GetRecordedResourceSize(AsObjectHandle(buffer)), 2048u);
    EXPECT_EQ(DeviceMemoryReport::Get().GetRecordedResourceSize(AsObjectHandle(image)), 4096u);
}

TEST_F(DeviceMemoryReportDispatchTests, BindMemoryReportsMissingDispatchEntries) {
    // When the driver below the layer does not provide a bind entry point, the layer must report
    // that rather than calling through a null dispatch table entry.
    g_unimplemented = {"vkBindBufferMemory",  "vkBindImageMemory",      "vkBindBufferMemory2",
                       "vkBindImageMemory2",  "vkBindBufferMemory2KHR", "vkBindImageMemory2KHR"};
    FakeDevice device;

    VkBuffer buffer = MakeHandle<VkBuffer>(0xB5000);
    VkImage image = MakeHandle<VkImage>(0xB5001);
    VkDeviceMemory memory = MakeHandle<VkDeviceMemory>(0xB5002);

    g_buffer_requirements_size = 4096;
    g_image_requirements_size = 4096;

    EXPECT_EQ(vkBindBufferMemory(device.handle(), buffer, memory, 0), VK_ERROR_EXTENSION_NOT_PRESENT);
    EXPECT_EQ(vkBindImageMemory(device.handle(), image, memory, 0), VK_ERROR_EXTENSION_NOT_PRESENT);

    VkBindBufferMemoryInfo buffer_bind = {};
    buffer_bind.sType = VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_INFO;
    buffer_bind.buffer = buffer;
    buffer_bind.memory = memory;
    EXPECT_EQ(vkBindBufferMemory2(device.handle(), 1, &buffer_bind), VK_ERROR_EXTENSION_NOT_PRESENT);
    EXPECT_EQ(vkBindBufferMemory2KHR(device.handle(), 1, &buffer_bind), VK_ERROR_EXTENSION_NOT_PRESENT);

    VkBindImageMemoryInfo image_bind = {};
    image_bind.sType = VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_INFO;
    image_bind.image = image;
    image_bind.memory = memory;
    EXPECT_EQ(vkBindImageMemory2(device.handle(), 1, &image_bind), VK_ERROR_EXTENSION_NOT_PRESENT);
    EXPECT_EQ(vkBindImageMemory2KHR(device.handle(), 1, &image_bind), VK_ERROR_EXTENSION_NOT_PRESENT);

    // Failed bindings must not leave any tracking behind.
    EXPECT_EQ(DeviceMemoryReport::Get().GetRecordedResourceSize(AsObjectHandle(buffer)), 0u);
    EXPECT_EQ(DeviceMemoryReport::Get().GetRecordedResourceSize(AsObjectHandle(image)), 0u);
}

TEST_F(DeviceMemoryReportDispatchTests, DisjointImageFallsBackToAllocationSize) {
    // When an image is created with VK_IMAGE_CREATE_DISJOINT_BIT (for example, when an app
    // queries requirements upfront via vkGetDeviceImageMemoryRequirements and skips
    // post-creation vkGetImageMemoryRequirements2), the layer skips vkGetImageMemoryRequirements
    // at creation time.
    //
    // At bind time, its recorded size is 0. The layer must fall back to the owning allocation's
    // total size rather than dropping the suballocation from tracking.
    FakeDevice device;

    // Simulate stub driver returning 0 for legacy non-plane requirements on disjoint image.
    g_image_requirements_size = 0;

    VkImageCreateInfo image_ci = {};
    image_ci.sType = VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO;
    image_ci.flags = VK_IMAGE_CREATE_DISJOINT_BIT;
    image_ci.imageType = VK_IMAGE_TYPE_2D;
    image_ci.format = VK_FORMAT_G8_B8R8_2PLANE_420_UNORM;
    image_ci.extent = {1920, 1080, 1};
    image_ci.mipLevels = 1;
    image_ci.arrayLayers = 1;
    image_ci.samples = VK_SAMPLE_COUNT_1_BIT;
    image_ci.usage = VK_IMAGE_USAGE_SAMPLED_BIT;

    VkImage image = VK_NULL_HANDLE;
    EXPECT_EQ(vkCreateImage(device.handle(), &image_ci, nullptr, &image), VK_SUCCESS);
    EXPECT_NE(image, VK_NULL_HANDLE);

    // Image size was not recorded at creation time because it is disjoint.
    EXPECT_EQ(DeviceMemoryReport::Get().GetRecordedResourceSize(AsObjectHandle(image)), 0u);

    const VkDeviceSize kAllocSize = 65536;
    VkMemoryAllocateInfo alloc_info = {};
    alloc_info.sType = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;
    alloc_info.allocationSize = kAllocSize;
    alloc_info.memoryTypeIndex = 0;

    VkDeviceMemory memory = VK_NULL_HANDLE;
    EXPECT_EQ(vkAllocateMemory(device.handle(), &alloc_info, nullptr, &memory), VK_SUCCESS);
    EXPECT_NE(memory, VK_NULL_HANDLE);

    // Initial state before binding: the entire allocation is unbound headroom.
    EXPECT_EQ(DeviceMemoryReport::Get().GetUsageMemoryBytes("vulkan.mem.app.usage.unbound_memory"), kAllocSize);
    EXPECT_EQ(DeviceMemoryReport::Get().GetUsageMemoryBytes("vulkan.mem.app.usage.static_texture"), 0u);

    // Bind disjoint image plane memory via vkBindImageMemory2 without querying vkGetImageMemoryRequirements2.
    VkBindImagePlaneMemoryInfo plane_info = {};
    plane_info.sType = VK_STRUCTURE_TYPE_BIND_IMAGE_PLANE_MEMORY_INFO;
    plane_info.planeAspect = VK_IMAGE_ASPECT_PLANE_0_BIT;

    VkBindImageMemoryInfo bind_info = {};
    bind_info.sType = VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_INFO;
    bind_info.pNext = &plane_info;
    bind_info.image = image;
    bind_info.memory = memory;
    bind_info.memoryOffset = 0;

    EXPECT_EQ(vkBindImageMemory2(device.handle(), 1, &bind_info), VK_SUCCESS);

    // After hardening:
    // - Texture counter receives the suballocation sized to kAllocSize.
    // - Unbound memory drops to 0.
    EXPECT_EQ(DeviceMemoryReport::Get().GetUsageMemoryBytes("vulkan.mem.app.usage.static_texture"), kAllocSize);
    EXPECT_EQ(DeviceMemoryReport::Get().GetUsageMemoryBytes("vulkan.mem.app.usage.unbound_memory"), 0u);

    // Clean up
    vkDestroyImage(device.handle(), image, nullptr);
    vkFreeMemory(device.handle(), memory, nullptr);

    EXPECT_EQ(DeviceMemoryReport::Get().GetUsageMemoryBytes("vulkan.mem.app.usage.static_texture"), 0u);
    EXPECT_EQ(DeviceMemoryReport::Get().GetUsageMemoryBytes("vulkan.mem.app.usage.unbound_memory"), 0u);
}

}  // namespace
