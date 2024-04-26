/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init_gl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 12:32:01 by glions            #+#    #+#             */
/*   Updated: 2024/04/26 12:41:06 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gl_mlx.h"

t_mlx_gl	*mlx_init_with_window_gl(int width_window, int height_window,
		char *title_window)
{
	t_mlx_gl	*new;

	new = malloc(sizeof(t_mlx_gl));
	if (!new)
		return (NULL);
	new->ptr = mlx_init();
	if (!new->ptr)
		return (free(new), NULL);
	new->images = NULL;
	new->objects = NULL;
	new->cameras = NULL;
	new->window = mlx_create_win_gl(new, width_window, height_window,
			title_window);
	if (!new->window)
		return (mlx_free_gl(new), NULL);
	return (new);
}

t_mlx_gl	*mlx_init_gl(void)
{
	t_mlx_gl	*new;

	new = malloc(sizeof(t_mlx_gl));
	if (!new)
		return (NULL);
	new->ptr = mlx_init();
	if (!new->ptr)
		return (free(new), NULL);
	new->images = NULL;
	new->cameras = NULL;
	new->objects = NULL;
	new->window = NULL;
	return (new);
}
