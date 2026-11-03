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

// Counter names for the AThermalStatus / PowerManager.THERMAL_STATUS_* values that can carry a
// headroom threshold.
inline constexpr const char* ThresholdCounterName(int status) {
    switch (status) {
        case 1:
            return "sherlock.thermal.headroom.threshold.light";
        case 2:
            return "sherlock.thermal.headroom.threshold.moderate";
        case 3:
            return "sherlock.thermal.headroom.threshold.severe";
        case 4:
            return "sherlock.thermal.headroom.threshold.critical";
        case 5:
            return "sherlock.thermal.headroom.threshold.emergency";
        case 6:
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

    virtual std::optional<int> ThermalStatus() = 0;

    // AThermal_getThermalHeadroom(forecast_seconds); 0 asks for the current headroom.
    virtual std::optional<double> ThermalHeadroom(int forecast_seconds) = 0;

    // Headroom at which each THERMAL_STATUS_* starts, or empty if the device or OS version cannot
    // report it.
    virtual std::map<int, double> ThermalHeadroomThresholds() = 0;
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

    ThermalCollector(ThermalSource& source, Emitter emit, int forecast_seconds = ThermalConstants::kDefaultForecastSeconds);

    void Sample();

   private:
    using ThresholdList = std::vector<std::pair<const char*, double>>;

    // AThermal_getThermalHeadroom() also returns NaN when it is called too often or the thermal
    // service hiccups, so one failure does not prove that the device cannot forecast.
    static constexpr int kMaxForecastFailures = 3;

    // The thresholds are static for a device, so they are read from source_ once, but re-emitted
    // with every headroom sample because the monitor starts before tracing does and a one-off
    // emission at startup would not land in the trace.
    const ThresholdList& GetThresholds();

    bool EmitHeadroom(const char* counter, std::optional<double> headroom);

    ThermalSource& source_;
    Emitter emit_;
    int forecast_seconds_;
    std::optional<ThresholdList> thresholds_;
    int tick_ = 0;
    int forecast_failures_ = 0;
    bool forecast_supported_;
};

}  // namespace apa::thermal
