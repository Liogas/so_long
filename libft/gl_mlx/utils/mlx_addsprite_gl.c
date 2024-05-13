/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_addsprite_gl.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 10:08:06 by glions            #+#    #+#             */
/*   Updated: 2024/05/13 15:07:48 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gl_mlx.h"

static int	already_in(t_list_gl *list, t_mlx_sprite_gl *sprite)
{
	t_list_gl	*tmp;

	if (!list || !sprite)
		return (0);
	tmp = list;
	while (tmp)
	{
		if (((t_mlx_sprite_gl *)tmp->content)->name == sprite->name)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	mlx_addsprite_gl(t_mlx_gl *mlx, char *img_name, t_mlx_sprite_gl *sprite)
{
	t_mlx_image_gl	*img;

	if (!mlx || !img_name || !img_name[0] || !sprite)
		return (0);
	img = mlx_get_image_by_name_gl(mlx, img_name);
	if (!img)
		return (mlx_free_sprite_gl(sprite), 0);
	if (already_in(img->sprites, sprite))
		return (mlx_free_sprite_gl(sprite), 1);
	if (!addback_list_gl(&img->sprites, new_element_gl(sprite)))
		return (mlx_free_sprite_gl(sprite), 0);
	return (1);
}
