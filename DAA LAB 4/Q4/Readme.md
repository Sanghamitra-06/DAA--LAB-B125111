# 📌 Problem 4: Application of Sorting-IV (Peak Simultaneous Population)

### 🛑 Problem Statement
Given the arrival times $a_1, a_2, \dots, a_n$ and departure times $b_1, b_2, \dots, b_n$ of $n$ guests at a party, design an $O(n \log n)$ algorithm to find the exact time when the maximum number of people were present simultaneously.

### 💡 Algorithmic Logic
This problem is solved using the **Sweep-Line Algorithm**:
1. Deconstruct every individual's timeline into isolated timeline tracking pairs: an Entry event `(time, +1)` and an Exit event `(time, -1)`.
2. Consolidate all $2n$ events into a single array and sort them chronologically by time. If an entry and exit match timestamp values, exit is processed first to keep computations correct.
3. Move a step scanner variable through the sorted timeline array. Maintain a running counter of active guests (`current_count`) and record the peak point whenever the counter exceeds the previous high mark.

### 📋 Step-by-Step Dry Run
Let 3 people have timelines: $P_1(1, 4)$, $P_2(2, 6)$, $P_3(3, 5)$.
1. **Generate Events**: `(1, +1), (4, -1), (2, +1), (6, -1), (3, +1), (5, -1)`
2. **Sort Chronologically**: `[(1, +1), (2, +1), (3, +1), (4, -1), (5, -1), (6, -1)]`
3. **Sweep Line Tracking**:
   * Time 1: `current = 1`, `max = 1`, Peak Time = 1
   * Time 2: `current = 2`, `max = 2`, Peak Time = 2
   * Time 3: `current = 3`, `max = 3`, Peak Time = 3
   * Time 4: `current = 2`, `max = 3`
   * Time 5: `current = 1`, `max = 3`
   * Time 6: `current = 0`, `max = 3`
* **Result**: Peak population is **3** people, occurring at Time **3**.
