#include <stdio.h>
#include <stdlib.h>
#include <math.h>
double** allocate_matrix(int n) {
    double **mat = (double**)malloc(n * sizeof(double*));
    for (int i = 0; i < n; i++) {
        mat[i] = (double*)calloc(n, sizeof(double));
    }
    return mat;
}

void free_matrix(double **mat, int n) {
    for (int i = 0; i < n; i++) free(mat[i]);
    free(mat);
}


void print_matrix(double **mat, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%6.2f ", mat[i][j]);
        }
        printf("\n");
    }
}


double** matrix_add(double **A, double **B, int n) {
    double **C = allocate_matrix(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    return C;
}

// (ii) Matrix Multiplication -> O(n^3)
double** matrix_multiply(double **A, double **B, int n) {
    double **C = allocate_matrix(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}

// (iii) Finding if zero matrix -> O(n^2)
int is_zero_matrix(double **mat, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (fabs(mat[i][j]) > 1e-9) return 0; // Not a zero matrix
        }
    }
    return 1;
}

// (iv) Finding if symmetric matrix -> O(n^2)
int is_symmetric(double **mat, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (fabs(mat[i][j] - mat[j][i]) > 1e-9) return 0; // Not symmetric
        }
    }
    return 1;
}

// (v) Computing Determinant via Gaussian Elimination -> O(n^3)
double compute_determinant(double **mat, int n) {
    double **temp = allocate_matrix(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) temp[i][j] = mat[i][j];
    }

    double det = 1.0;
    for (int i = 0; i < n; i++) {
        // Pivot selection
        int pivot = i;
        for (int j = i + 1; j < n; j++) {
            if (fabs(temp[j][i]) > fabs(temp[pivot][i])) pivot = j;
        }

        if (pivot != i) {
            double *t = temp[i];
            temp[i] = temp[pivot];
            temp[pivot] = t;
            det *= -1.0;
        }

        if (fabs(temp[i][i]) < 1e-9) {
            free_matrix(temp, n);
            return 0.0; // Matrix is singular
        }

        det *= temp[i][i];

        for (int j = i + 1; j < n; j++) {
            double factor = temp[j][i] / temp[i][i];
            for (int k = i; k < n; k++) {
                temp[j][k] -= factor * temp[i][k];
            }
        }
    }

    free_matrix(temp, n);
    return det;
}

// (vi) Transposing the matrix in situ (in place) -> O(n^2)
void transpose_in_situ(double **mat, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double temp = mat[i][j];
            mat[i][j] = mat[j][i];
            mat[j][i] = temp;
        }
    }
}

// (vii) Finding dominant Eigenvalue and Eigenvector using Power Iteration -> O(k * n^2)
void find_dominant_eigen(double **mat, int n, int max_iter, double *eigenvalue, double *eigenvector) {
    double *v = (double*)malloc(n * sizeof(double));
    double *next_v = (double*)malloc(n * sizeof(double));
    
    // Initialize starting vector
    for (int i = 0; i < n; i++) v[i] = 1.0;

    double lambda = 0.0;
    for (int iter = 0; iter < max_iter; iter++) {
        // Matrix-vector multiplication: next_v = mat * v
        for (int i = 0; i < n; i++) {
            next_v[i] = 0;
            for (int j = 0; j < n; j++) {
                next_v[i] += mat[i][j] * v[j];
            }
        }

        // Find the absolute maximum element to normalize
        double max_val = 0.0;
        for (int i = 0; i < n; i++) {
            if (fabs(next_v[i]) > fabs(max_val)) max_val = next_v[i];
        }

        if (fabs(max_val) < 1e-9) break;

        lambda = max_val;
        // Normalize vector
        for (int i = 0; i < n; i++) v[i] = next_v[i] / lambda;
    }

    *eigenvalue = lambda;
    for (int i = 0; i < n; i++) eigenvector[i] = v[i];

    free(v);
    free(next_v);
}

int main() {
    int n = 3;
    double **A = allocate_matrix(n);
    double **B = allocate_matrix(n);

    // Initializing Sample Matrix A (Symmetric matrix for clear testing output)
    A[0][0] = 2; A[0][1] = -1; A[0][2] = 0;
    A[1][0] = -1; A[1][1] = 2; A[1][2] = -1;
    A[2][0] = 0; A[2][1] = -1; A[2][2] = 2;

    // Initializing Sample Matrix B
    B[0][0] = 1; B[0][1] = 0; B[0][2] = 0;
    B[1][0] = 0; B[1][1] = 1; B[1][2] = 0;
    B[2][0] = 0; B[2][1] = 0; B[2][2] = 1;

    printf(" Matrix A\n"); print_matrix(A, n);
    
    // (i) Addition
    double **C_add = matrix_add(A, B, n);
    printf("\n(i) Matrix Addition (A + B):\n"); print_matrix(C_add, n);

    // (ii) Multiplication
    double **C_mul = matrix_multiply(A, B, n);
    printf("\n(ii) Matrix Multiplication (A * B):\n"); print_matrix(C_mul, n);

    // (iii) Zero check
    printf("\n(iii) Is A a Zero Matrix? %s\n", is_zero_matrix(A, n) ? "Yes" : "No");

    // (iv) Symmetry check
    printf("(iv) Is A Symmetric? %s\n", is_symmetric(A, n) ? "Yes" : "No");

    // (v) Determinant
    printf("(v) Determinant of A: %.2f\n", compute_determinant(A, n));

    // (vi) In-situ Transpose
    transpose_in_situ(B, n); // transposing identity matrix or simple modified layout
    B[0][1] = 5.0; // add a test component
    printf("\nMatrix B before In-Situ Transpose:\n"); print_matrix(B, n);
    transpose_in_situ(B, n);
    printf("(vi) Matrix B after In-Situ Transpose:\n"); print_matrix(B, n);

    // (vii) Eigenvalue & Eigenvector
    double eval;
    double *evec = (double*)malloc(n * sizeof(double));
    find_dominant_eigen(A, n, 100, &eval, evec);
    printf("\n(vii) Dominant Eigenvalue of A: %.4f\n", eval);
    printf("Corresponding Eigenvector: [ ");
    for(int i=0; i<n; i++) printf("%.4f ", evec[i]);
    printf("]\n");

    // Clean up memory
    free_matrix(A, n); free_matrix(B, n);
    free_matrix(C_add, n); free_matrix(C_mul, n);
    free(evec);

    return 0;
}
