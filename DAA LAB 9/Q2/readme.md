# Canonical Huffman Codebook Generator

## 💡 Core Logic & Algorithm
Standard Huffman trees generate optimal prefix codes, but their exact bit representations can vary based on tree layout choices. A **Canonical Huffman Code** standardizes the output by enforcing a strict structural ordering constraint.

1. **Greedy Bottom-Up Tree:** A min-priority queue repeatedly extracts the two nodes with the lowest frequencies and pairs them into a parent internal node until only a single root remains.
2. **Code Length Extraction:** The algorithm traverses the generated tree solely to extract the exact **bit-length** required for each individual character symbol.
3. **Lexicographical Canonical Sorting:** Symbols are sorted using a two-tier comparison:
   * Primarily by code length (ascending).
   * Secondarily by alphabetical order of the symbols.
4. **Bit-String Generation:** Codes are assigned sequentially using a simple tracking rule:
   $$\text{code} = (\text{code} + 1) \ll 1$$
   This ensures that all values of a specific length form a continuous sequence of integers, allowing for fast, tree-less decompression.

## 📊 Complexity Analysis
* **Time Complexity:** $\mathcal{O}(n \log n)$ dominated by the min-heap operations during tree assembly and the subsequent canonical layout sort.
* **Space Complexity:** $\mathcal{O}(n)$ to store structural tree nodes and the mapped length array buffers.
