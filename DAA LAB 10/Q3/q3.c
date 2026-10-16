#include <stdio.h>
#include <stdlib.h>

#define MAX_V 100005

int parent[MAX_V];
int comp_size[MAX_V];
long long comp_weight[MAX_V];
int weight[MAX_V];

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
        comp_size[root_j] += comp_size[root_i];
        comp_weight[root_j] += comp_weight[root_i];
    }
}

int main() {
    int V, E, K_limit;
    if (scanf("%d %d %d", &V, &E, &K_limit) != 3) return 0;

    for (int i = 1; i <= V; i++) {
        if (scanf("%d", &weight[i]) != 1) return 0;
        parent[i] = i;
        comp_size[i] = 1;
        comp_weight[i] = weight[i];
    }

    for (int e = 0; e < E; e++) {
        int u, v;
        if (scanf("%d %d", &u, &v) != 2) break;

        union_sets(u, v);

        long long max_w = -1;
        for (int i = 1; i <= V; i++) {
            if (parent[i] == i) {
                if (comp_size[i] <= K_limit && comp_weight[i] > max_w) {
                    max_w = comp_weight[i];
                }
            }
        }
        printf("%lld\n", max_w);
    }
    return 0;
}
