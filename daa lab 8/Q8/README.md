# Optimal Binary Search Trees (OBST)

## Problem Summary
Given a set of $n$ distinct sorted keys $K = \langle k_1, k_2, \dots, k_n \rangle$ with search probabilities $p_1, p_2, \dots, p_n$, and $n+1$ dummy keys $d_0, d_1, \dots, d_n$ representing unsuccessful searches with probabilities $q_0, q_1, \dots, q_n$, find the minimum expected search cost of a binary search tree.

## Complexity Analysis
* **Time Complexity:** $\mathcal{O}(n^3)$
  * Utilizes three nested loops: one for tree sequence length, one for the starting index, and an innermost loop to evaluate every candidate root key within that range.
* **Space Complexity:** $\mathcal{O}(n^2)$
  * Employs two 2D matrices of size $(n + 2) \times (n + 2)$ to track sub-tree search costs and weight probabilities.
