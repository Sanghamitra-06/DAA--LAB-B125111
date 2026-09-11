# Super Egg Testing Experiment (Generalized Egg Dropping)

## Overview
This problem designs a generalized Dynamic Programming strategy to determine the highest safe floor in an $F$-storey building from which an egg can be dropped without breaking, given a limited pool of $E$ identical eggs.

## Core Logic
The strategy uses an optimal decision-tree framework to minimize the maximum number of drops required in the worst-case scenario. When dropping an egg from an arbitrary floor $k$ within a range of $j$ floors:
1. **The egg breaks:** The problem reduces to finding the critical floor among the $k-1$ lower floors using $i-1$ remaining eggs.
2. **The egg survives:** The problem reduces to checking the remaining $j-k$ upper floors using all $i$ eggs.

Let $DP[i][j]$ represent the minimum drops needed for $i$ eggs and $j$ floors. The optimal choice minimizes the worst-case outcome across all possible floor drops $k$:
$$DP[i][j] = 1 + \min_{1 \leq k \leq j} \Big\{ \max\big(DP[i-1][k-1],\, DP[i][j-k]\big) \Big\}$$

**Base Cases:**
* $DP[i][0] = 0$, $DP[i][1] = 1$ (0 or 1 floors require 0 or 1 drops).
* $DP[1][j] = j$ (1 single egg forces a sequential linear search from bottom to top).

## Complexity Analysis

### Time Complexity
* **Analysis:** The baseline dynamic programming solution uses three nested loops to iterate through the total count of eggs $E$, the total number of floors $F$, and all possible intermediate split points $k$.
* **Order of Growth:** $\mathcal{O}(E \cdot F^2)$ 

### Space Complexity
* **Analysis:** The state spaces are systematically cached using a two-dimensional lookup matrix of dimensions $(E+1) \times (F+1)$ to prevent redundant overlapping sub-problem calculations.
* **Order of Growth:** $\mathcal{O}(E \cdot F)$
