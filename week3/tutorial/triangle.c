/* file: triangle.c										*/
/* author: Dan (email: d.plamadeala@student.rug.nl)	*/
/* date: 2017/09/20 14:19:23						*/
/* version: 1.0										*/
/* Description:	*/

#include <stdio.h>
#include <stdlib.h>

void showTriangle(char c, int lines)
{
	for (int i = lines; i > 0; i--)
	{
		for (int j = i; j > 0; j--)
			putchar(c);
		putchar('\n');
	}
}

int	main(int argc, char *argv[])
{
	int lines = 0;
	char c = ' ';
	scanf("%c %d", &c, &lines);
	showTriangle(c, lines);
	return (0);
}

