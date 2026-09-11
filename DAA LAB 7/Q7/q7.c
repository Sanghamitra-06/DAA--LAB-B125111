#include <stdio.h>
#include <limits.h>

void print_parenthesis(int i, int j, int n, int *s, char *name) {
    if (i == j) {
        printf("%c", (*name)++);
        return;
    }
    printf("(");
    print_parenthesis(i, *((s + i * n) + j), n, s, name);
    print_parenthesis(*((s + i * n) + j) + 1, j, n, s, name);
    printf(")");
}

void matrix_chain_order(int p[], int n) {
    int m[n][n];
    int s[n][n];

    for (int i = 1; i < n; i++) {
        m[i][i] = 0;
    }

    for (int l = 2; l < n; l++) {
        for (int i = 1; i < n - l + 1; i++) {
            int j = i + l - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++) {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }

    printf("Minimum number of multiplications: %d\n", m[1][n - 1]);
    char name = 'A';
    printf("Optimal Parenthesization: ");
    print_parenthesis(1, n - 1, n, (int *)s, &name);
    printf("\n");
}

int main() {
    int arr[] = {40, 20, 30, 10, 30};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("--- Matrix Chain Multiplication ---\n");
    matrix_chain_order(arr, size);
    return 0;
}
