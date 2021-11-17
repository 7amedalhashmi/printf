/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ullitoa_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halhashm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:28:12 by halhashm          #+#    #+#             */
/*   Updated: 2021/11/17 12:36:10 by halhashm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libftprintf.h"

void	ft_tsize(unsigned long long int *n, char *base, size_t *size)
{
	*n = *n / ft_strlen(base);
	while (*n)
	{
		*n = *n / ft_strlen(base);
		*size = *size + 1;
	}
}

void	ft_ullitoa_base(unsigned long long int n, char *base, int *i)
{
	char					*a;
	unsigned long long int	nbr;
	size_t					size;

	nbr = n;
	size = 1;
	ft_tsize(&n, base, &size);
	a = (char *)malloc(size + 1);
	if (!(a))
		return ;
	a[size--] = '\0';
	while (nbr > 0)
	{
		a[size--] = base[nbr % ft_strlen(base)];
		nbr /= ft_strlen(base);
	}
	if (size == 0 && a[1] == '\0')
		a[0] = '0';
	if (a >= 0)
	{
		write(1, a, ft_strlen(a));
		*i += ft_strlen(a);
	}
	free(a);
}
