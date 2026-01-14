// Copyright (c) 2026 Clément Metz - MIT License
// SPDX-License-Identifier: MIT

#pragma once

#include "macro_utils.hpp"

namespace constest
{

struct constexpr_section
{
    struct checker
    {
        constexpr explicit(false) checker(const char*) {}
    };

    template <typename Callable>
    constexpr explicit(false) constexpr_section(Callable constexpr_section_content)
    {
        static_assert((constexpr_section_content(), true), "constexpr section failure");
        constexpr_section_content();
    }
};

struct constexpr_section_debug
{
    template <typename Callable>
    constexpr explicit(false) constexpr_section_debug(Callable constexpr_section_content)
    {
        constexpr_section_content();
    }
};

}  // namespace constest

// Don't make it constexpr because we want it to be called at runtime as well!
#define CONSTEST_INTERNAL_CONSTEXPR_SECTIONS_IMPL(type)                                                                                \
    [[maybe_unused]] const type CONSTEST_UNIQUE_NAME(constexpr_section_) = [&]([[maybe_unused]] ::constest::constexpr_section::checker \
                                                                                   this_macro_should_be_used_inside_a_CONSTEXPR_SECTION = nullptr)

#define CONSTEST_INTERNAL_CONSTEXPR_SECTION_IMPL       CONSTEST_INTERNAL_CONSTEXPR_SECTIONS_IMPL(::constest::constexpr_section)
#define CONSTEST_INTERNAL_CONSTEXPR_SECTION_DEBUG_IMPL CONSTEST_INTERNAL_CONSTEXPR_SECTIONS_IMPL(::constest::constexpr_section_debug)