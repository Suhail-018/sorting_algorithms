#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
* counting_sort - Sorts an array of integers in ascending order using
*                 the Counting sort algorithm.
* @array: The array to be sorted.
* @size: The size of the array.
*/
void counting_sort(int *array, size_t size)
{
int max;
size_t i;
int *sorted_array;
int *counting_array;
if (array == NULL || size <= 1)
return;
max = array[0];
for (i = 1; i < size; i++)
{
if (array[i] > max)
max = array[i];
}
counting_array = malloc((max + 1) * sizeof(int));
if (counting_array == NULL)
return;
for (i = 0; i <= (size_t)max; i++)
counting_array[i] = 0;
for (i = 0; i < size; i++)
counting_array[array[i]]++;
print_array(counting_array, max + 1);
printf("\n");
sorted_array = malloc(size * sizeof(int));
if (sorted_array == NULL)
{
free(counting_array);
return;
}
for (i = 0; i < size; i++)
{
sorted_array[counting_array[array[i]] - 1] = array[i];
counting_array[array[i]]--;
}
for (i = 0; i < size; i++)
array[i] = sorted_array[i];
free(counting_array);
free(sorted_array);
}
