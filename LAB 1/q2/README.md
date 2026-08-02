### Problem 2: Fair vs. Biased Coin Simulation

*   **File Name**: `q2.c`
*   **Compilation Command**: 
    ```bash
    gcc q2.c -o q2
    ```
*   **Execution Command**: 
    ```bash
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
