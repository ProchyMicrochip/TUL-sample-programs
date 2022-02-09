#include <stdio.h>
#include <math.h>
#include <stdbool.h>

float m, n, r;
float positive;
float negative;

float diskriminant(float a, float b, float c) {
    return pow(b, 2) - 4 * a * c;
}

bool computePos(float a, float b, float c) {
    float d = diskriminant(a, b, c);
    if (d < 0)
        return false;
    positive = (-b + sqrt(d)) / (2 * a);
    return true;
}

bool computeNeg(float a, float b, float c) {
    float d = diskriminant(a, b, c);
    if (d < 0)
        return false;
    negative = (-b - sqrt(d)) / (2 * a);
    return true;
}


int main() {
    printf("Zadejte m:\n");
    scanf("%f", &m);
    printf("Zadejte n:\n");
    scanf("%f", &n);
    printf("Zadejte r:\n");
    scanf("%f", &r);


    float a = 1.25;
    float b = (-2 * m) - n;
    float c = pow(m, 2) + pow(n, 2) - pow(r, 2);
    //printf("%f;%f;%f\n",a,b,c);
    bool pos = computePos(a, b, c);
    bool neg = computeNeg(a, b, c);
    if (positive == negative)
        neg = false;
    if (pos && neg)
        printf("[%f;%f],[%f;%f]", positive, positive * 0.5, negative, negative * 0.5);
    else if (pos)
        printf("[%f;%f]", positive, positive * 0.5);
    else if (neg)
        printf("[%f;%f]", negative, negative * 0.5);
    else
        printf("Přímka a kružnice se neprotínají.");
    return 0;
}


