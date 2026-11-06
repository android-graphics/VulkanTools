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

ThermalCollector::ThermalCollector(ThermalSource& source, Emitter emitter, int forecast_seconds)
    : source_(source),
      emitter_(std::move(emitter)),
      thresholds_(ReadThresholds(source)),
      forecast_seconds_(forecast_seconds),
      forecast_supported_(forecast_seconds > 0) {}

void ThermalCollector::Sample() {
    if (const std::optional<AThermalStatus> status = source_.CurrentThermalStatus(); status.has_value()) {
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
    emitter_(counter, *headroom);
    return true;
}

}  // namespace apa::thermal
