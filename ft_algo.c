/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htillman <htillman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 22:04:01 by htillman          #+#    #+#             */
/*   Updated: 2019/02/12 17:26:19 by htillman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	ft_limit_x(int *i, int *j, t_bank *bank)
{
	if ((*i) > ((bank->start) - 1))
	{
		(*j)++;
		(*i) = 0;
	}
}

int			ft_algo(t_bank *bank, int b)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if ((b) == (bank->block))
		return (1);
	while ((b) < (bank->block))
	{
		if (ft_put(bank, (b), &j, &i) == 1)
		{
			if (ft_algo(bank, (b + 1)) == 1)
				return (1);
			else
			{
				ft_search_f_start((b), &j, &i, bank);
				ft_limit_x(&i, &j, bank);
			}
		}
		else
			return (-1);
	}
	return (-1);
}
