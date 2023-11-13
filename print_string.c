#include "main.h"
/**
 * _printf - A function that prints
 * string or character
 * @format: A pointer that contains the required string or character
 * Return: Returns number of character printer
 */


int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	va_start(args, format);
	
	if (format == NULL)
		return (-1);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
				break;
			switch (*format)
			{
				case 'c':
					count += putchar(va_arg(args, int));
					break;
				case 's':
					{
					const char *str = va_arg(args, const char *);

					while (*str)
					{
						count += putchar(*str);
						str++;
					}
					break;
					}
				case '%':
					count += putchar('%');
					break;
				default:
					break;
			}
		}
		else
			count += putchar(*format);
		format++;
	}
	va_end(args);
	return (count);
}
