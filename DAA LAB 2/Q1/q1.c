#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MAX_N 100

// Define structural growth types: 0 = O(1), 1 = O(log n), 2 = O(n)
typedef enum {
    CONSTANT,
    LOGARITHMIC,
    LINEAR
} GrowthType;

// Structure to define operational profiles for each dictionary
typedef struct {
    const char* name;
    GrowthType search;
    GrowthType insert;
    GrowthType delete_op;
    GrowthType max;
    GrowthType min;
    GrowthType predecessor;
    GrowthType successor;
} DataStructureProfile;

// Global array mapping explicit operational strings for legends
const char* op_names[] = {
    "Search", "Insert", "Delete", "Max", "Min", "Predecessor", "Successor"
};

// Returns the mathematical value based on asymptotic code using switch-case
double get_complexity_val(GrowthType type, int n) {
    switch (type) {
        case CONSTANT:     return 5.0;            // O(1) Constant (scaled for visibility)
        case LOGARITHMIC:   return log2(n) * 10.0; // O(log n) Logarithmic
        case LINEAR:        return (double)n;      // O(n) Linear
        default:            return 0.0;
    }
}

int main() {
    // Clear structure initialization mapping theoretical complexities explicitly
    DataStructureProfile ds_list[6] = {
        {"Unsorted Array",         LINEAR,      CONSTANT,    LINEAR,      LINEAR,      LINEAR,      LINEAR,      LINEAR},
        {"Sorted Array",           LOGARITHMIC, LINEAR,      LINEAR,      CONSTANT,    CONSTANT,    CONSTANT,    CONSTANT},
        {"Singly Unsorted List",   LINEAR,      CONSTANT,    LINEAR,      LINEAR,      LINEAR,      LINEAR,      LINEAR},
        {"Singly Sorted List",     LINEAR,      LINEAR,      LINEAR,      CONSTANT,    CONSTANT,    LINEAR,      CONSTANT},
        {"Doubly Unsorted List",   LINEAR,      CONSTANT,    CONSTANT,    LINEAR,      LINEAR,      LINEAR,      LINEAR},
        {"Doubly Sorted List",     LINEAR,      LINEAR,      CONSTANT,    CONSTANT,    CONSTANT,    CONSTANT,    CONSTANT}
    };

    // Open a persistent pipeline connection to Gnuplot
    FILE *gnuplotPipe = popen("gnuplot -persistent", "w");
    
    if (gnuplotPipe == NULL) {
        printf("Error: Gnuplot not found. Please install it and add it to your PATH.\n");
        return 1;
    }

    printf("Generating separate graphs via struct data matrix parsing...\n");

    // Initialize a 2-row, 3-column interactive layout window canvas
    fprintf(gnuplotPipe, "set multiplot layout 2,3 title 'Dictionary Operations Asymptotic Complexities by Structure' font ',14'\n");
    fprintf(gnuplotPipe, "set xlabel 'Input Size (n)' font ',9'\n");
    fprintf(gnuplotPipe, "set ylabel 'Growth Order' font ',9'\n");
    fprintf(gnuplotPipe, "set grid\n");
    fprintf(gnuplotPipe, "set yrange [0:110]\n"); // Keep scales uniform to easily see curve trajectories
    fprintf(gnuplotPipe, "set key top left font ',8' maxrows 4\n");

    // Main operational structure array processing loop
    for (int ds = 0; ds < 6; ds++) {
        // Access structure variables directly via dot notation
        fprintf(gnuplotPipe, "set title '%s' font ',11'\n", ds_list[ds].name);

        // Command Gnuplot to prepare for 7 inline data-streams sequentially via '-'
        fprintf(gnuplotPipe, "plot ");
        for (int op = 0; op < 7; op++) {
            fprintf(gnuplotPipe, "'-' with lines lw 2 title '%s'%s", 
                    op_names[op], (op == 6) ? "\n" : ", ");
        }

        // Stream coordinate matrices for each of the 7 separate operations
        for (int op = 0; op < 7; op++) {
            // Select the target operation profile from the struct using switch-case logic
            GrowthType target_growth;
            switch (op) {
                case 0: target_growth = ds_list[ds].search; break;
                case 1: target_growth = ds_list[ds].insert; break;
                case 2: target_growth = ds_list[ds].delete_op; break;
                case 3: target_growth = ds_list[ds].max; break;
                case 4: target_growth = ds_list[ds].min; break;
                case 5: target_growth = ds_list[ds].predecessor; break;
                case 6: target_growth = ds_list[ds].successor; break;
            }

            for (int n = 1; n <= MAX_N; n++) {
                double y_val = get_complexity_val(target_growth, n);
                fprintf(gnuplotPipe, "%d %lf\n", n, y_val);
            }
            // Send end-of-stream flag 'e' to seal vector pipeline updates
            fprintf(gnuplotPipe, "e\n");
        }
    }

    // Reset layout modes and close pipe handles safely
    fprintf(gnuplotPipe, "unset multiplot\n");
    pclose(gnuplotPipe);

    printf("Done! Gnuplot window populated successfully using struct models.\n");
    return 0;
}
