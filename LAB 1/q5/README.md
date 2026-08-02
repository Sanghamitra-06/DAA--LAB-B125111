### Problem 5: Find the Partition Point

*   **File Name**: `q5.c`
*   **Compilation Command**: 
    ```bash
    gcc q5.c -o q5
    ```
*   **Execution Command**: 
    ```bash
    ./q5
    ```

#### 💡 Algorithmic Technique Used
This solution implements an optimized search algorithm designed to isolate the exact index where a sequence of sorted `0` entries transitions into a sequence of `1` entries inside an unmapped binary array (e.g., `[0, 0, 0, 0, 1, 1, 1]`).
*   **Logarithmic Binary Search ($O(\log n)$)**: A naive approach requires scanning sequentially from left to right, resulting in a slow $O(n)$ time footprint. Instead, this solution applies a modified **Binary Search** pattern that operates via a divide-and-conquer model. By checking the midpoint element (`mid = low + (high - low) / 2`), it slices the remaining operational search space cleanly in half during every loop step.
*   **Left-Bound Inward Convergence**: When a `1` is successfully encountered, the algorithm does not immediately stop. Instead, it logs that location inside a temporary tracking variable as a candidate point, and aggressively shifts its search window to the left half of the array (`high = mid - 1`). This extra convergence loop guarantees that the application safely pins the *very first* transition boundary, even if the array contains millions of repeating `1`s.
