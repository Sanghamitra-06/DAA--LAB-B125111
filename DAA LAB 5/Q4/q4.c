#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
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

    // 2. Read elements from file
    int *arr = (int *)malloc(n * sizeof(int));
    fin = fopen("input.txt", "r");
    for (int i = 0; i < n; i++) {
        fscanf(fin, "%d", &arr[i]);
    }
    fclose(fin);

    // 3. Perform Heap Sort
    heapSort(arr, n);

    // 4. Write sorted elements to output file
    FILE *fout = fopen("output_heap.txt", "w");
    for (int i = 0; i < n; i++) {
        fprintf(fout, "%d\n", arr[i]);
    }
    fclose(fout);

    printf("Heap Sort complete. Check output_heap.txt\n");
    free(arr);
    return 0;
}
