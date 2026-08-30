# Lab Question 1: Find Median Without Sorting

## 📌 Problem Statement
Given an unsorted list of $N$ numbers, find the **median** of the elements without sorting the entire array.

---

## 💡 Logic & Algorithm (Quickselect)
To find the median without a full sort, this implementation uses the **Quickselect algorithm** (a variant of Quicksort's partitioning scheme).

### **Algorithm Steps:**
1. **Find Target Index:** 
   - If $N$ is odd, the median is at index $k = N / 2$.
   - If $N$ is even, the median is the average of elements at $k_1 = (N / 2) - 1$ and $k_2 = N / 2$.
2. **Choose a Pivot:** Pick the last element as the pivot.
3. **Partition:** Rearrange the array so that elements smaller than the pivot go to the left, and larger elements go to the right. This places the pivot at its correct final sorted index (`pivotIndex`).
4. **Recurse Selectively:** 
   - If `pivotIndex` matches our target index $k$, we found the element.
   - If `pivotIndex > k`, repeat the process on the left sub-array.
   - If `pivotIndex < k`, repeat on the right sub-array.

---

## ⏱️ Time & Space Complexity Analysis

| Scenario | Time Complexity | Notes |
| :--- | :--- | :--- |
| **Best Case** | $\mathcal{O}(N)$ | The pivot splits the array evenly every time. |
| **Average Case** | $\mathcal{O}(N)$ | Mathematically scales to $N + N/2 + N/4 + \dots \approx 2N$. |
| **Worst Case** | $\mathcal{O}(N^2)$ | Occurs when the input is already sorted and the extreme element is always chosen as the pivot. |

* **Space Complexity:** $\mathcal{O}(1)$ auxiliary space if implemented iteratively, or $\mathcal{O}(N)$ stack memory in the absolute worst-case recursion scenario.
