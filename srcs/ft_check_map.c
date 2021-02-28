/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barodrig <barodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 18:17:44 by barodrig          #+#    #+#             */
/*   Updated: 2021/02/28 18:54:20 by barodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		check_map_with_spaces(int i, t_map *map_tmp, t_map *map_before)
{
	t_map *map_after;

	map_tmp = map_tmp->next;
	map_after = map_tmp->next;
	while (map_tmp->next)
	{
		i = 0;
		while (map_tmp->line[i])
		{
			if (map_tmp->line[i] != ' ' && map_tmp->line[i] != '1' && i >= ft_strlen(map_before->line))
				return (-1);
			if (map_after)
				if (map_tmp->line[i] != ' ' && map_tmp->line[i] != '1' && i >= ft_strlen(map_after->line))
					return (-1);
			i++;
		}
		map_before = map_tmp;
		map_tmp = map_tmp->next;
		map_after = map_tmp->next;
	}
	return (1);
}

int		check_map_borders(t_map *map)
{
	int i;
	t_map *map_tmp;

	i = 0;
	map_tmp = map;
	if (check_map_with_spaces(0, map_tmp, map_tmp) != 1)
		return (-1);
	while (map_tmp->line[i])
	{
		if (map_tmp->line[i++] != '1')
			return (-1);
	}
	while (map_tmp->next)
	{
		if (map_tmp->line[0] != '1')
			return (-1);
		if (map_tmp->line[ft_strlen(map_tmp->line) -1] != '1')
			return (-1);
		map_tmp = map_tmp->next;
	}
	i = 0;
	while (map_tmp->line[i])
		if (map_tmp->line[i++] != '1')
			return (-1);
	return (1);
}

int		map_checker(t_map *map, int pos, int i)
{
	t_map	*map_tmp;

	map_tmp = map;
	while (map_tmp)
	{
		i = 0;
		while (map_tmp->line[i])
		{
			if (ft_strchr("012NSWE", map_tmp->line[i]) == 0)
			{
				printf("WRONG CHAR IN MAP\n");
				return (-1);
			}
			if (ft_strchr("NSWE", map_tmp->line[i]) != 0)
				pos++;
			if (pos > 1)
			{
				printf("TOO MANY STARTING POS IN MAP\n");
				return (-1);
			}
			i++;
		}
		map_tmp = map_tmp->next;
	}
	if (!pos)
	{
		printf("NO STARTING POS IN MAP\n");
		return (-1);
	}
	if (check_map_borders(map) != 1)
	{
		printf("ERROR MAP NOT CLOSED\n");
		return (-1);
	}
	return (1);
}
