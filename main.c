/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htillman <htillman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 17:57:30 by nevanna           #+#    #+#             */
/*   Updated: 2019/02/12 17:30:23 by htillman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	int	fd;

	fd = 0;
	if (argc < 2 || argc > 2)
	{
		ft_putstr("usage: ./fillit source_file\n");
		return (-1);
	}
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		return (-1);
	if (ft_validation(fd) < 0)
	{
		ft_putstr("error\n");
		if (close(fd) == -1)
			return (-1);
		return (-1);
	}
	if (close(fd) == -1)
		return (-1);
	return (0);
}
