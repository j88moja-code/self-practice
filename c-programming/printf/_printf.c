#include "main.h"
/**
 * _printf - produces output according to a format.
 *
 * @format: is the character string. The format string is composed of zero
 * or more directives.
 * Return: number of characters printed (excluding the null byte used to end
 * output strings).
 */
int _printf(const char *format, ...)
{
	va_list args_ptr;
	unsigned int i = 0;
	unsigned int count = 0;
	int (*f)(va_list);

	va_start(args_ptr, format);
	if (format == NULL)
		return (-1);

	while (format[i])
	{
		for (; format[i] != '%' && format[i]; i++)
		{
			_putchar(format[i]);
			count++;
		}
		if (!format[i])
			return (count);
		f = get_char_func(&format[i + 1]);
		if (f != NULL)
		{
			count += f(args_ptr);
			i += 2;
			continue;
		}
		if (!format[i + 1])
			return (-1);
		_putchar(format[i]);
		count++;
		if (format[i + 1] == '%')
			i += 2;
		else
			i++;
	}
	va_end(args_ptr);
	return (count);
}
