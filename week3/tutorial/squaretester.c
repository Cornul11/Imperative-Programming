/* file: squaretester.c										*/
/* author: Dan (email: d.plamadeala@student.rug.nl)	*/
/* date: 2017/09/20 14:08:06						*/
/* version: 1.0										*/
/* Description:	*/

#include <stdio.h>
#include <stdlib.h>

int	squareTester(int n)
{
	int i = 1;
	for (i = 0; i * i < n; i++) ;
	return (i * i == n);
}


int	main(int argc, char *argv[])
{
	int integer = 0;
	scanf("%d", &integer);
	printf("%d\n", squareTester(integer));
	return (0);
}

