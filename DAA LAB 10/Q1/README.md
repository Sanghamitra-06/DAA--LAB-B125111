# Problem 1: Online Graph-Bipartiteness Testing

## Description
A graph is bipartite if its vertices can be partitioned into two independent sets such that no two graph vertices within the same set are adjacent. This is equivalent to checking if the graph contains any odd-length cycles.

In an **online setting**, edges are added one by one. For each incoming edge:
1. The system checks if adding this edge forms an odd-length cycle with the already existing edges.
2. If it creates an odd-length cycle, the graph would lose its bipartiteness; the edge is **rejected/skipped**.
3. If it does not create an odd-length cycle, the edge is **accepted** and permanently integrated.

An optimized **Disjoint Set Union (DSU)** structural design handles this tracking by storing the 2-color parity relative to the dynamic parent node during path compression.

## Complexity Analysis

### Time Complexity
- **Initialization**: \(O(V)\) to allocate and clear vertex tracking states.
- **Per Edge Processing**: Amortized \(O(\alpha(V))\) per edge check via path-compressed DSU lookups, where \(\alpha\) is the Inverse Ackermann function.
- **Total Operational Time**: \(O(V + E \cdot \alpha(V))\), making it nearly linear and highly suited for real-time edge streaming.

### Space Complexity
- **Total Space**: \(O(V)\) auxiliary space to persist the state tracking structures (`parent` and `parity_arr`).

## Execution Example
```text
Input:
4 4
1 2
2 3
3 4
4 1

Output:
Edge (1, 2) added successfully.
Edge (2, 3) added successfully.
Edge (3, 4) added successfully.
Edge (4, 1) added successfully.
```
