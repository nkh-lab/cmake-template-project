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

#include "IntPairMaker.h"

namespace nkhlab {
namespace projectmy {

IntPairMaker::IntPairMaker(ILibMyPtr_t int_generator1, ILibMyPtr_t int_generator2)
    : int_generator1_{std::move(int_generator1)}
    , int_generator2_{std::move(int_generator2)}
{
}

IntPair_t IntPairMaker::GetPair()
{
    return IntPair_t(int_generator1_->GetInt(), int_generator2_->GetInt());
}

} // namespace projectmy
} // namespace nkhlab