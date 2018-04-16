/* file: statistics.c								*/
/* author: Dan (email: d.plamadeala@student.rug.nl)	*/
/* date: 2017/10/22 05:05:25						*/
/* version: 2.1										*/
/* Description:	Computes the mean, the median and 	*/
/* the mean of a series of numbers.					*/

#include <stdio.h>
#include <stdlib.h>

//function for swapping two values in an array
void swapInArr(int n1, int n2, unsigned int *arr) {
    int temp = arr[n1];
    arr[n1] = arr[n2];
    arr[n2] = temp;
}

//a component of the mergeSort algorithm
void merge(int lenA, unsigned int a[], int lenB, unsigned int b[], unsigned int arr[]) {
    int idx, l, r;
    idx = l = r = 0;
    while ((l != lenA) && (r != lenB)) {
        if (a[l] <= b[r]) {
            arr[idx] = a[l];
            l++;
        } else {
            arr[idx] = b[r];
            r++;
        }
        idx++;
    }
    while (l != lenA) {
        arr[idx] = a[l];
        idx++;
        l++;
    }
    while (r != lenB) {
        arr[idx] = b[r];
        idx++;
        r++;
    }
}

//another component of the mergeSort algorithm
unsigned int *copySubArray(int left, int right, unsigned int arr[]) {
    unsigned int i, length, *copy;
    length = right - left;
    copy = calloc(length, sizeof(int));
    for (i = 0; i < length; i++) {
        copy[i] = arr[i + left];
    }
    return (copy);
}

//mergeSort algorithm implementation
void mergeSort(unsigned int length, unsigned int arr[]) {
    unsigned int mid, *left, *right;
    if (length <= 1) {
        return;
    }
    mid = length / 2;
    left = copySubArray(0, mid, arr);
    mergeSort(mid, left);
    right = copySubArray(mid, length, arr);
    mergeSort(length - mid, right);
    merge(mid, left, length - mid, right, arr);
    free(right);
    free(left);
}

int main(int argc, char *argv[]) {
    //unsigned int n, *arr, sum = 0, *modes, count = 1, num = 0, max = 0, mode;
    unsigned int n, *arr, sum = 0, *modes, max, maxValue, lastValue, count, maxCount, k = 0;
    scanf("%u", &n);
    arr = (unsigned int *) calloc(n, sizeof(unsigned int));
    modes = (unsigned int *) calloc(n, sizeof(unsigned int));
    max = arr[0];
    for (unsigned int i = 0; i < n; i++) {
        scanf("%u", &arr[i]);
        sum += arr[i];
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    mergeSort(n, arr);
    printf("mean: %.2f\nmedian: %d\nmode: ", ((double) sum / (double) n), arr[n / 2]);
    maxValue = lastValue = arr[0];
    count = maxCount = 1;
    for (int i = 1; i < n; i++) {
        if (arr[i] == lastValue) {
            count++;
        } else {
            count = 1;
            lastValue = arr[i];
        }
        if (count == maxCount) {    //if more numbers with this frequency then we have no mode
            k = 1;
        }
        if (count > maxCount) {
            k = 0;
            maxCount = count;
            maxValue = lastValue;
        }
    }
    if (k) {
        printf("NONE\n");
    } else {
        printf("%d\n", maxValue);
    }
    free(arr);    //avoiding memory leaks
    free(modes);
    return (0);
}