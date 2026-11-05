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

#include "thermal_collector.h"

#include <charconv>
#include <cmath>
#include <cstdlib>
#include <system_error>
#include <utility>

namespace apa::thermal {
namespace {

// The NDK reports headroom as a float, and converting it straight to a double keeps the float's
// rounding error (0.8f becomes 0.800000011920929). Returns the double nearest to the shortest
// decimal that identifies the float instead (0.8).
double ToCounterValue(float value) {
    // std::to_chars gives the shortest form, but the NDK's libc++ has no floating-point
    // std::from_chars, so it is parsed with strtod. Neither the monitor nor the tests change the
    // locale from "C", so the decimal point is '.'.
    char buffer[32];
    if (const auto [end, ec] = std::to_chars(buffer, buffer + sizeof(buffer) - 1, value); ec == std::errc()) {
        *end = '\0';
        return std::strtod(buffer, nullptr);
    }
    return static_cast<double>(value);
}

}  // namespace

ThermalCollector::ThermalCollector(ThermalSource& source, Emitter emitter, int forecast_seconds)
    : source_(source),
      emitter_(std::move(emitter)),
      thresholds_(ReadThresholds(source)),
      forecast_seconds_(forecast_seconds),
      forecast_supported_(forecast_seconds > 0) {}

void ThermalCollector::Sample() {
    if (const std::optional<ThermalStatus> status = source_.CurrentThermalStatus(); status.has_value()) {
        emitter_(ThermalConstants::kStatusCounter, static_cast<double>(*status));
    }
    if (forecast_supported_ && (tick_++ % 2) == 1) {
        if (EmitHeadroom(ThermalConstants::kHeadroomForecastCounter, source_.ThermalHeadroom(forecast_seconds_))) {
            forecast_failures_ = 0;
        } else if (++forecast_failures_ >= kMaxForecastFailures) {
            forecast_supported_ = false;
        }
        return;
    }
    EmitHeadroom(ThermalConstants::kHeadroomCounter, source_.ThermalHeadroom(0));
}

void ThermalCollector::EmitThresholds() const {
    for (const auto& [name, value] : thresholds_) {
        EmitHeadroom(name, value);
    }
}

ThermalCollector::ThresholdList ThermalCollector::ReadThresholds(ThermalSource& source) {
    ThresholdList thresholds;
    for (const auto& [status, value] : source.ThermalHeadroomThresholds()) {
        const char* name = ThermalConstants::ThresholdCounterName(status);
        if (name != nullptr) {
            thresholds.emplace_back(name, value);
        }
    }
    return thresholds;
}

bool ThermalCollector::EmitHeadroom(const char* counter, std::optional<float> headroom) const {
    if (!headroom.has_value() || !std::isfinite(*headroom) || *headroom < 0.0f) {
        return false;
    }
    emitter_(counter, ToCounterValue(*headroom));
    return true;
}

}  // namespace apa::thermal
