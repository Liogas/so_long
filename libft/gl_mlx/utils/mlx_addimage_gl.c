/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_addimage_gl.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 09:36:32 by glions            #+#    #+#             */
/*   Updated: 2024/05/13 15:07:43 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gl_mlx.h"

static int	already_in(t_list_gl *list, t_mlx_image_gl *image)
{
	t_list_gl	*tmp;

	if (!list || !image)
		return (0);
	tmp = list;
	while (tmp)
	{
		if (((t_mlx_image_gl *)tmp->content)->name == image->name)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	mlx_addimage_gl(t_mlx_gl *mlx, t_mlx_image_gl *image)
{
	if (!mlx || !image)
		return (0);
	if (already_in(mlx->images, image))
		return (mlx_free_img_gl(mlx, image), 1);
	if (!addback_list_gl(&mlx->images, new_element_gl(image)))
		return (mlx_free_img_gl(mlx, image), 0);
	return (1);
}
