/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 16:15:48 by barodrig          #+#    #+#             */
/*   Updated: 2021/01/14 18:30:04 by barodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str;

	if (s1 && s2)
	{
		if (!(str = malloc(sizeof(char *) * (ft_strlen((char *)s1)
			+ ft_strlen((char *)s2 + 1)))))
			return (NULL);
		i = 0;
		j = 0;
		while (i < (ft_strlen((char *)s1) + ft_strlen((char *)s2)))
		{
			while (s1[i])
			{
				str[i] = s1[i];
				i++;
			}
			while (s2[j])
				str[i++] = s2[j++];
		}
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}
