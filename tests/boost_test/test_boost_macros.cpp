// Copyright (c) 2026 Clément Metz - MIT License
// SPDX-License-Identifier: MIT


#include "../common/utils.h"
#include "internal/asserts_boost_test.hpp"
#include <boost/test/unit_test.hpp>

namespace constest::tests
{

BOOST_AUTO_TEST_CASE(should_be_called_at_runtime)
{
    test_call_at_runtime::reset();
    CONSTEXPR_SECTION("CONSTEXPR_BOOST_TEST should be called at runtime")
    {
        CONSTEXPR_BOOST_TEST(test_call_at_runtime::call());
    };

    BOOST_TEST(test_call_at_runtime::m_wasCalledAtRuntime);
}

BOOST_AUTO_TEST_CASE(should_be_evaluated_once_only)
{
    test_call_at_runtime::reset();
    CONSTEXPR_SECTION("CONSTEXPR_BOOST_TEST expression should be evaluated only once")
    {
        test_evaluate_only_once x;
        CONSTEXPR_BOOST_TEST(x.call());
        CONSTEXPR_BOOST_TEST(x.m_callCount == 1);
    };
}

BOOST_AUTO_TEST_CASE(constexpr_section_debug_should_work_with_all_macros)
{
    CONSTEXPR_SECTION_DEBUG("CONSTEXPR_SECTION_DEBUG should work with all CONSTEXPR macros")
    {
        CONSTEXPR_BOOST_TEST(non_constexpr_function());
        BOOST_TEST(true);
    };
}

}  // namespace constest::tests