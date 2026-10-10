#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int end;
} Interval;

int compareIntervals(const void *a, const void *b) {
    return ((Interval *)a)->start - ((Interval *)b)->start;
}

typedef struct {
    int *data;
    int size;
    int capacity;
} MinHeap;

MinHeap* createHeap(int capacity) {
    MinHeap *h = (MinHeap *)malloc(sizeof(MinHeap));
    h->data = (int *)malloc(sizeof(int) * (capacity + 1));
    h->size = 0;
    h->capacity = capacity;
    return h;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void pushHeap(MinHeap *h, int val) {
    h->size++;
    int i = h->size;
    h->data[i] = val;
    while (i > 1 && h->data[i] < h->data[i / 2]) {
        swap(&h->data[i], &h->data[i / 2]);
        i /= 2;
    }
}

int popHeap(MinHeap *h) {
    if (h->size == 0) return -1;
    int top = h->data[1];
    h->data[1] = h->data[h->size];
    h->size--;

    int i = 1;
    while (2 * i <= h->size) {
        int left = 2 * i;
        int right = 2 * i + 1;
        int smallest = i;

        if (left <= h->size && h->data[left] < h->data[smallest])
            smallest = left;
        if (right <= h->size && h->data[right] < h->data[smallest])
            smallest = right;

        if (smallest != i) {
            swap(&h->data[i], &h->data[smallest]);
            i = smallest;
        } else {
            break;
        }
    }
    return top;
}

int minMeetingRooms(Interval intervals[], int n) {
    if (n == 0) return 0;

    qsort(intervals, n, sizeof(Interval), compareIntervals);

    MinHeap *heap = createHeap(n);
    pushHeap(heap, intervals[0].end);

    for (int i = 1; i < n; i++) {
        if (intervals[i].start >= heap->data[1]) {
            popHeap(heap);
        }
        pushHeap(heap, intervals[i].end);
    }

    int rooms = heap->size;

    free(heap->data);
    free(heap);
    return rooms;
}

int main() {
    Interval intervals[] = {{0, 30}, {5, 10}, {15, 20}};
    int n = sizeof(intervals) / sizeof(intervals[0]);

    int result = minMeetingRooms(intervals, n);
    printf("Minimum meeting rooms required: %d\n", result);

    return 0;
}