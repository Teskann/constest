// Base build macros for doctest - redirect CONSTEXPR_* to base framework macros
#pragma once

// CONSTEXPR_SECTION expands to nothing (empty)
#define CONSTEXPR_SECTION(...) SUBCASE(__VA_ARGS__)
#define CONSTEXPR_SECTION_DEBUG(...) SUBCASE(__VA_ARGS__)

// Redirect all CONSTEXPR_* assertion macros to base doctest macros
#define CONSTEXPR_REQUIRE REQUIRE
#define CONSTEXPR_REQUIRE_FALSE REQUIRE_FALSE
#define CONSTEXPR_CHECK CHECK
#define CONSTEXPR_CHECK_FALSE CHECK_FALSE