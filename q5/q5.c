#include <stdio.h>
int find_partition_point(int arr[], int n) {
    int low = 0;
    int high = n - 1;
    int result = -1; // Represents not found if array has all 0s
 while (low <= high) {
        int mid = low + (high - low) / 2;
            if (arr[mid] == 1) {
            result = mid;     
            high = mid - 1;   
        } else {
            low = mid + 1;    
        }
    }
    return result;
}

int main() {
    int arr[] = {0, 0, 0, 0, 0, 1, 1, 1, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int index = find_partition_point(arr, n);

    if (index != -1) {
        printf("The transition point from 0 to 1 is at index: %d\n", index);
        printf("Verification -> arr[%d] = %d, arr[%d] = %d\n", index - 1, arr[index - 1], index, arr[index]);
    } else {
        printf("No transition found (array might contain only 0s).\n");
    }

    return 0;
}