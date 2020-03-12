/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_f_start.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htillman <htillman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 20:41:04 by htillman          #+#    #+#             */
/*   Updated: 2019/02/12 16:50:17 by htillman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_clear(t_bank *bank, int x, int y, int b)
{
	int		k;

	k = 0;
	while (k < 4)
	{
		(bank->map)[y + bank->figurs[b].pair[k].y]
		[x + bank->figurs[b].pair[k].x] = '.';
		k++;
	}
}

void		ft_search_f_start(int b, int *j, int *i, t_bank *bank)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < (bank->start))
	{
		x = 0;
		while (x < (bank->start))
		{
			if ((bank->map)[y + bank->figurs[b].pair[0].y]
				[x + bank->figurs[b].pair[0].x] == bank->figurs[b].liter)
			{
				ft_clear(bank, x, y, b);
				(*i) = x + 1;
				(*j) = y;
				return ;
			}
			x++;
		}
		y++;
	}
}
