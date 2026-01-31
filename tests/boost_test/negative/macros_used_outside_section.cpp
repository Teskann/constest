// Copyright (c) 2026 Clément Metz - MIT License
// SPDX-License-Identifier: MIT

#include "../../common/utils.h"
#include <boost/test/unit_test.hpp>
#include <constest.hpp>

BOOST_AUTO_TEST_CASE(macros_used_outside_section)
{
    CONSTEXPR_BOOST_TEST(1 + 1 == 2);  // Should fail here
    CONSTEXPR_BOOST_TEST(1 + 2 == 3);  // Should fail here
}
