#include <stdio.h>
#include <stdbool.h>

char vstup[] = "Na strane 123 v 5-tem odstavci najdete 123 oddelenych slov";

int l = sizeof(vstup);

bool Contains(char string[],char substring[] ,int string_lenght, int substring_lenght, int startindex){
    if(string_lenght < startindex+substring_lenght) return false;
    for (int i = 0; i < substring_lenght; ++i) {
        if(string[startindex+i] != substring[i]) return false;
    }
    return true;
}

int main() {
    int counter = 0;
    char fraze[] = "st"; //hledana fraze
    int demanded = 2; //kolikatou frazy hledame
    int sl = sizeof(fraze)-1;

    for (int i = 0; i < l; ++i) {
        if(Contains(vstup,fraze,l,sl,i)) counter++;
        if(demanded == counter){
            printf("%i. vyskyt textu \"%s\" je na indexu %i",demanded,fraze,i);
            return 0;
        }
    }
    printf("%i. vyskyt textu \"%s\" je na indexu %i",demanded,fraze,-1);
    return 0;
}