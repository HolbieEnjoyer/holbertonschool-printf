#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include "main.h"

extern unsigned int write_length;
void _putchar(char c) {
    write(1, &c, 1);
    write_length++;
}

int _sign(int num)
{
    return num < 0 ? -1 : 1;
}

void print_num(int num) {
    
    if (num != 0) {
        print_num(num / 10 * _sign(num));
        _putchar('0' + (num % (10 * _sign(num)) * _sign(num)));
    }
}

void printnum_full(int num)
{
    if (num == 0)
        _putchar('0');
    else {
        if (num < 0)
            _putchar('-');
        print_num(num);
    }
}

void simple_print(const char* str)
{
	int i;

	if (str == 0)
	{
		simple_print("(null)");
		return;
	}

	for (i = 0; str[i] != 0; i++)
	{
		_putchar(str[i]);
	}
}
