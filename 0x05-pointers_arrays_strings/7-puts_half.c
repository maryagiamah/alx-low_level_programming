#include "main.h"
#include <stdio.h>

/**
* puts_half - prints the reverse of  a string.
* @str: a pointer to the string array.
*
* Return: Always0 (Success)
*/

void puts_half(char *str)
{
	int p, m = 0;

	while (*(str + p))
		m++;
	p = m / 2;
	if (i % 2)
		p += 1;
	while (p < m)
	{
		_putchar(*(str + p));
		p++;
	}
	_putchar('\n');
}
