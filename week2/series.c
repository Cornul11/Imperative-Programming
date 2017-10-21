/* file: series.c									*/
/* author: Dan (email: d.plamadeala@student.rug.nl)	*/
/* date: 2017/09/12 18:39:52						*/
/* version: 1.0										*/
/* Description:	Shows the nth element which is		*/
/* divisible by the sum of its digits.				*/

#include <stdio.h>
#include <stdlib.h>

int	sumOfDigits(int num)		//function for calculating the...
{								//...sum of the digits
	int sum = 0, remainder = 0;
	while (num != 0)
	{
		remainder = num % 10;
		sum += remainder;
		num /= 10;
	}
	return (sum);
}

int	main(int argc, char *argv[])
{
	int n = 0, j = 0;
	scanf("%d", &n);
	for (int i = 1; i <= 12150510; i++)	//loop until the 1000000...
	{									//...nth number
		if (!(i % sumOfDigits(i)))		//if divisible by the sum
			j++;						//we've got the j-nth number
		if (j == n)
		{
			printf("%d\n", i);
			break;						//if the number was found
		}								//break the loop
	}
	return (0);
}

