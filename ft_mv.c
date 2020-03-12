/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mv.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htillman <htillman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 01:12:58 by htillman          #+#    #+#             */
/*   Updated: 2019/02/01 18:08:12 by htillman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		ft_relative(t_fig *f, int minx, int miny)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		f->pair[i].x = f->pair[i].x - minx;
		f->pair[i].y = f->pair[i].y - miny;
		i++;
	}
}

static void		ft_min(t_fig *f)
{
	int			minx;
	int			miny;
	int			k;

	minx = f->pair[0].x;
	miny = f->pair[0].y;
	k = 0;
	while (k < 4)
	{
		if (minx > f->pair[k].x)
			minx = f->pair[k].x;
		if (miny > f->pair[k].y)
			miny = f->pair[k].y;
		k++;
	}
	ft_relative(f, minx, miny);
}

void			ft_mv_fig(t_fig *f, int block)
{
	int			i;

	i = 0;
	while (i < block)
	{
		ft_min(&f[i]);
		i++;
	}
}
