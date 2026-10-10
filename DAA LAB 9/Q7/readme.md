# Minimise Deviation in Array

## 💡 Core Logic & Algorithm
The objective is to minimize the difference between the maximum and minimum elements in an array by multiplying odd numbers by 2 or dividing even numbers by 2.

1. **One-Directional Conversion:** Odd numbers can only be multiplied by 2 once (after which they become even). To simplify the problem, the algorithm multiplies all odd numbers by 2 upfront, setting every element to its maximum possible upper bound.
2. **Max-Heap Initialization:** All elements are placed into a Max-Heap, and the global minimum value (`min_val`) is tracked.
3. **Greedy Reduction Loop:**
   * Extract the maximum element (`max_val`) from the heap.
   * Calculate the current deviation (`max_val - min_val`) and update the minimum deviation found so far.
   * If `max_val` is even, divide it by 2, update `min_val` if this new value is smaller, and insert it back into the heap.
4. **Termination Option:** If `max_val` is odd, the loop stops. Since it is the largest element and cannot be divided further, the deviation cannot be reduced any more.

## 📊 Complexity Analysis
* **Time Complexity:** \(\mathcal{O}(n \log n \log M)\), where \(n\) is the number of elements and \(M\) is the maximum value in the array (since an element can be divided at most \(\log M\) times).
* **Space Complexity:** \(\mathcal{O}(n)\) to store elements inside the max-heap array layout.
