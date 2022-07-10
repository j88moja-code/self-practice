#include "main.h"
#include <unistd.h>
/*FOR CHARACTERS && STRINGS */

/**
 * print_char - prints out a character.
 *
 * @c: character to be printed
 * Return: Always 1.
 */

int print_char(va_list c)
{
    char ch = (char)va_arg(c, int);

    _putchar(ch);
    return (1);
}

/**
 * print_string - prints out the string.
 *
 * @s: string to be printed out.
 * Return: number of chars to be printed.
 */

int print_string(va_list s)
{
    int count;
    char *str = va_arg(s, char *);

    if (str == NULL)
        str = "(null)";

    for (count = 0; str[count]; count++)
    {
        _putchar(str[count]);
    }
    return (count);
}

/* FOR NUMBERS && DIGITS */

/**
 * print_int - prints out an integer.
 *
 * @i: integer to be printed out.
 *
 * Return: number of characters and digits printed out.
 */

int print_int(va_list i)
{
    int arr[10];
    int x, y, z, sum, counter;

    z = va_arg(i, int);
    counter = 0;
    y = 1000000000;
    arr[0] = z / y;
    for (x = 1; x < 10; x++)
    {
        y /= 10;
        arr[x] = (z / y) % 10;
    }
    if (z < 0)
    {
        _putchar('-');
        counter++;
        for (x = 0; x < 10; x++)
            arr[x] *= -1;
    }
    for (x = 0, sum = 0; x < 10; x++)
    {
        sum += arr[x];
        if (sum != 0 || x == 9)
        {
            _putchar('0' + arr[x]);
            counter++;
        }
    }
    return (counter);
}

/**
 * print_dol - prints out a decimal/ double.
 *
 * @d: decimal to be printed out.
 *
 * Return: number of characters and digits to be printed
 */

int print_dol(va_list d)
{
    int arr[10];
    int x, y, z, sum, counter;

    z = va_arg(d, int);
    counter = 0;
    y = 1000000000;
    arr[0] = z / y;
    for (x = 1; x < 10; x++)
    {
        y /= 10;
        arr[x] = (z / y) % 10;
    }
    if (z < 0)
    {
        _putchar('-');
        counter++;
        for (x = 0; x < 10; x++)
            arr[x] *= -1;
    }
    for (x = 0, sum = 0; x < 10; x++)
    {
        sum += arr[x];
        if (sum != 0 || x == 9)
        {
            _putchar('0' + arr[x]);
            counter++;
        }
    }
    return (counter);
}

/**
 * print_unsignedint -prints out binary number from unsigned int.
 *
 * @b: unsigned int to be printed out.
 *
 * Return: number of digits printed.
 */
int print_unsignedint(va_list b)
{
    unsigned int x, y, z, sum;
    unsigned int arr[32];
    int counter;

    x = va_arg(b, unsigned int);
    y = 2147483648;
    arr[0] = x / y;
    for (z = 1; z < 32; z++)
    {
        y /= 2;
        arr[z] = (x / y) % 2;
    }
    for (z = 0, sum = 0, counter = 0; z < 32; z++)
    {
        sum += arr[z];
        if (sum || z == 31)
        {
            _putchar('0' + arr[z]);
            counter++;
        }
    }
    return (counter);
}