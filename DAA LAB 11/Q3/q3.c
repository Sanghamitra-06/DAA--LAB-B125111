#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Queue {
    int* data;
    int front;
    int rear;
    int capacity;
} Queue;

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

int isAdjacent(const char* a, const char* b, int len) {
    int diff = 0;
    for (int i = 0; i < len; i++) {
        if (a[i] != b[i]) {
            diff++;
            if (diff > 1) return 0;
        }
    }
    return diff == 1;
}

int solveQuestion3(char** dictionary, int dictSize, const char* startWord, const char* targetWord, int wordLen) {
    if (strcmp(startWord, targetWord) == 0) return 0;

    int targetIdx = -1;
    for (int i = 0; i < dictSize; i++) {
        if (strcmp(dictionary[i], targetWord) == 0) {
            targetIdx = i;
            break;
        }
    }
    if (targetIdx == -1) return -1;

    int startIdx = -1;
    for (int i = 0; i < dictSize; i++) {
        if (strcmp(dictionary[i], startWord) == 0) {
            startIdx = i;
            break;
        }
    }

    int totalNodes = dictSize;
    if (startIdx == -1) {
        totalNodes++;
    }

    int* distS = (int*)malloc(totalNodes * sizeof(int));
    int* distT = (int*)malloc(totalNodes * sizeof(int));
    for (int i = 0; i < totalNodes; i++) {
        distS[i] = -1;
        distT[i] = -1;
    }

    Queue* qS = createQueue(totalNodes);
    Queue* qT = createQueue(totalNodes);

    int sNode = (startIdx != -1) ? startIdx : totalNodes - 1;
    int tNode = targetIdx;

    distS[sNode] = 0;
    enqueue(qS, sNode);

    distT[tNode] = 0;
    enqueue(qT, tNode);

    while (!isEmpty(qS) && !isEmpty(qT)) {
        if (qS->rear - qS->front <= qT->rear - qT->front) {
            int u = dequeue(qS);
            const char* uWord = (u == totalNodes - 1 && startIdx == -1) ? startWord : dictionary[u];

            for (int v = 0; v < dictSize; v++) {
                if (distS[v] == -1) {
                    if (isAdjacent(uWord, dictionary[v], wordLen)) {
                        distS[v] = distS[u] + 1;
                        if (distT[v] != -1) {
                            int ans = distS[v] + distT[v];
                            free(distS); free(distT); free(qS->data); free(qS); free(qT->data); free(qT);
                            return ans;
                        }
                        enqueue(qS, v);
                    }
                }
            }
        } else {
            int u = dequeue(qT);
            const char* uWord = (u == totalNodes - 1 && startIdx == -1) ? startWord : dictionary[u];

            for (int v = 0; v < totalNodes; v++) {
                if (distT[v] == -1) {
                    const char* vWord = (v == totalNodes - 1 && startIdx == -1) ? startWord : dictionary[v];
                    if (isAdjacent(uWord, vWord, wordLen)) {
                        distT[v] = distT[u] + 1;
                        if (distS[v] != -1) {
                            int ans = distS[v] + distT[v];
                            free(distS); free(distT); free(qS->data); free(qS); free(qT->data); free(qT);
                            return ans;
                        }
                        enqueue(qT, v);
                    }
                }
            }
        }
    }

    free(distS); free(distT); free(qS->data); free(qS); free(qT->data); free(qT);
    return -1;
}

int main() {
    int dictSize = 4;
    int wordLen = 3;
    char* dictionary[] = {"hot", "dot", "dog", "cog"};
    const char* startWord = "hit";
    const char* targetWord = "cog";

    int result = solveQuestion3(dictionary, dictSize, startWord, targetWord, wordLen);
    printf("Minimum mutations required: %d\n", result);

    return 0;
}
