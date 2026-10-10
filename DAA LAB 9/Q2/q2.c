#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char ch;
    int freq;
    struct Node *left, *right;
} Node;

typedef struct {
    char ch;
    int length;
    char code[50];
} CanonicalCode;

Node* createNode(char ch, int freq) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->ch = ch; n->freq = freq;
    n->left = n->right = NULL;
    return n;
}

int compareNodes(const void* a, const void* b) {
    return (*(Node**)a)->freq - (*(Node**)b)->freq;
}

int compareCanonical(const void* a, const void* b) {
    CanonicalCode* c1 = (CanonicalCode*)a;
    CanonicalCode* c2 = (CanonicalCode*)b;
    if (c1->length != c2->length) return c1->length - c2->length;
    return c1->ch - c2->ch;
}

void getLengths(Node* root, int depth, int lengths[]) {
    if (!root) return;
    if (!root->left && !root->right) {
        lengths[(unsigned char)root->ch] = depth;
        return;
    }
    getLengths(root->left, depth + 1, lengths);
    getLengths(root->right, depth + 1, lengths);
}

void generateCanonicalHuffman(char chars[], int freq[], int size) {
    Node** heap = (Node**)malloc(size * sizeof(Node*));
    for (int i = 0; i < size; i++) heap[i] = createNode(chars[i], freq[i]);
    
    int heap_size = size;
    while (heap_size > 1) {
        qsort(heap, heap_size, sizeof(Node*), compareNodes);
        Node* left = heap[0];
        Node* right = heap[1];
        Node* parent = createNode('$', left->freq + right->freq);
        parent->left = left; parent->right = right;
        heap[0] = parent;
        for (int i = 1; i < heap_size - 1; i++) heap[i] = heap[i + 1];
        heap_size--;
    }
    
    int lengths[256] = {0};
    getLengths(heap[0], 0, lengths);
    
    CanonicalCode* cc = (CanonicalCode*)malloc(size * sizeof(CanonicalCode));
    for (int i = 0; i < size; i++) {
        cc[i].ch = chars[i];
        cc[i].length = lengths[(unsigned char)chars[i]];
    }
    
    qsort(cc, size, sizeof(CanonicalCode), compareCanonical);
    
    int code = 0;
    int current_len = cc[0].length;
    for (int i = 0; i < size; i++) {
        while (current_len < cc[i].length) {
            code <<= 1;
            current_len++;
        }
        for (int j = current_len - 1; j >= 0; j--) {
            cc[i].code[j] = (code & (1 << (current_len - 1 - j))) ? '1' : '0';
        }
        cc[i].code[current_len] = '\0';
        code++;
    }
    
    printf("Canonical Huffman Codebook:\n");
    for (int i = 0; i < size; i++) {
        printf("Symbol: %c, Length: %d, Code: %s\n", cc[i].ch, cc[i].length, cc[i].code);
    }
    printf("\n");
}

int main() {
    char chars[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    generateCanonicalHuffman(chars, freq, 6);
    return 0;
}
