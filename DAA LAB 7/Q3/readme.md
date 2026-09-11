# Reve's Puzzle (4-Peg Tower of Hanoi)

## Overview
Reve's Puzzle modifies the classic Tower of Hanoi problem by adding a fourth peg, optimizing the total number of disk transfers required to migrate a sorted stack from a source peg to a destination peg.

## Core Logic
The puzzle is solved using the **Frame-Stewart Algorithm**, which divides the problem into smaller recursive subsets using a decrease-and-conquer strategy:
1. Determine an optimal threshold value $k$ for a given $n$ stack size.
2. Recursively transfer the top $k$ smallest disks to an operational auxiliary peg utilizing all 4 available pegs.
3. Transfer the remaining $n - k$ larger disks directly to the destination peg using a classic 3-peg strategy (leaving the peg containing the $k$ disks untouched).
4. Recursively transfer the $k$ disks from their temporary auxiliary peg onto the destination peg using all 4 available pegs.

The optimal $k$ selection that minimizes moves is dynamically evaluated using the mathematical boundary relation:
$$k = \text{round}\left(n + 1 - \sqrt{2n + 1}\right)$$

## Complexity Analysis

### Time Complexity
* **Analysis:** The recurrence relation is defined by $R(n) = 2 \cdot R(k) + (2^{n-k} - 1)$. Choosing the optimal $k$ yields an asymptotic sub-exponential growth pattern rather than a strict exponential curve.
* **Order of Growth:** $\mathcal{O}(2^{\sqrt{2n}})$

### Space Complexity
* **Analysis:** Memory utilization is constrained by the maximum call stack depth generated during the recursive breakdown of the $n$ disks.
* **Order of Growth:** $\mathcal{O}(n)$
