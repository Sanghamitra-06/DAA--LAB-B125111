# Maximum Sum Increasing Subsequence

## Problem Summary
Given an array of $n$ positive integers $A = [a_0, a_1, \dots, a_{n-1}]$, find the maximum possible sum of a strictly increasing subsequence.

## Complexity Analysis
* **Time Complexity:** $\mathcal{O}(n^2)$
  * Uses a nested loop structure identical to LIS to compare each element against all prior elements.
* **Space Complexity:** $\mathcal{O}(n)$
  * Requires a 1D table of size $n$ to store the maximum cumulative sum achievable ending at each specific index.
