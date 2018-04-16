/* file: string_conversion.c						*/
/* author: Dan (email: d.plamadeala@student.rug.nl)	*/
/* date: 2017/10/24 02:44:43						*/
/* version: 1.2										*/
/* Description:	Program that finds the minimal	 	*/
/* amount of operations in order to transform a 	*/
/* string into another.								*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define min(a, b)    (a < b ? a : b)    //min out of two

int min3(int x, int y, int z) {    //function for finding the lowest int out of three ints
    return min(min(x, y), z);
}

int minOperations(char str1[], char str2[], int len1, int len2) {
    int returnValue;
    int **storage = (int **) calloc((len1 + 1) * (len2 + 1), sizeof(int *));
    for (int i = 0; i <= len1; i++) {   //memory allocation
        storage[i] = (int *) calloc((len2 + 1), sizeof(int));
    }
    for (int i = 0; i <= len1; i++) {
        for (int j = 0; j <= len2; j++) {
            if (i == 0) {   //if first string has no char, then we have to insert j chars
                storage[i][j] = j;
            } else if (j == 0) {    //if second string has no char, then we have to remove i chars
                storage[i][j] = i;
            } else if (str1[i - 1] == str2[j - 1]) {//if the last chars are the same, check next by ignoring the last chars
                storage[i][j] = storage[i - 1][j - 1];
            } else {    //if last chars differ, check which operation is lest costly
                storage[i][j] = 1 + min3(storage[i][j - 1], storage[i - 1][j], storage[i - 1][j - 1]);
            }
        }
    }
    returnValue = storage[len1][len2];    //final result
    for (int i = 0; i <= len1; i++) { //avoiding memory leaks
        free(storage[i]);
    }
    free(storage);
    return returnValue;
}

int main(int argc, char *argv[]) {
    char str1[25], str2[25];
    fgets(str1, 25, stdin);    //reading the whole line
    fgets(str2, 25, stdin);
    printf("%d\n", minOperations(str1, str2, strlen(str1), strlen(str2)));
    return (0);
}