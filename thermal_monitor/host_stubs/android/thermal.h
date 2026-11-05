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

// Host-only stand-in for the NDK's <android/thermal.h>, so that ThermalCollector, which only needs
// the AThermalStatus type, can be built and unit tested off-device. Only on the include path for
// non-Android builds; Android builds use the real NDK header. The values are part of the NDK ABI.

#pragma once

enum AThermalStatus {
    ATHERMAL_STATUS_ERROR = -1,
    ATHERMAL_STATUS_NONE = 0,
    ATHERMAL_STATUS_LIGHT = 1,
    ATHERMAL_STATUS_MODERATE = 2,
    ATHERMAL_STATUS_SEVERE = 3,
    ATHERMAL_STATUS_CRITICAL = 4,
    ATHERMAL_STATUS_EMERGENCY = 5,
    ATHERMAL_STATUS_SHUTDOWN = 6,
};
typedef enum AThermalStatus AThermalStatus;
