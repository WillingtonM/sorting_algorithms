/*
 * File: 106-bitonic_sort.c
 * Auth: Brennan D Baraban
 */

#include "sort.h"

void bitonic_seqc(int *array, size_t size, size_t start, size_t seq, char flow);
void bitonic_sort(int *array, size_t size);
void bitonic_merge(int *array, size_t size, size_t start, size_t seq,
		char flow);
void swap_ints(int *a, int *b);

/**
 * bitonic_merge - Sort bitonic sequence inside an array of integers.
 * @array: Array of integers.
 * @size: Size of array.
 * @start: Starting index of sequence in array to sort.
 * @seq: Size of sequence to sort.
 * @flow: Direction to sort in.
 * Return: void
 */
void bitonic_merge(int *array, size_t size, size_t start, size_t seq,
				   char flow)
{
	size_t x, s_jump = seq / 2;

	if (seq > 1)
	{
		for (x = start; x < start + s_jump; x++)
		{
			if ((flow == UP && array[x] > array[x + s_jump]) ||
				(flow == DOWN && array[x] < array[x + s_jump]))
				swap_ints(array + x, array + x + s_jump);
		}
		bitonic_merge(array, size, start, s_jump, flow);
		bitonic_merge(array, size, start + s_jump, s_jump, flow);
	}
}

/**
 * bitonic_sort - Sort array of integers in ascending order
 * @array: Array of integers.
 * @size: Size of array.
 * Description: Prints array after each swap.
 * Return: void
 */
void bitonic_sort(int *array, size_t size)
{
	if (size < 2 || array == NULL)
		return;

	bitonic_seqc(array, size, 0, size, UP);
}

/**
 * swap_ints - Swap two integers in an array.
 * @a: First integer to swap.
 * @b: Second integer to swap.
 * Return: void
 */
void swap_ints(int *a, int *b)
{
	int s_tmp;

	s_tmp = *a;
	*a = *b;
	*b = s_tmp;
}

/**
 * bitonic_seqc - Convert array of integers into a bitonic sequence.
 * @array: Array of integers.
 * @size: Size of array.
 * @start: Starting index of a block of building bitonic sequence.
 * @seq: Size of a block of building bitonic sequence.
 * @flow: Direction to sort bitonic sequence block in.
 * Return: void
 */
void bitonic_seqc(int *array, size_t size, size_t start, size_t seq, char flow)
{
	size_t s_cut = seq / 2;
	char *str = (flow == UP) ? "UP" : "DOWN";

	if (seq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);

		bitonic_seqc(array, size, start, s_cut, UP);
		bitonic_seqc(array, size, start + s_cut, s_cut, DOWN);
		bitonic_merge(array, size, start, seq, flow);

		printf("Result [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);
	}
}

