#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}


void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int find_max(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}


// (ii) Finding the first and second largest elements -> O(n)

void find_two_largest(int arr[], int n, int *first, int *second) {
    if (arr[0] > arr[1]) {
        *first = arr[0];
        *second = arr[1];
    } else {
        *first = arr[1];
        *second = arr[0];
    }
    for (int i = 2; i < n; i++) {
        if (arr[i] > *first) {
            *second = *first;
            *first = arr[i];
        } else if (arr[i] > *second) {
            *second = arr[i];
        }
    }
}


// (iii) Finding the mean -> O(n)

double find_mean(int arr[], int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum / n;
}


// (iv) Finding the median -> O(n log n) [Worst-case via sorting]

double find_median(int arr[], int n) {
    // Dynamically allocate a temp array to preserve original order
    int *temp = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) temp[i] = arr[i];
    
    qsort(temp, n, sizeof(int), compare);
    
    double median;
    if (n % 2 != 0) {
        median = temp[n / 2];
    } else {
        median = (temp[(n - 1) / 2] + temp[n / 2]) / 2.0;
    }
    
    free(temp);
    return median;
}
// (v) Finding the standard deviation -> O(n)

double find_std_dev(int arr[], int n) {
    double mean = find_mean(arr, n);
    double sum_sq_diff = 0;
    for (int i = 0; i < n; i++) {
        sum_sq_diff += pow(arr[i] - mean, 2);
    }
    return sqrt(sum_sq_diff / n);
}
// (vi) Finding the mode -> O(n log n) [Worst-case via sorting]

int find_mode(int arr[], int n) {
    int *temp = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) temp[i] = arr[i];
    
    qsort(temp, n, sizeof(int), compare);
    
    int mode = temp[0];
    int max_count = 1;
    int current_count = 1;
    
    for (int i = 1; i < n; i++) {
        if (temp[i] == temp[i - 1]) {
            current_count++;
        } else {
            if (current_count > max_count) {
                max_count = current_count;
                mode = temp[i - 1];
            }
            current_count = 1;
        }
    }
    if (current_count > max_count) {
        mode = temp[n - 1];
    }
    
    free(temp);
    return mode;
}


// (vii) Removing all duplicates (In-place sorting approach) -> O(n log n)

int remove_duplicates(int arr[], int n) {
    if (n == 0 || n == 1) return n;
    
    qsort(arr, n, sizeof(int), compare);
    
    int j = 0;
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] != arr[i + 1]) {
            arr[j++] = arr[i];
        }
    }
    arr[j++] = arr[n - 1];
    return j; // Returns the new size of the array
}


// (viii) Reversing the elements of the array -> O(n)

void reverse_array(int arr[], int n) {
    int start = 0, end = n - 1;
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}


// (ix) Partitioning the array with respect to a given random pivot element 
// Conditions: elements >= pivot come first, elements < pivot come after -> O(n)

void partition_array(int arr[], int n, int pivot) {
    int left = 0, right = n - 1;
    while (left <= right) {
        // Move left index forward if elements are correctly >= pivot
        while (left <= right && arr[left] >= pivot) left++;
        // Move right index backward if elements are correctly < pivot
        while (left <= right && arr[right] < pivot) right--;
        
        if (left < right) {
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            left++;
            right--;
        }
    }
}


int main() {
    // Sample test dataset
    int arr[] = {35, 10, 45, 20, 10, 50, 20, 45, 10, 60};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("--- INITIALIZATION ---\n");
    printf("Original Unsorted Array: ");
    print_array(arr, n);
    printf("\n--- OPERATIONS VALIDATION ---\n");

    // (i) Maximum
    printf("(i)   Maximum Element: %d\n", find_max(arr, n));

    // (ii) Two Largest
    int first, second;
    find_two_largest(arr, n, &first, &second);
    printf("(ii)  First Largest: %d, Second Largest: %d\n", first, second);

    // (iii) Mean
    printf("(iii) Mean: %.2f\n", find_mean(arr, n));

    // (iv) Median
    printf("(iv)  Median: %.2f\n", find_median(arr, n));

    // (v) Standard Deviation
    printf("(v)   Standard Deviation: %.4f\n", find_std_dev(arr, n));

    // (vi) Mode
    printf("(vi)  Mode (Most frequent element): %d\n", find_mode(arr, n));

    // (viii) Reverse Array
    int rev_arr[10];
    for(int i=0; i<n; i++) rev_arr[i] = arr[i];
    reverse_array(rev_arr, n);
    printf("(viii) Reversed Array: ");
    print_array(rev_arr, n);

    // (ix) Partition around a random pivot (e.g., pivot = 30)
    int part_arr[10];
    for(int i=0; i<n; i++) part_arr[i] = arr[i];
    int pivot = 30;
    partition_array(part_arr, n, pivot);
    printf("(ix)  Partitioned Array (Pivot = %d, Elements >= %d first): ", pivot, pivot);
    print_array(part_arr, n);

    // (vii) Remove Duplicates (Modifies the array structure)
    int dup_arr[10];
    for(int i=0; i<n; i++) dup_arr[i] = arr[i];
    int new_size = remove_duplicates(dup_arr, n);
    printf("(vii) Array after duplicate removal: ");
    for (int i = 0; i < new_size; i++) printf("%d ", dup_arr[i]);
    printf("\n");

    return 0;
}
