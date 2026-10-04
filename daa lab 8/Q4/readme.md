# Longest Increasing Subsequence (LIS)

## Problem Summary
Given an integer array $A = [a_0, a_1, \dots, a_{n-1}]$, find the length of the longest subsequence such that all elements of the subsequence are strictly increasing. The elements do not need to be contiguous in the original array.

## Complexity Analysis
* **Time Complexity:** $\mathcal{O}(n^2)$
  * Employs two nested loops where each element $i$ is compared against all preceding elements $j$ (where $j < i$).
* **Space Complexity:** $\mathcal{O}(n)$
  * Utilizes a 1D DP array of size $n$ to store the length of the LIS ending at each index.
