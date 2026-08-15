# Module 3: Maximum and Minimum via Tournament Selection

## 1. Algorithmic Overview & Bounding Logic
A naive sequential scan requires $2n - 2$ operations to extract both the global minimum and maximum elements from an array. This module uses a parallelized tournament-style Divide and Conquer pattern to minimize the total operational comparison count to a strict upper bound of $\lfloor \frac{3n}{2} \rfloor - 2$.

## 2. Partitioning Logic & Base Cases
The array is recursively split into symmetric halves until meeting explicit base scenarios:
* **Single Element Sub-array:** If the isolated range length equals 1, that single element is returned as both the local maximum and minimum ($0$ comparisons).
* **Two-Element Sub-array:** If the range length equals 2, the elements are checked directly against each other. The larger becomes the local maximum, and the smaller becomes the local minimum ($1$ comparison).
* **Recursive Bisection:** Larger segments are split into symmetric halves ($mid = low + \frac{high-low}{2}$), triggering concurrent child threads for the left and right spaces.

## 3. Synthesis and Combination Phase
The left subproblem returns `(left_min, left_max)` and the right returns `(right_min, right_max)`. The global values are synthesized using exactly two steps: comparing the two local maximums and comparing the two local minimums. This corresponds to the recurrence relation $T(n) = 2T(n/2) + 2$, bounding the global comparison overhead to $\frac{3n}{2} - 2$.
