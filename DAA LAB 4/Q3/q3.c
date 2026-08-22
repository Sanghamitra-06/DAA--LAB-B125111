#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

// O(n^(k-1)) using a recursive K-Sum reduction wrapper with Two-Pointers for the base case
bool kSumHelper(int arr[], int n, int target, int k, int start, int current_count) {
    // Base Case 1: If we have picked k-2 elements, solve the remaining 2-Sum using Two-Pointers
    if (k - current_count == 2) {
        int left = start;
        int right = n - 1;
        while (left < right) {
            int current_sum = arr[left] + arr[right];
            if (current_sum == target) {
                printf("%d %d ", arr[left], arr[right]);
                return true;
            } else if (current_sum < target) {
                left++;
            } else {
                right--;
            }
        }
        return false;
    }

    // Recursively lock in the current element and reduce to (k-1) Sum
    for (int i = start; i < n - (k - current_count - 1); i++) {
        if (kSumHelper(arr, n, target - arr[i], k, i + 1, current_count + 1)) {
            printf("%d ", arr[i]);
            return true;
        }
    }
    return false;
}

void checkKSum(int arr[], int n, int target, int k) {
    qsort(arr, n, sizeof(int), compare);
    printf("Testing %d-Sum for target %d: ", k, target);
    if (!kSumHelper(arr, n, target, k, 0, 0)) {
        printf("No such subset found.");
    }
    printf("\n");
}

int main() {
    int arr[] = {4, 1, 3, 2, 9, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    checkKSum(arr, n, 9, 3); // Looks for 3 numbers summing to 9
    return 0;
}
