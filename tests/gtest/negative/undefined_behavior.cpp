// Copyright (c) 2026 Clément Metz - MIT License
// SPDX-License-Identifier: MIT

#include <gtest/gtest.h>
#include <constest.hpp>
#include <vector>

TEST(undefined_behavior, out_of_bounds)
{
    CONSTEXPR_SECTION("Out of bounds")
    {
        std::vector v = { 1, 2, 3, 4, 5 };
        v[0] = 10;
        v[1] = 7;
        v[5] = 56;  // Should fail here
    };
}

TEST(undefined_behavior, double_delete)
{
    CONSTEXPR_SECTION("Double delete")
    {
        auto* const a = new int{ 10 };
        delete a;
        delete a;  // Should fail here
    };
}

TEST(undefined_behavior, use_after_free)
{
    CONSTEXPR_SECTION("Use after free")
    {
        auto* const a = new int{ 10 };
        delete a;
        auto b = *a + 1;  // Should fail here
    };
}
