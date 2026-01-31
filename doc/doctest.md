# ConsTest with Doctest

## Configuration

To use ConsTest with Doctest, you need to `#define` the `CONSTEST_CONFIG_DOCTEST` macro.

CMakeLists.txt:

```cmake
target_compile_definitions(your_target PRIVATE CONSTEST_CONFIG_DOCTEST)
```

## Usage

```C++
#include <constest.hpp>

TEST_CASE("Doctest")
{
    CONSTEXPR_SECTION("basic arithmetic expressions")
    {
        CONSTEXPR_REQUIRE(2 + 2 == 4);
        CONSTEXPR_CHECK(15 - 7 == 8);
        CONSTEXPR_REQUIRE_FALSE(6 * 7 != 42);
        CONSTEXPR_CHECK_FALSE(144 / 12 != 12);
    }; // <-- Don't forget the semicolon!
}
```

[See a more complete example](../tests/doctest/test_doctest.cpp)

## `CONSTEXPR_SECTION` macro

At runtime, the `CONSTEXPR_SECTION` will be transformed into a `SUBCASE` with the same description prefixed
by `[Passed at compile-time] `. The whole content of the `CONSTEXPR_SECTION` will be executed at runtime as well.

## Assertion macros

| ConsTest Macro            | doctest equivalent | Runtime call    |
|---------------------------|--------------------|-----------------|
| `CONSTEXPR_REQUIRE`       | `REQUIRE`          | `REQUIRE`       |
| `CONSTEXPR_REQUIRE_FALSE` | `REQUIRE_FALSE`    | `REQUIRE_FALSE` |
| `CONSTEXPR_CHECK`         | `CHECK`            | `CHECK`         |
| `CONSTEXPR_CHECK_FALSE`   | `CHECK_FALSE`      | `CHECK_FALSE`   |

> [!NOTE]
> There is no concept of non-fatal assertions in ConsTest, as they prevent compilation. `REQUIRE`/`CHECK`
> macros are equivalent at compile-time.

> [!IMPORTANT]
> Using these macros outside a `CONSTEXPR_SECTION` will result in a compile-time error because this would
> be pointless.
>
> Doctest's standard macros (`REQUIRE`, `CHECK`, etc.) should not be used inside a `CONSTEXPR_SECTION` because they
> cannot be evaluated at compile-time. Doing so
> will result in a compile-time error, even if the assertion is true.

## Debugging a failing `CONSTEXPR_SECTION`

To debug a failing `CONSTEXPR_SECTION`, you can replace it with a `CONSTEXPR_SECTION_DEBUG` so that its content won't be
evaluated at compile-time but only at runtime.

```C++
TEST_CASE("doctest CONSTEXPR_REQUIRE tests")
{
    CONSTEXPR_SECTION_DEBUG("basic arithmetic expressions")
    {
        CONSTEXPR_REQUIRE(2 + 2 == 4);
        CONSTEXPR_REQUIRE(15 - 7 == 8);
        CONSTEXPR_REQUIRE(6 * 7 == 42);
        CONSTEXPR_REQUIRE(144 / 12 == 12);
    };
}
```

> [!WARNING]
> You should not keep `CONSTEXPR_SECTION_DEBUG` in production code, this should be used only for debugging purposes.

At runtime, the `CONSTEXPR_SECTION_DEBUG` will be transformed into a `SUBCASE` with the same description
prefixed
by `[WARNING - Debugging a CONSTEXPR_SECTION] `.

## Supported doctest versions

Any version of doctest supporting the macros above should work.
However, it has only been tested with the following versions:

- ✅ 2.4.12
- ✅ 2.4.11
- ✅ 2.4.10
- ✅ 2.4.9
- ✅ 2.4.8
- ✅ 2.4.6
