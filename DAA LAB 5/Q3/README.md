# Lab Question 3: File-Based Quicksort Implementation

## 📌 Problem Statement
Generate $N$ random integers, store them inside an unformatted input text file, read the values from the file into memory, sort them using the **Quicksort** algorithm, and save the final outputs to a separate file.

---

## 💡 Logic & Algorithm
This program couples standard File I/O operations with the traditional divide-and-conquer **Quicksort** paradigm.

### **Algorithm Steps:**
1. **File Population:** Initialize a random seed and write $N$ randomly generated numbers via `rand()` into a file named `input.txt`.
2. **Ingestion:** Open `input.txt` and parse the raw numbers directly into a dynamic array.
3. **Divide and Conquer (Quicksort):**
   - **Partition:** Choose an element as a pivot. Move smaller items to its left and larger items to its right.
   - **Recurse:** Separately invoke the sort algorithm on the left chunk and the right chunk.
4. **Export:** Iterate through the fully sorted array and write each index line-by-line into `output_quick.txt`.

---

## ⏱️ Time & Space Complexity Analysis

| Scenario | Time Complexity | Notes |
| :--- | :--- | :--- |
| **Best Case** | $\mathcal{O}(N \log N)$ | The pivot always splits the workspace into balanced halves. |
| **Average Case** | $\mathcal{O}(N \log N)$ | Standard performance metric for randomized data streams. |
| **Worst Case** | $\mathcal{O}(N^2)$ | Highly unbalanced splits (e.g., trying to sort already sorted files using a boundary pivot). |

* **Space Complexity:** $\mathcal{O}(\log N)$ auxiliary space for the implicit recursion stack framework during typical operations.
