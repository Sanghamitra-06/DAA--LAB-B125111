# Hitting a Moving Target

## Overview
This problem establishes a deterministic shooting strategy to hit an unseen target moving along a linear array of $n$ hiding spots. The target moves exactly one spot to the left or right after every shot.

## Core Logic
The underlying logic exploits **parity invariance**. Because the target changes its position index by exactly $\pm 1$ every step, its position parity (even or odd) alternates cleanly between every shot. The target's exact starting parity is unknown, so a two-pass algorithm handles both possibilities:
1. **First Pass (Even Sweep):** Assume the target began on an even position. By checking locations sequentially from $2$ to $n-1$, the shooter's guess will match the target's position parity state and catch it if the assumption holds.
2. **Second Pass (Odd Sweep):** If the target remains unhit, the original assumption was wrong, meaning it started on an odd spot. Because of the elapsed turns, its current parity is now inverted. Running a second sweep from $n-1$ down to $2$ guarantees a hit.

This deterministic sweep guarantees a hit within a maximum of $2n - 4$ structural operations.

## Complexity Analysis

### Time Complexity
* **Analysis:** The algorithm runs two linear passes across the array bounds. The total operations scale proportionally with the number of hiding spots $n$.
* **Order of Growth:** $\mathcal{O}(n)$

### Space Complexity
* **Analysis:** The state tracking requires no secondary lookup structures or recursive call depth frames, executing entirely within fixed boundary registers.
* **Order of Growth:** $\mathcal{O}(1)$
