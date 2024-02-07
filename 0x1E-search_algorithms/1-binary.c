#include "search_algos.h"
/**
 * binary_search - uses binary search algorithm on an array
 * @array: pointer to the first element of the array to search in
 * @size: number of elements in array
 * @value: the value to search for
 *
 * Return: ZERO OR VALUE INDEX
 */
int binary_search(int *array, size_t size, int value)
{
	size_t left = 0, right = size - 1, mid;

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

	if (!array | (left > right))
		return;
	if (left == right)
	{
		printf("%d\n", array[left]);
		return;
	}
	while (left <= right)
	{
		if (left != righy)
			printf(", ");
		printf("%d", array[left]);
		left++;
	}
	printf("\n");
}
