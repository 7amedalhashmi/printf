#include "libftprintf.h"

void	ft_putstr(char *s, int *i)
{
	write(1, s, ft_strlen(s));
	*i += ft_strlen(s);
}