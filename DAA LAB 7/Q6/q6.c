#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int year;
    int type; 
} Event;

int compare_events(const void *a, const void *b) {
    Event *e1 = (Event *)a;
    Event *e2 = (Event *)b;
    if (e1->year != e2->year) {
        return e1->year - e2->year;
    }
    return e1->type - e2->type;
}

void find_best_time(int births[], int deaths[], int n) {
    int total_events = 2 * n;
    Event *events = (Event *)malloc(total_events * sizeof(Event));

    for (int i = 0; i < n; i++) {
        events[2 * i].year = births[i];
        events[2 * i].type = 1;
        events[2 * i + 1].year = deaths[i];
        events[2 * i + 1].type = -1;
    }

    qsort(events, total_events, sizeof(Event), compare_events);

    int current_alive = 0;
    int max_alive = 0;
    int best_year = events[0].year;

    for (int i = 0; i < total_events; i++) {
        current_alive += events[i].type;
        if (current_alive > max_alive) {
            max_alive = current_alive;
            best_year = events[i].year;
        }
    }

    printf("Best year to be alive: %d (Scientists alive: %d)\n", best_year, max_alive);
    free(events);
}

int main() {
    int births[] = {1643, 1879, 1646, 1856};
    int deaths[] = {1727, 1955, 1716, 1943};
    int n = 4;

    printf("--- Finding Best Time to be Alive ---\n");
    find_best_time(births, deaths, n);
    return 0;
}
