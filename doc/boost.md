# ConsTest with Boost.Test

## Configuration

To use ConsTest with Boost.Test, you need to `#define` the `CONSTEST_CONFIG_BOOST_TEST` macro.

CMakeLists.txt:

```cmake
target_compile_definitions(your_target PRIVATE CONSTEST_CONFIG_BOOST_TEST)
```

## Usage

```C++
#include <constest.hpp>

BOOST_AUTO_TEST_CASE(boost_test_basic_arithmetic)
{
    CONSTEXPR_SECTION("simple addition and subtraction")
    {
        CONSTEXPR_BOOST_TEST(2 + 2 == 4);
        CONSTEXPR_BOOST_TEST(10 - 3 == 7);
        CONSTEXPR_BOOST_TEST(5 + 5 == 10);
        CONSTEXPR_BOOST_TEST(100 - 25 == 75);
    }; // <-- Don't forget the semicolon! 
}
```

[See a more complete example](../tests/boost_test/test_boost.cpp)

## `CONSTEXPR_SECTION` macro

At runtime, the `CONSTEXPR_SECTION` will be transformed into a `BOOST_TEST_CONTEXT` with the same description prefixed
by `[Passed at compile-time] `. The whole content of the `CONSTEXPR_SECTION` will be executed at runtime as well.

## Assertion macros

| ConsTest Macro         | Boost.Test equivalent      | Runtime call |
|------------------------|----------------------------|--------------|
| `CONSTEXPR_BOOST_TEST` | `BOOST_TEST`<sup>[1]</sup> | `BOOST_TEST` |

<sup>[1]</sup> Despite `BOOST_TEST` accepts several arguments, `CONSTEXPR_BOOST_TEST` only accepts a single argument.

> [!IMPORTANT]
> Using `CONSTEXPR_BOOST_TEST` outside a `CONSTEXPR_SECTION` will result in a compile-time error because this would
> be pointless.
>
> `BOOST_TEST` should not be used inside a `CONSTEXPR_SECTION` because it cannot be evaluated at compile-time. Doing so
> will result in a compile-time error, even if the assertion is true.

## Debugging a failing `CONSTEXPR_SECTION`

To debug a failing `CONSTEXPR_SECTION`, you can replace it with a `CONSTEXPR_SECTION_DEBUG` so that its content won't be
evaluated at compile-time but only at runtime.

```C++
BOOST_AUTO_TEST_CASE(boost_test_basic_arithmetic)
{
    CONSTEXPR_SECTION_DEBUG("simple addition and subtraction")
    {
        CONSTEXPR_BOOST_TEST(2 + 2 == 4);
        CONSTEXPR_BOOST_TEST(10 - 3 == 7);
        CONSTEXPR_BOOST_TEST(5 + 5 == 10);
        CONSTEXPR_BOOST_TEST(100 - 25 == 75);
    }; 
}
```

> [!WARNING]
> You should not keep `CONSTEXPR_SECTION_DEBUG` in production code, this should be used only for debugging purposes.

At runtime, the `CONSTEXPR_SECTION_DEBUG` will be transformed into a `BOOST_TEST_CONTEXT` with the same description
prefixed
by `[WARNING - Debugging a CONSTEXPR_SECTION] `.

## Supported Boost.Test versions

Any version of Boost.Test supporting the macros above should work.
However, it has only been tested with the following versions:

- ✅ 1.90.0
- ✅ 1.86.0
- ✅ 1.85.0
- ✅ 1.84.0
- ✅ 1.83.0
- ✅ 1.81.0