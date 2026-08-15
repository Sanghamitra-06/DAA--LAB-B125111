# Advanced Algorithms Analysis, Design, and Implementation Suite

This repository contains a comprehensive collection of advanced algorithmic paradigms, formal correctness proofs, and architectural descriptions. Each module explores critical aspects of data analysis, optimal partitioning, divide-and-conquer strategy engineering, and theoretical complexity boundaries.

## 🛠️ Global Technology Stack & Tooling
* **Programming Language:** C (Standard Compliance: C99 / C11)
* **Compiler Framework:** GCC (GNU Compiler Collection) or any standard standard-compliant C toolchain.
* **Compilation Command Template:** `gcc -Wall -Wextra -O2 <filename>.c -o <output_executable>`
* **Benchmarking Strategy:** To keep tests independent of operating system process scheduling, CPU frequency states, or hardware thermal throttling, algorithmic efficiency is verified by counting discrete primitive operations (such as data comparisons or scale weight balances) using dedicated runtime counters.
* **Repository Layout Structure:**
  * `src/` - Contains all separate standalone executable `.c` verification source files.
  * `README.md` - Master technical overview and algorithmic documentation.

---

## 📂 Module-by-Module Technical Overview and Architecture

### 1. Binary vs. Ternary Search Analysis

#### 📝 Algorithmic Logic
Both strategies operate exclusively on pre-sorted linear structures, but utilize completely different branching mechanics:
* **Binary Search:** Splits the search window into two equal halves ($n/2$) using a single midpoint element ($mid$). It eliminates one full partition per conditional test.
* **Ternary Search:** Divides the array into three equal intervals ($n/3$) via two midpoints ($mid1$ and $mid2$). It requires two sequential conditional comparisons per iteration loop to determine which sub-segment contains the target element.

#### ⚙️ Implementation Strategy
While Ternary Search reduces the total number of nested index iterations ($\log_3 n$ vs $\log_2 n$), it incurs a significantly higher total comparison cost. Mathematically, the worst-case comparison upper bounds evaluate as follows:
* **Binary Search Comparisons:** $C_{\text{binary}}(n) = 1 \cdot \log_2 n \approx 1.442 \ln n$
* **Ternary Search Comparisons:** $C_{\text{ternary}}(n) = 2 \cdot \log_3 n = 2 \cdot \frac{\ln n}{\ln 3} \approx 1.820 \ln n$

Ternary Search demands approximately **26.2% more operational comparisons** than Binary Search under identical worst-case search parameters, proving Binary Search's architectural superiority.

#### 📄 Implementation Script Reference
* **Implementation File Path:** `src/binary_vs_ternary.c`
* **Verification Design:** The tracking engine passes counter pointers into both functions to catch the exact primitive statement boundaries encountered during numerical target evaluations.

---

### 2. Search for the Defective Coin

#### 📝 Algorithmic Logic
The objective is to discover a single potentially underweight (defective) coin out of a pile of $n$ coins using a two-pan balance weighing scale within a strict bound of $\log_2 n + c$ operations. 

#### ⚙️ Implementation Strategy
The strategy relies on a specialized binary divide-and-conquer division pattern:
1. **Divide:** The active coin collection of size $m$ is divided into two groups of equal size $\lfloor m/2 \rfloor$. If $m$ is odd, one coin is set aside as a static pivot element.
2. **Weigh:** Place the two equal groups on the balance scale pans.
3. **Conquer:** 
   * *Scale Imbalance:* The lighter side contains the defective coin. Recursively search that specific half.
   * *Scale Balance:* Both sides have identical weights, proving all weighed coins are genuine. If $m$ was even, no defective coin exists. If $m$ was odd, the isolated pivot coin is flagged as the defective coin.
4. **Base Case Verification ($c$):** When the search field narrows down to a single suspect coin, it is verified against a known genuine coin. This introduction of a single extra validation check establishes the positive runtime constant factor $c = 1$.

#### 📄 Implementation Script Reference
* **Implementation File Path:** `src/defective_coin.c`
* **Verification Design:** Implements recursive block segmentations and tracks accumulation weights across sub-ranges to simulate balance pan balances.

---

### 3. Max and Min using Divide and Conquer Approach

#### 📝 Algorithmic Logic
Finding the minimum and maximum of an array sequentially requires $2n - 2$ total comparisons. By switching to a parallel tournament-style divide-and-conquer strategy, we can reduce this requirement to exactly $\lfloor \frac{3n}{2} \rfloor - 2$ operations.

#### ⚙️ Implementation Strategy
The algorithm splits the array recursively into equal halves until it strikes one of the base cases:
* **Base Case 1:** The subarray spans exactly 1 element. This element is returned as both the local minimum and maximum ($0$ comparisons).
* **Base Case 2:** The subarray spans exactly 2 elements. They are compared directly against each other to set the local minimum and maximum ($1$ comparison).
* **Recursive Path:** Subarrays larger than 2 elements are bisected ($mid = low + \frac{high-low}{2}$), computing separate minimums and maximums for the left and right spaces. These parameters are synthesized at the parent level using exactly 2 comparisons: one to find the global maximum and one to find the global minimum.

The global recurrence relation solves to $T(n) = 2T(n/2) + 2$, validating the $\frac{3n}{2} - 2$ performance boundary.

#### 📄 Implementation Script Reference
* **Implementation File Path:** `src/max_min_dc.c`
* **Verification Design:** Uses dual-pointer reference feedback matrices to capture and combine regional high/low parameters at every parent synthesis node.

---

### 4. Matrix Multiplication using Strassen’s Method

#### 📝 Algorithmic Logic
Standard matrix multiplication operates on an $O(n^3)$ cubic time envelope due to its three nested loops. Strassen's technique re-engineers sub-block cross-multiplications, dropping the number of recursive multiplication branches from 8 down to 7. This shifts the overall asymptotic time complexity down to $O(n^{\log_2 7}) \approx O(n^{2.81})$.

#### ⚙️ Implementation Strategy
The algorithm divides the $n \times n$ matrices into four equal quadrants of dimensions $\frac{n}{2} \times \frac{n}{2}$. It computes 7 distinct joint matrix products ($P_1$ through $P_7$) via linear matrix additions and subtractions. These products are then linearly combined to build the output quadrants, eliminating the eighth multiplication step.

#### 📄 Implementation Script Reference
* **Implementation File Path:** `src/strassen.c`
* **Verification Design:** Implements block factorization layouts optimized around core $2 \times 2$ algebraic base multiplication matrix transforms.

---

### 5. Multiply Special-Pattern Square Matrices

#### 📝 Algorithmic Logic
This module operates on structural $n \times n$ matrices where $n = 2^k$, exhibiting a recursive quadrant symmetry where the diagonal sub-blocks are completely identical and the off-diagonal sub-blocks are completely identical:

#### ⚙️ Implementation Strategy
A standard divide-and-conquer matrix expansion needs four distinct subproblem products ($A_1B_1, A_2B_2, A_1B_2, A_2B_1$), leading to an execution boundary of $O(n^{\log_2 4}) = O(n^2 \log n)$. 

To optimize this down to a true linear-quadratic bound of $O(n^2)$, the algorithm uses an algebraic transformation that drops the number of recursive operations from 4 to 2:
1. Compute the subproblem matrix sum product: $P_1 = (A_1 + A_2)(B_1 + B_2)$
2. Compute the subproblem matrix difference product: $P_2 = (A_1 - A_2)(B_1 - B_2)$

The final quadrant values are then resolved using basic addition and subtraction:
* $C_{11} = C_{22} = \frac{P_1 + P_2}{2}$
* $C_{12} = C_{21} = \frac{P_1 - P_2}{2}$

#### Complexity Analysis
The recurrence relation for this optimized approach maps out as:
$$T(n) = 2T(n/2) + \Theta(n^2)$$
Applying Case 3 of the Master Theorem ($\log_b a = \log_2 2 = 1 < 2$), the linear-quadratic partitioning work $\Theta(n^2)$ dominates the runtime profile, simplifying the total complexity to **$\Theta(n^2)$**.

#### 📄 Implementation Script Reference
* **Implementation File Path:** `src/pattern_multiply.c`
* **Verification Design:** Dynamically maps symmetric blocks to avoid redundant memory allocations during recursive matrix splits.

---

### 6. Use of Loop Invariants in Sorting

#### 📝 Selection Sort Pseudocode (1-Based Indexing)
```text
SELECTION-SORT(A, n)
1. For i = 1 to n - 1
2.     min_idx = i
3.     For j = i + 1 to n
4.         if A[j] < A[min_idx]
5.             min_idx = j
6.     exchange A[i] with A[min_idx]
```

#### ⚙️ Formal Correctness Proof via Invariant Evaluation
* **Invariant Specification:** At the start of each iteration of the outer loop (line 1), the sorted prefix subarray $A[1 \cdots i-1]$ consists of the $i-1$ smallest elements originally present in the global array, sorted in ascending order.
* **Initialization:** Prior to the first loop pass ($i = 1$), the prefix array translates to $A[1 \cdots 0]$, which is empty. This vacuously satisfies the sorting criteria and correctly represents the 0 smallest elements.
* **Maintenance:** During iteration $i$, the inner loop scans the remaining unsorted suffix array $A[i \cdots n]$ to identify the absolute minimum value's index (`min_idx`). Swapping $A[i]$ with $A[\text{min\_idx}]$ guarantees that the element now at index $i$ is greater than or equal to all elements in the sorted prefix $A[1 \cdots i-1]$ and less than or equal to all elements in the remaining suffix $A[i+1 \cdots n]$. When $i$ increments to $i + 1$, the sorted prefix array expands to safely include this new element, maintaining the invariant.
* **Termination:** The loop terminates precisely when $i = n$. Evaluating the invariant at termination states that the prefix subarray $A[1 \cdots n-1]$ contains the $n-1$ smallest elements of the array in sorted order. By extension, the single remaining element left at index $A[n]$ must be the largest value in the collection, leaving the entire array successfully sorted.

#### Runtime Analysis
* **Outer Loop Range Boundary Justification:** The algorithm terminates at $n-1$ elements because placing $n-1$ items in their correct relative positions automatically leaves the final element at index $n$ as the maximum remaining value. Running an extra iteration for the final element would be completely redundant.
* **Worst-Case Runtime Complexity:** $\Theta(n^2)$. The nested loops execute a deterministic number of comparisons equal to $\frac{n(n-1)}{2}$, regardless of input permutations.
* **Best-Case Runtime Complexity:** $\Theta(n^2)$. Even if the array is provided fully sorted, the inner loop must still scan all remaining elements to verify the local minimum during each iteration.

#### 📄 Implementation Script Reference
* **Implementation File Path:** `src/selection_sort.c`
* **Verification Design:** Implements the deterministic sorting boundary sequence on standard linear memory layouts to showcase consistent comparison operations.
