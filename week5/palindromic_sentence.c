/* file: palindromic_sentence.c						*/
/* author: Dan (email: d.plamadeala@student.rug.nl)	*/
/* date: 2017/10/15 20:42:58						*/
/* version: 1.1										*/
/* Description:	Checks whether the inputted			*/
/* sentence is a palindrome or not, using recursion.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//fixed memory leak

int isPalindromic(char str[], int start, int end) {                                                //if only one char or none..
    if (start - end == 0 || start - end == 1) {   //..remaining, then palindrome
        return (1);
    }
    if (str[start] == str[end]) {               //check each combination..
        return isPalindromic(str, start + 1, end - 1);
    }
    return (0);                                 //..of first and last char
}

int main(int argc, char *argv[]) {
    char *strOriginal, *strModified;
    int k = 0, len;
    strOriginal = (char *) malloc(64 * sizeof(char)); //alocating memory for enough chars
    scanf("%[^\n]s", strOriginal);
    len = strlen(strOriginal);
    strModified = (char *) malloc(len * sizeof(char));
    for (int i = 0; i < len; i++) {
        if (strOriginal[i] >= 'A' && strOriginal[i] <= 'Z') {
            strModified[k] = strOriginal[i];
        } else if (strOriginal[i] >= 'a' && strOriginal[i] <= 'z') {
            strModified[k] = strOriginal[i] - 32;    //convert all letters..
        } else {                                        //..to upper-case
            continue;                                //get rid of non-letter chars
        }
        k++;
    }
    if (isPalindromic(strModified, 0, k - 1)) {
        printf("The sentence is a palindrome.\n");
    } else {
        printf("The sentence is not a palindrome.\n");
    }
    free(strOriginal);
    free(strModified);
    return (0);
}