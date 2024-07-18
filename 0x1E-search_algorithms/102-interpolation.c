#include "search_algos.h"

/**
 * interpolation_search - uses binary search algorithm on an array
 * @array: pointer to the first element of the array to search in
 * @size: number of elements in array
 * @value: the value to search for
 *
 * Return: ZERO OR VALUE INDEX
 */
int interpolation_search(int *array, size_t size, int value)
{
	size_t left = 0, right = size - 1, pos;

	if (!array)
		return (-1);
	while (left <= right)
	{
		pos = left + ((right - left) *
((double)(value - array[left]) / (array[right] - array[left])));
		if (pos >= size)
		{
			printf("Value checked array[%ld] is out of range\n", pos);
			break;
		}

		printf("Value checked array[%ld] = [%d]\n", pos, array[pos);

		if (array[pos] < value)
			left = pos + 1;
		else if (array[pos] > value)
			right = pos - 1;
		else
			return (pos);
	}
	return (-1);
}
