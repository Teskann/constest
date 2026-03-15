# Catch2 benchmark builds
# Reuse Catch2 if already loaded, otherwise load it
if (NOT TARGET Catch2::Catch2WithMain)
    set(CONSTEST_CATCH2_VERSION "3.12.0" CACHE STRING "Version of Catch2 to use")
    CPMAddPackage("gh:catchorg/Catch2@${CONSTEST_CATCH2_VERSION}")
endif ()

# Build with constest
add_executable(catch2_bench_constest
        ${CMAKE_SOURCE_DIR}/tests/catch2/test_catch2.cpp
)
target_compile_definitions(catch2_bench_constest PRIVATE CONSTEST_CONFIG_CATCH2)
target_link_libraries(catch2_bench_constest PRIVATE constest Catch2::Catch2WithMain)

# Build with base framework (CONSTEXPR_SECTION as nothing, others as base macros)
add_executable(catch2_bench_base
        ${CMAKE_SOURCE_DIR}/tests/catch2/test_catch2.cpp
)
# Add base_macros to include path BEFORE system includes so stub headers are found
target_include_directories(catch2_bench_base BEFORE PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../base_macros)
target_compile_options(catch2_bench_base PRIVATE
        -include${CMAKE_CURRENT_SOURCE_DIR}/../base_macros/catch2_base_macros.hpp
)
target_link_libraries(catch2_bench_base PRIVATE Catch2::Catch2WithMain)
