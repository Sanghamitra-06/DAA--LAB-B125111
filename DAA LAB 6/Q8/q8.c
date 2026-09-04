#include <stdio.h>
#include <limits.h>

int matrix_chain_order(int p[], int n) {
    // dp[i][j] stores the minimum number of scalar multiplications
    int dp[100][100] = {0};
    
    // l is the chain length
    for (int l = 2; l < n; l++) {
        for (int i = 1; i < n - l + 1; i++) {
            int j = i + l - 1;
            dp[i][j] = INT_MAX;
            
            for (int k = i; k <= j - 1; k++) {
                int cost = dp[i][k] + dp[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                }
            }
        }
    }
    return dp[1][n - 1];
}

int main() {
    // Matching exact problem specification array profile given in your lab image
    int arr[] = {10, 30, 5, 60};
    int N = sizeof(arr) / sizeof(arr[0]);
    
    printf("4. Minimum scalar multiplications required (MCM): %d\n", matrix_chain_order(arr, N));
    return 0;
}
