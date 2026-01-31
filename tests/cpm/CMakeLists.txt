cmake_minimum_required(VERSION 3.14)
project(constest_cpm_test)

set(CMAKE_CXX_STANDARD 23)

include(../../cmake/CPM.cmake)

CPMAddPackage("gh:teskann/constest#cpm")
CPMAddPackage("gh:google/googletest@1.17.0")

add_executable(simple_test test.cpp)
target_link_libraries(simple_test PRIVATE constest gtest_main)
target_compile_definitions(simple_test PRIVATE CONSTEST_CONFIG_GTEST)

enable_testing()
add_test(NAME simple_test COMMAND simple_test)
