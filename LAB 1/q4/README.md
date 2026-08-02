## Problem 4: Towers of Hanoi Simulation (With SDL2 Plotting)

*   **File Name**: `q4.c`
*   **Compilation Command**: 
    ```bash
    gcc q4.c -o q4 -lSDL2
    ```
*   **Execution Command**: 
    ```bash
    ./q4
    ```

#### 💡 Algorithmic Technique Used
The Towers of Hanoi puzzle serves as a classic demonstration of divide-and-conquer exponential growth complexity $O(2^n)$. 
*   **Mathematical Recurrence**: The move sequences trace the absolute mathematical relation $T(n) = 2T(n-1) + 1$, establishing that the total operations needed to solve a puzzle of $n$ discs is exactly $2^n - 1$.
*   **64-Bit Bitwise Acceleration**: To eliminate the heavy call-stack memory footprint of deep recursive function executions, the program leverages high-performance 64-bit bitwise shifting (`1LL << n`). This evaluates the exact theoretical growth values instantly for disc counts all the way up to $n = 25$.

#### 🎨 How SDL2 Was Used to Generate the Plot
The application integrates with the **SDL2** rendering context to draw the exponential growth path:
*   **Exponential Coordinate Scaling**: At 25 discs, the operation count peaks at an immense $33,554,431$ moves. The code handles this massive vertical scale by creating a relative ratio framework that maps the data down into precise, uniform pixel dimensions.
*   **Inverted Canvas Axis Mapping**: Just like in Problem 3, the Y-axis coordinates are flipped using a boundary offset calculation (`WINDOW_HEIGHT - MARGIN`) to force the curve to rise upward naturally rather than extending downward from the top-left screen margin.
*   **Continuous Vector and Node Graphing**: Inside an active display render loop, the engine draws solid black coordinate axes. It then iterates across the dataset to link consecutive calculated positions via `SDL_RenderDrawLine` in a striking **Blue Line**. Simultaneously, the code builds geometric node tracking markers at every discrete intersection point by drawing filled squares (`SDL_RenderFillRect`) in a bright **Red Color**, perfectly recreating a professional scatter-line plot layout.
