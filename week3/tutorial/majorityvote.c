/* file: majorityvote.c										*/
/* author: Dan (email: d.plamadeala@student.rug.nl)	*/
/* date: 2017/09/20 14:12:31						*/
/* version: 1.0										*/
/* Description:	*/

#include <stdio.h>
#include <stdlib.h>

int	majorityVote(int a, int b, int c)
{
	return ((a && b) || (a && c) || (b && c));
	//return !!a + !!b + !!c > 1;
}

int	main(int argc, char *argv[])
{	
	int a = 0, b = 0, c = 0;
	scanf("%d %d %d", &a, &b, &c);
	printf("%d\n", majorityVote(a, b, c));
	return (0);
}

