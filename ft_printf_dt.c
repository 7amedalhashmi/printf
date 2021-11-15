# include "libftprintf.h"

int	ft_printf_dt(const char *c, va_list arg)
{
	int i;

	i = 0;
	if (*c == 'i')
		ft_putnbr(va_arg(arg, int), &i);
	else if (*c == 'd')
		ft_putnbr_base((va_arg(arg, int)), "0123456789", &i);
	else if (*c == 'u')
		ft_ullitoa_base((va_arg(arg, unsigned int)), "0123456789", &i);
	else if (*c == 'c')
		ft_putchar(va_arg(arg, int), &i);
	else if (*c == 's')
		ft_putstr(va_arg(arg, char *), &i);
	else if (*c == 'x')
		ft_ullitoa_base((va_arg(arg, unsigned int)), "0123456789abcdef", &i);
	else if (*c == 'X')
		ft_ullitoa_base((va_arg(arg, unsigned int)), "0123456789ABCDEF", &i);
	else if (*c == 'p')
	{
		ft_putstr("0x", &i);
		ft_ullitoa_base((va_arg(arg, unsigned long)), "0123456789abcdef", &i);
	}
	else if (*c == '%')
		ft_putchar('%', &i);
	return (i);
}