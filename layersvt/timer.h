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

#include <chrono>
#include <iostream>
#include <string>

class Timer {
  public:
    explicit Timer(const char* name) : name_(name), start_(std::chrono::high_resolution_clock::now()) {}

    ~Timer() {
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start_).count();
        std::cout << name_ << ": " << duration << " ns" << std::endl;
    }

  private:
    std::string name_;
    std::chrono::time_point<std::chrono::high_resolution_clock> start_;
};

#endif // LAYERSVT_TIMER_H
