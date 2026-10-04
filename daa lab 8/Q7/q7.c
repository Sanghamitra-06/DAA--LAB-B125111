#include <stdio.h>
#include <limits.h>

void rodCutting(int price[], int n) {
    int val[n + 1];
    int parent[n + 1];
    val[0] = 0;
    for (int i = 1; i <= n; i++) {
        int max_val = INT_MIN;
        for (int j = 0; j < i; j++) {
            if (price[j] + val[i - j - 1] > max_val) {
                max_val = price[j] + val[i - j - 1];
                parent[i] = j + 1;
            }
        }
        val[i] = max_val;
    }
    printf("Max Revenue: %d\n", val[n]);
    printf("Pieces: ");
    int temp = n;
    while (temp > 0) {
        printf("%d ", parent[temp]);
        temp -= parent[temp];
    }
    printf("\n");
}

int main() {
    int price[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int size = sizeof(price) / sizeof(price[0]);
    rodCutting(price, size);
    return 0;
}
