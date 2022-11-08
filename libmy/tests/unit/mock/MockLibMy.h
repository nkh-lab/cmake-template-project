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

#include <gmock/gmock.h>

#include "ILibMy.h"

namespace nkhlab {
namespace projectmy {
namespace tests {

class MockLibMy : public ILibMy
{
public:
    MOCK_METHOD0(GetInt, int());
};

} // namespace tests
} // namespace projectmy
} // namespace nkhlab