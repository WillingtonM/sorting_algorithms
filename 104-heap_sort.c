#include "sort.h"

void heap_sort(int *array, size_t size);
void swap_root(int *array, size_t root, size_t hi, size_t size);

/**
 * heap_sort - Function that sorts an array using heap algorithm.
 * @array: Array to sort.
 * @size: Size of the array.
 * Return: void.
 */
void heap_sort(int *array, size_t size)
{
	int s_tmp = 0;
	size_t hi = 0, s_gap = 0;

		if (array == NULL || size < 2)
			return;

		for (s_gap = (size - 2) / 2; 1; s_gap--)
		{
			swap_root(array, s_gap, size - 1, size);
			if (s_gap == 0)
				break;
		}

		hi = size - 1;
		while (hi > 0)
	{
		s_tmp = array[hi];
		array[hi] = array[0];
		array[0] = s_tmp;
		print_array(array, size);
		hi--;
		swap_root(array, 0, hi, size);
	}
}

/**
 * swap_root - Function that swap the root nodes.
 * @array: Heap to sort.
 * @root: Root of the heap.
 * @hi: Higher index.
 * @size: Size of the array.
 * Return: void
 */
void swap_root(int *array, size_t root, size_t hi, size_t size)
{
	size_t lo = 0, mi = 0, s_tmp = 0;
	int s_aux = 0;

	while ((lo = (2 * root + 1)) <= hi)
	{
		s_tmp = root;
		mi = lo + 1;
		if (array[s_tmp] < array[lo])
				s_tmp = lo;
		if (mi <= hi && array[s_tmp] < array[mi])
				s_tmp = mi;
		if (s_tmp == root)
				return;
		s_aux = array[root];
		array[root] = array[s_tmp];
		array[s_tmp] = s_aux;
		print_array(array, size);
		root = s_tmp;
	}
}