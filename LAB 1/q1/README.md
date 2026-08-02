### Problem 1: Put Them in Order (Asymptotic Growth)

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

#### 📊 Asymptotic Growth Comparison Table
When $n \to \infty$, lower-order terms and constant coefficients lose significance, leaving the dominant term to dictate the long-term scaling performance. The table below ranks the functions in definitive **increasing order of growth** (from slowest growth to fastest growth):

| Rank | Function Label | Complexity Class (Big-O) | Description / Asymptotic Behavior |
| :--- | :--- | :--- | :--- |
| **1** | $1 / n$ | $O(n^{-1})$ | **Decreasing**: The only function that shrinks toward $0$ as $n$ scales up. |
| **2** | $\log_2(n)$ | $O(\log n)$ | **Logarithmic**: Extremely slow, highly efficient growth curve. |
| **3** | $12 * \sqrt{n}$ | $O(n^{0.5})$ | **Sub-linear**: Fractional power ($n^{0.5}$); beats $\log_2(n)$ over time. |
| **4** | $50n^{0.5}$ | $O(n^{0.5})$ | **Sub-linear**: Same growth class as $12\sqrt{n}$, but larger due to the coefficient. |
| **5** | $n^{0.51}$ | $O(n^{0.51})$ | **Sub-linear**: Slightly higher exponent than $0.5$; will eventually overtake both. |
| **6** | $2^{32} * n$ | $O(n)$ | **Linear**: Even with a massive constant coefficient ($2^{32}$), it scales linearly. |
| **7** | $n * \log_2(n)$ | $O(n \log n)$ | **Linearithmic**: Slightly faster than linear growth due to the log multiplier. |
| **8** | $n^2 - 324$ | $O(n^2)$ | **Quadratic**: Lower-order constant offset becomes irrelevant at scale. |
| **9** | $100n^2 + 6n$ | $O(n^2)$ | **Quadratic**: Dominated strictly by $n^2$; tracks higher than $n^2 - 324$ via its constants. |
| **10** | $2n^3$ | $O(n^3)$ | **Cubic**: Outpaces all quadratic expressions rapidly as $n$ increases. |
| **11** | $n^{\log_2 n}$ | Super-Polynomial | **Quasi-Exponential**: Rewritten as $2^{(\log_2 n)^2}$, completely leaving polynomials behind. |
| **12** | $3^n$ | $O(3^n)$ | **Exponential**: The fastest, most aggressive growth class in the set. |
