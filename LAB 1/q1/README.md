📘 Detailed Problem Breakdown

Problem 1: 

Put Them in Order (Asymptotic Growth)

Core Technique: Structural Data Binding, Numerical Evaluation, and Quick Sort (qsort).

Explanation: This program calculates the exact numerical values of 12 distinct mathematical functions at a controlled evaluation threshold (n = 1000). To handle massive values like 3¹⁰⁰⁰ without crashing the runtime environment, the code wraps parameters into high-precision double floating-point containers. It uses C’s native library qsort() combined with a custom safe-difference comparator callback (diff > 0) - (diff < 0) to securely sequence the functions in ascending order of their growth rate.

The Functions (From Slowest to Fastest Growing)

Through asymptotic analysis (Big-O notation) and empirical data generation, the functions are ordered as follows:

log2(n) (Logarithmic - Most Efficient)

12√n & 50n^0.5 (Square Root / Tied)

n^0.51 (Fractional Polynomial)

2^32 * n (Linear - Massive constant, but scales linearly)

n * log2(n) (Linearithmic)

100n^2 + 6n & n^2 - 324 (Quadratic / Tied)

2n^3 (Cubic)

n^log2(n) (Quasi-polynomial)

3^n (Exponential - Least Efficient)


