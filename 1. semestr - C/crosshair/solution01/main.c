#include <stdio.h>
#include <math.h>
int a;

char XYchar(double x, double y){
    double o = (double )a;
    if(x == a/2 && y == a/2){
        return '+';
    } else if(x == a/2) {
        return '|';
    }else if(y == a/2){
        return '-';
    }
    else if(pow(x-o/2,2) + pow(y-o/2,2) >=pow(o/4,2)&& pow(x-o/2,2) + pow(y-o/2,2) <=pow(o/2,2)){
        return '*';
    } else return ' ';

}


int main() {
   do {
        printf("zadejte liche cislo (11-41):\n");
        scanf("%i",&a);
    } while ((int)a % 2 == 0 || a<11 || a>41);


    for (int y = 0; y < a; y++) {
        for (int x = 0 ; x < a; x++) {
            char c =XYchar((double)x,(double )y);
            printf("%c",c);


        }

        printf("\n");
    }
    return 0;
}