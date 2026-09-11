#include <stdio.h>
#include <math.h>

int move_count = 0;

void hanoi3(int n, char source, char dest, char aux) {
    if (n == 0) return;
    hanoi3(n - 1, source, aux, dest);
    printf("Move disk %d from %c to %c\n", n, source, dest);
    move_count++;
    hanoi3(n - 1, aux, dest, source);
}

void reves_puzzle(int n, char source, char dest, char aux1, char aux2) {
    if (n == 0) return;
    if (n == 1) {
        printf("Move disk %d from %c to %c\n", n, source, dest);
        move_count++;
        return;
    }

    int k = (int)round(n + 1 - sqrt(2 * n + 1));
    if (k < 0) k = 0;

    reves_puzzle(k, source, aux2, dest, aux1);
    hanoi3(n - k, source, dest, aux1);
    reves_puzzle(k, aux2, dest, source, aux1);
}

int main() {
    int n = 8;
    printf("--- Solving Reve's Puzzle for %d disks ---\n", n);
    reves_puzzle(n, 'A', 'B', 'C', 'D');
    printf("\nTotal moves executed: %d\n", move_count);
    return 0;
}
