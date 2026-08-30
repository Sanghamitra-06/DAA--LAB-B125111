# Lab Question 4: File-Based Heapsort Implementation

## 📌 Problem Statement
Generate $N$ random numbers, preserve them in a flat source file, load them back into runtime memory, sort them utilizing the **Heapsort** method, and record the results into an output file.

---

## 💡 Logic & Algorithm
This program relies on a binary heap tree layout structure to perform in-place sorting without requiring recursive tree node pointers.

### **Algorithm Steps:**
1. **File Creation:** Write $N$ pseudo-random numbers into `input.txt`.
2. **Buffer Load:** Read the file content into a dynamically allocated array.
3. **Build Max-Heap:** Transform the flat array into a max-heap structural framework from the bottom up, ensuring every parent element is larger than its children.
4. **Sort Loop:** 
   - Swap the primary maximum value (located at index `0`) with the last active element in the boundary array.
   - Shrink the valid heap zone length by 1.
   - Execute the `heapify()` balancing workflow on index `0` to bubble down the swapped value into its correct location.
5. **Output:** Export the finalized ordered array data into `output_heap.txt`.

---

## ⏱️ Time & Space Complexity Analysis

| Scenario | Time Complexity | Notes |
| :--- | :--- | :--- |
| **Best Case** | $\mathcal{O}(N \log N)$ | Same runtime workflow depth across all data states. |
| **Average Case** | $\mathcal{O}(N \log N)$ | Highly predictable performance due to structural heap balances. |
| **Worst Case** | $\mathcal{O}(N \log N)$ | Guarantees excellent scalability even with adverse worst-case data configurations. |

* **Space Complexity:** $\mathcal{O}(1)$ pure auxiliary workspace since the heap mutations occur natively inside the data array bounds.
