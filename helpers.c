#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include "main.h"

/**
 * _putchar - writes ASCII character to stdout.
 * @c: the char to write.
 * @wlen: external write length variable.
 */
void _putchar(char c, int *wlen)
{
	write(1, &c, 1);
	if (wlen != 0)
		(*wlen)++;
}

/**
 * _sign - calculate signum function of an integer
 * @num: the number to calculate signum for
 * Return: result of the signum function (either 1 or -1)
 */
int _sign(int num)
{
	return (num < 0 ? -1 : 1);
}

/**
 * print_num - prints integers to console.
 * @num: integer to print
 * @wlen: external write length variable
 */
void print_num(int num, int *wlen)
{
	if (num != 0)
	{
		print_num(num / 10 * _sign(num), wlen);
		_putchar('0' + (num % (10 * _sign(num)) * _sign(num)), wlen);
	}
}

/**
 * printnum_full - prints integers to console with sign and 0
 * @num: integer to print
 * @wlen: external write length variable
 */
void printnum_full(int num, int *wlen)
{
	if (num == 0)
		_putchar('0', wlen);
	else
	{
		if (num < 0)
			_putchar('-', wlen);
		print_num(num, wlen);
	}
}

/**
 * simple_print - prints a string of characters to console
 * @str: the string to print
 * @wlen: external write length variable
 */
void simple_print(const char *str, int *wlen)
{
	int i;

	if (str == 0)
	{
		simple_print("(null)", wlen);
		return;
	}

	for (i = 0; str[i] != 0; i++)
	{
		_putchar(str[i], wlen);
	}
}
