# Boost.Test benchmark builds
# Reuse the Boost package from the regular tests (already included)
if (NOT TARGET Boost::unit_test_framework)
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
endif ()

# Build with constest
add_executable(boost_test_bench_constest
        ${CMAKE_SOURCE_DIR}/tests/boost_test/test_boost.cpp
)
target_compile_definitions(boost_test_bench_constest PRIVATE CONSTEST_CONFIG_BOOST_TEST)
target_link_libraries(boost_test_bench_constest PRIVATE constest Boost::unit_test_framework)

# Build with base framework (CONSTEXPR_SECTION as nothing, others as base macros)
add_executable(boost_test_bench_base
        ${CMAKE_SOURCE_DIR}/tests/boost_test/test_boost.cpp
)
# Add base_macros to include path BEFORE system includes so stub headers are found
target_include_directories(boost_test_bench_base BEFORE PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../base_macros)
target_compile_options(boost_test_bench_base PRIVATE
        -include${CMAKE_CURRENT_SOURCE_DIR}/../base_macros/boost_test_base_macros.hpp
)
target_link_libraries(boost_test_bench_base PRIVATE Boost::unit_test_framework)
