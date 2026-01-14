#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <algorithm>
#include <constest.hpp>
#include <doctest/doctest.h>
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

constexpr int sum_of_squares(const int n)
{
    return n == 0 ? 0 : n * n + sum_of_squares(n - 1);
}

TEST_CASE("doctest CONSTEXPR_REQUIRE tests")
{
    CONSTEXPR_SECTION("basic arithmetic expressions")
    {
        CONSTEXPR_REQUIRE(2 + 2 == 4);
        CONSTEXPR_REQUIRE(15 - 7 == 8);
        CONSTEXPR_REQUIRE(6 * 7 == 42);
        CONSTEXPR_REQUIRE(144 / 12 == 12);
    };

    CONSTEXPR_SECTION("modulo and bitwise operations")
    {
        CONSTEXPR_REQUIRE(17 % 5 == 2);
        CONSTEXPR_REQUIRE(100 % 10 == 0);
        CONSTEXPR_REQUIRE((8 << 2) == 32);
        CONSTEXPR_REQUIRE((64 >> 3) == 8);
    };

    CONSTEXPR_SECTION("complex arithmetic combinations")
    {
        constexpr int a = 25;
        constexpr int b = 5;
        constexpr int c = 3;
        CONSTEXPR_REQUIRE((a + b) * c == 90);
        CONSTEXPR_REQUIRE((a * b) - (c * c) == 116);
        CONSTEXPR_REQUIRE(a / b + c * 2 == 11);
    };

    CONSTEXPR_SECTION("recursive function validation")
    {
        CONSTEXPR_REQUIRE(fibonacci(7) == 13);
        CONSTEXPR_REQUIRE(fibonacci(11) == 89);
        CONSTEXPR_REQUIRE(factorial(6) == 720);
        CONSTEXPR_REQUIRE(power(3, 5) == 243);
    };
}

TEST_CASE("doctest CONSTEXPR_REQUIRE_FALSE tests")
{
    CONSTEXPR_SECTION("negated boolean conditions")
    {
        CONSTEXPR_REQUIRE_FALSE(false);
        CONSTEXPR_REQUIRE_FALSE(5 > 10);
        CONSTEXPR_REQUIRE_FALSE(20 == 25);
        CONSTEXPR_REQUIRE_FALSE(100 < 50);
    };

    CONSTEXPR_SECTION("negated complex expressions")
    {
        constexpr int x = 150;
        constexpr int y = 75;
        CONSTEXPR_REQUIRE_FALSE(x < y);
        CONSTEXPR_REQUIRE_FALSE((x / 2) != y);
        CONSTEXPR_REQUIRE_FALSE(fibonacci(8) == fibonacci(9));
    };
}

TEST_CASE("doctest CONSTEXPR_CHECK tests")
{
    CONSTEXPR_SECTION("comparison operations")
    {
        CONSTEXPR_CHECK(10 > 5);
        CONSTEXPR_CHECK(20 >= 20);
        CONSTEXPR_CHECK(15 < 30);
        CONSTEXPR_CHECK(50 <= 50);
        CONSTEXPR_CHECK(99 != 100);
    };

    CONSTEXPR_SECTION("mathematical property checks")
    {
        CONSTEXPR_CHECK(power(2, 8) == 256);
        CONSTEXPR_CHECK(sum_of_squares(4) == 30);
        CONSTEXPR_CHECK(fibonacci(6) + fibonacci(7) == fibonacci(8));
        CONSTEXPR_CHECK(factorial(5) / factorial(4) == 5);
    };

    CONSTEXPR_SECTION("expression chains")
    {
        constexpr int base = 100;
        CONSTEXPR_CHECK((base / 2) == 50);
        CONSTEXPR_CHECK((base * 2) > base);
        CONSTEXPR_CHECK((base - 50) <= base);
        CONSTEXPR_CHECK((base + 100) >= 200);
    };
}

TEST_CASE("doctest CONSTEXPR_CHECK_FALSE tests")
{
    CONSTEXPR_SECTION("negated comparisons")
    {
        CONSTEXPR_CHECK_FALSE(5 > 10);
        CONSTEXPR_CHECK_FALSE(15 == 20);
        CONSTEXPR_CHECK_FALSE(100 < 50);
    };

    CONSTEXPR_SECTION("complex negated conditions")
    {
        constexpr int value = 300;
        CONSTEXPR_CHECK_FALSE(value < 200);
        CONSTEXPR_CHECK_FALSE((value / 3) != 100);
        CONSTEXPR_CHECK_FALSE(power(2, 7) > value);
    };
}

TEST_CASE("doctest mixed complex expressions")
{
    CONSTEXPR_SECTION("combining multiple assertion types")
    {
        constexpr int fib_9 = fibonacci(9);
        constexpr int fact_4 = factorial(4);
        constexpr int pow_3_3 = power(3, 3);

        CONSTEXPR_REQUIRE(fib_9 == 34);
        CONSTEXPR_CHECK(fact_4 == 24);
        CONSTEXPR_REQUIRE(pow_3_3 == 27);
        CONSTEXPR_CHECK_FALSE(fib_9 < fact_4);
        CONSTEXPR_REQUIRE_FALSE(pow_3_3 < 20);
    };

    CONSTEXPR_SECTION("nested arithmetic with all operators")
    {
        constexpr int a = 16;
        constexpr int b = 4;
        constexpr int c = 2;

        CONSTEXPR_REQUIRE((a / b) * c == 8);
        CONSTEXPR_CHECK((a % b) == 0);
        CONSTEXPR_CHECK((a - b) / c == 6);
        CONSTEXPR_REQUIRE_FALSE((a * b) < (a + b));
    };

    CONSTEXPR_SECTION("mathematical identities and properties")
    {
        CONSTEXPR_REQUIRE(power(2, 3) + power(2, 3) == power(2, 4));
        CONSTEXPR_CHECK(fibonacci(5) * 2 == 10);
        CONSTEXPR_CHECK(factorial(3) * factorial(2) == 12);
        CONSTEXPR_REQUIRE_FALSE(sum_of_squares(3) == sum_of_squares(2));
    };
}

TEST_CASE("doctest edge cases and boundaries")
{
    CONSTEXPR_SECTION("zero value operations")
    {
        CONSTEXPR_REQUIRE(fibonacci(0) == 0);
        CONSTEXPR_REQUIRE(factorial(0) == 1);
        CONSTEXPR_CHECK(power(5, 0) == 1);
        CONSTEXPR_CHECK(sum_of_squares(0) == 0);
    };

    CONSTEXPR_SECTION("one value operations")
    {
        CONSTEXPR_REQUIRE(fibonacci(1) == 1);
        CONSTEXPR_REQUIRE(factorial(1) == 1);
        CONSTEXPR_CHECK(power(100, 1) == 100);
        CONSTEXPR_CHECK(sum_of_squares(1) == 1);
    };

    CONSTEXPR_SECTION("identity properties")
    {
        constexpr int n = 77;
        CONSTEXPR_REQUIRE(n * 1 == n);
        CONSTEXPR_CHECK(n / 1 == n);
        CONSTEXPR_CHECK(n + 0 == n);
        CONSTEXPR_CHECK(n - 0 == n);
        CONSTEXPR_REQUIRE(power(n, 1) == n);
    };

    CONSTEXPR_SECTION("large value calculations")
    {
        CONSTEXPR_REQUIRE(fibonacci(15) == 610);
        CONSTEXPR_CHECK(factorial(8) == 40320);
        CONSTEXPR_CHECK(power(2, 12) == 4096);
        CONSTEXPR_REQUIRE(sum_of_squares(10) == 385);
    };
}

TEST_CASE("doctest non-transient vector tests")
{
    CONSTEXPR_SECTION("vector initialization and access")
    {
        std::vector data = { 10, 20, 30, 40, 50 };
        CONSTEXPR_REQUIRE(data.size() == 5);
        CONSTEXPR_CHECK(data[0] == 10);
        CONSTEXPR_CHECK(data[4] == 50);
        CONSTEXPR_CHECK_FALSE(data.empty());
    };

    CONSTEXPR_SECTION("vector dynamic growth")
    {
        std::vector<int> vec;
        vec.push_back(100);
        vec.push_back(200);
        vec.push_back(300);

        CONSTEXPR_REQUIRE(vec.size() == 3);
        CONSTEXPR_CHECK(vec[1] == 200);
        CONSTEXPR_CHECK(vec.back() == 300);
    };

    CONSTEXPR_SECTION("vector element modification")
    {
        std::vector values = { 1, 2, 3, 4, 5 };
        values[2] = 99;

        CONSTEXPR_REQUIRE(values[2] == 99);
        CONSTEXPR_CHECK(values.size() == 5);
        CONSTEXPR_CHECK(values.front() == 1);
    };

    CONSTEXPR_SECTION("vector iteration and accumulation")
    {
        const std::vector nums = { 5, 10, 15, 20 };
        int total = 0;
        for (const auto& n : nums)
        {
            total += n;
        }

        CONSTEXPR_REQUIRE(total == 50);
        CONSTEXPR_CHECK(total == static_cast<int>(static_cast<double>(nums.size()) * 12.5));
    };
}

TEST_CASE("doctest non-transient string tests")
{
    CONSTEXPR_SECTION("string creation and properties")
    {
        const std::string text = "testing";
        CONSTEXPR_REQUIRE(text.size() == 7);
        CONSTEXPR_REQUIRE(text.length() == 7);
        CONSTEXPR_CHECK(!text.empty());
    };

    CONSTEXPR_SECTION("string concatenation operations")
    {
        const std::string prefix = "Hello";
        const std::string suffix = "World";
        const std::string result = prefix + " " + suffix;

        CONSTEXPR_REQUIRE(result.size() == 11);
        CONSTEXPR_CHECK(result[0] == 'H');
        CONSTEXPR_CHECK(result[6] == 'W');
    };

    CONSTEXPR_SECTION("string comparison tests")
    {
        const std::string a = "alpha";
        const std::string b = "alpha";
        const std::string c = "beta";

        CONSTEXPR_REQUIRE(a == b);
        CONSTEXPR_REQUIRE(a != c);
        CONSTEXPR_CHECK(a < c);
        CONSTEXPR_CHECK_FALSE(a == c);
    };

    CONSTEXPR_SECTION("string modification and append")
    {
        std::string str = "foo";
        str += "bar";

        CONSTEXPR_REQUIRE(str.size() == 6);
        CONSTEXPR_CHECK(str[3] == 'b');

        str.push_back('!');
        CONSTEXPR_REQUIRE(str.size() == 7);
        CONSTEXPR_CHECK(str.back() == '!');
    };
}

TEST_CASE("doctest non-transient algorithm tests")
{
    CONSTEXPR_SECTION("std::find usage")
    {
        const std::vector collection = { 7, 14, 21, 28, 35 };
        auto iter = std::ranges::find(collection, 21);

        CONSTEXPR_REQUIRE(iter != collection.end());
        CONSTEXPR_CHECK(*iter == 21);
        CONSTEXPR_CHECK(std::distance(collection.begin(), iter) == 2);
    };

    CONSTEXPR_SECTION("std::count element frequency")
    {
        const std::vector data = { 5, 10, 5, 15, 5, 20, 5 };
        const auto count = std::ranges::count(data, 5);

        CONSTEXPR_REQUIRE(count == 4);
        CONSTEXPR_CHECK(count > 2);
        CONSTEXPR_CHECK_FALSE(count < 3);
    };

    CONSTEXPR_SECTION("std::accumulate sum")
    {
        const std::vector numbers = { 1, 2, 3, 4, 5, 6 };
        int sum = std::accumulate(numbers.begin(), numbers.end(), 0);

        CONSTEXPR_REQUIRE(sum == 21);
        CONSTEXPR_CHECK(sum > 20);
    };

    CONSTEXPR_SECTION("std::sort ordering")
    {
        std::vector unsorted = { 8, 3, 9, 1, 5, 2 };
        std::ranges::sort(unsorted);

        CONSTEXPR_REQUIRE(unsorted[0] == 1);
        CONSTEXPR_REQUIRE(unsorted[5] == 9);
        CONSTEXPR_CHECK(unsorted[2] < unsorted[3]);
    };

    CONSTEXPR_SECTION("std::min_element and std::max_element")
    {
        std::vector values = { 15, 8, 23, 4, 16 };
        const auto min_it = std::ranges::min_element(values);
        const auto max_it = std::ranges::max_element(values);

        CONSTEXPR_REQUIRE(*min_it == 4);
        CONSTEXPR_REQUIRE(*max_it == 23);
        CONSTEXPR_CHECK(*max_it > *min_it);
    };
}

TEST_CASE("doctest non-transient complex containers")
{
    CONSTEXPR_SECTION("vector of strings manipulation")
    {
        std::vector<std::string> words = { "apple", "banana", "cherry" };

        CONSTEXPR_REQUIRE(words.size() == 3);
        CONSTEXPR_CHECK(words[1] == "banana");

        words.emplace_back("date");
        CONSTEXPR_REQUIRE(words.size() == 4);

        size_t total_chars = 0;
        for (const auto& word : words)
        {
            total_chars += word.size();
        }
        CONSTEXPR_REQUIRE(total_chars == 21);
    };

    CONSTEXPR_SECTION("nested vector structures")
    {
        const std::vector<std::vector<int>> grid = {
            { 1, 2, 3 },
            { 4, 5, 6 },
            { 7, 8, 9 }
        };

        CONSTEXPR_REQUIRE(grid.size() == 3);
        CONSTEXPR_CHECK(grid[0].size() == 3);
        CONSTEXPR_CHECK(grid[1][1] == 5);
        CONSTEXPR_CHECK(grid[2][2] == 9);

        int diagonal_sum = grid[0][0] + grid[1][1] + grid[2][2];
        CONSTEXPR_REQUIRE(diagonal_sum == 15);
    };

    CONSTEXPR_SECTION("vector merge operations")
    {
        std::vector first = { 1, 2, 3 };
        const std::vector second = { 4, 5, 6 };

        first.insert(first.end(), second.begin(), second.end());

        CONSTEXPR_REQUIRE(first.size() == 6);
        CONSTEXPR_CHECK(first[3] == 4);
        CONSTEXPR_CHECK(first[5] == 6);

        int sum = std::accumulate(first.begin(), first.end(), 0);
        CONSTEXPR_REQUIRE(sum == 21);
    };
}
