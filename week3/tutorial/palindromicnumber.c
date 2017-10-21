/* file: palindromicnumber.c										*/
/* author: Dan (email: d.plamadeala@student.rug.nl)	*/
/* date: 2017/09/20 13:44:32						*/
/* version: 1.0										*/
/* Description:	*/

#include <stdio.h>
#include <stdlib.h>

void reverseNumber(int originalNumber, int *reversedNumber)
{
	int remainder = 0;
	while (originalNumber != 0)
	{
		remainder = originalNumber % 10;
		*reversedNumber = *reversedNumber*10 + remainder;
		originalNumber /= 10;
	}
}

int	main(int argc, char *argv[])
{
	int originalNumber = 0, reversedNumber = 0;
	scanf("%d", &originalNumber);
	
	reverseNumber(originalNumber, &reversedNumber);
	if (originalNumber == reversedNumber)
		printf("PALINDROMIC\n");
	else
		printf("NOT PALINDROMIC\n");
	return (0);
}

