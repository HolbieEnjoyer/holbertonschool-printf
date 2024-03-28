#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "main.h"

extern unsigned int write_length;
int _printf(const char *format, ...)
{
    int i;
    
    va_list list;
    va_start(list, format);
    write_length = 0;
    
    for (i = 0; format[i] != 0; i++) {
        char current = format[i];
        if (current == '%') {
        char c;
	    c = format[++i];
	    if (c == 0)
	        goto END_ZONE;

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
            
            continue;
        }
        
        _putchar(current);
    }

    va_end(list);

END_ZONE:
    if (write_length == 0) {
        return -1;
    }
    return write_length;
}
