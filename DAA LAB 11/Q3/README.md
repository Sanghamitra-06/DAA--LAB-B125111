# Problem 3: Bidirectional BFS for Shortest Transformation Sequence

## Question Analysis
The objective is to compute the minimum number of single-character mutations needed to transform a given starting string $\mathbf{A}$ into a target string $\mathbf{B}$, utilizing an intermediate dictionary $\mathbf{D}$ containing $N$ unique words of identical length $L$. A mutation is valid if and only if exactly one character changes between consecutive strings (representing a Hamming Distance of exactly 1). 

While a standard Breadth-First Search (BFS) expanding from $\mathbf{A}$ can find the shortest path, its search space expands exponentially as a factor of $b^d$, where $b$ represents the structural branching factor of matching word mutations and $d$ represents the total mutation path distance. 

To optimize this search space, a **Bidirectional BFS** is implemented. The algorithm initiates two simultaneous search perimeters: one working forward from the start word $\mathbf{A}$, and another working backward from the target word $\mathbf{B}$. 

Two separate FIFO queues and two independent distance maps are maintained. At each iterative step, the algorithm dynamically selects the queue containing fewer elements to expand. This step balances the growth of both search frontiers. For each popped word node, the dictionary is evaluated to find unvisited words matching a Hamming distance of 1. If an expanding node from the forward frontier intersects with an already visited node from the backward frontier (or vice-versa), a valid transformation path is completed. The shortest mutation sequence length is calculated as the sum of the distances from both search frontiers.

---

## Time and Space Complexity Analysis

### Time Complexity: $O(N \cdot L \cdot \sqrt{N})$ or $O(b^{d/2})$
- **Hamming Distance Check:** Comparing whether two words differ by exactly one character takes $O(L)$ operations.
- **Frontier Expansion:** In the worst-case scenario, every word in the dictionary must be checked against every other word to find structural neighbors, which takes $O(N)$ steps per expansion.
- **Search Space Reduction:** Traditional unidirectional BFS searches across an exponential growth bubble proportional to $O(b^d)$. By expanding from both ends simultaneously, the search frontiers intersect at approximately half the depth ($d/2$). This reduces the number of state evaluations to $O(b^{d/2}) + O(b^{d/2})$, effectively cutting the geometric search space area down to its square root.
- **Total Time:** Expressed in terms of dictionary dimensions, the worst-case search time scales as $O(N \cdot L \cdot \text{visited nodes})$. Because bidirectional intersection dramatically minimizes the number of visited nodes compared to unidirectional alternatives, the practical time scale remains highly efficient.

### Space Complexity: $O(N \cdot L)$
- **Dictionary Tracking:** Storing $N$ words of length $L$ in memory requires $O(N \cdot L)$ space.
- **Distance Maps:** The two allocation maps tracking discovery states and path lengths require storage space directly proportional to the dictionary size, $O(N)$.
- **Queue Buffering:** The combined structural footprints of both the forward and backward FIFO queues cannot exceed the total number of words in the dictionary, bounding queue space to $O(N)$.
- **Total Space:** The auxiliary runtime memory scales cleanly as $O(N \cdot L)$.
