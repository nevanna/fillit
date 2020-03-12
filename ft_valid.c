/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htillman <htillman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 01:06:41 by htillman          #+#    #+#             */
/*   Updated: 2019/02/01 17:43:17 by htillman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char			*ft_rewrite(int fd, int *ret)
{
	char			*b;
	char			*buf;

	buf = NULL;
	if (!(b = ft_strnew(550)))
		return (NULL);
	*ret = read(fd, b, 550);
	if (*ret > 525 || *ret < 20)
	{
		ft_strdel(&b);
		return (NULL);
	}
	if (!(buf = ft_strsub(b, 0, *ret)))
		return (NULL);
	ft_strdel(&b);
	return (buf);
}

int					ft_validation(int fd)
{
	char			*data;
	int				ret;
	int				block;

	block = 0;
	ret = 0;
	if (((data = ft_rewrite(fd, &ret)) == NULL))
		return (-1);
	if (ft_count_s(data, ret, &block) < 0)
	{
		ft_strdel(&data);
		return (-1);
	}
	if (ft_fig_val(data) < 0)
	{
		ft_strdel(&data);
		return (-1);
	}
	if (ft_prep_f(block, data) < 0)
	{
		ft_strdel(&data);
		return (-1);
	}
	return (0);
}
