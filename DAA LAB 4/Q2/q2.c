#include <stdio.h>
#include <stdlib.h>

// Standard comparison function for qsort
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// O(log n) Binary Search function
int binarySearch(int arr[], int size, int target) {
    int low = 0;
    int high = size - 1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (arr[mid] == target) {
            return mid; // Return the position if found
        }
        if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1; // Return -1 if the complement doesn't exist
}

// Main O(n log n) Algorithm
void findTargetPair(int S1[], int S2[], int n, int x) {
    // Phase 1: Sort S1 in O(n log n) time
    qsort(S1, n, sizeof(int), compare);
    
    // Phase 2: For each element in S2, binary search its complement in S1
    for (int i = 0; i < n; i++) {
        int current_element = S2[i];
        int complement = x - current_element;
        
        int found_index = binarySearch(S1, n, complement);
        
        if (found_index != -1) {
            printf("Success! Found a pair that adds up to %d:\n", x);
            printf("Element from S1: %d\n", S1[found_index]);
            printf("Element from S2: %d\n", current_element);
            return;
        }
    }
    
    printf("No structural pair exists between S1 and S2 that sums to %d.\n", x);
}

int main() {
    int n = 5;
    int S1[] = {12, 1, 4, 9, 7};
    int S2[] = {10, 5, 2, 8, 6};
    int target = 11;
    
    printf("Set S1: ");
    for(int i=0; i<n; i++) printf("%d ", S1[i]);
    printf("\nSet S2: ");
    for(int i=0; i<n; i++) printf("%d ", S2[i]);
    printf("\nTarget x: %d\n\n", target);
    
    findTargetPair(S1, S2, n, target);
    
    return 0;
}
