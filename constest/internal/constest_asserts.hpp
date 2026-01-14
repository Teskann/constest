// Copyright (c) 2026 Clément Metz - MIT License
// SPDX-License-Identifier: MIT

#pragma once

#include "macro_utils.hpp"
#include <utility>

namespace constest
{
/// Explicitly not constexpr to ensure it will cause a compilation error if called in a constant expression
inline void constexpr_assertion_failure() {}
}  // namespace constest

#define CONSTEST_INTERNAL_ASSERT_IMPL(expr, runtime_implementation, success_condition)                                 \
    do                                                                                                                 \
    {                                                                                                                  \
        this_macro_should_be_used_inside_a_CONSTEXPR_SECTION = "This macro should be used inside a CONSTEXPR_SECTION"; \
        CONSTEST_INTERNAL_IF_CONSTEVAL                                                                                 \
        {                                                                                                              \
            if (!(success_condition))                                                                                  \
            {                                                                                                          \
                ::constest::constexpr_assertion_failure();                                                             \
            }                                                                                                          \
        }                                                                                                              \
        else                                                                                                           \
        {                                                                                                              \
            [&]                                                                                                        \
            {                                                                                                          \
                runtime_implementation;                                                                                \
            }();                                                                                                       \
        }                                                                                                              \
    } while (false)

#define CONSTEST_INTERNAL_ASSERT(expr, runtime_implementation) CONSTEST_INTERNAL_ASSERT_IMPL(expr, runtime_implementation, expr)

#define CONSTEST_INTERNAL_ASSERT_NOT(expr, runtime_implementation) CONSTEST_INTERNAL_ASSERT_IMPL(expr, runtime_implementation, !(expr))
