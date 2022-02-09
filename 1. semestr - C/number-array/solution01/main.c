#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define R 5
#define C 5
#define N 3

int vygenerujnahodnecislo(int min,int max){
    return rand()%(max-min)+min;
}
int* zapisdopole(int pole[R][C], int n){
    int a = vygenerujnahodnecislo(1,100);
    for (int i = 0; i < n; ++i) {
        int x;
        int y;
        do {
            x = vygenerujnahodnecislo(0,R);
            y = vygenerujnahodnecislo(0,C);
        }while(pole[x][y] != 0);
        pole[x][y] = a;
    }

    return pole;
}
int* zobraz(int pole[R][C] ){
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            printf("%i ",pole[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    return pole;
}

int* dodelejpole(int pole[R][C]){
    for (int i = 1; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            if(pole[i][j] == 0)
                pole[i][j] = pole[i-1][j]/2;
        }
    }
    return pole;
}

int main() {
    int pole[R][C] = {};
    srand(time(0));
    zobraz(dodelejpole(zobraz(zapisdopole(pole,N))));
    return 0;
}
