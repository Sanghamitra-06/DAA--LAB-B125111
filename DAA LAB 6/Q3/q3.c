#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

typedef struct {
    double real;
    double imag;
} Complex;

// FFT / IFFT implementation
void fft(Complex *X, int N, int invert) {
    if (N <= 1) return;

    Complex *even = malloc(N / 2 * sizeof(Complex));
    Complex *odd = malloc(N / 2 * sizeof(Complex));

    for (int i = 0; i < N / 2; i++) {
        even[i] = X[2 * i];
        odd[i] = X[2 * i + 1];
    }

    fft(even, N / 2, invert);
    fft(odd, N / 2, invert);

    double angle = 2 * PI / N * (invert ? -1 : 1);
    Complex w, wn;
    wn.real = cos(angle);
    wn.imag = sin(angle);
    w.real = 1.0;
    w.imag = 0.0;

    for (int i = 0; i < N / 2; i++) {
        Complex t;
        t.real = w.real * odd[i].real - w.imag * odd[i].imag;
        t.imag = w.real * odd[i].imag + w.imag * odd[i].real;

        X[i].real = even[i].real + t.real;
        X[i].imag = even[i].imag + t.imag;

        X[i + N / 2].real = even[i].real - t.real;
        X[i + N / 2].imag = even[i].imag - t.imag;

        if (invert) {
            X[i].real /= 2;   X[i].imag /= 2;
            X[i + N / 2].real /= 2; X[i + N / 2].imag /= 2;
        }

        Complex next_w;
        next_w.real = w.real * wn.real - w.imag * wn.imag;
        next_w.imag = w.real * wn.imag + w.imag * wn.real;
        w = next_w;
    }

    free(even);
    free(odd);
}

int main() {
    int m = 3, n = 4;
    double A[] = {1.0, 2.0, 3.0};
    double B[] = {1.0, 1.0, 1.0, 1.0};

    // Find next power of 2
    int target_size = m + n - 1;
    int N = 1;
    while (N < target_size) N <<= 1;

    Complex *cA = calloc(N, sizeof(Complex));
    Complex *cB = calloc(N, sizeof(Complex));

    for (int i = 0; i < m; i++) cA[i].real = A[i];
    for (int i = 0; i < n; i++) cB[i].real = B[i];

    fft(cA, N, 0);
    fft(cB, N, 0);

    // Pointwise multiplication
    for (int i = 0; i < N; i++) {
        Complex t;
        t.real = cA[i].real * cB[i].real - cA[i].imag * cB[i].imag;
        t.imag = cA[i].real * cB[i].imag + cA[i].imag * cB[i].real;
        cA[i] = t;
    }

    fft(cA, N, 1); // IFFT

    printf("Convolution Vector C:\n");
    for (int i = 0; i < target_size; i++) {
        printf("C[%d] = %.2f\n", i, cA[i].real * N); // Scale back up due to nested IFFT divisions
    }

    free(cA); free(cB);
    return 0;
}
