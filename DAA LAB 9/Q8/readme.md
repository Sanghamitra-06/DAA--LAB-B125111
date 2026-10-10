# Minimum Number of Meeting Rooms

## 💡 Core Logic & Algorithm
Given an array of meeting time intervals, the goal is to find the minimum number of conference rooms required to host all meetings without scheduling overlaps.

1. **Chronological Event Separation:** Start times and end times are extracted from the intervals and stored in two independent linear arrays.
2. **Independent Sorting:** Both arrays are sorted in ascending order. This shifts the focus from structural meeting blocks to discrete time events.
3. **Two-Pointer Simulation Loop:** A start pointer (`start_ptr`) tracks incoming room requests, and an end pointer (`end_ptr`) tracks room releases.
4. **Greedy Evaluation:**
   * If the next meeting starts before the earliest ongoing meeting ends (`start_times[start_ptr] < end_times[end_ptr]`), a new room is allocated, and `start_ptr` advances.
   * Otherwise, a meeting has finished, so a room is freed (`end_ptr` advances).
5. **Peak Tracking:** The algorithm records the maximum number of concurrent active rooms.

## 📊 Complexity Analysis
* **Time Complexity:** \(\mathcal{O}(n \log n)\) dominated by the sorting phase of the two independent time boundary arrays.
* **Space Complexity:** \(\mathcal{O}(n)\) to allocate independent storage arrays for the start and end time sequences.
