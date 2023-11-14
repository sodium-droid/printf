#include "main.h"
/**
 * _printf - A function that prints
 * string or character
 * @format: A pointer that contains the required string or character
 * Return: Returns number of character printer
 */
int _printf(const char *format, ...)
{
	convert_match m[] = {
		{"%s", printf_string}, {"%c", printf_char},
		{"%%", printf_perc},
		{"%i", printf_int}, {"%d", printf_dec}
	};
	va_list args;
	int i = 0, j, len = 0;

	va_start(args, format);
	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			for (j = 0; j < 6; j++)
			{
				if (m[j].id[0] == format[i] && m[j].id[1] == format[i + 1])
				{	len += m[j].f(args);
					i += 2;
					break;
				}
			}
			if (j == 6)
			{	write(1, &format[i], 1);
				len++;
				i++;
			}
		}
		write(1, &format[i], 1);
		len++;
		i++;
	}
	va_end(args);
	return (len);
}
