# Problem 3: Maximum Weight Component with Size Constraints

## Description
This challenge processes a stream of edge insertions while continually determining the **maximum total weight** among all valid connected network components whose absolute vertex count does not cross a specified threshold size \(K\).

The process works as follows:
1. Every vertex holds an internal structural weight property.
2. As edges link components, both aggregate size arrays and collective weight structures are combined at the designated component root.
3. Upon receiving an edge, the disjoint tracking sets merge.
4. The system loops through existing valid parent components to isolate the highest cumulative component weight that satisfies the constraint \((\text{Size} \le K)\).

## Complexity Analysis

### Time Complexity
- **Initialization**: \(O(V)\) setup cost to define weight states across isolated vertices.
- **Per Edge Query Evaluation**: \(O(V)\) iteration loop to filter the global collection for the highest valid root configuration.
- **Total Operational Time**: \(O(E \cdot V)\), bounded tightly by vertex size limits.

### Space Complexity
- **Total Space**: \(O(V)\) storage map space to track parent links, element weights, and size capacities.

## Execution Example
```text
Input:
4 3 2
10 20 30 5
1 2
2 3
3 4

Output:
30
50
35
```
