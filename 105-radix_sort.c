#include "sort.h"

int get_s_max(int *array, int size);
void radix_sort(int *array, size_t size);
void radix_counting_sort(int *array, size_t size, int sig, int *buff);

/**
 * get_max - Get maximum value in an array of integers.
 * @array: An array of integers.
 * @size: Size of array.
 * Return: Maximum integer in array.
 */
int get_max(int *array, int size)
{
	int s_max, x;

	for (s_max = array[0], x = 1; x < size; x++)
	{
		if (array[x] > s_max)
			s_max = array[x];
	}

	return (s_max);
}

/**
 * radix_sort - Sort array of integers in ascending order
 * @array: Array of integers.
 * @size: Size of array.
 * Description: Implements LSD radix sort algorithm.
 * Return: void
 */
void radix_sort(int *array, size_t size)
{
	int s_max, sig, *s_buff;

	if (array == NULL || size < 2)
		return;

	s_buff = malloc(sizeof(int) * size);
	if (s_buff == NULL)
		return;

	s_max = get_max(array, size);
	for (sig = 1; s_max / sig > 0; sig *= 10)
	{
		radix_counting_sort(array, size, sig, s_buff);
		print_array(array, size);
	}

	free(s_buff);
}

/**
 * radix_counting_sort - Sort significant digits of an array of integers
 * @array: Array of integers.
 * @size: Size of array.
 * @sig: Significant digit to sort on.
 * @buff: Buffer to store sorted array.
 * Return: void
 */
void radix_counting_sort(int *array, size_t size, int sig, int *buff)
{
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t x;

	for (x = 0; x < size; x++)
		count[(array[x] / sig) % 10] += 1;

	for (x = 0; x < 10; x++)
		count[x] += count[x - 1];

	for (x = size - 1; (int)x >= 0; x--)
	{
		buff[count[(array[x] / sig) % 10] - 1] = array[x];
		count[(array[x] / sig) % 10] -= 1;
	}

	for (x = 0; x < size; x++)
		array[x] = buff[x];
}
