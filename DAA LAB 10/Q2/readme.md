# Problem 2: Dynamic Connected Components in a Grid

## Description
This problem dynamically keeps track of 4-directionally connected land components (islands) on an active \(R \times C\) matrix layout as individual grid slots transform into land cells sequentially.

The process tracks components as follows:
1. When a new land grid slot arrives, the total island tracker counter is incremented by 1.
2. The code inspects its 4-way neighbors (up, down, left, right).
3. If a neighbor slot is already a land structure, their respective structural groups are merged using a Disjoint Set Union (DSU) routine.
4. Each unique, successful component union reduces the global island count by 1.
5. Two-dimensional matrix coordinates \((r, c)\) are flattened into linear pointers using the mapping formula: \(\text{index} = r \times C + c\).

## Complexity Analysis

### Time Complexity
- **Initialization**: \(O(R \cdot C)\) to instantiate the empty grid matrix and parent pointers.
- **Per-query Update**: Amortized \(O(\alpha(R \cdot C))\) lookup and update cost for evaluating each neighbor.
- **Total Operational Time**: \(O(R \cdot C + K \cdot \alpha(R \cdot C))\), ensuring lightning-fast updates for \(K\) dynamic inputs.

### Space Complexity
- **Total Space**: \(O(R \cdot C)\) memory footprints to maintain state tracking layers across the static dimension space.

## Execution Example
```text
Input:
3 3 4
0 0
0 1
2 2
0 2

Output:
1
1
2
2
```
