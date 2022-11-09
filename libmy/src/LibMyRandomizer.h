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

#include "ILibMy.h"

#include <random>

#include "SleepPolicy.h"

namespace nkhlab {
namespace projectmy {
namespace impl {

template <class SleepPolicy = RealSleep>
class LibMyRandomizer final
    : public ILibMy
    , private SleepPolicy
{
public:
    LibMyRandomizer() = default;
    ~LibMyRandomizer() = default;

    int GetInt() override
    {
        // pretend that this call is time consuming
        SleepPolicy::sleep_ms(500);

        std::random_device dev;
        std::mt19937 rng(dev());
        std::uniform_int_distribution<std::mt19937::result_type> dist6(
            1, std::numeric_limits<int>::max()); // distribution in range [1, max()]

        return dist6(rng);
    }
};

} // namespace impl
} // namespace projectmy
} // namespace nkhlab
