/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barodrig <barodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 20:00:33 by barodrig          #+#    #+#             */
/*   Updated: 2021/03/03 15:23:07 by barodrig         ###   ########.fr       */
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
