# Module 6: Use of Loop Invariants in Sorting

## 1. Selection Sort Pseudocode (1-Based Indexing)
```text
SELECTION-SORT(A, n)
1. For i = 1 to n - 1
2.     min_idx = i
3.     For j = i + 1 to n
4.         if A[j] < A[min_idx]
5.             min_idx = j
6.     exchange A[i] with A[min_idx]
```

## 2. Loop Invariant Specification
> **Invariant Statement:** At the start of each iteration of the outer loop (line 1), the prefix subarray $A[1 \cdots i-1]$ consists of the $i-1$ smallest elements originally present in the global array, sorted in ascending order.

## 3. Formal Mathematical Proof
* **Initialization:** Prior to the first loop index step ($i = 1$), the target prefix subarray evaluates to $A[1 \cdots 0]$, which is empty. This vacuously satisfies the sorting criteria and correctly represents the 0 smallest elements.
* **Maintenance:** During iteration $i$, the inner loop scans the unsorted suffix array $A[i \cdots n]$ to locate the absolute minimum element's position (`min_idx`). Swapping $A[i]$ with $A[\text{min\_idx}]$ guarantees that the element now at index $i$ is greater than or equal to all elements in the sorted prefix $A[1 \cdots i-1]$ and less than or equal to all elements in the remaining suffix $A[i+1 \cdots n]$. Incremented to $i + 1$, the sorted prefix array grows to include this new element, maintaining the invariant.
* **Termination:** The loop terminates when $i = n$. Evaluating the invariant at termination states that the prefix subarray $A[1 \cdots n-1]$ contains the $n-1$ smallest elements of the array in sorted order. By extension, the single remaining element left at index $A[n]$ must be the largest value in the collection, leaving the entire array successfully sorted.

## 4. Boundary Conditions & Runtime Profile
* **Boundary Justification:** The algorithm safely terminates at $n-1$ elements because placing $n-1$ items in their correct relative positions automatically leaves the final element at index $n$ as the maximum remaining value. An additional loop pass would perform no operations.
* **Worst-Case Runtime Complexity:** $\Theta(n^2)$. The nested loops execute a deterministic number of comparisons equal to $\frac{n(n-1)}{2}$, regardless of input permutations.
* **Best-Case Runtime Complexity:** $\Theta(n^2)$. Even if the array is provided fully sorted, the inner loop must still scan all remaining elements to verify the local minimum during each iteration.
