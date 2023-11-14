#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>

/**
 * struct format - selects the conversion specifiers for printf
 * @id: pointer to the specifier i.e (l, h) for (d, i, u, o, x, X)
 * @f:  pointer to function for the conversion specifier
 */

typedef struct format
{
	char *id;
	int (*f)();
} convert_match;

int _printf(const char *format, ...);
int printf_perc(void);
int printf_char(va_list args);
int printf_string(va_list args);
int printf_int(va_list args);
int printf_dec(va_list args);


#endif
