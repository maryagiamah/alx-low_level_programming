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
int linear_search(int *array, size_t size, int value)
{
	size_t i;

	if (!array)
		return (-1);
	for (i = 0; i < size; i++)
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
		if (value < (i + step))
		{
			printf("Value found between indexes [%ld] and [%ld]\n", i, i + step);
			index = linear_search(array + i, i + step, value);
			return (i + index);
		}
	}
	return (-1);
}
