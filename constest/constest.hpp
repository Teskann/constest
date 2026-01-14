// Copyright (c) 2026 Clément Metz - MIT License
// SPDX-License-Identifier: MIT
#pragma once

#include "internal/compiler_support.hpp"
#include "internal/constest_asserts.hpp"
#include "internal/constexpr_section.hpp"

#ifdef CONSTEST_CONFIG_GTEST
    #include "internal/asserts_gtest.hpp"
#elif defined(CONSTEST_CONFIG_CATCH2)
    #include "internal/asserts_catch.hpp"
#elif defined(CONSTEST_CONFIG_DOCTEST)
    #include "internal/asserts_doctest.hpp"
#elif defined(CONSTEST_CONFIG_BOOST_TEST)
    #include "internal/asserts_boost_test.hpp"
#else
    #error \
        "No test framework selected. Please define CONSTEST_CONFIG_XXX where XXX is the name of the test framework. " \
        "Supported definitions: CONSTEST_CONFIG_GTEST, CONSTEST_CONFIG_CATCH2, " \
        "CONSTEST_CONFIG_DOCTEST, CONSTEST_CONFIG_BOOST_TEST"
#endif
