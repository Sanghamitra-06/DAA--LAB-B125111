# Invert the Coin-Triangle

## Overview
This problem involves rearranging an equilateral triangle of tightly packed coins to face the opposite direction (inverting it upside down) using the absolute minimum number of individual coin slides. 

## Core Logic
The optimal strategy relies on maximizing the geometric overlap between the initial upward-pointing triangle and the final downward-pointing inverted triangle. Instead of moving all coins, the algorithm keeps the central intersection intact and only repositions the outlying tip and edge coins. 

For a triangle with side length $n$, the total number of coins is given by the triangular number $T_n = \frac{n(n+1)}{2}$. The minimum number of coin moves required to completely invert the orientation follows a compact floor division formula:
$$\text{Minimum Moves} = \left\lfloor \frac{n(n+1)}{6} \right\rfloor$$

## Complexity Analysis

### Time Complexity
* **Analysis:** Evaluating the total number of minimum moves takes instantaneous constant time using the closed-form algebraic formula. If the algorithm maps and prints the coordinate transformations of each coin, it processes the full grid space.
* **Order of Growth:** $\mathcal{O}(1)$ for computation; $\mathcal{O}(n^2)$ if tracking explicit coordinates.

### Space Complexity
* **Analysis:** The mathematical validation operates entirely within fixed scalar registers without allocating auxiliary matrix tables or generating recursive call stacks.
* **Order of Growth:** $\mathcal{O}(1)$
