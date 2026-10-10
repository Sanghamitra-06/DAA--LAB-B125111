#include <stdio.h>
#include <stdlib.h>
void minHeapify(int heap[], int size, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;
    if (left < size && heap[left] < heap[smallest]) smallest = left;
    if (right < size && heap[right] < heap[smallest]) smallest = right;
    if (smallest != idx) {
        int temp = heap[idx]; heap[idx] = heap[smallest]; heap[smallest] = temp;
        minHeapify(heap, size, smallest);
    }
}
int extractMin(int heap[], int* size) {
    int minVal = heap[0];
    heap[0] = heap[*size - 1];
    (*size)--;
    minHeapify(heap, *size, 0);
    return minVal;
}
void insertHeap(int heap[], int* size, int val) {
    heap[*size] = val;
    int i = *size;
    (*size)++;
    while (i > 0 && heap[(i - 1) / 2] > heap[i]) {
        int temp = heap[i]; heap[i] = heap[(i - 1) / 2]; heap[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

int connectSticks(int sticks[], int n) {
    int* heap = (int*)malloc(n * sizeof(int));
    int heapSize = 0;
    for (int i = 0; i < n; i++) insertHeap(heap, &heapSize, sticks[i]);
    
    int totalCost = 0;
    while (heapSize > 1) {
        int first = extractMin(heap, &heapSize);
        int second = extractMin(heap, &heapSize);
        int cost = first + second;
        totalCost += cost;
        insertHeap(heap, &heapSize, cost);
    }
    free(heap);
    return totalCost;
}

int main() {
    int sticks[] = {2, 4, 3, 3};
    int ans = connectSticks(sticks, 4);
    printf("Minimum Total Cost to Connect Sticks: %d\n\n", ans);
    return 0;
}
