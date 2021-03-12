/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barodrig <barodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 11:22:58 by barodrig          #+#    #+#             */
/*   Updated: 2021/03/12 16:23:40 by barodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	win_close(t_env *env)
{
	mlx_destroy_window(env->mlx_ptr, env->win_ptr);
	exit(0);
}

int		key_press(int keycode, t_env *env)
{
	if (keycode == UP_ARROW || keycode == W)
		env->conf.p.up = 1;
	if (keycode == DOWN_ARROW || keycode == S)
		env->conf.p.down = 1;
	if (keycode == LEFT_ARROW)
		env->conf.p.dir = -1;
	if (keycode == RIGHT_ARROW)
		env->conf.p.dir = 1;
	if (keycode == A)
		env->conf.p.left = 1;
	if (keycode == D)
		env->conf.p.right = 1;
	if (keycode == ESC)
		win_close(env);
	return (1);
}

int	key_release(int keycode, t_env *env)
{
	if (keycode == UP_ARROW || keycode == W)
		env->conf.p.up = 0;
	if (keycode == DOWN_ARROW || keycode == S)
		env->conf.p.down = 0;
	if (keycode == LEFT_ARROW)
		env->conf.p.dir = 0;
	if (keycode == RIGHT_ARROW)
		env->conf.p.dir = 0;
	if (keycode == A)
		env->conf.p.left = 0;
	if (keycode == D)
		env->conf.p.right = 0;
	return (1);
}

int	ft_keyhook(t_env *env)
{
	mlx_hook(env->win_ptr, 2, 1L << 0, key_press, env);
	mlx_hook(env->win_ptr, 3, 1L << 1, key_release, env);
	return (1);
}
