# Problem 4: Reverse Time-Step DSU Application

## Description
Simulating successive node deletions directly from a live graph breaks connectivity path properties, making it algorithmically inefficient. This problem resolves that limitation by reversing the timeline and building the network graph backward from scratch.

The algorithm handles data elements as follows:
1. The process captures the destruction array sequence and conceptually starts with an empty graph setup.
2. The routine runs in reverse (from step \(V\) down to 1), reconstructing ("undeleting") one specific vertex per step.
3. The newly activated vertex forms links with any pre-activated neighbors using standard path-compressed DSU merges.
4. The global maximum weight track value is recorded at each reverse step, stored, and printed sequentially in forward-chronological order.

## Complexity Analysis

### Time Complexity
- **Graph and Node Configuration**: \(O(V + E)\) step cost to construct adjacency links.
- **Reverse Iteration**: Near-linear \(O((V + E) \cdot \alpha(V))\) timeline processing phase due to amortized DSU optimizations.
- **Total Operational Time**: \(O(V + E \cdot \alpha(V))\), avoiding expensive graph traversal resets.

### Space Complexity
- **Total Space**: \(O(V + E)\) memory blocks to host the inverse response array and tracking indices.

## Execution Example
```text
Input:
4 3
10 20 30 40
1 2
2 3
3 4
1 2 3 4

Output:
100
90
70
40
```
