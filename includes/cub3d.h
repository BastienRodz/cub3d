/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barodrig <barodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 14:00:05 by barodrig          #+#    #+#             */
/*   Updated: 2021/02/16 11:22:14 by barodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>
# include <math.h>

typedef	struct	s_pf
{
	int	 	R_y;
	int	 	R_x;

	char*	NO_path;
	char*	SO_path;
	char*	WE_path;
	char*	EA_path;

	char*	S_path;
	int		F1;
	int		F2;
	int		F3;
	int		C1;
	int		C2;
	int		C3;

	char*	map;
}				t_pf;

int			ft_check_map_error(int fd);

#endif
