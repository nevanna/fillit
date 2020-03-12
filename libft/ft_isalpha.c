/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htillman <htillman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 17:26:37 by htillman          #+#    #+#             */
/*   Updated: 2018/12/07 20:34:02 by htillman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isalpha(int c)
{
	int		i;
	int		j;

	j = 65;
	i = 97;
	while (i <= 122)
	{
		if (c == i)
			return (1);
		i++;
	}
	while (j <= 90)
	{
		if (c == j)
			return (1);
		j++;
	}
	return (0);
}