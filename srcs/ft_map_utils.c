/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barodrig <barodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 11:11:23 by barodrig          #+#    #+#             */
/*   Updated: 2021/03/11 11:14:13 by barodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_get_player(t_conf *conf, int x, int y)
{
	conf->p.pos_count++;
	conf->p.x = x;
	conf->p.y = y;
	conf->p.orient = conf->m.map[y][x];
	conf->m.map[y][x] = '0';
}

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

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '1')
			return (0);
		i++;
	}
	if (ft_strchr(line, '1'))
		return (1);
	return (0);
}

void	tmp_print_check(t_conf *conf)
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
	printf("F COLOR R = %d\n\n", conf->floor.r);
	printf("F COLOR G = %d\n\n", conf->floor.g);
	printf("F COLOR B = %d\n\n", conf->floor.b);
	printf("C COLOR R = %d\n\n", conf->ceil.r);
	printf("C COLOR R = %d\n\n", conf->ceil.g);
	printf("C COLOR R = %d\n\n", conf->ceil.b);
	printf("PLAYER CHECK\n\n");
	printf("POSITION = %c\n", conf->p.orient);
	printf("x = %f\n", conf->p.x);
	printf("y = %f\n", conf->p.y);
}
