cmake_minimum_required(VERSION 3.14)
set(CMAKE_POLICY_VERSION_MINIMUM 3.5)
project(constest)

# Header-only library
add_library(constest INTERFACE)
target_include_directories(constest INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/constest>
        $<INSTALL_INTERFACE:constest>
)

if (PROJECT_IS_TOP_LEVEL)
    if (NOT DEFINED CMAKE_CXX_STANDARD)
        set(CMAKE_CXX_STANDARD 20)
    endif ()

    include(cmake/CPM.cmake)
    enable_testing()
    add_subdirectory(tests)
endif ()