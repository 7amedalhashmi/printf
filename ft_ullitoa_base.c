/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ullitoa_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halhashm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:28:12 by halhashm          #+#    #+#             */
/*   Updated: 2021/11/16 14:37:46 by halhashm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libftprintf.h"

void	ft_ullitoa_base(unsigned long long int n, char *base, int *i)
{
	char					*a;
	unsigned long long int	nbr;
	size_t					size;
	int						b_len;

	b_len = ft_strlen(base);
	nbr = n;
	size = 1;
	a = (char *)malloc(size + 1);
	while (n /= b_len)
		size++;
	if (!(a))
		return ;
	a[size--] = '\0';
	while (nbr > 0)
	{
		a[size--] = base[nbr % b_len];
		nbr /= b_len;
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
