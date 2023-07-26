#include "sort.h"

/**
 * selection_sort - Function that use selection sort algorithm.
 * @array: Array to sort.
 * @size: Size of the array.
 * Return: void.
 */
void selection_sort(int *array, size_t size)
{
	int ss_aux = 0;
	size_t x = 0, y = 0, position = 0;

	if (array == NULL || size == 0)
		return;

	for (; x < size - 1; x++)
	{
		position = x;
		for (y = x + 1; y < size; y++)
		{
			if (array[y] < array[position])
				position = y;
		}
		if (position != x)
		{
			ss_aux = array[x];
			array[x] = array[position];
			array[position] = ss_aux;
			print_array(array, size);
		}
	}
}
