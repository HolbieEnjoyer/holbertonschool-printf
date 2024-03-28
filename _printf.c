#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "main.h"

int _printf(const char *format, ...) {

    va_list list;
    va_start(list, format);

    for (int i = 0; format[i] != 0; i++) {
        char current = format[i];
        if (current == '%') {
            char c = format[++i];

            switch (c) {
                case 'c':
                    _putchar((char)va_arg(list, int));
                    break;
                case 's':
                    char* str = va_arg(list, char*);
                    for (int j = 0; str[j] != 0; j++) {
                        _putchar(str[j]);
                    }
                    break;
                case 'd':
                    print_num(va_arg(list, int));
                    break;
                case 'u':
                    print_num(va_arg(list, int));
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
}
