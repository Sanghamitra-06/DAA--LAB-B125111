# Shortest Common Superstring - Greedy Heuristic Simulation

## 💡 Core Logic & Algorithm
The Shortest Common Superstring (SCS) problem is NP-hard. The classic greedy heuristic constructs an approximation by repeatedly maximizing the overlap between string pairs.

1. **Overlap Matrix Evaluation:** The algorithm checks every ordered pair of strings $(s_i, s_j)$ to find the longest suffix of $s_i$ that matches the prefix of $s_j$.
2. **Greedy Merge Choice:** It identifies the pair with the maximum overlap across the entire set.
3. **Consolidation Pass:** The two selected strings are merged into a single combined string, removing the overlapping segment to avoid duplication.
4. **Array Reduction:** The individual strings $s_i$ and $s_j$ are removed from the active pool, and the newly merged string is added. This loop runs until only one single superstring remains.
5. **Conjecture Context:** This tool simulates the greedy heuristic to test the limits of the approximation ratio against recent counterexamples.

## 📊 Complexity Analysis
* **Time Complexity:** $\mathcal{O}(n^3 \cdot L^2)$ where $n$ is the number of strings and $L$ is the maximum length of a string, due to pair-wise comparisons and string matching operations.
* **Space Complexity:** $\mathcal{O}(n \cdot L)$ to store the dynamically changing set of strings.
