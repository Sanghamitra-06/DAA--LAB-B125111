# Data Structures & Algorithms Analysis (DAA) Laboratory

This repository contains C implementations and visual performance verification scripts for foundational algorithmic engineering problems. The suite focuses on verifying theoretical worst-case asymptotic bounds using real-time data streams piped directly into **Gnuplot** from compiled C applications.

---

## 🏗️ Prerequisites & Environment Setup

To compile the C source files and render the interactive graphs, your system must have a C compiler (`gcc`) and **Gnuplot** installed and configured in your system's PATH.

### 🪟 Windows (MSYS2 / MinGW64 Terminal)
Open your MinGW64 terminal and run the following commands to install dependencies:
```bash
pacman -S mingw-w64-x86_64-gcc
pacman -S mingw-w64-x86_64-gnuplot
```

### 🐧 Linux (Ubuntu / Debian)
```bash
sudo apt update
sudo apt install build-essential gnuplot
```

### 🍎 macOS
```bash
brew install gcc gnuplot
```

---

## 📂 Laboratory Questions Directory

### 📝 Question 1: Dictionary ADT Structure Profiler

#### 📋 Overview
An evaluation dashboard using C structures (`struct`) to contrast **seven primary dictionary operations** across **six linear layout designs**: Unsorted Array, Sorted Array, Singly Unsorted List, Singly Sorted List, Doubly Unsorted List, and Doubly Sorted List.

#### 🧠 Algorithmic Logic
The code maps out the entire theoretical complexity table using structural data matrices. It tracks input data elements spanning from $N=1$ to $100$. A `switch-case` block matches internal structural complexity states (`CONSTANT`, `LOGARITHMIC`, `LINEAR`) to generate the theoretical curve shapes:
* `CONSTANT`: Emulates static performance profiles $\mathcal{O}(1)$.
* `LOGARITHMIC`: Evaluates `log2(n)` scaling configurations modeling $\mathcal{O}(\log n)$.
* `LINEAR`: Evaluates linear diagonal lines modeling $\mathcal{O}(n)$.

#### 📊 Gnuplot Architecture
Pipes configurations using a $2 \times 3$ grid layout (`set multiplot layout 2,3`). It plots the 7 dictionary operational vectors simultaneously on 6 separated graphs representing each distinct linear structure data layout, bounded safely under an uniform vertical scale (`set yrange [0:110]`) for immediate structural contrast.

#### 💻 Compilation & Running
```bash
# Compile and link the math library explicitly
gcc q1.c -o q1.exe -lm

# Run the program
./q1.exe
```

---

### 📝 Question 2: Modified 3-Way Merge Sort

#### 📋 Overview
A programmatic comparison between the standard **2-Way Merge Sort** and a modified **3-Way Merge Sort** that divides arrays into thirds instead of halves, recursively sorts each third, and stitches them back together under worst-case (reverse-sorted) conditions.

#### 🧠 Algorithmic Logic
* **2-Way Sort**: Splits the tracking block using a single median index: $m = l + \frac{r-l}{2}$.
* **3-Way Sort**: Computes two separate internal offsets to divide working subarrays cleanly into thirds:
  ```c
  int dim = (high - low) / 3;
  int mid1 = low + dim;
  int mid2 = low + 2 * dim;
  ```
  The merge subroutine runs a three-pointer comparison routine that scans the fronts of all three dynamic array blocks simultaneously, extracting the absolute minimum using optimized, nested conditional checks.

#### 📊 Gnuplot Architecture
Splits the graphics layout into a $1 \times 2$ grid:
1. **Left Plot**: Compares raw operational counters (comparisons + moves) against array size.
2. **Right Plot**: Validates complexity ratios ($Ops / [n \cdot \log(n)]$). Because standard C does not have a native `log3()` function, it applies the mathematical change-of-base rule to prevent compiler errors:
   ```c
   double log3_val = log((double)data[i].n) / log(3.0);
   double density = data[i].three_way_ops / ((double)data[i].n * log3_val);
   ```
   The resulting horizontal flat lines visually validate the exact asymptotic bounds calculated in the analysis.

#### 💻 Compilation & Running
```bash
# Compile and link the math library explicitly
gcc q2.c -o q2.exe -lm

# Run the program
./q2.exe
```

---

### 📝 Question 3: $k$-Way Sorted Array Merging Strategies

#### 📋 Overview
An evaluation of two distinct methodologies for combining $k$ independently pre-sorted arrays (each holding $n$ items) into a single, fully unified sorted output array of size $k \times n$.

#### 🧠 Algorithmic Logic
* **Method 1 (Repeated Sequential Merging)**: Implements an accumulator workflow. It initializes the final buffer with the first array, then sequentially loops through arrays $1$ to $k-1$, continually merging the growing output array with the next incoming array of size $n$.
* **Method 2 (Pairwise Divide & Conquer Merging)**: Implements a tree-structured workflow. It loops through active pointers and merges adjacent arrays in pairs. Each layer pass cuts the total number of independent working arrays in half while doubling their sizes, replicating a bottom-up Merge Sort tree.

#### ⏱️ Asymptotic Analysis & Performance Ratios
* **Method 1**: Summarized across all sequential steps as an arithmetic progression:
  $$\sum_{i=1}^{k-1} (i+1)n = n \left( \frac{k(k+1)}{2} - 1 \right) \implies \mathbf{\mathcal{O}(nk^2) \text{ [Quadratic Cost]}}$$
* **Method 2**: Matches a balanced tree of depth $\log_2 k$ processing a total volume of $k \cdot n$ items per level:
  $$\text{Total Cost} = \text{Tree Depth} \times \text{Work Per Level} \implies \mathbf{\mathcal{O}(kn \log k) \text{ [Logarithmic Optimal Cost]}}$$

#### 📊 Gnuplot Architecture
Pipes operation tracking boundaries straight to a plot comparing the two approaches. Method 1 displays a steep quadratic curve, whereas Method 2 exhibits a highly scalable, stable linear-logarithmic slope trajectory.

#### 💻 Compilation & Running
```bash
# Compile the code
gcc q3.c -o q3.exe

# Run the program
./q3.exe
```
*(Note: Since Question 3 does not use transcendental functions like `log()`, the `-lm` linker flag can be safely omitted during its compilation step).*

---

## 🛠️ Global Troubleshooting Notes

* **Executable default filename (`a.exe`)**: If you compile code without the output flag (e.g., `gcc q3.c`), the compiler generates `a.exe`. Always ensure you use `-o name.exe` to name the file explicitly.
* **Linker Error (`undefined reference to 'log' or 'log2'`)**: This happens if the math library flag is placed before the source files or forgotten entirely. Always position `-lm` at the **very end** of your compilation string: `gcc source.c -o binary.exe -lm`.
* **Gnuplot Pipeline Fails**: Ensure Gnuplot is added to your Windows Environment variables or Linux system path. Typing `gnuplot` directly into your terminal should bring up its interactive prompt. If it does not, verify your system path variable installation rules.
