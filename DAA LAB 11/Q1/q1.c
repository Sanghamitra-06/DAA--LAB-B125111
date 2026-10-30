#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF INT_MAX

typedef struct Edge {
    int to;
    int weight;
    struct Edge* next;
} Edge;

typedef struct Graph {
    int numVertices;
    Edge** adjLists;
} Graph;

typedef struct Node {
    int vertex;
    int parity;
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct Deque {
    Node* front;
    Node* rear;
} Deque;

Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;
    graph->adjLists = (Edge**)malloc(vertices * sizeof(Edge*));
    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
    }
    return graph;
}

void addEdge(Graph* graph, int src, int dest, int weight) {
    Edge* newEdge = (Edge*)malloc(sizeof(Edge));
    newEdge->to = dest;
    newEdge->weight = weight;
    newEdge->next = graph->adjLists[src];
    graph->adjLists[src] = newEdge;
}

Deque* createDeque() {
    Deque* deque = (Deque*)malloc(sizeof(Deque));
    deque->front = NULL;
    deque->rear = NULL;
    return deque;
}

int isEmpty(Deque* deque) {
    return deque->front == NULL;
}

void pushFront(Deque* deque, int v, int p) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->parity = p;
    newNode->next = deque->front;
    newNode->prev = NULL;
    if (isEmpty(deque)) {
        deque->rear = newNode;
    } else {
        deque->front->prev = newNode;
    }
    deque->front = newNode;
}

void pushBack(Deque* deque, int v, int p) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->parity = p;
    newNode->next = NULL;
    newNode->prev = deque->rear;
    if (isEmpty(deque)) {
        deque->front = newNode;
    } else {
        deque->rear->next = newNode;
    }
    deque->rear = newNode;
}

void popFront(Deque* deque, int* v, int* p) {
    if (isEmpty(deque)) return;
    Node* temp = deque->front;
    *v = temp->vertex;
    *p = temp->parity;
    deque->front = deque->front->next;
    if (deque->front == NULL) {
        deque->rear = NULL;
    } else {
        deque->front->prev = NULL;
    }
    free(temp);
}

void solveQuestion1(Graph* graph, int source, int penalty) {
    int V = graph->numVertices;
    int** dist = (int**)malloc(V * sizeof(int*));
    for (int i = 0; i < V; i++) {
        dist[i] = (int*)malloc(2 * sizeof(int));
        dist[i][0] = INF;
        dist[i][1] = INF;
    }

    Deque* deque = createDeque();
    dist[source][0] = 0;
    pushFront(deque, source, 0);

    while (!isEmpty(deque)) {
        int u, p;
        popFront(deque, &u, &p);

        Edge* temp = graph->adjLists[u];
        while (temp != NULL) {
            int v = temp->to;
            int w = temp->weight;
            int next_p = p;
            if (w == 1) {
                next_p = 1 - p;
            }

            if (dist[u][p] + w < dist[v][next_p]) {
                dist[v][next_p] = dist[u][p] + w;
                if (w == 0) {
                    pushFront(deque, v, next_p);
                } else {
                    pushBack(deque, v, next_p);
                }
            }
            temp = temp->next;
        }
    }

    printf("Vertex\tEffective Cost\n");
    for (int i = 0; i < V; i++) {
        int costEven = dist[i][0];
        int costOdd = (dist[i][1] == INF) ? INF : dist[i][1] + penalty;
        int minCost = (costEven < costOdd) ? costEven : costOdd;

        if (minCost == INF) {
            printf("%d\tUnreachable\n", i);
        } else {
            printf("%d\t%d\n", i, minCost);
        }
    }

    for (int i = 0; i < V; i++) {
        free(dist[i]);
    }
    free(dist);
    free(deque);
}

int main() {
    int vertices = 5;
    Graph* graph = createGraph(vertices);
    int penalty = 10;

    addEdge(graph, 0, 1, 1);
    addEdge(graph, 1, 2, 1);
    addEdge(graph, 0, 3, 0);
    addEdge(graph, 3, 2, 0);
    addEdge(graph, 2, 4, 1);

    solveQuestion1(graph, 0, penalty);

    return 0;
}
