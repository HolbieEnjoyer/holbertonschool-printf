#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include "main.h"

void _putchar(char c, int *wlen)
{
	write(1, &c, 1);
	if (wlen != 0)
		(*wlen)++;
}

int _sign(int num)
{
	return (num < 0 ? -1 : 1);
}

void print_num(int num, int *wlen)
{
	if (num != 0)
	{
		print_num(num / 10 * _sign(num), wlen);
		_putchar('0' + (num % (10 * _sign(num)) * _sign(num)), wlen);
	}
}

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
