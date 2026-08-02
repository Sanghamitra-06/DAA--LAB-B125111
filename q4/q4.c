#define SDL_MAIN_HANDLED
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <SDL2/SDL.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define MARGIN 80

int main(int argc, char* argv[]) {
    SDL_SetMainReady();
    if (SDL_Init(SDL_INIT_VIDEO) < 0) return 1;

    SDL_Window* window = SDL_CreateWindow("Tower of Hanoi: Exponential Growth O(2^n)", 
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    int max_discs = 25;
    // Theoretical moves at 25 discs = 2^25 - 1 = 33,554,431
    double max_moves = (double)((1LL << max_discs) - 1); 

    int plot_w = WINDOW_WIDTH - (2 * MARGIN);
    int plot_h = WINDOW_HEIGHT - (2 * MARGIN);

    int quit = 0;
    SDL_Event e;

    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) quit = 1;
        }

        // 1. Draw Canvas background (yellow)
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);

        // 2. Draw Graph Grid Borders (Black Axes)
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderDrawLine(renderer, MARGIN, WINDOW_HEIGHT - MARGIN, WINDOW_WIDTH - MARGIN, WINDOW_HEIGHT - MARGIN); // X Axis
        SDL_RenderDrawLine(renderer, MARGIN, MARGIN, MARGIN, WINDOW_HEIGHT - MARGIN); // Y Axis

        // 3. Mathematical Mapping Calculation & Plotting
        int prev_x = -1, prev_y = -1;

        for (int n = 1; n <= max_discs; n++) {
            long long moves = (1LL << n) - 1; // 2^n - 1

            // Scale calculations into pixel space
            int x = MARGIN + (int)(((double)(n - 1) / (max_discs - 1)) * plot_w);
            int y = (WINDOW_HEIGHT - MARGIN) - (int)(((double)moves / max_moves) * plot_h);

            // Draw connecting trendlines (Blue line matching the image)
            if (prev_x != -1) {
                SDL_SetRenderDrawColor(renderer, 0, 102, 204, 255); // Blue
                SDL_RenderDrawLine(renderer, prev_x, prev_y, x, y);
            }

            // Draw Data Markers (Red nodes matching the image)
            SDL_SetRenderDrawColor(renderer, 255, 51, 51, 255); // Red
            SDL_Rect dot = {x - 3, y - 3, 6, 6};
            SDL_RenderFillRect(renderer, &dot);

            prev_x = x;
            prev_y = y;
        }

        SDL_RenderPresent(renderer);
        SDL_Delay(16);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}

// ALGORITHM METHODOLOGY:
//    - Towers of Hanoi: Follows an absolute exponential recurrence relation 
//      T(n) = 2T(n-1) + 1. The total operation load scales as a function of 
//      (2^n - 1). This code implements a 64-bit bitwise shift (`1LL << n`) to 
//      compute the growth trends efficiently without deep recursion depth overhead.
   
//    SDL2 RENDER MECHANISM:
//    1. Loops through disk configurations from 1 to 25 to evaluate the trend.
//    2. Computes the maximum height layout dynamically based on the 25-disk threshold.
//    3. Converts exponential values into flat screen relative float positions.
//    4. Draws continuous blueprint vector paths using `SDL_SetRenderDrawColor` (Blue line).