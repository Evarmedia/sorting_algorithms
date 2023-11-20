#include "sort.h"

void swap_ints(int *a, int *b);
void max_heapify(int *array, size_t size, size_t base, size_t root);
void heap_sort(int *array, size_t size);

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmp_Val;

	tmp_Val = *a;
	*a = *b;
	*b = tmp_Val;
}

/**
 * max_heapify - Turn a binary tree into a complete binary heap.
 * @array: An array of integers representing a binary tree.
 * @size: The size of the array/tree.
 * @base: The index of the base row of the tree.
 * @root: The root node of the binary tree.
 */
void max_heapify(int *array, size_t size, size_t base, size_t root)
{
	size_t val_left, right_val, val_largest;

	val_left = 2 * root + 1;
	right_val = 2 * root + 2;
	val_largest = root;

	if (val_left < base && array[val_left] > array[val_largest])
		val_largest = val_left;
	if (right_val < base && array[right_val] > array[val_largest])
		val_largest = right_val;

	if (val_largest != root)
	{
		swap_ints(array + root, array + val_largest);
		print_array(array, size);
		max_heapify(array, size, base, val_largest);
	}
}

/**
 * heap_sort - Sort an array of integers in ascending
 *             order using the heap sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the sift-down heap sort
 * algorithm. Prints the array after each swap.
 */
void heap_sort(int *array, size_t size)
{
	int ind_i;

	if (array == NULL || size < 2)
		return;

	for (ind_i = (size / 2) - 1; ind_i >= 0; ind_i--)
		max_heapify(array, size, size, ind_i);

	for (ind_i = size - 1; ind_i > 0; ind_i--)
	{
		swap_ints(array, array + ind_i);
		print_array(array, size);
		max_heapify(array, size, ind_i, 0);
	}
}

