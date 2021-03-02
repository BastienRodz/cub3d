/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barodrig <barodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 18:17:44 by barodrig          #+#    #+#             */
/*   Updated: 2021/03/02 23:27:59 by barodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		is_in_set(char c, char *set)
{
	int		i;

	i = 0;
	while (set[i])
		if (c == set[i++])
			return (1);
	return (0);
}

int		is_map_1st_line(char *line)
{
	int	i;

	if (!line)
		return (0);
	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '1' && line[i] != '	')
			return (0);
		i++;
	}
	if (ft_strchr(line, '1'))
		return (1);
	return (0);
}

int		check_UDRL(t_conf *conf, int y, int x)
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
			if (conf->m.map[y][x] == '0')
				if (!check_UDRL(conf, y, x))
					return (0);
			x++;
		}
		y++;
	}
	return (1);
}

/*void	tmp_print_check(t_conf *conf)
{
	int	i;

	i = 0;
	printf("[MAP CHECK]\n\n");
	while (conf->m.map[i])
		printf("%s\n", conf->m.map[i++]);
	printf("\n");
	printf("[CONFIG CHECK]\n\n");
	printf("RESOLUTION = %d %d\n", conf->screen_width, conf->screen_height);
	printf("NO TEXTURE = %s\n", conf->NO_path);
	printf("SO TEXTURE = %s\n", conf->SO_path);
	printf("WE TEXTURE = %s\n", conf->WE_path);
	printf("EA TEXTURE = %s\n", conf->EA_path);
	printf("S TEXTURE = %s\n\n", conf->S_path);
	//printf("F COLOR = %d\n\n", conf->floor);
	//printf("C COLOR = %d\n\n", conf->ceil);
	printf("PLAYER CHECK\n\n");
	printf("POSITION = %c\n", conf->p.orient);
	printf("x = %d\n", conf->p.x);
	printf("y = %d\n", conf->p.y);
}
*/
