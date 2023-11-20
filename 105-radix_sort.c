#include "sort.h"

int get_max(int *array, int size);
void radix_counting_sort(int *array, size_t size, int sig, int *da_buffa);
void radix_sort(int *array, size_t size);

/**
 * get_max - Get the maximum value in an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: The maximum integer in the array.
 */
int get_max(int *array, int size)
{
	int maximum_Val, ind_i;

	for (maximum_Val = array[0], ind_i = 1; ind_i < size; ind_i++)
	{
		if (array[ind_i] > maximum_Val)
			maximum_Val = array[ind_i];
	}

	return (maximum_Val);
}

/**
 * radix_counting_sort - Sort the significant digits of an array of integers
 *                       in ascending order using the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 * @sig: The significant digit to sort on.
 * @da_buffa: A buffer to store the sorted array.
 */
void radix_counting_sort(int *array, size_t size, int sig, int *da_buffa)
{
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t ind_i;

	for (ind_i = 0; ind_i < size; ind_i++)
		count[(array[ind_i] / sig) % 10] += 1;

	for (ind_i = 0; ind_i < 10; ind_i++)
		count[ind_i] += count[ind_i - 1];

	for (ind_i = size - 1; (int)ind_i >= 0; ind_i--)
	{
		da_buffa[count[(array[ind_i] / sig) % 10] - 1] = array[ind_i];
		count[(array[ind_i] / sig) % 10] -= 1;
	}

	for (ind_i = 0; ind_i < size; ind_i++)
		array[ind_i] = da_buffa[ind_i];
}

/**
 * radix_sort - Sort an array of integers in ascending
 *              order using the radix sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the LSD radix sort algorithm. Prints
 * the array after each significant digit increase.
 */
void radix_sort(int *array, size_t size)
{
	int maximum_Val, sig, *da_buffa;

	if (array == NULL || size < 2)
		return;

	da_buffa = malloc(sizeof(int) * size);
	if (da_buffa == NULL)
		return;

	maximum_Val = get_max(array, size);
	for (sig = 1; maximum_Val / sig > 0; sig *= 10)
	{
		radix_counting_sort(array, size, sig, da_buffa);
		print_array(array, size);
	}

	free(da_buffa);
}
