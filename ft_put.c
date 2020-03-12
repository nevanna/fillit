/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htillman <htillman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 17:13:54 by nevanna           #+#    #+#             */
/*   Updated: 2019/02/12 17:42:21 by htillman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_place(t_bank *bank, int i, int j, int b)
{
	int		k;

	k = 0;
	while (k < 4)
	{
		bank->map[j + bank->figurs[b].pair[k].y]
		[i + bank->figurs[b].pair[k].x] = bank->figurs[b].liter;
		k++;
	}
	return (1);
}

int			ft_put(t_bank *bank, int b, int *j, int *i)
{
	int		bx;
	int		by;

	bx = (*i);
	by = (*j);
	while ((*j) < (bank->start))
	{
		if (bx == 0 && by == 0)
			(*i) = 0;
		while ((*i) < (bank->start))
		{
			if ((ft_free_space(*bank, (*i), (*j), b) == -1))
			{
				ft_place(bank, (*i), (*j), b);
				return (1);
			}
			(*i)++;
		}
		bx = 0;
		by = 0;
		(*j)++;
	}
	return (-1);
}
