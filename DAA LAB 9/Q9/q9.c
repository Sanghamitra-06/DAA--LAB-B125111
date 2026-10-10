#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Node {
    int weight;
    int is_original;
    int id;
    int depth;
    struct Node *left;
    struct Node *right;
} Node;

Node* createNode(int weight, int is_original, int id) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->weight = weight;
    node->is_original = is_original;
    node->id = id;
    node->depth = 0;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void computeDepths(Node *root, int currentDepth, int depths[]) {
    if (!root) return;
    if (root->is_original) {
        depths[root->id] = currentDepth;
        return;
    }
    computeDepths(root->left, currentDepth + 1, depths);
    computeDepths(root->right, currentDepth + 1, depths);
}

int isCompatible(Node* nodes[], int i, int j) {
    for (int k = i + 1; k < j; k++) {
        if (nodes[k]->is_original) {
            return 0;
        }
    }
    return 1;
}

int huTuckerCost(int weights[], int n) {
    Node* nodes[2 * n];
    for (int i = 0; i < n; i++) {
        nodes[i] = createNode(weights[i], 1, i);
    }

    int active_count = n;

    while (active_count > 1) {
        int min_sum = INT_MAX;
        int best_i = -1, best_j = -1;

        for (int i = 0; i < active_count; i++) {
            for (int j = i + 1; j < active_count; j++) {
                if (isCompatible(nodes, i, j)) {
                    int sum = nodes[i]->weight + nodes[j]->weight;
                    if (sum < min_sum) {
                        min_sum = sum;
                        best_i = i;
                        best_j = j;
                    }
                }
            }
        }

        Node *parent = createNode(min_sum, 0, -1);
        parent->left = nodes[best_i];
        parent->right = nodes[best_j];

        nodes[best_i] = parent;

        for (int k = best_j; k < active_count - 1; k++) {
            nodes[k] = nodes[k + 1];
        }
        active_count--;
    }

    int depths[n];
    computeDepths(nodes[0], 0, depths);

    int total_cost = 0;
    for (int i = 0; i < n; i++) {
        total_cost += weights[i] * depths[i];
    }

    return total_cost;
}

int main() {
    int weights[] = {10, 15, 20, 25, 30};
    int n = sizeof(weights) / sizeof(weights[0]);

    int cost = huTuckerCost(weights, n);
    printf("Optimal Weighted Path Length: %d\n", cost);

    return 0;
}