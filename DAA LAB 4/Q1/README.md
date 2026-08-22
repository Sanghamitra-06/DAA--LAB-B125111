# 📌 Problem 1: Application of Sorting-I (Stable Color Sort)

### 🛑 Problem Statement
Given an array of $n$ item pairs where each item has a number and a color ("red", "blue", or "yellow"). The array is initially sorted completely by the number field. Sort the items by color in $O(n)$ time such that the final order is Red $\rightarrow$ Blue $\rightarrow$ Yellow, while keeping items of the same color sorted by their original numerical order.

### 💡 Algorithmic Logic
We use an optimized **Counting Sort** strategy with frequency prefixes. Because the input values are already sorted numerically, a linear scan from left to right preserves the initial order for elements sharing the same color prefix—guaranteeing structural stability.

1. **Frequency Count**: Count the total occurrences of each color code (`RED`, `BLUE`, `YELLOW`).
2. **Prefix Offsets**: Compute the exact starting array boundaries for each color:
   * Reds start at index `0`.
   * Blues start right after the Reds at index `red_count`.
   * Yellows start right after the Blues at index `red_count + blue_count`.
3. **Stable Distribution**: Traverse the array from left to right. Place each item directly into its target calculated offset position inside a temporary memory space, then increment that specific pointer position.

### 📋 Step-by-Step Dry Run
Let's trace using a 4-element array where colors are mapped as **RED (0) → BLUE (1) → YELLOW (2)**.
* **Input Array**: `[(1, BLUE), (2, RED), (3, BLUE), (4, YELLOW)]`

1. **Count Frequencies**:
   * Loop through array to find counts: `counts = {RED: 1, BLUE: 2, YELLOW: 1}`
2. **Compute Starting Indices**:
   * `starting_indices = {RED: 0, BLUE: 1, YELLOW: 3}`
3. **Stable Placement (Left to Right)**:
   * **Element 1 `(1, BLUE)`**: Place at `starting_indices[BLUE]` (Index 1). Increment index to 2.
   * **Element 2 `(2, RED)`**: Place at `starting_indices[RED]` (Index 0). Increment index to 1.
   * **Element 3 `(3, BLUE)`**: Place at `starting_indices[BLUE]` (Index 2). Increment index to 3.
   * **Element 4 `(4, YELLOW)`**: Place at `starting_indices[YELLOW]` (Index 3). Increment index to 4.
* **Final Output Space**: `[(2, RED), (1, BLUE), (3, BLUE), (4, YELLOW)]` *(Notice that `(1, BLUE)` remains before `(3, BLUE)`, proving stability).*
