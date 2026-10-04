#include <stdio.h>
#include <limits.h>

int minCoins(int C[], int n, int V) {
    int dp[V + 1];
    dp[0] = 0;
    for (int i = 1; i <= V; i++) {
        dp[i] = INT_MAX;
    }
    for (int i = 1; i <= V; i++) {
        for (int j = 0; j < n; j++) {
            if (C[j] <= i) {
                int res = dp[i - C[j]];
                if (res != INT_MAX && res + 1 < dp[i]) {
                    dp[i] = res + 1;
                }
            }
        }
    }
    return dp[V] == INT_MAX ? -1 : dp[V];
}

int main() {
    int C[] = {1, 2, 5};
    int n = sizeof(C) / sizeof(C[0]);
    int V = 11;
    printf("%d\n", minCoins(C, n, V));
    return 0;
}
