#!/usr/bin/env python3
"""Test that a C++ file fails to compile with expected errors."""

import argparse
import subprocess
from pathlib import Path


def expect_compilation_failed(cmake_result: subprocess.CompletedProcess):
    assert cmake_result.returncode != 0, "[ FAILED ] Expected compilation to fail, but it succeeded"
    print(f"[   OK   ] Compilation failed as expected")


def expect_output_contains(cmake_result: subprocess.CompletedProcess, expect_in_output: str | None):
    output = cmake_result.stdout + cmake_result.stderr
    if expect_in_output:
        assert expect_in_output in output, f"[ FAILED ] Expected string '{expect_in_output}' not found in compiler output"
        print(f"[   OK   ] Found expected string: '{expect_in_output}'")
    else:
        print(f"[  SKIP  ] No expected string provided, skipping output check")


def expect_number_of_errors(cmake_result: subprocess.CompletedProcess, cpp_file: Path):
    compilation_error_marker = "// Should fail here"
    source_content = cpp_file.read_text()
    expected_count = source_content.count(compilation_error_marker)
    output = cmake_result.stdout + cmake_result.stderr
    actual_count = output.count(compilation_error_marker)
    assert actual_count == expected_count, f"[ FAILED ] All failing lines have not been reported in the output of the compiler (expected {expected_count}, got {actual_count})"
    print(f"[   OK   ] All failing lines have been reported in the output of the compiler (expected {expected_count})")


def test_compile_fails(cpp_file: Path, expect_in_output: str | None, cmake_args: list[str]):
    cmake_result = subprocess.run(["cmake"] + cmake_args, capture_output=True, text=True)
    expect_compilation_failed(cmake_result)
    expect_output_contains(cmake_result, expect_in_output)
    expect_number_of_errors(cmake_result, cpp_file)


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Test that a C++ file fails to compile with expected errors")
    parser.add_argument("--cpp-file", required=True, type=Path, help="Path to the C++ file to test")
    parser.add_argument("--expect-in-output", default=None, help="String that must be present in compiler output")

    args, unknown_args = parser.parse_known_args()

    test_compile_fails(args.cpp_file, args.expect_in_output, unknown_args)
