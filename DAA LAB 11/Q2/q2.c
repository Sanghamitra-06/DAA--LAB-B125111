#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Edge {
    int to;
    struct Edge* next;
} Edge;

typedef struct Graph {
    int numVertices;
    Edge** adjLists;
} Graph;

typedef struct Queue {
    int* data;
    int front;
    int rear;
    int capacity;
} Queue;

Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;
    graph->adjLists = (Edge**)malloc(vertices * sizeof(Edge*));
    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
    }
    return graph;
}

void addEdge(Graph* graph, int src, int dest) {
    Edge* newEdge = (Edge*)malloc(sizeof(Edge));
    newEdge->to = dest;
    newEdge->next = graph->adjLists[src];
    graph->adjLists[src] = newEdge;

    newEdge = (Edge*)malloc(sizeof(Edge));
    newEdge->to = src;
    newEdge->next = graph->adjLists[dest];
    graph->adjLists[dest] = newEdge;
}

Queue* createQueue(int capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = 0;
    queue->rear = 0;
    queue->data = (int*)malloc(capacity * sizeof(int));
    return queue;
}

int isEmpty(Queue* queue) {
    return queue->front == queue->rear;
}

void enqueue(Queue* queue, int value) {
    queue->data[queue->rear++] = value;
}

int dequeue(Queue* queue) {
    return queue->data[queue->front++];
}

void solveQuestion2(Graph* graph, int* hubs, int numHubs, int radius) {
    int V = graph->numVertices;
    int* owner = (int*)malloc(V * sizeof(int));
    int* dist = (int*)malloc(V * sizeof(int));
    Queue* queue = createQueue(V);

    for (int i = 0; i < V; i++) {
        owner[i] = -1;
        dist[i] = INT_MAX;
    }

    for (int i = 0; i < numHubs; i++) {
        int hubIdx = hubs[i];
        if (dist[hubIdx] == INT_MAX) {
            dist[hubIdx] = 0;
            owner[hubIdx] = i + 1; 
            enqueue(queue, hubIdx);
        } else if (dist[hubIdx] == 0) {
            if (i + 1 < owner[hubIdx]) {
                owner[hubIdx] = i + 1;
            }
        }
    }

    while (!isEmpty(queue)) {
        int u = dequeue(queue);

        Edge* temp = graph->adjLists[u];
        while (temp != NULL) {
            int v = temp->to;
            if (dist[u] + 1 < dist[v]) {
                dist[v] = dist[u] + 1;
                owner[v] = owner[u];
                enqueue(queue, v);
            } else if (dist[u] + 1 == dist[v]) {
                if (owner[u] < owner[v]) {
                    owner[v] = owner[u];
                }
            }
            temp = temp->next;
        }
    }

    printf("Vertex\tOwner Hub\n");
    for (int i = 0; i < V; i++) {
        if (dist[i] > radius || owner[i] == -1) {
            printf("%d\t-1\n", i);
        } else {
            printf("%d\t%d\n", i, owner[i]);
        }
    }

    free(owner);
    free(dist);
    free(queue->data);
    free(queue);
}

int main() {
    int vertices = 6;
    Graph* graph = createGraph(vertices);

    addEdge(graph, 0, 1);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    addEdge(graph, 4, 5);

    int hubs[] = {1, 4}; 
    int numHubs = 2;
    int radius = 2;

    solveQuestion2(graph, hubs, numHubs, radius);

    return 0;
}
