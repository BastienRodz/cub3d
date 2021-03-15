/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ray.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barodrig <barodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 17:05:24 by barodrig          #+#    #+#             */
/*   Updated: 2021/03/15 17:24:13 by barodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_ray_hit_y(t_env *env, double x, double y)
{
	float	hit_y;
	float	hit_x;
	float	hitb_y;
	float	hitb_x;

	hit_y = (env->conf.p.y / ratio_y) * ratio_y;
	hit_x = (env->conf.p.x + ((env->conf.p.y - hit_y) / tan(env->conf.p.angle)));
	hitb_y = (hit_y / ratio_y) * ratio_y;
	env->conf.ray.xstep = hit_x + ((hit_y - hitb_y) / tan(env->conf.p.angle));
}

void	ft_ray_hit_x(t_env *env, double x, double y)
{
	()
}

void	ft_create_maprays(t_env *env, double x, double y)
{
	float	angle;
	int		i;
	float	fov;

	fov = -0.785;
	env->conf.p.angle += env->conf.p.dir * env->conf.p.rotspeed;

	while (fov <= 0.785)
	{
		i = env->conf.p.radius;
		while (!is_in_set(env->conf.m.map[(int)floorf((y + sin(env->conf.p.angle
			- fov) * i) / env->conf.ratio_y)][(int)floorf((x +
				cos(env->conf.p.angle - fov) * i) / env->conf.ratio_x)], "12"))
		{
			my_mlx_pixel_put(&env->data, (x + cos(env->conf.p.angle - fov) * i),
					(y + sin(env->conf.p.angle - fov) * i), 0x0018AD3E);
			i++;
		}
		fov += 0.001;
	}
}
