# 📌 Problem 2: Application of Sorting-II (Two-Sum Across Two Arrays)

### 🛑 Problem Statement
Given two sets $S_1$ and $S_2$ (each of size $n$) and a target value $x$, describe an $O(n \log n)$ algorithm to determine whether there exists a pair of elements (one from $S_1$ and one from $S_2$) that add up exactly to $x$.

### 💡 Algorithmic Logic
The optimal process utilizes a hybrid approach mixing sorting with binary search lookups. 
1. **Divide**: Sort set $S_1$ using Quick Sort or Merge Sort in $O(n \log n)$ time. Leave $S_2$ unsorted.
2. **Conquer**: Iterate through every element $y \in S_2$. Its required complement must be $(x - y)$.
3. **Lookup**: Perform a **Binary Search** for this complement inside the pre-sorted $S_1$ array. Since binary searching takes $O(\log n)$ and is executed $n$ times, the search phase scales at $O(n \log n)$.

### 📋 Step-by-Step Dry Run
Let us find a pair that adds up to target **x = 11** using two sets of size $n = 4$.
* **S₁ (Unsorted)**: `[12, 1, 9, 7]`
* **S₂ (Unsorted)**: `[10, 5, 2, 8]`

1. **Sort S₁**:
   * After sorting, $S_1 = [1, 7, 9, 12]$.
2. **Linear Loop with Binary Search Complement Lookup**:
   * **Iteration 1**: Current element from $S_2$ is `5`. Complement is $11 - 5 = 6$. Search `6` in $S_1$ $\rightarrow$ *Not Found*.
   * **Iteration 2**: Current element from $S_2$ is `2`. Complement is $11 - 2 = 9$. Search `9` in $S_1$ $\rightarrow$ *Found!* (Index 2).
* **Result**: Pair found successfully: **(9, 2)**.
