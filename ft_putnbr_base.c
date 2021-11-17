/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halhashm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:21:20 by halhashm          #+#    #+#             */
/*   Updated: 2021/11/17 12:35:20 by halhashm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	check_base(char *base)
{
	int	i;
	int	z;

	i = 0;
	z = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i])
	{
		z = i + 1;
		if (base[i] == '+' || base[i] == '-')
			return (0);
		if (base[i] < 32 || base[i] > 126)
			return (0);
		while (base[z])
		{
			if (base[i] == base[z])
				return (0);
			z++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base, int *len)
{
	int	size_base;

	size_base = 0;
	if (check_base(base))
	{
		if (nbr == -2147483648)
		{
			ft_putstr("-2147483648", len);
			return ;
		}
		else if (nbr < 0)
		{
			nbr = -nbr;
			ft_putchar('-', len);
		}
		while (base[size_base])
			size_base++;
		if (nbr < size_base)
			ft_putchar(base[nbr], len);
		if (nbr >= size_base)
		{
			ft_putnbr_base(nbr / size_base, base, len);
			ft_putnbr_base(nbr % size_base, base, len);
		}
	}
}
