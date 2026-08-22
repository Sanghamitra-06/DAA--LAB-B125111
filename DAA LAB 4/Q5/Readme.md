# 📌 Problem 5: Application of Sorting-V (Merge Overlapping Intervals)

### 🛑 Problem Statement
Given a collection of $n$ intervals $I_i = (x_i, y_i)$, merge all overlapping intervals into a set of mutually exclusive, continuous intervals.

### 💡 Algorithmic Logic
1. Sort the list of intervals in ascending order based strictly on their **starting coordinates** ($x_i$).
2. Initialize an empty dynamic tracking array and place the first interval into it.
3. Progress linearly through the remaining sorted intervals. For every new interval check if its start boundaries sit lower than or equal to the end boundary of the last registered interval in our merged tracking space.
   * **If true (Overlap)**: Extend the active interval's end boundary to equal $\max(\text{last\_merged.end}, \text{current.end})$.
   * **If false (Gap)**: Insert the new non-overlapping interval as an independent tracking entry.

### 📋 Step-by-Step Dry Run
Let $I = \{(1,3), (2,6), (8,10), (7,18)\}$.
1. **Sort Intervals**: $I = [(1,3), (2,6), (7,18), (8,10)]$.
2. **Initialize Output**: `[(1,3)]`.
3. **Process (2,6)**:
   * Start `2` $\leq$ Last End `3` $\rightarrow$ **Overlaps!**
   * Merge: New End = $\max(3, 6) = 6$. Output becomes `[(1,6)]`.
4. **Process (7,18)**:
   * Start `7` > Last End `6` $\rightarrow$ **No Overlap!**
   * Append: Output becomes `[(1,6), (7,18)]`.
5. **Process (8,10)**:
   * Start `8` $\leq$ Last End `18` $\rightarrow$ **Overlaps!**
   * Merge: New End = $\max(18, 10) = 18$. Output stays `[(1,6), (7,18)]`.
* **Result**: Final merged list is **`{(1, 6), (7, 18)}`**.
