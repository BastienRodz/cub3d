/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barodrig <barodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 14:00:05 by barodrig          #+#    #+#             */
/*   Updated: 2021/03/02 20:38:12 by barodrig         ###   ########.fr       */
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

typedef	struct	s_player
{
	int			x;
	int			y;
	char		orient;
	int			pos_count;
}				t_player;

typedef	struct	s_map
{
	char		*line;
	char		**map;
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

	int				error;

	t_map			m;
	t_player		p;
}				t_conf;

/*
**	GET CONF & MAP IN STRUCT
*/
int				search_conf(t_conf *conf, char *buf);
int				search_textures_path(t_conf *conf, char *buf);
int				map_checker(t_map *map, int pos, int i);
int				is_map_1st_line(char *line);
int				map_gnl(int fd, char *line, t_conf *conf);
void			ft_get_player(t_conf *conf, int x, int y);

/*
**	CHECK_MAP
*/
void	tmp_print_check(t_conf *conf);
int		ft_check_walls(t_conf *conf);
int		check_UDRL(t_conf *conf, int y, int x);

#endif
