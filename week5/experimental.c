#include <stdio.h>


long factorialu(int n)
{
  int c;
  long result = 1;
 
  for (c = 1; c <= n; c++)
    result = result * c;
 
  return result;
}

int combinari(int n, int k)
{
	return (factorialu(n)/(factorialu(k)*(factorialu(n-k))));
}

int e(int i, int n)
{
	if (n == 0)
		return (0);
	else
		return (combinari(n, i)*e(n, i)*e(n, n-i));
}

int main(int argc, char *argv[])
{
	int n, sum = 0;
	scanf("%d",&n);
	for (int i = 0; i < n; i++)
	{
		sum = sum + combinations(n, i)*e(n, i)*e(n, n-i);
	}
	return (0);
}