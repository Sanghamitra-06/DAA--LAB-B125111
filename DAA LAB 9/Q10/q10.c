#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int findMaxOverlap(const char *a, const char *b, int *overlapLen) {
    int lenA = strlen(a);
    int lenB = strlen(b);
    int maxOverlap = 0;

    for (int k = 1; k <= lenA && k <= lenB; k++) {
        if (strncmp(a + lenA - k, b, k) == 0) {
            maxOverlap = k;
        }
    }

    *overlapLen = maxOverlap;
    return maxOverlap;
}

char* mergeStrings(const char *a, const char *b, int overlap) {
    int lenA = strlen(a);
    int lenB = strlen(b);
    char *merged = (char *)malloc(lenA + lenB - overlap + 1);
    
    strcpy(merged, a);
    strcat(merged, b + overlap);
    return merged;
}

void greedySuperstring(char *arr[], int n) {
    char *S[n];
    for (int i = 0; i < n; i++) {
        S[i] = strdup(arr[i]);
    }

    int count = n;

    while (count > 1) {
        int maxOverlap = -1;
        int bestI = -1, bestJ = -1;

        for (int i = 0; i < count; i++) {
            for (int j = 0; j < count; j++) {
                if (i != j) {
                    int ov = 0;
                    findMaxOverlap(S[i], S[j], &ov);
                    if (ov > maxOverlap) {
                        maxOverlap = ov;
                        bestI = i;
                        bestJ = j;
                    }
                }
            }
        }

        char *merged = mergeStrings(S[bestI], S[bestJ], maxOverlap);

        free(S[bestI]);
        free(S[bestJ]);

        S[bestI] = merged;

        for (int k = bestJ; k < count - 1; k++) {
            S[k] = S[k + 1];
        }
        count--;
    }

    printf("Greedy Shortest Common Superstring: %s\n", S[0]);
    printf("Length: %lu\n", strlen(S[0]));

    free(S[0]);
}

int main() {
    char *strings[] = {"CATGC", "CTAAGT", "GCTA", "TTCA", "ATGCATC"};
    int n = sizeof(strings) / sizeof(strings[0]);

    greedySuperstring(strings, n);

    return 0;
}