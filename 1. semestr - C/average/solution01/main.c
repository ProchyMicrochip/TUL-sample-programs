//Wrong peak average
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
bool first = true;
float min,max,avg,now,diff;
int count;
int main() {

    while (true) {
        printf("načtěte hodnotu (0-25):\n");
        do {
            scanf("%f", &now);
        } while (now < 0 || now > 25);
        if(first){
            min = now;
            max = now;
            avg = now;
            count++;
            first = false;
            printf("min: %f    max: %f    avg: %f    diff: %f    pocet: %i\n",min,max,avg,0, count);
        } else {
            min = fmin(min, now);
            max = fmax(max, now);
            diff = now - avg;
            if (fabs(diff) > 25/4){
                printf("hodnota se skokově změnila\n");
                avg = (avg * count + avg+diff*0.75) / ++count;
            } else{
                avg = (avg * count + now) / ++count;
            }
            printf("min: %f    max: %f    avg: %f    diff: %f    pocet: %i\n",min,max,avg,diff, count);
        }




        printf("chcete zadat další hodnotu?\n");
        char k;
        scanf("\n%c", &k);
        if(k != 'a') break;
    }
    return 0;
}