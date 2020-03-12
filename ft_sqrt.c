/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htillman <htillman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 22:31:42 by htillman          #+#    #+#             */
/*   Updated: 2019/02/01 17:43:43 by htillman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static unsigned int		ft_sqrt_inv(unsigned long n)
{
	unsigned int		c;
	unsigned int		g;

	c = 0x8000;
	g = 0x8000;
	while (1)
	{
		if (g * g > n)
			g ^= c;
		c >>= 1;
		if (c == 0)
			return (g);
		g |= c;
	}
}

unsigned int			ft_sqrt(unsigned long n)
{
	unsigned int		rez;

	rez = 0;
	rez = ft_sqrt_inv(n);
	if ((rez * rez) == n)
		return (rez);
	else
		return (rez + 1);
}
