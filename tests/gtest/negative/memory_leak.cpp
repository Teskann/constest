// Copyright (c) 2026 Clément Metz - MIT License
// SPDX-License-Identifier: MIT

#include <gtest/gtest.h>
#include <constest.hpp>

TEST(memory_leak, test)
{
    CONSTEXPR_SECTION("Test")
    {
        [[maybe_unused]] int const* const a = new int{ 10 };  // Should fail here
    };
}
