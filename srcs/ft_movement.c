/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barodrig <barodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 11:34:11 by barodrig          #+#    #+#             */
/*   Updated: 2021/03/12 16:23:58 by barodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	is_collision(t_conf *conf)
{
	int		y;
	int		x;

	x = (int)floorf(conf->p.x);
	y = (int)floorf(conf->p.y);
	if (is_in_set(conf->m.map[y][x], "12") && conf->p.up == 1)
		conf->p.y += DIST;
	if (is_in_set(conf->m.map[y][x], "12") && conf->p.down == 1)
		conf->p.y -= DIST;
	if (is_in_set(conf->m.map[y][x], "12") && conf->p.left == 1)
		conf->p.x += DIST;
	if (is_in_set(conf->m.map[y][x], "12") && conf->p.right == 1)
		conf->p.x -= DIST;
}

void	player_movement(t_conf *conf, t_env *env)
{
	if (conf->p.up == 1)
		conf->p.y -= DIST;
	if (conf->p.down == 1)
		conf->p.y += DIST;
	if (conf->p.left == 1)
		conf->p.x -= DIST;
	if (conf->p.right == 1)
		conf->p.x += DIST;
	is_collision(conf);
}
