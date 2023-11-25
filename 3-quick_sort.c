#include "sort.h"

/**
 * partition - Partitions an array using the Lomuto scheme
 * @array: The array to partition
 * @low: The lowest index of the partition
 * @high: The highest index of the partition
 * @size: The size of the array
 *
 * Return: The final index of the pivot
 */
int partition(int *array, int low, int high, size_t size)
{
    int pivot, i, j, tmp;

    pivot = array[high]; /* The pivot is always the last element */
    i = low - 1; /* The index of the smaller element */
    for (j = low; j <= high - 1; j++)
    {
        /* If the current element is smaller than the pivot */
        if (array[j] < pivot) /* This is the correct condition */
        {
            i++; /* Increment the index of the smaller element */
            /* Swap array[i] and array[j] */
            tmp = array[i];
            array[i] = array[j];
            array[j] = tmp;
            /* Print the array after each swap */
            print_array(array, size);
        }
    }
    /* Swap array[i + 1] and array[high] (the pivot) */
    tmp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = tmp;
    /* Print the array after the final swap */
    print_array(array, size);
    return (i + 1); /* Return the final index of the pivot */
}

/**
 * quick_sort_helper - Recursively sorts an array using the Quick sort algorithm
 * @array: The array to sort
 * @low: The lowest index of the partition to sort
 * @high: The highest index of the partition to sort
 * @size: The size of the array
 */
void quick_sort_helper(int *array, int low, int high, size_t size)
{
    int pi;

    if (low < high)
    {
        /* Partition the array and get the final index of the pivot */
        pi = partition(array, low, high, size);
        /* Recursively sort the left and right partitions */
        quick_sort_helper(array, low, pi - 1, size);
        quick_sort_helper(array, pi + 1, high, size);
    }
}

/**
 * quick_sort - Sorts an array of integers in ascending order using Quick sort
 * @array: The array to sort
 * @size: The size of the array
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    /* Call the helper function with low = 0 and high = size - 1 */
    quick_sort_helper(array, 0, size - 1, size);
}
