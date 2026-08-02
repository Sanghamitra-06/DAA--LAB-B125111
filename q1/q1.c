#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct {
    const char* name;
    double value;
} Func;

int compare(const void* a, const void* b) {
    double diff = ((Func*)a)->value - ((Func*)b)->value;
    return (diff > 0) - (diff < 0);
}

int main() {
    // Choose a value of n that is large enough to show asymptotic behavior 
    // but small enough to prevent infinity/overflow in exponential functions.
    double n = 15.0; 

    Func functions[] = {
        {"n * log2(n)", n * log2(n)},
        {"12 * sqrt(n)", 12 * sqrt(n)},
        {"1 / n", 1.0 / n},
        {"n^(log2(n))", pow(n, log2(n))},
        {"100n^2 + 6n", 100 * n * n + 6 * n},
        {"n^0.51", pow(n, 0.51)},
        {"n^2 - 324", n * n - 324},
        {"50n^0.5", 50 * pow(n, 0.5)},
        {"2n^3", 2 * pow(n, 3)},
        {"3^n", pow(3, n)},
        {"2^32 * n", pow(2, 32) * n},
        {"log2(n)", log2(n)}
    };

    int num_funcs = sizeof(functions) / sizeof(functions[0]);

    qsort(functions, num_funcs, sizeof(Func), compare);

    printf("Functions in increasing order of growth (evaluated at n = %.1f):\n", n);
    for (int i = 0; i < num_funcs; i++) {
        printf("%d. %-15s (Value: %e)\n", i + 1, functions[i].name, functions[i].value);
    }

    return 0;
}