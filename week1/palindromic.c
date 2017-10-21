/* file: palindromic.c								*/
/* author: Dan (email: d.plamadeala@student.rug.nl)	*/
/* date: 05.09.2017 23:39							*/
/* version: 1.5										*/
/* Description: Determines whether a number is		*/
/* palindromic or not.								*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int	main(int argc, char *argv[])
{
	int input;
	scanf("%d", &input);
	if (!((input >= 10) && (input < 1000)))					//checking if the input is in range
	{
		printf("Input not in range!\n");
		return (0);
	}
	char strint[4];
	snprintf(strint, 4, "%d", input);						//converting the integer to a string
	int len = strlen(strint);
	if (len == 1)											//verifying all cases of possible combinations
	{
		printf("%d is a palindromic number.\n", input);
		return (0);
	}
	else if (len == 2)
	{
		if (strint[0] == strint[1])
		{
			printf("%d is a palindromic number.\n", input);
			return (0);
		}
	}
	else if (len == 3)
	{
		if (strint[0] == strint[2])
		{
			printf("%d is a palindromic number.\n", input);
			return (0);
		}
	}
	printf("%d is not a palindromic number.\n", input);		//if none of the cases passes the test...
	return(0);												//...then it's not a palindromic number
}
