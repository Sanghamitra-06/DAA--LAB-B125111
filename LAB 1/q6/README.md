### Problem 6: Element Uniqueness Checking

*   **File Name**: `q6.c`
*   **Compilation Command**: 
    ```bash
    gcc q6.c -o q6
    ```
*   **Execution Command**: 
    ```bash
    ./q6
    ```

#### 💡 Algorithmic Technique Used
This application addresses the problem of determining whether all elements in a massive array are unique or if duplicates exist.
*   **Presorting Optimization**: Checking for identical elements using a standard nested-loop approach forces a time complexity of $O(n^2)$, which grinds to a halt on large datasets. To fix this, the program utilizes a high-efficiency sorting strategy. It funnels the raw unsorted array data directly into the standard C library quicksort (`qsort`) runtime engine. 
*   **Linear Scan Adjacency Verification**: Sorting rearranges the integers in numerical order, taking $O(n \log n)$ time. This guarantees that any duplicate values present in the data are forced to sit directly next to each other. The algorithm then runs a single linear pass ($O(n)$) to check neighboring indices (`arr[i] == arr[i + 1]`). This combined process scales the entire performance profile down from a sluggish quadratic curve to a fast $O(n \log n)$ operation footprint, allowing it to evaluate large test arrays in fractions of a second.
