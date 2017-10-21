/* file: divisors.c										*/
/* author: Dan (email: d.plamadeala@student.rug.nl)	*/
/* date: 2017/09/13 14:03:29						*/
/* version: 1.0										*/
/* Description:	*/

#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n / 2; i++)
		if (n % i == 0)
			printf("%d ", i);
	printf("%d\n", n);
	return (0);
}
