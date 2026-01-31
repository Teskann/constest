# doctest
CPMAddPackage("gh:doctest/doctest@2.4.11")

add_executable(doctest_tests test_doctest.cpp test_doctest_macros.cpp)
target_compile_definitions(doctest_tests PRIVATE CONSTEST_CONFIG_DOCTEST)
target_compile_options(doctest_tests PRIVATE ${TEST_WARNING_FLAGS})
target_link_libraries(doctest_tests PRIVATE constest doctest::doctest)

add_test(NAME doctest_tests COMMAND doctest_tests)

# Negative tests: ensure files fail to compile with expected errors
include(${CMAKE_SOURCE_DIR}/tests/common/AddNegativeTests.cmake)

add_negative_tests(
        NEGATIVE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/negative"
        PREFIX "doctest_negative"
        EXPECT_ERRORS "macros_used_outside_section:This macro should be used inside a CONSTEXPR_SECTION"
        LINK_LIBRARIES constest doctest::doctest
        COMPILE_DEFINITIONS CONSTEST_CONFIG_DOCTEST
)
