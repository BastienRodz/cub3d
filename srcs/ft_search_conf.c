/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_conf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barodrig <barodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 16:02:03 by barodrig          #+#    #+#             */
/*   Updated: 2021/03/01 23:20:02 by barodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			search_FC_b_textures(t_conf *conf, char *buf, int i)
{
	while (buf[i] >= '0' && buf[i] <= '9')
		i++;
	while ((buf[i] < '0' || buf[i] > '9') && buf[i] != '-')
		i++;
	if (ft_atoi(buf + i) < 0 || ft_atoi(buf + i) > 255)
		return (-1);
	if (buf[0] == 'F')
		conf->floor.b = ft_atoi(buf + i);
	else
		conf->ceil.b = ft_atoi(buf + i);
	return (1);
}

int			search_FC_textures(t_conf *conf, char *buf)
{
	int i;

	i = 0;
	while ((buf[i] < '0' || buf[i] > '9') && buf[i] != '-')
		i++;
	if (ft_atoi(buf + i) < 0 || ft_atoi(buf + i) > 255)
		return (-1);
	if (buf[0] == 'F')
		conf->floor.r = ft_atoi(buf + i);
	else
		conf->ceil.r = ft_atoi(buf + i);
	while (buf[i] >= '0' && buf[i] <= '9')
		i++;
	while ((buf[i] < '0' || buf[i] > '9') && buf[i] != '-')
		i++;
	if (ft_atoi(buf + i) < 0 || ft_atoi(buf + i) > 255)
		return (-1);
	if (buf[0] == 'F')
		conf->floor.g = ft_atoi(buf + i);
	else
		conf->ceil.g = ft_atoi(buf + i);
	if (search_FC_b_textures(conf, buf, i) != 1)
		return (-1);
	return (1);
}

int			search_screen_conf(t_conf *conf, char *buf, int i)
{
	while ((buf[i] < '0' || buf[i] > '9') && !ft_strchr("+-", buf[i]))
		i++;
	conf->screen_width = ft_atoi(buf + i);
	while (((buf[i] >= '0' && buf[i] <= '9') || ft_strchr("+-", buf[i])) && buf[i] != '\0')
		i++;
	conf->screen_height = ft_atoi(buf + i);
	while ((ft_strchr("\t\v\r\f ", buf[i]) || (buf[i] >= '0' && buf[i] <= '9'))\
				&& buf[i] != '\0')
		i++;
	while (buf[i] != '\0')
	{
		if (ft_strchr("\t\v\r\f ", buf[i]) == 0)
			return (-1);
		i++;
	}
	if (conf->screen_height <= 0 || conf->screen_width <= 0)
	{
		write(1, "ERROR SEARCH SCREEN CONF \n", 26);
		return (-1);
	}
	if (conf->screen_height >= 1440)
		conf->screen_height = 1440;
	if (conf->screen_width >= 2560)
		conf->screen_width = 2560;
	return (1);
}

int			stock_map(int fd, t_conf *conf, char *buf)
{
	t_map	*map_tmp;
	int		ret;

	while ((ret = get_next_line(fd, &buf)) > 0)
	{
		if (!(map_tmp = ft_lstnewmap(remove_space(buf, ' '))))
			return (-1);
		printf("%s\n", buf);
		ft_lstadd_backmap(&(conf->map), map_tmp);
		free(buf);
	}
	return (1);
}

int			search_conf(t_conf *conf, char *buf)
{
	if (buf[0] == '\n' || buf[0] == '\0')
		return (1);
	if (buf[0] == 'R')
		if (search_screen_conf(conf, buf, 0) != 1)
		{
			write(1, "ERROR SEARCH SCREEN CONF \n", 26);
			return (-1);
		}
	if (ft_strchr("NSWE", buf[0]))
		if (search_textures_path(conf, buf) != 1)
		{
			write(1, "ERROR SEARCH TEXTURES PATH\n", 27);
			return (-1);
		}
	if (ft_strchr("FC", buf[0]))
		if (search_FC_textures(conf, buf) != 1)
		{
			write(1, "ERROR FC textures \n", 19);
			return (-1);
		}
	if ((buf[0] < '0' || buf[0] > '9') && !ft_strchr("RNSWESFC \t", buf[0]))
	{
		write(1, "ERROR WRONG ARG IN .CUB FILE\n", 29);
		return (-1);
	}
	return (1);
}
