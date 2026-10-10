#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char ch;
    int freq;
} CharFreq;

void maxHeapify(CharFreq heap[], int size, int idx) {
    int largest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;
    if (left < size && heap[left].freq > heap[largest].freq) largest = left;
    if (right < size && heap[right].freq > heap[largest].freq) largest = right;
    if (largest != idx) {
        CharFreq temp = heap[idx]; heap[idx] = heap[largest]; heap[largest] = temp;
        maxHeapify(heap, size, largest);
    }
}

void rearrangeString(char* str, int K) {
    int len = strlen(str);
    int count[256] = {0};
    for (int i = 0; i < len; i++) count[(unsigned char)str[i]]++;
    
    CharFreq heap[256];
    int heapSize = 0;
    for (int i = 0; i < 256; i++) {
        if (count[i] > 0) {
            heap[heapSize].ch = (char)i;
            heap[heapSize].freq = count[i];
            heapSize++;
        }
    }
    
   
    for (int i = (heapSize / 2) - 1; i >= 0; i--) maxHeapify(heap, heapSize, i);
    
    char* result = (char*)malloc((len + 1) * sizeof(char));
    int resIdx = 0;
    CharFreq* queue = (CharFreq*)malloc(len * sizeof(CharFreq));
    int head = 0, tail = 0;
    
    while (heapSize > 0) {
        CharFreq current = heap[0];
        result[resIdx++] = current.ch;
        
        current.freq--;
        queue[tail++] = current; 
        
        
        heap[0] = heap[heapSize - 1];
        heapSize--;
        maxHeapify(heap, heapSize, 0);
        if (tail - head >= K) {
            CharFreq release = queue[head++];
            if (release.freq > 0) {
                heap[heapSize++] = release;
                int i = heapSize - 1;
                while (i > 0 && heap[(i - 1) / 2].freq < heap[i].freq) {
                    CharFreq temp = heap[i]; heap[i] = heap[(i - 1) / 2]; heap[(i - 1) / 2] = temp;
                    i = (i - 1) / 2;
                }
            }
        }
    }
    
    result[resIdx] = '\0';
    if (resIdx < len) {
        printf("Reorganised String: \"\" (Impossible with given K)\n");
    } else {
        printf("Reorganised String: %s\n", result);
    }
    
    free(result); free(queue);
}

int main() {
    char str[] = "aabbcc";
    int K = 3;
    rearrangeString(str, K);
    return 0;
}
