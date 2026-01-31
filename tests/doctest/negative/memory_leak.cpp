// Copyright (c) 2026 Clément Metz - MIT License
// SPDX-License-Identifier: MIT

#include <constest.hpp>
#include <doctest/doctest.h>

TEST_CASE("memory_leak")
{
    CONSTEXPR_SECTION("Test")
    {
        [[maybe_unused]] int const* const a = new int{ 10 };  // Should fail here
    };
}
