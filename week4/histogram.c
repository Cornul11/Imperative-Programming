/* file: histogram.c								*/
/* author: Dan (email: d.plamadeala@student.rug.nl)	*/
/* date: 2017/10/03 16:17:26						*/
/* version: 1.6										*/
/* Description:	Prints a histogram of grades that 	*/
/* are inputed from the keyboard.					*/

#include <stdio.h>
#include <stdlib.h>

int *readGrades(int length)	//reads grades into an array
{
	int *grades;
	grades = (int *) malloc (sizeof(int) * length);	//allocate the needed memory
	for (int i = 0; i < length; i++)
		scanf("%d", &grades[i]);
	return (grades);
}
	
void computeFrequencies(int grades[], int freq[10], int length)
{	//computes how often each grade is introduced
	for (int i = 0; i < length; i++)
		freq[grades[i]-1]++;
}

int arrayMax(int length, int arr[])
{	//return the maximum of an array
	int i, max = arr[0];
	for (i = 1; i < length; i++)
		if (arr[i] > max)
			max = arr[i];
  	return (max);
}
	
void printHistogram(int freq[10])
{
	for (int i = arrayMax(10, freq) - 1; i >= 0; i--)
	{	//number of rows = maximal frequency
		for (int j = 0; j < 10; j++)	//number of columns, equal to all possible grades
			if (i < freq[j])
				printf("* ");
			else 
				printf(". ");
		putchar('\n');
	}
	for (int i = 1; i < 11; i++)
		printf("%d ", i);
	putchar('\n');
	/*int i = arrayMax(10, freq) - 1;
	while (i >= 0)
	{
		int j = 0;
		while (j < 10)
		{
			if (i < freq[j])
				printf("* ");
			else
				printf(". ");
			j++;
		}
		putchar('\n');
		i--;
	}
	i = 0;
	while (i++ < 10)
		printf("%d ", i);
	putchar('\n');*/
}

int	main(int argc, char *argv[])
{
	int *grades;
	int frequencies[10] = {0};
	int n;
	scanf("%d", &n);
	grades = readGrades(n);
	computeFrequencies(grades, frequencies, n);
	printHistogram(frequencies);
	return (0);
}
