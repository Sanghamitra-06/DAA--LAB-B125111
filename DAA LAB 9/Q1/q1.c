#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int id;
    double v;
    double w;
    double lambda;
    double density;
} Item;
int compareItems(const void *a, const void *b) {
    double d1 = ((Item *)a)->density;
    double d2 = ((Item *)b)->density;
    return (d2 > d1) - (d2 < d1);
}

void fractionalKnapsackDeterioration(Item items[], int n, double W) {
    for (int i = 0; i < n; i++) {
        items[i].density = items[i].v / items[i].w;
    }
    
    qsort(items, n, sizeof(Item), compareItems);
    
    double current_weight = 0.0;
    double total_value = 0.0;
    double t = 0.0;
    
    printf("Optimal Selection Order:\n");
    for (int i = 0; i < n; i++) {
        if (current_weight >= W) break;
        
        double remaining_capacity = W - current_weight;
        double take_w = (items[i].w < remaining_capacity) ? items[i].w : remaining_capacity;
        double fraction = take_w / items[i].w;
        double eff_density = (items[i].v / items[i].w) - (items[i].lambda * t);
        if (eff_density < 0) eff_density = 0;
        double value_gained = take_w * eff_density;
        total_value += value_gained;
        
        printf("Item %d: Fraction = %.2f, Weight Taken = %.2f, Value Contribution = %.2f\n", 
               items[i].id, fraction, take_w, value_gained);
               
        t += take_w; 
        current_weight += take_w;
    }
    printf("Maximum Total Value: %.2f\n\n", total_value);
}
int main() {
    int n = 3;
    double W = 50;
    Item items[] = {
        {1, 60, 10, 0.05},
        {2, 100, 20, 0.02},
        {3, 120, 30, 0.03}
    };
    fractionalKnapsackDeterioration(items, n, W);
    return 0;
}
