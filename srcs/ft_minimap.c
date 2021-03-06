/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barodrig <barodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 11:07:24 by barodrig          #+#    #+#             */
/*   Updated: 2021/03/15 17:05:22 by barodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_create_player(t_env *env, double x, double y)
{
	float	angle;
	float	i;

	angle = 0;
	i = 0;
	env->conf.p.radius = 7000 / env->conf.screen_width;
	while (i <= env->conf.p.radius)
	{
		angle = 0;
		while (angle <= 6.28)
		{
			my_mlx_pixel_put(&env->data, (x + cos(angle) * i),
				(y + sin(angle) * i), 0x00000000);
			angle += 0.01;
		}
		i += 1;
	}
	ft_create_maprays(env, x, y);
}

void	ft_print_map(t_env *env, t_conf *conf, int color, int p)
{
	float	x;
	float	y;
	int		tmp_x;
	float	abs;
	float	ord;

	x = conf->x * conf->ratio_x;
	y = conf->y * conf->ratio_y;
	abs = x + conf->ratio_x;
	ord = y + conf->ratio_y;
	if (p == 1)
		ft_create_player(env, (conf->p.x * conf->ratio_x),
			(conf->p.y * conf->ratio_y));
	while (y < ord && y < conf->screen_height)
	{
		tmp_x = x;
		while (tmp_x < abs && tmp_x < conf->screen_width)
			my_mlx_pixel_put(&env->data, tmp_x++, y, color);
		y++;
	}
}

void	ft_minimap(t_conf *conf, t_env *env)
{
	conf->y = 0;
	while (conf->y < conf->y_max && conf->y < conf->screen_height)
	{
		conf->x = 0;
		while (conf->x < conf->x_max && conf->x < conf->screen_height)
		{
			if (conf->m.map[conf->y][conf->x] == '1')
				ft_print_map(env, conf, put_right_color('1'), 0);
			if (conf->m.map[conf->y][conf->x] == '0')
				ft_print_map(env, conf, put_right_color('0'), 0);
			if (conf->m.map[conf->y][conf->x] == '2')
				ft_print_map(env, conf, put_right_color('2'), 0);
			conf->x++;
		}
		conf->y++;
	}
	ft_print_map(env, conf, put_right_color('1'), 1);
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->data.img, 0, 0);
	mlx_destroy_image(env->mlx_ptr, env->data.img);
}

int		create_game(t_env *env)
{
	env->data.img = mlx_new_image(env->mlx_ptr, env->conf.screen_width,
					env->conf.screen_height);
	env->data.addr = mlx_get_data_addr(env->data.img, &env->data.bits_per_pixel,
					&env->data.line_length, &env->data.endian);
	ft_minimap(&env->conf, env);
	ft_keyhook(env);
	player_movement(&env->conf, env);
	return (1);
}
