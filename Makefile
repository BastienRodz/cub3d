# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: barodrig <barodrig@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/28 13:04:41 by barodrig          #+#    #+#              #
#    Updated: 2021/02/28 18:17:40 by barodrig         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Cub3D

SRCS = 	./srcs/main.c \
		./srcs/ft_search_conf.c \
		./srcs/ft_search_textures.c \
		./srcs/ft_lst_map.c \
		./srcs/ft_utils_map.c \
		./srcs/ft_check_map.c \
		./gnl/get_next_line.c \
		./gnl/get_next_line_utils.c \

CC = gcc

FLAGS = -Wall -Wextra -Werror -g

OBJS = $(SRCS:.c=.o)

all: libft $(NAME)

libft:
	make -C libft/

$(%.o): $(%.c)
	$(CC) -o $@ -c $^

$(NAME): $(OBJS)
	$(CC) -o $@ $^ -Llibft -lft

clean:
	@rm -f $(OBJS)
	make -C libft/ clean

fclean: clean
	@rm -f $(NAME)
	make -C libft/ fclean

re: fclean all

.PHONY: all clean fclean re libft
