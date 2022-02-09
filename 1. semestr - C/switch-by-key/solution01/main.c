#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
//MAYBE REVERSE KEY MAPPING
#define N 11
#define K 4
char src[N];
char dest[N];
int key[K] ={1,0,3,2};
void PopulateSrc(){
    for (int i = 0; i < N; ++i) {
        src[i] = 65+i;
    }
}
bool Contains(int newkey, int i){
    for (int j = 0; j < i; ++j) {
        if(key[j] == newkey)
            return true;
    }
    return false;
}
void CreateKey(){
    srand(time(0));
    for (int i = 0; i < K; ++i) {
        int newKey;
        do{
            newKey = rand()%K;
        } while (Contains(newKey,i));
        key[i]= newKey;
    }
}
void Dictionary(){
    for (int i = 0; i < N; ++i) {
        int a = i/K;
        int b = i%K;
        int shift =key[b]+a*K;
        if(shift < N)
            dest[shift] = src[i];

    }
    for (int i = 0; i < N; ++i) {
        if(dest[i] == 0)
            dest[i] = src[i];
    }
}
void print(){
    printf("puvodni pole => src =  [");
    for (int i = 0; i < N; ++i) {
        printf(" '%c'",src[i]);
    }
    printf("]\n");
    printf("        klic => key =  [");
    for (int i = 0; i < K; ++i) {
        printf(" '%i'",key[i]);
    }
    printf("]\n");
    printf(" cilove pole => dest = [");
    for (int i = 0; i < N; ++i) {
        printf(" '%c'",dest[i]);
    }
    printf("]\n");
}
int main() {
    PopulateSrc();
    CreateKey();
    Dictionary();
    print();
    return 0;
}
