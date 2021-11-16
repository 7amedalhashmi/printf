/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halhashm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:19:54 by halhashm          #+#    #+#             */
/*   Updated: 2021/11/16 14:20:02 by halhashm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
