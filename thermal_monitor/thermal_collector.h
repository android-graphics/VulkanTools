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

#include <cstdint>
#include <functional>
#include <map>
#include <optional>
#include <utility>
#include <vector>

namespace apa::thermal {

// Mirrors AThermalStatus from <android/thermal.h>, which is not available in the host build that
// unit tests ThermalCollector. main.cpp static_asserts that the values match.
enum class ThermalStatus : int {
    kNone = 0,
    kLight = 1,
    kModerate = 2,
    kSevere = 3,
    kCritical = 4,
    kEmergency = 5,
    kShutdown = 6,
};

// Must match the counter names and scale that the Android Performance Analyzer trace viewer reads.
namespace ThermalConstants {
inline constexpr int kDefaultPollIntervalMs = 1000;
// Polling faster than this would only collect NaNs from the ~1 Hz rate-limited headroom API.
inline constexpr int kMinPollIntervalMs = kDefaultPollIntervalMs;
inline constexpr int kDefaultForecastSeconds = 10;
inline constexpr int kMaxForecastSeconds = 60;
inline constexpr const char* kHeadroomCounter = "sherlock.thermal.headroom";
inline constexpr const char* kHeadroomForecastCounter = "sherlock.thermal.headroom.forecast";
inline constexpr const char* kStatusCounter = "sherlock.thermal.status";
// Atrace counters are integers, so headroom values are emitted multiplied by this.
inline constexpr int64_t kHeadroomScale = 1000;

// Counter names for the thermal statuses that can carry a headroom threshold.
inline constexpr const char* ThresholdCounterName(ThermalStatus status) {
    switch (status) {
        case ThermalStatus::kLight:
            return "sherlock.thermal.headroom.threshold.light";
        case ThermalStatus::kModerate:
            return "sherlock.thermal.headroom.threshold.moderate";
        case ThermalStatus::kSevere:
            return "sherlock.thermal.headroom.threshold.severe";
        case ThermalStatus::kCritical:
            return "sherlock.thermal.headroom.threshold.critical";
        case ThermalStatus::kEmergency:
            return "sherlock.thermal.headroom.threshold.emergency";
        case ThermalStatus::kShutdown:
            return "sherlock.thermal.headroom.threshold.shutdown";
        default:
            return nullptr;
    }
}
}  // namespace ThermalConstants

// Reads framework thermal signals (AThermal / PowerManager). Abstracted so ThermalCollector can be
// unit tested without a device.
class ThermalSource {
   public:
    virtual ~ThermalSource() = default;

    // AThermal_getCurrentThermalStatus(), or nullopt if the device cannot report it.
    virtual std::optional<ThermalStatus> CurrentThermalStatus() = 0;

    // AThermal_getThermalHeadroom(forecast_seconds); 0 asks for the current headroom. The returned
    // headroom is 0.0 with no thermal load and rises with it: 1.0 means the device is (or, for a
    // forecast, will be) throttled at ThermalStatus::kSevere, and values above 1.0 mean it is
    // throttled beyond kSevere. Returns nullopt if the API returns NaN, e.g. when the device does
    // not support headroom or the call was rate-limited.
    virtual std::optional<float> ThermalHeadroom(int forecast_seconds) = 0;

    // Headroom at which each thermal status starts, or empty if the device or OS version cannot
    // report it.
    virtual std::map<ThermalStatus, float> ThermalHeadroomThresholds() = 0;
};

// Samples the framework's thermal state and emits it as trace counters.
// AThermal_getThermalHeadroom() is rate-limited to ~1 Hz across all forecast_seconds values, which
// is why ThermalConstants::kDefaultPollIntervalMs is one second and why, when forecast_seconds is
// positive, current and forecast headroom are sampled on alternating ticks rather than on the same
// tick. A forecast tick that fails emits no headroom at all rather than retrying the current
// headroom, which the rate limit would reject.
class ThermalCollector {
   public:
    using Emitter = std::function<void(const char*, int64_t)>;

    ThermalCollector(ThermalSource& source, Emitter emitter, int forecast_seconds = ThermalConstants::kDefaultForecastSeconds);

    void Sample();

   private:
    using ThresholdList = std::vector<std::pair<const char*, float>>;

    // AThermal_getThermalHeadroom() also returns NaN when it is called too often or the thermal
    // service hiccups, so one failure does not prove that the device cannot forecast.
    static constexpr int kMaxForecastFailures = 3;

    // The thresholds are static for a device, so they are read from source_ once, but re-emitted
    // with every headroom sample because the monitor starts before tracing does and a one-off
    // emission at startup would not land in the trace.
    const ThresholdList& GetThresholds();

    bool EmitHeadroom(const char* counter, std::optional<float> headroom);

    ThermalSource& source_;
    Emitter emitter_;
    int forecast_seconds_;
    std::optional<ThresholdList> thresholds_;
    int tick_ = 0;
    int forecast_failures_ = 0;
    bool forecast_supported_;
};

}  // namespace apa::thermal
