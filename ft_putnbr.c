/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halhashm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:20:20 by halhashm          #+#    #+#             */
/*   Updated: 2021/11/17 12:35:04 by halhashm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
