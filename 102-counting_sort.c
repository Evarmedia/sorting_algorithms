#include "sort.h"

/**
 * get_max - Get the maximum value in an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: The maximum integer in the array.
 */
int get_max(int *array, int size)
{
	int maxNumVal, ind_i;

	for (maxNumVal = array[0], ind_i = 1; ind_i < size; ind_i++)
	{
		if (array[ind_i] > maxNumVal)
			maxNumVal = array[ind_i];
	}

	return (maxNumVal);
}

/**
 * counting_sort - Sort an array of integers in ascending order
 *                 using the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the counting array after setting it up.
 */
void counting_sort(int *array, size_t size)
{
	int *count, *sorted, maxNumVal, ind_i;

	if (array == NULL || size < 2)
		return;

	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
		return;
	maxNumVal = get_max(array, size);
	count = malloc(sizeof(int) * (maxNumVal + 1));
	if (count == NULL)
	{
		free(sorted);
		return;
	}

	for (ind_i = 0; ind_i < (maxNumVal + 1); ind_i++)
		count[ind_i] = 0;
	for (ind_i = 0; ind_i < (int)size; ind_i++)
		count[array[ind_i]] += 1;
	for (ind_i = 0; ind_i < (maxNumVal + 1); ind_i++)
		count[ind_i] += count[ind_i - 1];
	print_array(count, maxNumVal + 1);

	for (ind_i = 0; ind_i < (int)size; ind_i++)
	{
		sorted[count[array[ind_i]] - 1] = array[ind_i];
		count[array[ind_i]] -= 1;
	}

	for (ind_i = 0; ind_i < (int)size; ind_i++)
		array[ind_i] = sorted[ind_i];

	free(sorted);
	free(count);
}

