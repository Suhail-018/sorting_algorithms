#include "sort.h"
#include <stdio.h>

/**
 * lomuto_partition - Partitions an array using the Lomuto scheme
 *
 * @array: The array to be partitioned
 * @size: Number of elements in @array
 * @low: The starting index of the partition
 * @high: The ending index of the partition
 *
 * Return: Index of the pivot element after partitioning
 */
int lomuto_partition(int *array, size_t size, int low, int high)
{
int pivot;
int j;
int i;
int temp;
i = low - 1;
pivot = array[high];
for (j = low; j <= high - 1; j++)
{
if (array[j] <= pivot)
{
i++;
temp = array[i];
array[i] = array[j];
array[j] = temp;
print_array(array, size);
}
}
temp = array[i + 1];
array[i + 1] = array[high];
array[high] = temp;
print_array(array, size);
return (i + 1);
}

/**
 * quicksort_recursive - Recursively sorts an array using Quick Sort
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 * @low: The starting index of the subarray
 * @high: The ending index of the subarray
 */
void quicksort_recursive(int *array, size_t size, int low, int high)
{
if (low < high)
{
int pivot_index = lomuto_partition(array, size, low, high);
quicksort_recursive(array, size, low, pivot_index - 1);
quicksort_recursive(array, size, pivot_index + 1, high);
}
}
/**
 * quick_sort - Sorts an array of integers in ascending order using Quick Sort
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void quick_sort(int *array, size_t size)
{
if (array == NULL || size < 2)
return;
quicksort_recursive(array, size, 0, size - 1);
}

