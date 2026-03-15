#!/usr/bin/env python3
"""
Plot benchmark results from CSV file.
"""

import csv
from pathlib import Path
import matplotlib.pyplot as plt
import numpy as np


def pretty_framework(framework: str) -> str:
    return {"catch2": "Catch2",
            "doctest": "Doctest",
            "gtest": "Google Test",
            "boost_test": "Boost.Test"}[framework]


def plot_benchmarks(csv_file: Path):
    """Read CSV and create comparison charts."""

    # Read data
    frameworks = []
    compile_constest = []
    compile_constest_err = []
    compile_base_err = []
    runtime_constest = []
    runtime_constest_err = []
    runtime_base_err = []

    with open(csv_file, 'r') as f:
        reader = csv.DictReader(f)
        for row in reader:
            if row['variant'] == 'constest':
                frameworks.append(row['framework'])
                compile_constest.append(float(row['compile_time_normalized']))
                compile_constest_err.append(float(row['compile_time_stddev_normalized']))
                runtime_constest.append(float(row['runtime_normalized']))
                runtime_constest_err.append(float(row['runtime_stddev_normalized']))
            elif row['variant'] == 'base':
                compile_base_err.append(float(row['compile_time_stddev_normalized']))
                runtime_base_err.append(float(row['runtime_stddev_normalized']))

    # Create figure with two subplots
    fig, (ax1, ax2) = plt.subplots(1, 2, figsize=(14, 6))

    x = np.arange(len(frameworks))
    width = 0.35

    # Compile time comparison
    ax1.bar(x, compile_constest, width, yerr=compile_constest_err,
            label='ConsTest', capsize=5, alpha=0.8, color='#2ecc71')
    ax1.axhline(y=1.0, color='gray', linestyle='--', linewidth=1, label='Base (without ConsTest)')
    # Plot base error bars
    ax1.errorbar(x, [1.0] * len(frameworks), yerr=compile_base_err,
                 fmt='none', ecolor='gray', capsize=5, alpha=0.6)
    ax1.set_ylabel('Normalized Compile Time')
    ax1.set_title('Compile Time Overhead')
    ax1.set_xticks(x)
    ax1.set_xticklabels([pretty_framework(x) for x in frameworks])
    ax1.legend()
    ax1.grid(axis='y', alpha=0.3)

    # Runtime comparison
    ax2.bar(x, runtime_constest, width, yerr=runtime_constest_err,
            label='ConsTest', capsize=5, alpha=0.8, color='#3498db')
    ax2.axhline(y=1.0, color='gray', linestyle='--', linewidth=1, label='Base (without ConsTest)')
    # Plot base error bars
    ax2.errorbar(x, [1.0] * len(frameworks), yerr=runtime_base_err,
                 fmt='none', ecolor='gray', capsize=5, alpha=0.6)
    ax2.set_ylabel('Normalized Runtime')
    ax2.set_title('Runtime Overhead')
    ax2.set_xticks(x)
    ax2.set_xticklabels([pretty_framework(x) for x in frameworks])
    ax2.legend()
    ax2.grid(axis='y', alpha=0.3)

    plt.tight_layout()

    # Save figure
    output_file = csv_file.parent / "benchmark_results.png"
    plt.savefig(output_file, dpi=300, bbox_inches='tight')
    print(f"Chart saved to: {output_file}")


if __name__ == "__main__":
    script_dir = Path(__file__).parent
    csv_file = script_dir / "benchmark_results.csv"

    if not csv_file.exists():
        print(f"Error: CSV file not found: {csv_file}")
        print("Please run benchmark.py first to generate the data.")
    else:
        plot_benchmarks(csv_file)
