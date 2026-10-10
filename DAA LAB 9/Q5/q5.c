#include <stdio.h>
#include <stdlib.h>

int candyDistribution(int ratings[], int n) {
    int* candies = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) candies[i] = 1;
    for (int i = 1; i < n; i++) {
        if (ratings[i] > ratings[i - 1]) {
            candies[i] = candies[i - 1] + 1;
        }
    }
    for (int i = n - 2; i >= 0; i--) {
        if (ratings[i] > ratings[i + 1]) {
            if (candies[i] < candies[i + 1] + 1) {
                candies[i] = candies[i + 1] + 1;
            }
        }
    }
    
    int totalCandies = 0;
    for (int i = 0; i < n; i++) totalCandies += candies[i];
    
    free(candies);
    return totalCandies;
}

int main() {
    int ratings[] = {1, 0, 2};
    int ans = candyDistribution(ratings, 3);
    printf("Minimum Total Candies Needed: %d\n\n", ans);
    return 0;
}
