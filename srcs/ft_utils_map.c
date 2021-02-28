/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barodrig <barodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 12:46:49 by barodrig          #+#    #+#             */
/*   Updated: 2021/02/28 13:29:02 by barodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		count_space(char *buf, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (buf[i])
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
	int		len_before;
	int		len_after;

	i = 0;
	j = 0;
	len_before = ft_strlen(buf);
	len_after = len_before - (count_space(buf, c));
	new = (char *)malloc(sizeof(char) * (len_after + 1));
	if (!new)
		return (NULL);
	while (i < len_before)
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
