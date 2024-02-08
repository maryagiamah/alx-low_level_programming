#include "search_algos.h"
/**
 * expB_search - uses binary search algorithm on an array
 * @array: pointer to the first element of the array to search in
 * @start: point to start search
 * @end: point to end search
 * @value: the value to search for
 *
 * Return: INDEX OF VALUE OR ZERO
 */
int expB_search(int *array, size_t start, size_t size, int value)
{
	size_t left = start, right = end - 1, mid;

	if (!array)
		return (-1);

	while (left <= right)
	{
		printf("Searching in array: ");
		print_array(array, left, right);

		mid = (left + right) / 2;

		if (array[mid] < value)
			left = mid + 1;
		else if (array[mid] > value)
			right = mid - 1;
		else
			return (mid);
	}
	return (-1);
}

/**
 * print_array - prints array
 * @array: array to print
 * @left: index to start print
 * @right: index to end print
 *
 * Return: Void
 */
void print_array(int *array, size_t left, size_t right) 
{
	if (!array || (left > right))
		return;
	if (left == right)                                                                      {
		printf("%d\n", array[left]);
		return;
	}
	while (left <= right)
	{
		if (left == right)
		{
			printf("%d", array[left]);
			break;
		}
			printf("%d, ", array[left]);
			left++;
		}
		printf("\n");
}

/**
 * exponential_search - searches an array for a value
 * @array: pointer to the first element of the array to search in
 * @size: number of elements in array
 * @value: the value to search for
 *
 * Return: ZERO OR VALUE INDEX
 */
int exponential_search(int *array, size_t size, int value)
{
	size_t step = 2, i, index;
	if (!array)
		return (-1);
	for (i = 0; i < size; i *= step)
	{
		printf("Value checked array[%ld] = [%d]\n", i, array[i]);
		if ((i + step) < size && value <= array[i + step])
		{
			printf("Value found between indexes [%ld] and [%ld]\n", i, i + step);
			index = expB_search(array, i, i + step + 1, value);
			return (index);
		}
		else if ((i + step) >= size)
		{
			printf("Value found between indexes [%ld] and [%ld]\n", i, i + step);
			index = expB_search(array, i, size, value);
		}
	}
	return (index);
}
