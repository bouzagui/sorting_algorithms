#include "sort.h"

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
 * selection_sort - sorts an array of integers in ascending order
 * using the selection sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 */
void selection_sort(int *array, size_t size)
{
int i, j, min;

for (i = 0; i < (int)(size - 1); i++)
{
min = i;
for (j = i + 1; j < (int)size; j++)
{
if (array[j] < array[min])
{
min = j;
}
}
if (min != i)
{
swap(&array[i], &array[min]);
print_array(array, size);
}
}
}
