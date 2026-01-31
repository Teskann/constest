// Copyright (c) 2026 Clément Metz - MIT License
// SPDX-License-Identifier: MIT

#pragma once

#include "compiler_support.hpp"

#define CONSTEST_INTERNAL_CONCAT(a, b)        a##b
#define CONSTEST_INTERNAL_CONCAT_EXPAND(a, b) CONSTEST_INTERNAL_CONCAT(a, b)
#define CONSTEST_UNIQUE_NAME(prefix)          CONSTEST_INTERNAL_CONCAT_EXPAND(prefix, __COUNTER__)

#define CONSTEST_INTERNAL_PASSED_AT_COMPILE_TIME "[Passed at compile-time] "
#define CONSTEST_INTERNAL_WARNING_DEBUGGING      "[WARNING - Debugging a CONSTEXPR_SECTION] "

#if defined(_MSC_VER)
    #define CONSTEST_INTERNAL_DISABLE_MSVC_C4127 __pragma(warning(push)) __pragma(warning(disable : 4127))
    #define CONSTEST_INTERNAL_RESTORE_MSVC_C4127 __pragma(warning(pop))
#else
    #define CONSTEST_INTERNAL_DISABLE_MSVC_C4127
    #define CONSTEST_INTERNAL_RESTORE_MSVC_C4127
#endif
