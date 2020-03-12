/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htillman <htillman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 21:47:46 by htillman          #+#    #+#             */
/*   Updated: 2019/02/12 17:20:56 by htillman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft.h"
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct		s_pair{
	int				x;
	int				y;
}					t_pair;

typedef struct		s_fig{
	t_pair			pair[4];
	char			liter;
}					t_fig;

typedef struct		s_bank{
	int				start;
	int				block;
	char			**map;
	t_fig			*figurs;
}					t_bank;
int					ft_validation(int	fd);
int					ft_fig_val(char *data);
int					ft_count_s(char *data, int ret, int *block);
void				ft_pr_xy(t_fig *figurs, int block);
void				ft_print_map(int s, char **map);
int					ft_prep_f(int block, char *data);
void				ft_fill_fig(char *data, t_fig *figurs);
void				ft_mv_fig(t_fig *f, int block);
int					ft_create_map(int *s, char ***map);
int					ft_realloc(char ***map, int *s);
void				ft_clear(t_bank *bank, int x, int y, int b);
void				ft_search_f_start(int b, int *j, int *i, t_bank *bank);
int					ft_put(t_bank *bank, int b, int *j, int *i);
int					ft_algo(t_bank *bank, int b);
unsigned int		ft_sqrt(unsigned long n);
int					ft_isliter(char ch);
int					ft_border(t_fig f, int i, int j, int s);
int					ft_free_space(t_bank bank, int i, int j, int b);
void				ft_put_dot(int s, char ***m);
#endif
