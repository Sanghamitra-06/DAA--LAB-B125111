# Minimum Coin Change

## Problem Summary
Given an integer array of coin denominations \(C = \{c_1, c_2, \dots, c_n\}\) and a target amount \(V\), find the minimum number of coins needed to make up that amount. You may assume an infinite supply of each coin denomination. If the amount cannot be made up by any combination, return `-1`.

## Complexity Analysis
* **Time Complexity:** \(\mathcal{O}(n \times V)\)
  * The algorithm iterates through all target values from \(1\) to \(V\).
  * For each value, it checks all \(n\) coin denominations to find the optimal reduction.
* **Space Complexity:** \(\mathcal{O}(V)\)
  * Uses a 1D DP array of size \(V + 1\) to store the minimum coins needed for every sub-amount.
