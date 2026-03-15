#!/usr/bin/env python3
"""
Benchmark script to compare constest vs base framework performance.
Measures both compile time and runtime for each testing framework.
"""

import subprocess
import time
import csv
import sys
import shutil
from pathlib import Path
from typing import List, Tuple

# Frameworks to benchmark
FRAMEWORKS = ["catch2", "gtest", "doctest", "boost_test"]

# Number of iterations for benchmarks
COMPILE_TIME_ITERATIONS = 50
RUNTIME_ITERATIONS = 1000


def run_command(cmd: List[str], cwd: str = None) -> Tuple[float, bool]:
    """
    Run a command and measure execution time.
    Returns (elapsed_time, success)
    """
    start = time.time()
    try:
        _ = subprocess.run(
            cmd,
            cwd=cwd,
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            check=True
        )
        elapsed = time.time() - start
        return elapsed, True
    except subprocess.CalledProcessError as e:
        elapsed = time.time() - start
        print(f"Command failed: {' '.join(cmd)}")
        print(f"Error: {e.stderr.decode()}")
        return elapsed, False


def setup_build_dir(build_dir: Path, project_root: Path) -> bool:
    """
    Setup CMake build directory for benchmarks.
    """
    print(f"Setting up build directory: {build_dir}")

    # Remove existing build directory
    if build_dir.exists():
        shutil.rmtree(build_dir)

    build_dir.mkdir(parents=True, exist_ok=True)

    # Run CMake configuration from project root
    cmake_cmd = [
        "cmake",
        "-S", str(project_root),
        "-B", str(build_dir),
        "-DCONSTEST_BUILD_TESTS=ON",
        "-DCONSTEST_RUN_BENCHMARKS=ON"
    ]

    elapsed, success = run_command(cmake_cmd)
    if success:
        print(f"CMake configuration completed in {elapsed:.2f}s")
    else:
        print("CMake configuration failed!")

    return success


def build_framework_dependencies(build_dir: Path, framework: str, variant: str) -> bool:
    target = f"{framework}_bench_{variant}"

    print(f"  Pre-building dependencies for {target}...")

    # Build the target once to get all dependencies compiled
    build_cmd = ["cmake", "--build", str(build_dir), "--target", target, "--", "-j"]
    _, success = run_command(build_cmd)

    if not success:
        print(f"  WARNING: Initial build failed for {target}")
        return False

    return True


def benchmark_compile_time(build_dir: Path, framework: str, variant: str, source_files: list) -> Tuple[
    float, float, list]:
    """
    Benchmark compile time for test source files only.
    Assumes dependencies are already built.
    Measures incremental rebuild time by touching source files.
    Runs multiple iterations and returns (mean, stddev, individual_times).
    """
    target = f"{framework}_bench_{variant}"

    print(f"  Benchmarking compile time for {target}...")

    times = []
    for i in range(COMPILE_TIME_ITERATIONS):
        # Touch the source files to force recompilation
        for src_file in source_files:
            if src_file.exists():
                src_file.touch()

        # Build only the test files (framework deps are already built)
        build_cmd = ["cmake", "--build", str(build_dir), "--target", target, "--", "-j1"]
        elapsed, success = run_command(build_cmd)

        if success:
            times.append(elapsed)
        else:
            print(f"  WARNING: Compile iteration {i + 1} failed for {target}")

    if not times:
        return -1.0, 0.0, []

    mean = sum(times) / len(times)
    variance = sum((t - mean) ** 2 for t in times) / len(times)
    stddev = variance ** 0.5

    print(f"  Compile time: {mean:.3f}s ± {stddev:.3f}s ({len(times)} iterations)")
    return mean, stddev, times


def benchmark_runtime(build_dir: Path, framework: str, variant: str) -> Tuple[float, float, list]:
    """
    Benchmark runtime for a specific executable.
    Runs multiple iterations and returns (mean, stddev, individual_times).
    """
    target = f"{framework}_bench_{variant}"
    executable = build_dir / "tests" / "benchmarks" / framework / target

    if not executable.exists():
        print(f"  WARNING: Executable not found: {executable}")
        return -1.0, 0.0, []

    print(f"  Benchmarking runtime for {target}...")

    times = []
    for i in range(RUNTIME_ITERATIONS):
        elapsed, success = run_command([str(executable)])
        if success:
            times.append(elapsed)
        else:
            print(f"  WARNING: Run {i + 1} failed for {target}")

    if not times:
        return -1.0, 0.0, []

    mean = sum(times) / len(times)
    variance = sum((t - mean) ** 2 for t in times) / len(times)
    stddev = variance ** 0.5

    print(f"  Runtime: {mean:.4f}s ± {stddev:.4f}s ({len(times)} runs)")
    return mean, stddev, times


def main():
    # Get project root directory (2 levels up from this script)
    script_dir = Path(__file__).parent
    project_root = script_dir.parent.parent

    print(f"Project root: {project_root}")
    print(f"Benchmarking frameworks: {', '.join(FRAMEWORKS)}")
    print()

    # Define source files for each framework
    framework_sources = {
        "catch2": [
            project_root / "tests/catch2/test_catch2.cpp",
        ],
        "gtest": [
            project_root / "tests/gtest/test_gtest.cpp",
        ],
        "doctest": [
            project_root / "tests/doctest/test_doctest.cpp",
        ],
        "boost_test": [
            project_root / "tests/boost_test/test_boost.cpp",
        ]
    }

    # Setup build directory
    build_dir = project_root / "build_benchmark"
    if not setup_build_dir(build_dir, project_root):
        print("Failed to setup build directory. Exiting.")
        sys.exit(1)

    print()
    print("Pre-building all framework dependencies...")
    print("=" * 80)

    # Pre-build all targets to compile framework dependencies
    for framework in FRAMEWORKS:
        for variant in ["constest", "base"]:
            if not build_framework_dependencies(build_dir, framework, variant):
                print(f"Failed to build dependencies for {framework} {variant}. Skipping.")

    print()
    print("Starting benchmarks (measuring only test file compilation)...")
    print("=" * 80)
    print()

    # Run benchmarks
    results = []

    for framework in FRAMEWORKS:
        print(f"Benchmarking {framework}...")
        source_files = framework_sources[framework]

        for variant in ["constest", "base"]:
            print(f"  Variant: {variant}")

            # Compile time benchmark (only test files)
            compile_time_mean, compile_time_stddev, compile_times = benchmark_compile_time(build_dir, framework,
                                                                                           variant, source_files)

            # Runtime benchmark
            runtime_mean, runtime_stddev, runtime_times = benchmark_runtime(build_dir, framework, variant)

            results.append({
                "framework": framework,
                "variant": variant,
                "compile_time_s": compile_time_mean,
                "compile_time_stddev_s": compile_time_stddev,
                "compile_times": compile_times,
                "runtime_mean_s": runtime_mean,
                "runtime_stddev_s": runtime_stddev,
                "runtime_times": runtime_times
            })

            print()

    # Calculate normalized results (base = 1.0)
    normalized_results = []
    for framework in FRAMEWORKS:
        base_result = next((r for r in results if r['framework'] == framework and r['variant'] == 'base'), None)

        for result in [r for r in results if r['framework'] == framework]:
            # Calculate normalized values (base = 1.0)
            if base_result and base_result['compile_time_s'] > 0 and result['compile_times']:
                # Normalize each individual compile time measurement
                normalized_compile_times = [t / base_result['compile_time_s'] for t in result['compile_times']]
                compile_normalized = sum(normalized_compile_times) / len(normalized_compile_times)
                # Compute standard deviation of normalized values
                compile_variance = sum((t - compile_normalized) ** 2 for t in normalized_compile_times) / len(
                    normalized_compile_times)
                compile_stddev_normalized = compile_variance ** 0.5
            else:
                compile_normalized = -1
                compile_stddev_normalized = 0

            if base_result and base_result['runtime_mean_s'] > 0 and result['runtime_times']:
                # Normalize each individual runtime measurement
                normalized_runtime_times = [t / base_result['runtime_mean_s'] for t in result['runtime_times']]
                runtime_normalized = sum(normalized_runtime_times) / len(normalized_runtime_times)
                # Compute standard deviation of normalized values
                runtime_variance = sum((t - runtime_normalized) ** 2 for t in normalized_runtime_times) / len(
                    normalized_runtime_times)
                runtime_stddev_normalized = runtime_variance ** 0.5
            else:
                runtime_normalized = -1
                runtime_stddev_normalized = 0

            normalized_results.append({
                "framework": result['framework'],
                "variant": result['variant'],
                "compile_time_normalized": compile_normalized,
                "compile_time_stddev_normalized": compile_stddev_normalized,
                "runtime_normalized": runtime_normalized,
                "runtime_stddev_normalized": runtime_stddev_normalized
            })

    # Export results to CSV
    output_file = script_dir / "benchmark_results.csv"
    print(f"Exporting results to {output_file}...")

    with open(output_file, 'w', newline='') as csvfile:
        fieldnames = ["framework", "variant", "compile_time_normalized", "compile_time_stddev_normalized",
                      "runtime_normalized", "runtime_stddev_normalized"]
        writer = csv.DictWriter(csvfile, fieldnames=fieldnames)

        writer.writeheader()
        for result in normalized_results:
            writer.writerow(result)

    print()
    print("=" * 80)
    print("BENCHMARK RESULTS (NORMALIZED - base = 1.0)")
    print("=" * 80)
    print()

    # Print summary table with normalized values only
    print(f"{'Framework':<15} {'Variant':<10} {'Compile Time':<30} {'Runtime':<30}")
    print("-" * 90)
    for result in normalized_results:
        if result['compile_time_normalized'] >= 0:
            compile_norm = f"{result['compile_time_normalized']:.3f}s ± {result['compile_time_stddev_normalized']:.3f}s"
        else:
            compile_norm = "FAILED"

        if result['runtime_normalized'] >= 0:
            runtime_norm = f"{result['runtime_normalized']:.3f}s ± {result['runtime_stddev_normalized']:.3f}s"
        else:
            runtime_norm = "FAILED"

        print(f"{result['framework']:<15} {result['variant']:<10} {compile_norm:<30} {runtime_norm:<30}")

    print()
    print(f"Results saved to: {output_file}")


if __name__ == "__main__":
    main()
