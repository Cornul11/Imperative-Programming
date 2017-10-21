/* file: divisors.c										*/
/* author: Dan (email: d.plamadeala@student.rug.nl)	*/
/* date: 2017/09/13 14:02:44						*/
/* version: 1.0										*/
/* Description:	*/

#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i * i <= n / 2; i++)
		if (n % i == 0)
			printf("%d %d ", i, n/i);
	printf("\n");
	return (0);
}
