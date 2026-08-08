# Question 3: $k$-Way Sorted Array Merging Strategies

This project implements, analyzes, and visualizes two different methods for merging $k$ pre-sorted arrays (each containing $n$ elements) into a single, unified sorted output array.

## 📋 Problem Description
Design and implement two separate algorithmic workflows to merge $k$ pre-sorted arrays, track their internal operational metrics, and analyze their theoretical and empirical growth models.

## 🧠 Algorithmic Logic & Implementation
* **Method 1: Repeated Linear Merging**: This approach uses a sequential accumulation strategy. It takes the first array as the initial base, then uses a loop from index $1$ to $k-1$ to repeatedly merge the current accumulated output with the next incoming sorted array.
* **Method 2: Pairwise Divide & Conquer Merging**: This strategy mimics a balanced merge tree structure. It loops through the collection and merges adjacent arrays in pairs (e.g., Array 0 and 1, Array 2 and 3). Each pass cuts the number of active sorted buffers in half while doubling their size, continuing until only one fully merged array remains.

## ⏱️ Theoretical Time Complexity Overview
* **Method 1 (Repeated Sequential)**:
  Merging an accumulated array of size $i \times n$ with a new array of size $n$ takes $\mathcal{O}(in)$ operations. Summing this cost across all $k-1$ steps yields:
  \[\text{Total Cost} = \sum_{i=1}^{k-1} (i+1)n = n \left( \frac{k(k+1)}{2} - 1 \right) \implies \mathbf{\mathcal{O}(nk^2)}\]
* **Method 2 (Pairwise Tree)**:
  The balanced tree has a maximum depth of $\log_2 k$ levels. At every level of the tree, the total number of elements processed across all active merge operations is exactly $k \times n$.
  \[\text{Total Cost} = \text{Tree Depth} \times \text{Work Per Level} \implies \mathbf{\mathcal{O}(kn \log k)}\]

## 📊 Gnuplot Pipeline Interface
The C code uses standard streams to send the tracked operation counts directly to Gnuplot:
```c
fprintf(gnuplotPipe, "set title 'k-Way Merging Computational Scalability'\n");
fprintf(gnuplotPipe, "plot '-' with lines lw 2 title 'Repeated Sequential', '-' with lines lw 2 title 'Pairwise Tree'\n");
```
The plot highlights the contrast between the two approaches, showing Method 1 climbing along a steep quadratic curve, while Method 2 follows a much more efficient linear-logarithmic path.

## 🛠️ Compilation & Execution
Compile using GCC and run the generated executable:
```bash
gcc q3.c -o q3.exe
./q3.exe
```

## 🏁 Conclusion
The performance comparison demonstrates that Method 1 scales quadratically ($\mathcal{O}(nk^2)$), making it highly inefficient as the number of arrays ($k$) increases. Method 2 optimizes the execution path to logarithmic scale ($\mathcal{O}(kn \log k)$), meeting the theoretical lower bound for comparison-based merging and highlighting the clear advantage of divide-and-conquer design principles.
