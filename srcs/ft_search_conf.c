/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_conf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barodrig <barodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 16:02:03 by barodrig          #+#    #+#             */
/*   Updated: 2021/02/27 16:18:04 by barodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			search_screen_conf(t_conf *conf, char *buf, int i)
{
	while ((buf[i] < '0' || buf[i] > '9' && !ft_strchr("+-", buf[i]))
		i++;
	conf->screen_width = ft_atoi(buf + i);
	while ((buf[i] >= '0' && buf[i] <= '9') || ft_strchr("+-", buf[i]) && buf[i] != '\0')
		i++;
	conf->sceen_height = ft_atoi(buf + i);
	while ((ft_strchr("\t\v\r\f ", buf[i]) || (buf[i] >= '0' && buf[i] <= '9')\
				&& buf[i] != '\0'))
		i++;
	while (buf[i !=])

}

int			search_conf(t_conf *conf, char *buf)
{
	if (buf[0] == '\n' || buf[0] == '\0')
		return (1);
	if (buf[0] == 'R')
		if (search_screen_conf(conf, buf, 0) != 1)
			return (-1);
	if (ft_strchr("NSWES", buf[0]))
		if (search_textures_path(conf, buf) != 1)
			return (-1);
	if (ft_strchr("FC", buf[0])
		if (search_FC_textures(conf, buf) != 1)
			return (-1);
	if (buf[0] >= '0' && buf[0] <= '9')
		if (stock_map(conf, buf) != 1)
			{
				write(1, "MAP ERROR\n", 10);
				return (-1);
			}
	if ((buf[0] < '0' || buf[0] > '9') && !ft_strchr("RNSWESFC", buf[0]))
	{
		write(1, "ERROR WRONG ARG IN .CUB FILE\n", 29);
		return (-1);
	}
	return (1);
}
