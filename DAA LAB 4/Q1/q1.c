#include <stdio.h>
#include <stdlib.h>

// Using integers for colors to make lookups faster (0 = Red, 1 = Blue, 2 = Yellow)
typedef enum { RED = 0, BLUE = 1, YELLOW = 2 } Color;

typedef struct {
    int number;
    Color color;
} Item;

// O(n) Counting Sort Approach
void countingSortByColor(Item arr[], int n) {
    int counts[3] = {0, 0, 0};
    int starting_indices[3] = {0, 0, 0};
    Item* output = (Item*)malloc(n * sizeof(Item));

    // Step 1: Count frequencies of each color
    for (int i = 0; i < n; i++) {
        counts[arr[i].color]++;
    }

    // Step 2: Compute starting positions for each color group
    starting_indices[RED] = 0;
    starting_indices[BLUE] = counts[RED];
    starting_indices[YELLOW] = counts[RED] + counts[BLUE];

    // Step 3: Build the output array stably (Left to Right)
    for (int i = 0; i < n; i++) {
        Color c = arr[i].color;
        int target_pos = starting_indices[c];
        output[target_pos] = arr[i];
        
        starting_indices[c]++; // Move the pointer for the next item of this color
    }

    // Step 4: Copy the sorted elements back to the original array
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }

    free(output);
}

// Helper to convert enum to string for printing
const char* getColorName(Color c) {
    if (c == RED) return "Red";
    if (c == BLUE) return "Blue";
    return "Yellow";
}

void printItems(Item arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("(%d, %s) ", arr[i].number, getColorName(arr[i].color));
    }
    printf("\n");
}

int main() {
    // Input is already sorted by number
    Item arr[] = {
        {10, BLUE},   {15, RED},  {20, YELLOW}, 
        {25, RED},    {30, BLUE}, {35, YELLOW}
    };
    int n = sizeof(arr) / sizeof(arr)[0];

    printf("Original Array:\n");
    printItems(arr, n);

    countingSortByColor(arr, n);

    printf("\nSorted Array (Red -> Blue -> Yellow):\n");
    printItems(arr, n);

    return 0;
}
