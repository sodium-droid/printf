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
		{"%s", printf_string}, {"%c", printf_char}, {"%o", printf_oct}, {"%x", printf_hex}, {"%X", printf_HEX},
		{"%%", printf_perc},{"%R", printf_rot13}, {"%b", printf_bin}, {"%u", printf_unsigned},
		{"%i", printf_int}, {"%d", printf_dec}, {"%S", printf_exclusive_string}, {"%p", printf_pointer}
	};
	va_list args;
	int mlen, i = 0, j, len = 0;
	mlen = (sizeof(m) / sizeof(m[0])) + 1;

	va_start(args, format);
	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			for (j = 0; j < mlen; j++)
			{
				if (m[j].id[0] == format[i] && m[j].id[1] == format[i + 1])
				{	len += m[j].f(args);
					i += 2;
					break;
				}
			}
			if (j == mlen)
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
