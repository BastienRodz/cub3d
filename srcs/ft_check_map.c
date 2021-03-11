/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barodrig <barodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 18:17:44 by barodrig          #+#    #+#             */
/*   Updated: 2021/03/11 11:14:01 by barodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		check_udrl(t_conf *conf, int y, int x)
{
	if (!is_in_set(conf->m.map[y - 1][x], "120NSWE"))
		return (0);
	if (!is_in_set(conf->m.map[y + 1][x], "120NSWE"))
		return (0);
	if (!is_in_set(conf->m.map[y][x + 1], "120NSWE"))
		return (0);
	if (!is_in_set(conf->m.map[y][x - 1], "120NSWE"))
		return (0);
	return (1);
}

int		ft_check_walls(t_conf *conf)
{
	int	x;
	int y;

	y = 0;
	while (conf->m.map[y])
	{
		x = 0;
		while (conf->m.map[y][x])
		{
			if (!is_in_set(conf->m.map[y][x], " 120NSEW"))
				return (0);
			if (conf->m.map[y][x] == 'N' || conf->m.map[y][x] == 'S' || \
			conf->m.map[y][x] == 'E' || conf->m.map[y][x] == 'W')
				ft_get_player(conf, x, y);
			if (is_in_set(conf->m.map[y][x], "02NSWE"))
				if (!check_udrl(conf, y, x))
					return (0);
			x++;
		}
		y++;
	}
	return (1);
}
