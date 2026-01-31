function(_get_test_files NEGATIVE_DIR SOURCES OUT_TEST_FILES)
    if (NEGATIVE_DIR)
        file(GLOB TEST_FILES "${NEGATIVE_DIR}/*.cpp")
    elseif (SOURCES)
        set(TEST_FILES ${SOURCES})
    else ()
        message(FATAL_ERROR "add_negative_tests: Either NEGATIVE_DIR or SOURCES must be specified")
    endif ()

    if (NOT TEST_FILES)
        message(WARNING "add_negative_tests: No test files found")
    endif ()

    set(${OUT_TEST_FILES} ${TEST_FILES} PARENT_SCOPE)
endfunction()

function(_parse_error_map EXPECT_ERRORS)
    foreach (ERROR_SPEC ${EXPECT_ERRORS})
        if (ERROR_SPEC MATCHES "^([^:]+):(.+)$")
            set(ERROR_MAP_${CMAKE_MATCH_1} "${CMAKE_MATCH_2}" PARENT_SCOPE)
        endif ()
    endforeach ()
endfunction()

function(_create_negative_test_target TARGET_NAME TEST_FILE COMPILE_DEFINITIONS LINK_LIBRARIES)
    add_library(${TARGET_NAME} OBJECT EXCLUDE_FROM_ALL ${TEST_FILE})

    if (COMPILE_DEFINITIONS)
        target_compile_definitions(${TARGET_NAME} PRIVATE ${COMPILE_DEFINITIONS})
    endif ()
    if (LINK_LIBRARIES)
        target_link_libraries(${TARGET_NAME} PRIVATE ${LINK_LIBRARIES})
    endif ()
endfunction()

function(_add_compile_fail_test TARGET_NAME TEST_FILE TEST_NAME)
    set(TEST_COMMAND python ${CMAKE_HOME_DIRECTORY}/tests/common/test_compile_fail.py
            --cpp-file ${TEST_FILE}
            --compiler-name ${CMAKE_CXX_COMPILER_ID}
            --build ${CMAKE_BINARY_DIR}
            --target ${TARGET_NAME})

    if (DEFINED ERROR_MAP_${TEST_NAME})
        list(APPEND TEST_COMMAND --expect-in-output "${ERROR_MAP_${TEST_NAME}}")
    endif ()

    add_test(NAME ${TARGET_NAME} COMMAND ${TEST_COMMAND})
endfunction()

function(add_negative_tests)
    set(options "")
    set(oneValueArgs NEGATIVE_DIR PREFIX)
    set(multiValueArgs SOURCES EXPECT_ERRORS LINK_LIBRARIES COMPILE_DEFINITIONS)

    cmake_parse_arguments(ARG "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    if (NOT ARG_PREFIX)
        set(ARG_PREFIX "negative_test")
    endif ()

    _get_test_files("${ARG_NEGATIVE_DIR}" "${ARG_SOURCES}" TEST_FILES)

    if (NOT TEST_FILES)
        return()
    endif ()

    _parse_error_map("${ARG_EXPECT_ERRORS}")

    foreach (TEST_FILE ${TEST_FILES})
        get_filename_component(TEST_NAME ${TEST_FILE} NAME_WE)
        set(TARGET_NAME "${ARG_PREFIX}_${TEST_NAME}")

        _create_negative_test_target(${TARGET_NAME} ${TEST_FILE}
                "${ARG_COMPILE_DEFINITIONS}" "${ARG_LINK_LIBRARIES}")

        _add_compile_fail_test(${TARGET_NAME} ${TEST_FILE} ${TEST_NAME})
    endforeach ()
endfunction()
