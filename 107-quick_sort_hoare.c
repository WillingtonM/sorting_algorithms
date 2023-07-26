#include "sort.h"

int partition_h(int *array, int first, int last, size_t size);
void quick_sort_hoare(int *array, size_t size);
void qsh(int *array, int first, int last, size_t size);
/**
 * partition_h - array partition
 * @array: array to sort
 * @first: first position
 * @last: last position
 * @size: array size
 * Return: int s_pivot index
 */
int partition_h(int *array, int first, int last, size_t size)
{
	int s_pivot = array[last], x = first - 1, y = last + 1, s_aux;

	while (1)
	{
		do {
			x++;
		} while (array[x] < s_pivot);

		do {
			y--;
		} while (array[y] > s_pivot);

		if (y < x)
			return (j);
		if (array[x] > array[y])
		{
			s_aux = array[x];
			array[x] = array[y];
			array[y] = s_aux;
			print_array(array, size);
		}
	}
}

/**
 * quick_sort_hoare - sorts array of integers using Quick sort
 * @array: Array to sort
 * @size: Array size
 * Return: void
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	qsh(array, 0, size - 1, size);
}

/**
 * qsh - sorts array of integers recursively
 * @array: Array to sort
 * @first: First position
 * @last: last position
 * @size: Array size
 * Return: void
 */
void qsh(int *array, int first, int last, size_t size)
{
	int s_pivot;

	if (first < last)
	{
		s_pivot = partition_h(array, first, last, size);
		qsh(array, first, s_pivot, size);
		qsh(array, s_pivot + 1, last, size);
	}
}
