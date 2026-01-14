// Copyright (c) 2026 Clément Metz - MIT License
// SPDX-License-Identifier: MIT
#pragma once

#if __cplusplus >= 202002L
    #include <version>
#else
    #include <ciso646>
#endif

#if !defined(__cpp_lib_is_constant_evaluated) || __cpp_lib_is_constant_evaluated < 201811L
    #error "constest requires __cpp_lib_is_constant_evaluated support (C++20)"
#endif

#if defined(__cpp_if_consteval) && __cpp_if_consteval >= 202106L
    #define CONSTEST_INTERNAL_IF_CONSTEVAL if consteval
#else
    #include <type_traits>
    #define CONSTEST_INTERNAL_IF_CONSTEVAL if (std::is_constant_evaluated())
#endif