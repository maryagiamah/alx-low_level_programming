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
{                                                                                              size_t left = 0, right = size - 1, mid;

	if (!array)                                                                                     return (-1);
	while (left <= right)
	{                                
		mid = left + (((double)(right - left) / (array[right] - array[left])) * (value - array[left]));
		if (array[mid] < value)
			left = mid + 1;
		else if (array[mid] > value)                                                                    right = mid - 1;                                                                else
			return (mid);
	}
	return (-1);
}
