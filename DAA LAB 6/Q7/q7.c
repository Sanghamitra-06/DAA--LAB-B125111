#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void find_and_print_lcs(char *X, char *Y) {
    int m = strlen(X);
    int n = strlen(Y);
    
    int **dp = (int**)malloc((m + 1) * sizeof(int*));
    for (int i = 0; i <= m; i++) dp[i] = (int*)calloc(n + 1, sizeof(int));
    
    // Fill the DP table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = (dp[i - 1][j] > dp[i][j - 1]) ? dp[i - 1][j] : dp[i][j - 1];
        }
    }
    
    printf("3. Length of LCS: %d\n", dp[m][n]);
    
    // Backtrack to extract string path sequence
    int index = dp[m][n];
    char *lcs_str = (char*)malloc((index + 1) * sizeof(char));
    lcs_str[index] = '\0';
    
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcs_str[index - 1] = X[i - 1];
            i--; j--; index--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }
    
    printf("   LCS String: %s\n", lcs_str);
    
    for (int k = 0; k <= m; k++) free(dp[k]);
    free(dp); free(lcs_str);
}

int main() {
    char X[] = "LONGEST";
    char Y[] = "STONE";
    find_and_print_lcs(X, Y);
    return 0;
}
