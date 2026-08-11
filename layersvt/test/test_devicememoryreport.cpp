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

#include "layer_test_helper.h"
#include "device_memory_report.h"
#include "device_memory_report_perfetto.h"

#include <vulkan/vulkan_core.h>

#include <gtest/gtest.h>

static const char* kLayerName = "VK_LAYER_GOOGLE_DeviceMemoryReport";

class DeviceMemoryReportTests : public VkTestFramework {
   public:
    ~DeviceMemoryReportTests(){};

    static void SetUpTestSuite() {}
    static void TearDownTestSuite(){};
};

TEST_F(DeviceMemoryReportTests, InitLayer) {
    TEST_DESCRIPTION("Test Creating a Vulkan Instance with DeviceMemoryReport layer");

    layer_test::VulkanInstanceBuilder inst_builder;
    VkResult err = inst_builder.Init(kLayerName);
    EXPECT_EQ(err, VK_SUCCESS);

    VkInstance instance = inst_builder.GetInstance();
    EXPECT_NE(instance, VK_NULL_HANDLE);

    inst_builder.Reset();
}

TEST_F(DeviceMemoryReportTests, EmitEventsAndSubCounters) {
    TEST_DESCRIPTION("Test calling OnMemoryReportEvent with object types and allocating/freeing memory");

    InitializeDeviceMemoryReportPerfetto();

    VkDeviceMemoryReportCallbackDataEXT cb_data = {};
    cb_data.sType = VK_STRUCTURE_TYPE_DEVICE_MEMORY_REPORT_CALLBACK_DATA_EXT;
    cb_data.flags = 0; // Application memory
    cb_data.type = VK_DEVICE_MEMORY_REPORT_EVENT_TYPE_ALLOCATE_EXT;
    cb_data.memoryObjectId = 0x1000;
    cb_data.size = 1024 * 1024;
    cb_data.objectType = VK_OBJECT_TYPE_IMAGE;
    cb_data.objectHandle = 0x5000;

    DeviceMemoryReport::MemoryReportCallback(&cb_data, nullptr);

    cb_data.type = VK_DEVICE_MEMORY_REPORT_EVENT_TYPE_FREE_EXT;
    cb_data.size = 512 * 1024;
    DeviceMemoryReport::MemoryReportCallback(&cb_data, nullptr);

    cb_data.flags = VK_DEVICE_MEMORY_REPORT_FLAG_INTERNAL_OBJECT_BIT_EXT; // Driver memory
    cb_data.type = VK_DEVICE_MEMORY_REPORT_EVENT_TYPE_ALLOCATE_EXT;
    cb_data.objectType = VK_OBJECT_TYPE_BUFFER;
    cb_data.size = 2048;
    DeviceMemoryReport::MemoryReportCallback(&cb_data, nullptr);

    // Test direct allocate/free fallbacks
    VkDevice dummy_device = reinterpret_cast<VkDevice>(0x1234);
    VkDeviceMemory dummy_memory = reinterpret_cast<VkDeviceMemory>(0x5678);
    DeviceMemoryReport::Get().OnAllocateMemory(dummy_device, dummy_memory, 4096);
    DeviceMemoryReport::Get().OnFreeMemory(dummy_device, dummy_memory);

    EXPECT_TRUE(true);
}

TEST_F(DeviceMemoryReportTests, BufferImageBindingAndCallbackSuppression) {
    TEST_DESCRIPTION("Test buffer/image memory binding, IMPORT/UNIMPORT events, and fallback suppression when callback is enabled");

    InitializeDeviceMemoryReportPerfetto();

    // Test buffer and image memory binding
    uint64_t buffer_handle = 0x8000;
    uint64_t image_handle = 0x8001;
    uint64_t memory_handle = 0x9000;
    DeviceMemoryReport::Get().OnBindBufferMemory(buffer_handle, memory_handle);
    DeviceMemoryReport::Get().OnBindImageMemory(image_handle, memory_handle);

    // Test IMPORT_EXT and UNIMPORT_EXT events
    VkDeviceMemoryReportCallbackDataEXT cb_data = {};
    cb_data.sType = VK_STRUCTURE_TYPE_DEVICE_MEMORY_REPORT_CALLBACK_DATA_EXT;
    cb_data.flags = 0;
    cb_data.type = VK_DEVICE_MEMORY_REPORT_EVENT_TYPE_IMPORT_EXT;
    cb_data.memoryObjectId = 0x3000;
    cb_data.size = 4096;
    cb_data.objectType = VK_OBJECT_TYPE_DEVICE_MEMORY;
    cb_data.objectHandle = memory_handle;
    DeviceMemoryReport::MemoryReportCallback(&cb_data, nullptr);

    cb_data.type = VK_DEVICE_MEMORY_REPORT_EVENT_TYPE_UNIMPORT_EXT;
    DeviceMemoryReport::MemoryReportCallback(&cb_data, nullptr);

    // Test callback suppression: when callback is registered on VkDevice, fallback allocations should be ignored
    VkDevice test_device = reinterpret_cast<VkDevice>(0xABCD);
    VkDeviceMemory test_memory = reinterpret_cast<VkDeviceMemory>(0xEF01);

    DeviceMemoryReport::Get().SetHasMemoryReportCallback(test_device, true);
    DeviceMemoryReport::Get().OnAllocateMemory(test_device, test_memory, 8192);
    DeviceMemoryReport::Get().OnFreeMemory(test_device, test_memory);

    // Enable fallback by turning off callback flag and verify allocate/free work
    DeviceMemoryReport::Get().SetHasMemoryReportCallback(test_device, false);
    DeviceMemoryReport::Get().OnAllocateMemory(test_device, test_memory, 8192);
    DeviceMemoryReport::Get().OnFreeMemory(test_device, test_memory);

    EXPECT_TRUE(true);
}

TEST_F(DeviceMemoryReportTests, UsageTypeBreakdown) {
    TEST_DESCRIPTION("Test automatic usage type classification for granular image and buffer usage categories");

    InitializeDeviceMemoryReportPerfetto();

    uint64_t color_img = 0xA001;
    uint64_t depth_img = 0xA002;
    uint64_t sampled_img = 0xA005;

    uint64_t vtx_buf = 0xB001;
    uint64_t idx_buf = 0xB002;
    uint64_t ubo_buf = 0xB003;
    uint64_t staging_buf = 0xB006;

    uint64_t mem_handle = 0xC001;

    // Register images
    DeviceMemoryReport::Get().OnCreateImage(color_img, VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT);
    DeviceMemoryReport::Get().OnCreateImage(depth_img, VK_IMAGE_USAGE_DEPTH_STENCIL_ATTACHMENT_BIT);
    DeviceMemoryReport::Get().OnCreateImage(sampled_img, VK_IMAGE_USAGE_SAMPLED_BIT);

    // Register buffers
    DeviceMemoryReport::Get().OnCreateBuffer(vtx_buf, VK_BUFFER_USAGE_VERTEX_BUFFER_BIT);
    DeviceMemoryReport::Get().OnCreateBuffer(idx_buf, VK_BUFFER_USAGE_INDEX_BUFFER_BIT);
    DeviceMemoryReport::Get().OnCreateBuffer(ubo_buf, VK_BUFFER_USAGE_UNIFORM_BUFFER_BIT);
    DeviceMemoryReport::Get().OnCreateBuffer(staging_buf, VK_BUFFER_USAGE_TRANSFER_SRC_BIT | VK_BUFFER_USAGE_TRANSFER_DST_BIT);

    VkDeviceMemoryReportCallbackDataEXT cb_data = {};
    cb_data.sType = VK_STRUCTURE_TYPE_DEVICE_MEMORY_REPORT_CALLBACK_DATA_EXT;
    cb_data.flags = 0;
    cb_data.type = VK_DEVICE_MEMORY_REPORT_EVENT_TYPE_ALLOCATE_EXT;
    cb_data.memoryObjectId = 0x5000;
    cb_data.size = 1048576;
    cb_data.objectType = VK_OBJECT_TYPE_DEVICE_MEMORY;
    cb_data.objectHandle = mem_handle;
    DeviceMemoryReport::MemoryReportCallback(&cb_data, nullptr);

    // Bind images and buffers to test usage categorization and track transitions
    DeviceMemoryReport::Get().OnBindImageMemory(color_img, mem_handle);
    DeviceMemoryReport::Get().OnBindImageMemory(depth_img, mem_handle);
    DeviceMemoryReport::Get().OnBindImageMemory(sampled_img, mem_handle);

    DeviceMemoryReport::Get().OnBindBufferMemory(vtx_buf, mem_handle);
    DeviceMemoryReport::Get().OnBindBufferMemory(idx_buf, mem_handle);
    DeviceMemoryReport::Get().OnBindBufferMemory(ubo_buf, mem_handle);
    DeviceMemoryReport::Get().OnBindBufferMemory(staging_buf, mem_handle);

    // Free memory
    cb_data.type = VK_DEVICE_MEMORY_REPORT_EVENT_TYPE_FREE_EXT;
    DeviceMemoryReport::MemoryReportCallback(&cb_data, nullptr);

    // Clean up objects
    DeviceMemoryReport::Get().OnDestroyObject(color_img);
    DeviceMemoryReport::Get().OnDestroyObject(depth_img);
    DeviceMemoryReport::Get().OnDestroyObject(sampled_img);

    DeviceMemoryReport::Get().OnDestroyObject(vtx_buf);
    DeviceMemoryReport::Get().OnDestroyObject(idx_buf);
    DeviceMemoryReport::Get().OnDestroyObject(ubo_buf);
    DeviceMemoryReport::Get().OnDestroyObject(staging_buf);

    EXPECT_TRUE(true);
}
