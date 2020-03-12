# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: htillman <htillman@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/02 21:40:05 by htillman          #+#    #+#              #
#    Updated: 2019/02/12 18:55:09 by htillman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRC = ft_1validation.c ft_fig_val.c main.c ft_prep_f.c ft_fill_fig.c ft_mv.c ft_pr_xy.c ft_sqrt.c ft_try.c ft_isliter.c ft_put.c ft_put_dot.c ft_search_f_start.c ft_algo.c ft_valid.c
FILESO = ft_1validation.o ft_fig_val.o main.o ft_prep_f.o ft_fill_fig.o ft_mv.o ft_pr_xy.o ft_sqrt.o ft_try.o ft_isliter.o ft_put.o ft_put_dot.o ft_search_f_start.o ft_algo.o ft_valid.o
FLAGS = -Wall -Wextra -Werror
LIBA = -L ./libft -lft
INCL = -I ./libft

all: $(NAME)

$(NAME):
	make -C ./libft/
	gcc $(FLAGS) -o $(NAME) $(SRC) $(LIBA) $(INCL)
clean:

	rm -f $(FILESO)
	make clean -C ./libft/
fclean: clean
	rm -f $(NAME)
	make fclean -C ./libft/
re: fclean all
