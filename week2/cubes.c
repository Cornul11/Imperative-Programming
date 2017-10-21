/* file: cube.c										*/
/* author: Dan (email: d.plamadeala@student.rug.nl)	*/
/* date: 2017/09/13 12:10:09						*/
/* version: 2.1										*/
/* Description:	Outputs whether the introduced		*/
/* number can be expressed as the sum of at least	*/
/* two sum of cubes.								*/

#include <stdio.h>
#include <stdlib.h>
#define CUBE(n) (n*n*n)

int cubeRoot(int n)	//function for determining the...
{					//...aproximate cube root
	for (int i = 1; i <= n/3; i++)
		if ((i*i*i) >= n)
			return (i);
	return (1);
}

int	main(int argc, char *argv[])
{
	int n, s, j = 0;
	scanf("%d", &n);
	int x = 0, y = cubeRoot(n);	//start from both extremes
    while (x <= y)				
	{
        s = CUBE(x) + CUBE(y);	//verify solutions
        if (s < n)				//if the sum of cubes is less...
			x++;				//...than the input, increment
        else if (n < s)			//if the sum of cubes is bigger...
			y--;				//...than the input, decrement
        else					//if the sum is equal to the...
		{						//...input, add a solution and...
			j++;				//continue looking for other
			x++; y--;			//..solutions
		}
	}
	if (j >= 2)					//if we have at least 2 pairs...
		printf("YES\n");		//...of cubes, print yes...
	else
		printf("NO\n");			//...otherwise, print no
	return (0);
}

