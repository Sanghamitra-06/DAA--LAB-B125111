# Longest Common Subsequence (LCS)

## Problem Summary
Given two sequences $X = \langle x_1, x_2, \dots, x_m \rangle$ and $Y = \langle y_1, y_2, \dots, y_n \rangle$, compute the length of their longest common subsequence and reconstruct the actual subsequence string.

## Complexity Analysis
* **Time Complexity:** $\mathcal{O}(m \times n)$
  * Filling the lookup table requires computing values for an $m \times n$ matrix.
  * The traceback process to reconstruct the sequence takes linear time $\mathcal{O}(m + n)$, which is dominated by the table filling phase.
* **Space Complexity:** $\mathcal{O}(m \times n)$
  * Requires a 2D table of dimensions $(m + 1) \times (n + 1)$ to preserve the optimal subproblem values.
