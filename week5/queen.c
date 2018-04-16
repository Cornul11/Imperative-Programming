#include <stdio.h>
#include <stdlib.h>

#define ABS(a) ((a)<0 ? (-(a)) : (a))

void printPosition(int pos[8]) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (pos[i] == j) {
                printf("*");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
    printf("\n\n");
}

void placeQueen(int row, int pos[8]) {
    if (row == 8) {
        printPosition(pos);
    } else {
        int column;
        for (column = 0; column < 8; column++) {
            int r;
            for (r = 0; r < row; r++) {
                if ((pos[r] == column) || (ABS(pos[r] - column) == row - r)) {
                    break;
                }
            }
            if (r == row) {
                pos[row] = column;
                placeQueen(row + 1, pos);
            }
        }
    }
}

int main(int argc, char *argv[]) {
    int pos[8];
    placeQueen(0, pos);
    return (0);
}