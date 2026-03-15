# Tests

# Aggressive warning flags for all test targets
set(TEST_WARNING_FLAGS
        # GCC and Clang
        $<$<OR:$<CXX_COMPILER_ID:GNU>,$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>>:
        -Wall
        -Wextra
        -Wpedantic
        -Werror
        -Wconversion
        -Wsign-conversion
        -Wcast-align
        -Wcast-qual
        -Wformat=2
        -Wunused
        -Wnull-dereference
        -Wdouble-promotion
        -Wshadow
        -Wfloat-equal
        >
        # Clang-specific
        $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>>:
        "-Wno-#warnings"
        >
        # GCC-specific
        $<$<CXX_COMPILER_ID:GNU>:
        -Wlogical-op
        -Wduplicated-cond
        -Wduplicated-branches
        >
        # MSVC
        $<$<CXX_COMPILER_ID:MSVC>:
        /W4
        /WX
        /permissive-
        /w14242
        /w14254
        /w14263
        /w14265
        /w14287
        /we4289
        /w14296
        /w14311
        /w14545
        /w14546
        /w14547
        /w14549
        /w14555
        /w14619
        /w14640
        /w14826
        /w14905
        /w14906
        /w14928
        >
)

# Mark dependency directories as SYSTEM to suppress warnings
add_subdirectory(catch2 SYSTEM)
add_subdirectory(gtest SYSTEM)
add_subdirectory(doctest SYSTEM)
add_subdirectory(boost_test SYSTEM)

if (CONSTEST_RUN_BENCHMARKS)
    add_subdirectory(benchmarks)
endif ()