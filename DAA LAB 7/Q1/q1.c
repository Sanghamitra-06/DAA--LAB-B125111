#include <stdio.h>
#define M 10
void rnd(int g[M][M * 2], int r) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < M * 2; j++) {
            if (g[i][j] == 1) printf("(O) ");
            else printf("    ");
        }
        printf("\n");
    }
}
void xfrm(int n) {
    int m[M][M * 2] = {0};
    int a, b;

    for (a = 0; a < n; a++) {
        int s = n - a - 1;
        for (b = 0; b <= a; b++) {
            m[a][s + (b * 2)] = 1;
        }
    }
    printf("--- SRC ---\n");
    rnd(m, n);
    if (n == 4) {
        printf("\n[MOD]\n");
        m[3][0] = 0; m[1][0] = 1;
        m[3][6] = 0; m[1][6] = 1;
        m[0][3] = 0; m[4][3] = 1;
    } else {
        for (a = 0; a <= n; a++) {
            for (b = 0; b < n * 2; b++) m[a][b] = 0;
        }
        for (a = 0; a < n; a++) {
            int s = a;
            for (b = 0; b < (n - a); b++) {
                m[a + 1][s + (b * 2)] = 1;
            }
        }
    }

    printf("\n--- DST ---\n");
    rnd(m, n + 1);
}
int main() {
    int k = 4;
    int tc = (k * (k + 1)) / 2;
    int mv = tc / 3;
    
    printf("N=%d | C=%d | M=%d\n\n", k, tc, mv);
    xfrm(k);
    return 0;
}
//core logic :3 moves in total although space is taking but moves are min where the corners of the triangle are been taken then it is placed one after one in such a way that it is inverted