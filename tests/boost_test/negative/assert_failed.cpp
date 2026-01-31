// Copyright (c) 2026 Clément Metz - MIT License
// SPDX-License-Identifier: MIT

#include "../../common/utils.h"
#include <boost/test/unit_test.hpp>
#include <constest.hpp>

BOOST_AUTO_TEST_CASE(assert_failed)
{
    CONSTEXPR_SECTION("Test OK")
    {
        CONSTEXPR_BOOST_TEST(1 + 1 == 2);
    };

    CONSTEXPR_SECTION("Test")
    {
        CONSTEXPR_BOOST_TEST(1 + 1 == 3);  // Should fail here
        CONSTEXPR_BOOST_TEST(1 + 1 == 2);
    };
}