/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barodrig <barodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 14:00:05 by barodrig          #+#    #+#             */
/*   Updated: 2021/02/27 15:39:23 by barodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>
# include <math.h>
# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"

typedef struct	s_rgb
{
	int				r;
	int				g;
	int				b;

}				t_rgb;

typedef	struct	s_map;
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

int					ft_check_map_error(int fd);

#endif
