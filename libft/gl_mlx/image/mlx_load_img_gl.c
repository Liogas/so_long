/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_load_img_gl.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 16:38:35 by glions            #+#    #+#             */
/*   Updated: 2024/05/13 14:45:34 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gl_mlx.h"

t_mlx_image_gl	*mlx_load_img_gl(t_mlx_gl *mlx, char *path, char *name)
{
	t_mlx_image_gl	*new;

	if (!mlx || !path)
		return (NULL);
	if (!verif_extension(path, ".xpm"))
		return (NULL);
	new = malloc(sizeof(t_mlx_image_gl));
	if (!new)
		return (NULL);
	new->ptr = mlx_xpm_file_to_image(mlx->ptr, path, &new->width, &new->height);
	if (!new->ptr)
		return (free(new), NULL);
	new->sprites = NULL;
	new->name = name;
	new->mlx_ptr = mlx->ptr;
	new->addr = mlx_get_data_addr(new->ptr, &new->bpp, &new->line_len,
			&new->endian);
	if (!new->addr)
		return (mlx_free_img_gl(mlx, new), NULL);
	return (new);
}
