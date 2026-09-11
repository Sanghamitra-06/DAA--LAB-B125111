#include <stdio.h>
#include <stdlib.h>

int move_count = 0;

void print_switches(int switches[], int n) {
    printf("[Move %3d]: State -> ", move_count);
    for (int i = 0; i < n; i++) {
        printf("%d ", switches[i]);
    }
    printf("\n");
}

void toggle_switch(int switches[], int n, int idx) {
    switches[idx] ^= 1;
    move_count++;
    print_switches(switches, n);
}

void turn_off(int switches[], int n, int i);
void turn_on(int switches[], int n, int i);

void turn_off(int switches[], int n, int i) {
    if (i < 1) return;
    if (i == 1) {
        if (switches[n - 1] == 1) {
            toggle_switch(switches, n, n - 1);
        }
        return;
    }
    
    turn_off(switches, n, i - 2);
    if (switches[n - (i - 1)] == 0) {
        turn_on(switches, n, i - 1);
    }
    
    toggle_switch(switches, n, n - i);
    turn_off(switches, n, i - 1);
}

void turn_on(int switches[], int n, int i) {
    if (i < 1) return;
    if (i == 1) {
        if (switches[n - 1] == 0) {
            toggle_switch(switches, n, n - 1);
        }
        return;
    }
    
    turn_on(switches, n, i - 1);
    turn_off(switches, n, i - 2);
    toggle_switch(switches, n, n - i);
    turn_off(switches, n, i - 1);
}

int main() {
    int n = 4;
    int *switches = (int *)malloc(n * sizeof(int));
    
    for (int i = 0; i < n; i++) {
        switches[i] = 1;
    }
    
    printf("--- Deactivating Security Switches ---\n");
    print_switches(switches, n);
    
    turn_off(switches, n, n);
    
    printf("\nTotal moves executed: %d\n", move_count);
    free(switches);
    return 0;
}
