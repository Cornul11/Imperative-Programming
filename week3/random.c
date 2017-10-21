/* file: random.c									*/
/* author: Dan (email: d.plamadeala@student.rug.nl)	*/
/* date: 2017/09/20 21:07:45						*/
/* version: 1.5										*/
/* Description:	Finds out how many iterations of	*/
/* random number generations until we get to the	*/
/* first number.									*/

#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	int i = 1, x = 0, a = 0, c = 0, m = 0, initialX0 = 0;
	scanf("%d %d %d %d", &x, &a, &c, &m);
	initialX0 = x;
	x = (a * x + c) % m;			//computing first random number
	while (x != initialX0 && i++)	//if the newly generated random..
	{								//..number is equal to the first..
		x = (a * x + c) % m;		//..x, print number of iterations
		if (i > m)					//if iterations > m, the first..
		{							//..random number, is not reachable
			printf("NOT REACHABLE\n");
			return (0);				//exit program
		}
	}
	printf("%d\n", i);
	return (0);
}
