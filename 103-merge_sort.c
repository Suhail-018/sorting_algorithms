#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
* merge_sort - Sorts an array of integers in ascending order using
* the Merge sort algorithm.
* @array: The array to be sorted.
* @size: The size of the array.
*/
void merge_sort(int *array, size_t size)
{
if (size > 1)
{
size_t mid = size / 2;
size_t i, j, k;
int *left, *right;
left = malloc(mid * sizeof(int));
right = malloc((size - mid) * sizeof(int));
if (left == NULL || right == NULL)
{
free(left);
free(right);
return;
}
for (i = 0; i < mid; i++)
left[i] = array[i];
for (j = 0; i < size; i++, j++)
right[j] = array[i];
merge_sort(left, mid);
merge_sort(right, size - mid);
i = j = k = 0;
while (i < mid && j < (size - mid))
{
if (left[i] <= right[j])
array[k++] = left[i++];
else
array[k++] = right[j++];
}
while (i < mid)
array[k++] = left[i++];
while (j < (size - mid))
array[k++] = right[j++];
printf("Merging...\n[left]: ");
print_array(left, mid);
printf("[right]: ");
print_array(right, size - mid);
printf("[Done]: ");
print_array(array, size);
free(left);
free(right);
}
}
