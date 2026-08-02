#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
void coin(double probhead,long toss, const char* type){
    long heads=0;
    for(long i=0;i<toss;i++){
        double r=(double)rand()/RAND_MAX;
        if(r<probhead){
            heads++;
        }

    }
    double exp=(double)heads/toss;
    printf("%s Coin:\n", type);
    printf("  Total Tosses: %ld\n", toss);
    printf("  Heads Obtained: %ld\n", heads);
    printf("  Experimental Probability of HEAD: %.4f\n\n", exp);


}
int main(){
    srand(time(NULL));
    long total=100;
    coin(0.5,total,"fair");
    coin(0.7,total,"baised");
    return 0;
}