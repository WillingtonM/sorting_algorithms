#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

void print_left_right(int *array, int size, int first, int mid);
void merge(int *array, int size, int first, int mid, int *cpy);
void mergeSort(int *cpy, int first, int size, int *array);
void copy_array(int *arr, int *cpy, int size);
void merge_sort(int *array, size_t size);

/**
 * merge - Merge values in position of array
 * @array: First array
 * @size: Size of second array
 * @cpy: Copy of array
 * @mid: Middle position
 * @first: initial position
 */
void merge(int *array, int size, int first, int mid, int *cpy)
{
	int i, j, k;

	print_left_right(array, size, first, mid);

	i = first;
	j = mid;

	printf("[Done]: ");
	k = first;
	while (k < size)
	{
		if (i < mid && (j >= size || array[i] <= array[j]))
		{
			cpy[k] = array[i];
			i++;
		}
		else
		{
			cpy[k] = array[j];
			j++;
		}
		if (k < size - 1)
			printf("%d, ", cpy[k]);
		else
			printf("%d\n", cpy[k]);
		k++;
	}
}

/**
 * print_left_right - print left and right partitions
 * @array: Array
 * @size: Size of second array
 * @first: Initial position
 * @mid: Middle position
 */
void print_left_right(int *array, int size, int first, int mid)
{
	int x;

	printf("Merging...\n");
	printf("[left]: ");
	x = first;
	while (x < mid)
	{
		if (x != mid - 1)
			printf("%d, ", array[x]);
		else
			printf("%d\n", array[x]);
		x++;
	}

	printf("[right]: ");
	x = mid;
	while (x < size)
	{
		if (x < size - 1)
			printf("%d, ", array[x]);
		else
			printf("%d\n", array[x]);
		x++;
	}
}

/**
 * mergeSort - array separator
 * @cpy: Copy of array
 * @first: initial position
 * @size: size of original  array
 * @array: original array
 */
void mergeSort(int *cpy, int first, int size, int *array)
{
	int mid;

	if (size - first < 2)
		return;

	mid = (size + first) / 2;

	mergeSort(array, first, mid, cpy);
	mergeSort(array, mid, size, cpy);

	merge(cpy, size, first, mid, array);
}

/**
 * merge_sort - create partition and copy
 * @array: array
 * @size : array size
 */
void merge_sort(int *array, size_t size)
{
	int *cpy;

	cpy = malloc(sizeof(int) * size - 1);

	if (cpy == NULL)
		return;

	copy_array(array, cpy, size);

	mergeSort(cpy, 0, size, array);
	free(cpy);
}

/**
 * copy_array - copy array of int
 * @arr: array src
 * @cpy: array dest
 * @size : array size
 */
void copy_array(int *arr, int *cpy, int size)
{
	int i;

	for (i = 0; i < (int)size; i++)
		cpy[i] = arr[i];
}
