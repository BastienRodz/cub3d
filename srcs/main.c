/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barodrig <barodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 13:57:49 by barodrig          #+#    #+#             */
/*   Updated: 2021/03/12 15:57:51 by barodrig         ###   ########.fr       */
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
	ft_get_max_y_max_x(conf, 0, 0);
	adapt_to_greatest(conf);
	//tmp_print_check(conf);
	return (1);
}

void	ft_init_ray_orient(t_env *env)
{
	if (env->conf.p.orient == 'N')
	{
		env->ray.diry = -0.99;
		env->ray.planex = -0.80;
	}
	if (env->conf.p.orient == 'S')
	{
		env->ray.diry = 0.99;
		env->ray.planex = 0.80;
	}
	if (env->conf.p.orient == 'E')
	{
		env->ray.dirx = 0.99;
		env->ray.planey = -0.80;
	}
	if (env->conf.p.orient == 'W')
	{
		env->ray.dirx = -0.99;
		env->ray.planey = 0.80;
	}
}

void	init_env(t_conf *conf, t_env *env)
{
	//env->ray.speed = 0.1;
	env->conf = *conf;
	//env->floor = get_color(conf->floor);
	//env->ceil = get_color(conf->ceil);
	env->mlx_ptr = mlx_init();
	//env->conf.p.x += 0.5;
	//env->conf.p.y += 0.5;
	//env->lives = 3;
	//env->minimap = 1;
	//ft_init_ray_orient(env);
	//init_raybuffer(env);
	env->win_ptr = mlx_new_window(env->mlx_ptr, conf->screen_width, conf->screen_height, "Cub3D");
	env->data.img = mlx_new_image(env->mlx_ptr, conf->screen_width, conf->screen_height);
	env->data.addr = mlx_get_data_addr(env->data.img, &env->data.bits_per_pixel, &env->data.line_length,
                                 &env->data.endian);
	mlx_loop_hook(env->mlx_ptr, create_game, env);
	mlx_loop(env->mlx_ptr);
}

int		game_launch(t_conf *conf, int fd, int ac, char *buf)
{
	t_env env;

	if (!ft_check_map(fd, conf, buf))
		return (-1);
	if (ac == 3)
		env.save_flag = 1;
	init_env(conf, &env);
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
