#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Global counter to track operations (comparisons and moves) across both algorithms
long long operation_count = 0;

// Standard 2-way merge subroutine that merges two sorted arrays into a destination array
void merge_two_arrays(int arr1[], int size1, int arr2[], int size2, int dest[]) {
    int i = 0, j = 0, k = 0;
    
    while (i < size1 && j < size2) {
        operation_count++; // Comparison step
        if (arr1[i] <= arr2[j]) {
            dest[k++] = arr1[i++];
        } else {
            dest[k++] = arr2[j++];
        }
    }
    
    // Drain any remaining elements from arr1
    while (i < size1) {
        dest[k++] = arr1[i++];
        operation_count++;
    }
    
    // Drain any remaining elements from arr2
    while (j < size2) {
        dest[k++] = arr2[j++];
        operation_count++;
    }
}

// --- METHOD 1: REPEATED LINEAR MERGING ---
int* merge_method1(int **arrays, int k, int n, long long *tracked_ops) {
    operation_count = 0;
    
    // Allocate space for the final accumulated output array
    int *output = (int *)malloc(k * n * sizeof(int));
    
    // Copy the first array into the output buffer to start the accumulation chain
    for (int i = 0; i < n; i++) {
        output[i] = arrays[0][i];
        operation_count++;
    }
    
    // Allocate a temporary buffer to hold intermediate merge steps
    int *temp = (int *)malloc(k * n * sizeof(int));
    
    // Progressively merge the accumulated result with the next array one-by-one
    for (int i = 1; i < k; i++) {
        int current_accumulated_size = i * n;
        
        merge_two_arrays(output, current_accumulated_size, arrays[i], n, temp);
        
        // Copy back from temp into output for the next iteration step
        int next_size = (i + 1) * n;
        for (int j = 0; j < next_size; j++) {
            output[j] = temp[j];
            operation_count++;
        }
    }
    
    free(temp);
    *tracked_ops = operation_count;
    return output;
}

// --- METHOD 2: DIVIDE AND CONQUER (PAIRWISE) MERGING ---
int* merge_method2(int **arrays, int k, int n, long long *tracked_ops) {
    operation_count = 0;
    
    // We create a temporary array of pointers to manage intermediate sorted buffers
    int **current_buffers = (int **)malloc(k * sizeof(int *));
    int *sizes = (int *)malloc(k * sizeof(int));
    
    for (int i = 0; i < k; i++) {
        sizes[i] = n;
        current_buffers[i] = (int *)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            current_buffers[i][j] = arrays[i][j];
            operation_count++;
        }
    }
    
    int active_buffers = k;
    
    // Pairwise merge iteration tree loop
    while (active_buffers > 1) {
        int next_active_count = 0;
        
        for (int i = 0; i < active_buffers; i += 2) {
            if (i + 1 < active_buffers) {
                // Merge pair: current_buffers[i] and current_buffers[i+1]
                int new_size = sizes[i] + sizes[i + 1];
                int *merged_temp = (int *)malloc(new_size * sizeof(int));
                
                merge_two_arrays(current_buffers[i], sizes[i], current_buffers[i + 1], sizes[i + 1], merged_temp);
                
                // Clean up merged buffers
                free(current_buffers[i]);
                free(current_buffers[i + 1]);
                
                // Save back into the tracking grid array slots
                current_buffers[next_active_count] = merged_temp;
                sizes[next_active_count] = new_size;
                next_active_count++;
            } else {
                // Odd array buffer out: carry over to the next level unchanged
                current_buffers[next_active_count] = current_buffers[i];
                sizes[next_active_count] = sizes[i];
                next_active_count++;
            }
        }
        active_buffers = next_active_count;
    }
    
    int *final_output = current_buffers[0];
    free(current_buffers);
    free(sizes);
    
    *tracked_ops = operation_count;
    return final_output;
}

int main() {
    // Test Configurations: k = 4 sorted arrays, each with n = 4 elements
    int k = 4;
    int n = 4;
    
    // Initialize standard mock sorted test arrays via pointer matrices
    int data[4][4] = {
        {1, 5, 9, 13},
        {2, 6, 10, 14},
        {3, 7, 11, 15},
        {4, 8, 12, 16}
    };
    
    int **arrays = (int **)malloc(k * sizeof(int *));
    for (int i = 0; i < k; i++) {
        arrays[i] = (int *)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            arrays[i][j] = data[i][j];
        }
    }
    
    long long ops_m1 = 0, ops_m2 = 0;
    
    // Run and print results for Method 1
    int *res1 = merge_method1(arrays, k, n, &ops_m1);
    printf("Method 1 Output: ");
    for (int i = 0; i < k * n; i++) printf("%d ", res1[i]);
    printf("\nMethod 1 Operation Steps Tracked: %lld\n\n", ops_m1);
    
    // Run and print results for Method 2
    int *res2 = merge_method2(arrays, k, n, &ops_m2);
    printf("Method 2 Output: ");
    for (int i = 0; i < k * n; i++) printf("%d ", res2[i]);
    printf("\nMethod 2 Operation Steps Tracked: %lld\n", ops_m2);
    
    // Clean up all dynamically allocated memory blocks
    free(res1);
    free(res2);
    for (int i = 0; i < k; i++) free(arrays[i]);
    free(arrays);
    
    return 0;
}
