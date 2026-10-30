# Problem 1: Shortest Path on Parity-Constrained Graphs via 0-1 BFS

## Question Analysis
The objective is to find the shortest path from a source vertex $S$ to all other vertices $v \in V$ in a directed graph where edge weights are restricted to $\{0, 1\}$. The path metric is constrained by an odd-weight edge count parity check: if the total number of weight-1 edges traversed along a path is odd, an extra penalty cost $C \ge 0$ is added to the total weight.

To solve this optimally, the state space is expanded to track both the current vertex and the parity of weight-1 edges traversed so far. Each vertex $u$ is split into two virtual states:
- `(u, 0)`: Reaching vertex $u$ with an **even** number of weight-1 edges.
- `(u, 1)`: Reaching vertex $u$ with an **odd** number of weight-1 edges.

Transitions from a state `(u, p)` to an adjacent vertex $v$ via an edge with weight $w \in \{0, 1\}$ follow these rules:
- If $w = 0$, the next state is `(v, p)` with a transition cost of 0.
- If $w = 1$, the next state is `(v, 1 - p)` with a transition cost of 1.

Because the transition costs are strictly 0 or 1, a standard Dijkstra's algorithm $O(E \log V)$ can be optimized into a **0-1 BFS** using a double-ended queue (Deque). When a cost-0 transition is found, the new state is pushed to the front of the deque; when a cost-1 transition is found, it is pushed to the back. This ensures that the deque remains sorted by distance at all times.

Once the shortest path distances to all virtual states are calculated, the effective cost to any vertex $v$ is determined by finding the minimum of:
- `dist[v][0]` (Even count, no penalty)
- `dist[v][1] + C` (Odd count, penalty $C$ applied)

---

## Time and Space Complexity Analysis

### Time Complexity: $O(V + E)$
- **State Expansion:** The number of states in the virtual graph is $2 \cdot |V|$, which remains linear with respect to the number of vertices.
- **Edge Traversals:** Each virtual edge is examined at most once during the BFS execution. The number of virtual edges is $2 \cdot |E|$.
- **Deque Operations:** Elements are added and removed from the Deque in $O(1)$ constant time. Since each state is processed at most once, the aggregate time spent on queue operations is $O(V)$.
- **Total Time:** Combining these factors results in a strict linear time complexity of $O(V + E)$, bypassing the log-factor overhead of traditional priority-queue-based shortest path methods.

### Space Complexity: $O(V + E)$
- **Graph Representation:** The adjacency list stores $|V|$ vertex heads and $|E|$ edge structures, requiring $O(V + E)$ memory space.
- **Distance Storage:** The distance array requires a fixed size of $2 \cdot |V|$, yielding $O(V)$ space.
- **Deque Memory Allocation:** The maximum concurrent elements stored within the Deque structure cannot exceed the total state space size, consuming $O(V)$ memory.
- **Total Space:** The space layout scales linearly as $O(V + E)$.
