/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wlen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htillman <htillman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 20:45:31 by htillman          #+#    #+#             */
/*   Updated: 2018/12/27 19:52:54 by htillman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_wlen(char const *str, size_t start, char c)
{
	size_t	wlen;

	wlen = 0;
	while (str[start] != c)
	{
		wlen++;
		start++;
	}
	return (wlen);
}
