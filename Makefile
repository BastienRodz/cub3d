# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: barodrig <barodrig@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/28 13:04:41 by barodrig          #+#    #+#              #
<<<<<<< HEAD
#    Updated: 2021/03/05 18:11:37 by barodrig         ###   ########.fr        #
=======
#    Updated: 2021/03/05 11:01:53 by barodrig         ###   ########.fr        #
>>>>>>> 038e851cb422072270fa11449bf2509d160b7f11
#                                                                              #
# **************************************************************************** #

NAME = Cub3D

SRCS = 	./srcs/main.c \
		./srcs/ft_search_conf.c \
		./srcs/ft_search_textures.c \
		./srcs/ft_check_map.c \
<<<<<<< HEAD
		./srcs/ft_search_map.c \
=======
		./srcs/ft_init_env.c \
		./srcs/ft_init_textures.c \
>>>>>>> 038e851cb422072270fa11449bf2509d160b7f11
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
