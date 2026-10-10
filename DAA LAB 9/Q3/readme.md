# Minimum Refueling Stops Optimization

## 💡 Core Logic & Algorithm
A vehicle must travel a distance $D$ with a capacity-constrained fuel system, starting with a baseline fuel amount. The objective is to reach the destination with the minimum number of stops.

1. **Forward Drive Pass:** The vehicle drives forward, consuming fuel linearly with distance. It continues until it either reaches the destination or runs out of gas completely.
2. **Lazy Deferred Evaluation:** While driving forward, the vehicle bypasses gas stations. Instead of stopping immediately, it records the fuel capacities of all passed stations into a Max-Priority Queue (Max-Heap).
3. **Retroactive Recovery Choice:** When the fuel level drops below zero before reaching the next location, the vehicle reaches back into its heap history and retroactively "stops" at the passed station that provides the maximum possible fuel volume.
4. **Termination:** If the heap becomes empty and the vehicle still cannot reach the next target milestone, the destination is marked unreachable.

## 📊 Complexity Analysis
* **Time Complexity:** $\mathcal{O}(n \log n)$ where $n$ is the number of refueling stations, driven by sorting the stations by distance and executing heap push/pop operations.
* **Space Complexity:** $\mathcal{O}(n)$ to store the array elements within the max-heap structure.
