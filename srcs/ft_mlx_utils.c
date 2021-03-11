/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barodrig <barodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 11:05:10 by barodrig          #+#    #+#             */
/*   Updated: 2021/03/11 14:15:07 by barodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int		put_right_color(char c)
{
	if (c == '0')
		return (0x00FCFAFD);
	if (c == '1' || c == ' ')
		return (0x00E6220E);
	if (c == '2')
		return (0x001A1BFF);
}

/*void	ft_free_tex(t_env *env, t_tex *tex)
{
	if (tex)
	{
		mlx_destroy_image(env->mlx_ptr, tex->tex_ptr);
		free(tex);
		tex = NULL;
	}
}*/

void	ft_free_img(t_env *env, t_data *data)
{
	if (data)
	{
		mlx_destroy_image(env->mlx_ptr, env->data.img_ptr);
		free(env->data);
		data = NULL;
	}
}
