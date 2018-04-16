/* file: maze.c										*/
/* author: Dan (email: d.plamadeala@student.rug.nl)	*/
/* date: 2017/10/24 04:49:10						*/
/* version: 1.4										*/
/* Description:	Program that finds the shortest 	*/
/* (only) correct path for going from S to E using 	*/
/* backtracking.									*/

#include <stdio.h>
#include <stdlib.h>

int mazeSolver(int x, int y, int rows, int columns, char *arr[]) {
    if (x < 0 || x + 1 > columns || y < 0 || y + 1 > rows) { //if out of bounds stop executing
        return (0);
    }
    if (arr[y][x] == 'E') {    //if we have found the ending, path has been found
        arr[y][x] = '#'; //mark the ending as the correct path
        return (1);
    }
    if (arr[y][x] != '.' && arr[y][x] != 'S') { //if in the direction that we're searching there's a wall, stop executing
        return (0);
    }
    arr[y][x] = '#'; //if the conditions mentioned earlier pass, then it's a possible path
    //recursive part
    if (mazeSolver(x + 1, y, rows, columns, arr)) {    //look for path to the right
        return (1);
    }
    if (mazeSolver(x, y + 1, rows, columns, arr)) {    //look for path down
        return (1);
    }
    if (mazeSolver(x, y - 1, rows, columns, arr)) {    //look for path up
        return (1);
    }
    if (mazeSolver(x - 1, y, rows, columns, arr)) {    //look for path to the left
        return (1);
    }
    arr[y][x] = '.'; //backtrack
    return (0);
}

int main(int argc, char *argv[]) {
    int m, n;
    char **arr;
    scanf("%d%d", &m, &n);
    arr = (char **) calloc(m, sizeof(char *)); //allocating memory
    for (int i = 0; i < m; i++) {
        arr[i] = (char *) calloc(n, sizeof(char));
        for (int j = 0; j < n; j++) {
            scanf(" %c", &arr[i][j]);
        }
    }
    mazeSolver(0, 1, m, n, arr); //start to search for path from the S char
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%c", arr[i][j]);    //printing the modified maze
        }
        printf("\n");
        free(arr[i]);    //avoiding memory leaks
    }
    free(arr);    //avoiding memory leaks
    return (0);
}