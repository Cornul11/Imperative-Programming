/* file: manhattan.c										*/
/* author: Dan (email: d.plamadeala@student.rug.nl)	*/
/* date: 2017/09/20 14:41:46						*/
/* version: 1.0										*/
/* Description:	*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Coord
{
	int x, y;
} Coord;

int absolute(int x)
{
	return x < 0 ? -x : x;
}

int measureDistance(Coord a, Coord b)
{
	return (absolute(a.x-b.x) + absolute(a.y-b.y));
}

int	main(int argc, char *argv[])
{
	Coord a, b;
	scanf("%d %d %d %d", &a.x, &a.y, &b.x, &b.y);
	printf("%d\n", measureDistance(a, b));
	return (0);
}

