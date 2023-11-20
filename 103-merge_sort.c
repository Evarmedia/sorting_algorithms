#include "sort.h"

void merge_subarr(int *subarr, int *da_buffa, size_t front, size_t mid,
		size_t back);
void merge_sort_recursive(int *subarr, int *da_buffa, size_t front, size_t back);
void merge_sort(int *array, size_t size);

/**
 * merge_subarr - Sort a subarray of integers.
 * @subarr: A subarray of an array of integers to sort.
 * @da_buffa: A buffer to store the sorted subarray.
 * @front: The front index of the array.
 * @mid: The middle index of the array.
 * @back: The back index of the array.
 */
void merge_subarr(int *subarr, int *da_buffa, size_t front, size_t mid,
		size_t back)
{
	size_t ind_i, jnd_j, k = 0;

	printf("Merging...\n[left]: ");
	print_array(subarr + front, mid - front);

	printf("[right]: ");
	print_array(subarr + mid, back - mid);

	for (ind_i = front, jnd_j = mid; ind_i < mid && jnd_j < back; k++)
		da_buffa[k] = (subarr[ind_i] < subarr[jnd_j]) ? subarr[ind_i++] : subarr[jnd_j++];
	for (; ind_i < mid; ind_i++)
		da_buffa[k++] = subarr[ind_i];
	for (; jnd_j < back; jnd_j++)
		da_buffa[k++] = subarr[jnd_j];
	for (ind_i = front, k = 0; ind_i < back; ind_i++)
		subarr[ind_i] = da_buffa[k++];

	printf("[Done]: ");
	print_array(subarr + front, back - front);
}

/**
 * merge_sort_recursive - Implement the merge sort algorithm through recursion.
 * @subarr: A subarray of an array of integers to sort.
 * @da_buffa: A buffer to store the sorted result.
 * @front: The front index of the subarray.
 * @back: The back index of the subarray.
 */
void merge_sort_recursive(int *subarr, int *da_buffa, size_t front, size_t back)
{
	size_t mid;

	if (back - front > 1)
	{
		mid = front + (back - front) / 2;
		merge_sort_recursive(subarr, da_buffa, front, mid);
		merge_sort_recursive(subarr, da_buffa, mid, back);
		merge_subarr(subarr, da_buffa, front, mid, back);
	}
}

/**
 * merge_sort - Sort an array of integers in ascending
 *              order using the merge sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the top-down merge sort algorithm.
 */
void merge_sort(int *array, size_t size)
{
	int *da_buffa;

	if (array == NULL || size < 2)
		return;

	da_buffa = malloc(sizeof(int) * size);
	if (da_buffa == NULL)
		return;

	merge_sort_recursive(array, da_buffa, 0, size);

	free(da_buffa);
}

