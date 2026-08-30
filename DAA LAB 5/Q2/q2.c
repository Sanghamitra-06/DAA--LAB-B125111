#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[high]);
    return i;
}

int quickSelect(int arr[], int low, int high, int k) {
    if (k > 0 && k <= (high - low + 1)) {
        int index = partition(arr, low, high);
        if (index - low == k - 1) {
            return arr[index];
        }
        if (index - low > k - 1) {
            return quickSelect(arr, low, index - 1, k);
        }
        return quickSelect(arr, index + 1, high, k - (index - low + 1));
    }
    return -1;
}

int main() {
    int n, k;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    int *arr = (int *)malloc(n * sizeof(int));
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("Enter K: ");
    scanf("%d", &k);

    if (k > 0 && k <= n) {
        int result = quickSelect(arr, 0, n - 1, k);
        printf("%d'th smallest element is %d\n", k, result);
    } else {
        printf("Invalid value of K\n");
    }

    free(arr);
    return 0;
}
