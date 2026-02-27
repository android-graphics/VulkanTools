/*
 * Copyright (c) 2024 Your Company
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

#ifndef LAYERSVT_TIMER_H
#define LAYERSVT_TIMER_H

#include "perfetto/perfetto_helpers.h"

#ifndef __ANDROID__
#include <chrono>
#include <iostream>
#endif


class Timer {
  public:
    explicit Timer(const char* name) {
#ifndef __ANDROID__
        name_ = name;
        start_ = std::chrono::high_resolution_clock::now();
#endif
        TRACE_EVENT_BEGIN("CPUTiming", perfetto::StaticString(name));
    }

    ~Timer() {
        TRACE_EVENT_END("CPUTiming");
#ifndef __ANDROID__
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start_).count();
        std::cout << name_ << ": " << duration << " ns" << std::endl;
#endif
    }

  private:
#ifndef __ANDROID__
    const char* name_;
#endif
#ifndef __ANDROID__
    std::chrono::time_point<std::chrono::high_resolution_clock> start_;
#endif
};

#endif // LAYERSVT_TIMER_H
