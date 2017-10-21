/* file: functioneval.c								*/
/* author: Dan (email: d.plamadeala@student.rug.nl)	*/
/* date: 2017/09/20 21:03:46						*/
/* version: 1.1										*/
/* Description:	Evaluates the input, and returns	*/
/* the final value.									*/

#include <stdio.h>
#include <stdlib.h>

int	f(int x)	//the f(x) function
{
	return (2 * x + 42);
}

int	g(int x)	//the g(x) function
{
	return (x * x + 2 * x + 1);
}

int	h(int x)	//the h(x) function
{
	return (x - 1);
}

int	main(int argc, char *argv[])
{
	int input = 0;
	char c = ' ';
	scanf("%d", &input);
	while ((c = getchar()) != '=')	//reading input until...
	{								//...the equal sign
		switch (c)					//check for each character
		{
			case 'f':				//if f, then x = f(x)
				{
					input = f(input);
					break;			//get out of the switch
				}
			case 'g':				//if g, then x = g(x)
				{
					input = g(input);
					break;			//get out of the switch
				}
			case 'h':				//if h, then x = h(x)
				{
					input = h(input);
					break;			//get out of the switch
				}
		}
	}
	printf("%d\n", input);			//print the final result
	return (0);
}
