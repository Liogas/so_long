/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_create_img_gl.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 22:25:21 by glions            #+#    #+#             */
/*   Updated: 2024/04/23 14:18:23 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gl_mlx.h"

t_mlx_image_gl	*mlx_create_img_gl(t_mlx_gl *mlx, int width, int height,
		char *name)
{
	t_mlx_image_gl	*new;

	if (!mlx)
		return (NULL);
	new = malloc(sizeof(t_mlx_image_gl));
	if (!new)
		return (NULL);
	new->ptr = mlx_new_image(mlx->ptr, width, height);
	if (!new->ptr)
		return (free(new), NULL);
	new->width = width;
	new->height = height;
	new->name = name;
	new->mlx_ptr = mlx->ptr;
	new->sprites = NULL;
	new->addr = mlx_get_data_addr(new->ptr, &new->bpp, &new->line_len,
			&new->endian);
	if (!new->addr)
		return (mlx_free_img_gl(mlx, new), NULL);
	return (new);
}
