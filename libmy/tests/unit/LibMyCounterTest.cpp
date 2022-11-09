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

#include <gtest/gtest.h>

#include "LibMyCounter.h"

using namespace nkhlab::projectmy::impl;

TEST(LibMyCounterTest, TestGetIntFirstCall)
{ // Should always return 1 at first call
    EXPECT_EQ(LibMyCounter<FakeSleep>().GetInt(), 1);
    EXPECT_EQ(LibMyCounter<FakeSleep>().GetInt(), 1);
}

TEST(LibMyCounterTest, TestGetIntSequence)
{
    LibMyCounter<FakeSleep> counter;
    constexpr int kSequenceSize{5};

    for (int i = 0; i < kSequenceSize; ++i)
    {
        EXPECT_EQ(counter.GetInt(), i + 1);
    }
}
