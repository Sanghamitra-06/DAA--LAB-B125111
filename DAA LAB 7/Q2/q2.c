#include <stdio.h>
#define MAX_E 105
#define MAX_F 105

int sol[MAX_E][MAX_F];

int max_val(int a, int b) { return (a > b) ? a : b; }

int eggDrop(int e, int f) {
    for (int i = 1; i <= e; i++) {
        sol[i][0] = 0;
        sol[i][1] = 1;
    }
    for (int j = 1; j <= f; j++) {
        sol[1][j] = j;
    }
    for (int i = 2; i <= e; i++) {
        for (int j = 2; j <= f; j++) {
            sol[i][j] = 1e9;
            for (int x = 1; x <= j; x++) {
                int res = 1 + max_val(sol[i-1][x-1], sol[i][j-x]);
                if (res < sol[i][j]) {
                    sol[i][j] = res;
                }
            }
        }
    }
    return sol[e][f];
}

int main() {
    printf("Result: %d\n", eggDrop(2, 100));
    return 0;
}
