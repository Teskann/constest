// Copyright (c) 2026 Clément Metz - MIT License
// SPDX-License-Identifier: MIT

#include <catch2/catch_test_macros.hpp>
#include <constest.hpp>

TEST_CASE("memory_leak")
{
    CONSTEXPR_SECTION("Test")
    {
        [[maybe_unused]] int const* const a = new int{ 10 };  // Should fail here
    };
}
