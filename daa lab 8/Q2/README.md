# Coin Change: Total Number of Ways

## Problem Summary
Given an array of distinct positive integers representing coin denominations $C = \{c_1, c_2, \dots, c_n\}$ and a target amount $V$, find the total number of distinct combinations of coins that sum up to $V$. You may assume an infinite supply of each coin denomination. The order of coins does not matter.

## Complexity Analysis
* **Time Complexity:** $\mathcal{O}(n \times V)$
  * The outer loop runs through each of the $n$ coin denominations.
  * The inner loop runs from the value of the current coin up to the target $V$.
* **Space Complexity:** $\mathcal{O}(V)$
  * Employs a single 1D array of size $V + 1$ to accumulate combination counts in-place.
