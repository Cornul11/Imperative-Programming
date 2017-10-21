#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int	main(int argc, char *argv[])
{
	int x1, y1, x2, y2, r1, r2;
	printf("Input the coordinates and then the radius of the center of the first circle:\n");
	scanf("%d %d %d", &x1, &y1, &r1);
	printf("Input the coordinates and then the radius of the center of the second circle:\n");
	scanf("%d %d %d", &x2, &y2, &r2);
	int c1 = abs(x2 - x1), c2 = abs(y2 - y1);
	int hypo = (int)sqrt(c1 * c1 + c2 * c2);
	if (hypo > (r1 + r2))
		printf("Circles don't overlap!\n");
	else
		printf("Circles overlap!\n");
	return (0);
}
