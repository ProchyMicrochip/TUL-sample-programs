#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
struct Kostka
{
    int a;
    int b;
};

int main() {
    bool flag = false;
    srand(time(0));
    struct Kostka kostky;
    for (int i = 0; i < 3; i++) {
        kostky.a = rand() % 6 + 1;
        kostky.b = rand() % 6 + 1;
        if (kostky.a != kostky.b) {
            printf("Debug: %i, %i\n", kostky.a, kostky.b);
            flag = true;
            break;
        }
    }
    printf("Hodili jste %i", flag? kostky.a+kostky.b : 0);
}