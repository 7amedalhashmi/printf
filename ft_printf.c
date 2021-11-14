# include "libftprintf.h"

int		ft_printf(const char *c, ...)
{
	va_list		arg;

	va_start(arg, c);
	while (*c != '\0')
	{
		if (*c == '%')
		{
			c++;
			ft_printf_dt(c, arg);
		}
		else
			ft_putchar(*c);
		c++;
	}
	va_end(arg);
	return (0);
}

int main()
{
	char b;
	b = 42;
	ft_printf("FAKE: My age is %p but the most %s is the: #-%d %u\n", &b ,"19", 35, 20);
	printf("REAL: My age is %p but the most %s is the: #-%d %u\n", &b, "19", 35, 20);
}