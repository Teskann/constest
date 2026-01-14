cmake_minimum_required(VERSION 3.14)
set(CMAKE_POLICY_VERSION_MINIMUM 3.5)
project(constest)

set(CMAKE_CXX_STANDARD 20)

# Header-only library
add_library(constest INTERFACE)
target_include_directories(constest INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/constest>
        $<INSTALL_INTERFACE:constest>
)

# CPM package manager
include(cmake/CPM.cmake)

# Enable testing
enable_testing()
add_subdirectory(tests)
