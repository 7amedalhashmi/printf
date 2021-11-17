/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halhashm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:35:27 by halhashm          #+#    #+#             */
/*   Updated: 2021/11/17 12:34:33 by halhashm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf(const char *c, ...)
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
