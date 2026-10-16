#include <stdio.h>
#include <stdlib.h>

int parent[40005];
int grid[205][205];
int count = 0;

int find_set(int i) {
    if (parent[i] == i)
        return i;
    return parent[i] = find_set(parent[i]);
}

void union_sets(int i, int j) {
    int root_i = find_set(i);
    int root_j = find_set(j);
    if (root_i != root_j) {
        parent[root_i] = root_j;
        count--;
    }
}

int main() {
    int R, C, K;
    if (scanf("%d %d %d", &R, &C, &K) != 3) return 0;

    for (int i = 0; i < R * C; i++) {
        parent[i] = i;
    }

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    for (int k = 0; k < K; k++) {
        int r, c;
        if (scanf("%d %d", &r, &c) != 2) break;

        if (grid[r][c] == 1) {
            printf("%d\n", count);
            continue;
        }

        grid[r][c] = 1;
        count++;
        int curr_id = r * C + c;

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nr < R && nc >= 0 && nc < C && grid[nr][nc] == 1) {
                int neighbor_id = nr * C + nc;
                union_sets(curr_id, neighbor_id);
            }
        }
        printf("%d\n", count);
    }
    return 0;
}
