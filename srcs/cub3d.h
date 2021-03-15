/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barodrig <barodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 14:00:05 by barodrig          #+#    #+#             */
/*   Updated: 2021/03/15 12:24:06 by barodrig         ###   ########.fr       */
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
# include "../mlx/mlx.h"

typedef struct				s_save
{
	int				height;
	int				width;
	int				pad;
	unsigned char	*file_header;
	unsigned char	*img_header;
	int				fd;
}					t_save;

typedef	struct				s_tex
{
	void			*tex_ptr;
	int				*tex_data;
	int				bpp;
	int				size_line;
	int				endian;
	int				width;
	int				height;
	char			*type;
	int				sprite_x;
	int				sprite_y;
}							t_tex;

typedef struct				s_sprite_data
{
	double			sp_dist;
	double			spcamx;
	double			spcamy;
	double			transx;
	double			transy;
	int				spritescreenx;
	int				sprite_height;
	int				drawstart_y;
	int				drawend_y;
	int				sprite_width;
	int				drawstart_x;
	int				drawend_x;
	int				stripe;
	int				sp_x;
	int				sp_y;
}							t_sprite_data;

typedef	struct				s_sprite
{
	double			pos_x;
	double			pos_y;
	t_tex			*tex;
}					t_sprite;

typedef struct				s_ray
{
	double			planex;
	double			planey;
	double			stepx;
	double			stepy;
	double			dirx;
	double			diry;
	int				tex_x;
	int				tex_y;
	double			rposx;
	double			rposy;
	double			rdirx;
	double			rdiry;
	double			rdisdx;
	double			rdisdy;
	double			rdistx;
	double			rdisty;
	int				rmapx;
	int				rmapy;
	int				wall;
	int				wstart;
	int				wend;
	double			camera;
	int				hit;
	double			rh;
	double			step_tex;
	double			tex_pos;
	double			dist;
	double			speed;
	double			*zbuffer;
	int				*sp_order;
	double			*sp_distance;
	int				sprite;
	int				sprite_x;
	int				sprite_y;
	double			sprite_dist;
	double			spstart;
	double			spend;
	int				ennemy;
	int				door;
}					t_ray;

typedef struct	s_rgb
{
	int				r;
	int				g;
	int				b;

}				t_rgb;

typedef	struct	s_player
{
	double			x;
	double			y;
	int				radius;
	char			orient;
	int				pos_count;
	float			sidewalk;
	int				turndir;
	int				walkdir;
	float			angle;
	float			dir;
	float			rotspeed;
	float			movespeed;
	int				collision;
}				t_player;

typedef	struct	s_map
{
	char			*line;
	char			**map;
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

	int				x;
	int				y;
	int				x_max;
	int				y_max;
	float			ratio_x;
	float			ratio_y;
	int				error;

	t_map			m;
	t_player		p;
}				t_conf;

typedef struct  s_data {
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				width;
	int				height;
}               t_data;

typedef	struct				s_env
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_data			data;
	t_conf			conf;
	int				map_height;
	int				map_width;
	int				height;
	int				width;
	unsigned int	floor;
	unsigned int	ceil;
	int				error;
	t_ray			ray;
	t_tex			*tex_s;
	t_tex			*tex_n;
	t_tex			*tex_w;
	t_tex			*tex_e;
	t_tex			*tex_sprite;
	t_tex			*tex_sprite1;
	t_tex			*tex_floor;
	int				save_flag;
	int				sprite_width;
	unsigned int	color;
	t_sprite		*sprite_tex;
	int				sprite_count;
	t_sprite		*sprite_tab;
	t_sprite_data	sprite;
	int				lives;
	int				minimap;
}							t_env;

/*
**	GET CONF & MAP IN STRUCT
*/
int					search_conf(t_conf *conf, char *buf);
int					search_textures_path(t_conf *conf, char *buf);
int					map_checker(t_map *map, int pos, int i);
int					map_gnl(int fd, char *line, t_conf *conf);
void				ft_get_max_y_max_x(t_conf *conf, int x, int y);
void				adapt_to_greatest(t_conf *conf);

/*
** MINIMAP
*/
int					create_game(t_env *env);

/*
** MLX UTILS
*/
int					put_right_color(char c);
void 				my_mlx_pixel_put(t_data *data, int x, int y, int color);
int					init_raybuffer(t_env *env);
void				ft_free_img(t_env *env, t_data *data);

/*
**	CHECK_MAP
*/
int					ft_check_walls(t_conf *conf);
int					check_udrl(t_conf *conf, int y, int x);

/*
** CHECK MAP UTILS
*/
void				ft_get_player(t_conf *conf, int x, int y);
int					is_in_set(char c, char *set);
int					is_map_1st_line(char *line);
void				tmp_print_check(t_conf *conf);
int					get_color(t_rgb color);

/*
**	EVENTS
*/
int					ft_keyhook(t_env *env);
void				player_movement(t_conf *conf, t_env *env);
void				ft_exit(t_conf *conf);
void				ft_construct_player(t_env *env);

# define W 13
# define A 0
# define D 2
# define S 1
# define TAB 48
# define SHIFT 257
# define SPACE 49
# define UP_ARROW 126
# define DOWN_ARROW 125
# define LEFT_ARROW 123
# define RIGHT_ARROW 124
# define ESC 53
# define RED_CROSS 33
# define DIST 0.1

#endif
