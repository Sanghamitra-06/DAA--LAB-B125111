### Problem 3: Performance Analysis of Bubble Sort (With SDL2 Plotting)

*   **File Name**: `q3.c`
*   **Compilation Command**: 
    ```bash
    gcc q3.c -o q3 -lSDL2
    ```
*   **Execution Command**: 
    ```bash
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
