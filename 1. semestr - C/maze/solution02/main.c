#include <stdio.h>
#include <stdlib.h>

// ex,ey - cíl
// ox,oy - obstacle
int sx, sy, ex, ey, ox, oy;
int w = 8;
int h = 4;
// State of our array
u_int32_t state = 0;

unsigned int setStateBit(int x, int y, u_int32_t array) {
    int bit = y * w + x;
    return array |= (1 << bit);
}

// 0 == False
int isSetStateBit(int x, int y, u_int32_t array) {
    int bit = y * w + x;
    return (array >> bit) & 1;
}

//int setPathBit(int x, int y) {
//    int bit = y * w + x;
//    int val = 1 << bit;
//    path |= val;
//}

void find_path(int x, int y, u_int32_t array) {
    // Finish reached
    printf("%i%i ",x,y);
    if (x == ex && y == ey) {
        state = array;
        return;
    }

    array = setStateBit(x, y, array);

    if (x + 1 < w && isSetStateBit(x + 1, y, array) == 0) {
        find_path(x + 1, y, array);
        if (state != 0)
            return;
    }

    if (y + 1 < h && isSetStateBit(x, y + 1, array)  == 0) {
        find_path(x, y + 1, array);
        if (state != 0)
            return;
    }

    if (x > 0 && isSetStateBit(x - 1, y, array)  == 0) {
        find_path(x - 1, y, array);
        if (state != 0)
            return;
    }

    if (y > 0 && isSetStateBit(x, y - 1, array)  == 0) {
        find_path(x, y - 1, array);
        if (state != 0)
            return;
    }
}


int main() {
    ox = rand() % w;
    oy = rand() % h;
    ex = rand() % w;
    ey = rand() % h;

    u_int32_t array = 0;

    array = setStateBit(ox, oy, array); // Set obstacle bit

    find_path(0, 0, array);

    printf("Start [%d,%d] \n Cíl [%d, %d]\n", sx, sy, ex, ey);

    for (int y = 0; y < h; ++y) {
        for (int x = 0; x < w; ++x) {
            if (x == ex && y == ey)
                printf("0");
            else if (x == ox && y == oy)
                printf("X");
            else if (isSetStateBit(x, y, state))
                printf("+");
            else
                printf(" ");
        }
        printf("\n");
    }

    return 0;
}
