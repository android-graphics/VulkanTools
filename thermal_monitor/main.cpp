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
#include <poll.h>

#include <algorithm>
#include <charconv>
#include <cmath>
#include <csignal>
#include <cstdlib>
#include <cstring>
#include <map>
#include <optional>
#include <string_view>

#include "perfetto/perfetto.h"

PERFETTO_DEFINE_CATEGORIES(
    perfetto::Category(apa::thermal::ThermalConstants::kTrackEventCategory).SetDescription("Framework thermal status and headroom"));

PERFETTO_TRACK_EVENT_STATIC_STORAGE();

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

    std::optional<AThermalStatus> CurrentThermalStatus() override {
        const AThermalStatus status = AThermal_getCurrentThermalStatus(manager_);
        if (status < ATHERMAL_STATUS_NONE || status > ATHERMAL_STATUS_SHUTDOWN) {
            return std::nullopt;
        }
        return status;
    }

    std::optional<float> ThermalHeadroom(int forecast_seconds) override {
        const float headroom = AThermal_getThermalHeadroom(manager_, forecast_seconds);
        if (std::isnan(headroom)) {
            return std::nullopt;
        }
        return headroom;
    }

    std::map<AThermalStatus, float> ThermalHeadroomThresholds() override {
        std::map<AThermalStatus, float> result;
        // AThermal_getThermalHeadroomThresholds() was added in Android 15 (API 35). Older versions
        // cannot report thresholds, so they get an empty map.
        if (__builtin_available(android 35, *)) {
            const AThermalHeadroomThreshold* thresholds = nullptr;
            size_t size = 0;
            if (AThermal_getThermalHeadroomThresholds(manager_, &thresholds, &size) != 0 || thresholds == nullptr) {
                return result;
            }
            for (size_t i = 0; i < size; ++i) {
                const AThermalStatus status = thresholds[i].thermalStatus;
                if (status >= ATHERMAL_STATUS_NONE && status <= ATHERMAL_STATUS_SHUTDOWN) {
                    result[status] = thresholds[i].headroom;
                }
            }
            // The NDK allocates the array and documents that the client array-deletes it.
            delete[] thresholds;
        }
        return result;
    }

   private:
    AThermalManager* manager_ = nullptr;
};

// Emits the headroom thresholds at the start of every tracing session that enables the category.
// The thresholds never change, so emitting them once per session is enough, and the monitor can be
// started before tracing is.
class ThresholdSessionObserver final : public perfetto::TrackEventSessionObserver {
   public:
    explicit ThresholdSessionObserver(const ThermalCollector& collector) : collector_(collector) {
        perfetto::TrackEvent::AddSessionObserver(this);
    }

    ~ThresholdSessionObserver() override { perfetto::TrackEvent::RemoveSessionObserver(this); }

    ThresholdSessionObserver(const ThresholdSessionObserver&) = delete;
    ThresholdSessionObserver& operator=(const ThresholdSessionObserver&) = delete;

    void OnStart(const perfetto::DataSourceBase::StartArgs&) override { collector_.EmitThresholds(); }

   private:
    const ThermalCollector& collector_;
};

void EmitCounter(const char* name, double value) {
    // Thermal state belongs to the device, not to this process, so the counters go on global tracks
    // (the default parent would be this process's track). The names are ThermalConstants string
    // literals, so they outlive the track.
    TRACE_COUNTER(ThermalConstants::kTrackEventCategory, perfetto::CounterTrack(perfetto::StaticString{name}, perfetto::Track()),
                  value);
}

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

// Reads the value that follows argv[*i] into *out, logging an error and exiting when it is missing
// or malformed.
void ParseIntOption(int argc, char** argv, int* i, int* out) {
    const char* flag = argv[*i];
    if (*i + 1 >= argc) {
        __android_log_print(ANDROID_LOG_ERROR, kLogTag, "Missing value for %s", flag);
        std::exit(1);
    }
    const char* value = argv[++*i];
    if (const std::optional<int> parsed = ParseInt(value); parsed.has_value()) {
        *out = *parsed;
        return;
    }
    __android_log_print(ANDROID_LOG_ERROR, kLogTag, "Invalid value '%s' for %s", value, flag);
    std::exit(1);
}

Options ParseOptions(int argc, char** argv) {
    Options options;
    for (int i = 1; i < argc; ++i) {
        if (std::strcmp(argv[i], "--poll-interval-ms") == 0) {
            ParseIntOption(argc, argv, &i, &options.poll_interval_ms);
        } else if (std::strcmp(argv[i], "--forecast-seconds") == 0) {
            ParseIntOption(argc, argv, &i, &options.forecast_seconds);
        } else {
            __android_log_print(ANDROID_LOG_ERROR, kLogTag, "Unknown argument '%s'", argv[i]);
            std::exit(1);
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

    perfetto::TracingInitArgs args;
    args.backends = perfetto::kSystemBackend;
    perfetto::Tracing::Initialize(args);
    perfetto::TrackEvent::Register();

    ThermalCollector collector(source, EmitCounter, options.forecast_seconds);
    ThresholdSessionObserver observer(collector);
    // OnStart() only reports sessions that start after the observer is added.
    collector.EmitThresholds();

    while (!g_stop_requested) {
        collector.Sample();
        if (g_stop_requested) {
            break;
        }
        poll(nullptr, 0, options.poll_interval_ms);
    }

    // Commits the last samples to the tracing service before the process exits.
    perfetto::TrackEvent::Flush();
    return 0;
}
