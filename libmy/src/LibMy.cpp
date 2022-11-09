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

#include "LibMy.h"
#include "LibMyCounter.h"
#include "LibMyRandomizer.h"

namespace nkhlab {
namespace projectmy {

ILibMyPtr_t CreateLibMyCounter()
{
    return std::make_unique<impl::LibMyCounter<>>();
}

ILibMyPtr_t CreateLibMyRandomizer()
{
    return std::make_unique<impl::LibMyRandomizer<>>();
}

} // namespace projectmy
} // namespace nkhlab