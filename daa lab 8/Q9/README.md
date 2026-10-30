# Collatz Conjecture

## Problem Summary
Defines a sequence where for any positive integer $n$: if $n$ is even, the next number is $n/2$; if $n$ is odd, the next number is $3n + 1$. The program analyzes the total step count and maximum peak value reached for a specific single input value as well as across an entire interval range $[a, b]$.

## Complexity Analysis
* **Time Complexity:** Unbounded (Empirically open) / $\mathcal{O}((b - a) \times K)$ for intervals
  * The exact upper bound for a single number remains mathematically unproven.
  * For an entire interval, execution runs linearly with the range size multiplied by the average number of trajectory steps $K$ per element.
* **Space Complexity:** $\mathcal{O}(1)$
  * Operates completely inline with primitive storage variables, using no dynamic memory structures.
