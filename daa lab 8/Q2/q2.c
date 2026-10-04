#include <stdio.h>

int countWays(int C[], int n, int V) {
    int dp[V + 1];
    for (int i = 0; i <= V; i++) dp[i] = 0;
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = C[i]; j <= V; j++) {
            dp[j] += dp[j - C[i]];
        }
    }
    return dp[V];
}

int main() {
    int C[] = {1, 2, 3};
    int n = sizeof(C) / sizeof(C[0]);
    int V = 4;
    printf("%d\n", countWays(C, n, V));
    return 0;
}
