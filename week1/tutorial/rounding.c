#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	int cents = 0, roundedCents = 0;
	printf("Type in the amount of cents you have to pay = ");
	scanf("%d", &cents);
	if (cents % 5 != 0)
		roundedCents = cents / 5 * 5 + 5;
	else
		roundedCents = cents;
	printf("You have to pay %d cents\n", roundedCents);
	return (0);
}
