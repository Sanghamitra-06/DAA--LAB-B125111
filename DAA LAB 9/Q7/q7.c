#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int size;
    int capacity;
} MaxHeap;

MaxHeap* createHeap(int capacity) {
    MaxHeap *h = (MaxHeap *)malloc(sizeof(MaxHeap));
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

void pushHeap(MaxHeap *h, int val) {
    h->size++;
    int i = h->size;
    h->data[i] = val;
    while (i > 1 && h->data[i] > h->data[i / 2]) {
        swap(&h->data[i], &h->data[i / 2]);
        i /= 2;
    }
}

int popHeap(MaxHeap *h) {
    if (h->size == 0) return -1;
    int top = h->data[1];
    h->data[1] = h->data[h->size];
    h->size--;

    int i = 1;
    while (2 * i <= h->size) {
        int left = 2 * i;
        int right = 2 * i + 1;
        int largest = i;

        if (left <= h->size && h->data[left] > h->data[largest])
            largest = left;
        if (right <= h->size && h->data[right] > h->data[largest])
            largest = right;

        if (largest != i) {
            swap(&h->data[i], &h->data[largest]);
            i = largest;
        } else {
            break;
        }
    }
    return top;
}

int getMin(int a, int b) {
    return (a < b) ? a : b;
}

int minimumDeviation(int* nums, int numsSize) {
    MaxHeap *h = createHeap(numsSize);
    int minVal = 2147483647;

    for (int i = 0; i < numsSize; i++) {
        int val = nums[i];
        if (val % 2 != 0) {
            val *= 2;
        }
        pushHeap(h, val);
        minVal = getMin(minVal, val);
    }

    int minDev = h->data[1] - minVal;

    while (h->data[1] % 2 == 0) {
        int maxVal = popHeap(h);
        int dev = maxVal - minVal;
        if (dev < minDev) {
            minDev = dev;
        }

        int newVal = maxVal / 2;
        minVal = getMin(minVal, newVal);
        pushHeap(h, newVal);
    }

    minDev = getMin(minDev, h->data[1] - minVal);

    free(h->data);
    free(h);
    return minDev;
}

int main() {
    int nums[] = {1, 2, 3, 4};
    int n = sizeof(nums) / sizeof(nums[0]);

    int result = minimumDeviation(nums, n);
    printf("Minimum deviation: %d\n", result);

    return 0;
}