# Module 1: Binary vs. Ternary Search Analysis

## 1. Architectural View & Algorithmic Core Logic
This directory contains a performance evaluation framework comparing two comparison-based search paradigms running on pre-sorted arrays. 

* **Binary Search:** Places a single midpoint partitioning target ($mid$). It divides the search space into two balanced halves ($n/2$). At each step, a single element comparison determines whether to narrow the boundary to the lower or upper half.
* **Ternary Search:** Introduces two distinct internal partitioning boundaries ($mid1$ and $mid2$), slicing the linear collection into three equal-sized intervals ($n/3$). This structure requires a minimum of two consecutive conditional evaluations per iteration step to pinpoint the target quadrant.

## 2. Mathematical Performance Justification
While Ternary Search features a lower maximum recursion/loop depth ($\log_3 n$ levels compared to $\log_2 n$ levels), it incurs a greater overall cost due to the higher number of comparisons per iteration. 

The worst-case comparison profiles map out as follows:
* **Worst-Case Binary Comparisons:** $C_{\text{binary}}(n) = 1 \cdot \log_2 n \approx 1.442 \ln n$
* **Worst-Case Ternary Comparisons:** $C_{\text{ternary}}(n) = 2 \cdot \log_3 n = 2 \cdot \frac{\ln n}{\ln 3} \approx 1.820 \ln n$

This demonstrates that Ternary Search introduces approximately a 26.2% comparison overhead under worst-case inputs.

## 3. Implementation and Validation Strategy
The program tracks algorithmic efficiency by incrementing absolute conditional execution counters rather than relying on system clock cycles. This ensures that the benchmarks remain completely decoupled from operating system thread scheduling, CPU thermal scaling, or background context switches.
