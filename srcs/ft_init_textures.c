/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barodrig <barodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 16:40:27 by barodrig          #+#    #+#             */
/*   Updated: 2021/03/05 10:49:21 by barodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_tex	*ft_new_tex(t_env *env, char *file, char *type)
{
	t_tex *tex;

	if (!(tex = malloc(sizeof(t_tex))))
		return (NULL);
	if (!(tex->tex_ptr = mlx_xpm_file_to_image(env->mlx_ptr, file,
		&tex->width, &tex->height)))
	{
		free(tex);
		return (NULL);
	}
	if (!(tex->tex_data = (int *)mlx_get_data_addr(tex->tex_ptr, &tex->bpp,
		&tex->size_line, &tex->endian)))
	{
		free(tex->tex_ptr);
		free(tex);
		return (NULL);
	}
	tex->type = type;
	return (tex);
}

void	init_tex_wall_sprite(t_env *env)
{
	if ((env->tex_n = ft_new_tex(env, env->conf.NO_path, "NO")) == NULL)
		env->error = -1;
	if ((env->tex_s = ft_new_tex(env, env->conf.SO_path, "SO")) == NULL)
		env->error = -2;
	if ((env->tex_w = ft_new_tex(env, env->conf.WE_path, "WE")) == NULL)
		env->error = -3;
	if ((env->tex_e = ft_new_tex(env, env->conf.EA_path, "EA")) == NULL)
		env->error = -4;
	if ((env->tex_sprite = ft_new_tex(env, env->conf.S_path, "sprite")) == NULL)
		env->error = -5;
}

int		init_tex(t_env *env)
{
	env->error = 0;
	init_tex_wall_sprite(env);
	if (env->error < 0)
	{
		printf("ERROR IN INIT TEXTURES\n");
		return (-1);
	}
	return (1);
}
