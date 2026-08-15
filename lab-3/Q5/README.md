# Module 5: Special-Pattern Recursive Matrix Multiplication

## 1. Structural Paradigm
This module implements an optimized multiplication strategy for square matrices of size $n = 2^k$ that feature a repeating recursive block symmetry:
Use code with caution.Matrix M = [ M1  M2 ][ M2  M1 ]This specific uniform pattern repeats recursively down to individual scalar elements.

## 2. Algorithmic Logic & O(n²) Optimization
A standard divide-and-conquer strategy requires four sub-blocks multiplications ($A_1B_1$, $A_2B_2$, $A_1B_2$, $A_2B_1$), leading to a runtime of $O(n^{\log_2 4}) = O(n^2 \log n)$ under the Master Theorem. 

To achieve a true $O(n^2)$ time bound, the algorithm applies an algebraic optimization that reduces the number of recursive operations from four to two:
1. Compute the subproblem matrix sum: $P_1 = (A_1 + A_2)(B_1 + B_2)$
2. Compute the subproblem matrix difference: $P_2 = (A_1 - A_2)(B_1 - B_2)$

Using these intermediate products, the output blocks are resolved via linear matrix addition and subtraction:
* $C_{11} = C_{22} = \frac{P_1 + P_2}{2}$
* $C_{12} = C_{21} = \frac{P_1 - P_2}{2}$

## 3. Complexity Verification
The recurrence relation for this optimized approach is:
T(n) = 2T(n/2) + Θ(n²)Here, $a = 2$, $b = 2$, and the split work is $f(n) = \Theta(n^2)$. Since $\log_b a = \log_2 2 = 1$, the division work $\Theta(n^2)$ dominates the execution profile. By Case 3 of the Master Theorem, the overall complexity simplifies to:
T(n) = Θ(n²)This matches the optimal runtime bound required to read the input values
