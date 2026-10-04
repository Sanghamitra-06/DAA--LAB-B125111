#include <stdio.h>

void analyzeTrajectory(long long n) {
    printf("Trajectory for %lld: ", n);
    while (n != 1) {
        printf("%lld -> ", n);
        if (n % 2 == 0) {
            n = n / 2;
        } else {
            n = 3 * n + 1;
        }
    }
    printf("1\n");
}

void analyzeInterval(long long a, long long b) {
    for (long long i = a; i <= b; i++) {
        long long temp = i;
        int steps = 0;
        long long max_val = temp;
        while (temp != 1) {
            if (temp > max_val) {
                max_val = temp;
            }
            if (temp % 2 == 0) {
                temp = temp / 2;
            } else {
                temp = 3 * temp + 1;
            }
            steps++;
        }
        printf("Start: %lld, Steps: %d, Max: %lld\n", i, steps, max_val);
    }
}

int main() {
    long long n = 6;
    long long a = 10, b = 15;
    analyzeTrajectory(n);
    printf("\nInterval Analysis:\n");
    analyzeInterval(a, b);
    return 0;
}
