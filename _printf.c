#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "main.h"

void handle_print_cases(char c, va_list *list, int *wlen)
{
switch (c)
{
	case 'c':
		_putchar((char) va_arg(*list, int), wlen);
		break;
	case 's':
		simple_print(va_arg(*list, char *), wlen);
		break;
	case 'd':
		printnum_full(va_arg(*list, int), wlen);
		break;
	case 'i':
		printnum_full(va_arg(*list, int), wlen);
		break;
	case 'u':
		printnum_full(va_arg(*list, unsigned int), wlen);
		break;
	default:
		if (c != '%')
			_putchar('%', wlen);
		_putchar(c, wlen);
		break;
}
}

int _printf(const char *format, ...)
{
	int i;
	int write_length;
	va_list list;

	va_start(list, format);
	write_length = 0;

	for (i = 0; format[i] != 0; i++)
	{
	char current = format[i];

	if (current == '%')
	{
		char c;

		c = format[++i];
		if (c == 0)
			goto END_ZONE;

		handle_print_cases(c, &list, &write_length);
		continue;
	}

		_putchar(current, &write_length);
	}

	va_end(list);

END_ZONE:
	if (write_length == 0)
	{
		return (-1);
	}
	return (write_length);
}
