# Problem 5: Lexicographically Smallest Permutation

## Description
Given an array and a set of allowed index pairs that can be swapped, this problem finds the lexicographically smallest permutation of the array. Since swap relations are transitive, any indices that are directly or indirectly linked form a connected component, and elements within the same component can be rearranged into any arbitrary order.

The algorithm proceeds as follows:
1. A DSU structure groups array index positions into connected clusters based on permissible swap relationships.
2. For each distinct structural component, the code extracts its member element indices alongside their corresponding values.
3. Both extracted index and value sub-arrays are sorted independently in ascending order.
4. The sorted array values are mapped back into the sorted index locations, achieving the lowest possible lexicographical array configuration.

## Complexity Analysis

### Time Complexity
- **DSU Grouping Phase**: Amortized \(O(M \cdot \alpha(N))\) time to cluster index swap components.
- **Component Sorting Phase**: \(O(N \log N)\) worst-case time to sort arrays of values and indices across components using `qsort`.
- **Total Operational Time**: \(O(N \log N + M \cdot \alpha(N))\), dominated by the sorting phase.

### Space Complexity
- **Total Space**: \(O(N)\) linear memory space to map structural elements and track sorting buffers.

## Execution Example
```text
Input:
4 2
4 3 2 1
1 4
2 3

Output:
1 2 3 4
```
