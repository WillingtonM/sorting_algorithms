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
 * Return: void
 */
void merge(int *array, int size, int first, int mid, int *cpy)
{
	int x, y, k;

	print_left_right(array, size, first, mid);

	k = first;
	y = mid;
	x = first;

	printf("[Done]: ");
	while (k < size)
	{
		if (x < mid && (y >= size || array[x] <= array[y]))
		{
			cpy[k] = array[x];
			x++;
		}
		else
		{
			cpy[k] = array[y];
			y++;
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
 * Return: void
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
 * mergeSort - Array separator
 * @cpy: Copy of array
 * @first: Initial position
 * @size: Size of original  array
 * @array: Original array
 * Return: void
 */
void mergeSort(int *cpy, int first, int size, int *array)
{
	int ms_mid;

	if (size - first < 2)
		return;

	ms_mid = (size + first) / 2;

	mergeSort(array, first, ms_mid, cpy);
	mergeSort(array, ms_mid, size, cpy);

	merge(cpy, size, first, ms_mid, array);
}

/**
 * merge_sort - create partition and copy
 * @array: Array
 * @size : Array size
 * Return: void
 */
void merge_sort(int *array, size_t size)
{
	int *c_copy;

	c_copy = malloc(sizeof(int) * size - 1);

	if (c_copy == NULL)
		return;

	copy_array(array, c_copy, size);

	mergeSort(c_copy, 0, size, array);
	free(c_copy);
}

/**
 * copy_array - Copy array of int
 * @arr: Array src
 * @cpy: Array dest
 * @size : array size
 * Return: void
 */
void copy_array(int *arr, int *cpy, int size)
{
	int x;

	for (x = 0; x < (int)size; x++)
		cpy[x] = arr[x];
}
