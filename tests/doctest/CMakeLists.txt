# doctest
CPMAddPackage("gh:doctest/doctest@2.4.11")

add_executable(doctest_tests test_doctest.cpp test_doctest_macros.cpp)
target_compile_definitions(doctest_tests PRIVATE CONSTEST_CONFIG_DOCTEST)
target_compile_options(doctest_tests PRIVATE ${TEST_WARNING_FLAGS})
target_link_libraries(doctest_tests PRIVATE constest doctest::doctest)

add_test(NAME doctest_tests COMMAND doctest_tests)
