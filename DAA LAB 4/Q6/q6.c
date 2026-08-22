#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int point;
    int type; // +1 for start endpoint, -1 for end endpoint
} Endpoint;

int compareEndpoints(const void* a, const void* b) {
    Endpoint* e1 = (Endpoint*)a;
    Endpoint* e2 = (Endpoint*)b;
    if (e1->point != e2->point) {
        return e1->point - e2->point;
    }
    // Since endpoints are inclusive, a starting interval (+1) should stack up before an ending one (-1) 
    return e2->type - e1->type; 
}

void findMostIntersectedPoint(int left[], int right[], int n) {
    int total_endpoints = 2 * n;
    Endpoint* endpoints = (Endpoint*)malloc(total_endpoints * sizeof(Endpoint));

    for (int i = 0; i < n; i++) {
        endpoints[2 * i] = (Endpoint){left[i], 1};
        endpoints[2 * i + 1] = (Endpoint){right[i], -1};
    }

    qsort(endpoints, total_endpoints, sizeof(Endpoint), compareEndpoints);

    int active_intervals = 0, max_intervals = 0, best_point = -1;

    for (int i = 0; i < total_endpoints; i++) {
        active_intervals += endpoints[i].type;
        if (active_intervals > max_intervals) {
            max_intervals = active_intervals;
            best_point = endpoints[i].point;
        }
    }

    printf("Point containing the maximum number of intervals: p = %d (Involved in %d intervals)\n", best_point, max_intervals);
    free(endpoints);
}

int main() {
    int left[] = {10, 20, 50, 15};
    int right[] = {40, 60, 90, 70};
    int n = sizeof(left) / sizeof(left[0]);
    findMostIntersectedPoint(left, right, n);
    return 0;
}
