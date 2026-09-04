# Convolution Operation on Vectors

## Logic
Computes the spatial combination of two signals $A$ (size $m$) and $B$ (size $n$). It can be solved using two distinct divide-and-conquer strategies:
1. **Fast Fourier Transform (FFT):** Pads arrays to a uniform base-2 size, maps signals into frequency domains, performs immediate pointwise dot products, and translates them back using Inverse FFT.
2. **Karatsuba Algorithm:** Breaks down arrays into high and low coefficient halves. Algebraically groups cross-terms to reduce 4 recursive sub-multiplications down to 3.

## Analysis of Time & Space
* **FFT Methodology:**
  * **Time Complexity:** $O(n \log n)$ — Follows standard divide-and-conquer butterfly indexing splits where $n \ge m$.
  * **Space Complexity:** $O(n)$ — Requires memory allocation to store real/imaginary complex coordinate structures.
* **Karatsuba Methodology:**
  * **Time Complexity:** $O(n^{\log_2 3}) \approx O(n^{1.585})$ — Bypasses complex algebra while staying significantly faster than a naive $O(n^2)$ loop.
  * **Space Complexity:** $O(n)$ — Relies on stack memory allocations for the recursive call divisions.

## Implementation Method
Recursive processing functions. The FFT variant relies on bit-reversal indexing and trigonometric adjustments, while Karatsuba implements standard array displacement additions.
