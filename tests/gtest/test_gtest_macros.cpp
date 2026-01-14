// Copyright (c) 2026 Clément Metz - MIT License
// SPDX-License-Identifier: MIT


#include "../common/utils.h"
#include "internal/asserts_gtest.hpp"
#include <constest.hpp>
#include <gtest/gtest.h>

namespace constest::tests
{

TEST(ConstexprExpectEq, should_be_called_at_runtime)
{
    test_call_at_runtime::reset();
    CONSTEXPR_SECTION("CONSTEXPR_EXPECT_EQ should be called at runtime")
    {
        CONSTEXPR_EXPECT_EQ(test_call_at_runtime::call(), true);
    };

    EXPECT_TRUE(test_call_at_runtime::m_wasCalledAtRuntime);
}

TEST(ConstexprExpectEq, should_be_evaluated_once_only)
{
    test_call_at_runtime::reset();
    CONSTEXPR_SECTION("CONSTEXPR_EXPECT_EQ expression should be evaluated only once")
    {
        test_evaluate_only_once x;
        CONSTEXPR_EXPECT_EQ(x.call(), true);
        CONSTEXPR_EXPECT_EQ(x.m_callCount, 1);
    };
}

TEST(ConstexprExpectNe, should_be_called_at_runtime)
{
    test_call_at_runtime::reset();
    CONSTEXPR_SECTION("CONSTEXPR_EXPECT_NE should be called at runtime")
    {
        CONSTEXPR_EXPECT_NE(test_call_at_runtime::call(), false);
    };

    EXPECT_TRUE(test_call_at_runtime::m_wasCalledAtRuntime);
}

TEST(ConstexprExpectNe, should_be_evaluated_once_only)
{
    test_call_at_runtime::reset();
    CONSTEXPR_SECTION("CONSTEXPR_EXPECT_NE expression should be evaluated only once")
    {
        test_evaluate_only_once x;
        CONSTEXPR_EXPECT_NE(x.call(), false);
        CONSTEXPR_EXPECT_EQ(x.m_callCount, 1);
    };
}

TEST(ConstexprExpectLt, should_be_called_at_runtime)
{
    test_call_at_runtime::reset();
    CONSTEXPR_SECTION("CONSTEXPR_EXPECT_LT should be called at runtime")
    {
        CONSTEXPR_EXPECT_LT(test_call_at_runtime::call() ? 1 : 0, 2);
    };

    EXPECT_TRUE(test_call_at_runtime::m_wasCalledAtRuntime);
}

TEST(ConstexprExpectLt, should_be_evaluated_once_only)
{
    test_call_at_runtime::reset();
    CONSTEXPR_SECTION("CONSTEXPR_EXPECT_LT expression should be evaluated only once")
    {
        test_evaluate_only_once x;
        CONSTEXPR_EXPECT_LT(x.call() ? 1 : 0, 2);
        CONSTEXPR_EXPECT_EQ(x.m_callCount, 1);
    };
}

TEST(ConstexprExpectLe, should_be_called_at_runtime)
{
    test_call_at_runtime::reset();
    CONSTEXPR_SECTION("CONSTEXPR_EXPECT_LE should be called at runtime")
    {
        CONSTEXPR_EXPECT_LE(test_call_at_runtime::call() ? 1 : 0, 1);
    };

    EXPECT_TRUE(test_call_at_runtime::m_wasCalledAtRuntime);
}

TEST(ConstexprExpectLe, should_be_evaluated_once_only)
{
    test_call_at_runtime::reset();
    CONSTEXPR_SECTION("CONSTEXPR_EXPECT_LE expression should be evaluated only once")
    {
        test_evaluate_only_once x;
        CONSTEXPR_EXPECT_LE(x.call() ? 1 : 0, 1);
        CONSTEXPR_EXPECT_EQ(x.m_callCount, 1);
    };
}

TEST(ConstexprExpectGt, should_be_called_at_runtime)
{
    test_call_at_runtime::reset();
    CONSTEXPR_SECTION("CONSTEXPR_EXPECT_GT should be called at runtime")
    {
        CONSTEXPR_EXPECT_GT(test_call_at_runtime::call() ? 2 : 0, 1);
    };

    EXPECT_TRUE(test_call_at_runtime::m_wasCalledAtRuntime);
}

TEST(ConstexprExpectGt, should_be_evaluated_once_only)
{
    test_call_at_runtime::reset();
    CONSTEXPR_SECTION("CONSTEXPR_EXPECT_GT expression should be evaluated only once")
    {
        test_evaluate_only_once x;
        CONSTEXPR_EXPECT_GT(x.call() ? 2 : 0, 1);
        CONSTEXPR_EXPECT_EQ(x.m_callCount, 1);
    };
}

TEST(ConstexprExpectGe, should_be_called_at_runtime)
{
    test_call_at_runtime::reset();
    CONSTEXPR_SECTION("CONSTEXPR_EXPECT_GE should be called at runtime")
    {
        CONSTEXPR_EXPECT_GE(test_call_at_runtime::call() ? 1 : 0, 1);
    };

    EXPECT_TRUE(test_call_at_runtime::m_wasCalledAtRuntime);
}

TEST(ConstexprExpectGe, should_be_evaluated_once_only)
{
    test_call_at_runtime::reset();
    CONSTEXPR_SECTION("CONSTEXPR_EXPECT_GE expression should be evaluated only once")
    {
        test_evaluate_only_once x;
        CONSTEXPR_EXPECT_GE(x.call() ? 1 : 0, 1);
        CONSTEXPR_EXPECT_EQ(x.m_callCount, 1);
    };
}

TEST(ConstexprExpectTrue, should_be_called_at_runtime)
{
    test_call_at_runtime::reset();
    CONSTEXPR_SECTION("CONSTEXPR_EXPECT_TRUE should be called at runtime")
    {
        CONSTEXPR_EXPECT_TRUE(test_call_at_runtime::call());
    };

    EXPECT_TRUE(test_call_at_runtime::m_wasCalledAtRuntime);
}

TEST(ConstexprExpectTrue, should_be_evaluated_once_only)
{
    test_call_at_runtime::reset();
    CONSTEXPR_SECTION("CONSTEXPR_EXPECT_TRUE expression should be evaluated only once")
    {
        test_evaluate_only_once x;
        CONSTEXPR_EXPECT_TRUE(x.call());
        CONSTEXPR_EXPECT_EQ(x.m_callCount, 1);
    };
}

TEST(ConstexprExpectFalse, should_be_called_at_runtime)
{
    test_call_at_runtime::reset();
    CONSTEXPR_SECTION("CONSTEXPR_EXPECT_FALSE should be called at runtime")
    {
        CONSTEXPR_EXPECT_FALSE(!test_call_at_runtime::call());
    };

    EXPECT_TRUE(test_call_at_runtime::m_wasCalledAtRuntime);
}

TEST(ConstexprExpectFalse, should_be_evaluated_once_only)
{
    test_call_at_runtime::reset();
    CONSTEXPR_SECTION("CONSTEXPR_EXPECT_FALSE expression should be evaluated only once")
    {
        test_evaluate_only_once x;
        CONSTEXPR_EXPECT_FALSE(!x.call());
        CONSTEXPR_EXPECT_EQ(x.m_callCount, 1);
    };
}

TEST(ConstexprAssertEq, should_be_called_at_runtime)
{
    test_call_at_runtime::reset();
    CONSTEXPR_SECTION("CONSTEXPR_ASSERT_EQ should be called at runtime")
    {
        CONSTEXPR_ASSERT_EQ(test_call_at_runtime::call(), true);
    };

    ASSERT_TRUE(test_call_at_runtime::m_wasCalledAtRuntime);
}

TEST(ConstexprAssertEq, should_be_evaluated_once_only)
{
    test_call_at_runtime::reset();
    CONSTEXPR_SECTION("CONSTEXPR_ASSERT_EQ expression should be evaluated only once")
    {
        test_evaluate_only_once x;
        CONSTEXPR_ASSERT_EQ(x.call(), true);
        CONSTEXPR_ASSERT_EQ(x.m_callCount, 1);
    };
}

TEST(ConstexprAssertNe, should_be_called_at_runtime)
{
    test_call_at_runtime::reset();
    CONSTEXPR_SECTION("CONSTEXPR_ASSERT_NE should be called at runtime")
    {
        CONSTEXPR_ASSERT_NE(test_call_at_runtime::call(), false);
    };

    ASSERT_TRUE(test_call_at_runtime::m_wasCalledAtRuntime);
}

TEST(ConstexprAssertNe, should_be_evaluated_once_only)
{
    test_call_at_runtime::reset();
    CONSTEXPR_SECTION("CONSTEXPR_ASSERT_NE expression should be evaluated only once")
    {
        test_evaluate_only_once x;
        CONSTEXPR_ASSERT_NE(x.call(), false);
        CONSTEXPR_ASSERT_EQ(x.m_callCount, 1);
    };
}

TEST(ConstexprAssertLt, should_be_called_at_runtime)
{
    test_call_at_runtime::reset();
    CONSTEXPR_SECTION("CONSTEXPR_ASSERT_LT should be called at runtime")
    {
        CONSTEXPR_ASSERT_LT(test_call_at_runtime::call() ? 1 : 0, 2);
    };

    ASSERT_TRUE(test_call_at_runtime::m_wasCalledAtRuntime);
}

TEST(ConstexprAssertLt, should_be_evaluated_once_only)
{
    test_call_at_runtime::reset();
    CONSTEXPR_SECTION("CONSTEXPR_ASSERT_LT expression should be evaluated only once")
    {
        test_evaluate_only_once x;
        CONSTEXPR_ASSERT_LT(x.call() ? 1 : 0, 2);
        CONSTEXPR_ASSERT_EQ(x.m_callCount, 1);
    };
}

TEST(ConstexprAssertLe, should_be_called_at_runtime)
{
    test_call_at_runtime::reset();
    CONSTEXPR_SECTION("CONSTEXPR_ASSERT_LE should be called at runtime")
    {
        CONSTEXPR_ASSERT_LE(test_call_at_runtime::call() ? 1 : 0, 1);
    };

    ASSERT_TRUE(test_call_at_runtime::m_wasCalledAtRuntime);
}

TEST(ConstexprAssertLe, should_be_evaluated_once_only)
{
    test_call_at_runtime::reset();
    CONSTEXPR_SECTION("CONSTEXPR_ASSERT_LE expression should be evaluated only once")
    {
        test_evaluate_only_once x;
        CONSTEXPR_ASSERT_LE(x.call() ? 1 : 0, 1);
        CONSTEXPR_ASSERT_EQ(x.m_callCount, 1);
    };
}

TEST(ConstexprAssertGt, should_be_called_at_runtime)
{
    test_call_at_runtime::reset();
    CONSTEXPR_SECTION("CONSTEXPR_ASSERT_GT should be called at runtime")
    {
        CONSTEXPR_ASSERT_GT(test_call_at_runtime::call() ? 2 : 0, 1);
    };

    ASSERT_TRUE(test_call_at_runtime::m_wasCalledAtRuntime);
}

TEST(ConstexprAssertGt, should_be_evaluated_once_only)
{
    test_call_at_runtime::reset();
    CONSTEXPR_SECTION("CONSTEXPR_ASSERT_GT expression should be evaluated only once")
    {
        test_evaluate_only_once x;
        CONSTEXPR_ASSERT_GT(x.call() ? 2 : 0, 1);
        CONSTEXPR_ASSERT_EQ(x.m_callCount, 1);
    };
}

TEST(ConstexprAssertGe, should_be_called_at_runtime)
{
    test_call_at_runtime::reset();
    CONSTEXPR_SECTION("CONSTEXPR_ASSERT_GE should be called at runtime")
    {
        CONSTEXPR_ASSERT_GE(test_call_at_runtime::call() ? 1 : 0, 1);
    };

    ASSERT_TRUE(test_call_at_runtime::m_wasCalledAtRuntime);
}

TEST(ConstexprAssertGe, should_be_evaluated_once_only)
{
    test_call_at_runtime::reset();
    CONSTEXPR_SECTION("CONSTEXPR_ASSERT_GE expression should be evaluated only once")
    {
        test_evaluate_only_once x;
        CONSTEXPR_ASSERT_GE(x.call() ? 1 : 0, 1);
        CONSTEXPR_ASSERT_EQ(x.m_callCount, 1);
    };
}

TEST(ConstexprAssertTrue, should_be_called_at_runtime)
{
    test_call_at_runtime::reset();
    CONSTEXPR_SECTION("CONSTEXPR_ASSERT_TRUE should be called at runtime")
    {
        CONSTEXPR_ASSERT_TRUE(test_call_at_runtime::call());
    };

    ASSERT_TRUE(test_call_at_runtime::m_wasCalledAtRuntime);
}

TEST(ConstexprAssertTrue, should_be_evaluated_once_only)
{
    test_call_at_runtime::reset();
    CONSTEXPR_SECTION("CONSTEXPR_ASSERT_TRUE expression should be evaluated only once")
    {
        test_evaluate_only_once x;
        CONSTEXPR_ASSERT_TRUE(x.call());
        CONSTEXPR_ASSERT_EQ(x.m_callCount, 1);
    };
}

TEST(ConstexprAssertFalse, should_be_called_at_runtime)
{
    test_call_at_runtime::reset();
    CONSTEXPR_SECTION("CONSTEXPR_ASSERT_FALSE should be called at runtime")
    {
        CONSTEXPR_ASSERT_FALSE(!test_call_at_runtime::call());
    };

    ASSERT_TRUE(test_call_at_runtime::m_wasCalledAtRuntime);
}

TEST(ConstexprAssertFalse, should_be_evaluated_once_only)
{
    test_call_at_runtime::reset();
    CONSTEXPR_SECTION("CONSTEXPR_ASSERT_FALSE expression should be evaluated only once")
    {
        test_evaluate_only_once x;
        CONSTEXPR_ASSERT_FALSE(!x.call());
        CONSTEXPR_ASSERT_EQ(x.m_callCount, 1);
    };
}

TEST(ConstexprSectionDebug, should_work_with_all_macros)
{
    CONSTEXPR_SECTION_DEBUG("CONSTEXPR_SECTION_DEBUG should work with all CONSTEXPR macros")
    {
        CONSTEXPR_EXPECT_EQ(non_constexpr_function(), true);
        CONSTEXPR_EXPECT_NE(non_constexpr_function(), false);
        CONSTEXPR_EXPECT_LT(1, 2);
        CONSTEXPR_EXPECT_LE(1, 1);
        CONSTEXPR_EXPECT_GT(2, 1);
        CONSTEXPR_EXPECT_GE(1, 1);
        CONSTEXPR_EXPECT_TRUE(non_constexpr_function());
        CONSTEXPR_EXPECT_FALSE(!non_constexpr_function());
        CONSTEXPR_ASSERT_EQ(non_constexpr_function(), true);
        CONSTEXPR_ASSERT_NE(non_constexpr_function(), false);
        CONSTEXPR_ASSERT_LT(1, 2);
        CONSTEXPR_ASSERT_LE(1, 1);
        CONSTEXPR_ASSERT_GT(2, 1);
        CONSTEXPR_ASSERT_GE(1, 1);
        CONSTEXPR_ASSERT_TRUE(non_constexpr_function());
        CONSTEXPR_ASSERT_FALSE(!non_constexpr_function());
        ASSERT_TRUE(true);
    };
}

}  // namespace constest::tests
