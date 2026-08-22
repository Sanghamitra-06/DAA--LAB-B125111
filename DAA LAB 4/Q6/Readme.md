# 📌 Problem 6: Application of Sorting-VI (Most Intersected Point)

### 🛑 Problem Statement
Given $n$ intervals on a 1D line, determine a coordinate point $p$ that intersects the maximum number of intervals.

### 💡 Algorithmic Logic
This variation maps coordinates to independent boundary states using a sweep-line matrix:
1. Break down every continuous interval $(l_i, r_i)$ into discrete starting coordinates `(l_i, +1)` and ending markers `(r_i, -1)`.
2. Sort these markers together in ascending numerical order. If a starting marker and an ending marker fall on the exact same coordinate value, sort the starting marker (`+1`) first to ensure inclusive intersections are counted.
3. Sweep across the ordered points from left to right. Accumulate the values into a running balance counter. The point where the counter peaks marks the coordinate space intersecting the highest density of layers.

### 📋 Step-by-Step Dry Run
Let $S = \{(10, 40), (20, 60), (50, 90), (15, 70)\}$.
1. **Flatten to Bound Events**: `(10, +1), (40, -1), (20, +1), (60, -1), (50, +1), (90, -1), (15, +1), (70, -1)`
2. **Sort Chronologically**: `[(10, +1), (15, +1), (20, +1), (40, -1), (50, +1), (60, -1), (70, -1), (90, -1)]`
3. **Sweep Line Tracking**:
   * Point 10: `count = 1`, `max = 1`
   * Point 15: `count = 2`, `max = 2`
   * Point 20: `count = 3`, `max = 3`, Peak Point = 20
   * Point 40: `count = 2` (Interval ends after point 40)
   * Point 50: `count = 3`, `max = 3` (Another peak interval)
   * Point 60: `count = 2`
* **Result**: The maximum number of overlapping intervals is **3**, and any point between **20 and 40** (or point **50**) is a valid intersection point.
