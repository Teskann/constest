# Google Test
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

add_executable(gtest_tests test_gtest.cpp test_gtest_macros.cpp ${GTEST_MAIN_SRC})
target_compile_definitions(gtest_tests PRIVATE CONSTEST_CONFIG_GTEST)
target_compile_options(gtest_tests PRIVATE ${TEST_WARNING_FLAGS})
target_link_libraries(gtest_tests PRIVATE constest ${GTEST_LINK_LIBS})

add_test(NAME gtest_tests COMMAND gtest_tests)

# Negative tests: ensure files fail to compile with expected errors
include(${CMAKE_SOURCE_DIR}/tests/common/AddNegativeTests.cmake)

add_negative_tests(
        NEGATIVE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/negative"
        PREFIX "gtest_negative"
        EXPECT_ERRORS "macros_used_outside_section:This macro should be used inside a CONSTEXPR_SECTION"
        LINK_LIBRARIES constest ${GTEST_LINK_LIBS}
        COMPILE_DEFINITIONS CONSTEST_CONFIG_GTEST
        EXTRA_SOURCES ${GTEST_MAIN_SRC}
)
