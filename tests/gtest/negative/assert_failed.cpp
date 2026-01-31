// Copyright (c) 2026 Clément Metz - MIT License
// SPDX-License-Identifier: MIT

#include "../../common/utils.h"
#include <constest.hpp>
#include <gtest/gtest.h>

TEST(assert_failed, test_ok)
{
    CONSTEXPR_SECTION("Test OK")
    {
        CONSTEXPR_EXPECT_EQ(1 + 1, 2);
    };
}

TEST(assert_failed, CONSTEXPR_EXPECT_EQ)
{
    CONSTEXPR_SECTION("CONSTEXPR_EXPECT_EQ")
    {
        CONSTEXPR_EXPECT_EQ(1 + 1, 3);  // Should fail here
    };
}

TEST(assert_failed, CONSTEXPR_EXPECT_NE)
{
    CONSTEXPR_SECTION("CONSTEXPR_EXPECT_NE")
    {
        CONSTEXPR_EXPECT_NE(1 + 1, 2);  // Should fail here
    };
}

TEST(assert_failed, CONSTEXPR_EXPECT_LT)
{
    CONSTEXPR_SECTION("CONSTEXPR_EXPECT_LT")
    {
        CONSTEXPR_EXPECT_LT(5, 3);  // Should fail here
    };
}

TEST(assert_failed, CONSTEXPR_EXPECT_LE)
{
    CONSTEXPR_SECTION("CONSTEXPR_EXPECT_LE")
    {
        CONSTEXPR_EXPECT_LE(5, 3);  // Should fail here
    };
}

TEST(assert_failed, CONSTEXPR_EXPECT_GT)
{
    CONSTEXPR_SECTION("CONSTEXPR_EXPECT_GT")
    {
        CONSTEXPR_EXPECT_GT(3, 5);  // Should fail here
    };
}

TEST(assert_failed, CONSTEXPR_EXPECT_GE)
{
    CONSTEXPR_SECTION("CONSTEXPR_EXPECT_GE")
    {
        CONSTEXPR_EXPECT_GE(3, 5);  // Should fail here
    };
}

TEST(assert_failed, CONSTEXPR_EXPECT_TRUE)
{
    CONSTEXPR_SECTION("CONSTEXPR_EXPECT_TRUE")
    {
        CONSTEXPR_EXPECT_TRUE(false);  // Should fail here
    };
}

TEST(assert_failed, CONSTEXPR_EXPECT_FALSE)
{
    CONSTEXPR_SECTION("CONSTEXPR_EXPECT_FALSE")
    {
        CONSTEXPR_EXPECT_FALSE(true);  // Should fail here
    };
}

TEST(assert_failed, CONSTEXPR_ASSERT_EQ)
{
    CONSTEXPR_SECTION("CONSTEXPR_ASSERT_EQ")
    {
        CONSTEXPR_ASSERT_EQ(1 + 1, 3);  // Should fail here
    };
}

TEST(assert_failed, CONSTEXPR_ASSERT_NE)
{
    CONSTEXPR_SECTION("CONSTEXPR_ASSERT_NE")
    {
        CONSTEXPR_ASSERT_NE(1 + 1, 2);  // Should fail here
    };
}

TEST(assert_failed, CONSTEXPR_ASSERT_LT)
{
    CONSTEXPR_SECTION("CONSTEXPR_ASSERT_LT")
    {
        CONSTEXPR_ASSERT_LT(5, 3);  // Should fail here
    };
}

TEST(assert_failed, CONSTEXPR_ASSERT_LE)
{
    CONSTEXPR_SECTION("CONSTEXPR_ASSERT_LE")
    {
        CONSTEXPR_ASSERT_LE(5, 3);  // Should fail here
    };
}

TEST(assert_failed, CONSTEXPR_ASSERT_GT)
{
    CONSTEXPR_SECTION("CONSTEXPR_ASSERT_GT")
    {
        CONSTEXPR_ASSERT_GT(3, 5);  // Should fail here
    };
}

TEST(assert_failed, CONSTEXPR_ASSERT_GE)
{
    CONSTEXPR_SECTION("CONSTEXPR_ASSERT_GE")
    {
        CONSTEXPR_ASSERT_GE(3, 5);  // Should fail here
    };
}

TEST(assert_failed, CONSTEXPR_ASSERT_TRUE)
{
    CONSTEXPR_SECTION("CONSTEXPR_ASSERT_TRUE")
    {
        CONSTEXPR_ASSERT_TRUE(false);  // Should fail here
    };
}

TEST(assert_failed, CONSTEXPR_ASSERT_FALSE)
{
    CONSTEXPR_SECTION("CONSTEXPR_ASSERT_FALSE")
    {
        CONSTEXPR_ASSERT_FALSE(true);  // Should fail here
    };
}
