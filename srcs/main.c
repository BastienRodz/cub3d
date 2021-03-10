/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barodrig <barodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 13:57:49 by barodrig          #+#    #+#             */
/*   Updated: 2021/03/10 15:49:00 by barodrig         ###   ########.fr       */
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
	tmp_print_check(conf);
	return (1);
}

void 	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int		put_right_color(char c)
{
	if (c == '0' || c == 'N')
		return (0x00FCFAFD);
	if (c == '1' || c == ' ')
		return (0x00E6220E);
	if (c == '2')
		return (0x001A1BFF);
}

void	init_env(t_conf *conf, t_env *env)
{
	int x;
	int y;
	int pixel_x;
	int pixel_y;

	pixel_x = 0;
	pixel_y = 0;
	x = 0;
	y = 0;
	env->mlx_ptr = mlx_init();
	env->win_ptr = mlx_new_window(env->mlx_ptr, conf->screen_width, conf->screen_height, "Cub3D");
	env->data.img = mlx_new_image(env->mlx_ptr, 1920, 1080);
	env->data.addr = mlx_get_data_addr(env->data.img, &env->data.bits_per_pixel, &env->data.line_length,
                                 &env->data.endian);
	while (conf->m.map[y][x])
	{
		x = 0;
		while (conf->m.map[y][x])
		{
			while (pixel_x < 100 && pixel_x + 100 < conf->screen_width)
			{
				while (pixel_y < 100 && pixel_y + 100 < conf->screen_height)
					my_mlx_pixel_put(&env->data, x, y, put_right_color(conf->m.map[y][x]));
				pixel_x++;
			}
		}
		y++;
	}
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->data.img, 0, 0);
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
