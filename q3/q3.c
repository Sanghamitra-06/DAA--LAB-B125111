#define SDL_MAIN_HANDLED
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SDL2/SDL.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define MARGIN 60

typedef struct {
    int size;
    long comp_early;
    long comp_full;
} DataPoint;

long bubble_sort_early_stop(int arr[], int n) {
    long comparisons = 0;
    for (int i = 0; i < n - 1; i++) {
        int swapped = 0;
        for (int j = 0; j < n - i - 1; j++) {
            comparisons++;
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        if (!swapped) break;
    }
    return comparisons;
}

long bubble_sort_full(int arr[], int n) {
    long comparisons = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            comparisons++;
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    return comparisons;
}

void generate_random_array(int arr[], int n) {
    for (int i = 0; i < n; i++) arr[i] = rand() % 10000;
}

void copy_array(int source[], int dest[], int n) {
    for (int i = 0; i < n; i++) dest[i] = source[i];
}

int main(int argc, char* argv[]) {
    SDL_SetMainReady();
    srand(time(NULL));

    int sizes[] = {100, 300, 600, 1000, 1500, 2000};
    int num_points = sizeof(sizes) / sizeof(sizes[0]);
    DataPoint* data = malloc(num_points * sizeof(DataPoint));

    printf("Running Benchmarks...\n");
    for (int i = 0; i < num_points; i++) {
        int n = sizes[i];
        int *arr1 = malloc(n * sizeof(int));
        int *arr2 = malloc(n * sizeof(int));

        generate_random_array(arr1, n);
        copy_array(arr1, arr2, n);

        data[i].size = n;
        data[i].comp_early = bubble_sort_early_stop(arr1, n);
        data[i].comp_full = bubble_sort_full(arr2, n);

        printf("Size: %-5d | Early: %-8ld | Full: %-8ld\n", n, data[i].comp_early, data[i].comp_full);

        free(arr1);
        free(arr2);
    }

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow("Bubble Sort Performance Curve", 
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    double max_x = sizes[num_points - 1];
    double max_y = data[num_points - 1].comp_full;

    int plot_w = WINDOW_WIDTH - (2 * MARGIN);
    int plot_h = WINDOW_HEIGHT - (2 * MARGIN);

    int quit = 0;
    SDL_Event e;

    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) quit = 1;
        }

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderDrawLine(renderer, MARGIN, WINDOW_HEIGHT - MARGIN, WINDOW_WIDTH - MARGIN, WINDOW_HEIGHT - MARGIN);
        SDL_RenderDrawLine(renderer, MARGIN, MARGIN, MARGIN, WINDOW_HEIGHT - MARGIN);

        for (int i = 0; i < num_points - 1; i++) {
            int x1 = MARGIN + (int)((data[i].size / max_x) * plot_w);
            int x2 = MARGIN + (int)((data[i + 1].size / max_x) * plot_w);

            int y1_full = (WINDOW_HEIGHT - MARGIN) - (int)((data[i].comp_full / max_y) * plot_h);
            int y2_full = (WINDOW_HEIGHT - MARGIN) - (int)((data[i + 1].comp_full / max_y) * plot_h);

            int y1_early = (WINDOW_HEIGHT - MARGIN) - (int)((data[i].comp_early / max_y) * plot_h);
            int y2_early = (WINDOW_HEIGHT - MARGIN) - (int)((data[i + 1].comp_early / max_y) * plot_h);

            SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
            SDL_RenderDrawLine(renderer, x1, y1_full, x2, y2_full);

            SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
            SDL_RenderDrawLine(renderer, x1, y1_early, x2, y2_early);
        }

        SDL_RenderPresent(renderer);
        SDL_Delay(16);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    free(data);

    return 0;
}

 // ALGORITHM METHODOLOGY:
//    - Standard Bubble Sort: Employs nested loops to repeatedly step through 
//      the array, comparing adjacent elements and swapping them if they are in 
//      the wrong order. It performs exactly [n * (n - 1)] / 2 comparisons, 
//      resulting in a rigid quadratic O(n^2) complexity curve.
//    - Early-Stop Bubble Sort: Introduces a boolean flag (swapped) initialized 
//      to 0 on each outer pass. If a full pass completes without changing any 
//      positions, `swapped` remains 0, indicating the array is sorted. The loop 
//      terminates early.
   
//    SDL2 RENDER MECHANISM:
//    1. Collects benchmarks across expanding array sizes (n = 100 to 2000).
//    2. Finds the maximum data bounds (`max_x` and `max_y`) to establish a scaling multiplier.
//    3. Normalizes mathematical data coordinates to fit inside the safe window width/height.
//    4. Inverts the Y-axis calculation because screen pixels count down from top-left (0,0).
//    5. Uses `SDL_RenderDrawLine` to draw consecutive coordinate segments.