#include "search_algos.h"
#include <math.h>

/**
 * linear_search - searches an array for a value
 * @array: pointer to the first element of the array to search in
 * @size: number of elements in array
 * @value: the value to search for
 *
 * Return: ZERO OR VALUE INDEX
 */
int search(int *array, size_t begin, size_t end, int value)
{
	size_t i;

	if (!array)
		return (-1);
	for (i = begin; i < end; i++)
	{
		printf("Value checked array[%ld] = [%d]\n", i, array[i]);
		if (array[i] == value)
			return (i);
	}
	return (-1);
}

/**
 * jump_search - searches an array for a value
 * @array: pointer to the first element of the array to search in
 * @size: number of elements in array
 * @value: the value to search for
 *
 * Return: ZERO OR VALUE INDEX
 */
int jump_search(int *array, size_t size, int value)
{
	size_t step = sqrt(size), i, index;

	if (!array)
		return (-1);
	for (i = 0; i < size; i += step)
	{
		printf("Value checked array[%ld] = [%d]\n", i, array[i]);
		if ((i + step) < size && value <= array[i + step])
		{
			printf("Value found between indexes [%ld] and [%ld]\n", i, i + step);
			index = search(array, i, i + step, value);
			return (index);
		}
		else if ((i + step) >= size)
		{
			printf("Value found between indexes [%ld] and [%ld]\n", i, i + step);
			index = search(array, i, size, value);
		}
	}
	return (index);
}
