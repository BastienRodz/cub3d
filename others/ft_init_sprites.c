/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_sprites.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barodrig <barodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 16:45:45 by barodrig          #+#    #+#             */
/*   Updated: 2021/03/04 19:09:51 by barodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_sprite_tex(t_env *env, int x, int y, int i)
{
	env->sprite_tab[i].pos_x = x + 0.5;
	env->sprite_tab[i].pos_y = y + 0.5;
	if (env->map[y][x] == '2')
		env->sprite_tab[i].tex = env->tex_sprite;
	if (env->map[y][x] == '3')
		env->sprite_tab[i].tex = env->tex_sprite1;
	//if (env->map[y][x] == 'D')
	//	env->sprite_tab[i].tex = env->tex_door;
	//if (env->map[y][x] == 'B')
	//	env->sprite_tab[i].tex = env->tex_bonus;
	//if (env->map[y][x] == 'A')
	//	env->sprite_tab[i].tex = env->tex_ammo;
	//if (env->map[y][x] == 'O')
	//	get_ennemy_sprite(env, i);
	//if (env->map[y][x] == 'T')
	//	env->sprite_tab[i].tex = env->tex_treasure;
	env->sprite_tab[i].tex->sprite_x = x;
	env->sprite_tab[i].tex->sprite_y = y;
}

int		ft_place_sprite(t_env *env)
{
	int x;
	int y;
	int i;

	i = 0;
	y = 0;
	while (y < env->map_height)
	{
		x = 0;
		while (env->map[y][x] && i < env->sprite_count)
		{
			if (ft_strchr("23DBAOT", env->map[y][x]))
			{
				get_sprite_tex(env, x, y, i);
				i++;
			}
			x++;
		}
		y++;
	}
	return (1);
}

int		init_sprite(t_env *env)
{
	int	i;

	i = 0;
	if (!(env->sprite_tab = malloc(sizeof(t_sprite) * (env->sprite_count + 1))))
		return (-1);
	if (!(env->ray.sp_order = malloc(sizeof(int) * env->sprite_count)))
		return (-1);
	if (!(env->ray.sp_distance = malloc(sizeof(double) * env->sprite_count)))
		return (-1);
	ft_place_sprite(env);
	ft_order_sprite(env);
	if (env->sprite_tab)
	{
		free(env->sprite_tab);
	}
	if (env->ray.sp_order)
	{
		free(env->ray.sp_order);
	}
	if (env->ray.sp_distance)
	{
		free(env->ray.sp_distance);
	}
	return (1);
}
