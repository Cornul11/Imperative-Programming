/* file: cubes.c									*/
/* author: Dan (email: d.plamadeala@student.rug.nl)	*/
/* date: 2017/09/13 11:50:54						*/
/* version: 1.10									*/
/* Description:	Outputs whether the introduced		*/
/* number can be expressed as the sum of at least	*/
/* two sum of cubes.								*/

#include <stdio.h>
#include <stdlib.h>
#define CUBE(n) 	(n*n*n)

int	main(int argc, char *argv[])
{
	int input = 0;
	scanf("%d", &input);
	
	//bruteforce until we find the possible combination
	int k = 1;
	do
	{
		int k3 = CUBE(k);
		if (k3 > input)	//if the cube is bigger than n, the solution is not good
			break;
		int l = k;			//avoid checking already verified solutions for speed
		do
		{
			int l3 = CUBE(l);
			if (k3 + l3 > input)			//check solution for valability
				break;
			int m = k + 1;	//avoid checking already verified solutions for speed
			do
			{
				int m3 = CUBE(m);
				if (m3 > k3 + l3)			//check solution for valability
					break;
				int n = m;	//avoid checking already verified solutions for speed
				do
				{
					int n3 = CUBE(n);
					if (m3 + n3 > k3 + l3)	//check solution for valability
						break;
					if ((m3 + n3 == k3 + l3) && ((k3 + l3) == input))	//if the main condition is...
					{												//...positive, print yes
						printf("YES\n");
						return (0);
					}
					n++;
				} while (n <= input);
				m++;
			} while (m <= input);
			l++;
		} while (l <= input);
		k++;
	} while (k <= input);
	printf("NO\n");
	return (0);
}
