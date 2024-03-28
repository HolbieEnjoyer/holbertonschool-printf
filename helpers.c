#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include "main.h"

void _putchar(char c) {
    write(1, &c, 1);
}

void print_num(int num) {
    if (num < 0) {
        _putchar('-');
        num = num == INT_MIN ? INT_MAX : num * -1;
    }
    
    if (num > 0) {
        print_num(num / 10);
        _putchar('0' + (num % 10));
    }
}

void simple_print(const char* str)
{
	int i;

	for (i = 0; str[i] != 0; i++)
	{
		_putchar(str[i]);
	}
}
