# Minimum Cost to Connect Sticks

## 💡 Core Logic & Algorithm
This problem is a direct application of the optimal merge pattern strategy. When connecting two sticks of length $X$ and $Y$, a cost of $X + Y$ is paid, and they form a single new stick.

1. **Greedy Aggregation Strategy:** To minimize total costs, the algorithm must avoid letting large numbers participate in multiple additions. It always selects the two smallest available elements from the pool.
2. **Heap-Based Extraction:** A Min-Heap (Min-Priority Queue) is initialized with all stick lengths.
3. **Iterative Reduction Loop:** 
   * Extract the two minimum elements from the heap root.
   * Add them together to find the connection cost.
   * Add this cost to the global running total.
   * Insert the newly combined stick length back into the min-heap.
4. **Termination:** The process repeats until only one single unified stick remains in the heap collection.

## 📊 Complexity Analysis
* **Time Complexity:** $\mathcal{O}(n \log n)$ because building the heap takes $\mathcal{O}(n)$, and each of the $(n-1)$ extraction and insertion steps takes $\mathcal{O}(\log n)$ time.
* **Space Complexity:** $\mathcal{O}(n)$ to allocate space for the elements inside the min-heap array.
