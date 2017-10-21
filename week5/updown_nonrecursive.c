
#include <stdio.h>


int globalN, countUpDown;

void QuickPerm(int *arr, int size)
{
   int k = 0;
   int i, j, tmp; // Upper Index i; Lower Index j
   p = (int *) calloc((size + 1), sizeof(int));
   for(i = 0; i < size; i++)   // initialize arrays; a[N] can be any type
   {
      p[i] = i;
      //printf("%d\n", a[i]);
   }
   p[size] = size; // p[N] > 0 controls iteration and the index boundary for i
   //display(a, 0, 0);   // remove comment to display array a[]
   i = 1;   // setup first swap points to be 1 and 0 respectively (i & j)
   while(i < size)
   {
      p[i]--;             // decrease index "weight" for i by one
      j = i % 2 * p[i];   // IF i is odd then j = p[i] otherwise j = 0
      tmp = arr[j];         // swap(a[j], a[i])
      arr[j] = arr[i];
      arr[i] = tmp;
      if (size % 2 == 0) {
         for (int l = 0; l < size - 1; l++) {
            if (l % 2 == 0) {
               if (arr[l] < arr[l+1]) 
                  k = 1;
               else {
                  k = 0;
                  break;
               }
            }
            else {
               if (arr[l] > arr[l+1])
                  k = 1;
               else {
                  k = 0;
                  break;
               }
            }
         }
      }
         else {
            for (int l = 0; l < globalN - 1; l++) {
            if (l % 2 == 0)   {
               if (arr[l] < arr[l+1])
                  k = 1;
               else {
                  k = 0;
                  break;
               }
            }
            else {
               if (arr[l] > arr[l+1])
                  k = 1;
               else {
                  k = 0;
                  break;
               }
            }
            }
         }
         if (k == 1)
            countUpDown++;
      i = 1;              // reset index i to 1 (assumed)
      while (!p[i])       // while (p[i] == 0)
      {
         p[i] = i;        // reset p[i] zero value
         i++;             // set new index value for i (increase by one)
      }
   }
}

int main(void)
{
   int *arr;
   scanf("%d", &globalN);
   arr = (int *) calloc(globalN, sizeof(int));
   QuickPerm();

   printf("%d\n", countUpDown);
   return (0);
}