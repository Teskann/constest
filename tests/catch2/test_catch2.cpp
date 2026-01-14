#include <algorithm>
#include <catch2/catch_test_macros.hpp>
#include <constest.hpp>
#include <numeric>
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

constexpr int power(const int base, const int exp)
{
    return exp == 0 ? 1 : base * power(base, exp - 1);
}

TEST_CASE("Catch2 CONSTEXPR_REQUIRE tests", "[catch2][require]")
{
    CONSTEXPR_SECTION("basic arithmetic expressions")
    {
        CONSTEXPR_REQUIRE(2 + 2 == 4);
        CONSTEXPR_REQUIRE(10 * 5 == 50);
        CONSTEXPR_REQUIRE(100 / 4 == 25);
        CONSTEXPR_REQUIRE(17 % 5 == 2);
    };

    CONSTEXPR_SECTION("complex mathematical operations")
    {
        constexpr int a = 42;
        constexpr int b = 7;
        CONSTEXPR_REQUIRE(a * b == 294);
        CONSTEXPR_REQUIRE((a + b) * (a - b) == 1715);
        CONSTEXPR_REQUIRE(power(2, 10) == 1024);
    };

    CONSTEXPR_SECTION("fibonacci sequence validation")
    {
        CONSTEXPR_REQUIRE(fibonacci(0) == 0);
        CONSTEXPR_REQUIRE(fibonacci(1) == 1);
        CONSTEXPR_REQUIRE(fibonacci(5) == 5);
        CONSTEXPR_REQUIRE(fibonacci(10) == 55);
        CONSTEXPR_REQUIRE(fibonacci(12) == 144);
    };

    CONSTEXPR_SECTION("factorial calculations")
    {
        CONSTEXPR_REQUIRE(factorial(0) == 1);
        CONSTEXPR_REQUIRE(factorial(1) == 1);
        CONSTEXPR_REQUIRE(factorial(5) == 120);
        CONSTEXPR_REQUIRE(factorial(6) == 720);
        CONSTEXPR_REQUIRE(factorial(7) == 5040);
    };
}

TEST_CASE("Catch2 CONSTEXPR_REQUIRE_FALSE tests", "[catch2][require_false]")
{
    CONSTEXPR_SECTION("negated boolean expressions")
    {
        CONSTEXPR_REQUIRE_FALSE(false);
        CONSTEXPR_REQUIRE_FALSE(5 < 3);
        CONSTEXPR_REQUIRE_FALSE(10 == 20);
        CONSTEXPR_REQUIRE_FALSE(100 % 10 != 0);
    };

    CONSTEXPR_SECTION("complex negated conditions")
    {
        constexpr int x = 100;
        constexpr int y = 50;
        CONSTEXPR_REQUIRE_FALSE(x < y);
        CONSTEXPR_REQUIRE_FALSE((x + y) == (x - y));
        CONSTEXPR_REQUIRE_FALSE(fibonacci(5) > factorial(5));
    };

    CONSTEXPR_SECTION("logical combinations")
    {
        CONSTEXPR_REQUIRE_FALSE(((10 > 20) && (30 > 20)));
        CONSTEXPR_REQUIRE_FALSE(((5 == 6) || (7 == 8)));
        CONSTEXPR_REQUIRE_FALSE(!(true && true));
    };
}

TEST_CASE("Catch2 CONSTEXPR_CHECK tests", "[catch2][check]")
{
    CONSTEXPR_SECTION("comparison operations")
    {
        CONSTEXPR_CHECK(5 > 3);
        CONSTEXPR_CHECK(10 >= 10);
        CONSTEXPR_CHECK(7 < 15);
        CONSTEXPR_CHECK(20 <= 20);
        CONSTEXPR_CHECK(100 != 99);
    };

    CONSTEXPR_SECTION("expression evaluation")
    {
        constexpr int a = 25;
        constexpr int b = 5;
        CONSTEXPR_CHECK(a / b == 5);
        CONSTEXPR_CHECK((a * b) > (a + b));
        CONSTEXPR_CHECK((a - b) * 2 == 40);
    };

    CONSTEXPR_SECTION("recursive function results")
    {
        CONSTEXPR_CHECK(fibonacci(7) == 13);
        CONSTEXPR_CHECK(fibonacci(8) > fibonacci(7));
        CONSTEXPR_CHECK(factorial(4) == 24);
        CONSTEXPR_CHECK(power(3, 4) == 81);
    };
}

TEST_CASE("Catch2 CONSTEXPR_CHECK_FALSE tests", "[catch2][check_false]")
{
    CONSTEXPR_SECTION("negated comparisons")
    {
        CONSTEXPR_CHECK_FALSE(3 > 5);
        CONSTEXPR_CHECK_FALSE(10 < 5);
        CONSTEXPR_CHECK_FALSE(15 == 20);
    };

    CONSTEXPR_SECTION("complex negated expressions")
    {
        constexpr int value = 200;
        CONSTEXPR_CHECK_FALSE(value < 100);
        CONSTEXPR_CHECK_FALSE((value / 2) != 100);
        CONSTEXPR_CHECK_FALSE(power(2, 8) < 200);
    };
}

TEST_CASE("Catch2 mixed complex expressions", "[catch2][mixed]")
{
    CONSTEXPR_SECTION("combining all assertion types")
    {
        constexpr int fib_10 = fibonacci(10);
        constexpr int fact_5 = factorial(5);
        constexpr int pow_2_7 = power(2, 7);

        CONSTEXPR_REQUIRE(fib_10 == 55);
        CONSTEXPR_REQUIRE(fact_5 == 120);
        CONSTEXPR_CHECK(pow_2_7 == 128);
        CONSTEXPR_CHECK_FALSE(fib_10 > fact_5);
        CONSTEXPR_REQUIRE_FALSE(pow_2_7 < fib_10);
    };

    CONSTEXPR_SECTION("nested calculations with multiple operations")
    {
        constexpr int a = 12;
        constexpr int b = 8;
        constexpr int c = 4;

        CONSTEXPR_REQUIRE((a + b) * c == 80);
        CONSTEXPR_CHECK(a * b / c == 24);
        CONSTEXPR_CHECK((a - b) * c == c * c);
        CONSTEXPR_REQUIRE_FALSE((a * b) < (a + b));
    };

    CONSTEXPR_SECTION("mathematical relationships")
    {
        CONSTEXPR_REQUIRE(fibonacci(6) + fibonacci(7) == fibonacci(8));
        CONSTEXPR_CHECK(factorial(4) * 5 == factorial(5));
        CONSTEXPR_CHECK(power(2, 5) * power(2, 3) == power(2, 8));
        CONSTEXPR_REQUIRE_FALSE(fibonacci(10) == factorial(5));
    };
}

TEST_CASE("Catch2 boundary and edge cases", "[catch2][edge]")
{
    CONSTEXPR_SECTION("zero and one values")
    {
        CONSTEXPR_REQUIRE(fibonacci(0) == 0);
        CONSTEXPR_REQUIRE(fibonacci(1) == 1);
        CONSTEXPR_CHECK(factorial(0) == 1);
        CONSTEXPR_CHECK(power(0, 0) == 1);
        CONSTEXPR_CHECK(power(100, 0) == 1);
    };

    CONSTEXPR_SECTION("identity operations")
    {
        constexpr int n = 42;
        CONSTEXPR_REQUIRE(n * 1 == n);
        CONSTEXPR_CHECK(n / 1 == n);
        CONSTEXPR_CHECK(n + 0 == n);
        CONSTEXPR_CHECK(n - 0 == n);
    };
}

TEST_CASE("Catch2 non-transient vector operations", "[catch2][vector]")
{
    CONSTEXPR_SECTION("vector creation and basic operations")
    {
        const std::vector vec = { 1, 2, 3, 4, 5 };
        CONSTEXPR_REQUIRE(vec.size() == 5);
        CONSTEXPR_CHECK(!vec.empty());
        CONSTEXPR_CHECK(vec[0] == 1);
        CONSTEXPR_CHECK(vec[4] == 5);
    };

    CONSTEXPR_SECTION("vector modification and growth")
    {
        std::vector<int> vec;
        vec.push_back(10);
        vec.push_back(20);
        vec.push_back(30);

        CONSTEXPR_REQUIRE(vec.size() == 3);
        CONSTEXPR_CHECK(vec[1] == 20);

        vec[1] = 99;
        CONSTEXPR_REQUIRE(vec[1] == 99);
    };

    CONSTEXPR_SECTION("vector range-based operations")
    {
        const std::vector numbers = { 2, 4, 6, 8, 10 };
        int product = 1;
        for (const auto& n : numbers)
        {
            product *= n;
        }
        CONSTEXPR_REQUIRE(product == 3840);
        CONSTEXPR_CHECK(numbers.front() == 2);
        CONSTEXPR_CHECK(numbers.back() == 10);
    };

    CONSTEXPR_SECTION("vector with std::accumulate")
    {
        std::vector values = { 5, 10, 15, 20, 25 };
        const int sum = std::accumulate(values.begin(), values.end(), 0);

        CONSTEXPR_REQUIRE(sum == 75);
        CONSTEXPR_CHECK(sum == static_cast<int>(values.size()) * 15);
    };
}

TEST_CASE("Catch2 non-transient string operations", "[catch2][string]")
{
    CONSTEXPR_SECTION("string creation and size")
    {
        const std::string text = "constexpr";
        CONSTEXPR_REQUIRE(text.size() == 9);
        CONSTEXPR_REQUIRE(text.length() == 9);
        CONSTEXPR_CHECK_FALSE(text.empty());
    };

    CONSTEXPR_SECTION("string concatenation")
    {
        const std::string part1 = "Hello";
        const std::string part2 = " ";
        const std::string part3 = "World";
        const std::string full = part1 + part2 + part3;

        CONSTEXPR_REQUIRE(full.size() == 11);
        CONSTEXPR_CHECK(full[0] == 'H');
        CONSTEXPR_CHECK(full[6] == 'W');
    };

    CONSTEXPR_SECTION("string comparison and equality")
    {
        const std::string s1 = "test";
        const std::string s2 = "test";
        const std::string s3 = "different";

        CONSTEXPR_REQUIRE(s1 == s2);
        CONSTEXPR_REQUIRE(s1 != s3);
        CONSTEXPR_CHECK(s1.size() == s2.size());
        CONSTEXPR_CHECK_FALSE(s1 == s3);
    };

    CONSTEXPR_SECTION("string mutation operations")
    {
        std::string str = "abc";
        str += "def";

        CONSTEXPR_REQUIRE(str.size() == 6);
        CONSTEXPR_CHECK(str[3] == 'd');

        str.push_back('g');
        CONSTEXPR_REQUIRE(str.size() == 7);
    };
}

TEST_CASE("Catch2 non-transient algorithm operations", "[catch2][algorithms]")
{
    CONSTEXPR_SECTION("std::find on vector")
    {
        const std::vector data = { 10, 20, 30, 40, 50 };
        auto it = std::ranges::find(data, 30);

        CONSTEXPR_REQUIRE(it != data.end());
        CONSTEXPR_CHECK(*it == 30);
        CONSTEXPR_CHECK(std::distance(data.begin(), it) == 2);
    };

    CONSTEXPR_SECTION("std::count with duplicates")
    {
        const std::vector numbers = { 1, 3, 3, 5, 3, 7, 3 };
        const auto count = std::ranges::count(numbers, 3);

        CONSTEXPR_REQUIRE(count == 4);
        CONSTEXPR_CHECK(count > 3);
        CONSTEXPR_CHECK_FALSE(count < 4);
    };

    CONSTEXPR_SECTION("std::sort and ordering verification")
    {
        std::vector unsorted = { 9, 3, 7, 1, 5 };
        std::ranges::sort(unsorted);

        CONSTEXPR_REQUIRE(unsorted[0] == 1);
        CONSTEXPR_REQUIRE(unsorted[4] == 9);
        CONSTEXPR_CHECK(unsorted[0] < unsorted[1]);
        CONSTEXPR_CHECK(unsorted[3] < unsorted[4]);
    };

    CONSTEXPR_SECTION("std::reverse and element checking")
    {
        std::vector vec = { 1, 2, 3, 4, 5 };
        std::ranges::reverse(vec);

        CONSTEXPR_REQUIRE(vec[0] == 5);
        CONSTEXPR_REQUIRE(vec[4] == 1);
        CONSTEXPR_CHECK(vec.front() == 5);
        CONSTEXPR_CHECK(vec.back() == 1);
    };
}

TEST_CASE("Catch2 non-transient complex containers", "[catch2][complex]")
{
    CONSTEXPR_SECTION("vector of strings processing")
    {
        const std::vector<std::string> words = { "one", "two", "three", "four" };

        CONSTEXPR_REQUIRE(words.size() == 4);
        CONSTEXPR_CHECK(words[0].size() == 3);
        CONSTEXPR_CHECK(words[2].size() == 5);

        size_t total = 0;
        for (const auto& word : words)
        {
            total += word.length();
        }
        CONSTEXPR_REQUIRE(total == 15);
    };

    CONSTEXPR_SECTION("nested vector matrix operations")
    {
        const std::vector<std::vector<int>> matrix = {
            { 1, 2 },
            { 3, 4 },
            { 5, 6 }
        };

        CONSTEXPR_REQUIRE(matrix.size() == 3);
        CONSTEXPR_REQUIRE(matrix[0].size() == 2);
        CONSTEXPR_CHECK(matrix[1][0] == 3);
        CONSTEXPR_CHECK(matrix[2][1] == 6);

        int sum = 0;
        for (const auto& row : matrix)
        {
            sum += std::accumulate(row.begin(), row.end(), 0);
        }
        CONSTEXPR_REQUIRE(sum == 21);
    };

    CONSTEXPR_SECTION("mixed container operations")
    {
        std::vector v1 = { 1, 2, 3 };
        const std::vector v2 = { 4, 5, 6 };

        v1.insert(v1.end(), v2.begin(), v2.end());

        CONSTEXPR_REQUIRE(v1.size() == 6);
        CONSTEXPR_CHECK(v1[3] == 4);
        CONSTEXPR_CHECK(v1[5] == 6);
        CONSTEXPR_REQUIRE_FALSE(v1.empty());
    };
}
