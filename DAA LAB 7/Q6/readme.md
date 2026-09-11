# The Best Time to Be Alive

## Overview
This algorithm processes a historical dataset of prominent scientists' lifespans to determine the specific calendar year during which the highest concentration of individuals were concurrently alive.

## Core Logic
The problem transforms raw time intervals into chronological lifecycle events using a sweep-line logic layout:
1. **Interval Decomposition:** Every scientist's profile is broken down into two separate events: a birth milestone ($+1$) and a death milestone ($-1$).
2. **Chronological Ordering:** All generated milestones are sorted together by year. When two events land on the exact same year, the tie-breaking rules process death events ($-1$) right before birth events ($+1$).
3. **Linear Accumulation:** A single continuous sweep travels down the sorted timeline, adding or subtracting values to maintain a running total of active lives. The maximum peak value encountered flags the target year.

## Complexity Analysis

### Time Complexity
* **Analysis:** For $n$ scientists, the dataset expands into $2n$ individual lifecycle events. Sorting these milestones takes $\mathcal{O}(n \log n)$ steps, while the final linear sweep requires $\mathcal{O}(n)$ steps.
* **Order of Growth:** $\mathcal{O}(n \log n)$

### Space Complexity
* **Analysis:** Space allocation is directly tied to storing the linear transformation array containing the $2n$ distinct lifecycle event structures.
* **Order of Growth:** $\mathcal{O}(n)$
