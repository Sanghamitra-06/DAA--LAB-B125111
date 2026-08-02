## Problem 1: Put Them in Order (Asymptotic Growth)

*   **File Name**: `q1.c`
*   **Compilation Command**: 
    ```bash
    gcc q1.c -o q1 -lm
    ```
*   **Execution Command**: 
    ```bash
    ./q1
    ```

#### 💡 Algorithmic Technique Used
This program focuses on evaluating and sorting a set of 12 distinct mathematical functions according to their **asymptotic growth rates** (Big-O notation). 
*   **High-Precision Numerical Profiling**: Functions like $3^n$ or $n^{\log_2 n}$ scale exponentially and easily overflow standard memory architectures. The code utilizes high-precision `double` floating-point containers to safely evaluate and handle massive limits up to roughly $1.7 \times 10^{308}$.
*   **Structural Binding & Quick Sort (`qsort`)**: To automate ordering, each function's string formula is structurally tied to its calculated numerical value in a custom `Func` array. The complete set is then organized using C's native quicksort algorithm (`qsort()`).
*   **Safe Comparison Hook**: The sort engine leverages a safe-difference comparison method, `(diff > 0) - (diff < 0)`. This pattern safely normalizes the `double` floating-point differences into exact integer return values (`-1`, `0`, or `1`), completely eliminating data truncation bugs.
