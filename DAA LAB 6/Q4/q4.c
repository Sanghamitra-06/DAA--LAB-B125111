#include <stdio.h>
#include <stdlib.h>

long long total_reversal_cost = 0;

void reverse(int p[], int i, int j) {
    if (i >= j) return;
    total_reversal_cost += (j - i + 1);
    while (i < j) {
        int temp = p[i];
        p[i] = p[j];
        p[j] = temp;
        i++; j--;
    }
}

// Find median value of an array segment statically to guide the binary partition
int get_median_val(int p[], int start, int end) {
    int len = end - start + 1;
    int *temp = malloc(len * sizeof(int));
    for (int i = 0; i < len; i++) temp[i] = p[start + i];
    
    // Simple bubble sort for helper median calculation
    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - i - 1; j++) {
            if (temp[j] > temp[j+1]) {
                int t = temp[j]; temp[j] = temp[j+1]; temp[j+1] = t;
            }
        }
    }
    int mid = temp[len / 2];
    free(temp);
    return mid;
}

// O(n log n) stable partition via block swaps using reversals
int stable_partition_reversal(int p[], int start, int end, int median) {
    if (start >= end) return (p[start] <= median) ? start : start - 1;
    
    int mid = start + (end - start) / 2;
    int left_end_small = stable_partition_reversal(p, start, mid, median);
    int right_end_small = stable_partition_reversal(p, mid + 1, end, median);
    
    // Swap Left_Large block and Right_Small block using 3 targeted reversals
    int left_large_start = left_end_small + 1;
    int left_large_end = mid;
    int right_small_start = mid + 1;
    int right_small_end = right_end_small;
    
    if (left_large_start <= left_large_end && right_small_start <= right_small_end) {
        reverse(p, left_large_start, left_large_end);
        reverse(p, right_small_start, right_small_end);
        reverse(p, left_large_start, right_small_end);
    }
    
    return left_end_small + (right_small_end - right_small_start + 1);
}

// O(n log^2 n) Cost Sorting Procedure
void reversal_sort(int p[], int start, int end) {
    if (start >= end) return;
    
    int median = get_median_val(p, start, end);
    int mid_boundary = stable_partition_reversal(p, start, end, median);
    
    // Prevent infinite loops if values are identical
    if (mid_boundary < start || mid_boundary >= end) return;
    
    reversal_sort(p, start, mid_boundary);
    reversal_sort(p, mid_boundary + 1, end);
}

int main() {
    int p[] = {1, 4, 3, 2, 5, 8, 7, 6};
    int n = sizeof(p) / sizeof(p[0]);

    printf("Original Permutation: ");
    for (int i = 0; i < n; i++) printf("%d ", p[i]);
    printf("\n");

    reversal_sort(p, 0, n - 1);

    printf("Sorted Permutation:   ");
    for (int i = 0; i < n; i++) printf("%d ", p[i]);
    printf("\nTotal Reversal Cost:  %lld\n", total_reversal_cost);

    return 0;
}
