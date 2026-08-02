# DAA--LAB-B125111
# Design and Analysis of Algorithms (DAA) - Lab 1

## 👤 Student Information
*   **Name**: Sanghamitra Moharatha
*   **Student ID**: B125111
*   **Institution**: International Institute of Information Technology, Bhubaneswar (IIIT BBSR)
*   **Course**: Design and Analysis of Algorithms (DAA) Lab

---

## 🚀 Lab Module Overview & Summary
This repository contains a comprehensive set of operational C implementations and data profiling engines for six foundational computational problem blocks. The objective of this lab is to explore algorithmic complexities, asymptotic behaviors, stochastic empirical modeling, and sorting structures, transitioning theoretical concepts into practical code.

### 🛠️ Core Engineering Tools Used
1.  **Programming Language**: ISO C (Standard C Runtime Engine).
2.  **Environment & Compiler**: **MSYS2 (MinGW 64-bit / UCRT64)** running the **GCC** toolchain compiler framework.
3.  **Graphics API**: **SDL2 (Simple DirectMedia Layer)**. This cross-platform hardware-accelerated rendering pipeline was embedded directly into the C architecture to generate live performance trend curves and scatter-plots inside distinct interactive OS windows, bypassing external visualization spreadsheet dependency.

### 📦 Development Environment Setup
To initialize the development dependencies on your local machine, open your MSYS2 terminal shell environment and install the required tools:
```bash
# Install the native C/C++ GCC Compiler Toolchain
pacman -S mingw-w64-x86_64-toolchain

# Install the SDL2 Graphics Development Packages
pacman -S mingw-w64-x86_64-SDL2
```

---

## 📘 Detailed Problem Breakdown

### Problem 1: Put Them in Order (Asymptotic Growth)

*   **File Name**: `q1.c`
*   **Compilation & Execution**:
    ```bash
    gcc q1.c -o q1 -lm
    ./q1
    ```

#### 💡 Algorithmic Technique Used
This program focuses on evaluating and sorting a set of 12 distinct mathematical functions according to their **asymptotic growth rates** (Big-O notation). 
*   **High-Precision Numerical Profiling**: Functions like $3^n$ or $n^{\log_2 n}$ scale exponentially and easily overflow standard memory architectures. The code utilizes high-precision `double` floating-point containers to safely evaluate and handle massive limits up to roughly $1.7 \times 10^{308}$ at a threshold of $n = 1000$.
*   **Structural Binding & Quick Sort (`qsort`)**: To automate ordering, each function's string formula is structurally tied to its calculated numerical value in a custom `Func` array. The complete set is then organized using C's native quicksort algorithm (`qsort()`).
*   **Safe Comparison Hook**: The sort engine leverages a safe-difference comparison method, `(diff > 0) - (diff < 0)`. This pattern safely normalizes the `double` floating-point differences into exact integer return values (`-1`, `0`, or `1`), completely eliminating data truncation bugs.

#### 📊 Asymptotic Growth Comparison Table
When $n \to \infty$, lower-order terms and constant coefficients lose significance, leaving the dominant term to dictate the long-term scaling performance. The table below ranks the functions in definitive **increasing order of growth** (from slowest growth to fastest growth):

| Rank | Function Label | Complexity Class (Big-O) | Description / Asymptotic Behavior |
| :--- | :--- | :--- | :--- |
| **1** | $1 / n$ | $O(n^{-1})$ | **Decreasing**: The only function that shrinks toward $0$ as $n$ scales up. |
| **2** | $\log_2(n)$ | $O(\log n)$ | **Logarithmic**: Extremely slow, highly efficient growth curve. |
| **3** | $12 * \sqrt{n}$ | $O(n^{0.5})$ | **Sub-linear**: Fractional power ($n^{0.5}$); beats $\log_2(n)$ over time. |
| **4** | $50n^{0.5}$ | $O(n^{0.5})$ | **Sub-linear**: Same growth class as $12\sqrt{n}$, but larger due to the coefficient. |
| **5** | $n^{0.51}$ | $O(n^{0.51})$ | **Sub-linear**: Slightly higher exponent than $0.5$; will eventually overtake both. |
| **6** | $2^{32} * n$ | $O(n)$ | **Linear**: Even with a massive constant coefficient ($2^{32}$), it scales linearly. |
| **7** | $n * \log_2(n)$ | $O(n \log n)$ | **Linearithmic**: Slightly faster than linear growth due to the log multiplier. |
| **8** | $n^2 - 324$ | $O(n^2)$ | **Quadratic**: Lower-order constant offset becomes irrelevant at scale. |
| **9** | $100n^2 + 6n$ | $O(n^2)$ | **Quadratic**: Dominated strictly by $n^2$; tracks higher than $n^2 - 324$ via its constants. |
| **10** | $2n^3$ | $O(n^3)$ | **Cubic**: Outpaces all quadratic expressions rapidly as $n$ increases. |
| **11** | $n^{\log_2 n}$ | Super-Polynomial | **Quasi-Exponential**: Rewritten as $2^{(\log_2 n)^2}$, completely leaving polynomials behind. |
| **12** | $3^n$ | $O(3^n)$ | **Exponential**: The fastest, most aggressive growth class in the set. |

---

### Problem 2: Fair vs. Biased Coin Simulation

*   **File Name**: `q2.c`
*   **Compilation & Execution**:
    ```bash
    gcc q2.c -o q2
    ./q2
    ```

#### 💡 Algorithmic Technique Used
This program constructs an empirical testing engine to validate probability theory using a computational framework known as a **Monte Carlo Simulation**.
*   **Pseudo-Random Sequence Seeding**: Real computers cannot naturally generate spontaneous random choices. The program initializes a pseudo-random integer sequence by seeding the engine with the Unix epoch system clock time in seconds (`srand(time(NULL))`). This guarantees that every execution yields completely unique, fresh results.
*   **Interval Transformation and Geometric Weighting**: The native `rand()` function returns arbitrary integers between `0` and a massive platform limit (`RAND_MAX`). The program divides `rand()` by `RAND_MAX` to transform this range into a continuous, high-precision floating decimal between `0.0` and `1.0`. It then establishes clear mathematical boundaries to simulate real-world probability outcomes:
    *   **Fair Coin Setup**: A threshold bounding window is set at `< 0.5`. Any random decimal falling within this window registers as a **HEAD**, which naturally occurs exactly 50% of the time.
    *   **Biased Coin Setup**: The threshold bounding window is expanded to `< 0.7`. This weights the distribution to register a **HEAD** exactly 70% of the time.

#### 📊 Convergence and the Law of Large Numbers
Small sample sizes (like flipping a coin 10 times) are heavily skewed by temporary variance or "luck." To eliminate this discrepancy, this engine loops the simulation **1,000,000 times**. According to the **Law of Large Numbers**, as the volume of independent trials increases, the experimental frequency will perfectly flatten out and converge to the true theoretical probability. 

The application outputs an explicit evaluation summary mapping the convergence:

| Coin Type | Implemented Threshold | Execution Iterations | Expected Theoretical P(Head) | Sample Experimental Output |
| :--- | :--- | :--- | :--- | :--- |
| **Fair Coin** | `r < 0.5` | 1,000,000 tosses | **0.5000 (50%)** | `0.5002` (99.9% accurate) |
| **Biased Coin** | `r < 0.7` | 1,000,000 tosses | **0.7000 (70%)** | `0.6998` (99.9% accurate) |

---

### Problem 3: Performance Analysis of Bubble Sort (With SDL2 Plotting)

*   **File Name**: `q3.c`
*   **Compilation & Execution**: 
    ```bash
    gcc q3.c -o q3 -lSDL2
    ./q3
    ```

#### 💡 Algorithmic Technique Used
This program analyzes and profiles the operational efficiency gap between two design variations of the Bubble Sort algorithm:
1.  **Standard Variant (Full Passes)**: Implements rigid, fixed nested loops. It forces the program to execute a fixed \(O(n^2)\) quadratic pass volume of exactly \(\frac{n(n-1)}{2}\) comparisons, regardless of how randomized or pre-sorted the data is.
2.  **Optimized Variant (Early Stop)**: Introduces a state tracking flag (`swapped`) initialized to `0` at the start of each outer pass. If an entire inner loop pass finishes without executing a single swap, it proves the array is already fully sorted. The program immediately breaks out of execution early, reducing the time complexity to a linear \(O(n)\) best-case profile.

#### 🎨 How SDL2 Was Used to Generate the Plot
Instead of relying on external charting programs like Excel, the C code interfaces directly with the **SDL2 (Simple DirectMedia Layer)** hardware-accelerated rendering pipeline to draw the performance curve inside a live interactive window:
*   **Data Aggregation**: The program runs benchmarks on random arrays scaling from $n = 100$ to $n = 2000$. It continuously logs the exact comparison counters into an array of structural data points (`DataPoint`).
*   **Coordinate Scaling & Normalization**: The maximum array size (`max_x`) and the highest counted comparison number from the unoptimized run (`max_y`) are used as baseline denominators. Raw mathematical coordinates are converted into relative percentages (`data[i].size / max_x`) so that the lines scale dynamically to fit any window dimension flawlessly.
*   **Y-Axis Inversion Mapping**: By default, computer operating systems orient pixel coordinates starting from the top-left corner $(0,0)$, counting downwards. To make the graph grow upwards traditionally, the code maps the pixel position by subtracting the scaled value from the boundary margins:
    $$\text{Screen } Y = (\text{WINDOW\_HEIGHT} - \text{MARGIN}) - \text{Scaled Data Value}$$
*   **Vector Path Rendering**: A `while` event loop handles system windows management to prevent freezing. The engine clears the screen to white, outlines a black coordinate grid axis using `SDL_RenderDrawLine`, and steps through the dataset to connect consecutive plot segments. The standard unoptimized runtime trajectory is drawn as a **Red Line**, while the optimized early-termination path is drawn as a **Blue Line**, visually charting the widening optimization gap.

---

### Problem 4: Towers of Hanoi Simulation (With SDL2 Plotting)

*   **File Name**: `q4.c`
*   **Compilation & Execution**: 
    ```bash
