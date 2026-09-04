# Matrix Chain Multiplication (MCM) via Dynamic Programming

## Logic
Calculates the most efficient sequence for multiplying a chain of matrices by determining the optimal placement of parentheses.
* The algorithm uses a sliding window to evaluate every possible splitting boundary $k$ within a sub-chain, selecting the split that minimizes scalar multiplications.

## Analysis of Time & Space
* **Time Complexity:** $O(N^3)$ — Driven by three nested loops: managing the chain length window, scanning the left index boundary, and evaluating internal splits.
* **Space Complexity:** $O(N^2)$ — Requires a 2D lookup table to preserve optimal scalar cost combinations across sub-chains.

## Implementation Method
Iterative bottom-up array interval mapping using a dynamic 2D cost matrix.
