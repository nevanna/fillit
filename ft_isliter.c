/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isliter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htillman <htillman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 16:58:52 by nevanna           #+#    #+#             */
/*   Updated: 2019/02/12 16:50:58 by htillman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_isliter(char ch)
{
	if (ch >= 'A' && ch <= 'Z')
		return (1);
	else
		return (0);
}

int			ft_border(t_fig f, int i, int j, int s)
{
	int		flag;
	int		k;

	k = 0;
	flag = 0;
	while (k < 4)
	{
		if ((j + f.pair[k].y) > (s - 1) || (i + f.pair[k].x) > (s - 1))
		{
			flag++;
			return (flag);
		}
		k++;
	}
	return (flag);
}

int			ft_free_space(t_bank bank, int i, int j, int b)
{
	int		k;
	int		rez;

	k = 0;
	rez = 0;
	if ((rez = ft_border(bank.figurs[b], i, j, bank.start)) == 0)
	{
		while (k < 4)
		{
			if (ft_isliter((bank.map)[j + bank.figurs[b].pair[k].y]
				[i + bank.figurs[b].pair[k].x]) == 0)
				k++;
			else
				return (-2);
		}
		return (-1);
	}
	else
		return (rez);
}
