/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barodrig <barodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 16:30:25 by barodrig          #+#    #+#             */
/*   Updated: 2021/03/04 16:48:10 by barodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			from_rgb_to_hex(t_rgb color)
{
	int		output;

	output = 256 * 256 * color.r + 256 * color.g + color.b;
	return (output);
}

void		init_env_orientation(t_env *env)
{
	if (env->orientation == 'N')
	{
		env->ray.diry = -0.99;
		env->ray.planex = -0.80;
	}
	if (env->orientation == 'S')
	{
		env->ray.diry = 0.99;
		env->ray.planex = 0.80;
	}
	if (env->orientation == 'E')
	{
		env->ray.dirx = 0.99;
		env->ray.planey = -0.80;
	}
	if (env->orientation == 'W')
	{
		env->ray.dirx = -0.99;
		env->ray.planey = 0.80;
	}
}

void		init_env_2(t_env *env, t_conf conf)
{
	env->width = conf.screen_width;
	env->height = arg.screen_height;
	env->floor = from_rgb_to_hex(conf.floor);
	env->ceil = from_rgb_to_hex(conf.ceil);
	env->conf = conf;
	init_env_orientation(env);
	env->mlx_ptr = mlx_init();
	env->player_x += 0.5;
	env->player_y += 0.5;
	env->lives = 3;
	env->minimap = 1;
	env->target_divider = 1;
}

void		get_conf(t_env *env, t_conf conf, int y, int x)
{
	t_map	*tmp;

	tmp = conf.map;
	while (tmp)
	{
		x = 0;
		while (tmp->line[x] != '\0')
		{
			if (ft_strchr("NSWE", tmp->line[x]))
			{
				env->orientation = tmp->line[x];
				env->player_x = x++;
				env->player_y = y++;
			}
			if (ft_strchr("23DBAOT", tmp->line[x]))
				env->sprite_count++;
			if (tmp->line[x] == 'O')
				env->ennemy_count++;
			x++;
		}
		env->map_width = x;
		tmp = tmp->next;
		y++;
	}
	env->map_height = y - 1;
}

t_env		init_env(t_conf conf)
{
	t_env	env;
	int		i;

	i = 0;
	ft_bzero(&env, sizeof(t_env));
	ft_bzero(&env.ray, sizeof(t_ray));
	get_conf(&env, conf, 0, 0);
	env.ray.speed = 0.1;
	init_env_2(&env, conf);
	init_env_orientation(&env);
	init_tex(&env);
	while (conf.m.map[0][i])
		i++;
	env.map_height = i;
	if ((env.error = init_raybuffer(&env)) != 1)
	{
		printf("RAY BUFFER ISSUE\n");
		return (-1);
	}
	init_sprite(&env);
	return (env);
}