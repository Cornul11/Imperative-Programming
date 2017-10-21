#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	printf("Type in the length of the side of a cube = ");
	int cubeSideLen = 0;
	scanf("%d", &cubeSideLen);
	printf("The dimensions of the box?\n");
	int boxL, boxl, boxH;
	scanf("%d %d %d", &boxL, &boxl, &boxH);
	int boxVol = boxL * boxl * boxH;
	int cubeVol = cubeSideLen * cubeSideLen * cubeSideLen;
	int amountOfCubes = boxVol / cubeVol;
	printf("%d of cubes can be stacked in the box.\n", amountOfCubes);
	return (0);
}
