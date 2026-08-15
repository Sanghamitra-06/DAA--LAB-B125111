#include <stdio.h>


int weigh(const int coins[], int l1, int r1, int l2, int r2) {
    int weight1 = 0;
    int weight2 = 0;
    
    for (int i = l1; i <= r1; i++) {
        weight1 += coins[i];
    }
    for (int i = l2; i <= r2; i++) {
        weight2 += coins[i];
    }
    
    if (weight1 < weight2) return -1;
    if (weight2 < weight1) return 1;
    return 0;
}

int find_defective_rec(const int coins[], int low, int high, int good_idx) {
    int length = high - low + 1;
    
    // Base Case 1: Only 1 coin remaining in the suspected group
    if (length == 1) {
        // If we reached here, this coin was in a group that was strictly lighter
        // than its counterpart, meaning it is guaranteed to be defective.
        return low;
    }
    
    int mid = low + (high - low) / 2;
    
    // Case A: Even number of coins in the current subset
    if (length % 2 == 0) {
        // Divide into two equal halves: [low ... mid] and [mid + 1 ... high]
        int balance = weigh(coins, low, mid, mid + 1, high);
        
        if (balance == -1) {
            // Left half is lighter -> defective coin must be in the left half
            return find_defective_rec(coins, low, mid, mid + 1); // use a coin from the right half as a known good coin
        } else if (balance == 1) {
            // Right half is lighter -> defective coin must be in the right half
            return find_defective_rec(coins, mid + 1, high, low); // use a coin from the left half as a known good coin
        } else {
            // Balanced -> no coin inside this entire [low ... high] range is defective
            return -1;
        }
    } 
    // Case B: Odd number of coins in the current subset
    else {
        // Set aside the last coin ('high') and divide the remaining even number of coins into two halves
        // Left half: [low ... mid - 1], Right half: [mid ... high - 1]
        int balance = weigh(coins, low, mid - 1, mid, high - 1);
        
        if (balance == -1) {
            return find_defective_rec(coins, low, mid - 1, mid);
        } else if (balance == 1) {
            return find_defective_rec(coins, mid, high - 1, low);
        } else {
            if (coins[high] < coins[good_idx]) {
                return high; // The set-aside coin is indeed lighter (defective)
            } else {
                return -1;   // The set-aside coin is normal; no defective coin exists
            }
        }
    }
}
int find_defective_coin(const int coins[], int n) {
    if (n <= 0) return -1;
    if (n == 1) return -1; // Problem states one dropped into (n-1) pile, so n >= 2
    
    // Pass index 0 initially as a dummy good_idx; it updates correctly down the recursive tree
    return find_defective_rec(coins, 0, n - 1, 0);
}

int main() {
    int n = 7;
    // Normal coin weight is 10. The defective coin (if present) is lighter (e.g., 8).
    
    // Scenario 1: Defective coin is present at index 4
    int coins1[] = {10, 10, 10, 10, 8, 10, 10};
    int result1 = find_defective_coin(coins1, n);
    if (result1 != -1) {
        printf("Test 1: Defective coin found at index: %d\n", result1);
    } else {
        printf("Test 1: No defective coin found.\n");
    }

    // Scenario 2: No defective coin is present (all perfectly identical)
    int coins2[] = {10, 10, 10, 10, 10, 10, 10};
    int result2 = find_defective_coin(coins2, n);
    if (result2 != -1) {
        printf("Test 2: Defective coin found at index: %d\n", result2);
    } else {
        printf("Test 2: No defective coin found.\n");
    }

    return 0;
}
