#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
* swap - Swaps two integers in an array and prints the array
* @array: The array of integers
* @size: The size of the array
* @a: Index of the first integer to swap
* @b: Index of the second integer to swap
*/
void swap(int *array, size_t size, int a, int b)
{
int temp;
temp = array[a];
array[a] = array[b];
array[b] = temp;
print_array(array, size);
}
/**
* sift_down - Performs the sift-down operation in heap sort
* @array: The array of integers
* @size: The size of the array
* @start: The root index of the heap
* @end: The end index of the heap
*/
void sift_down(int *array, size_t size, int start, int end)
{
int root = start;
int child, swap_idx;
while (2 * root + 1 <= end)
{
child = 2 * root + 1;
swap_idx = root;
if (array[swap_idx] < array[child])
swap_idx = child;
if (child + 1 <= end && array[swap_idx] < array[child + 1])
swap_idx = child + 1;
if (swap_idx != root)
{
swap(array, size, root, swap_idx);
root = swap_idx;
}
else
{
break;
}
}
}
/**
* heap_sort - Sorts an array of integers in ascending order using Heap sort
* @array: The array of integers
* @size: The size of the array
*/
void heap_sort(int *array, size_t size)
{
int i;
for (i = size / 2 - 1; i >= 0; i--)
sift_down(array, size, i, size - 1);
for (i = size - 1; i > 0; i--)
{
swap(array, size, 0, i);
sift_down(array, size, 0, i - 1);
}
}
