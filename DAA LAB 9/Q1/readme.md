# Fractional Knapsack with Deterioration Rate

## 💡 Core Logic & Algorithm
In this variant of the Fractional Knapsack problem, the value density of each item decays over time at a specific linear rate ($\lambda_i$). 

1. **Greedy Metric:** The algorithm computes the initial value density ($v_i / w_i$) for each item.
2. **Sorting Strategy:** Items are sorted in descending order based on their initial value density.
3. **Time Progression Tracking:** As the knapsack is filled sequentially, an internal time counter ($t$) increases by the weight of the items accumulated so far ($t \leftarrow t + \Delta w$).
4. **Dynamic Value Evaluation:** When an item is processed, its contribution is determined by its decayed density at that exact time slot: 
   $$\text{Effective Density} = \max\left(0, \frac{v_i}{w_i} - \lambda_i \cdot t\right)$$
5. **Fractional Selection:** If the knapsack capacity runs out, the maximum possible fraction of the current item is taken before terminating.

## 📊 Complexity Analysis
* **Time Complexity:** $\mathcal{O}(n \log n)$ due to the initial sorting phase of the item array. The linear scanning loop runs in $\mathcal{O}(n)$ time.
* **Space Complexity:** $\mathcal{O}(n)$ or $\mathcal{O}(1)$ depending on whether auxiliary array storage is used for structural sorting.
