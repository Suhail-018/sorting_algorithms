#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
* getMax - Get the maximum value in an array
* @array: The array of integers
* @size: The size of the array
* Return: The maximum value in the array
*/
int getMax(int *array, size_t size)
{
int max = array[0];
size_t i;
for (i = 1; i < size; i++)
{
if (array[i] > max)
max = array[i];
}
return (max);
}

/**
* countSort - Perform counting sort based on the significant place
* @array: The array of integers
* @size: The size of the array
* @exp: The current exponent (significant place)
*/
void countSort(int *array, size_t size, int exp)
{
int *output = malloc(size * sizeof(int));
int count[10] = {0};
size_t i;
if (!output)
exit(1);
for (i = 0; i < size; i++)
count[(array[i] / exp) % 10]++;
for (i = 1; i < 10; i++)
count[i] += count[i - 1];
for (i = size - 1; i != (size_t)-1; i--)
{
output[count[(array[i] / exp) % 10] - 1] = array[i];
count[(array[i] / exp) % 10]--;
}
for (i = 0; i < size; i++)
array[i] = output[i];

print_array(array, size);
free(output);
}
/**
* radix_sort - Sorts an array of integers in ascending order using Radix sort
* @array: The array of integers
* @size: The size of the array
*/
void radix_sort(int *array, size_t size)
{
int max = getMax(array, size);
int exp;
for (exp = 1; max / exp > 0; exp *= 10)
{
countSort(array, size, exp);
}
}
