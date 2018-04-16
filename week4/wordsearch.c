/* file: wordsearch.c										*/
/* author: Dan (email: d.plamadeala@student.rug.nl)	*/
/* date: 2017/10/09 23:48:41						*/
/* version: 1.0										*/
/* Description:	*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int n;
    scanf("%d", &n);
    char ***puzzle = (char ***) calloc(n * n, sizeof(char **));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            puzzle[i] = (char **) calloc(n, sizeof(char **));
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%c", puzzle[i][j]);
        }
    }
    int count = -1;
    char *words[100];
    scanf("%s", words[++count]);
    while (words[count][0] != '.') {
        scanf("%s", words[++count]);
    }
    count -= 1;
    return (0);
}

