# Matrix Chain Multiplication (MCM)

## Overview
This utility implements a dynamic programming approach to find the most efficient ordering for multiplying a chain of matrices, minimizing total scalar multiplication costs.

## Core Logic
Matrix multiplication is associative but highly sensitive to ordering. The algorithm calculates the optimal evaluation layout by breaking down global arrays into sub-problems:
1. **Cost Matrix Construction:** Maintain a 2D grid cost structure $m[i][j]$ to track the minimum multiplication actions needed to calculate products spanning from matrix $A_i$ through $A_j$.
2. **Recurrence Optimization:** Calculate costs across all potential splitting thresholds $k$ using the relation:
   $$m[i][j] = \min_{i \leq k < j} \{ m[i][k] + m[k+1][j] + p[i-1] \cdot p[k] \cdot p[j] \}$$
3. **Split Point Tracking:** An auxiliary tracking table $s[i][j]$ logs the exact index $k$ that yielded the lowest structural cost for each window, allowing the program to reconstruct the parenthesized output expression.

## Complexity Analysis

### Time Complexity
* **Analysis:** The solution uses three nested execution loops: one controlling the window sub-chain length, another tracking the starting boundaries, and a third evaluating split options inside the window.
* **Order of Growth:** $\mathcal{O}(n^3)$

### Space Complexity
* **Analysis:** The approach requires allocating two separate 2D storage grids ($m$ and $s$) of dimensions $n \times n$ to store intermediate costs and optimal split choices.
* **Order of Growth:** $\mathcal{O}(n^2)$
