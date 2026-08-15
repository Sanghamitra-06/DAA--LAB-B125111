# Module 2: Search for the Defective Coin

## 1. Problem Formulation & Architectural Strategy
This folder implements a diagnostic divide-and-conquer strategy to isolate a single potentially lightweight (defective) coin out of a pile of $n$ otherwise perfectly identical coins. The constraint dictates that the defect must be isolated or verified as absent using a two-pan balance scale within a tight bound of $\log_2 n + c$ total weighings.

## 2. Algorithmic Core Logic
The strategy uses an exact binary partitioning pattern that handles both even and odd collection bounds:
1. **Division Step:** Bisect the active coin set of size $m$ into two equal sub-blocks of size $\lfloor m/2 \rfloor$. If $m$ is odd, isolate the remaining coin as a separate pivot element.
2. **Weighing Step:** Place the two equal sub-blocks onto opposite pans of the balance scale.
3. **Branch Decision Step:**
   * **Scale Imbalance:** The scale tips. The lighter pan contains the defective item, reducing the active search space to that specific sub-block.
   * **Scale Balance:** The pans align perfectly. This confirms all weighed coins are genuine. If $m$ was even, the entire set is clean. If $m$ was odd, the isolated pivot coin is flagged as the defective item.

## 3. Constant Factor Validation ($c$)
When the search space scales down to a single suspect coin, a final validation check is performed against a known genuine coin (saved from a prior balanced group). This structural base-case validation check establishes the positive constant cost component of $c = 1$.
