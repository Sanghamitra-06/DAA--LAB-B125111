#include <stdio.h>

typedef struct {
    int max;
    int min;
} MinMax;

MinMax find_min_max(int arr[], int low, int high) {
    MinMax result, left, right;
    
    if (low == high) {
        result.max = arr[low];
        result.min = arr[low];
        return result;
    }
    
    if (high == low + 1) {
        if (arr[low] > arr[high]) {
            result.max = arr[low];
            result.min = arr[high];
        } else {
            result.max = arr[high];
            result.min = arr[low];
        }
        return result;
    }
    
    int mid = low + (high - low) / 2;
    left = find_min_max(arr, low, mid);
    right = find_min_max(arr, mid + 1, high);
    
    result.max = (left.max > right.max) ? left.max : right.max;
    result.min = (left.min < right.min) ? left.min : right.min;
    
    return result;
}

int main() {
    int arr[] = {12, 45, 2, 78, 34, 8, 99, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    MinMax res = find_min_max(arr, 0, n - 1);
    printf("Minimum element: %d\n", res.min);
    printf("Maximum element: %d\n", res.max);
    
    return 0;
}
