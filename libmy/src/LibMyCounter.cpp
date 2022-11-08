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

#include "LibMyCounter.h"

#include <thread>

using namespace std::chrono_literals;

namespace nkhlab {
namespace projectmy {
namespace impl {

int LibMyCounter::GetInt()
{
    // pretend that this call is time consuming
    std::this_thread::sleep_for(500ms);

    return ++counter_;
}

} // namespace impl
} // namespace projectmy
} // namespace nkhlab
