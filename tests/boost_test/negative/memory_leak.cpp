// Copyright (c) 2026 Clément Metz - MIT License
// SPDX-License-Identifier: MIT

#include <boost/test/unit_test.hpp>
#include <constest.hpp>

BOOST_AUTO_TEST_CASE(memory_leak)
{
    CONSTEXPR_SECTION("Test")
    {
        [[maybe_unused]] int const* const a = new int{ 10 };  // Should fail here
    };
}