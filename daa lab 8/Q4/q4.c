#include <stdio.h>

int lis(int A[], int n) {
    int dp[n];
    int max_lis = 0;
    for (int i = 0; i < n; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (A[i] > A[j] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
            }
        }
        if (dp[i] > max_lis) {
            max_lis = dp[i];
        }
    }
    return max_lis;
}

int main() {
    int A[] = {10, 22, 9, 33, 21, 50, 41, 60};
    int n = sizeof(A) / sizeof(A[0]);
    printf("%d\n", lis(A, n));
    return 0;
}
