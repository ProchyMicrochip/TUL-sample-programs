#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Figure {
    char x;
    char y;
};

void generate_tower_position(char board[8][8], struct Figure towers[2]) {
    struct Figure t1 = {(char) (rand() % 8), (char) (rand() % 8)};
    towers[0] = t1;
    struct Figure t2;
    do {
        t2.x = (char) (rand() % 8);
    } while (t2.x == t1.x);
    do {
        t2.y = (char) (rand() % 8);
    } while (t2.y == t1.y);
    towers[1] = t2;
    board[t1.y][t1.x] = 1;
    board[t2.y][t2.x] = 1;
}

void print_board(char board[8][8]) {
    printf("  ");
    for (int i = 0; i < 8; ++i) {
        printf("%c", 'A' + i);
    }
    printf("\n");
    for (int i = 0; i < 8; ++i) {
        printf("%i ", i + 1);
        for (int j = 0; j < 8; ++j) {
            if (board[i][j] == 0) {
                printf(".");
            } else if (board[i][j] == 1) {
                printf("X");
            } else {
                printf("+");
            }
        }
        printf("\n");
    }
}

void find_covered_fields(char board[8][8], struct Figure towers[2]) {
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (board[j][towers[i].x] == 0) {
                board[j][towers[i].x] = 2;
            }
            if (board[towers[i].y][j] == 0) {
                board[towers[i].y][j] = 2;
            }
        }
    }
}

void validate_input(const char input[3], struct Figure *figure) {
    if ((input[0] >= 'A' && input[0] <= 'H')) {
        figure->x = (char) (input[0] - 'A');
    } else {
        if (input[0] >= 'a' && input[0] <= 'h') {
            figure->x = (char) (input[0] - 'a');
        } else {
            exit(1);
        }
    }

    if (input[1] < '1' || input[1] > '8') {
        exit(1);
    }

    figure->y = (char) (input[1] - '1');
}

void user_input(struct Figure *figure) {
    printf("Zadejte souřadnice pěšce: ");
    char input[3]; // char, number, \n
    scanf("%2s", input);
    validate_input(input, figure);
}

int main() {
    srand(time(0));
    char board[8][8] = {0}; // radky, sloupce
    struct Figure towers[2];
    generate_tower_position(board, towers);
    find_covered_fields(board, towers);
    print_board(board);
    struct Figure figure;
    user_input(&figure);
    printf("x:%i y:%i\n", figure.x, figure.y);
    switch (board[figure.y][figure.x]) {
        case 0:
            printf("Safe");
            break;
        case 1:
        case 2:
            printf("oops");
            break;
        default:
            printf("nekde se stala chyba :(");
    }

    return 0;
}
