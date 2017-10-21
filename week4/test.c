#include <stdio.h>
int squareRoot(int n)
{
	int i = 1, result = 1;
	while (result < n)
	{
		if (result == n)
			return result;
		i++;
		result = i*i;
	}
	return (i);
}


int main()
{
	printf("%d %d %d %d", squareRoot(10), squareRoot(5000), squareRoot(-15), squareRoot(-123));
	return (0);
}