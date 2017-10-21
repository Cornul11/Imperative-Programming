/* file: multiples.c										*/
/* author: Dan (email: d.plamadeala@student.rug.nl)	*/
/* date: 2017/09/20 14:13:20						*/
/* version: 1.0										*/
/* Description:	*/

#include <stdio.h>
#include <stdlib.h>

int	isMultipleOf(int x, int y)
{
	return (x % y == 0 ? 1 : 0);
	//return (x % y == 0);
}

int	main(int argc, char *argv[])
{	
	int x = 0, y = 0;
	scanf("%d %d", &x, &y);
	printf("%d\n", isMultipleOf(x, y));
	return (0);
}

