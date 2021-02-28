/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barodrig <barodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 14:00:05 by barodrig          #+#    #+#             */
/*   Updated: 2021/02/28 17:08:24 by barodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include "../gnl/get_next_line.h"
# include "../libft/libft.h"

typedef struct	s_rgb
{
	int				r;
	int				g;
	int				b;

}				t_rgb;

typedef struct	s_map
{
	char			*line;
	struct s_map	*next;
}				t_map;

typedef struct	s_conf
{
	int				screen_width;
	int				screen_height;

	char			*NO_path;
	char			*SO_path;
	char			*WE_path;
	char			*EA_path;

	char			*S_path;
	t_rgb			floor;
	t_rgb			ceil;

	t_map			*map;
}				t_conf;

int			search_conf(t_conf *conf, char *buf);
int			search_textures_path(t_conf *conf, char *buf);

t_map		*ft_lstnewmap(void *content);
void		ft_lstadd_backmap(t_map **alst, t_map *new);
char		*remove_space(char *buf, char c);

#endif
