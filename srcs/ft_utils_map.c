/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barodrig <barodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 12:46:49 by barodrig          #+#    #+#             */
/*   Updated: 2021/03/01 22:25:48 by barodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		is_map_1st_line(char *line)
{
	int	i;

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

int		count_space(char *buf, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (buf[i] != '\0')
	{
		if (buf[i] == c)
			count++;
		i++;
	}
	return (count);
}

char	*remove_space(char *buf, char c)
{
	int		i;
	int		j;
	char	*new;
	int		newlen;
	int		oldlen;

	i = 0;
	j = 0;
	oldlen = ft_strlen(buf);
	newlen = oldlen - (count_space(buf, c));
	new = (char *)malloc(sizeof(char) * (newlen + 1));
	if (!new)
		return (NULL);
	while (i < oldlen)
	{
		if (buf[i] != c)
		{
			new[j] = buf[i];
			j++;
		}
		i++;
	}
	new[j] = '\0';
	return (new);
}
