/* file: exponentiation.c										*/
/* author: Dan (email: d.plamadeala@student.rug.nl)	*/
/* date: 2017/09/13 13:43:58						*/
/* version: 1.0										*/
/* Description:	*/

#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	int b, e, sum = 1;
	scanf("%d %d", &b, &e);
	for (int i = 1; i <= e; i++)
	{
		sum *= b;
	}
	printf("%d\n", sum);
	return (0);
}
