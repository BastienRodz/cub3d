/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barodrig <barodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 20:00:33 by barodrig          #+#    #+#             */
/*   Updated: 2021/03/11 11:11:41 by barodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_get_max_y_max_x(t_conf *conf, int x, int y)
{
	while (conf->m.map[y])
		conf->y_max = y++;
	conf->y_max++;
	y = 0;
	conf->x_max = 0;
	while (conf->m.map[y])
	{
		if (conf->x_max < ft_strlen(conf->m.map[y]))
		{
			conf->x_max = ft_strlen(conf->m.map[y]);
		}
		y++;
	}
	conf->ratio_x = (float)conf->screen_width / (float)conf->x_max;
	conf->ratio_y = (float)conf->screen_height / (float)conf->y_max;
}

char	*space_to_join(t_conf *conf, char *map_y, int len)
{
	char	*space;
	int		i;
	int		size;

	i = 0;
	size = conf->x_max - len;
	space = (char *)malloc(sizeof(char) * size + 1);
	if (!space)
		return (NULL);
	while (i < size)
		space[i++] = ' ';
	space[i] = '\0';
	return (space);
}

void	adapt_to_greatest(t_conf *conf)
{
	int		y;
	int		len;
	char	*space;

	y = 0;
	while (conf->m.map[y])
	{
		len = (int)ft_strlen(conf->m.map[y]);
		if (len < conf->x_max)
		{
			space = space_to_join(conf, conf->m.map[y], len);
			conf->m.map[y] = ft_strjoin(conf->m.map[y], space, 2);
		}
		y++;
	}
}

void	get_map(char *line, t_conf *conf)
{
	char	*tmp;

	tmp = ft_strjoin(line, "*", 1);
	if (conf->m.line == NULL)
		conf->m.line = ft_strdup(tmp);
	else
		conf->m.line = ft_strjoin(conf->m.line, tmp, 1);
	free(tmp);
}

int		map_gnl(int fd, char *line, t_conf *conf)
{
	int	ret;
	int	end_map;

	end_map = 0;
	if (is_map_1st_line(line))
		get_map(line, conf);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (!*line)
			end_map = 1;
		if (*line && end_map == 1)
		{
			printf("NEW LINE AFTER_MAP\n");
			return (-1);
		}
		get_map(line, conf);
	}
	if (*line && !is_map_1st_line(line))
	{
		printf("LAST LINE IN MAP IS NOT CLOSED\n");
		return (-1);
	}
	get_map(line, conf);
	return (1);
}
