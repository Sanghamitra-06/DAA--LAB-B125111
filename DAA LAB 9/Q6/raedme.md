# Reorganize String K-Distance Apart

## 💡 Core Logic & Algorithm
The objective is to rearrange a string so that identical characters are separated by a distance of at least $K$.

1. **Frequency Counting:** The algorithm counts the occurrences of each character and pushes them into a Max-Heap based on frequency.
2. **Greedy Highest-First Choice:** In each step, the character with the highest remaining frequency is popped and appended to the output string.
3. **Queue-Based Cooldown:** Popped characters cannot be reused immediately. They are placed into a cooling-off queue.
4. **Lock Release:** A character remains locked in the queue until the string grows by $K$ characters. Once $K$ positions have passed, the character is popped from the queue and re-inserted into the max-heap if its remaining count is greater than 0.
5. **Failure Condition:** If the max-heap becomes empty before the string is completely constructed, it is mathematically impossible to satisfy the distance requirement.

## 📊 Complexity Analysis
* **Time Complexity:** $\mathcal{O}(n \log \Sigma)$ where $n$ is the string length and $\Sigma$ is the alphabet size. Since $\Sigma \leq 256$ (constant text bounds), this reduces to an effective time complexity of $\mathcal{O}(n)$.
* **Space Complexity:** $\mathcal{O}(n + \Sigma) = \mathcal{O}(n)$ for the result allocation buffers and queue structures.
