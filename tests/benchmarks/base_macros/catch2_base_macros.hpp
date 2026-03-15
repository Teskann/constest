// Base build macros for Catch2 - redirect CONSTEXPR_* to base framework macros
#pragma once

// CONSTEXPR_SECTION and CONSTEXPR_SECTION_DEBUG expand to nothing (empty)
#define CONSTEXPR_SECTION(...) SECTION(__VA_ARGS__)
#define CONSTEXPR_SECTION_DEBUG(...) SECTION(__VA_ARGS__)

// Redirect all CONSTEXPR_* assertion macros to base Catch2 macros
#define CONSTEXPR_REQUIRE REQUIRE
#define CONSTEXPR_REQUIRE_FALSE REQUIRE_FALSE
#define CONSTEXPR_CHECK CHECK
#define CONSTEXPR_CHECK_FALSE CHECK_FALSE
