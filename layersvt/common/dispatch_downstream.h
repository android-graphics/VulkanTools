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

#include "layer_base.h"
#include <vulkan/vulkan.h>
#include <vulkan/utility/vk_dispatch_table.h>
#include <cassert>
#include <type_traits>
#include <utility>

namespace layersvt {

// Trait helper to extract the class type from a member pointer
template <typename MemberType>
struct MemberTraits {
    static_assert(std::is_member_pointer_v<MemberType>,
                  "MemberPointer must be a pointer to a member of VkuInstanceDispatchTable or VkuDeviceDispatchTable");
};

template <typename Class, typename Member>
struct MemberTraits<Member Class::*> {
    using ClassType = Class;
    using MemberType = Member;
};

/**
 * Retrieves a Vulkan command pointer from the downstream dispatch table for a handle without
 * invoking it. The dispatch table type (VkuInstanceDispatchTable or VkuDeviceDispatchTable) is
 * deduced from MemberPointer; Handle must be VkInstance or VkPhysicalDevice for instance commands,
 * and VkDevice, VkQueue, VkCommandBuffer, or VkExternalComputeQueueNV for device commands.
 * Returns the downstream command pointer, or nullptr if the handle is null, unregistered, or its
 * dispatch table slot is null.
 *
 * The lookup uses the dispatch key of the handle. A dispatchable object that the layer creates
 * itself, such as a VkCommandBuffer, gets the key of its device from the callback returned by
 * LayerBase::GetDeviceLoaderDataCallback(). Call that callback, when the loader provides one,
 * before dispatching through such an object.
 */
template <auto MemberPointer, typename Handle>
[[nodiscard]] inline auto GetDownstream(Handle handle) {
    using Traits = MemberTraits<decltype(MemberPointer)>;
    using TableType = typename Traits::ClassType;
    static_assert(std::is_same_v<TableType, VkuInstanceDispatchTable> || std::is_same_v<TableType, VkuDeviceDispatchTable>,
                  "MemberPointer must be a member of VkuInstanceDispatchTable or VkuDeviceDispatchTable");
    TableType* table = nullptr;
    if constexpr (std::is_same_v<TableType, VkuInstanceDispatchTable>) {
        static_assert(std::is_same_v<Handle, VkInstance> || std::is_same_v<Handle, VkPhysicalDevice>,
                      "Instance dispatch table commands require a VkInstance or VkPhysicalDevice handle");
        table = LayerBase::GetInstanceDispatchTable(handle);
    } else {
        static_assert(std::is_same_v<Handle, VkDevice> || std::is_same_v<Handle, VkQueue> ||
                          std::is_same_v<Handle, VkCommandBuffer> || std::is_same_v<Handle, VkExternalComputeQueueNV>,
                      "Device dispatch table commands require a dispatchable device-level handle");
        table = LayerBase::GetDeviceDispatchTable(handle);
    }
    return table != nullptr ? table->*MemberPointer : typename Traits::MemberType{nullptr};
}

/**
 * Forwards a required Vulkan command downstream using the dispatch table.
 * Deduces instance vs. device table and asserts the entry point is non-null.
 * Returns the result of calling the downstream Vulkan command.
 */
template <auto MemberPointer, typename Handle, typename... Args>
inline auto DispatchDownstream(Handle handle, Args&&... args) {
    auto downstream_function = GetDownstream<MemberPointer>(handle);
    assert(downstream_function != nullptr && "Dispatch table and function pointer must exist for valid handle");
    return downstream_function(handle, std::forward<Args>(args)...);
}

/**
 * Forwards a Vulkan command downstream, returning or invoking fallback if the entry point is null.
 * Returns the downstream command result on success, or the evaluated fallback value if the table
 * or command pointer is unavailable.
 */
template <auto MemberPointer, typename Fallback, typename Handle, typename... Args>
inline auto DispatchDownstreamOr(Fallback&& fallback, Handle handle, Args&&... args) {
    using TableType = typename MemberTraits<decltype(MemberPointer)>::ClassType;
    using ReturnType = decltype((std::declval<TableType*>()->*MemberPointer)(handle, std::forward<Args>(args)...));
    if (auto downstream_function = GetDownstream<MemberPointer>(handle)) {
        return static_cast<ReturnType>(downstream_function(handle, std::forward<Args>(args)...));
    }

    if constexpr (std::is_invocable_v<Fallback>) {
        return static_cast<ReturnType>(std::forward<Fallback>(fallback)());
    } else {
        return static_cast<ReturnType>(std::forward<Fallback>(fallback));
    }
}

/**
 * Forwards an optional Vulkan command returning void downstream; does nothing if the downstream
 * entry point is unavailable (e.g. layer-implemented extensions such as VK_EXT_debug_utils).
 */
template <auto MemberPointer, typename Handle, typename... Args>
inline void DispatchDownstreamIfAvailable(Handle handle, Args&&... args) {
    using TableType = typename MemberTraits<decltype(MemberPointer)>::ClassType;
    using ReturnType = decltype((std::declval<TableType*>()->*MemberPointer)(handle, std::forward<Args>(args)...));
    static_assert(std::is_void_v<ReturnType>, "Use DispatchDownstreamOr or DispatchDownstreamOrSuccess for non-void commands");
    DispatchDownstreamOr<MemberPointer>([] {}, handle, std::forward<Args>(args)...);
}

/**
 * Forwards an optional Vulkan command returning VkResult downstream, falling back to VK_SUCCESS.
 * Returns the downstream VkResult on success, or VK_SUCCESS if the downstream command is unavailable.
 */
template <auto MemberPointer, typename Handle, typename... Args>
inline VkResult DispatchDownstreamOrSuccess(Handle handle, Args&&... args) {
    using TableType = typename MemberTraits<decltype(MemberPointer)>::ClassType;
    using ReturnType = decltype((std::declval<TableType*>()->*MemberPointer)(handle, std::forward<Args>(args)...));
    static_assert(std::is_same_v<ReturnType, VkResult>,
                  "DispatchDownstreamOrSuccess can only be used with Vulkan commands returning VkResult");
    return DispatchDownstreamOr<MemberPointer>(VK_SUCCESS, handle, std::forward<Args>(args)...);
}

}  // namespace layersvt
