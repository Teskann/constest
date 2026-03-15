// Base build macros for Boost.Test - redirect CONSTEXPR_* to base framework macros
#pragma once

// CONSTEXPR_SECTION expands to nothing (empty)
#define CONSTEXPR_SECTION(...) BOOST_TEST_CONTEXT(__VA_ARGS__)
#define CONSTEXPR_SECTION_DEBUG(...) BOOST_TEST_CONTEXT(__VA_ARGS__)

// Redirect all CONSTEXPR_* assertion macros to base Boost.Test macros
#define CONSTEXPR_BOOST_TEST BOOST_TEST