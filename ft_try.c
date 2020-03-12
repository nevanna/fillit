/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_try.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htillman <htillman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 23:58:58 by htillman          #+#    #+#             */
/*   Updated: 2019/02/12 16:19:45 by htillman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_create_map(int *s, char ***map)
{
	int		i;

	i = 0;
	if (!((*map) = (char **)malloc(sizeof(char *) * ((*s) + 1))))
		return (-1);
	(*map)[(*s)] = NULL;
	while (i < (*s))
	{
		if (!((*map)[i] = ft_strnew(*s)))
		{
			while (i >= 0)
				free((*map)[i--]);
			free(*map);
			return (-1);
		}
		i++;
	}
	ft_put_dot((*s), map);
	return (1);
}

int			ft_realloc(char ***map, int *s)
{
	int		i;

	i = (*s);
	while (i >= 0)
		free((*map)[i--]);
	free((*map));
	(*s)++;
	if (ft_create_map(s, map) == -1)
		return (-1);
	return (1);
}
