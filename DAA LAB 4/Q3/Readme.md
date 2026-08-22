# 📌 Problem 3: Application of Sorting-III (k-SUM Problem)

### 🛑 Problem Statement
Given a set $S$ of $n$ elements, find if there exist $k$ elements that sum up to a given target $T$ in $O(n^{k-1})$ time complexity.

### 💡 Algorithmic Logic
We use structural nesting combined with an inner **Two-Pointer** window technique:
1. Sort the entire array $S$ in $O(n \log n)$ time.
2. Set up $k-2$ nested loops to systematically fix the first $k-2$ elements.
3. For the remaining 2 elements, avoid nesting loops further. Instead, initialize a left pointer $L$ at the beginning of the remaining elements and a right pointer $R$ at the end of the array. 
4. Move $L$ inward to increase the sum or $R$ inward to decrease it. This resolves the final two elements in linear $O(n)$ time, bounding the total execution complexity to $O(n^{k-2} \times n) = $O(n^{k-1})$.

### 📋 Step-by-Step Dry Run
Let $S = \{4, 1, 3, 2\}$, $k = 3$, and target $T = 9$.
1. **Sort S**: $S = [1, 2, 3, 4]$.
2. **Loop k-2 = 1 element**:
   * **Iteration 1**: Pick first element index $i = 0$ ($S[0] = 1$). 
   * **New Target**: We need 2 remaining numbers to sum to $T - S[0] = 9 - 1 = 8$.
   * **Two-Pointer Window**: Set $L = 1$ ($S[1]=2$) and $R = 3$ ($S[3]=4$).
   * **Check**: $2 + 4 = 6 < 8$. Move $L$ right ($L = 2$).
   * **Check**: $3 + 4 = 7 < 8$. $L$ meets $R$. No valid pair found for base element `1`.
   * **Iteration 2**: Pick next element index $i = 1$ ($S[1] = 2$).
   * **New Target**: We need 2 remaining numbers to sum to $9 - 2 = 7$.
   * **Two-Pointer Window**: Set $L = 2$ ($S[2]=3$) and $R = 3$ ($S[3]=4$).
   * **Check**: $3 + 4 = 7 == 7$. **Match Found!** The elements are **$\{2, 3, 4\}$**.
