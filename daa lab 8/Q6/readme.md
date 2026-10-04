# Edit Distance with Traceback Information

## Problem Summary
Given two strings $A$ of length $m$ and $B$ of length $n$, compute the minimum number of operations (insertions, deletions, or substitutions) required to transform $A$ into $B$, and print the detailed step-by-step traceback operations.

## Complexity Analysis
* **Time Complexity:** $\mathcal{O}(m \times n)$
  * Evaluates edit operations across a matrix of size $m \times n$.
  * Printing the traceback path takes linear time bounded by $\mathcal{O}(m + n)$.
* **Space Complexity:** $\mathcal{O}(m \times n)$
  * Requires allocating a 2D grid of size $(m + 1) \times (n + 1)$ to cache transformation costs.
