# Longest Common Subsequence (LCS) via Dynamic Programming

## Logic
Identifies the longest aligned matching character sequence between two strings.
* **Tabulation:** Builds a bottom-up 2D grid matrix storing optimal match profiles for all index combinations.
* **Reconstruction:** Once the table is fully populated, the algorithm backtracks from the final cell to reconstruct the exact character sequence.

## Analysis of Time & Space
* **Time Complexity:** $O(m \cdot n)$ — Two nested loops evaluate character matching states across string lengths $m$ and $n$.
* **Space Complexity:** $O(m \cdot n)$ — Requires a full 2D grid allocation to support the backtracking pointer path.

## Implementation Method
2D array grid mapping combined with a reverse index conditional verification loop.
