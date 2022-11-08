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

#include <utility>

#include "LibMy.h"

namespace nkhlab {
namespace projectmy {

using IntPair_t = std::pair<int, int>;

class IntPairMaker
{
public:
    explicit IntPairMaker(ILibMyPtr_t int_generator1, ILibMyPtr_t int_generator2);
    ~IntPairMaker() = default;

    IntPair_t GetPair();

private:
    ILibMyPtr_t int_generator1_;
    ILibMyPtr_t int_generator2_;
};

} // namespace projectmy
} // namespace nkhlab
