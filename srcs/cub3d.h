/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barodrig <barodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 14:00:05 by barodrig          #+#    #+#             */
/*   Updated: 2021/03/06 10:18:13 by barodrig         ###   ########.fr       */
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
	int						height;
	int						width;
	int						pad;
	unsigned char			*file_header;
	unsigned char			*img_header;
	int						fd;
}							t_save;

typedef	struct				s_tex
{
	void					*tex_ptr;
	int						*tex_data;
	int						bpp;
	int						size_line;
	int						endian;
	int						width;
	int						height;
	char					*type;
	int						sprite_x;
	int						sprite_y;
}							t_tex;

typedef	struct				s_img
{
	void					*img_ptr;
	int						*img_data;
	int						bpp;
	int						size_line;
	int						endian;
	int						width;
	int						height;
}							t_img;

typedef struct				s_sprite_data
{
	double					sp_dist;
	double					spcamx;
	double					spcamy;
	double					transx;
	double					transy;
	int						spritescreenx;
	int						sprite_height;
	int						drawstart_y;
	int						drawend_y;
	int						sprite_width;
	int						drawstart_x;
	int						drawend_x;
	int						stripe;
	int						sp_x;
	int						sp_y;
}							t_sprite_data;

typedef	struct				s_sprite
{
	double					pos_x;
	double					pos_y;
	t_tex					*tex;
}							t_sprite;

typedef struct				s_move
{
	int						up;
	int						down;
	int						left;
	int						right;
	int						strafl;
	int						strafr;
	int						lean_for;
	int						lean_back;
	int						jump_crouch;
	int						collision;
}							t_move;

typedef struct				s_ray
{
	double					planex;
	double					planey;
	double					stepx;
	double					stepy;
	double					dirx;
	double					diry;
	int						tex_x;
	int						tex_y;
	double					rposx;
	double					rposy;
	double					rdirx;
	double					rdiry;
	double					rdisdx;
	double					rdisdy;
	double					rdistx;
	double					rdisty;
	int						rmapx;
	int						rmapy;
	int						wall;
	int						wstart;
	int						wend;
	double					camera;
	int						hit;
	double					rh;
	double					step_tex;
	double					tex_pos;
	double					dist;
	double					speed;
	double					*zbuffer;
	int						*sp_order;
	double					*sp_distance;
	int						sprite;
	int						sprite_x;
	int						sprite_y;
	double					sprite_dist;
	double					spstart;
	double					spend;
	int						ennemy;
	int						door;
}							t_ray;

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

	int				x_max;
	int				error;

	t_map			m;
	t_player		p;
}				t_conf;


typedef	struct				s_env
{
	void					*mlx_ptr;
	void					*win_ptr;
	t_conf					conf;
	char					**map;
	int						map_height;
	int						map_width;
	double					player_x;
	double					player_y;
	char					orientation;
	int						height;
	int						width;
	unsigned int			floor;
	unsigned int			ceil;
	int						error;
	t_move					move;
	t_ray					ray;
	t_img					*img;
	t_tex					*tex_s;
	t_tex					*tex_n;
	t_tex					*tex_w;
	t_tex					*tex_e;
	t_tex					*tex_sprite;
	t_tex					*tex_sprite1;
	//t_tex					*tex_door;
	//t_tex					*tex_bonus;
	//t_tex					*tex_ennemy;
	//t_tex					*tex_ennemy_1;
	//t_tex					*tex_ennemy_2;
	//t_tex					*tex_ennemy_3;
	//t_tex					*tex_ennemy_4;
	//t_tex					*tex_ennemy_5;
	//t_tex					*tex_ennemy_6;
	//t_tex					*tex_ennemy_7;
	//t_tex					*tex_ennemy_8;
	//t_tex					*tex_ennemy_9;
	//t_tex					*tex_ammo;
	//t_tex					*tex_treasure;
	t_tex					*tex_floor;
	//t_img					*sound_icon;
	//t_img					*bullet;
	//t_img					*lives_icon;
	//t_img					*target;
	//t_img					*weapon_img;
	//int						weapon_shot;
	int						save_flag;
	int						sprite_width;
	//t_weapon_list			weapon_list;
	//t_weapon				*current_weapon;
	//int						weapon_id;
	unsigned int			color;
	//double					lives;
	t_sprite				*sprite_tex;
	//int						sound;
	//int						minimap;
	int						sprite_count;
	t_sprite				*sprite_tab;
	t_sprite_data			sprite;
	//int						open_door;
	//int						shot_box_x;
	//int						shot_box_y;
	//int						shot_box_size;
	//int						ennemy_can_be_shot;
	//int						ennemy_be_shot_x;
	//int						ennemy_be_shot_y;
	//int						ennemy_count;
	//int						level;
	//int						treasure_caught;
	//int						count_ennemy_gif;
	//double					target_divider;
}							t_env;

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
int		check_udrl(t_conf *conf, int y, int x);

/*
**	TEST
*/
//int		init_tex(t_env *env);
//t_env		init_env(t_conf *conf);

#endif
