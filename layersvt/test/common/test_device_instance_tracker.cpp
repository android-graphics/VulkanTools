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

#include "common/device_instance_tracker.h"
#include <gtest/gtest.h>
#include <atomic>
#include <cstring>
#include <thread>
#include <vector>

using namespace layersvt;

TEST(DeviceInstanceTrackerTest, BasicTracking) {
    DeviceInstanceTracker tracker;

    auto mock_instance1 = reinterpret_cast<VkInstance>(static_cast<uintptr_t>(0x1000));
    auto mock_physical_device1 = reinterpret_cast<VkPhysicalDevice>(static_cast<uintptr_t>(0x2001));
    auto mock_physical_device2 = reinterpret_cast<VkPhysicalDevice>(static_cast<uintptr_t>(0x2002));

    EXPECT_EQ(tracker.GetVkInstance(mock_physical_device1), VK_NULL_HANDLE);

    tracker.SetVkInstance(mock_physical_device1, mock_instance1);
    tracker.SetVkInstance(mock_physical_device2, mock_instance1);

    EXPECT_EQ(tracker.GetVkInstance(mock_physical_device1), mock_instance1);
    EXPECT_EQ(tracker.GetVkInstance(mock_physical_device2), mock_instance1);
}

TEST(DeviceInstanceTrackerTest, UnmapPhysicalDevices) {
    DeviceInstanceTracker tracker;

    auto mock_instance1 = reinterpret_cast<VkInstance>(static_cast<uintptr_t>(0x1001));
    auto mock_instance2 = reinterpret_cast<VkInstance>(static_cast<uintptr_t>(0x1002));
    auto mock_physical_device1 = reinterpret_cast<VkPhysicalDevice>(static_cast<uintptr_t>(0x2001));
    auto mock_physical_device2 = reinterpret_cast<VkPhysicalDevice>(static_cast<uintptr_t>(0x2002));

    tracker.SetVkInstance(mock_physical_device1, mock_instance1);
    tracker.SetVkInstance(mock_physical_device2, mock_instance2);

    tracker.UnmapPhysicalDevices(mock_instance1);

    EXPECT_EQ(tracker.GetVkInstance(mock_physical_device1), VK_NULL_HANDLE);
    EXPECT_EQ(tracker.GetVkInstance(mock_physical_device2), mock_instance2);
}

TEST(DeviceInstanceTrackerTest, MapPhysicalDevices) {
    DeviceInstanceTracker tracker;

    void* mock_instance_vtable = reinterpret_cast<void*>(static_cast<uintptr_t>(0xABCDEF01));
    auto mock_instance = reinterpret_cast<VkInstance>(&mock_instance_vtable);
    auto mock_physical_device1 = reinterpret_cast<VkPhysicalDevice>(static_cast<uintptr_t>(0x3001));
    auto mock_physical_device2 = reinterpret_cast<VkPhysicalDevice>(static_cast<uintptr_t>(0x3002));

    PFN_vkGetInstanceProcAddr mock_get_instance_proc_addr = [](VkInstance, const char* function_name) -> PFN_vkVoidFunction {
        if (std::strcmp(function_name, "vkEnumeratePhysicalDevices") == 0) {
            return reinterpret_cast<PFN_vkVoidFunction>(
                +[](VkInstance, uint32_t* physical_device_count, VkPhysicalDevice* physical_devices) -> VkResult {
                    if (!physical_device_count) return VK_ERROR_INITIALIZATION_FAILED;
                    if (!physical_devices) {
                        *physical_device_count = 2;
                        return VK_SUCCESS;
                    }
                    physical_devices[0] = reinterpret_cast<VkPhysicalDevice>(static_cast<uintptr_t>(0x3001));
                    physical_devices[1] = reinterpret_cast<VkPhysicalDevice>(static_cast<uintptr_t>(0x3002));
                    *physical_device_count = 2;
                    return VK_SUCCESS;
                });
        }
        return nullptr;
    };

    tracker.MapPhysicalDevices(mock_instance, mock_get_instance_proc_addr);
    EXPECT_EQ(tracker.GetVkInstance(mock_physical_device1), mock_instance);
    EXPECT_EQ(tracker.GetVkInstance(mock_physical_device2), mock_instance);
}

TEST(DeviceInstanceTrackerTest, ConcurrentAccess) {
    DeviceInstanceTracker tracker;

    constexpr int kNumberOfThreads = 8;
    constexpr int kIterations = 500;
    std::atomic<bool> start_flag{false};
    std::vector<std::thread> threads;

    struct ThreadData {
        VkInstance instance;
        VkPhysicalDevice physical_device1;
        VkPhysicalDevice physical_device2;
    };

    std::vector<ThreadData> thread_data(kNumberOfThreads);
    for (int thread_index = 0; thread_index < kNumberOfThreads; ++thread_index) {
        thread_data[thread_index].instance = reinterpret_cast<VkInstance>(static_cast<uintptr_t>(0x1000 + thread_index * 0x10));
        thread_data[thread_index].physical_device1 = reinterpret_cast<VkPhysicalDevice>(static_cast<uintptr_t>(0x2000 + thread_index * 0x20));
        thread_data[thread_index].physical_device2 = reinterpret_cast<VkPhysicalDevice>(static_cast<uintptr_t>(0x2001 + thread_index * 0x20));
    }

    for (int thread_index = 0; thread_index < kNumberOfThreads; ++thread_index) {
        threads.emplace_back([&, thread_index]() {
            while (!start_flag.load()) {
                std::this_thread::yield();
            }

            const auto& data = thread_data[thread_index];

            for (int iteration = 0; iteration < kIterations; ++iteration) {
                tracker.SetVkInstance(data.physical_device1, data.instance);
                tracker.SetVkInstance(data.physical_device2, data.instance);

                EXPECT_EQ(tracker.GetVkInstance(data.physical_device1), data.instance);
                EXPECT_EQ(tracker.GetVkInstance(data.physical_device2), data.instance);

                int neighbor_index = (thread_index + 1) % kNumberOfThreads;
                (void)tracker.GetVkInstance(thread_data[neighbor_index].physical_device1);

                if ((iteration % 10) == 0) {
                    tracker.UnmapPhysicalDevices(data.instance);
                    EXPECT_EQ(tracker.GetVkInstance(data.physical_device1), VK_NULL_HANDLE);
                    EXPECT_EQ(tracker.GetVkInstance(data.physical_device2), VK_NULL_HANDLE);
                }
            }
        });
    }

    start_flag.store(true);
    for (auto& thread : threads) {
        thread.join();
    }
}

TEST(DeviceInstanceTrackerTest, MapPhysicalDevicesIncomplete) {
    DeviceInstanceTracker tracker;

    void* mock_instance_vtable = reinterpret_cast<void*>(static_cast<uintptr_t>(0xABCDEF02));
    auto mock_instance = reinterpret_cast<VkInstance>(&mock_instance_vtable);
    auto mock_physical_device1 = reinterpret_cast<VkPhysicalDevice>(static_cast<uintptr_t>(0x4001));

    PFN_vkGetInstanceProcAddr mock_get_instance_proc_addr = [](VkInstance, const char* function_name) -> PFN_vkVoidFunction {
        if (std::strcmp(function_name, "vkEnumeratePhysicalDevices") == 0) {
            return reinterpret_cast<PFN_vkVoidFunction>(
                +[](VkInstance, uint32_t* physical_device_count, VkPhysicalDevice* physical_devices) -> VkResult {
                    if (!physical_device_count) return VK_ERROR_INITIALIZATION_FAILED;
                    if (!physical_devices) {
                        *physical_device_count = 1;
                        return VK_SUCCESS;
                    }
                    physical_devices[0] = reinterpret_cast<VkPhysicalDevice>(static_cast<uintptr_t>(0x4001));
                    *physical_device_count = 2;
                    return VK_INCOMPLETE;
                });
        }
        return nullptr;
    };

    tracker.MapPhysicalDevices(mock_instance, mock_get_instance_proc_addr);
    EXPECT_EQ(tracker.GetVkInstance(mock_physical_device1), mock_instance);
}

TEST(DeviceInstanceTrackerTest, MapPhysicalDevicesErrorHandling) {
    DeviceInstanceTracker tracker;

    void* mock_instance_vtable = reinterpret_cast<void*>(static_cast<uintptr_t>(0xABCDEF03));
    auto mock_instance = reinterpret_cast<VkInstance>(&mock_instance_vtable);

    // Missing vkEnumeratePhysicalDevices returns nullptr
    PFN_vkGetInstanceProcAddr missing_proc_addr = [](VkInstance, const char*) -> PFN_vkVoidFunction { return nullptr; };
    tracker.MapPhysicalDevices(mock_instance, missing_proc_addr);

    // vkEnumeratePhysicalDevices returns error
    PFN_vkGetInstanceProcAddr failing_proc_addr = [](VkInstance, const char* function_name) -> PFN_vkVoidFunction {
        if (std::strcmp(function_name, "vkEnumeratePhysicalDevices") == 0) {
            return reinterpret_cast<PFN_vkVoidFunction>(
                +[](VkInstance, uint32_t*, VkPhysicalDevice*) -> VkResult { return VK_ERROR_OUT_OF_HOST_MEMORY; });
        }
        return nullptr;
    };
    tracker.MapPhysicalDevices(mock_instance, failing_proc_addr);
}

