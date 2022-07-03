#include "main.h"

/**
 * _puts - prints a string.
 *
 * @str: a pointer for the string.
 *
 * Return: nothing.
 */

void _puts(char *str)
{
	while (*str != '\0')
	{
		_putchar(*str);
		str++;
	}
	_putchar('\0');
}
