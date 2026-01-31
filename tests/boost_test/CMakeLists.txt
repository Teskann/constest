# Boost.Test
CPMAddPackage(
        NAME Boost
        VERSION 1.84.0
        URL https://github.com/boostorg/boost/releases/download/boost-1.84.0/boost-1.84.0.tar.xz
        OPTIONS "BOOST_ENABLE_CMAKE ON" "BOOST_INCLUDE_LIBRARIES test"
)

add_executable(boost_tests test_boost.cpp test_boost_macros.cpp)
target_compile_definitions(boost_tests PRIVATE CONSTEST_CONFIG_BOOST_TEST)
target_link_libraries(boost_tests PRIVATE constest Boost::unit_test_framework)

add_test(NAME boost_tests COMMAND boost_tests)

# Negative tests: ensure files fail to compile with expected errors
include(${CMAKE_SOURCE_DIR}/tests/common/AddNegativeTests.cmake)

add_negative_tests(
        NEGATIVE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/negative"
        PREFIX "boost_test_negative"
        EXPECT_ERRORS "macros_used_outside_section:This macro should be used inside a CONSTEXPR_SECTION"
        LINK_LIBRARIES constest Boost::unit_test_framework
        COMPILE_DEFINITIONS CONSTEST_CONFIG_BOOST_TEST
)

