# 1D Array Operations and Their Complexities

## Logic
Processes basic numerical properties and structural transformations on a single-dimensional unsorted integer array.
* **Linear Scans:** Track element properties (bounds, sums, or conditions) by maintaining a few registers through a single pass.
* **Rearrangements:** Modify index positioning either symmetrically inward from the boundaries or around a pivot metric.
* **Sorting Dependency:** Complex properties like order statistics (median, mode) or uniqueness (duplicate removal) rely on partitioning elements sequentially.

## Analysis of Time & Space
* **Operations (i, ii, iii, v, viii, ix) - Max, Two Largest, Mean, Standard Deviation, Reverse, Pivot Partition:** 
  * **Time Complexity:** $O(n)$ — Single-pass linear traversals.
  * **Space Complexity:** $O(1)$ — Performs all exchanges and tracking in place.
* **Operations (iv, vi, vii) - Median, Mode, Remove Duplicates:**
  * **Time Complexity:** $O(n \log n)$ — Driven by standard element sorting (`qsort`). *Alternative approach achieves $O(n)$ using hash tables or QuickSelect.*
  * **Space Complexity:** $O(1)$ if sorted in place, or $O(n)$ if utilizing tracking tables.

## Implementation Method
Iterative structures written in native C using standard `for` or `while` control loops. Order-dependent operations utilize the standard library's `qsort` utility before matching indices.
