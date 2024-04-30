#include "sort.h"
#include <stdio.h>

/**
 * swap - swaps two ints
 * @a: The first int
 * @b: The second int
 */

void swap(int *a, int *b)
{
int temp = *a;
*a = *b;
*b = temp;
}

/**
 * pivot_finder - finds the pivot and adjusts the array
 * @low: The first element
 * @high: The last element
 * @array: The array to be sorted
 * @size: The size of the array
 *
 * Return: the pivot
 */

int pivot_finder(int *array, int low, int high, size_t size)
{
int pivot = array[high];
int i = low - 1, j;

for (j = low; j <= high - 1; j++)
{
if (array[j] <= pivot)
{
i++;
if (i != j)
{
swap(&array[i], &array[j]);
print_array(array, size);
}
}
}
if ((i + 1) != high)
{
swap(&array[i + 1], &array[high]);
print_array(array, size);
}
return (i + 1);
}

/**
 * quick_sort_helper - helps with the recursion
 * @low: The first element
 * @high: The last element
 * @array: The array to be sorted
 * @size: The size of the array
 */

void quick_sort_helper(int *array, int low, int high, size_t size)
{
if (low < high)
{
int pivot = pivot_finder(array, low, high, size);

quick_sort_helper(array, low, pivot - 1, size);
quick_sort_helper(array, pivot + 1, high, size);
}
}

/**
 * quick_sort - the main func
 * @array: The array to be sorted
 * @size: The size of the array
 */

void quick_sort(int *array, size_t size)
{
quick_sort_helper(array, 0, size - 1, size);
}
