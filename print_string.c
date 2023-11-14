#include "main.h"
/**
 * printf_string - print a string.
 * @args: argument.
 * Return: the length of the string.
 */
int printf_string(va_list args)
{
	char *s;
	int len;

	s = va_arg(args, char *);
	if (s == NULL)
	{
		s = "(null)";
		len = strlen(s);
		write(1, s, len);
		return (len);
	}
	else
	{
		len = strlen(s);
		write(1, s, len);
		return (len);
	}
}
