// Copyright (c) 2026 Clément Metz - MIT License
// SPDX-License-Identifier: MIT
#pragma once
#include "../../constest/internal/compiler_support.hpp"

namespace constest::tests
{

struct test_call_at_runtime
{
    inline static bool m_wasCalledAtRuntime = false;
    static constexpr bool call()
    {
        CONSTEST_INTERNAL_IF_CONSTEVAL {}
        else
        {
            m_wasCalledAtRuntime = true;
        }
        return true;
    }
    static void reset()
    {
        m_wasCalledAtRuntime = false;
    }
};

struct test_evaluate_only_once
{
    int m_callCount = 0;
    constexpr bool call()
    {
        ++m_callCount;
        return true;
    }
};

inline bool non_constexpr_function()
{
    return true;
}

}  // namespace constest::tests