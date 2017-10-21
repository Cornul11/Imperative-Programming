/* file: remarkable.c								*/
/* author: Dan (email: d.plamadeala@student.rug.nl)	*/
/* date: 2017/09/12 01:33:40						*/
/* version: 1.8										*/
/* Description:	Shows and counts the number of		*/
/* iterations before getting to 6174.				*/

#include <stdio.h>
#include <stdlib.h>

int n1, n2, n3, n4;

void swap(int *num1, int *num2)	//swaps two values
{
	int temp = *num2;
	*num2 = *num1;
	*num1 = temp;
}

void divideToDigits(int num)	//divides the input into digits
{
	n1 = num % 10;
	num /= 10;
	n2 = num % 10;
	num /= 10;
	n3 = num % 10;
	num /= 10;
	n4 = num % 10;
}

void sortDigitsAscending()		//sort the digits in an ascending order
{								//for future operations
	if (n1 > n2)
		swap(&n1, &n2);
	if (n1 > n3)
		swap(&n1, &n3);
	if (n1 > n4)
		swap(&n1, &n4);
	if (n2 > n3)
		swap(&n2, &n3);
	if (n4 < n2)
		swap(&n4, &n2);
	if (n3 > n4)
		swap(&n3, &n4);
}

void sortDigitsDescending()		//sort the digits in a descending order
{								//in a hardcoded way
	swap(&n1, &n4);
	swap(&n3, &n2);
}

int returnNumber(int n1, int n2, int n3, int n4)
{								//composes a number out of four digits
	int output = 0;
	output = output * 10 + n1;
	output = output * 10 + n2;
	output = output * 10 + n3;
	output = output * 10 + n4;
	return (output);
}

int	main(int argc, char *argv[])
{
	int input = 0;
	int ascending = 0;
	int descending = 0;
	int iters = 0;
	scanf("%d", &input);
	while (input != 6174)		//loop until the needed condition
	{
		divideToDigits(input);
		sortDigitsAscending();
		ascending = returnNumber(n1, n2, n3, n4);	//composing the subtrahend
		sortDigitsDescending();
		descending = returnNumber(n1, n2, n3, n4);	//composing the minuend
		printf("%d-%04d=%04d\n", descending, ascending, (descending - ascending));
		input = descending - ascending;				//main operation
		iters++;									//count the number of iterations
	}
	printf("%d iterations.\n", iters);				//print the number of iterations
	return (0);
}
