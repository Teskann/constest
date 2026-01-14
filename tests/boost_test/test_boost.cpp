#define BOOST_TEST_MODULE SampleTest
#include <algorithm>
#include <boost/test/unit_test.hpp>
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

constexpr int gcd(const int a, const int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

constexpr bool is_even(const int n)
{
    return n % 2 == 0;
}

BOOST_AUTO_TEST_CASE(boost_test_basic_arithmetic)
{
    CONSTEXPR_SECTION("simple addition and subtraction")
    {
        CONSTEXPR_BOOST_TEST(2 + 2 == 4);
        CONSTEXPR_BOOST_TEST(10 - 3 == 7);
        CONSTEXPR_BOOST_TEST(5 + 5 == 10);
        CONSTEXPR_BOOST_TEST(100 - 25 == 75);
    };

    CONSTEXPR_SECTION("multiplication and division")
    {
        CONSTEXPR_BOOST_TEST(6 * 7 == 42);
        CONSTEXPR_BOOST_TEST(144 / 12 == 12);
        CONSTEXPR_BOOST_TEST(25 * 4 == 100);
        CONSTEXPR_BOOST_TEST(1000 / 10 == 100);
    };

    CONSTEXPR_SECTION("modulo operations")
    {
        CONSTEXPR_BOOST_TEST(17 % 5 == 2);
        CONSTEXPR_BOOST_TEST(100 % 7 == 2);
        CONSTEXPR_BOOST_TEST(50 % 10 == 0);
        CONSTEXPR_BOOST_TEST(23 % 8 == 7);
    };
}

BOOST_AUTO_TEST_CASE(boost_test_comparison_operators)
{
    CONSTEXPR_SECTION("less than and greater than")
    {
        CONSTEXPR_BOOST_TEST(5 < 10);
        CONSTEXPR_BOOST_TEST(100 > 50);
        CONSTEXPR_BOOST_TEST(3 < 7);
        CONSTEXPR_BOOST_TEST(99 > 98);
    };

    CONSTEXPR_SECTION("less or equal and greater or equal")
    {
        CONSTEXPR_BOOST_TEST(10 <= 10);
        CONSTEXPR_BOOST_TEST(5 <= 8);
        CONSTEXPR_BOOST_TEST(20 >= 20);
        CONSTEXPR_BOOST_TEST(30 >= 25);
    };

    CONSTEXPR_SECTION("equality and inequality")
    {
        CONSTEXPR_BOOST_TEST(42 == 42);
        CONSTEXPR_BOOST_TEST(10 != 20);
        CONSTEXPR_BOOST_TEST(100 == 100);
        CONSTEXPR_BOOST_TEST(7 != 8);
    };
}

BOOST_AUTO_TEST_CASE(boost_test_fibonacci_sequence)
{
    CONSTEXPR_SECTION("first fibonacci numbers")
    {
        CONSTEXPR_BOOST_TEST(fibonacci(0) == 0);
        CONSTEXPR_BOOST_TEST(fibonacci(1) == 1);
        CONSTEXPR_BOOST_TEST(fibonacci(2) == 1);
        CONSTEXPR_BOOST_TEST(fibonacci(3) == 2);
        CONSTEXPR_BOOST_TEST(fibonacci(4) == 3);
    };

    CONSTEXPR_SECTION("larger fibonacci numbers")
    {
        CONSTEXPR_BOOST_TEST(fibonacci(5) == 5);
        CONSTEXPR_BOOST_TEST(fibonacci(8) == 21);
        CONSTEXPR_BOOST_TEST(fibonacci(10) == 55);
        CONSTEXPR_BOOST_TEST(fibonacci(12) == 144);
    };

    CONSTEXPR_SECTION("fibonacci relationships")
    {
        CONSTEXPR_BOOST_TEST(fibonacci(6) + fibonacci(7) == fibonacci(8));
        CONSTEXPR_BOOST_TEST(fibonacci(9) > fibonacci(8));
    };
}

BOOST_AUTO_TEST_CASE(boost_test_factorial_computations)
{
    CONSTEXPR_SECTION("base factorial cases")
    {
        CONSTEXPR_BOOST_TEST(factorial(0) == 1);
        CONSTEXPR_BOOST_TEST(factorial(1) == 1);
        CONSTEXPR_BOOST_TEST(factorial(2) == 2);
        CONSTEXPR_BOOST_TEST(factorial(3) == 6);
    };

    CONSTEXPR_SECTION("larger factorial values")
    {
        CONSTEXPR_BOOST_TEST(factorial(4) == 24);
        CONSTEXPR_BOOST_TEST(factorial(5) == 120);
        CONSTEXPR_BOOST_TEST(factorial(6) == 720);
        CONSTEXPR_BOOST_TEST(factorial(7) == 5040);
    };

    CONSTEXPR_SECTION("factorial properties")
    {
        CONSTEXPR_BOOST_TEST(factorial(5) / factorial(4) == 5);
        CONSTEXPR_BOOST_TEST(factorial(6) == factorial(5) * 6);
        CONSTEXPR_BOOST_TEST(factorial(4) > factorial(3));
    };
}

BOOST_AUTO_TEST_CASE(boost_test_power_calculations)
{
    CONSTEXPR_SECTION("powers of two")
    {
        CONSTEXPR_BOOST_TEST(power(2, 0) == 1);
        CONSTEXPR_BOOST_TEST(power(2, 5) == 32);
        CONSTEXPR_BOOST_TEST(power(2, 8) == 256);
        CONSTEXPR_BOOST_TEST(power(2, 10) == 1024);
    };

    CONSTEXPR_SECTION("powers of three")
    {
        CONSTEXPR_BOOST_TEST(power(3, 2) == 9);
        CONSTEXPR_BOOST_TEST(power(3, 3) == 27);
        CONSTEXPR_BOOST_TEST(power(3, 4) == 81);
        CONSTEXPR_BOOST_TEST(power(3, 5) == 243);
    };

    CONSTEXPR_SECTION("power properties")
    {
        CONSTEXPR_BOOST_TEST(power(5, 0) == 1);
        CONSTEXPR_BOOST_TEST(power(100, 1) == 100);
        CONSTEXPR_BOOST_TEST(power(2, 3) * power(2, 2) == power(2, 5));
    };
}

BOOST_AUTO_TEST_CASE(boost_test_gcd_algorithm)
{
    CONSTEXPR_SECTION("basic gcd calculations")
    {
        CONSTEXPR_BOOST_TEST(gcd(12, 8) == 4);
        CONSTEXPR_BOOST_TEST(gcd(100, 50) == 50);
        CONSTEXPR_BOOST_TEST(gcd(17, 13) == 1);
        CONSTEXPR_BOOST_TEST(gcd(48, 18) == 6);
    };

    CONSTEXPR_SECTION("gcd special cases")
    {
        CONSTEXPR_BOOST_TEST(gcd(7, 7) == 7);
        CONSTEXPR_BOOST_TEST(gcd(13, 1) == 1);
        CONSTEXPR_BOOST_TEST(gcd(100, 10) == 10);
    };
}

BOOST_AUTO_TEST_CASE(boost_test_boolean_functions)
{
    CONSTEXPR_SECTION("even number detection")
    {
        CONSTEXPR_BOOST_TEST(is_even(0));
        CONSTEXPR_BOOST_TEST(is_even(2));
        CONSTEXPR_BOOST_TEST(is_even(100));
        CONSTEXPR_BOOST_TEST(!is_even(1));
        CONSTEXPR_BOOST_TEST(!is_even(99));
    };
}

BOOST_AUTO_TEST_CASE(boost_test_complex_expressions)
{
    CONSTEXPR_SECTION("nested arithmetic operations")
    {
        constexpr int a = 12;
        constexpr int b = 8;
        constexpr int c = 4;

        CONSTEXPR_BOOST_TEST((a + b) * c == 80);
        CONSTEXPR_BOOST_TEST((a * b) / c == 24);
        CONSTEXPR_BOOST_TEST((a - b) + c == 8);
        CONSTEXPR_BOOST_TEST((a / c) * (b / c) == 6);
    };

    CONSTEXPR_SECTION("mixed function calls")
    {
        constexpr int fib_10 = fibonacci(10);
        constexpr int fact_5 = factorial(5);
        constexpr int pow_2_8 = power(2, 8);

        CONSTEXPR_BOOST_TEST(fib_10 == 55);
        CONSTEXPR_BOOST_TEST(fact_5 == 120);
        CONSTEXPR_BOOST_TEST(pow_2_8 == 256);
        CONSTEXPR_BOOST_TEST(fib_10 < fact_5);
        CONSTEXPR_BOOST_TEST(pow_2_8 > fib_10);
    };

    CONSTEXPR_SECTION("combining multiple operations")
    {
        CONSTEXPR_BOOST_TEST((fibonacci(5) + fibonacci(6)) == fibonacci(7));
        CONSTEXPR_BOOST_TEST(factorial(4) * 5 == factorial(5));
        CONSTEXPR_BOOST_TEST(power(2, 4) + power(2, 4) == power(2, 5));
        CONSTEXPR_BOOST_TEST(gcd(factorial(4), factorial(3)) == factorial(3));
    };
}

BOOST_AUTO_TEST_CASE(boost_test_bitwise_operations)
{
    CONSTEXPR_SECTION("left and right shifts")
    {
        CONSTEXPR_BOOST_TEST((1 << 3) == 8);
        CONSTEXPR_BOOST_TEST((16 >> 2) == 4);
        CONSTEXPR_BOOST_TEST((5 << 4) == 80);
        CONSTEXPR_BOOST_TEST((128 >> 3) == 16);
    };

    CONSTEXPR_SECTION("bitwise and, or, xor")
    {
        CONSTEXPR_BOOST_TEST((12 & 10) == 8);
        CONSTEXPR_BOOST_TEST((12 | 10) == 14);
        CONSTEXPR_BOOST_TEST((12 ^ 10) == 6);
        CONSTEXPR_BOOST_TEST((~0) == -1);
    };
}

BOOST_AUTO_TEST_CASE(boost_test_mathematical_identities)
{
    CONSTEXPR_SECTION("multiplicative and additive identity")
    {
        constexpr int n = 99;
        CONSTEXPR_BOOST_TEST(n * 1 == n);
        CONSTEXPR_BOOST_TEST(n / 1 == n);
        CONSTEXPR_BOOST_TEST(n + 0 == n);
        CONSTEXPR_BOOST_TEST(n - 0 == n);
    };

    CONSTEXPR_SECTION("distributive property")
    {
        constexpr int a = 7;
        constexpr int b = 5;
        constexpr int c = 3;
        CONSTEXPR_BOOST_TEST(a * (b + c) == (a * b) + (a * c));
    };

    CONSTEXPR_SECTION("commutative property")
    {
        constexpr int x = 13;
        constexpr int y = 17;
        CONSTEXPR_BOOST_TEST(x + y == y + x);
        CONSTEXPR_BOOST_TEST(x * y == y * x);
    };
}

BOOST_AUTO_TEST_CASE(boost_test_nontransient_vectors)
{
    CONSTEXPR_SECTION("vector basic initialization and access")
    {
        std::vector nums = { 10, 20, 30, 40, 50 };
        CONSTEXPR_BOOST_TEST(nums.size() == 5);
        CONSTEXPR_BOOST_TEST(nums[0] == 10);
        CONSTEXPR_BOOST_TEST(nums[4] == 50);
        CONSTEXPR_BOOST_TEST(!nums.empty());
    };

    CONSTEXPR_SECTION("vector push_back operations")
    {
        std::vector<int> vec;
        vec.push_back(7);
        vec.push_back(14);
        vec.push_back(21);

        CONSTEXPR_BOOST_TEST(vec.size() == 3);
        CONSTEXPR_BOOST_TEST(vec[1] == 14);
        CONSTEXPR_BOOST_TEST(vec.back() == 21);
    };

    CONSTEXPR_SECTION("vector element modification")
    {
        std::vector data = { 1, 2, 3, 4, 5 };
        data[2] = 100;

        CONSTEXPR_BOOST_TEST(data[2] == 100);
        CONSTEXPR_BOOST_TEST(data.size() == 5);
        CONSTEXPR_BOOST_TEST(data.front() == 1);
    };

    CONSTEXPR_SECTION("vector iteration and sum")
    {
        const std::vector values = { 3, 6, 9, 12 };
        int sum = 0;
        for (const auto& v : values)
        {
            sum += v;
        }

        CONSTEXPR_BOOST_TEST(sum == 30);
        CONSTEXPR_BOOST_TEST(sum > 25);
    };

    CONSTEXPR_SECTION("vector with std::accumulate")
    {
        std::vector sequence = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
        int total = std::accumulate(sequence.begin(), sequence.end(), 0);

        CONSTEXPR_BOOST_TEST(total == 55);
        CONSTEXPR_BOOST_TEST(total == sequence.size() * 5.5);
    };
}

BOOST_AUTO_TEST_CASE(boost_test_nontransient_strings)
{
    CONSTEXPR_SECTION("string initialization and size")
    {
        const std::string text = "example";
        CONSTEXPR_BOOST_TEST(text.size() == 7);
        CONSTEXPR_BOOST_TEST(text.length() == 7);
        CONSTEXPR_BOOST_TEST(!text.empty());
    };

    CONSTEXPR_SECTION("string concatenation")
    {
        const std::string first = "Hello";
        const std::string second = "World";
        std::string combined = first + " " + second;

        CONSTEXPR_BOOST_TEST(combined.size() == 11);
        CONSTEXPR_BOOST_TEST(combined[0] == 'H');
        CONSTEXPR_BOOST_TEST(combined[6] == 'W');
    };

    CONSTEXPR_SECTION("string equality checks")
    {
        std::string str1 = "boost";
        std::string str2 = "boost";
        std::string str3 = "test";

        CONSTEXPR_BOOST_TEST(str1 == str2);
        CONSTEXPR_BOOST_TEST(str1 != str3);
        CONSTEXPR_BOOST_TEST(str1.size() == str2.size());
    };

    CONSTEXPR_SECTION("string append operations")
    {
        std::string str = "foo";
        str += "bar";

        CONSTEXPR_BOOST_TEST(str.size() == 6);
        CONSTEXPR_BOOST_TEST(str[3] == 'b');

        str.push_back('!');
        CONSTEXPR_BOOST_TEST(str.size() == 7);
        CONSTEXPR_BOOST_TEST(str.back() == '!');
    };
}

BOOST_AUTO_TEST_CASE(boost_test_nontransient_algorithms)
{
    CONSTEXPR_SECTION("std::find element search")
    {
        std::vector container = { 5, 10, 15, 20, 25 };
        const auto it = std::ranges::find(container, 15);

        CONSTEXPR_BOOST_TEST((it != container.end()));
        CONSTEXPR_BOOST_TEST(*it == 15);
        CONSTEXPR_BOOST_TEST(std::distance(container.begin(), it) == 2);
    };

    CONSTEXPR_SECTION("std::count occurrences")
    {
        std::vector list = { 2, 5, 2, 8, 2, 10, 2 };
        const auto count = std::ranges::count(list, 2);

        CONSTEXPR_BOOST_TEST(count == 4);
        CONSTEXPR_BOOST_TEST(count > 3);
    };

    CONSTEXPR_SECTION("std::sort ordering")
    {
        std::vector unsorted = { 7, 3, 9, 1, 5 };
        std::ranges::sort(unsorted);

        CONSTEXPR_BOOST_TEST(unsorted[0] == 1);
        CONSTEXPR_BOOST_TEST(unsorted[4] == 9);
        CONSTEXPR_BOOST_TEST(unsorted[1] < unsorted[2]);
    };

    CONSTEXPR_SECTION("std::reverse order flip")
    {
        std::vector vec = { 1, 2, 3, 4, 5 };
        std::ranges::reverse(vec);

        CONSTEXPR_BOOST_TEST(vec[0] == 5);
        CONSTEXPR_BOOST_TEST(vec[4] == 1);
        CONSTEXPR_BOOST_TEST(vec.front() == 5);
    };

    CONSTEXPR_SECTION("std::max_element and std::min_element")
    {
        std::vector numbers = { 12, 45, 7, 23, 67, 34 };
        const auto max_it = std::ranges::max_element(numbers);
        const auto min_it = std::ranges::min_element(numbers);

        CONSTEXPR_BOOST_TEST(*max_it == 67);
        CONSTEXPR_BOOST_TEST(*min_it == 7);
        CONSTEXPR_BOOST_TEST(*max_it > *min_it);
    };
}

BOOST_AUTO_TEST_CASE(boost_test_nontransient_complex)
{
    CONSTEXPR_SECTION("vector of strings")
    {
        std::vector<std::string> words = { "one", "two", "three" };

        CONSTEXPR_BOOST_TEST(words.size() == 3);
        CONSTEXPR_BOOST_TEST(words[1] == "two");

        words.emplace_back("four");
        CONSTEXPR_BOOST_TEST(words.size() == 4);

        size_t total_length = 0;
        for (const auto& word : words)
        {
            total_length += word.length();
        }
        CONSTEXPR_BOOST_TEST(total_length == 15);
    };

    CONSTEXPR_SECTION("nested vector matrix")
    {
        std::vector<std::vector<int>> matrix = {
            { 1, 2, 3 },
            { 4, 5, 6 },
            { 7, 8, 9 }
        };

        CONSTEXPR_BOOST_TEST(matrix.size() == 3);
        CONSTEXPR_BOOST_TEST(matrix[0].size() == 3);
        CONSTEXPR_BOOST_TEST(matrix[1][1] == 5);

        int sum = 0;
        for (const auto& row : matrix)
        {
            for (const auto& val : row)
            {
                sum += val;
            }
        }
        CONSTEXPR_BOOST_TEST(sum == 45);
    };

    CONSTEXPR_SECTION("vector concatenation with insert")
    {
        std::vector v1 = { 10, 20, 30 };
        std::vector v2 = { 40, 50, 60 };

        v1.insert(v1.end(), v2.begin(), v2.end());

        CONSTEXPR_BOOST_TEST(v1.size() == 6);
        CONSTEXPR_BOOST_TEST(v1[3] == 40);
        CONSTEXPR_BOOST_TEST(v1[5] == 60);

        int total = std::accumulate(v1.begin(), v1.end(), 0);
        CONSTEXPR_BOOST_TEST(total == 210);
    };
}
