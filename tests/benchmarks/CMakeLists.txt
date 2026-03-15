# Benchmark builds for comparing constest vs base frameworks
# Each framework builds two versions:
# 1. *_bench_constest: Uses constest library
# 2. *_bench_base: Uses base framework macros (CONSTEXPR_SECTION as nothing, others as base)

add_subdirectory(catch2)
add_subdirectory(gtest)
add_subdirectory(doctest)
add_subdirectory(boost_test)
