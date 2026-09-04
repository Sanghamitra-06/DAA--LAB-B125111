# 0/1 Knapsack Problem via Dynamic Programming

## Logic
Selects an optimal combination of items to maximize overall profit without violating a strict weight capacity threshold $W$. 
* For each item, the algorithm builds upon previous capacities to decide whether excluding or including the current item yields a higher total profit.

## Analysis of Time & Space
* **Time Complexity:** $O(n \cdot W)$ — Driven by nested loops processing all $n$ available items against every integer weight profile up to capacity $W$.
* **Space Complexity:** $O(W)$ — Space-optimized down to a single 1D memory array. By scanning weights in reverse, the algorithm safely prevents an item from being counted multiple times.

## Implementation Method
Tabulation optimization utilizing a dynamically allocated single-row state cache.
