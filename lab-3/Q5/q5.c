#include <stdio.h>
#include <stdlib.h>

void allocate_matrix(int ***matrix, int n) {
    *matrix = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        (*matrix)[i] = (int *)malloc(n * sizeof(int));
    }
}

void free_matrix(int **matrix, int n) {
    for (int i = 0; i < n; i++) free(matrix[i]);
    free(matrix);
}

void matrix_add(int **A, int **B, int **C, int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
}

void matrix_sub(int **A, int **B, int **C, int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
}

void special_matrix_multiply(int **X, int **Y, int **Z, int n) {
    if (n == 1) {
        Z[0][0] = X[0][0] * Y[0][0];
        return;
    }

    int k = n / 2;
    int **X1, **X2, **Y1, **Y2;
    allocate_matrix(&X1, k); allocate_matrix(&X2, k);
    allocate_matrix(&Y1, k); allocate_matrix(&Y2, k);

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            X1[i][j] = X[i][j];
            X2[i][j] = X[i][j + k];
            Y1[i][j] = Y[i][j];
            Y2[i][j] = Y[i][j + k];
        }
    }

    int **S1, **S2, **D1, **D2;
    allocate_matrix(&S1, k); allocate_matrix(&S2, k);
    allocate_matrix(&D1, k); allocate_matrix(&D2, k);

    matrix_add(X1, X2, S1, k);
    matrix_add(Y1, Y2, S2, k);
    matrix_sub(X1, X2, D1, k);
    matrix_sub(Y1, Y2, D2, k);

    int **M_Sum, **M_Diff;
    allocate_matrix(&M_Sum, k);
    allocate_matrix(&M_Diff, k);

    special_matrix_multiply(S1, S2, M_Sum, k);
    special_matrix_multiply(D1, D2, M_Diff, k);

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            int sum_val = M_Sum[i][j];
            int diff_val = M_Diff[i][j];
            
            int diag = (sum_val + diff_val) / 2;
            int cross = (sum_val - diff_val) / 2;

            Z[i][j] = diag;          Z[i][j + k] = cross;
            Z[i + k][j] = cross;      Z[i + k][j + k] = diag;
        }
    }

    free_matrix(X1, k); free_matrix(X2, k); free_matrix(Y1, k); free_matrix(Y2, k);
    free_matrix(S1, k); free_matrix(S2, k); free_matrix(D1, k); free_matrix(D2, k);
    free_matrix(M_Sum, k); free_matrix(M_Diff, k);
}

int main() {
    int n = 4;
    int **X, **Y, **Z;
    allocate_matrix(&X, n); allocate_matrix(&Y, n); allocate_matrix(&Z, n);

    int sampleX[4][4] = {{2, 3, 4, 5}, {3, 2, 5, 4}, {4, 5, 2, 3}, {5, 4, 3, 2}};
    int sampleY[4][4] = {{1, 2, 3, 4}, {2, 1, 4, 3}, {3, 4, 1, 2}, {4, 3, 2, 1}};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            X[i][j] = sampleX[i][j];
            Y[i][j] = sampleY[i][j];
        }
    }

    special_matrix_multiply(X, Y, Z, n);

    printf("Special Pattern Matrix Multiplication Result:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) printf("%d ", Z[i][j]);
        printf("\n");
    }

    free_matrix(X, n); free_matrix(Y, n); free_matrix(Z, n);
    return 0;
}
