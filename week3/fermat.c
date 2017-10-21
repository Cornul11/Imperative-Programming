/* file: fermat.c									*/
/* author: Dan (email: d.plamadeala@student.rug.nl)	*/
/* date: 2017/09/24 17:11:22						*/
/* version: 1.6										*/
/* Description:	Checks whether a number is a prime	*/
/* number, a Charmichael number, and the first		*/
/* witness.											*/

#include <stdio.h>
#include <stdlib.h>

int modExp(int val, int pow, int mod)
{	//computes the modular exponentiation without overflow using recursion
	if (pow == 0)
		return (1);
	else if (pow % 2 == 0) {
		int res = modExp(val, pow / 2, mod);
		return (res * res) % mod;
	}
	else
		return ((val % mod) * modExp(val, pow - 1, mod)) % mod;
}

int isPrime(int num)
{	//traditional method of checking if a number is prime or not
	if (num <= 1)
		return (0);
	for (int i = 2; i * i <= num; i++)
		if (num % i == 0)
			return (0);
	return (1);
}

int	main(int argc, char *argv[])
{
	int n, k, i = 0, foundWitness = 0, primeBool;
	scanf("%d", &n);
	primeBool = isPrime(n);
	for (i = 2; i < n; i++)
	{
		k = modExp(i, n, n);
		if (k != i)	//if we find a witness
		{
			printf("%d is a witness for %d.\n", i, n);
			foundWitness = 1;
			break;
		}
	}
	if (!primeBool && !foundWitness)	//if no witnesses, but not prime, then carmichael
		printf("%d is a Carmichael number.\n", n);
	else if (primeBool && !foundWitness)	//if not witnesses and prime, then prime
		printf("%d is prime.\n", n);
	return (0);
}
