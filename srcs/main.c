/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barodrig <barodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 13:57:49 by barodrig          #+#    #+#             */
/*   Updated: 2021/03/09 13:33:11 by barodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


int		ft_check_map(int fd, t_conf *conf, char *line)
{

	map_gnl(fd, line, conf);
	conf->m.map = ft_split(conf->m.line, '*');
	if (!ft_check_walls(conf))
		return (-1);
	if (conf->p.pos_count != 1)
		return (-1);
	return (1);
}

int		game_launch(t_conf *conf, int fd, int ac, char *buf)
{
	t_env env;
	if (!ft_check_map(fd, conf, buf))
		return (-1);
	tmp_print_check(conf);
	if (ac == 3)
		env.save_flag = 1;
	return (1);
}

int		check_arguments(int ac, char **av)
{
	int ret;

	ret = 0;
	if (ac > 3)
		ret = -1;
	if (ac < 2)
		ret = -1;
	if (ac == 3)
		if (ft_strncmp(av[2], "--save", 6) != 0)
			ret = -1;
	if (ac == 2)
		if (ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".cub", 4) != 0)
			ret = -1;
	if (ret == -1)
	{
		write(1, "ARGS ERROR", 10);
		return (-1);
	}
	return (1);
}

int		main(int ac, char **av)
{
	int		fd;
	int		ret;
	char	*buf;
	t_conf	conf;

	ft_bzero(&conf, sizeof(conf));
	ret = 0;
	buf = NULL;
	if (check_arguments(ac, av) != 1)
		return (0);
	fd = open(av[1], O_RDWR);
	while ((ret = get_next_line(fd, &buf)) > 0 && !is_map_1st_line(buf))
	{
		if (search_conf(&conf, buf) != 1)
			return (-1);
		free(buf);
	}
	if (ret == -1)
		return (-1);
	if (game_launch(&conf, fd, ac, buf) != 1)
		return (-1);
	write(1, "SUCCESS !\n", 10);
	return (0);
}
