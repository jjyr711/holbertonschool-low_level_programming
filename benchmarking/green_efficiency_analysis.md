# Green Tech Efficiency and Benchmarking Analysis

## Measurement Methodology

All benchmarks were executed sequentially on the same machine and software environment to ensure controlled, comparable conditions. Each C program was compiled using strict compiler flags (`gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-long-long`) without optimization overrides so that source-level algorithmic behavior remained directly observable. Timing instrumentation relied on standard `clock()` calls from `<time.h>`, converting raw processor tick differences into seconds via `CLOCKS_PER_SEC` and formatting values to six decimal places. For the baseline loop (`baseline_loop.c`) and algorithm comparison (`comparison_algorithms.c`), three consecutive runs were recorded to capture run-to-run variance and compute arithmetic averages. For the multi-phase workload (`instrumentation_lab.c`), contiguous timestamp boundaries were placed around `build_dataset()`, `process_dataset()`, and `reduce_checksum()` so that individual phase durations summed cleanly within the total measured execution window.

## Observed Performance Differences

In the baseline benchmark executing 100,000,000 deterministic modulo-addition iterations, recorded runtimes were 0.095898 s, 0.095426 s, and 0.093487 s, yielding an average of 0.094937 s with minor scheduling variance across identical runs. In the algorithm comparison over an array of 50,000 integers, both implementations produced the exact same count of 25,000 even elements per pass, yet their runtimes diverged sharply. The quadratic $O(n^2)$ nested-loop implementation (`count_even_naive`) averaged 1.767085 s across three runs (2.026718 s, 1.636624 s, and 1.637914 s), whereas the linear $O(n)$ single-pass implementation (`count_even_single_pass`) averaged 0.000100 s (0.000117 s, 0.000083 s, and 0.000100 s). Consequently, the naive version was approximately 17670.9 times slower than the single-pass approach. In the instrumented multi-phase program, total execution took 0.000363 s, distributed across `BUILD_DATA` (0.000159 s), `PROCESS` (0.000134 s), and `REDUCE` (0.000070 s), showing that data transformation consumed the largest fraction of CPU time.

## Relation Between Runtime and Energy Consumption

Although this experiment does not record electrical power directly in watts, CPU execution time serves as a practical proxy for active compute demand. In `comparison_algorithms.c`, eliminating redundant inner-loop scans reduced average CPU time from 1.767085 s to 0.000100 s for an identical functional result. Keeping processor cores active for roughly 17670.9 times longer forces the hardware to execute millions of unnecessary instructions and memory reads, delaying idle power-state transitions and increasing cumulative energy draw when workloads scale across repeated invocations or large deployments.

## Limitations of the Experiment

Several methodological constraints bound these conclusions. First, `clock()` measures process CPU time rather than actual hardware power draw in watts, voltage scaling, or thermal dissipation. Second, background operating system interrupts, cache state, and frequency scaling introduce small fluctuations, as seen in the slight differences between consecutive baseline runs. Third, tests were restricted to fixed input sizes (50,000 elements) and single-threaded execution without compiler optimization flags, meaning scaling behavior under `-O2` or larger datasets was not directly evaluated.

## Practical Engineering Takeaway

Evidence-based profiling should precede optimization. Developers should first select algorithms with lower asymptotic complexity—replacing $O(n^2)$ scans with $O(n)$ passes—and then use phase-level instrumentation to target genuine bottlenecks, such as the `PROCESS` stage in `instrumentation_lab.c`, achieving measurable reductions in both latency and compute energy footprint.
