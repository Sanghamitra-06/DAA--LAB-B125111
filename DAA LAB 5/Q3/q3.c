#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n;
    printf("Enter number of random elements (N): ");
    scanf("%d", &n);

    // 1. Generate random elements and write to file
    FILE *fin = fopen("input.txt", "w");
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        fprintf(fin, "%d\n", rand() % 10000);
    }
    fclose(fin);

    // 2. Read elements from file into memory
    int *arr = (int *)malloc(n * sizeof(int));
    fin = fopen("input.txt", "r");
    for (int i = 0; i < n; i++) {
        fscanf(fin, "%d", &arr[i]);
    }
    fclose(fin);

    // 3. Perform Quicksort
    quickSort(arr, 0, n - 1);

    // 4. Write sorted elements to output file
    FILE *fout = fopen("output_quick.txt", "w");
    for (int i = 0; i < n; i++) {
        fprintf(fout, "%d\n", arr[i]);
    }
    fclose(fout);

    printf("Quick Sort complete. Check output_quick.txt\n");
    free(arr);
    return 0;
}
