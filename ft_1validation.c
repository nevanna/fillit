/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_1validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htillman <htillman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 21:47:15 by htillman          #+#    #+#             */
/*   Updated: 2019/02/01 18:06:11 by htillman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int			ft_control_for_count_s(int block, int i, int count_f)
{
	int				kols;

	kols = 0;
	kols = (block * 20) + (block - 1);
	if ((block <= 26 || block >= 1) && kols == i)
		if (block * 4 == count_f)
			return (1);
	return (-1);
}

static void			ft_norm(int *one, int *three)
{
	(*one)++;
	(*three)++;
}

static void			ft_norm_q(int *two, int *zero)
{
	(*two)++;
	(*zero) = 0;
}

static int			ft_norm_w(int *two, int *three, int *block)
{
	if (*three != 4)
		return (-1);
	(*block)++;
	(*two) = 0;
	(*three) = 0;
	return (1);
}

int					ft_count_s(char *data, int ret, int *block)
{
	int				i;
	int				count[4];
	int				bl;

	bl = 0;
	i = 0;
	ft_bzero((void*)count, 4 * 4);
	while (i < ret)
	{
		if (data[i] != '#' && data[i] != '.' && data[i] != '\n')
			return (-1);
		if (data[i] == '#')
			ft_norm(&count[1], &count[3]);
		if (data[i] == '#' || data[i] == '.')
			count[0]++;
		if (data[i] == '\n' && count[0] == 4)
			ft_norm_q(&count[2], &count[0]);
		if (data[i] == '\n' && count[2] == 4 && (data[i + 1] == '\n'
			|| data[i + 1] == '\0'))
			if (ft_norm_w(&count[2], &count[3], block) == -1)
				return (-1);
		i++;
	}
	return (ft_control_for_count_s(*block, i, count[1]));
}
