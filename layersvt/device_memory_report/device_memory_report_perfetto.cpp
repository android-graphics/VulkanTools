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

#include "device_memory_report_perfetto.h"

PERFETTO_TRACK_EVENT_STATIC_STORAGE();

void InitializeDeviceMemoryReportPerfetto() {
    static std::once_flag init_flag;
    std::call_once(init_flag, []() {
        perfetto::TracingInitArgs args;
        args.backends = perfetto::kSystemBackend;
        perfetto::Tracing::Initialize(args);
        perfetto::TrackEvent::Register();
    });
}

perfetto::CounterTrack GetCounterTrack(const char* name) {
    return perfetto::CounterTrack(perfetto::DynamicString(name))
        .set_unit(perfetto::CounterTrack::Unit::UNIT_SIZE_BYTES);
}
