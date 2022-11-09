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

#include <set>

#include <gtest/gtest.h>

#include "LibMyRandomizer.h"

using namespace nkhlab::projectmy::impl;

TEST(LibMyRandomizerTest, TestGetIntSequenceRandomization)
{
    LibMyRandomizer<FakeSleep> randomizer;
    constexpr int kSequenceSize{5};
    std::set<int> random_values;

    for (int i = 0; i < kSequenceSize; ++i)
    {
        random_values.emplace(randomizer.GetInt());
    }

    EXPECT_EQ(random_values.size(), kSequenceSize);
}