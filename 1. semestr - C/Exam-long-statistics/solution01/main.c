#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <minmax.h>

#define N 10
int test_pole[] = { 0,1,2,3,15,15,15,7,8,15 };
void findandreplace(int pole[], int value) {
    for (size_t i = 0; i < N; i++)
    {
        if (value == pole[i]) {
            pole[i] = 20;
            return;
        }
    }
}
struct Statistika {
    int min;
    int max;
    int median;
    float prumer;
};
int minimal(int pole[]) {
    int mini = pole[0];
    for (size_t i = 0; i < N; i++) {
        mini = min(pole[i], mini);
    }
    return mini;
}
int maximal(int pole[]) {
    int maxi = pole[0];
    for (size_t i = 0; i < N; i++) {
        maxi = max(pole[i], maxi);
    }
    return maxi;
}
float avg(int pole[]) {
    float sum = 0;
    for (size_t i = 0; i < N; i++)
    {
        sum += pole[i];
    }
    return sum / N;
}
int median(int vstup_pole[]) {
    int pole[N];
    for (size_t i = 0; i < N; i++)
    {
        pole[i] = vstup_pole[i];
    }
    int vystup[N];
    for (size_t i = 0; i < N; i++)
    {
        vystup[i] = minimal(pole);
        findandreplace(pole, minimal(pole));
    }

    return vystup[N / 2];
}



struct Statistika calculate(int pole[]) {
    struct Statistika vystup;
    vystup.min = minimal(pole);
    vystup.max = maximal(pole);
    vystup.prumer = avg(pole);
    vystup.median = median(pole);
    return vystup;
}
void input(int pole[]) {
    for (size_t i = 0; i < N; i++) {
        int hodnota;
        printf("Nactete %i. hodnotu v rozsahu 0-15\n", i+1);
        scanf("\n%i", &hodnota);
        while (hodnota < 0 || hodnota > 15)
        {
            printf("Hodnota musi byt z rozsahu 0-15, vy jste zadali: %i\nZkuste to prosim znovu:\n", hodnota);
            scanf("\n%i", &hodnota);
        }
        pole[i] = hodnota;
    }
}
void vykresli(const int pole[], struct Statistika stats) {

    for (size_t i = 0; i < stats.max; i++)
    {
        printf("%s%lu|",stats.max-i > 9 ? "": " ", stats.max - i);
        for (size_t j = 0; j < 10; j++)
        {
            printf("%s", pole[j] < stats.max - i ? "   " : " X ");
        }

        printf("\n");
    }


}

int main() {
    int vstup[N];
    input(vstup);
    struct Statistika vysledek = calculate(vstup);
    //struct Statistika vysledek = calculate(test_pole);
    vykresli(vstup, vysledek);
    //vykresli(test_pole, vysledek);
    printf("min = %i, max = %i, prumer = %f, median = %i", vysledek.min, vysledek.max, vysledek.prumer, vysledek.median);
}

