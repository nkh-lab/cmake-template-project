/*
 * Copyright (C) 2022 https://github.com/nkh-lab
 *
 * This is free software. You can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * version 3 as published by the Free Software Foundation.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY.
 */

#pragma once

#include <thread>

namespace nkhlab {
namespace projectmy {
namespace impl {

class RealSleep
{
public:
    RealSleep() = default;
    ~RealSleep() = default;

protected:
    inline void sleep_ms(int value)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(value));
    }
};

class FakeSleep
{
public:
    FakeSleep() = default;
    ~FakeSleep() = default;

protected:
    inline void sleep_ms(int) {}
};

} // namespace impl
} // namespace projectmy
} // namespace nkhlab