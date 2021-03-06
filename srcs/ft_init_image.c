/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barodrig <barodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 10:53:42 by barodrig          #+#    #+#             */
/*   Updated: 2021/03/05 10:54:04 by barodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_img		*ft_new_img(t_env *env, char *file)
{
	t_img	*img;

	if (!(img = malloc(sizeof(t_img))))
	{
		return (NULL);
	}
	if (!(img->img_ptr = mlx_xpm_file_to_image(env->mlx_ptr, file,
		&img->width, &img->height)))
	{
		free(img);
		return (NULL);
	}
	if (!(img->img_data = (int *)mlx_get_data_addr(img->img_ptr, &img->bpp,
		&img->size_line, &img->endian)))
	{
		free(img->img_ptr);
		free(img);
		return (NULL);
	}
	return (img);
}
