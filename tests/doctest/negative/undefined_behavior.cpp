// Copyright (c) 2026 Clément Metz - MIT License
// SPDX-License-Identifier: MIT

#include <constest.hpp>
#include <doctest/doctest.h>
#include <vector>

TEST_CASE("undefined_behavior")
{
    CONSTEXPR_SECTION("Out of bounds")
    {
        std::vector v = { 1, 2, 3, 4, 5 };
        v[0] = 10;
        v[1] = 7;
        v[5] = 56;  // Should fail here
    };

    CONSTEXPR_SECTION("Double delete")
    {
        auto* const a = new int{ 10 };
        delete a;
        delete a;  // Should fail here
    };

    CONSTEXPR_SECTION("Use after free")
    {
        auto* const a = new int{ 10 };
        delete a;
        auto b = *a + 1;  // Should fail here
    };
}
