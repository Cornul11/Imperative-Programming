/* file: compressor.c								*/
/* author: Dan (email: d.plamadeala@student.rug.nl)	*/
/* date: 2017/10/18 14:42:14						*/
/* version: 2.4										*/
/* Description:	This program compresses a 			*/
/* hypothetical image containing only two kinds of	*/
/* "bits" into a string.							*/

#include <stdio.h>
#include <stdlib.h>

void compressing(char **arr, int startingX, int startingY, int length)
{
	if (length == 1)
		printf("%c", arr[startingY][startingX]);
	else {
		char o = arr[startingY][startingX];
		int k = 0;
		for (int i = startingX; i < length + startingX; i++) {
			if (k == -1)
				break;
			for (int j = startingY; j < length + startingY; j++) {	
				if (arr[j][i] == o)
					k++;	
				else {
					k = -1;
					break; //if at least one character is different, break the loop and divide it by four
				}
			}
		}
		if (k == (length * length))	//check if all the characters are the same
			printf("1%c", o);
		else {
			printf("0");
			int actualLength = length / 2;	//divide the actual grid by 4 and analyze each one of them
			compressing(arr, startingX, startingY, actualLength);
			compressing(arr, startingX + actualLength, startingY, actualLength);			
			compressing(arr, startingX + actualLength, startingY + actualLength, actualLength);
			compressing(arr, startingX, startingY + actualLength, actualLength);
		}
	}
}

int	main(int argc, char *argv[])
{
	int n;
	char **arr;
	scanf("%d", &n);
	arr = (char **) malloc(n * sizeof(char *));	//memory allocation
	for (int j = 0; j < n; j++) {
		arr[j] = (char *) malloc(n * sizeof(char));
		for (int i = 0; i < n; i++)
			scanf(" %c", &arr[j][i]);
	}	
	printf("%d\n", n);
	compressing(arr, 0, 0, n);
	printf("\n");
	for (int i = 0; i < n; i++) {	//avoiding memory leaks
		free(arr[i]);
	}
	free(arr);
	return (0);
}
