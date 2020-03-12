/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prep_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htillman <htillman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 17:31:39 by htillman          #+#    #+#             */
/*   Updated: 2019/02/12 17:29:57 by htillman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	ft_free_final(char ***map, int s)
{
	int		i;

	i = s;
	while (i >= 0)
		free((*map)[i--]);
	free((*map));
}

int			ft_prep_f(int block, char *data)
{
	t_bank	bank;
	char	**map;

	map = NULL;
	if (!(bank.figurs = (t_fig *)malloc(sizeof(t_fig) * block)))
		return (-1);
	ft_fill_fig(data, bank.figurs);
	ft_strdel(&data);
	bank.block = block;
	ft_mv_fig(bank.figurs, bank.block);
	bank.start = (int)(ft_sqrt((unsigned long)(block * 4)));
	if (ft_create_map(&bank.start, &bank.map) < 0)
		return (-1);
	while (ft_algo(&bank, 0) != 1)
	{
		if (ft_realloc(&bank.map, &bank.start) == -1)
			return (-1);
	}
	ft_print_map(bank.start, bank.map);
	ft_free_final(&bank.map, bank.start);
	exit(0);
	return (0);
}
