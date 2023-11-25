#include "sort.h"
#include <stdio.h>

/**
* bitonic_compare - Compare two elements based on the direction
* @dir: The direction of comparison (1: increasing, 0: decreasing)
* @array: The array of integers
* @i: Index of the first element
* @j: Index of the second element
*/
void bitonic_compare(int dir, int *array, size_t i, size_t j)
{
if ((dir && array[i] > array[j]) || (!dir && array[i] < array[j]))
{
int temp = array[i];
array[i] = array[j];
array[j] = temp;
}
}

/**
* bitonic_merge - Merge two halves of an array
* @dir: The direction of merging (1: increasing, 0: decreasing)
* @array: The array of integers
* @low: Starting index of the first half
* @count: Size of the half to be merged
*/
void bitonic_merge(int dir, int *array, size_t low, size_t count)
{
if (count > 1)
{
size_t k = count / 2;
size_t i;

for (i = low; i < low + k; i++)
bitonic_compare(dir, array, i, i + k);

bitonic_merge(dir, array, low, k);
bitonic_merge(dir, array, low + k, k);
}
}

/**
* bitonic_sort_recursive - Recursive implementation of Bitonic Sort
* @dir: The direction of sorting (1: increasing, 0: decreasing)
* @array: The array of integers
* @low: Starting index of the subarray
* @count: Size of the subarray
*/
void bitonic_sort_recursive(int dir, int *array, size_t low, size_t count)
{
if (count > 1)
{
size_t k = count / 2;

printf("Merging [%lu/%lu] (%s):\n", count, count * 2, (dir) ? "UP" : "DOWN");
print_array(array + low, count);

bitonic_sort_recursive(1, array, low, k);
bitonic_sort_recursive(0, array, low + k, k);

bitonic_merge(dir, array, low, count);
}
}

/**
* bitonic_sort - Sorts an array of integers in ascending order using Bitonic sort
* @array: The array of integers
* @size: The size of the array
*/
void bitonic_sort(int *array, size_t size)
{
int dir = 1; /* 1 for increasing order, 0 for decreasing order */

if (size > 1)
bitonic_sort_recursive(dir, array, 0, size);
}
