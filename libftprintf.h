#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <string.h>
# include <stdlib.h>

void	ft_putchar(char c, int *i);
void	ft_putnbr_base(int nbr, char *base, int *len);
void	ft_putnbr(int n, int *i);
void	ft_putstr(char *s, int *i);
size_t	ft_strlen(const char *c);
void    ft_ullitoa_base(unsigned long long int n, char *base, int *i);
int		ft_printf(const char *c, ...);
int     ft_printf_dt(const char *c, va_list arg);

#endif