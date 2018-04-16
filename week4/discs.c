/* file: discs.c									*/
/* author: Dan (email: d.plamadeala@student.rug.nl)	*/
/* date: 2017/10/07 18:49:16						*/
/* version: 4.5										*/
/* Description:	Prints the number of non-overlapping*/
/* discs.											*/

#include <stdio.h>
#include <stdlib.h>

int **readDiscs(int n)    //reading the discs data into array
{
    int **discs = (int **) calloc(n, sizeof(int *));
    for (int i = 0; i < n; i++) {
        discs[i] = (int *) calloc(3, sizeof(int));
        for (int j = 0; j < 3; j++) {
            scanf("%d", &discs[i][j]);
        }
    }
    return (discs);
}

int power2(int n) { //avoiding using the math library
    return (n * n);
}

int checkOverlap(int **discs, int length) {
    int *overlaps = (int *) calloc(length, sizeof(int));
    int k = 0, R1, R2, X1, X2, Y1, Y2;
    for (int i = 0; i < length; i++) {
        for (int j = i + 1; j < length; j++) {
            R1 = discs[i][2];
            R2 = discs[j][2];
            X1 = discs[i][0];    //if the distance between discs..
            X2 = discs[j][0];    //..centres is less or equal than..
            Y1 = discs[i][1];    //..the sum of their radii then..
            Y2 = discs[j][1];    //..they overlap or touch
            if (power2(X2 - X1) + power2(Y2 - Y1) <= power2(R1 + R2))
                overlaps[i] = overlaps[j] = 1;
        }
    }
    for (int f = 0; f < length; f++) {
        if (overlaps[f] == 0) {
            k++;
        }
    }
    free(overlaps);    //avoiding memory leak
    return (k);
}

int main(int argc, char *argv[]) {
    int **discs;
    int n;
    scanf("%d", &n);
    discs = readDiscs(n);
    printf("%d\n", checkOverlap(discs, n));
    for (int i = 0; i < n; i++) {    //avoiding memory leaks
        free(discs[i]);
    }
    free(discs);
    return (0);
}
