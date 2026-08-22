#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int time;
    int type; // +1 for entry, -1 for exit
} Event;

int compareEvents(const void* a, const void* b) {
    Event* e1 = (Event*)a;
    Event* e2 = (Event*)b;
    if (e1->time != e2->time) {
        return e1->time - e2->time;
    }
    return e1->type - e2->type; // If times match, exit (-1) comes before entry (+1)
}

void findPeakTime(int entry[], int exit[], int n) {
    int total_events = 2 * n;
    Event* events = (Event*)malloc(total_events * sizeof(Event));

    for (int i = 0; i < n; i++) {
        events[2 * i] = (Event){entry[i], 1};
        events[2 * i + 1] = (Event){exit[i], -1};
    }

    qsort(events, total_events, sizeof(Event), compareEvents);

    int current_people = 0, max_people = 0, peak_time = -1;

    for (int i = 0; i < total_events; i++) {
        current_people += events[i].type;
        if (current_people > max_people) {
            max_people = current_people;
            peak_time = events[i].time;
        }
    }

    printf("Peak Population: %d people simultaneously at time: %d\n", max_people, peak_time);
    free(events);
}

int main() {
    int entry[] = {1, 2, 3};
    int exit[] = {4, 6, 5};
    int n = sizeof(entry) / sizeof(entry[0]);
    findPeakTime(entry, exit, n);
    return 0;
}
