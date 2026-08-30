# Lab Question 2: Find the K-th Smallest Element

## 📌 Problem Statement
Given an unsorted list of $N$ numbers, find the **$K$-th smallest element** in the array without using any full sorting algorithms.

---

## 💡 Logic & Algorithm (Quickselect)
Instead of processing a full $\mathcal{O}(N \log N)$ sort, this program utilizes the **Quickselect** approach to locate the exact item that would settle at index $K - 1$ in a sorted setup.

### **Algorithm Steps:**
1. **Partitioning:** Select a pivot (e.g., the last element). Rearrange elements so everything smaller than the pivot rests to its left and everything larger rests to its right.
2. **Index Check:** Let the pivot's final index position be `index`.
3. **Branch Selection:**
   - If `index == K - 1`, return the element at `index`.
   - If `index > K - 1`, discard the right half and recursively partition the left side.
   - If `index < K - 1`, discard the left half and focus entirely on the right side.

---

## ⏱️ Time & Space Complexity Analysis

| Scenario | Time Complexity | Notes |
| :--- | :--- | :--- |
| **Best Case** | $\mathcal{O}(N)$ | The chosen pivot happens to land perfectly at index $K-1$ early on. |
| **Average Case** | $\mathcal{O}(N)$ | The search space is roughly halved during each step. |
| **Worst Case** | $\mathcal{O}(N^2)$ | Bad pivot selections consistently reduce the problem size by only 1 element. |

* **Space Complexity:** $\mathcal{O}(1)$ auxiliary space when written iteratively.
