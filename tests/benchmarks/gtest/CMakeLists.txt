# Google Test benchmark builds
# Reuse googletest if already loaded, otherwise load it
if (NOT TARGET gtest AND NOT TARGET GTest::gtest)
    set(CONSTEST_GTEST_VERSION "1.17.0" CACHE STRING "Version of Google Test to use")

    if (CONSTEST_GTEST_VERSION VERSION_LESS_EQUAL "1.12.1")
        set(GTEST_TAG_PREFIX "release-")
    else ()
        set(GTEST_TAG_PREFIX "v")
    endif ()

    if (MSVC)
        set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    endif ()

    CPMAddPackage(
            NAME googletest
            GITHUB_REPOSITORY google/googletest
            GIT_TAG ${GTEST_TAG_PREFIX}${CONSTEST_GTEST_VERSION}
    )
endif ()

# Determine which GTest library to use
if (TARGET GTest::gtest_main)
    set(GTEST_LINK_LIBS GTest::gtest_main)
    set(GTEST_HAS_MAIN TRUE)
elseif (TARGET gtest_main)
    set(GTEST_LINK_LIBS gtest_main gtest)
    set(GTEST_HAS_MAIN TRUE)
elseif (TARGET GTest::gtest)
    set(GTEST_LINK_LIBS GTest::gtest)
    set(GTEST_HAS_MAIN FALSE)
else ()
    set(GTEST_LINK_LIBS gtest)
    set(GTEST_HAS_MAIN FALSE)
endif ()

# If no main is available, create a simple main file
if (NOT GTEST_HAS_MAIN)
    file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/gtest_main.cpp
            "#include <gtest/gtest.h>\nint main(int argc, char** argv) {\n  ::testing::InitGoogleTest(&argc, argv);\n  return RUN_ALL_TESTS();\n}\n")
    set(GTEST_MAIN_SRC ${CMAKE_CURRENT_BINARY_DIR}/gtest_main.cpp)
endif ()

# Build with constest
add_executable(gtest_bench_constest
        ${CMAKE_SOURCE_DIR}/tests/gtest/test_gtest.cpp
        ${GTEST_MAIN_SRC}
)
target_compile_definitions(gtest_bench_constest PRIVATE CONSTEST_CONFIG_GTEST)
target_link_libraries(gtest_bench_constest PRIVATE constest ${GTEST_LINK_LIBS})

# Build with base framework (CONSTEXPR_SECTION as nothing, others as base macros)
add_executable(gtest_bench_base
        ${CMAKE_SOURCE_DIR}/tests/gtest/test_gtest.cpp
        ${GTEST_MAIN_SRC}
)
# Add base_macros to include path BEFORE system includes so stub headers are found
target_include_directories(gtest_bench_base BEFORE PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../base_macros)
target_compile_options(gtest_bench_base PRIVATE
        -include${CMAKE_CURRENT_SOURCE_DIR}/../base_macros/gtest_base_macros.hpp
)
target_link_libraries(gtest_bench_base PRIVATE ${GTEST_LINK_LIBS})
