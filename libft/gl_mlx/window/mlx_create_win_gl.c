/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_create_win_gl.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 16:25:46 by glions            #+#    #+#             */
/*   Updated: 2024/04/22 09:23:45 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gl_mlx.h"

t_mlx_window_gl	*mlx_create_win_gl(t_mlx_gl *mlx, int width, int height,
		char *title)
{
	t_mlx_window_gl	*new;

	if (!mlx)
		return (NULL);
	new = malloc(sizeof(t_mlx_window_gl));
	if (!new)
		return (NULL);
	new->ptr = mlx_new_window(mlx->ptr, width, height, title);
	if (!new->ptr)
		return (free(new), NULL);
	new->bckgd = mlx_create_img_gl(mlx, width, height, "Background");
	if (!new->bckgd)
		return (mlx_free_win_gl(mlx, new), NULL);
	new->width = width;
	new->height = height;
	new->mlx_ptr = mlx->ptr;
	return (new);
}
