# Rod Cutting with Reconstruction

## Problem Summary
Given a rod of length $n$ inches and an array of prices $P = [price_1, price_2, \dots, price_n]$, determine:
1. The maximum revenue obtainable by cutting up the rod and selling the pieces.
2. The exact lengths of the pieces that constitute the optimal decomposition.

## Complexity Analysis
* **Time Complexity:** $\mathcal{O}(n^2)$
  * Solved using two nested loops where each rod length $i$ evaluates every possible first cut size $j$.
* **Space Complexity:** $\mathcal{O}(n)$
  * Allocates two 1D arrays of size $n + 1$: one for tracking maximum revenues, and one for storing parent cuts to reconstruct the pieces.
