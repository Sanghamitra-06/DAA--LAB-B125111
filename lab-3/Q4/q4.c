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

void strassen_multiply(int **A, int **B, int **C, int n) {
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int k = n / 2;
    int **A11, **A12, **A21, **A22;
    int **B11, **B12, **B21, **B22;
    int **C11, **C12, **C21, **C22;
    
    allocate_matrix(&A11, k); allocate_matrix(&A12, k); allocate_matrix(&A21, k); allocate_matrix(&A22, k);
    allocate_matrix(&B11, k); allocate_matrix(&B12, k); allocate_matrix(&B21, k); allocate_matrix(&B22, k);
    allocate_matrix(&C11, k); allocate_matrix(&C12, k); allocate_matrix(&C21, k); allocate_matrix(&C22, k);

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            A11[i][j] = A[i][j];         A12[i][j] = A[i][j + k];
            A21[i][j] = A[i + k][j];     A22[i][j] = A[i + k][j + k];
            B11[i][j] = B[i][j];         B12[i][j] = B[i][j + k];
            B21[i][j] = B[i + k][j];     B22[i][j] = B[i + k][j + k];
        }
    }

    int **P1, **P2, **P3, **P4, **P5, **P6, **P7;
    allocate_matrix(&P1, k); allocate_matrix(&P2, k); allocate_matrix(&P3, k); allocate_matrix(&P4, k);
    allocate_matrix(&P5, k); allocate_matrix(&P6, k); allocate_matrix(&P7, k);
    
    int **t1, **t2;
    allocate_matrix(&t1, k); allocate_matrix(&t2, k);

    matrix_sub(B12, B22, t1, k); strassen_multiply(A11, t1, P1, k);
    matrix_add(A11, A12, t1, k); strassen_multiply(t1, B22, P2, k);
    matrix_add(A21, A22, t1, k); strassen_multiply(t1, B11, P3, k);
    matrix_sub(B21, B11, t1, k); strassen_multiply(A22, t1, P4, k);
    matrix_add(A11, A22, t1, k); matrix_add(B11, B22, t2, k); strassen_multiply(t1, t2, P5, k);
    matrix_sub(A12, A22, t1, k); matrix_add(B21, B22, t2, k); strassen_multiply(t1, t2, P6, k);
    matrix_sub(A11, A22, t1, k); matrix_add(B11, B12, t2, k); strassen_multiply(t1, t2, P7, k);

    matrix_add(P5, P4, t1, k); matrix_sub(t1, P2, t2, k); matrix_add(t2, P6, C11, k);
    matrix_add(P1, P2, C12, k);
    matrix_add(P3, P4, C21, k);
    matrix_add(P5, P1, t1, k); matrix_sub(t1, P3, t2, k); matrix_sub(t2, P7, C22, k);

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            C[i][j] = C11[i][j];         C[i][j + k] = C12[i][j];
            C[i + k][j] = C21[i][j];     C[i + k][j + k] = C22[i][j];
        }
    }

    free_matrix(A11, k); free_matrix(A12, k); free_matrix(A21, k); free_matrix(A22, k);
    free_matrix(B11, k); free_matrix(B12, k); free_matrix(B21, k); free_matrix(B22, k);
    free_matrix(C11, k); free_matrix(C12, k); free_matrix(C21, k); free_matrix(C22, k);
    free_matrix(P1, k);  free_matrix(P2, k);  free_matrix(P3, k);  free_matrix(P4, k);
    free_matrix(P5, k);  free_matrix(P6, k);  free_matrix(P7, k);  free_matrix(t1, k); free_matrix(t2, k);
}

int main() {
    int n = 2;
    int **A, **B, **C;
    allocate_matrix(&A, n); allocate_matrix(&B, n); allocate_matrix(&C, n);

    A[0][0] = 1; A[0][1] = 2; A[1][0] = 3; A[1][1] = 4;
    B[0][0] = 5; B[0][1] = 6; B[1][0] = 7; B[1][1] = 8;

    strassen_multiply(A, B, C, n);

    printf("Strassen Multiplication Result:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) printf("%d ", C[i][j]);
        printf("\n");
    }

    free_matrix(A, n); free_matrix(B, n); free_matrix(C, n);
    return 0;
}
