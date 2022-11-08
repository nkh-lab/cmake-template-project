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

#include "IntPairMaker.h"
#include "MockLibMy.h"

using ::testing::Return;

using namespace nkhlab::projectmy;
using namespace nkhlab::projectmy::tests;

class IntPairMakerTest : public ::testing::Test
{
protected:
    void SetUp() override
    {
        int_generator1_ = std::make_unique<MockLibMy>();
        int_generator2_ = std::make_unique<MockLibMy>();
    }

    // void TearDown() override {}

    std::unique_ptr<MockLibMy> int_generator1_;
    std::unique_ptr<MockLibMy> int_generator2_;
};

TEST_F(IntPairMakerTest, TestGetPairOnce)
{
    // Mocking
    EXPECT_CALL(*int_generator1_, GetInt()).Times(1).WillOnce(Return(1));
    EXPECT_CALL(*int_generator2_, GetInt()).Times(1).WillOnce(Return(2));
    //========

    IntPairMaker int_pair_maker(std::move(int_generator1_), std::move(int_generator2_));

    auto p = int_pair_maker.GetPair();

    EXPECT_EQ(p.first, 1);
    EXPECT_EQ(p.second, 2);
}

TEST_F(IntPairMakerTest, TestGetPairTwice)
{
    // Mocking
    EXPECT_CALL(*int_generator1_, GetInt()).Times(2).WillRepeatedly(Return(1));
    EXPECT_CALL(*int_generator2_, GetInt()).Times(2).WillRepeatedly(Return(2));
    //========

    IntPairMaker int_pair_maker(std::move(int_generator1_), std::move(int_generator2_));

    for (size_t i = 0; i < 2; ++i)
    {
        auto p = int_pair_maker.GetPair();

        EXPECT_EQ(p.first, 1);
        EXPECT_EQ(p.second, 2);
    }
}
