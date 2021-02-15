/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barodrig <barodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 13:57:49 by barodrig          #+#    #+#             */
/*   Updated: 2021/02/15 16:06:12 by barodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cub3d(char *path, int save, t_pf config)
{
	printf("YOU REACHED CUB3D FUNCTION ! CONGRATS !\n");
}

int		main(int ac, char **av)
{
	t_pf config;

	if (ac < 2 || ac > 3)
	{
		write(1, "Error argc\n", 11);
		return (0);
	}
	else if(ac == 2 && !ft_check_map_error(av[1], NULL, config))
		cub3d(av[1], 0, config);
	else if (ac == 3 && !ft_check_map_error(av[1], av[2], config))
		cub3d(av[1], 1, config);
	return (1);
}
