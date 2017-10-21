/* file: firstidigt.c										*/
/* author: Dan (email: d.plamadeala@student.rug.nl)	*/
/* date: 2017/09/20 14:18:19						*/
/* version: 1.0										*/
/* Description:	*/

#include <stdio.h>
#include <stdlib.h>

char firstDigit(int number)
{
	char strInt[10];
	snprintf(strInt, 10, "%d", number);
	return (strInt[0]);
}
/*	int firstDigit(int n)
 *	{
 * 		while (n > 9)
 * 			n /= 10;
 * 		return (n);
 *	}

int	main(int argc, char *argv[])
{
	int number = 0;
	scanf("%d", &number);
	printf("%c\n", firstDigit(number));
	return (0);
}

