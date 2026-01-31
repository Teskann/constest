# Google Test
CPMAddPackage("gh:google/googletest@1.14.0")

add_executable(gtest_tests test_gtest.cpp test_gtest_macros.cpp)
target_compile_definitions(gtest_tests PRIVATE CONSTEST_CONFIG_GTEST)
target_compile_options(gtest_tests PRIVATE ${TEST_WARNING_FLAGS})
target_link_libraries(gtest_tests PRIVATE constest GTest::gtest_main)

add_test(NAME gtest_tests COMMAND gtest_tests)

# Negative tests: ensure files fail to compile with expected errors
include(${CMAKE_SOURCE_DIR}/tests/common/AddNegativeTests.cmake)

add_negative_tests(
        NEGATIVE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/negative"
        PREFIX "gtest_negative"
        EXPECT_ERRORS "macros_used_outside_section:This macro should be used inside a CONSTEXPR_SECTION"
        LINK_LIBRARIES constest GTest::gtest_main
        COMPILE_DEFINITIONS CONSTEST_CONFIG_GTEST
)
