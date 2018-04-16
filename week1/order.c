/* file: order.c									*/
/* author: Dan (email: d.plamadeala@student.rug.nl)	*/
/* date: 05.09.2017 23:55							*/
/* version: 1.0										*/
/* Description: Outputs the four integers in an		*/
/* ascending order.									*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void swap(int *num1, int *num2) {            //function for swapping values of two variables
    int temp = *num2;
    *num2 = *num1;
    *num1 = temp;
}

int main(int argc, char *argv[]) {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);    //reading the input
    if (a > b) {                                //sorting the numbers by comparing
        swap(&a, &b);                        //each one of them, and by exclusion
    }
    if (a > c) {
        swap(&a, &c);
    }
    if (a > d) {
        swap(&a, &d);
    }
    if (b > c) {
        swap(&c, &b);
    }
    if (d < b) {
        swap(&d, &b);
    }
    if (c > d) {
        swap(&c, &d);
    }
    printf("%d %d %d %d\n", a, b, c, d);    //printing the sorted numbers
    return (0);
}

//this version has the comments in it
