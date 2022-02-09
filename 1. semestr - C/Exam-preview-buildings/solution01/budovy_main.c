#include <stdio.h>
#include <stdbool.h>

#define N 10

int data[N] = {5,4,6,8,15,12,6,8,17,5};


void input(int pole[]){
    for (int i = 0; i < N; ++i) {
        printf("Zadejte vysku %i. budovy\n",i+1);
        scanf("\n %i", &pole[i]);
        while (pole[i] <1 || pole[i] >20){
            printf("Zadali jste vysku %i, vyska musi byt v rozsahu 1-20\nZkuste to znovu \n",pole[i]);
            printf("Zadejte vysku %i. budovy\n",i+1);
            scanf("\n %i", &pole[i]);
        }
        printf("Budova cislo %i ma vysku %i\n",i+1,pole[i] );
    }
}
int max(const int pole[]){
    int max = pole[0];
    for (int i = 1; i < N; ++i) {
        max = max < pole[i] ? pole[i] : max;
    }
    return max;
}
void printit(int pole[]){
    int maxim = max(pole);
    for (int i = 0; i < maxim; ++i) {
        bool flag = false;
        for (int j = 0; j < N+4; ++j) {
            if(j<4) printf("-");
            else printf(pole[j-4] > maxim-i-1 ? "  X  " : flag ? "     " : "-----");
            if(pole[j-4] > maxim-i-1) flag=true;
        }
        printf("\n");


    }

}
int calculate(int pole[])
{
    int i = 0;
    int pocet =0;
    int last_height = 0;
    while (true){
        if(max(pole) == pole[i]) return pocet+1;
        pocet += last_height >= pole[i] ? 0 : 1;
        last_height = last_height >= pole[i] ? last_height : pole[i];
        i++;
    }
}

void printout(int pInt[]) {
    int a =calculate(pInt);
    if(a == 1) printf("pozorovatel uvidi %i budovu\n",a);
    else if(a < 5) printf("pozorovatel uvidi %i budovy\n",a);
    else if(a > 5) printf("pozorovatel uvidi %i budov\n",a);
}

int main() {
    //input(data);
    printit(data);
    printout(data);
    return 0;
}


