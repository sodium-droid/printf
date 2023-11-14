#include "main.h"
/**
 * printf_perc - prints "%" or the char 37.
 * Return: 1.
 */
int printf_perc(void)
{
	char c = '%';

	write(1, &c, 1);
	return (1);
}
