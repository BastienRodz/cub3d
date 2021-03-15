/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barodrig <barodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 11:34:11 by barodrig          #+#    #+#             */
/*   Updated: 2021/03/15 15:52:27 by barodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_is_collision(t_conf *conf)
{
	int		y;
	int		x;

	x = (int)floorf(conf->p.x);
	y = (int)floorf(conf->p.y);
	if (is_in_set(conf->m.map[y][x], "12") && (conf->p.walkdir == 1
		|| conf->p.walkdir == -1))
	{
		conf->p.x -= cos(conf->p.angle) * conf->p.movestep;
		conf->p.y -= sin(conf->p.angle) * conf->p.movestep;
	}
	if (is_in_set(conf->m.map[y][x], "12") && conf->p.sidewalk == 1)
	{
		conf->p.x -= cos(conf->p.angle +
			(90 * (3.1415 / 180))) * conf->p.movespeed;
		conf->p.y -= sin(conf->p.angle +
			(90 * (3.1415 / 180))) * conf->p.movespeed;
	}
	if (is_in_set(conf->m.map[y][x], "12") && conf->p.sidewalk == -1)
	{
		conf->p.x -= cos(conf->p.angle -
			(90 * (3.1415 / 180))) * conf->p.movespeed;
		conf->p.y -= sin(conf->p.angle -
			(90 * (3.1415 / 180))) * conf->p.movespeed;
	}
}

void	player_movement(t_conf *conf, t_env *env)
{
	conf->p.movestep = conf->p.walkdir * conf->p.movespeed;
	if (conf->p.walkdir == 1 || conf->p.walkdir == -1)
	{
		conf->p.x += cos(conf->p.angle) * conf->p.movestep;
		conf->p.y += sin(conf->p.angle) * conf->p.movestep;
	}
	if (conf->p.sidewalk == 1)
	{
		conf->p.x += cos(conf->p.angle +
			(90 * (3.1415 / 180))) * conf->p.movespeed;
		conf->p.y += sin(conf->p.angle +
			(90 * (3.1415 / 180))) * conf->p.movespeed;
	}
	if (conf->p.sidewalk == -1)
	{
		conf->p.x += cos(conf->p.angle -
			(90 * (3.1415 / 180))) * conf->p.movespeed;
		conf->p.y += sin(conf->p.angle -
			(90 * (3.1415 / 180))) * conf->p.movespeed;
	}
	ft_is_collision(conf);
}
