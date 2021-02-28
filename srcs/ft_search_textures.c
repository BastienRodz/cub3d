/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_textures.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barodrig <barodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 13:32:51 by barodrig          #+#    #+#             */
/*   Updated: 2021/02/28 17:13:30 by barodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	search_textures_path_2(char *direction, int i, char *buf, t_conf *conf)
{
	if (!ft_strncmp("WE", direction, 2))
	{
		if (ft_strlen(conf->WE_path))
			return (-1);
		conf->WE_path = ft_strsub(buf, i, ft_strlen(buf) - i);
	}
	if (!ft_strncmp("EA", direction, 2))
	{
		if (ft_strlen(conf->EA_path))
			return (-1);
		conf->EA_path = ft_strsub(buf, i, ft_strlen(buf) - i);
	}
	if (!ft_strncmp("S ", direction, 2))
	{
		if (ft_strlen(conf->S_path))
			return (-1);
		conf->S_path = ft_strsub(buf, i, ft_strlen(buf) - i);
	}
	return (1);
}

int	search_textures_path(t_conf *conf, char *buf)
{
	char	*direction;
	int		i;

	if (ft_strlen(buf) < 1)
		return (-1);
	direction = ft_strsub(buf, 0, 2);
	i = 2;
	while (ft_strchr("\t\v\r\f ", buf[i]))
		i++;
	if (!ft_strncmp("NO", direction, 2))
	{
		if (ft_strlen(conf->NO_path))
			return (-1);
		conf->NO_path = ft_strsub(buf, i, ft_strlen(buf) - i);
	}
	if (!ft_strncmp("SO", direction, 2))
	{
		if (ft_strlen(conf->SO_path))
			return (-1);
		conf->SO_path = ft_strsub(buf, i, ft_strlen(buf) - i);
	}
	return (search_textures_path_2(direction, i, buf, conf));
}
