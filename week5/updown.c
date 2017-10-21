/* file: updown.c									*/
/* author: Dan (email: d.plamadeala@student.rug.nl)	*/
/* date: 2017/10/17 01:54:46						*/
/* version: 4.3										*/
/* Description:	Programing for determining the		*/
/* amount of updown sequences of n-length.			*/

#include <stdio.h>
#include <stdlib.h>

int countUpDown;

void swapInt(int *n1, int *n2) //function for swapping ints
{
	int temp = *n1;
	*n1 = *n2;
	*n2 = temp;
}

void permuteNums(int arr[], int start, int end, int length) {
	int i, k;			//function for finding all possible permutations using recursion
	if (start == end) {	//and checking whether the actual permutation is valid
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
		}
		if (k == 1)
   			countUpDown++;
	}
   	else {
   	  		for (i = start; i <= end; i++) {	//recursive permutation process
   			swapInt(&arr[start], &arr[i]);

   			permuteNums(arr, start+1, end, length);
   			swapInt(&arr[start], &arr[i]);
   		}
   	}
}

int	main(int argc, char *argv[]) {
	int n, *arr;
	scanf("%d", &n);
	arr = (int *) calloc(n, sizeof(int));
	for (int i = 0; i < n; i++)	{	//filling the array with needed values
		arr[i] = i + 1;
	}
	permuteNums(arr, 0, n-1, n);
	free(arr);
	printf("%d\n", countUpDown);
	return (0);
}