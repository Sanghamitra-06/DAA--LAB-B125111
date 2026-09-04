# $n$-th Fibonacci Number via Dynamic Programming

## Logic
Computes sequential values in the Fibonacci chain by building upon the solution to preceding indices. Instead of redundant, exponential recursive trees, values are computed linearly from the bottom up.

## Analysis of Time & Space
* **Time Complexity:** $O(n)$ — Single sequential execution loop running from index 2 up to the target value.
* **Space Complexity:** $O(1)$ — Space-optimized to eliminate array requirements by tracking only the last two computed states in separate variables.

## Implementation Method
A simple iterative calculation loop updating tracking variables (`prev2`, `prev1`, `current`) on each cycle.
