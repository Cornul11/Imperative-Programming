/* file: short.c									*/
/* author: Dan (email: d.plamadeala@student.rug.nl)	*/
/* date: 2017/10/24 00:43:48						*/
/* version: 1.3										*/
/* Description:	Program that finds the shortest 	*/
/* circuit length between all of the points of the	*/
/* circuit.											*/

#include <stdio.h>
#include <stdlib.h>

int min;

void swapInt(int *n1, int *n2) { //function for swapping two ints
    int temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

void permuteNums(int *arr[], int addresses[], int start, int end, int length) {
    int sum = 0;
    if (start == end) {
        for (int i = 0; i < length; i++) //calculating the sum of distances
        {
            if (i == length - 1)
                sum = sum + arr[addresses[i]][addresses[0]];
            else
                sum = sum + arr[addresses[i]][addresses[i + 1]];
        }
        if (sum < min)    //storing the minimal distance
            min = sum;
    } else {
        for (int i = start; i <= end; i++) {    //recursive permutation process
            swapInt(&addresses[start], &addresses[i]);
            permuteNums(arr, addresses, start + 1, end, length);
            swapInt(&addresses[start], &addresses[i]);
        }
    }
}

int main(int argc, char *argv[]) {
    int **arr, n, *addresses;
    scanf("%d", &n);
    arr = (int **) calloc(n * n, sizeof(int *)); //memory allocation
    addresses = (int *) calloc(n, sizeof(int));
    for (int i = 0; i < n; i++)
        arr[i] = (int *) calloc(n, sizeof(int));
    for (int i = 0; i < n; i++) //reading half of the array
        for (int j = 0; j <= i; j++) {
            scanf("%d", &arr[i][j]);
            min += arr[i][j];
        }
    for (int i = 0; i < n; i++) //mirroring the array
        for (int j = 0; j < n; j++)
            if (j > i)
                arr[i][j] = arr[j][i];
    for (int i = 0; i < n; i++) //initializing circuits array
        addresses[i] = i;
    permuteNums(arr, addresses, 0, n - 1, n); //making all possible permutations
    printf("%d\n", min);
    for (int i = 0; i < n; i++) //avoiding memory leaks
        free(arr[i]);
    free(arr);
    free(addresses);
    return (0);
}