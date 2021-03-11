# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: barodrig <barodrig@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/28 13:04:41 by barodrig          #+#    #+#              #
#    Updated: 2021/03/11 11:43:20 by barodrig         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Cub3D

SRCS = 	./srcs/main.c \
		./srcs/ft_search_conf.c \
		./srcs/ft_search_textures.c \
		./srcs/ft_check_map.c \
		./srcs/ft_map_utils.c \
		./srcs/ft_search_map.c \
		./srcs/ft_mlx_utils.c \
		./srcs/ft_minimap.c \
		./srcs/ft_key.c \
		./srcs/ft_error.c \
		./srcs/ft_movement.c \
		./gnl/get_next_line.c \
		./gnl/get_next_line_utils.c \

CC = clang

FLAGS = -Wall -Wextra -Werror -g

OBJS = $(SRCS:.c=.o)

$(%.o): $(%.c)
		@$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

all: libft mlx $(NAME)

mlx :
		@make -C mlx/

libft:
		@make -C libft/

$(NAME): $(OBJS)
		@$(CC) $(FLAGS) -o $@ $^ -Lmlx -lmlx -framework OpenGL -framework AppKit -lm -Llibft -lft

clean:
		@rm -f $(OBJS)
		@make -C libft/ clean
		@make -C mlx/ clean

fclean: clean
		@rm -f $(NAME)
		@make -C libft/ fclean
		@make -C mlx/ clean

re: fclean all

norm:
	norminette $(SRCS) ./cub3d.h

.PHONY: all clean fclean re libft mlx
