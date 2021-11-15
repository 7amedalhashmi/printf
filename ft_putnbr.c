#include "libftprintf.h"

void	ft_putnbr(int n, int *i)
{
	if (n == -2147483648)
		ft_putstr("-2147483648", i);
	else if (n < 0)
	{
		ft_putchar('-', i);
		ft_putnbr(-n, i);
	}
	else if (n >= 10)
	{
		ft_putnbr((n / 10), i);
		ft_putchar((n % 10 + '0'), i);
	}
	else
		ft_putchar((n + '0'), i);
}