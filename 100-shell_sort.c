#include "sort.h"

/**
  * shell_sort - Function that sorts array using shell algorithm.
  * @array: Array to sort.
  * @size: Length of array.
  * Return: void.
  */
void shell_sort(int *array, size_t size)
{
	int ss_aux = 0;
	unsigned int x = 0, y = 0, ss_gap = 0;

	if (array == NULL || size < 2)
		return;

	while (ss_gap < size / 3)
		ss_gap = ss_gap * 3 + 1;

	for (; ss_gap > 0; ss_gap = (ss_gap - 1) / 3)
	{
		for (x = ss_gap; x < size; x++)
		{
			ss_aux = array[x];
			for (y = x; y >= ss_gap && array[y - ss_gap] > ss_aux;
					y -= ss_gap)
			{
				if (array[y] != array[y - ss_gap])
					array[y] = array[y - ss_gap];
			}
			if (array[y] != ss_aux)
				array[y] = ss_aux;

		}
		print_array(array, size);
	}
}
