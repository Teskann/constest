#include <algorithm>
#include <constest.hpp>
#include <gtest/gtest.h>
#include <string>
#include <vector>

constexpr int fibonacci(const int n)
{
    return n <= 1 ? n : fibonacci(n - 1) + fibonacci(n - 2);
}

constexpr int factorial(const int n)
{
    return n <= 1 ? 1 : n * factorial(n - 1);
}

TEST(GTestConstexpr, EqualityComparisons)
{
    CONSTEXPR_SECTION("basic equality with arithmetic expressions")
    {
        CONSTEXPR_EXPECT_EQ(2 + 2, 4);
        CONSTEXPR_EXPECT_EQ(10 * 5 - 3, 47);
        CONSTEXPR_EXPECT_EQ(100 / 4, 25);
        CONSTEXPR_ASSERT_EQ(fibonacci(10), 55);
    };

    CONSTEXPR_SECTION("equality with complex expressions")
    {
        constexpr int a = 42;
        constexpr int b = 7;
        CONSTEXPR_EXPECT_EQ(a * b, 294);
        CONSTEXPR_EXPECT_EQ((a + b) * (a - b), 1715);
        CONSTEXPR_ASSERT_EQ(factorial(5), 120);
    };
}

TEST(GTestConstexpr, InequalityComparisons)
{
    CONSTEXPR_SECTION("not equal with various types")
    {
        CONSTEXPR_EXPECT_NE(5, 3);
        CONSTEXPR_EXPECT_NE(100 - 1, 100);
        CONSTEXPR_ASSERT_NE(fibonacci(6), fibonacci(5));
    };

    CONSTEXPR_SECTION("inequality with computed values")
    {
        constexpr int x = 15;
        constexpr int y = 20;
        CONSTEXPR_EXPECT_NE(x * 2, y * 2);
        CONSTEXPR_ASSERT_NE((x + y) / 2, x);
    };
}

TEST(GTestConstexpr, LessThanComparisons)
{
    CONSTEXPR_SECTION("less than with increasing sequences")
    {
        CONSTEXPR_EXPECT_LT(1, 2);
        CONSTEXPR_EXPECT_LT(fibonacci(5), fibonacci(6));
        CONSTEXPR_ASSERT_LT(10 * 10, 10 * 11);
    };

    CONSTEXPR_SECTION("complex less than expressions")
    {
        constexpr int a = 100;
        constexpr int b = 200;
        CONSTEXPR_EXPECT_LT(a / 2, b / 3);
        CONSTEXPR_ASSERT_LT((a + b) / 4, a);
    };
}

TEST(GTestConstexpr, LessOrEqualComparisons)
{
    CONSTEXPR_SECTION("less or equal with boundaries")
    {
        CONSTEXPR_EXPECT_LE(5, 5);
        CONSTEXPR_EXPECT_LE(3, 7);
        CONSTEXPR_EXPECT_LE(factorial(3), factorial(4));
        CONSTEXPR_ASSERT_LE(fibonacci(10), 55);
    };

    CONSTEXPR_SECTION("complex less or equal expressions")
    {
        constexpr int max_value = 1000;
        CONSTEXPR_EXPECT_LE(max_value / 2, max_value);
        CONSTEXPR_ASSERT_LE((max_value - 100) * 2, max_value * 2);
    };
}

TEST(GTestConstexpr, GreaterThanComparisons)
{
    CONSTEXPR_SECTION("greater than with decreasing order")
    {
        CONSTEXPR_EXPECT_GT(10, 5);
        CONSTEXPR_EXPECT_GT(fibonacci(8), fibonacci(7));
        CONSTEXPR_ASSERT_GT(100 * 100, 99 * 99);
    };

    CONSTEXPR_SECTION("complex greater than expressions")
    {
        constexpr int base = 50;
        CONSTEXPR_EXPECT_GT(base * 3, base * 2);
        CONSTEXPR_ASSERT_GT((base + 10) * (base + 10), base * base);
    };
}

TEST(GTestConstexpr, GreaterOrEqualComparisons)
{
    CONSTEXPR_SECTION("greater or equal with boundaries")
    {
        CONSTEXPR_EXPECT_GE(10, 10);
        CONSTEXPR_EXPECT_GE(20, 15);
        CONSTEXPR_EXPECT_GE(factorial(5), factorial(4));
        CONSTEXPR_ASSERT_GE(fibonacci(9), fibonacci(8));
    };

    CONSTEXPR_SECTION("complex greater or equal expressions")
    {
        constexpr int threshold = 500;
        CONSTEXPR_EXPECT_GE(threshold * 2, threshold);
        CONSTEXPR_ASSERT_GE((threshold / 2) + 300, threshold / 2);
    };
}

TEST(GTestConstexpr, TrueAssertions)
{
    CONSTEXPR_SECTION("boolean true with logical expressions")
    {
        CONSTEXPR_EXPECT_TRUE(true);
        CONSTEXPR_EXPECT_TRUE(5 > 3);
        CONSTEXPR_EXPECT_TRUE((10 + 5) == 15);
        CONSTEXPR_ASSERT_TRUE(fibonacci(5) > 0);
    };

    CONSTEXPR_SECTION("complex boolean true expressions")
    {
        constexpr bool condition_a = 100 > 50;
        constexpr bool condition_b = 25 * 4 == 100;
        CONSTEXPR_EXPECT_TRUE(condition_a && condition_b);
        CONSTEXPR_ASSERT_TRUE((factorial(4) == 24) && (fibonacci(6) == 8));
    };
}

TEST(GTestConstexpr, FalseAssertions)
{
    CONSTEXPR_SECTION("boolean false with logical expressions")
    {
        CONSTEXPR_EXPECT_FALSE(false);
        CONSTEXPR_EXPECT_FALSE(3 > 5);
        CONSTEXPR_EXPECT_FALSE((10 + 5) == 20);
        CONSTEXPR_ASSERT_FALSE(fibonacci(5) < 0);
    };

    CONSTEXPR_SECTION("complex boolean false expressions")
    {
        constexpr bool wrong_condition = 100 < 50;
        CONSTEXPR_EXPECT_FALSE(wrong_condition);
        CONSTEXPR_ASSERT_FALSE((factorial(4) != 24) || (fibonacci(6) != 8));
    };
}

TEST(GTestConstexpr, MixedComplexExpressions)
{
    CONSTEXPR_SECTION("combining multiple assertion types")
    {
        constexpr int fib_10 = fibonacci(10);
        constexpr int fact_5 = factorial(5);

        CONSTEXPR_EXPECT_EQ(fib_10, 55);
        CONSTEXPR_EXPECT_NE(fib_10, fact_5);
        CONSTEXPR_EXPECT_LT(fib_10, fact_5);
        CONSTEXPR_EXPECT_TRUE(fib_10 < fact_5);
        CONSTEXPR_ASSERT_GE(fact_5, fib_10);
    };

    CONSTEXPR_SECTION("nested arithmetic with multiple operations")
    {
        constexpr int a = 12;
        constexpr int b = 8;
        constexpr int c = 4;

        CONSTEXPR_EXPECT_EQ((a + b) * c, 80);
        CONSTEXPR_EXPECT_LT(a * b, (a + b) * (c + 1));
        CONSTEXPR_EXPECT_GE((a * b) / c, b);
        CONSTEXPR_ASSERT_TRUE(((a - b) * c) == (c * c));
    };
}

TEST(GTestConstexpr, NonTransientConstexprVectorOperations)
{
    CONSTEXPR_SECTION("vector initialization and size checks")
    {
        const std::vector vec = { 1, 2, 3, 4, 5 };
        CONSTEXPR_EXPECT_EQ(vec.size(), 5);
        CONSTEXPR_EXPECT_FALSE(vec.empty());
        CONSTEXPR_ASSERT_TRUE(vec.capacity() >= 5);
    };

    CONSTEXPR_SECTION("vector element access and modification")
    {
        std::vector vec = { 10, 20, 30, 40, 50 };
        CONSTEXPR_EXPECT_EQ(vec[0], 10);
        CONSTEXPR_EXPECT_EQ(vec[2], 30);
        CONSTEXPR_EXPECT_EQ(vec.front(), 10);
        CONSTEXPR_EXPECT_EQ(vec.back(), 50);

        vec[1] = 99;
        CONSTEXPR_EXPECT_EQ(vec[1], 99);
    };

    CONSTEXPR_SECTION("vector push_back and size growth")
    {
        std::vector<int> vec;
        CONSTEXPR_EXPECT_EQ(vec.size(), 0);

        vec.push_back(42);
        CONSTEXPR_EXPECT_EQ(vec.size(), 1);
        CONSTEXPR_EXPECT_EQ(vec[0], 42);

        vec.push_back(100);
        CONSTEXPR_EXPECT_EQ(vec.size(), 2);
        CONSTEXPR_ASSERT_EQ(vec[1], 100);
    };

    CONSTEXPR_SECTION("vector with complex expressions")
    {
        const std::vector numbers = { 1, 2, 3, 4, 5 };
        int sum = 0;
        for (const auto& n : numbers)
        {
            sum += n;
        }
        CONSTEXPR_EXPECT_EQ(sum, 15);
        CONSTEXPR_ASSERT_EQ(static_cast<int>(numbers.size()) * 3, sum);
    };
}

TEST(GTestConstexpr, NonTransientConstexprStringOperations)
{
    CONSTEXPR_SECTION("string initialization and basic checks")
    {
        const std::string str = "hello";
        CONSTEXPR_EXPECT_EQ(str.size(), 5);
        CONSTEXPR_EXPECT_EQ(str.length(), 5);
        CONSTEXPR_EXPECT_FALSE(str.empty());
        CONSTEXPR_ASSERT_TRUE(str.capacity() >= 5);
    };

    CONSTEXPR_SECTION("string concatenation and modification")
    {
        const std::string s1 = "hello";
        const std::string s2 = " world";
        const std::string combined = s1 + s2;

        CONSTEXPR_EXPECT_EQ(combined.size(), 11);
        CONSTEXPR_EXPECT_EQ(combined[0], 'h');
        CONSTEXPR_ASSERT_EQ(combined[6], 'w');
    };

    CONSTEXPR_SECTION("string comparison operations")
    {
        const std::string str1 = "abc";
        const std::string str2 = "abc";
        const std::string str3 = "xyz";

        CONSTEXPR_EXPECT_TRUE(str1 == str2);
        CONSTEXPR_EXPECT_FALSE(str1 == str3);
        CONSTEXPR_EXPECT_TRUE(str1 != str3);
        CONSTEXPR_ASSERT_TRUE(str1 < str3);
    };

    CONSTEXPR_SECTION("string append and clear")
    {
        std::string str = "test";
        CONSTEXPR_EXPECT_EQ(str.size(), 4);

        str += "123";
        CONSTEXPR_EXPECT_EQ(str.size(), 7);

        str.clear();
        CONSTEXPR_EXPECT_EQ(str.size(), 0);
        CONSTEXPR_ASSERT_TRUE(str.empty());
    };
}

TEST(GTestConstexpr, NonTransientConstexprAlgorithms)
{
    CONSTEXPR_SECTION("std::find with vectors")
    {
        std::vector vec = { 5, 10, 15, 20, 25 };
        const auto it = std::ranges::find(vec, 15);

        CONSTEXPR_EXPECT_TRUE(it != vec.end());
        CONSTEXPR_EXPECT_EQ(*it, 15);
        CONSTEXPR_ASSERT_EQ(std::distance(vec.begin(), it), 2);
    };

    CONSTEXPR_SECTION("std::count operations")
    {
        std::vector vec = { 1, 2, 2, 3, 2, 4, 2 };
        const auto count = std::ranges::count(vec, 2);

        CONSTEXPR_EXPECT_EQ(count, 4);
        CONSTEXPR_ASSERT_GT(count, 2);
    };

    CONSTEXPR_SECTION("std::max_element and std::min_element")
    {
        std::vector vec = { 5, 2, 9, 1, 7 };
        const auto max_it = std::ranges::max_element(vec);
        const auto min_it = std::ranges::min_element(vec);

        CONSTEXPR_EXPECT_EQ(*max_it, 9);
        CONSTEXPR_EXPECT_EQ(*min_it, 1);
        CONSTEXPR_ASSERT_GT(*max_it, *min_it);
    };

    CONSTEXPR_SECTION("std::sort and ordering")
    {
        std::vector vec = { 5, 2, 8, 1, 9 };
        std::ranges::sort(vec);

        CONSTEXPR_EXPECT_EQ(vec[0], 1);
        CONSTEXPR_EXPECT_EQ(vec[4], 9);
        CONSTEXPR_EXPECT_LT(vec[1], vec[2]);
        CONSTEXPR_ASSERT_TRUE(vec[0] < vec[1] && vec[1] < vec[2]);
    };
}

TEST(GTestConstexpr, NonTransientConstexprMixedOperations)
{
    CONSTEXPR_SECTION("vector of strings with complex operations")
    {
        std::vector<std::string> words = { "hello", "world", "test" };
        CONSTEXPR_EXPECT_EQ(words.size(), 3);

        words.emplace_back("constexpr");
        CONSTEXPR_EXPECT_EQ(words.size(), 4);
        CONSTEXPR_EXPECT_EQ(words.back().size(), 9);

        size_t total_length = 0;
        for (const auto& word : words)
        {
            total_length += word.length();
        }
        CONSTEXPR_ASSERT_EQ(total_length, 23);
    };

    CONSTEXPR_SECTION("nested vectors and calculations")
    {
        const std::vector<std::vector<int>> matrix = {
            { 1, 2, 3 },
            { 4, 5, 6 },
            { 7, 8, 9 }
        };

        CONSTEXPR_EXPECT_EQ(matrix.size(), 3);
        CONSTEXPR_EXPECT_EQ(matrix[0].size(), 3);
        CONSTEXPR_EXPECT_EQ(matrix[1][1], 5);

        int sum = 0;
        for (const auto& row : matrix)
        {
            for (const auto& val : row)
            {
                sum += val;
            }
        }
        CONSTEXPR_ASSERT_EQ(sum, 45);
    };
}
