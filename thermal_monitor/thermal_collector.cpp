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

#include <cmath>
#include <utility>

namespace apa::thermal {

ThermalCollector::ThermalCollector(ThermalSource& source, Emitter emit, int forecast_seconds)
    : source_(source), emit_(std::move(emit)), forecast_seconds_(forecast_seconds), forecast_supported_(forecast_seconds > 0) {}

void ThermalCollector::Sample() {
    if (const std::optional<int> status = source_.ThermalStatus(); status.has_value()) {
        emit_(ThermalConstants::kStatusCounter, static_cast<int64_t>(*status));
    }
    if (forecast_supported_ && (tick_++ % 2) == 1) {
        if (EmitHeadroom(ThermalConstants::kHeadroomForecastCounter, source_.ThermalHeadroom(forecast_seconds_))) {
            forecast_failures_ = 0;
        } else if (++forecast_failures_ >= kMaxForecastFailures) {
            forecast_supported_ = false;
        }
        return;
    }
    if (EmitHeadroom(ThermalConstants::kHeadroomCounter, source_.ThermalHeadroom(0))) {
        for (const auto& [name, value] : GetThresholds()) {
            EmitHeadroom(name, value);
        }
    }
}

const ThermalCollector::ThresholdList& ThermalCollector::GetThresholds() {
    if (!thresholds_.has_value()) {
        ThresholdList resolved;
        for (const auto& [status, value] : source_.ThermalHeadroomThresholds()) {
            const char* name = ThermalConstants::ThresholdCounterName(status);
            if (name != nullptr) {
                resolved.emplace_back(name, value);
            }
        }
        thresholds_ = std::move(resolved);
    }
    return *thresholds_;
}

bool ThermalCollector::EmitHeadroom(const char* counter, std::optional<double> headroom) {
    // Headroom is 1.0 at SEVERE throttling, so values this large are bogus; the cap also keeps the
    // scaled value well inside the range of std::llround.
    constexpr double kMaxHeadroom = 1e6;
    if (!headroom.has_value() || !std::isfinite(*headroom) || *headroom < 0.0 || *headroom > kMaxHeadroom) {
        return false;
    }
    emit_(counter, std::llround(*headroom * ThermalConstants::kHeadroomScale));
    return true;
}

}  // namespace apa::thermal
