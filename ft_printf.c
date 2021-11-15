# include "libftprintf.h"

int		ft_printf(const char *c, ...)
{
	va_list	arg;
	int		i;

	i = 0;
	va_start(arg, c);
	while (*c != '\0')
	{
		if (*c == '%')
		{
			c++;
			i += ft_printf_dt(c, arg);
		}
		else
			ft_putchar(*c, &i);
		c++;
	}
	va_end(arg);
	return (i);
}
// int main()
// {
// 	char b;
// 	int len;
// 	int mylen;
// 	b = 42;
// 	mylen = ft_printf("FAKE: My age is %p but the most %s is the: #-%d %u\n", &b ,"19", 35, 20);
// 	len = printf("REAL: My age is %p but the most %s is the: #-%d %u\n", &b, "19", 35, 20);
// 	printf("%d \n %d", mylen, len);
// }