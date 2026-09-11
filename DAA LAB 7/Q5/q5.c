#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool simulate_shot(int shot_pos, int *target_pos, int n) {
    if (shot_pos == *target_pos) {
        return true;
    }
    if (*target_pos == 1) {
        *target_pos = 2;
    } else if (*target_pos == n) {
        *target_pos = n - 1;
    } else {
        if (rand() % 2 == 0) {
            (*target_pos)--;
        } else {
            (*target_pos)++;
        }
    }
    return false;
}

void find_moving_target(int n, int initial_target_pos) {
    int target_pos = initial_target_pos;
    int shot_count = 0;
    bool hit = false;

    for (int i = 2; i <= n - 1; i++) {
        shot_count++;
        if (simulate_shot(i, &target_pos, n)) {
            printf("Target hit at position %d on shot %d\n", i, shot_count);
            hit = true;
            break;
        }
    }

    if (!hit) {
        for (int i = n - 1; i >= 2; i--) {
            shot_count++;
            if (simulate_shot(i, &target_pos, n)) {
                printf("Target hit at position %d on shot %d\n", i, shot_count);
                hit = true;
                break;
            }
        }
    }

    if (!hit) {
        printf("Target not hit within deterministic bounds\n");
    }
}

int main() {
    int n = 5;
    int initial_target_pos = 3;
    printf("--- Hitting a Moving Target (n=%d, initial=%d) ---\n", n, initial_target_pos);
    find_moving_target(n, initial_target_pos);
    return 0;
}
