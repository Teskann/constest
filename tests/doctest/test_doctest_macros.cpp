// Copyright (c) 2026 Clément Metz - MIT License
// SPDX-License-Identifier: MIT


#include "../common/utils.h"
#include <constest.hpp>
#include <doctest/doctest.h>

namespace constest::tests
{

TEST_CASE("CONSTEXPR_REQUIRE should be called at runtime")
{
    test_call_at_runtime::reset();
    CONSTEXPR_SECTION("CONSTEXPR_REQUIRE should be called at runtime")
    {
        CONSTEXPR_REQUIRE(test_call_at_runtime::call());
    };

    REQUIRE(test_call_at_runtime::m_wasCalledAtRuntime);
}

TEST_CASE("CONSTEXPR_REQUIRE should be evaluated once only")
{
    test_call_at_runtime::reset();
    CONSTEXPR_SECTION("CONSTEXPR_REQUIRE expression should be evaluated only once")
    {
        test_evaluate_only_once x;
        CONSTEXPR_REQUIRE(x.call());
        CONSTEXPR_REQUIRE(x.m_callCount == 1);
    };
}

TEST_CASE("CONSTEXPR_REQUIRE_FALSE should be called at runtime")
{
    test_call_at_runtime::reset();
    CONSTEXPR_SECTION("CONSTEXPR_REQUIRE_FALSE should be called at runtime")
    {
        CONSTEXPR_REQUIRE_FALSE(!test_call_at_runtime::call());
    };

    REQUIRE(test_call_at_runtime::m_wasCalledAtRuntime);
}

TEST_CASE("CONSTEXPR_REQUIRE_FALSE should be evaluated once only")
{
    test_call_at_runtime::reset();
    CONSTEXPR_SECTION("CONSTEXPR_REQUIRE_FALSE expression should be evaluated only once")
    {
        test_evaluate_only_once x;
        CONSTEXPR_REQUIRE_FALSE(!x.call());
        CONSTEXPR_REQUIRE(x.m_callCount == 1);
    };
}

TEST_CASE("CONSTEXPR_CHECK should be called at runtime")
{
    test_call_at_runtime::reset();
    CONSTEXPR_SECTION("CONSTEXPR_CHECK should be called at runtime")
    {
        CONSTEXPR_CHECK(test_call_at_runtime::call());
    };

    CHECK(test_call_at_runtime::m_wasCalledAtRuntime);
}

TEST_CASE("CONSTEXPR_CHECK should be evaluated once only")
{
    test_call_at_runtime::reset();
    CONSTEXPR_SECTION("CONSTEXPR_CHECK expression should be evaluated only once")
    {
        test_evaluate_only_once x;
        CONSTEXPR_CHECK(x.call());
        CONSTEXPR_CHECK(x.m_callCount == 1);
    };
}

TEST_CASE("CONSTEXPR_CHECK_FALSE should be called at runtime")
{
    test_call_at_runtime::reset();
    CONSTEXPR_SECTION("CONSTEXPR_CHECK_FALSE should be called at runtime")
    {
        CONSTEXPR_CHECK_FALSE(!test_call_at_runtime::call());
    };

    CHECK(test_call_at_runtime::m_wasCalledAtRuntime);
}

TEST_CASE("CONSTEXPR_CHECK_FALSE should be evaluated once only")
{
    test_call_at_runtime::reset();
    CONSTEXPR_SECTION("CONSTEXPR_CHECK_FALSE expression should be evaluated only once")
    {
        test_evaluate_only_once x;
        CONSTEXPR_CHECK_FALSE(!x.call());
        CONSTEXPR_CHECK(x.m_callCount == 1);
    };
}

TEST_CASE("CONSTEXPR_SECTION_DEBUG should work with all macros")
{
    CONSTEXPR_SECTION_DEBUG("CONSTEXPR_SECTION_DEBUG should work with all CONSTEXPR macros")
    {
        CONSTEXPR_REQUIRE(non_constexpr_function());
        CONSTEXPR_REQUIRE_FALSE(!non_constexpr_function());
        CONSTEXPR_CHECK(non_constexpr_function());
        CONSTEXPR_CHECK_FALSE(!non_constexpr_function());
        REQUIRE(true);
    };
}

}  // namespace constest::tests
