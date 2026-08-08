# Question 1: Dictionary Abstract Data Type (ADT) Profiler

This project evaluates and visualizes the worst-case asymptotic complexities (\(\mathcal{O}\)) of seven primary dictionary operations across six linear data structure implementations.

## 📋 Problem Description
Analyze and plot the order of growth for the primary operations (**Search, Insert, Delete, Max, Min, Predecessor, Successor**) when implemented using:
* An unsorted array.
* A sorted array.
* A singly linked unsorted list.
* A singly linked sorted list.
* A doubly linked unsorted list.
* A doubly linked sorted list.

## 🧠 Algorithmic Logic & Implementation
The program encapsulates the operational specifications inside a custom C structure array:
* **The Structure Array (`DataStructureProfile`)**: Groups data structure names alongside explicit operational growth tokens (`CONSTANT`, `LOGARITHMIC`, `LINEAR`).
* **The Switch-Case Core**: Reads those operational profile tokens from the matrix as the data scale sizes grow ($N=1$ to $100$) and triggers the corresponding function mapping:
  * `CONSTANT`: Evaluates a static height factor modeling $\mathcal{O}(1)$.
  * `LOGARITHMIC`: Calculates `log2(n)` scaling trends modeling $\mathcal{O}(\log n)$.
  * `LINEAR`: Traces standard diagonal growth modeling $\mathcal{O}(n)$.

## ⏱️ Theoretical Time Complexity Overview

| Data Structure | Search | Insert | Delete | Max | Min | Predecessor | Successor |
| :--- | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| **Unsorted Array** | $\mathcal{O}(n)$ | $\mathcal{O}(1)$ | $\mathcal{O}(n)$ | $\mathcal{O}(n)$ | $\mathcal{O}(n)$ | $\mathcal{O}(n)$ | $\mathcal{O}(n)$ |
| **Sorted Array** | $\mathcal{O}(\log n)$ | $\mathcal{O}(n)$ | $\mathcal{O}(n)$ | $\mathcal{O}(1)$ | $\mathcal{O}(1)$ | $\mathcal{O}(1)$ | $\mathcal{O}(1)$ |
| **Singly Unsorted List** | $\mathcal{O}(n)$ | $\mathcal{O}(1)$ | $\mathcal{O}(n)$ | $\mathcal{O}(n)$ | $\mathcal{O}(n)$ | $\mathcal{O}(n)$ | $\mathcal{O}(n)$ |
| **Singly Sorted List** | $\mathcal{O}(n)$ | $\mathcal{O}(n)$ | $\mathcal{O}(n)$ | $\mathcal{O}(1)$ | $\mathcal{O}(1)$ | $\mathcal{O}(n)$ | $\mathcal{O}(1)$ |
| **Doubly Unsorted List** | $\mathcal{O}(n)$ | $\mathcal{O}(1)$ | $\mathcal{O}(1)$ | $\mathcal{O}(n)$ | $\mathcal{O}(n)$ | $\mathcal{O}(n)$ | $\mathcal{O}(n)$ |
| **Doubly Sorted List** | $\mathcal{O}(n)$ | $\mathcal{O}(n)$ | $\mathcal{O}(1)$ | $\mathcal{O}(1)$ | $\mathcal{O}(1)$ | $\mathcal{O}(1)$ | $\mathcal{O}(1)$ |

## 📊 Gnuplot Pipeline Interface
The program opens a secure communication pipeline to Gnuplot using `popen("gnuplot -persistent", "w")`. It dynamically configures a $2 \times 3$ grid using:
```gnuplot
set multiplot layout 2,3 title 'Dictionary Operations Asymptotic Complexities'
set yrange [0:110]
plot '-' with lines lw 2 title 'Search', '-' with lines lw 2 title 'Insert' ...
```
Data coordinates are streamed line-by-line. The end of each curve data stream block is flagged by writing the character sequence `e\n` to the pipeline.

## 🛠️ Compilation & Execution
Compile using GCC and link the standard math module library (`-lm`):
```bash
gcc q1.c -o q1.exe -lm
./q1.exe
```

## 🏁 Conclusion
The generated multiplot window visually proves that un-ordered layouts optimize mutation speeds ($\mathcal{O}(1)$ inserts), whereas sorted layouts optimize boundary and contextual analytical scanning tasks ($\mathcal{O}(1)$ min/max queries). It shows how array bounds offer superior random search parameters ($\mathcal{O}(\log n)$ binary sweeps) at the cost of rigid, high-overhead structural resizing data shifts ($\mathcal{O}(n)$ element moves) during deletes.
