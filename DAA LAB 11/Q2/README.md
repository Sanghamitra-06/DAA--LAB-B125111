# Problem 2: Multi-Source BFS for Radius-Constrained Voronoi Cell Partitioning

## Question Analysis
The goal is to partition an unweighted, undirected graph $G = (V, E)$ into a set of Voronoi cells centered around $K$ designated hub vertices $H = \{h_1, h_2, \dots, h_k\}$. Each vertex $v \in V$ must be assigned an ownership label matching the closest hub index. If a vertex is equidistant to multiple hubs, a deterministic tie-breaking rule dictates that it must be assigned to the hub with the lowest numerical index. Additionally, a radius threshold restriction $R$ is enforced: if the distance to its closest hub exceeds $R$, the vertex falls outside the covered service area and is labeled with `-1`.

Instead of executing a separate Breadth-First Search (BFS) for each individual hub—which would result in redundant traversals—the problem is solved using a **Multi-Source BFS**. 

The algorithm initializes by populating a distance tracker array with infinity and an ownership tracker array with `-1`. All $K$ hubs are loaded simultaneously into a single FIFO queue as multi-source reference points with an initial distance of `0`. The deterministic tie-breaking criteria is maintained during initialization: if a vertex is a hub itself, it receives ownership priority based on the lowest identifier index.

The standard BFS then traverses outward level-by-level:
1. When evaluating a neighbor $v$ from a current node $u$, if the path through $u$ offers a strictly shorter route (`dist[u] + 1 < dist[v]`), the distance is updated, the neighbor inherits $u$'s hub owner, and $v$ is enqueued.
2. If an equidistant path is discovered (`dist[u] + 1 == dist[v]`), the tie-breaking rule updates ownership to the smaller hub index if `owner[u] < owner[v]`.

After the traversal completes, a final filter scan sets the ownership of any vertex to `-1` if its shortest distance value exceeds the maximum allowable threshold radius $R$.

---

## Time and Space Complexity Analysis

### Time Complexity: $O(V + E)$
- **Initialization:** Setting up initial arrays for distances and hub assignments takes $O(V)$ time. Processing the $K$ initial hubs requires $O(K)$ operations.
- **Graph Traversal:** Because the queue processes vertices level-by-level across all sources simultaneously, each vertex is enqueued and dequeued at most once. Every edge in the undirected graph layout is inspected exactly twice (once from each endpoint). This bounds the primary path exploration phase to $O(V + E)$ time.
- **Radius Post-Processing:** The final threshold filtering pass visits each vertex exactly once, taking $O(V)$ time.
- **Total Time:** The total execution time simplifies directly to linear scale, $O(V + E)$, completely independent of the total number of hubs $K$.

### Space Complexity: $O(V)$
- **Graph Storage:** The adjacency list structure uses $O(V + E)$ space to hold nodes and connections.
- **Tracking Arrays:** The `dist` and `owner` lookup records each require a continuous array block proportional to the number of vertices, taking $O(V)$ space.
- **Queue Allocation:** The maximum number of elements held within the sequential FIFO queue at peak utilization is bounded by $|V|$, requiring $O(V)$ space.
- **Total Space:** Excluding graph storage, the auxiliary working space scales tightly to $O(V)$.
