/* file: leapyear.c										*/
/* author: Dan (email: d.plamadeala@student.rug.nl)	*/
/* date: 2017/09/20 14:17:21						*/
/* version: 1.0										*/
/* Description:	*/

#include <stdio.h>
#include <stdlib.h>

int	isLeapYear(int year)
{
	return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

int	main(int argc, char *argv[])
{
	int year = 0;
	scanf("%d", &year);
	printf("%d\n", isLeapYear(year));
	return (0);
}

