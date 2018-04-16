/* file: overlap.c									*/
/* author: Dan (email: d.plamadeala@student.rug.nl)	*/
/* date: 2017/09/11 20:40:10						*/
/* version: 1.5										*/
/* Description:	Determines whether two given		*/
/* rectangles overlap at least in one point.		*/

#include <stdio.h>
#include <stdlib.h>

void swap(int *num1, int *num2) {                    //function for swapping two values
    int temp = *num2;
    *num2 = *num1;
    *num1 = temp;
}

int main(int argc, char *argv[]) {
    int x1, x2, y1, y2, a1, a2, b1, b2;
    scanf("%d %d %d %d", &x1, &y1, &a1, &b1);        //reading first rectangle coordinates
    scanf("%d %d %d %d", &x2, &y2, &a2, &b2);        //reading second rectangle coordinates

    if (y1 > b1) {                                //swapping the coordinates relatively...
        swap(&y1, &b1);                                //...to the diagonal
    }
    if (x1 > a1) {
        swap(&x1, &a1);
    }
    if (x2 > a2) {
        swap(&x2, &a2);
    }
    if (y2 > b2) {
        swap(&y2, &b2);
    }

    if (a1 < x2 || a2 < x1 || b1 < y2 || b2 < y1) {    //checking the conditions for overlap
        printf("no overlap\n");
    } else {
        printf("overlap\n");
    }
    return (0);
}

