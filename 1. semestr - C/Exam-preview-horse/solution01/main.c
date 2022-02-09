#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

struct Figure {
    int x;
    int y;
};
struct Figure gen_figure(int y, int x){
    struct Figure t;
    t.x = x;
    t.y = y;
    return t;
}
void print_board(char board[8][8]) {

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (board[i][j] == 0) {
                printf(" \u25A1 ");
            } else if (board[i][j] == 1) {
                printf(" \u26DB ");
            }else{
                printf(" \u25A0 ");
            }
        }
        printf("\n");
    }
}

void generate_horse_position(char board[8][8], struct Figure horse[1]) {
    struct Figure t1 = {(rand() % 8), (rand() % 8)};
    horse[0] = t1;
    board[t1.y][t1.x] = 1;
}

bool check_on_board(struct  Figure pos){

    if(pos.x > 7)
        return false;
    if(pos.x < 0)
        return false;
    if(pos.y > 7)
        return false;
    if(pos.y < 0)
        return false;
    return true;

}

bool check_occupancy(int board[8][8], struct  Figure pos){
    if(board[pos.y][pos.x] == 0)
        return true;
    return false;

}

void find_covered_fields(char board[8][8], struct Figure horse1[]) {
    struct Figure horse = horse1[0];
    struct Figure available_pos[8];
    available_pos[0] = gen_figure(horse.y+2,horse.x+1);
    available_pos[1] = gen_figure(horse.y+2,horse.x-1);
    available_pos[2] = gen_figure(horse.y-2,horse.x+1);
    available_pos[3] = gen_figure(horse.y-2,horse.x-1);
    available_pos[4] = gen_figure(horse.y+1,horse.x+2);
    available_pos[5] = gen_figure(horse.y+1,horse.x-2);
    available_pos[6] = gen_figure(horse.y-1,horse.x+2);
    available_pos[7] = gen_figure(horse.y-1,horse.x-2);
    for (int i = 0; i < 8; ++i) {
        if(check_on_board(available_pos[i]) && check_occupancy(board,available_pos[i]))
            board[available_pos[i].y][available_pos[i].x] = 2;
    }

}

int main() {
    srand(time(0));
    int board[8][8] = {0};
    struct Figure horse[1];
    generate_horse_position(board, horse);
    find_covered_fields(board, horse);
    print_board(board);
    return 0;
}
