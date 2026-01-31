# Catch2 tests
CPMAddPackage("gh:catchorg/Catch2@3.5.2")

add_executable(catch2_tests test_catch2.cpp test_catch2_macros.cpp)
target_compile_definitions(catch2_tests PRIVATE CONSTEST_CONFIG_CATCH2)
target_compile_options(catch2_tests PRIVATE ${TEST_WARNING_FLAGS})
target_link_libraries(catch2_tests PRIVATE constest Catch2::Catch2WithMain)

add_test(NAME catch2_tests COMMAND catch2_tests)

# Negative tests: ensure files fail to compile with expected errors
include(${CMAKE_SOURCE_DIR}/tests/common/AddNegativeTests.cmake)

add_negative_tests(
        NEGATIVE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/negative"
        PREFIX "catch2_negative"
        EXPECT_ERRORS "macros_used_outside_section:This macro should be used inside a CONSTEXPR_SECTION"
        LINK_LIBRARIES constest Catch2::Catch2WithMain
        COMPILE_DEFINITIONS CONSTEST_CONFIG_CATCH2
)
