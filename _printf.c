#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "main.h"

void handle_print_cases(va_list *list)
{
switch (c)
{
	case 'c':
		_putchar((char) va_arg(*list, int));
		break;
	case 's':
		simple_print(va_arg(*list, char *));
		break;
	case 'd':
		printnum_full(va_arg(*list, int));
		break;
	case 'i':
		printnum_full(va_arg(*list, int));
		break;
	case 'u':
		printnum_full(va_arg(*list, unsigned int));
		break;
	default:
		if (c != '%')
			_putchar('%');
		_putchar(c);
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
			handle_print_cases(&list);
			continue;
		}

		_putchar(current);
	}

	va_end(list);

END_ZONE:
	if (write_length == 0)
	{
		return (-1);
	}
	return (write_length);
}
