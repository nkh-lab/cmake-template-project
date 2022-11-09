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

#include "SleepPolicy.h"

namespace nkhlab {
namespace projectmy {
namespace impl {

template <class SleepPolicy = RealSleep>
class LibMyCounter final
    : public ILibMy
    , private SleepPolicy
{
public:
    LibMyCounter() = default;
    ~LibMyCounter() = default;

    int GetInt() override
    {
        // pretend that this call is time consuming
        SleepPolicy::sleep_ms(500);

        return ++counter_;
    }

private:
    int counter_{0};
};

} // namespace impl
} // namespace projectmy
} // namespace nkhlab
