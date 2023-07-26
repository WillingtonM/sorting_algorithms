#include "sort.h"

/**
  * bubble_sort - A function for bubble sorting.
  * @array: Array to sort.
  * @size: length of aaray.
  * Return: void.
  */
void bubble_sort(int *array, size_t size)
{
	size_t x = 0, y = 0;
	int bs_aux = 0;

	if (array == NULL || size == 0)
		return;
	for (; x < size - 1; x++)
	{
		for (y = 0; y < size - x - 1; y++)
		{
			if (array[y] > array[y + 1])
			{
				bs_aux = array[y + 1];
				array[y + 1] = array[y];
				array[y] = bs_aux;
				print_array(array, size);
			}
		}
	}
}
