# Candy Distribution Problem

## 💡 Core Logic & Algorithm
The goal is to allocate candies to children standing in a line based on their performance ratings, ensuring children with higher ratings get more candies than their immediate neighbors.

1. **Two-Pass Greedy Sweep:** Instead of checking both neighbors simultaneously, the problem is split into two independent directional slope sweeps.
2. **Initialization:** Every child is allocated a minimum baseline of 1 candy.
3. **Left-to-Right Pass:** The array is scanned forward. If child $i$ has a higher rating than child $i-1$, their candy allocation is set to:
   $$\text{candies}[i] = \text{candies}[i-1] + 1$$
4. **Right-to-Left Pass:** The array is scanned backward. If child $i$ has a higher rating than child $i+1$, the allocation is updated to satisfy the right-side condition without breaking the left-side condition:
   $$\text{candies}[i] = \max(\text{candies}[i], \text{candies}[i+1] + 1)$$
5. **Summation:** The total minimum candies required is the sum of the final array values.

## 📊 Complexity Analysis
* **Time Complexity:** $\mathcal{O}(n)$ because it only performs two independent linear sweeps across the dataset.
* **Space Complexity:** $\mathcal{O}(n)$ to maintain the tracking array for candies allocated to each index.
