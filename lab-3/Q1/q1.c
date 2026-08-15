#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int index;
    int comparisons;
} SearchResult;
SearchResult binary_search(const int arr[], int size, int target) {
    int low = 0;
    int high = size - 1;
    int comp_count = 0;
    SearchResult result = {-1, 0};

    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        comp_count++; // Increment for the first condition check
        if (arr[mid] == target) {
            result.index = mid;
            result.comparisons = comp_count;
            return result;
        }
        
        comp_count++; // Increment for the second condition check
        if (arr[mid] > target) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    result.comparisons = comp_count;
    return result;
}


SearchResult ternary_search(const int arr[], int size, int target) {
    int low = 0;
    int high = size - 1;
    int comp_count = 0;
    SearchResult result = {-1, 0};

    while (low <= high) {
        // Calculate two midpoints to divide the range into three intervals
        int mid1 = low + (high - low) / 3;
        int mid2 = high - (high - low) / 3;

        comp_count++; // Comparison for mid1
        if (arr[mid1] == target) {
            result.index = mid1;
            result.comparisons = comp_count;
            return result;
        }

        comp_count++; // Comparison for mid2
        if (arr[mid2] == target) {
            result.index = mid2;
            result.comparisons = comp_count;
            return result;
        }

        comp_count++; // Comparison to see if target is in the first third
        if (target < arr[mid1]) {
            high = mid1 - 1;
        } 
        else {
            comp_count++; // Comparison to see if target is in the last third
            if (target > arr[mid2]) {
                low = mid2 + 1;
            } 
            else {
                // Target is in the middle third
                low = mid1 + 1;
                high = mid2 - 1;
            }
        }
    }

    result.comparisons = comp_count;
    return result;
}


void run_search_test(const int arr[], int size, int target) {
    printf("Searching for target element: %d\n", target);
    printf("----------------------------------------\n");

    SearchResult bin_res = binary_search(arr, size, target);
    if (bin_res.index != -1) {
        printf("Binary Search : Found at index %d | Total Comparisons: %d\n", bin_res.index, bin_res.comparisons);
    } else {
        printf("Binary Search : Element not found    | Total Comparisons: %d\n", bin_res.comparisons);
    }

    SearchResult tern_res = ternary_search(arr, size, target);
    if (tern_res.index != -1) {
        printf("Ternary Search: Found at index %d | Total Comparisons: %d\n", tern_res.index, tern_res.comparisons);
    } else {
        printf("Ternary Search: Element not found    | Total Comparisons: %d\n", tern_res.comparisons);
    }
    
    printf("Comparison Ratio (Ternary/Binary): %.2f\n\n", (float)tern_res.comparisons / bin_res.comparisons);
}

int main() {
    // Generate a sample sorted array of 20 elements
    int size = 20;
    int sorted_array[] = {2, 5, 8, 12, 16, 23, 38, 42, 50, 55, 60, 67, 71, 75, 80, 85, 90, 93, 97, 100};

    printf("Sorted Array Elements:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", sorted_array[i]);
    }
    printf("\n\n");

    // Test Case 1: Searching for an element towards the beginning
    run_search_test(sorted_array, size, 8);

    // Test Case 2: Searching for an element in the middle block
    run_search_test(sorted_array, size, 60);

    // Test Case 3: Searching for an element near the end
    run_search_test(sorted_array, size, 97);

    // Test Case 4: Worst-case scenario item (Not present in the list)
    run_search_test(sorted_array, size, 45);

    return 0;
}
