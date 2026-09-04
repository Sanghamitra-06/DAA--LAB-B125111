#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) { return (a > b) ? a : b; }

int knapsack(int W, int wt[], int val[], int n) {
    // Space-optimized DP array
    int *dp = (int*)calloc(W + 1, sizeof(int));
    
    for (int i = 0; i < n; i++) {
        for (int w = W; w >= wt[i]; w--) {
            dp[w] = max(dp[w], val[i] + dp[w - wt[i]]);
        }
    }
    
    int result = dp[W];
    free(dp);
    return result;
}

int main() {
    int profit[] = {60, 100, 120};
    int weight[] = {10, 20, 30};
    int W = 50;
    int n = sizeof(profit) / sizeof(profit[0]);
    
    printf("2. Maximum Knapsack profit: %d\n", knapsack(W, weight, profit, n));
    return 0;
}
