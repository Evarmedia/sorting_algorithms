#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int val_tmp;

	val_tmp = *a;
	*a = *b;
	*b = val_tmp;
}

/**
 * selection_sort - Sort an array of integers in ascending order
 *                  using the selection sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap.
 */
void selection_sort(int *array, size_t size)
{
	int *minVal;
	size_t ind, jnd;

	if (array == NULL || size < 2)
		return;

	for (ind = 0; ind < size - 1; ind++)
	{
		minVal = array + ind;
		for (jnd = ind + 1; jnd < size; jnd++)
			minVal = (array[jnd] < *minVal) ? (array + jnd) : minVal;

		if ((array + ind) != minVal)
		{
			swap_ints(array + ind, minVal);
			print_array(array, size);
		}
	}
}

