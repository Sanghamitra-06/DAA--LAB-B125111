# Module 4: Matrix Multiplication via Strassen's Method

## 1. Architectural Strategy
Standard matrix multiplication operates on an $O(n^3)$ cubic growth curve due to three nested loops. Strassen’s Divide and Conquer methodology optimizes this layout by re-engineering the partitioning math of sub-matrices, reducing the required sub-block multiplications from 8 down to 7. This drops the asymptotic runtime complexity to $O(n^{\log_2 7}) \approx O(n^{2.81})$.

## 2. Algorithmic Core Logic
The approach divides each input matrix into four equal quadrants of dimension $\frac{n}{2} \times \frac{n}{2}$. Instead of using eight traditional cross-multiplications, Strassen's method builds seven specialized matrix joint equations ($P_1$ through $P_7$):
* $P_1 = A_{11}(B_{12} - B_{22})$
* $P_2 = (A_{11} + A_{12})B_{22}$
* $P_3 = (A_{21} + A_{22})B_{11}$
* $P_4 = A_{22}(B_{21} - B_{11})$
* $P_5 = (A_{11} + A_{22})(B_{11} + B_{22})$
* $P_6 = (A_{12} - A_{22})(B_{21} + B_{22})$
* $P_7 = (A_{11} - A_{21})(B_{11} + B_{12})$

These intermediate products are combined using matrix addition and subtraction to construct the output quadrants ($C_{11} = P_5 + P_4 - P_2 + P_6$, etc.), bypassing the eighth multiplication step.
