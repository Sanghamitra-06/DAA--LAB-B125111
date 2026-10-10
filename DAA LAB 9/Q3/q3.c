#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int dist;
    int fuel;
} Station;

int compareStations(const void* a, const void* b) {
    return ((Station*)a)->dist - ((Station*)b)->dist;
}

int minRefuelStops(int target, int startFuel, Station stations[], int n) {
    qsort(stations, n, sizeof(Station), compareStations);
    
    int* maxHeap = (int*)malloc(n * sizeof(int));
    int heapSize = 0;
    
    int stops = 0, i = 0;
    int currentFuel = startFuel;
    while (currentFuel < target) {
        
        while (i < n && stations[i].dist <= currentFuel) {
            maxHeap[heapSize++] = stations[i].fuel;
            
            int child = heapSize - 1;
            while (child > 0) {
                int parent = (child - 1) / 2;
                if (maxHeap[child] <= maxHeap[parent]) break;
                int temp = maxHeap[child]; maxHeap[child] = maxHeap[parent]; maxHeap[parent] = temp;
                child = parent;
            }
            i++;
        }
        
        if (heapSize == 0) {
            free(maxHeap);
            return -1;
        }
        int maxFuel = maxHeap[0];
        maxHeap[0] = maxHeap[--heapSize];
       
        int parent = 0;
        while (2 * parent + 1 < heapSize) {
            int left = 2 * parent + 1;
            int right = left + 1;
            int largest = left;
            if (right < heapSize && maxHeap[right] > maxHeap[left]) largest = right;
            if (maxHeap[parent] >= maxHeap[largest]) break;
            int temp = maxHeap[parent]; maxHeap[parent] = maxHeap[largest]; maxHeap[largest] = temp;
            parent = largest;
        }
        
        currentFuel += maxFuel;
        stops++;
    }
    
    free(maxHeap);
    return stops;
}

int main() {
    int target = 100;
    int startFuel = 10;
    Station stations[] = {{10, 60}, {20, 30}, {30, 30}, {60, 40}};
    int ans = minRefuelStops(target, startFuel, stations, 4);
    printf("Minimum Refuelling Stops Required: %d\n\n", ans);
    return 0;
}
