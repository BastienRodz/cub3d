/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barodrig <barodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 12:40:43 by barodrig          #+#    #+#             */
/*   Updated: 2021/02/28 14:55:33 by barodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_map		*ft_lstnewmap(void *content)
{
	t_map	*map;

	if (!(map = malloc(sizeof(t_map))))
		return (NULL);
	map->line = content;
	map->next = NULL;
	return (map);
}

t_map		*ft_lstlastmap(t_map *lst)
{
	t_map	*tmp;

	if (!lst)
		return (NULL);
	tmp = lst;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

void	ft_lstadd_backmap(t_map **alst, t_map *new)
{
	t_map	*tmp;

	tmp = *alst;
	if (*alst == NULL)
		*alst = new;
	else
		(ft_lstlastmap(*alst))->next = new;
}
