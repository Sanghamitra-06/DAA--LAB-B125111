# Sorting via Reversal Procedure

## Logic
Organizes a disorganized random permutation using only range-bounded reversals.
* To avoid a slow $O(n^2)$ length-weighted cost, a value-based divide-and-conquer architecture splits the subarray across its median.
* Blocks are stably partitioned into smaller and larger value sets using 3 localized block swaps: `reverse(Left_Large)`, `reverse(Right_Small)`, and a combined `reverse(Both)`.

## Analysis of Time & Space
* **Reversal Operations Count:** Bounded strictly by $O(n)$ total calls.
* **Length-Weighted Cost:** 
  * **Time Complexity:** $O(n \log^2 n)$ — The stable reversal partitioning step costs $O(n \log n)$ at each tier of the tree. Summing across $\log n$ recursion levels yields $O(n \log^2 n)$.
  * **Space Complexity:** $O(n)$ auxiliary space to compute local subarray median states.

## Implementation Method
Divide-and-conquer binary recursion combined with a standard in-place double-pointer swapping reversal sequence.
