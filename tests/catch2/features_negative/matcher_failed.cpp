// Copyright (c) 2026 Clément Metz - MIT License
// SPDX-License-Identifier: MIT

#include "../../common/utils.h"
#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_container_properties.hpp>
#include <constest.hpp>

TEST_CASE("matcher_failed")
{
#if CONSTEST_INTERNAL_CATCH_HAS_CONSTEXPR_MATCHERS
    CONSTEXPR_SECTION("CONSTEXPR_REQUIRE_THAT")
    {
        CONSTEXPR_REQUIRE_THAT(std::vector<int>{}, !Catch::Matchers::IsEmpty());  // Should fail here
    };

    CONSTEXPR_SECTION("CONSTEXPR_CHECK_THAT")
    {
        CONSTEXPR_CHECK_THAT(std::vector<int>{}, !Catch::Matchers::IsEmpty());  // Should fail here
    };
#endif
}
