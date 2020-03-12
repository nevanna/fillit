/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fig_val.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htillman <htillman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 20:56:39 by htillman          #+#    #+#             */
/*   Updated: 2019/02/02 14:54:52 by htillman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		ft_cross(char *tmp, int j, int *side, int i)
{
	int			touch;

	touch = 0;
	if (tmp[j] == '#')
	{
		if (tmp[j + 1] == '#' && i < 20)
			(touch)++;
		if (j >= 1)
			if (tmp[j - 1] == '#' && i > 0)
				(touch)++;
		if (tmp[j + 5] == '#' && i < 15)
			(touch)++;
		if (j >= 5)
			if (tmp[j - 5] == '#' && i > 4)
				(touch)++;
		if ((touch) == 0)
			return (-1);
		if ((touch) > (*side))
			(*side) = (touch);
		return (1);
	}
	else
		return (-1);
}

int				ft_fig_val(char *data)
{
	int			i;
	int			j;
	int			side;

	i = 0;
	j = 0;
	side = 0;
	while (data[j] != '\0')
	{
		if (data[j] == '#')
			if ((ft_cross(data, j, &side, i)) < 0)
				return (-1);
		if (data[j] == '\n' && (data[j + 1] == '\n' || data[j + 1] == '\0'))
		{
			if (side < 2)
				return (-1);
			else
				side = 0;
			i = -1;
		}
		i++;
		j++;
	}
	return (1);
}
