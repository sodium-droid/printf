#include "main.h"
/**
 * printf_int - prints integer
 * @args: arguments to print
 * Return: number of characters printed
 */
int printf_int(va_list args)
{
	int n = va_arg(args, int);
	int absVal = (n < 0) ? -n : n;
	int  exp = 1;
	int digit, i = 0;
	char c;

	if (n < 0)
	{
		c = '-';
		write(1, &c, 1);
		i++;
	}
	while (absVal / exp >= 10)
		exp *= 10;

	while (exp > 0)
	{
		digit = absVal / exp;
		c = digit + '0';
		write(1, &c, 1);
		absVal -= digit * exp;
		exp /= 10;
		i++;
	}
	return (i);
}

/**
 * printf_dec - prints decimal
 * @args: argument to print
 * Return: number of characters printed
 */
int printf_dec(va_list args)
{ 

	int n = va_arg(args, int);
	int absVal = (n < 0) ? -n : n;
	int  exp = 1;
	int digit, i = 0;
	char c;

	if (n < 0)
	{
		c = '-';
		write(1, &c, 1);
		i++;
	}
	while (absVal / exp >= 10)
		exp *= 10;

	while (exp > 0)
	{
		digit = absVal / exp;
		c = digit + '0';
		write(1, &c, 1);
		absVal -= digit * exp;
		exp /= 10;
		i++;
	}
	return (i);
}
