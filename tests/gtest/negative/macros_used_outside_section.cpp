// Copyright (c) 2026 Clément Metz - MIT License
// SPDX-License-Identifier: MIT

#include "../../common/utils.h"
#include <gtest/gtest.h>
#include <constest.hpp>

TEST(macros_used_outside_section, test)
{
    CONSTEXPR_EXPECT_EQ(1 + 1, 2);  // Should fail here
    CONSTEXPR_ASSERT_EQ(1 + 2, 3);  // Should fail here
}
