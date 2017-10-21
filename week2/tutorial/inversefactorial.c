/* file: inversefactorial.c										*/
/* author: Dan (email: d.plamadeala@student.rug.nl)	*/
/* date: 2017/09/13 14:38:16						*/
/* version: 1.0										*/
/* Description:	*/

#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char *argv[])
{	
	int n, result = 1;
	scanf("%d", &n);
	int initial = n;
	n = n / result;
	while (n > 1)
	{
		++result;
		n = n / result;
	}
	printf("caf(%d) == %d\n", initial, result);
	return (0);
}

