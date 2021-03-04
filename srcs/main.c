/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barodrig <barodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 13:57:49 by barodrig          #+#    #+#             */
/*   Updated: 2021/03/04 17:04:16 by barodrig         ###   ########.fr       */
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
	env = init_env(conf);
	if (ac == 3)
		env.save_flag = 1;
	//events(env);
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

void	tmp_print_check(t_conf *conf)
{
	int	i;

	i = 0;
	printf("[MAP CHECK]\n\n");
	while (conf->m.map[i])
		printf("%s\n", conf->m.map[i++]);
	printf("\n");
	printf("[CONFIG CHECK]\n\n");
	printf("RESOLUTION = %d %d\n", conf->screen_width, conf->screen_height);
	printf("NO TEXTURE = %s\n", conf->NO_path);
	printf("SO TEXTURE = %s\n", conf->SO_path);
	printf("WE TEXTURE = %s\n", conf->WE_path);
	printf("EA TEXTURE = %s\n", conf->EA_path);
	printf("S TEXTURE = %s\n\n", conf->S_path);
	printf("F COLOR R = %d\n\n", conf->floor.r);
	printf("F COLOR G = %d\n\n", conf->floor.g);
	printf("F COLOR B = %d\n\n", conf->floor.b);
	printf("C COLOR R = %d\n\n", conf->ceil.r);
	printf("C COLOR G = %d\n\n", conf->ceil.g);
	printf("C COLOR B = %d\n\n", conf->ceil.b);
	printf("PLAYER CHECK\n\n");
	printf("POSITION = %c\n", conf->p.orient);
	printf("x = %d\n", conf->p.x);
	printf("y = %d\n", conf->p.y);
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
