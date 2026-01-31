// Copyright (c) 2026 Clément Metz - MIT License
// SPDX-License-Identifier: MIT

#include "../../common/utils.h"
#include <constest.hpp>
#include <doctest/doctest.h>

TEST_CASE("assert_failed")
{
    CONSTEXPR_SECTION("Test OK")
    {
        CONSTEXPR_REQUIRE(1 + 1 == 2);
    };

    CONSTEXPR_SECTION("CONSTEXPR_REQUIRE")
    {
        CONSTEXPR_REQUIRE(1 + 1 == 3);  // Should fail here
    };

    CONSTEXPR_SECTION("CONSTEXPR_REQUIRE_FALSE")
    {
        CONSTEXPR_REQUIRE_FALSE(1 + 1 == 2);  // Should fail here
    };

    CONSTEXPR_SECTION("CONSTEXPR_CHECK")
    {
        CONSTEXPR_CHECK(1 + 1 == 3);  // Should fail here
    };

    CONSTEXPR_SECTION("CONSTEXPR_CHECK_FALSE")
    {
        CONSTEXPR_CHECK_FALSE(1 + 1 == 2);  // Should fail here
    };
}
