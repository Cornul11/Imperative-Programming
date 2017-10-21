#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int countUpDown;

void swapInt(int *n1, int *n2) //function for swapping ints
{
  int temp = *n1;
  *n1 = *n2;
  *n2 = temp;
}

void permuteNums(int arr[], int size, int length)
{
    int k = 0;          //function for finding all possible permutations using recursion  
    if (size == 1) {    //and checking whether the actual permutation is valid
        for (int i = 0; i < length - 1; i++) { 
            if (i % 2 == 0) {
                if (arr[i] < arr[i+1]) //updown condition
                    k = 1;
                else {
                    k = 0;
                    break;
                }
            }
            else {
                if (arr[i] > arr[i+1]) //updown condition
                    k = 1;
                else {
                    k = 0;
                    break;
                }
            }
            if (k == 1)
                countUpDown++;
        }
    }
    //using heap's algorithm for recursive permutations
    for (int i = 0; i < size; i++) {
        permuteNums(arr, size - 1, length);
        if (size % 2 == 1) //if size is odd, swap first and last element
            swapInt(&arr[0], &arr[size - 1]);
        else //If size is even, swap ith and last element
            swapInt(&arr[i], &arr[size - 1]);
    }
}

int main()
{
    int n, *arr;
    scanf("%d", &n);
    arr = (int *) calloc(n, sizeof(int));
    for (int i = 0; i < n; i++) { //filling the array with needed values
        arr[i] = i + 1;
    }
    permuteNums(arr, n, n);
    free(arr);
    printf("%d\n", countUpDown);
    return (0);
}