/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barodrig <barodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 15:41:21 by barodrig          #+#    #+#             */
/*   Updated: 2021/02/15 15:50:10 by barodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_pf	ft_init_struct(void);
{
	t_pf	struct;

	R_y = 0;
	R_x = 0;

	NO_path = NULL;
	SO_path = NULL;
	WE_path = NULL;
	EA_path = NULL;

	S_path = NULL;
	F_color = {0,0,0};
	C_color = {0,0,0};

	char*	map;
}
