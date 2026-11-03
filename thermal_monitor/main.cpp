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

#include <android/log.h>
#include <android/thermal.h>
#include <android/trace.h>
#include <poll.h>

#include <algorithm>
#include <charconv>
#include <cmath>
#include <csignal>
#include <cstring>
#include <map>
#include <optional>
#include <string_view>

namespace apa::thermal {
namespace {

constexpr const char* kLogTag = "ThermalMonitor";

// Queries the Android framework's thermal state via the NDK AThermal API in libandroid.so.
// The binary targets API 31 (see scripts/android.py), which covers everything except
// AThermal_getThermalHeadroomThresholds() (API 35). That symbol is weakly linked
// (__ANDROID_UNAVAILABLE_SYMBOLS_ARE_WEAK__) and guarded by __builtin_available.
class NdkThermalSource final : public ThermalSource {
   public:
    NdkThermalSource() : manager_(AThermal_acquireManager()) {}

    ~NdkThermalSource() override {
        if (manager_ != nullptr) {
            AThermal_releaseManager(manager_);
        }
    }

    NdkThermalSource(const NdkThermalSource&) = delete;
    NdkThermalSource& operator=(const NdkThermalSource&) = delete;

    [[nodiscard]] bool IsValid() const { return manager_ != nullptr; }

    std::optional<int> ThermalStatus() override {
        const AThermalStatus status = AThermal_getCurrentThermalStatus(manager_);
        if (status <= ATHERMAL_STATUS_ERROR) {
            return std::nullopt;
        }
        return static_cast<int>(status);
    }

    std::optional<double> ThermalHeadroom(int forecast_seconds) override {
        const float headroom = AThermal_getThermalHeadroom(manager_, forecast_seconds);
        if (std::isnan(headroom)) {
            return std::nullopt;
        }
        return static_cast<double>(headroom);
    }

    std::map<int, double> ThermalHeadroomThresholds() override {
        std::map<int, double> result;
        // Added in Android 15 (API 35). Older devices only get the SEVERE line, which the viewer
        // derives from the API definition.
        if (__builtin_available(android 35, *)) {
            const AThermalHeadroomThreshold* thresholds = nullptr;
            size_t size = 0;
            if (AThermal_getThermalHeadroomThresholds(manager_, &thresholds, &size) != 0 || thresholds == nullptr) {
                return result;
            }
            for (size_t i = 0; i < size; ++i) {
                result[static_cast<int>(thresholds[i].thermalStatus)] = static_cast<double>(thresholds[i].headroom);
            }
            // The NDK allocates the array and documents that the client array-deletes it.
            delete[] thresholds;
        }
        return result;
    }

   private:
    AThermalManager* manager_ = nullptr;
};

volatile std::sig_atomic_t g_stop_requested = 0;

void HandleStopSignal(int /*signum*/) { g_stop_requested = 1; }

std::optional<int> ParseInt(std::string_view str) {
    int value = 0;
    const char* begin = str.data();
    const char* end = begin + str.size();
    const auto [ptr, ec] = std::from_chars(begin, end, value);
    if (ec != std::errc() || ptr != end) {
        return std::nullopt;
    }
    return value;
}

struct Options {
    int poll_interval_ms = ThermalConstants::kDefaultPollIntervalMs;
    int forecast_seconds = ThermalConstants::kDefaultForecastSeconds;
};

// Reads the value that follows argv[*i] into *out, warning instead of silently keeping the default
// when it is missing or malformed.
void ParseIntOption(int argc, char** argv, int* i, int* out) {
    const char* flag = argv[*i];
    if (*i + 1 >= argc) {
        __android_log_print(ANDROID_LOG_WARN, kLogTag, "Missing value for %s", flag);
        return;
    }
    const char* value = argv[++*i];
    if (const std::optional<int> parsed = ParseInt(value); parsed.has_value()) {
        *out = *parsed;
    } else {
        __android_log_print(ANDROID_LOG_WARN, kLogTag, "Ignoring invalid value '%s' for %s", value, flag);
    }
}

Options ParseOptions(int argc, char** argv) {
    Options options;
    for (int i = 1; i < argc; ++i) {
        if (std::strcmp(argv[i], "--poll-interval-ms") == 0) {
            ParseIntOption(argc, argv, &i, &options.poll_interval_ms);
        } else if (std::strcmp(argv[i], "--forecast-seconds") == 0) {
            ParseIntOption(argc, argv, &i, &options.forecast_seconds);
        } else {
            __android_log_print(ANDROID_LOG_WARN, kLogTag, "Ignoring unknown argument '%s'", argv[i]);
        }
    }
    options.poll_interval_ms = std::max(options.poll_interval_ms, ThermalConstants::kMinPollIntervalMs);
    options.forecast_seconds = std::clamp(options.forecast_seconds, 0, ThermalConstants::kMaxForecastSeconds);
    return options;
}

}  // namespace
}  // namespace apa::thermal

int main(int argc, char** argv) {
    using namespace apa::thermal;

    struct sigaction sa = {};
    sa.sa_handler = HandleStopSignal;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGTERM, &sa, nullptr);
    sigaction(SIGINT, &sa, nullptr);

    const Options options = ParseOptions(argc, argv);

    NdkThermalSource source;
    if (!source.IsValid()) {
        __android_log_print(ANDROID_LOG_WARN, kLogTag, "AThermalManager is unavailable on this device");
        return 0;
    }

    ThermalCollector collector(
        source, [](const char* name, int64_t value) { ATrace_setCounter(name, value); }, options.forecast_seconds);

    while (!g_stop_requested) {
        collector.Sample();
        if (g_stop_requested) {
            break;
        }
        poll(nullptr, 0, options.poll_interval_ms);
    }

    return 0;
}
