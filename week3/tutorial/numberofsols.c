/* file: numberofsols.c										*/
/* author: Dan (email: d.plamadeala@student.rug.nl)	*/
/* date: 2017/09/20 14:34:50						*/
/* version: 1.0										*/
/* Description:	*/

#include <stdio.h>
#include <stdlib.h>

int	numSolutions(int a, int b, int c)
{
	int result = 0;
	int disc = b * b - 4 * a * c;
	if (disc > 0)
		result = 2;
	else if (disc == 0)
		result = 1;
	return (result);
	//return disc < 0 ? 0 : d != 0 + 1;
}

int	main(int argc, char *argv[])
{
	int a = 0, b = 0, c = 0;
	scanf("%d %d %d", &a, &b, &c);
	printf("%d\n", numSolutions(a, b, c));
	return (0);
}

