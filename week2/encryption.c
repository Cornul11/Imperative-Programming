/* file: encryption.c								*/
/* author: Dan (email: d.plamadeala@student.rug.nl)	*/
/* date: 2017/09/11 16:27:49						*/
/* version: 1.0.1									*/
/* Description:	Encrypting a string according to	*/
/* the rules in the .pdf							*/

#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	char c;
										//read until newline char (\n)
	while ((c = getchar()) != '\n')		//process the string per character
	{									//if the char is in between..
		if (c >= 65 && c <= 90)			//..A and Z (upper case)
			c = 90 - (c - 65);			//flip the other way around
		else if (c >= 97 && c <= 122)	//..a and z (lower case)
			c = 122 - (c - 97);			//flip the other way around
		else if (c >= 48 && c <= 57)	//..0 and 9
			c = 57 - (c - 48);			//flip the other way around
		printf("%c", c);				//print the processed char
	}
	printf("\n");						//print the newline (for themis)
	/* A..Z - 65..90
	 * a..z - 97..122
	 * 0..9 - 48..57 */
	return (0);
}

