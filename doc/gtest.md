# ConsTest with Google Test

## Configuration

To use ConsTest with Google Test, you need to `#define` the `CONSTEST_CONFIG_GTEST` macro.

CMakeLists.txt:

```cmake
target_compile_definitions(your_target PRIVATE CONSTEST_CONFIG_GTEST)
```

## Usage

```C++
#include <constest.hpp>

TEST(GTest_example, basic)
{
    CONSTEXPR_SECTION("basic equality with arithmetic expressions")
    {
        CONSTEXPR_EXPECT_EQ(2 + 2, 4);
        CONSTEXPR_EXPECT_EQ(10 * 5 - 3, 47);
        CONSTEXPR_EXPECT_EQ(100 / 4, 25);
        CONSTEXPR_ASSERT_EQ(fibonacci(10), 55);
    }; // <-- Don't forget the semicolon!
}
```

[See a more complete example](../tests/gtest/test_gtest.cpp)

## `CONSTEXPR_SECTION` macro

The whole content of the `CONSTEXPR_SECTION` will be executed at runtime as well.

## Assertion macros

| ConsTest Macro           | Google Test equivalent | Runtime call   |
|--------------------------|------------------------|----------------|
| `CONSTEXPR_EXPECT_EQ`    | `EXPECT_EQ`            | `EXPECT_EQ`    |
| `CONSTEXPR_EXPECT_NE`    | `EXPECT_NE`            | `EXPECT_NE`    |
| `CONSTEXPR_EXPECT_LT`    | `EXPECT_LT`            | `EXPECT_LT`    |
| `CONSTEXPR_EXPECT_LE`    | `EXPECT_LE`            | `EXPECT_LE`    |
| `CONSTEXPR_EXPECT_GT`    | `EXPECT_GT`            | `EXPECT_GT`    |
| `CONSTEXPR_EXPECT_GE`    | `EXPECT_GE`            | `EXPECT_GE`    |
| `CONSTEXPR_EXPECT_TRUE`  | `EXPECT_TRUE`          | `EXPECT_TRUE`  |
| `CONSTEXPR_EXPECT_FALSE` | `EXPECT_FALSE`         | `EXPECT_FALSE` |
| `CONSTEXPR_ASSERT_EQ`    | `ASSERT_EQ`            | `ASSERT_EQ`    |
| `CONSTEXPR_ASSERT_NE`    | `ASSERT_NE`            | `ASSERT_NE`    |
| `CONSTEXPR_ASSERT_LT`    | `ASSERT_LT`            | `ASSERT_LT`    |
| `CONSTEXPR_ASSERT_LE`    | `ASSERT_LE`            | `ASSERT_LE`    |
| `CONSTEXPR_ASSERT_GT`    | `ASSERT_GT`            | `ASSERT_GT`    |
| `CONSTEXPR_ASSERT_GE`    | `ASSERT_GE`            | `ASSERT_GE`    |
| `CONSTEXPR_ASSERT_TRUE`  | `ASSERT_TRUE`          | `ASSERT_TRUE`  |
| `CONSTEXPR_ASSERT_FALSE` | `ASSERT_FALSE`         | `ASSERT_FALSE` |

> [!NOTE]
> There is no concept of non-fatal assertions in ConsTest, as they prevent compilation. `ASSERT`/`EXPECT`
> macros are equivalent at compile-time.

> [!IMPORTANT]
> Using these macros outside a `CONSTEXPR_SECTION` will result in a compile-time error because this would
> be pointless.
>
> Google Test's standard macros (`EXPECT_*`, `ASSERT_*`) should not be used inside a `CONSTEXPR_SECTION` because they
> cannot be evaluated at compile-time. Doing so
> will result in a compile-time error, even if the assertion is true.

## Debugging a failing `CONSTEXPR_SECTION`

To debug a failing `CONSTEXPR_SECTION`, you can replace it with a `CONSTEXPR_SECTION_DEBUG` so that its content won't be
evaluated at compile-time but only at runtime.

```C++
TEST(GTestConstexpr, EqualityComparisons)
{
    CONSTEXPR_SECTION_DEBUG("basic equality with arithmetic expressions")
    {
        CONSTEXPR_EXPECT_EQ(2 + 2, 4);
        CONSTEXPR_EXPECT_EQ(10 * 5 - 3, 47);
        CONSTEXPR_EXPECT_EQ(100 / 4, 25);
        CONSTEXPR_ASSERT_EQ(fibonacci(10), 55);
    };
}
```

> [!WARNING]
> You should not keep `CONSTEXPR_SECTION_DEBUG` in production code, this should be used only for debugging purposes.

## Supported Google Test versions

Any version of Google Test supporting the macros above should work.
However, it has only been tested with the following versions:

- ✅ 1.17.0
- ✅ 1.14.0
- ✅ 1.13.0
- ✅ 1.12.1
- ✅ 1.11.0
- ✅ 1.8.1
