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

#include <gtest/gtest.h>

#include <cstdint>
#include <limits>
#include <map>
#include <optional>
#include <string>
#include <utility>
#include <vector>

namespace apa::thermal {
namespace {

using CounterSample = std::pair<std::string, int64_t>;

class FakeThermalSource final : public ThermalSource {
   public:
    FakeThermalSource(std::optional<ThermalStatus> status, std::optional<float> headroom,
                      std::optional<float> forecast = std::nullopt, std::map<ThermalStatus, float> thresholds = {})
        : status_(status), headroom_(headroom), forecast_(forecast), thresholds_(std::move(thresholds)) {}

    std::optional<ThermalStatus> CurrentThermalStatus() override { return status_; }

    std::optional<float> ThermalHeadroom(int forecast_seconds) override {
        headroom_queries_.push_back(forecast_seconds);
        return forecast_seconds == 0 ? headroom_ : forecast_;
    }

    std::map<ThermalStatus, float> ThermalHeadroomThresholds() override {
        ++thresholds_read_count_;
        return thresholds_;
    }

    int ThresholdsReadCount() const { return thresholds_read_count_; }

    const std::vector<int>& HeadroomQueries() const { return headroom_queries_; }

   private:
    std::optional<ThermalStatus> status_;
    std::optional<float> headroom_;
    std::optional<float> forecast_;
    std::map<ThermalStatus, float> thresholds_;
    int thresholds_read_count_ = 0;
    std::vector<int> headroom_queries_;
};

// Tests for ThermalCollector's sampling policy, which is the part that has to cope with what real
// devices actually report.
class ThermalCollectorTest : public ::testing::Test {
   protected:
    std::vector<CounterSample> emitted_;
    ThermalCollector::Emitter emitter_ = [this](const char* name, int64_t value) { emitted_.emplace_back(name, value); };
};

TEST_F(ThermalCollectorTest, InterleavesCurrentAndForecastHeadroomOnAlternatingTicks) {
    FakeThermalSource source(/*status=*/ThermalStatus::kModerate, /*headroom=*/0.93f, /*forecast=*/1.04f);
    ThermalCollector collector(source, emitter_, /*forecast_seconds=*/10);

    collector.Sample();
    collector.Sample();
    collector.Sample();

    EXPECT_EQ(source.HeadroomQueries(), (std::vector<int>{0, 10, 0}));
    const std::vector<CounterSample> expected = {
        {ThermalConstants::kStatusCounter, 2}, {ThermalConstants::kHeadroomCounter, 930},
        {ThermalConstants::kStatusCounter, 2}, {ThermalConstants::kHeadroomForecastCounter, 1040},
        {ThermalConstants::kStatusCounter, 2}, {ThermalConstants::kHeadroomCounter, 930},
    };
    EXPECT_EQ(emitted_, expected);
}

TEST_F(ThermalCollectorTest, DisablesForecastWhenHorizonIsZero) {
    FakeThermalSource source(/*status=*/ThermalStatus::kLight, /*headroom=*/0.8f, /*forecast=*/0.9f);
    ThermalCollector collector(source, emitter_, /*forecast_seconds=*/0);

    collector.Sample();
    collector.Sample();

    EXPECT_EQ(source.HeadroomQueries(), (std::vector<int>{0, 0}));
    const std::vector<CounterSample> expected = {
        {ThermalConstants::kStatusCounter, 1},
        {ThermalConstants::kHeadroomCounter, 800},
        {ThermalConstants::kStatusCounter, 1},
        {ThermalConstants::kHeadroomCounter, 800},
    };
    EXPECT_EQ(emitted_, expected);
}

TEST_F(ThermalCollectorTest, SkipsFailedForecastTickWithoutRetryingCurrentHeadroom) {
    FakeThermalSource source(/*status=*/ThermalStatus::kLight, /*headroom=*/0.8f, /*forecast=*/std::nullopt);
    ThermalCollector collector(source, emitter_, /*forecast_seconds=*/10);

    collector.Sample();
    collector.Sample();

    // Retrying the current headroom on the failed forecast tick would hit the ~1 Hz rate limit.
    EXPECT_EQ(source.HeadroomQueries(), (std::vector<int>{0, 10}));
    const std::vector<CounterSample> expected = {
        {ThermalConstants::kStatusCounter, 1},
        {ThermalConstants::kHeadroomCounter, 800},
        {ThermalConstants::kStatusCounter, 1},
    };
    EXPECT_EQ(emitted_, expected);
}

TEST_F(ThermalCollectorTest, DropsForecastOnlyAfterRepeatedFailures) {
    FakeThermalSource source(/*status=*/std::nullopt, /*headroom=*/0.8f, /*forecast=*/std::nullopt);
    ThermalCollector collector(source, emitter_, /*forecast_seconds=*/10);

    for (int i = 0; i < 9; ++i) {
        collector.Sample();
    }

    // Three failed forecast ticks (1, 3, 5) disable the forecast; after that every tick is current.
    EXPECT_EQ(source.HeadroomQueries(), (std::vector<int>{0, 10, 0, 10, 0, 10, 0, 0, 0}));
}

TEST_F(ThermalCollectorTest, KeepsForecastAfterTransientFailures) {
    // Each fake failure is followed by a success, so the failure count never reaches the limit.
    class FlakyForecastSource final : public ThermalSource {
       public:
        std::optional<ThermalStatus> CurrentThermalStatus() override { return std::nullopt; }
        std::optional<float> ThermalHeadroom(int forecast_seconds) override {
            if (forecast_seconds == 0) {
                return 0.8f;
            }
            return (forecast_calls_++ % 2) == 0 ? std::nullopt : std::optional<float>(0.9f);
        }
        std::map<ThermalStatus, float> ThermalHeadroomThresholds() override { return {}; }

       private:
        int forecast_calls_ = 0;
    } source;
    ThermalCollector collector(source, emitter_, /*forecast_seconds=*/10);

    for (int i = 0; i < 12; ++i) {
        collector.Sample();
    }

    const std::vector<CounterSample> expected = {
        {ThermalConstants::kHeadroomCounter, 800},         {ThermalConstants::kHeadroomCounter, 800},
        {ThermalConstants::kHeadroomForecastCounter, 900}, {ThermalConstants::kHeadroomCounter, 800},
        {ThermalConstants::kHeadroomCounter, 800},         {ThermalConstants::kHeadroomForecastCounter, 900},
        {ThermalConstants::kHeadroomCounter, 800},         {ThermalConstants::kHeadroomCounter, 800},
        {ThermalConstants::kHeadroomForecastCounter, 900},
    };
    EXPECT_EQ(emitted_, expected);
}

TEST_F(ThermalCollectorTest, KeepsThreeDecimalPlacesOfHeadroom) {
    // The Galaxy S25 puts LIGHT at 0.867 and MODERATE at 0.933, so rounding to hundredths would
    // merge distinguishable states.
    FakeThermalSource source(/*status=*/ThermalStatus::kNone, /*headroom=*/0.8674f);
    ThermalCollector(source, emitter_).Sample();

    ASSERT_EQ(emitted_.size(), 2u);
    EXPECT_EQ(emitted_[1], CounterSample(ThermalConstants::kHeadroomCounter, 867));
}

TEST_F(ThermalCollectorTest, OmitsHeadroomEntirelyOnDeviceThatDoesNotReportIt) {
    FakeThermalSource source(
        /*status=*/ThermalStatus::kLight,
        /*headroom=*/std::nullopt,
        /*forecast=*/std::nullopt,
        /*thresholds=*/{{ThermalStatus::kLight, 0.7f}});
    ThermalCollector collector(source, emitter_);

    collector.Sample();

    // A status track and no headroom track, rather than a headroom track full of a sentinel the
    // host would have to strip. Thresholds are also suppressed when headroom is absent.
    const std::vector<CounterSample> expected = {
        {ThermalConstants::kStatusCounter, 1},
    };
    EXPECT_EQ(emitted_, expected);
}

TEST_F(ThermalCollectorTest, IgnoresNonFiniteOrNegativeHeadroom) {
    FakeThermalSource nan_source(
        /*status=*/ThermalStatus::kLight,
        /*headroom=*/std::numeric_limits<float>::quiet_NaN(),
        /*forecast=*/std::nullopt,
        /*thresholds=*/{{ThermalStatus::kLight, 0.7f}});
    ThermalCollector(nan_source, emitter_).Sample();

    FakeThermalSource negative_source(
        /*status=*/ThermalStatus::kLight,
        /*headroom=*/-1.0f,
        /*forecast=*/-1.0f,
        /*thresholds=*/{{ThermalStatus::kLight, 0.7f}});
    ThermalCollector negative_collector(negative_source, emitter_, /*forecast_seconds=*/10);
    negative_collector.Sample();
    negative_collector.Sample();

    // A rejected forecast tick emits no headroom rather than retrying the current headroom.
    EXPECT_EQ(negative_source.HeadroomQueries(), (std::vector<int>{0, 10}));
    const std::vector<CounterSample> expected = {
        {ThermalConstants::kStatusCounter, 1},
        {ThermalConstants::kStatusCounter, 1},
        {ThermalConstants::kStatusCounter, 1},
    };
    EXPECT_EQ(emitted_, expected);
}

TEST_F(ThermalCollectorTest, OmitsStatusOnDeviceThatDoesNotReportIt) {
    FakeThermalSource source(/*status=*/std::nullopt, /*headroom=*/0.5f);
    ThermalCollector collector(source, emitter_);

    collector.Sample();

    const std::vector<CounterSample> expected = {
        {ThermalConstants::kHeadroomCounter, 500},
    };
    EXPECT_EQ(emitted_, expected);
}

TEST_F(ThermalCollectorTest, ReadsThresholdsOnceAndReEmitsWithCurrentHeadroomOnly) {
    // The Galaxy S25 reports SEVERE as NaN even though LIGHT and MODERATE are populated.
    FakeThermalSource source(
        /*status=*/ThermalStatus::kNone,
        /*headroom=*/0.8f,
        /*forecast=*/0.9f,
        /*thresholds=*/
        {
            {ThermalStatus::kNone, 0.0f},
            {ThermalStatus::kLight, 0.867f},
            {ThermalStatus::kModerate, 0.933f},
            {ThermalStatus::kSevere, std::numeric_limits<float>::quiet_NaN()},
        });
    ThermalCollector collector(source, emitter_, /*forecast_seconds=*/10);

    collector.Sample();
    collector.Sample();
    collector.Sample();

    EXPECT_EQ(source.ThresholdsReadCount(), 1);
    const std::vector<CounterSample> expected = {
        {ThermalConstants::kStatusCounter, 0},
        {ThermalConstants::kHeadroomCounter, 800},
        {"sherlock.thermal.headroom.threshold.light", 867},
        {"sherlock.thermal.headroom.threshold.moderate", 933},
        {ThermalConstants::kStatusCounter, 0},
        {ThermalConstants::kHeadroomForecastCounter, 900},
        {ThermalConstants::kStatusCounter, 0},
        {ThermalConstants::kHeadroomCounter, 800},
        {"sherlock.thermal.headroom.threshold.light", 867},
        {"sherlock.thermal.headroom.threshold.moderate", 933},
    };
    EXPECT_EQ(emitted_, expected);
}

}  // namespace
}  // namespace apa::thermal
