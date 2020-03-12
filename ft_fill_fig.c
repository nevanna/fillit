/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_fig.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htillman <htillman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 21:51:41 by htillman          #+#    #+#             */
/*   Updated: 2019/02/01 17:38:36 by htillman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		ft_fig(t_fig *f, int *iter)
{
	f->pair[iter[3]].x = iter[0];
	f->pair[iter[3]].y = iter[2];
	f->liter = 'A' + iter[1];
}

static void		ft_stupid_norm(int *count)
{
	count[1]++;
	count[2] = 0;
	count[3] = 0;
}

static void		ft_stupid_norm_again(int *count)
{
	count[2]++;
	count[0] = 0;
}

void			ft_fill_fig(char *data, t_fig *figurs)
{
	int		count[4];
	int		n;

	n = 0;
	ft_bzero((void*)count, 4 * 4);
	while (data[n] != '\0')
	{
		if (data[n] == '#' || data[n] == '.')
		{
			if (data[n] == '#')
			{
				ft_fig(&figurs[count[1]], count);
				count[3]++;
			}
			count[0]++;
		}
		if (data[n] == '\n' && count[0] == 4)
			ft_stupid_norm_again(count);
		if (data[n] == '\n' && count[2] == 4
			&& (data[n + 1] == '\n' || data[n + 1] == '\0'))
			ft_stupid_norm(count);
		n++;
	}
}
