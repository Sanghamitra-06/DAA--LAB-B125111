# Security Switches (Chinese Rings Puzzle)

## Overview
This problem models a row of $n$ dependent switches guarding an entrance. The goal is to determine the most direct sequence of operations required to transition all switches from an active configuration (`1`) to a completely deactivated configuration (`0`).

## Core Logic
The movement constraints align directly with the structural properties of binary Gray codes and the traditional Baguenaudier (Chinese Rings) puzzle structure:
1. The rightmost switch (index 1) can be freely toggled at any moment.
2. Any other switch $i$ can change state if and only if switch $i-1$ directly to its right is active (`1`) and all switches further to the right ($i-2$ down to $1$) are completely inactive (`0`).

To turn off switch $n$, the algorithm recursively sets up switch $n-1$ to be active and clears all switches below it. Once switch $n$ is toggled off, a recursive cleanup routine is run to clear out the operational dependencies left behind.

## Complexity Analysis

### Time Complexity
* **Analysis:** The recurrence pattern follows $F(n) = F(n-1) + 2 \cdot F(n-2) + 1$. The closed-form execution sequence requires approximately $\frac{2^{n+1}-2}{3}$ moves for even numbers and $\frac{2^{n+1}-1}{3}$ for odd variations.
* **Order of Growth:** $\mathcal{O}(2^n)$

### Space Complexity
* **Analysis:** The configuration state space is managed within a linear array, while the memory consumption is bounded by the deep execution frame lineage of the call stack.
* **Order of Growth:** $\mathcal{O}(n)$
