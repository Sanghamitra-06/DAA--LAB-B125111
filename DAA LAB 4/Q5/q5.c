#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int end;
} Interval;

int compareIntervals(const void* a, const void* b) {
    return ((Interval*)a)->start - ((Interval*)b)->start;
}

void mergeIntervals(Interval arr[], int n) {
    if (n <= 0) return;

    qsort(arr, n, sizeof(Interval), compareIntervals);

    Interval* merged = (Interval*)malloc(n * sizeof(Interval));
    int count = 0;
    merged[count] = arr[0];

    for (int i = 1; i < n; i++) {
        Interval current = arr[i];
        Interval* last_merged = &merged[count];

        if (current.start <= last_merged->end) {
            // Overlap detected: expand the boundary
            if (current.end > last_merged->end) {
                last_merged->end = current.end;
            }
        } else {
            // No overlap: add a fresh window segment
            count++;
            merged[count] = current;
        }
    }

    printf("Merged Intervals: ");
    for (int i = 0; i <= count; i++) {
        printf("(%d, %d) ", merged[i].start, merged[i].end);
    }
    printf("\n");
    free(merged);
}

int main() {
    Interval I[] = {{1, 3}, {2, 6}, {8, 10}, {7, 18}};
    int n = sizeof(I) / sizeof(I[0]);
    mergeIntervals(I, n);
    return 0;
}
