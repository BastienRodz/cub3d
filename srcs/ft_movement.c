/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barodrig <barodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 11:34:11 by barodrig          #+#    #+#             */
/*   Updated: 2021/03/11 14:16:05 by barodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	is_collision(t_conf *conf)
{
	int		y;
	int		x;
	int		y_ord;
	int		x_abs;

	x = (int)floorf(conf->p.x);
	y = (int)floorf(conf->p.y);
	y_ord = (int)floorf(conf->p.y + conf->p.y / conf->ratio_y);
	x_abs = (int)floorf(conf->p.x + conf->p.x / conf->ratio_x);
	printf("y_ord = %f\nx_abs = %f\n", conf->p.y, conf->p.x);
	if ((is_in_set(conf->m.map[y][x], "12")
		|| is_in_set(conf->m.map[y_ord][x], "12")) && conf->p.up == 1)
		conf->p.y += DIST;
	if ((is_in_set(conf->m.map[y][x], "12")
		|| is_in_set(conf->m.map[y_ord][x], "12")) && conf->p.down == 1)
		conf->p.y -= DIST;
	if ((is_in_set(conf->m.map[y][x], "12")
		|| is_in_set(conf->m.map[y][x_abs], "12")) && conf->p.left == 1)
		conf->p.x += DIST;
	if ((is_in_set(conf->m.map[y][x], "12")
		|| is_in_set(conf->m.map[y][x_abs], "12")) && conf->p.right == 1)
		conf->p.x -= DIST;
}

void	player_movement(t_conf *conf)
{
	ft_free_img(env, env->data);
	if (conf->p.up == 1)
		conf->p.y -= DIST;
	if (conf->p.down == -1)
		conf->p.y += DIST;
	if (conf->p.left == 1)
		conf->p.x -= DIST;
	if (conf->p.right == 1)
		conf->p.x += DIST;
	is_collision(conf);
}
