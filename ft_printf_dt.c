# include "libftprintf.h"

void	ft_printf_dt(const char *c, va_list arg)
{
	if (*c == 'i')
		ft_putnbr(va_arg(arg, int));
	else if (*c == 'd')
		ft_putnbr_base((va_arg(arg, int)), "0123456789");
	else if (*c == 'u')
		ft_ullitoa_base((va_arg(arg, unsigned int)), "0123456789");
	else if (*c == 'c')
		ft_putchar(va_arg(arg, int));
	else if (*c == 's')
		ft_putstr(va_arg(arg, char *));
	else if (*c == 'x')
		ft_putnbr_base((va_arg(arg, unsigned int)), "0123456789abcdef");
	else if (*c == 'X')
		ft_putnbr_base((va_arg(arg, unsigned int)), "0123456789ABCDEF");
	else if (*c == 'p')
	{
		ft_putstr("0x");
		ft_ullitoa_base((va_arg(arg, unsigned long)), "0123456789abcdef");
	}
	else if (*c == '%')
		ft_putchar('%');	
}