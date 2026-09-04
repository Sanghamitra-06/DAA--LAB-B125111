#include <stdio.h>

long long fibonacci(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    
    long long prev2 = 0, prev1 = 1, current = 0;
    for (int i = 2; i <= n; i++) {
        current = prev1 + prev2;
        prev2 = prev1;
        prev1 = current;
    }
    return current;
}

int main() {
    int n = 10;
    printf("1. Fibonacci number at position %d is: %lld\n", n, fibonacci(n));
    return 0;
}
