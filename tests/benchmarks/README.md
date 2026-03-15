# ConsTest Benchmarks

Benchmarks comparing ConsTest overhead vs base testing frameworks.

These benchmarks only compile the test files of ConsTest, not a real-world example of test suite.
This stands as a base for ConsTest's compilation overhead. Of course, this will depend a lot on
the functions being tested, because ConsTest evaluates them at compile time.

Results might also depend on the compiler.

## Comparison strategy

The same file is compiled once with ConsTest and once with ConsTest macros redefined to their runtime expansions.

Benchmark results are normalized to that the version without ConsTest has a value of 1.0.

## Running Benchmarks

```bash
python3 benchmark.py
python3 plot_benchmarks.py  # Generate chart (requires matplotlib)
```

## What's Measured

- **Compile time**: Incremental compilation of test files only (50 iterations, framework dependencies excluded)
- **Runtime**: Test execution time (1000 iterations)

Results are normalized with base framework = 1.0, showing relative overhead.

## Customization

Edit `benchmark.py`:

- `COMPILE_TIME_ITERATIONS`: Compile time iterations (default: 50)
- `RUNTIME_ITERATIONS`: Runtime iterations (default: 1000)
- `FRAMEWORKS`: Frameworks to benchmark (default: all)
