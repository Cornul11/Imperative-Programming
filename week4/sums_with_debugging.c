/* file: sums.c										*/
/* author: Dan (email: d.plamadeala@student.rug.nl)	*/
/* date: 2017/10/04 00:10:34						*/
/* version: 1.0										*/
/* Description:	*/

#include <stdio.h>
#include <stdlib.h>

int **readArray(int length)
{
	int **array = (int **) calloc(length, sizeof(int *));

	for (int i = 0; i < length; i++)
	{
		array[i] = (int *) calloc(length, sizeof(int));
		for (int j = 0; j < length; j++)
			scanf("%d", &array[i][j]);
	}
	return (array);
}

int	checkSums(int **array, int n, int m)
{
	int sum = 0, k = 0;
	int iter = 0;
	int **diagarr = (int **) calloc(m * 6, sizeof(int *));
	for (int i = 0; i < m * 2 - 1; i++)	//diagonals slash
	{
		diagarr[iter] = (int *) calloc(m, sizeof(int));
		for (int j = 0; j <= i; j++)
		{
			int l = i - j;
			if (l < m && j < m)
				diagarr[iter][j] = array[l][j];
		}
		iter++;
	}
	diagarr[iter] = (int *) calloc(m, sizeof(int));
	for (int i = m - 1; i > 0; i--) //backslash lower half
	{
		diagarr[iter] = (int *) calloc(m, sizeof(int));
		for (int j = 0, x = i; x <= m - 1; j++, x++)
			diagarr[iter][j] = array[x][j];
		iter++;
	}
	for (int i = 0; i <= m - 1; i++) //backslash upper half
	{
		diagarr[iter] = (int *) calloc(m, sizeof(int));
		for (int j = 0, y = i; y <= m - 1; j++, y++)
			diagarr[iter][j] = array[j][y];
		iter++;
	}
	for (int i = 0; i < m; i++) //rows
	{
		diagarr[iter] = (int *) calloc(m, sizeof(int));
		for (int j = 0; j < m; j++)
			diagarr[iter][j] = array[i][j];
		iter++;
	}
	for (int i = 0; i < m; i++) //columns
	{
		diagarr[iter] = (int *) calloc(m, sizeof(int));
		for (int j = 0; j < m; j++)
			diagarr[iter][j] = array[j][i];
		iter++;
	}
	for (int i = 0; i < iter; i++)
	{
		printf("%d =\t", i);
		for (int j = 0; j < m; j++)
		{
			printf("%d ", diagarr[i][j]);
		}
		printf("\n");
	}
/*	for (int i = 0; i < iter; i++)
	{
		sum = 0;
		for (int j = 0; j < m; j++)
		{
			for (int op = j; op < m; op++)
			{
				sum += diagarr[i][op];
				//printf("%d ", diagarr[i][op]);
				if (sum == n)
				{
					sum = 0;
					k++;
					break;
				}
				if (sum > n)
					sum = 0;
					
			}
			//printf("\n");
		}
	}*/
	int *sumFound = (int *) calloc(iter, sizeof(int));
	int temp;
	for (int i = 0; i < iter; i++)
	{
		sum = temp = 0;
		for (int j = 0; j < m; j++)
		{
			sum = temp = 0;
			for (int op = j; op < m; op++)
			{
				if (diagarr[i][op] == 42)
					continue;
				sum += diagarr[i][op];
				printf("sum = %d\n", sum);
				temp++;
				if (sum == n && temp > 1)
				{
					printf("FOUND AT iter = %d\n", i);
					sumFound[i] = 1;
					sum = temp = 0;
					break;
				}
			}
		}
	}
	printf("iters = %d\n", iter);
	for (int i = 0; i < iter; i++)
		if (sumFound[i] == 1)
			k++;

	free(sumFound);
	for (int i = 0; i < iter; i++)
		free(diagarr[i]);
	free(diagarr);
	return (k);
}

int	main(int argc, char *argv[])
{
	int m, n;
	int **array;
	scanf("%d %d", &n, &m);
	array = readArray(m);
	printf("%d\n", checkSums(array, n, m));
	for (int i = 0; i < m; i++)
		free(array[i]);
	free(array);
	return (0);
}