#include "libftprintf.h"

void	ft_putstr(char *s, int *i)
{
	if (s == NULL)
	{
		write(1, "(null)", 6);
		*i += 6;
		return ;
	}
	else if (*s != '\0')
	{
		write(1, s, ft_strlen(s));
		*i += ft_strlen(s);
		return ;
	}
}