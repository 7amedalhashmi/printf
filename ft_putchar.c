#include "libftprintf.h"

void	ft_putchar(char c, int *i)
{
	write(1, &c, 1);
	*i += 1;
}