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
