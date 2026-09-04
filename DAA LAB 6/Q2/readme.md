# 2D Square Matrix Operations and Their Complexities

## Logic
Executes standard algebraic manipulations and checks on dynamic $n \times n$ grids via multi-dimensional index loops.
* **Determinant:** Avoids exponential expansion by implementing Gaussian Elimination to systematically reduce rows into an upper triangular structure.
* **Eigen Analysis:** Employs the iterative Power Method to track and scale a dominant direction vector toward stability.

## Analysis of Time & Space
* **Operations (i, iii, iv, vi) - Addition, Zero Check, Symmetry Check, In-Situ Transpose:**
  * **Time Complexity:** $O(n^2)$ — Must visit every cell in the grid exactly once.
  * **Space Complexity:** $O(1)$ auxiliary space as calculations occur within existing array spaces.
* **Operations (v, ii) - Matrix Multiplication, Determinant:**
  * **Time Complexity:** $O(n^3)$ — Driven by row-to-column vector dot products or structural row-reduction operations.
  * **Space Complexity:** $O(n^2)$ for multiplication output storage, or $O(1)$ auxiliary for the row transformations.
* **Operation (vii) - Dominant Eigen Pair:**
  * **Time Complexity:** $O(k \cdot n^2)$ — Where $k$ is the total execution cycles needed to reach convergence.
  * **Space Complexity:** $O(n)$ auxiliary space to preserve intermediate transformation vectors.

## Implementation Method
Dynamic double-pointer allocations (`double **`). Calculations are structured through sequential nested loops mapping the coordinate columns.
