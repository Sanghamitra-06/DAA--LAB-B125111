# Hu-Tucker Alphabetic Binary Tree Simulation

## 💡 Core Logic & Algorithm
The Hu-Tucker algorithm constructs an optimal alphabetic binary search tree. Unlike standard Huffman codes, it preserves the strict in-order structural sequence of the leaf nodes.

1. **Combination Step:** The algorithm searches the sequence to find an adjacent compatible pair of nodes $(i, j)$ that minimizes the combined weight sum $w_i + w_j$.
2. **Compatibility Conditions:** Two nodes are compatible if they are next to each other in the sequence, skipping over any internal nodes that have already been merged.
3. **Iterative Reduction:** The selected pair is merged into a new internal parent node, replacing the original two nodes in the sequence.
4. **Level Adjustment (Overview):** After all merges are complete, the algorithm determines the final leaf depths and reconstructs the tree to match the original in-order sequence constraints.

## 📊 Complexity Analysis
* **Time Complexity:** $\mathcal{O}(n^2)$ for a basic sequential implementation that scans for adjacent valid pairs. (Can be optimized to $\mathcal{O}(n \log n)$ using priority queues).
* **Space Complexity:** $\mathcal{O}(n)$ to maintain the dynamic sequence array layout during the combination phase.
