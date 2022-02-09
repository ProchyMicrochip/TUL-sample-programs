#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define BitVal(data,y) ( (data>>y) & 1)
#define SetBit(data,y)    data |= (1 << y)
const int w = 8, h = 4;
int ex, ey, ox, oy;
uint32_t pos = 0;
uint32_t output=0;

int XY(int x, int y){
    return y * w + x;
}

bool occupancy(uint32_t pozice, int x, int y){

    if (BitVal(pozice, XY(x,y)) == 0)
        return false;
    else return true;


}


void rekurze(int x, int y, uint32_t pozice){
    //printf("%i%i ",x,y);
    if(output !=0) return ;
if(ex == x && ey == y){
    //printf("\nVysledek je %i,%i\n",x,y);
    output = pozice;
    return ;
}

    SetBit(pozice,XY(x,y));

if(x<w-1 && occupancy(pozice,x+1,y) == false){
    rekurze(x+1,y,pozice);
    if(output !=0) return ;
}

if(y<h-1 && occupancy(pozice,x,y+1) == false){
    rekurze(x,y+1,pozice);
    if(output !=0) return ;
}
if(x>0 && occupancy(pozice,x-1,y) == false){
    rekurze(x-1,y,pozice);
if(output !=0) return ;
}
if(y>0 && occupancy(pozice,x,y-1) == false){
if(output !=0) return ;
}
}


int main() {
    srand(time(0));
ex = rand()%8;
ox = rand()%8;
ey = rand()%4;
oy = rand()%4;
//ex = 0;
//ey = 0;
//ox = 2;
//oy = 2;
    printf("\nStart 0,0 / Cil %i,%i",ex,ey);
SetBit(pos, XY(ox,oy));
rekurze(0,0,pos);
    printf("\n");
for(int i = 0;i<h;i++){
    for(int j =0;j<w;j++){
        if(j == ex && i == ey)
            printf("0");
        else if(j == ox && i == oy)
            printf("X");
        else if(occupancy(output,j,i) == true)
            printf("+");
        else
            printf(" ");
    }
    printf("\n");
}

    return 0;
}
