#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "main.h"

int _printf(const char *format, ...)
{
    int i, len;
    
    va_list list;
    va_start(list, format);
    
    for (i = 0, len = 0; format[i] != 0; i++) {
        char current = format[i];
        if (current == '%') {
        char c;
	    c = format[++i];

            switch (c) {
                case 'c':
                    _putchar((char)va_arg(list, int));
                    break;
                case 's':
                    simple_print(va_arg(list, char*));
                    break;
                case 'd':
                    print_num(va_arg(list, int));
                    break;
                case 'i':
                    print_num(va_arg(list, int));
                    break;
                case 'u':
                    print_num(va_arg(list, unsigned int));
                    break;
                default:
                    _putchar(c);
                    break;
            }
            
            len++;
            continue;
        }
        
        len++;
        _putchar(current);
    }

    va_end(list);

    return len;
}
