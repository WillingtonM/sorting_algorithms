#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
  * counting_sort - Function that sorts array using counting algorithm.
  * @array: Array to sort.
  * @size: Length of array.
  * Return: void.
  */
void counting_sort(int *array, size_t size)
{
	unsigned int x = 1;
	int *count = NULL, k = 0, j = 0;

	if (array == NULL || size < 2)
		return;

	k = array[0];
	for (; x < size; x++)
	{
		if (array[x] > k)
			k = array[x];
	}

	count = malloc(sizeof(int) * (k + 1));
	if (count == NULL)
		return;

	for (j = 0; j <= k; j++)
		count[j] = 0;
	for (x = 0; x < size; x++)
		count[array[x]] += 1;
	for (j = 0; j < k; j++)
	{
		count[j + 1] += count[j];
		printf("%d, ", count[j]);
	}
	count[j + 1] += count[j];
	printf("%d\n", count[j + 1]);
	for (x = 0; x < size; x++)
	{
		j = count[array[x]] - 1;
		if (array[x] != array[j])
		{
			k = array[x];
			array[x] = array[j];
			array[j] = k;
		}
	}
	free(count);
}
