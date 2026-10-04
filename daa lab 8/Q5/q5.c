#include <stdio.h>

int maxSumIS(int A[], int n) {
    int dp[n];
    int max_sum = 0;
    for (int i = 0; i < n; i++) {
        dp[i] = A[i];
        for (int j = 0; j < i; j++) {
            if (A[i] > A[j] && dp[i] < dp[j] + A[i]) {
                dp[i] = dp[j] + A[i];
            }
        }
        if (dp[i] > max_sum) {
            max_sum = dp[i];
        }
    }
    return max_sum;
}

int main() {
    int A[] = {1, 101, 2, 3, 100, 4, 5};
    int n = sizeof(A) / sizeof(A[0]);
    printf("%d\n", maxSumIS(A, n));
    return 0;
}
