/* file: functioneval.c								*/
/* author: Dan (email: d.plamadeala@student.rug.nl)	*/
/* date: 2017/09/20 21:15:55						*/
/* version: 1.1										*/
/* Description:	Evaluates the input, and returns	*/
/* the final value.									*/

#include <stdio.h>
#include <stdlib.h>

int	f(int x)
{
	return (2 * x + 42);
}
int	g(int x)
{
	return (x * x + 2 * x + 1);
}
int	h(int x)
{
	return (x - 1);
}
int	main(int argc, char *argv[])
{
	int input = 0;
	char c = ' ';
	scanf("%d", &input);
	while ((c = getchar()) != '=')	//reading input until...
	{
		if (c == 'f')
			input = f(input);
		else if (c == 'g')				//if g, then x = g(x)
			input = g(input);
		else if (c == 'h')
			input = h(input);
	}
	printf("%d\n", input);			//print the final result
	return (0);
}
