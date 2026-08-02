#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int compare_ints(const void *a, const void *b) {
    int arg1 = *(const int *)a;
    int arg2 = *(const int *)b;
    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
}
bool is_unique(int arr[], int n) {
    if (n <= 1) return true;
 // Step 1: Sort the array using C's built-in quicksort (O(n log n))
    qsort(arr, n, sizeof(int), compare_ints);
 // Step 2: Linear scan for adjacent duplicates (O(n))
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] == arr[i + 1]) {
            return false; // Duplicate found
        }
    }
    return true; // All elements unique
}
int main() {
    int data[] = {3, 7, 1, 9, 4, 7, 5};
    int n = sizeof(data) / sizeof(data[0]);
    if (is_unique(data, n)) {
        printf("All elements are unique.\n");
    } else {
        printf("Duplicates found.\n");
    }
    return 0;
}