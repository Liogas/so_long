/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_free_img_gl.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 16:53:28 by glions            #+#    #+#             */
/*   Updated: 2024/05/13 14:45:21 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gl_mlx.h"

static void	mlx_free_sprites_gl(t_mlx_image_gl *img)
{
	t_list_gl	*tmp;

	while (img->sprites)
	{
		tmp = img->sprites->next;
		mlx_free_sprite_gl((t_mlx_sprite_gl *)img->sprites->content);
		free(img->sprites);
		img->sprites = tmp;
	}
}

void	mlx_free_img_gl(t_mlx_gl *mlx, t_mlx_image_gl *img)
{
	if (!mlx)
		return ;
	if (img)
	{
		if (img->sprites)
			mlx_free_sprites_gl(img);
		if (img->ptr)
			mlx_destroy_image(mlx->ptr, img->ptr);
		free(img);
	}
}
