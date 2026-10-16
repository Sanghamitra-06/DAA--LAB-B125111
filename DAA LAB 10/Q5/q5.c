#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100005

int parent[MAX_N];
int A[MAX_N];
int res[MAX_N];

int comp_indices[MAX_N];
int comp_values[MAX_N];

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
    }
}

int cmp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int N, M;
    if (scanf("%d %d", &N, &M) != 2) return 0;

    for (int i = 1; i <= N; i++) {
        if (scanf("%d", &A[i]) != 1) return 0;
        parent[i] = i;
    }

    for (int i = 0; i < M; i++) {
        int u, v;
        if (scanf("%d %d", &u, &v) != 2) break;
        union_sets(u, v);
    }

    int *head = (int *)malloc((N + 1) * sizeof(int));
    int *next = (int *)malloc((N + 1) * sizeof(int));
    for (int i = 1; i <= N; i++) head[i] = 0;

    for (int i = 1; i <= N; i++) {
        int root = find_set(i);
        next[i] = head[root];
        head[root] = i;
    }

    for (int i = 1; i <= N; i++) {
        if (head[i] == 0) continue;

        int count = 0;
        int curr = head[i];
        while (curr != 0) {
            comp_indices[count] = curr;
            comp_values[count] = A[curr];
            count++;
            curr = next[curr];
        }

        qsort(comp_indices, count, sizeof(int), cmp);
        qsort(comp_values, count, sizeof(int), cmp);

        for (int j = 0; j < count; j++) {
            res[comp_indices[j]] = comp_values[j];
        }
    }

    for (int i = 1; i <= N; i++) {
        printf("%d ", res[i]);
    }
    printf("\n");

    free(head);
    free(next);
    return 0;
}
