#include <stdio.h>
#include <stdlib.h>

#define MAX_V 100005

int parent[MAX_V];
int parity_arr[MAX_V];

void init(int n) {
    for (int i = 0; i <= n; i++) {
        parent[i] = i;
        parity_arr[i] = 0;
    }
}

int find_set(int v) {
    if (v == parent[v]) {
        return v;
    }
    int root = find_set(parent[v]);
    parity_arr[v] ^= parity_arr[parent[v]];
    return parent[v] = root;
}

int add_edge(int u, int v) {
    int root_u = find_set(u);
    int root_v = find_set(v);

    if (root_u == root_v) {
        if (parity_arr[u] == parity_arr[v]) {
            return 0;
        }
        return 1;
    } else {
        parent[root_u] = root_v;
        parity_arr[root_u] = parity_arr[u] ^ parity_arr[v] ^ 1;
        return 1;
    }
}

int main() {
    int V, E;
    if (scanf("%d %d", &V, &E) != 2) return 0;

    init(V);

    for (int i = 0; i < E; i++) {
        int u, v;
        if (scanf("%d %d", &u, &v) != 2) break;

        if (add_edge(u, v)) {
            printf("Edge (%d, %d) added successfully.\n", u, v);
        } else {
            printf("Edge (%d, %d) violates bipartiteness and is skipped.\n", u, v);
        }
    }

    return 0;
}
