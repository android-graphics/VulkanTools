# Copyright (C) 2026 Google Inc.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

# The sampling policy has no Android dependencies, so it is also built on the host for the unit tests.
add_library(thermal_collector STATIC thermal_collector.cpp thermal_collector.h)
target_include_directories(thermal_collector PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
if(NOT ANDROID)
    # Stands in for the NDK's <android/thermal.h> so that the collector builds off-device.
    target_include_directories(thermal_collector PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/host_stubs)
endif()

if(WIN32 AND (QT_TARGET_TYPE STREQUAL STATIC_LIBRARY))
    set_property(TARGET thermal_collector PROPERTY MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
endif()

if(ANDROID)
    # The Perfetto SDK that the layers use. Built as its own library so that the availability checks
    # below only apply to main.cpp.
    set(PERFETTO_SDK_DIR ${PROJECT_SOURCE_DIR}/layersvt/perfetto)
    add_library(thermal_monitor_perfetto STATIC ${PERFETTO_SDK_DIR}/perfetto.cc)
    target_include_directories(thermal_monitor_perfetto PUBLIC ${PROJECT_SOURCE_DIR}/layersvt)
    target_compile_options(thermal_monitor_perfetto PRIVATE -Wno-deprecated-declarations)
    target_link_libraries(thermal_monitor_perfetto PUBLIC log)

    add_executable(thermal_monitor main.cpp)
    target_link_libraries(thermal_monitor PRIVATE thermal_collector thermal_monitor_perfetto android log)
    # AThermal_getThermalHeadroomThresholds() is API 35, above ANDROID_PLATFORM, so it is weakly
    # linked and guarded by __builtin_available.
    target_compile_definitions(thermal_monitor PRIVATE __ANDROID_UNAVAILABLE_SYMBOLS_ARE_WEAK__)
    target_compile_options(thermal_monitor PRIVATE -Werror=unguarded-availability)
    install(TARGETS thermal_monitor DESTINATION ${CMAKE_INSTALL_BINDIR})
endif()

if(BUILD_TESTS AND NOT ANDROID)
    add_subdirectory(test)
endif()
