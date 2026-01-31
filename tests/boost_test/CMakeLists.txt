# Boost.Test
set(CONSTEST_BOOST_VERSION "1.90.0" CACHE STRING "Version of Boost to use")

# Boost >= 1.85.0 requires -cmake suffix
if (CONSTEST_BOOST_VERSION VERSION_GREATER_EQUAL "1.85.0")
    set(BOOST_URL_SUFFIX "-cmake")
else ()
    set(BOOST_URL_SUFFIX "")
endif ()

CPMAddPackage(
        NAME Boost
        VERSION ${CONSTEST_BOOST_VERSION}
        URL https://github.com/boostorg/boost/releases/download/boost-${CONSTEST_BOOST_VERSION}/boost-${CONSTEST_BOOST_VERSION}${BOOST_URL_SUFFIX}.tar.xz
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

