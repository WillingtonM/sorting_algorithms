
#include "sort.h"

int partition(int *array, int first, int last, size_t size);
void quick_s(int *array, int first, int last, size_t size);
void quick_sort(int *array, size_t size);

/**
 * partition - partition
 * @array: Array to sort
 * @first: First position
 * @last: last position
 * @size: Array size
 * Return: Pivot index
 */
int partition(int *array, int first, int last, size_t size)
{
	int x = first - 1, p_aux, y;

	for (y = first; y <= last - 1; y++)
	{
		if (array[y] < array[last])
		{
			x++;
			if (x < y)
			{
				p_aux = array[x];
				array[x] = array[y];
				array[y] = p_aux;
				print_array(array, size);
			}
		}
	}
	if (array[x + 1] > array[last])
	{
		p_aux = array[x + 1];
		array[x + 1] = array[last];
		array[last] = p_aux;
		print_array(array, size);
	}

	return (x + 1);
}

/**
 * quick_sort - sorts an array of integers using the Quick
 * sort algorithm in ascending order
 * @array: array to sort
 * @size: array size
 */
void quick_sort(int *array, size_t size)
{
	quick_s(array, 0, size - 1, size);
}

/**
 * quick_s - sorts an array of integers recursively
 * @array: Array to sort
 * @first: First position
 * @last: Last position
 * @size: Array size
 */
void quick_s(int *array, int first, int last, size_t size)
{
	int pvt;

	if (first < last)
	{
		pvt = partition(array, first, last, size);
		quick_s(array, first, pvt - 1, size);
		quick_s(array, pvt + 1, last, size);
	}
}