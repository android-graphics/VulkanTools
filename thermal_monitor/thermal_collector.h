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

#include <android/thermal.h>

#include <functional>
#include <map>
#include <optional>
#include <utility>
#include <vector>

namespace apa::thermal {

// Must match the track event category and counter names that the Android Performance Analyzer trace
// viewer reads.
namespace ThermalConstants {
// Perfetto track event category that the counters are written to.
inline constexpr const char* kTrackEventCategory = "SherlockThermal";
inline constexpr int kDefaultPollIntervalMs = 1000;
// Polling faster than this would only collect NaNs from the ~1 Hz rate-limited headroom API.
inline constexpr int kMinPollIntervalMs = kDefaultPollIntervalMs;
inline constexpr int kDefaultForecastSeconds = 10;
inline constexpr int kMaxForecastSeconds = 60;
inline constexpr const char* kHeadroomCounter = "sherlock.thermal.headroom";
inline constexpr const char* kHeadroomForecastCounter = "sherlock.thermal.headroom.forecast";
inline constexpr const char* kStatusCounter = "sherlock.thermal.status";

// Counter names for the thermal statuses that can carry a headroom threshold.
inline constexpr const char* ThresholdCounterName(AThermalStatus status) {
    switch (status) {
        case ATHERMAL_STATUS_LIGHT:
            return "sherlock.thermal.headroom.threshold.light";
        case ATHERMAL_STATUS_MODERATE:
            return "sherlock.thermal.headroom.threshold.moderate";
        case ATHERMAL_STATUS_SEVERE:
            return "sherlock.thermal.headroom.threshold.severe";
        case ATHERMAL_STATUS_CRITICAL:
            return "sherlock.thermal.headroom.threshold.critical";
        case ATHERMAL_STATUS_EMERGENCY:
            return "sherlock.thermal.headroom.threshold.emergency";
        case ATHERMAL_STATUS_SHUTDOWN:
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
    virtual std::optional<AThermalStatus> CurrentThermalStatus() = 0;

    // AThermal_getThermalHeadroom(forecast_seconds); 0 asks for the current headroom. The returned
    // headroom is 0.0 with no thermal load and rises with it: 1.0 means the device is (or, for a
    // forecast, will be) throttled at ATHERMAL_STATUS_SEVERE, and values above 1.0 mean it
    // is throttled beyond that. Returns nullopt if the API returns NaN, e.g. when the device does
    // not support headroom or the call was rate-limited.
    virtual std::optional<float> ThermalHeadroom(int forecast_seconds) = 0;

    // Headroom at which each thermal status starts, or empty if the device or OS version cannot
    // report it.
    virtual std::map<AThermalStatus, float> ThermalHeadroomThresholds() = 0;
};

// Samples the framework's thermal state and emits it as trace counters.
//
// AThermal_getThermalHeadroom() is rate-limited to ~1 Hz across all forecast_seconds values, which
// is why ThermalConstants::kDefaultPollIntervalMs is one second and why, when forecast_seconds is
// positive, current and forecast headroom are sampled on alternating ticks rather than on the same
// tick. A forecast tick that fails emits no headroom at all rather than retrying the current
// headroom, which the rate limit would reject.
//
// The headroom thresholds are static for a device, so they are read once, at construction, and
// emitted separately by EmitThresholds() once per tracing session.
class ThermalCollector {
   public:
    using Emitter = std::function<void(const char* counter, double value)>;

    ThermalCollector(ThermalSource& source, Emitter emitter, int forecast_seconds = ThermalConstants::kDefaultForecastSeconds);

    // Emits the current status and either the current or the forecast headroom. Call it once per
    // poll interval.
    void Sample();

    // Emits the device's headroom thresholds. Only reads state that is fixed at construction, so it
    // can be called from another thread than Sample(), as long as the emitter is thread-safe.
    void EmitThresholds() const;

   private:
    using ThresholdList = std::vector<std::pair<const char*, float>>;

    // AThermal_getThermalHeadroom() also returns NaN when it is called too often or the thermal
    // service hiccups, so one failure does not prove that the device cannot forecast.
    static constexpr int kMaxForecastFailures = 3;

    static ThresholdList ReadThresholds(ThermalSource& source);

    bool EmitHeadroom(const char* counter, std::optional<float> headroom) const;

    ThermalSource& source_;
    const Emitter emitter_;
    const ThresholdList thresholds_;
    int forecast_seconds_;
    int tick_ = 0;
    int forecast_failures_ = 0;
    bool forecast_supported_;
};

}  // namespace apa::thermal
