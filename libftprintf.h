#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <string.h>
# include <stdlib.h>

void	ft_putchar(char c);
void	ft_putnbr_base(int nbr, char *base);
void	ft_putnbr(int n);
void	ft_putstr(char *s);
size_t	ft_strlen(const char *c);
void    ft_ullitoa_base(unsigned long long int n, char *base);
int		ft_printf(const char *c, ...);
void	ft_printf_dt(const char *c, va_list arg);

#endif