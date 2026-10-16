#include <stdio.h>
#include <stdlib.h>

#define MAX_V 100005
#define MAX_E 200005

int parent[MAX_V];
long long comp_weight[MAX_V];
int weight[MAX_V];
int P[MAX_V];
int active[MAX_V];
long long ans[MAX_V];

int head[MAX_V];
int to_val[MAX_E * 2];
int next_edge[MAX_E * 2];
int edge_idx = 0;

void add_edge(int u, int v) {
    to_val[edge_idx] = v;
    next_edge[edge_idx] = head[u];
    head[u] = edge_idx++;
}

int find_set(int i) {
    if (parent[i] == i)
        return i;
    return parent[i] = find_set(parent[i]);
}

long long max_weight = 0;

void union_sets(int i, int j) {
    int root_i = find_set(i);
    int root_j = find_set(j);
    if (root_i != root_j) {
        parent[root_i] = root_j;
        comp_weight[root_j] += comp_weight[root_i];
        if (comp_weight[root_j] > max_weight) {
            max_weight = comp_weight[root_j];
        }
    }
}

int main() {
    int V, E;
    if (scanf("%d %d", &V, &E) != 2) return 0;

    for (int i = 1; i <= V; i++) {
        if (scanf("%d", &weight[i]) != 1) return 0;
        parent[i] = i;
        comp_weight[i] = weight[i];
        head[i] = -1;
    }

    for (int i = 0; i < E; i++) {
        int u, v;
        if (scanf("%d %d", &u, &v) != 2) break;
        add_edge(u, v);
        add_edge(v, u);
    }

    for (int i = 1; i <= V; i++) {
        if (scanf("%d", &P[i]) != 1) return 0;
    }

    for (int i = V; i >= 1; i--) {
        int u = P[i];
        active[u] = 1;
        if (comp_weight[u] > max_weight) {
            max_weight = comp_weight[u];
        }

        for (int e = head[u]; e != -1; e = next_edge[e]) {
            int v = to_val[e];
            if (active[v]) {
                union_sets(u, v);
            }
        }
        ans[i] = max_weight;
    }

    for (int i = 1; i <= V; i++) {
        printf("%lld\n", ans[i]);
    }

    return 0;
}
