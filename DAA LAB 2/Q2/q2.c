#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MAX_N 200

// Global tracker to count basic operations (comparisons and data moves)
long long operation_count = 0;

// Structure to capture profiling performance data metrics
typedef struct {
    int n;
    double two_way_ops;
    double three_way_ops;
} ComplexityData;

// --- STANDARD TWO-WAY MERGE SORT ROUTINES ---
void merge_two_way(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++) { L[i] = arr[l + i]; operation_count++; }
    for (int j = 0; j < n2; j++) { R[j] = arr[m + 1 + j]; operation_count++; }

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        operation_count++; // Comparison step
        if (L[i] <= R[j]) { arr[k] = L[i]; i++; } 
        else { arr[k] = R[j]; j++; }
        k++;
    }

    while (i < n1) { arr[k] = L[i]; i++; k++; operation_count++; }
    while (j < n2) { arr[k] = R[j]; j++; k++; operation_count++; }

    free(L);
    free(R);
}

void two_way_merge_sort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        two_way_merge_sort(arr, l, m);
        two_way_merge_sort(arr, m + 1, r);
        merge_two_way(arr, l, m, r);
    }
}

// --- MODIFIED THREE-WAY MERGE SORT ROUTINES ---
void merge_three_way(int arr[], int low, int mid1, int mid2, int high) {
    int n1 = mid1 - low + 1;
    int n2 = mid2 - mid1;
    int n3 = high - mid2;

    int *L = (int *)malloc(n1 * sizeof(int));
    int *M = (int *)malloc(n2 * sizeof(int));
    int *R = (int *)malloc(n3 * sizeof(int));

    for (int i = 0; i < n1; i++) { L[i] = arr[low + i]; operation_count++; }
    for (int i = 0; i < n2; i++) { M[i] = arr[mid1 + 1 + i]; operation_count++; }
    for (int i = 0; i < n3; i++) { R[i] = arr[mid2 + 1 + i]; operation_count++; }

    int i = 0, j = 0, k = 0, l = low;

    while ((i < n1) && (j < n2) && (k < n3)) {
        operation_count += 2; // Two structural comparisons executed
        if (L[i] <= M[j]) {
            if (L[i] <= R[k]) { arr[l++] = L[i++]; } 
            else { arr[l++] = R[k++]; }
        } else {
            if (M[j] <= R[k]) { arr[l++] = M[j++]; } 
            else { arr[l++] = R[k++]; }
        }
    }

    while ((i < n1) && (j < n2)) {
        operation_count++;
        if (L[i] <= M[j]) { arr[l++] = L[i++]; } 
        else { arr[l++] = M[j++]; }
    }

    while ((j < n2) && (k < n3)) {
        operation_count++;
        if (M[j] <= R[k]) { arr[l++] = M[j++]; } 
        else { arr[l++] = R[k++]; }
    }

    while ((i < n1) && (k < n3)) {
        operation_count++;
        if (L[i] <= R[k]) { arr[l++] = L[i++]; } 
        else { arr[l++] = R[k++]; }
    }

    while (i < n1) { arr[l++] = L[i++]; operation_count++; }
    while (j < n2) { arr[l++] = M[j++]; operation_count++; }
    while (k < n3) { arr[l++] = R[k++]; operation_count++; }

    free(L); free(M); free(R);
}

void three_way_merge_sort(int arr[], int low, int high) {
    if (low < high) {
        int dim = (high - low) / 3;
        int mid1 = low + dim;
        int mid2 = low + 2 * dim;

        three_way_merge_sort(arr, low, mid1);
        three_way_merge_sort(arr, mid1 + 1, mid2);
        three_way_merge_sort(arr, mid2 + 1, high);

        merge_three_way(arr, low, mid1, mid2, high);
    }
}

int main() {
    ComplexityData data[MAX_N];

    // Generate empirical operation curve metrics using worst-case inputs (Inverted Arrays)
    for (int n = 1; n <= MAX_N; n++) {
        int *arr1 = (int *)malloc(n * sizeof(int));
        int *arr2 = (int *)malloc(n * sizeof(int));

        data[n - 1].n = n;

        for (int i = 0; i < n; i++) {
            arr1[i] = n - i;
            arr2[i] = n - i;
        }

        operation_count = 0;
        two_way_merge_sort(arr1, 0, n - 1);
        data[n - 1].two_way_ops = (double)operation_count;

        operation_count = 0;
        three_way_merge_sort(arr2, 0, n - 1);
        data[n - 1].three_way_ops = (double)operation_count;

        free(arr1);
        free(arr2);
    }

    // --- INTERACTIVE GNUPLOT PIPELINE STREAM ---
    FILE *gnuplotPipe = popen("gnuplot -persistent", "w");
    if (gnuplotPipe == NULL) {
        printf("Gnuplot setup pipeline failed to initialize.\n");
        return 1;
    }

    fprintf(gnuplotPipe, "set multiplot layout 1,2 title 'Merge Sort vs 3-Way Modified Merge Sort Performance Profile' font ',14'\n");
    
    // Subplot 1: Total Raw Operation Steps
    fprintf(gnuplotPipe, "set title 'Direct Operational Growth Comparison'\n");
    fprintf(gnuplotPipe, "set xlabel 'Array Size (n)'\n");
    fprintf(gnuplotPipe, "set ylabel 'Total Operation Counts'\n");
    fprintf(gnuplotPipe, "set grid\n");
    fprintf(gnuplotPipe, "plot '-' with lines lw 2 title 'Standard 2-Way Merge', \\\n");
    fprintf(gnuplotPipe, "     '-' with lines lw 2 title 'Modified 3-Way Merge'\n");

    for (int i = 0; i < MAX_N; i++) {
        fprintf(gnuplotPipe, "%d %lf\n", data[i].n, data[i].two_way_ops);
    }
    fprintf(gnuplotPipe, "e\n");

    for (int i = 0; i < MAX_N; i++) {
        fprintf(gnuplotPipe, "%d %lf\n", data[i].n, data[i].three_way_ops);
    }
    fprintf(gnuplotPipe, "e\n");

    // Subplot 2: Logarithmic Asymptotic Growth Curves Trend Verification
    fprintf(gnuplotPipe, "set title 'Logarithmic Asymptotic Trend Ratios'\n");
    fprintf(gnuplotPipe, "set ylabel 'Operations / (n * log(n))'\n");
    fprintf(gnuplotPipe, "plot '-' with lines lw 2 title '2-Way Scale Factor', \\\n");
    fprintf(gnuplotPipe, "     '-' with lines lw 2 title '3-Way Scale Factor'\n");

    // Stream 2-Way Metrics
    for (int i = 1; i < MAX_N; i++) {
        double density = data[i].two_way_ops / ((double)data[i].n * log2(data[i].n));
        fprintf(gnuplotPipe, "%d %lf\n", data[i].n, density);
    }
    fprintf(gnuplotPipe, "e\n");

    // Stream 3-Way Metrics using the safe change of base rule
    for (int i = 1; i < MAX_N; i++) {
        double log3_val = log((double)data[i].n) / log(3.0);
        double density = data[i].three_way_ops / ((double)data[i].n * log3_val);
        fprintf(gnuplotPipe, "%d %lf\n", data[i].n, density);
    }
    fprintf(gnuplotPipe, "e\n");

    fprintf(gnuplotPipe, "unset multiplot\n");
    pclose(gnuplotPipe);

    printf("Analysis execution complete. Gnuplot window should now open.\n");
    return 0;
}
