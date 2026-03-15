# doctest benchmark builds
# Reuse doctest if already loaded, otherwise load it
if (NOT TARGET doctest::doctest)
    set(CONSTEST_DOCTEST_VERSION "2.4.12" CACHE STRING "Version of doctest to use")
    CPMAddPackage("gh:doctest/doctest@${CONSTEST_DOCTEST_VERSION}")
endif ()

# Build with constest
add_executable(doctest_bench_constest
        ${CMAKE_SOURCE_DIR}/tests/doctest/test_doctest.cpp
)
target_compile_definitions(doctest_bench_constest PRIVATE
        CONSTEST_CONFIG_DOCTEST
)
target_link_libraries(doctest_bench_constest PRIVATE constest doctest::doctest)

# Build with base framework (CONSTEXPR_SECTION as nothing, others as base macros)
add_executable(doctest_bench_base
        ${CMAKE_SOURCE_DIR}/tests/doctest/test_doctest.cpp
)
# Add base_macros to include path BEFORE system includes so stub headers are found
target_include_directories(doctest_bench_base BEFORE PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../base_macros)
target_compile_options(doctest_bench_base PRIVATE
        -include${CMAKE_CURRENT_SOURCE_DIR}/../base_macros/doctest_base_macros.hpp
)
target_link_libraries(doctest_bench_base PRIVATE doctest::doctest)
