
_________________________________________
Q2 Fair vs. Biased Coin Toss Simulation
_________________________________________


---

##  Overview
This repository contains the C programming implementation for the **Coin Toss Simulation** of our DAA Lab-01 assignment. 
The objective is to computationally simulate a standard (fair) coin and a mathematically weighted (biased) coin over a massive sample size to observe probability in action.
The program runs 10,000 independent trials, counting the occurrences of Heads and Tails, and outputs the final experimental probabilities directly to the console.

## Algorithmic Logic

The simulation relies on pseudo-random number generation (`rand()`) seeded by the current system time to model probability:

1. **Fair Coin (50%):** We use modulo 2 (`rand() % 2`). If the result is `0`, it counts as Heads; if `1`, it counts as Tails. This enforces a strict 50/50 algorithmic split.
2. **Biased Coin (75%):** We use modulo 100 (`rand() % 100`). If the generated number is strictly less than 75 (0 through 74), it counts as Heads. If it is 75 to 99, it counts as Tails. This perfectly enforces a 75/25 algorithmic bias.

--------------------------------------
## THE OUTPUT OF THIS PROGRAM IS GIVEN BELOW AND I HAVE ATTTACHED A SVG FILE TO SHOW THE SIMULATION FOR THE COMPARISON 


###  Experimental Data Output

| Coin Type | Theoretical Expectation (Heads) | Total Heads | Total Tails | Actual Experimental Probability |
| :--- | :--- | :--- | :--- | :--- |
| **Normal (Fair) Coin** | 50.00% | 5,042 | 4,958 | **50.42%** |
| **Biased Coin** | 75.00% | 7,481 | 2,519 | **74.81%** |

---


> **Course:** Design and Analysis of Algorithm (DAA), Lab-01  
> **Instructor:** Dr. Ajaya Kumar Dash  
> **Date:** 31 July 2026  
