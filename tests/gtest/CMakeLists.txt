# Google Test
CPMAddPackage("gh:google/googletest@1.14.0")

add_executable(gtest_tests test_gtest.cpp test_gtest_macros.cpp)
target_compile_definitions(gtest_tests PRIVATE CONSTEST_CONFIG_GTEST)
target_compile_options(gtest_tests PRIVATE ${TEST_WARNING_FLAGS})
target_link_libraries(gtest_tests PRIVATE constest GTest::gtest_main)

add_test(NAME gtest_tests COMMAND gtest_tests)
