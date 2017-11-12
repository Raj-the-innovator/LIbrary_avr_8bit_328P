#include "lib.h"

void insertionSort(unsigned int *arr, int n) // sorting program is used to sorting distance and give least value at first position
{
	cli();
   int i, key, j;
   for (i = 1; i < n; i++)
   {
       key = arr[i];
       j = i-1;
	   
       while (j >= 0 && arr[j] > key)
       {
           arr[j+1] = arr[j];
           j = j-1;
       }
       arr[j+1] = key;
   }
}