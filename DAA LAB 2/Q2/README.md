# Question 2: 2-Way vs. Modified 3-Way Merge Sort

This project evaluates and compares standard two-way Merge Sort against a modified three-way division Merge Sort variant under empirical worst-case execution conditions.

## 📋 Problem Description
Consider a modification to merge sort: divide the input array into thirds (rather than halves), recursively sort each third, and combine the results using a three-way merge subroutine. Determine the worst-case running time and write a C program to validate the claim by plotting the order of growth for both.

## 🧠 Algorithmic Logic & Implementation
* **2-Way Division**: Computes a single split point $m = l + \frac{r-l}{2}$ to break data blocks into equal halves.
* **Modified 3-Way Division**: Divides working ranges systematically into matching thirds by computing two explicit internal pivot offsets:
  ```c
  int dim = (high - low) / 3;
  int mid1 = low + dim;
  int mid2 = low + 2 * dim;
  ```
* **The 3-Way Structural Merge**: Allocates three dedicated transient arrays (`L`, `M`, `R`). It loops through all three segments concurrently, picking the lowest element among the three positions using a series of nested comparison rules, and then cleans up any remaining items.

## ⏱️ Theoretical Time Complexity Overview
* **Standard 2-Way Sort**: $T(n) = 2T(n/2) + \Theta(n) \implies \mathbf{\Theta(n \log_2 n)}$
* **Modified 3-Way Sort**: $T(n) = 3T(n/3) + \Theta(n) \implies \mathbf{\Theta(n \log_3 n)}$

By applying the mathematical change of base formula:
\[\log_3 n = \frac{\log_2 n}{\log_2 3} \approx 0.63 \log_2 n\]
The three-way variation results in a shallower tree depth (fewer split layers), but requires more comparisons per element during the merge phase.

## 📊 Gnuplot Pipeline Interface
The metrics are routed into a $1 \times 2$ subplot multiplot layout. 
1. **Subplot 1**: Traces the raw operation counters against an increasing size scale ($N=1$ to $200$).
2. **Subplot 2**: Validates the time complexity bounds. To prevent compilation link errors due to the missing standard `log3` function, the code calculates the logarithmic base values explicitly using standard operations:
   ```c
   double log3_val = log((double)data[i].n) / log(3.0);
   double density = data[i].three_way_ops / ((double)data[i].n * log3_val);
   ```
The resulting horizontal flat lines visually confirm the exact asymptotic bounds calculated in the analysis.

## 🛠️ Compilation & Execution
Compile using GCC and link the standard math module library (`-lm`):
```bash
gcc q2.c -o q2.exe -lm
./q2.exe
```

## 🏁 Conclusion
The results show that while the 3-way sort creates fewer levels of recursion (a shallower execution tree), the additional comparison logic required to find the minimum of three elements instead of two offsets the reduction in depth. This makes it highly efficient for systems where memory access or secondary storage overhead dominates computation, but means it does not provide an immediate performance advantage for standard in-memory sorting.
