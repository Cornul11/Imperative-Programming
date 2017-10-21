/* file: integerlog.c										*/
/* author: Dan (email: d.plamadeala@student.rug.nl)	*/
/* date: 2017/09/13 14:31:46						*/
/* version: 1.0										*/
/* Description:	*/

#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	int n = 0, b = 0;
	int k = 0, result = 1;
	scanf("%d %d", &n, &b);
	while (result < n)
	{
		result *= b;
		k++;
	}
	printf("%d\n", k);
	return (0);
}

