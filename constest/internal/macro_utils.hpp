// Copyright (c) 2026 Clément Metz - MIT License
// SPDX-License-Identifier: MIT

#pragma once

#include "compiler_support.hpp"

#define CONSTEST_INTERNAL_CONCAT(a, b)        a##b
#define CONSTEST_INTERNAL_CONCAT_EXPAND(a, b) CONSTEST_INTERNAL_CONCAT(a, b)
#define CONSTEST_UNIQUE_NAME(prefix)          CONSTEST_INTERNAL_CONCAT_EXPAND(prefix, __COUNTER__)

#define CONSTEST_INTERNAL_PASSED_AT_COMPILE_TIME "[Passed at compile time] "
#define CONSTEST_INTERNAL_WARNING_DEBUGGING      "[WARNING - Debugging a CONSTEXPR_SECTION] "
