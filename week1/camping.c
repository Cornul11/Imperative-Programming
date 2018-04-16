/* file: camping.c									*/
/* author: Dan (email: d.plamadeala@student.rug.nl)	*/
/* date: 05.09.2017 23:34							*/
/* version: 1.0										*/
/* Description: This program outputs how often the	*/
/* dad has to walk up and down to fill the bath.	*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]) {
    int input = 0;
    scanf("%d", &input);        //reading the input
    int output = input / 24;    //calculating the amount of walks
    if ((input % 24) != 0) {        //if the amount is not divisible by 24, add 1
        output++;
    }
    printf("%d\n", output);        //printing the output
    return (0);
}
