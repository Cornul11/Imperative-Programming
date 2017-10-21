/* file: decompressor.c								*/
/* author: Dan (email: d.plamadeala@student.rug.nl)	*/
/* date: 2017/10/19 00:41:47						*/
/* version: 1.0										*/
/* Description:	*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main(int argc, char *argv[])
{
	int n;
	char *str = (char *) malloc(256 * sizeof(char));
	scanf("%d\n", &n);
	fgets(str, 256, stdin);
	int len = strlen(str) - 1;
	return (0);
}

