#include <stdio.h>
#include <stdlib.h>

void swap(int *num1, int *num2)
{
	int temp  = *num2;
	*num2 = *num1;
	*num1 = temp;
}

int	main(int argc, char *argv[])
{
	int A, B, C;
	printf("Type in the lengths of the three sides of the triangle:\n");
	scanf("%d %d %d", &A, &B, &C);
	if (A > B)
		swap(&A, &B);
	if (A > C)
		swap(&B, &C);
	if (A > B)
		swap(&A, &B);
	if (C*C == A*A + B*B)
	{
		printf("Your triangle is a right angled triangle!\n");
	}
	else
	{
		printf("Your triangle is not a right angled triangle!\n");
	}
	return (0);
}
