// Copyright (c) 2026 Clément Metz - MIT License
// SPDX-License-Identifier: MIT

#include "../../common/utils.h"
#include <constest.hpp>
#include <doctest/doctest.h>

TEST_CASE("macros_used_outside_section")
{
    CONSTEXPR_REQUIRE(1 + 1 == 2);  // Should fail here
    CONSTEXPR_CHECK(1 + 2 == 3);    // Should fail here
}
