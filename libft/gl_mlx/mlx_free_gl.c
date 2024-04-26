/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_free_gl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 12:29:40 by glions            #+#    #+#             */
/*   Updated: 2024/04/26 12:54:54 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gl_mlx.h"

static void	mlx_free_imgs_gl(t_mlx_gl *mlx)
{
	t_list_gl	*tmp;

	while (mlx->images)
	{
		tmp = mlx->images->next;
		mlx_free_img_gl(mlx, (t_mlx_image_gl *)mlx->images->content);
		free(mlx->images);
		mlx->images = tmp;
	}
}

static void	mlx_free_objects_gl(t_mlx_gl *mlx)
{
	t_list_gl	*tmp;

	while (mlx->objects)
	{
		tmp = mlx->objects->next;
		mlx_free_object_gl((t_mlx_object_gl *)mlx->objects->content);
		free(mlx->objects);
		mlx->objects = tmp;
	}
}

static void	mlx_free_cameras_gl(t_mlx_gl *mlx)
{
	t_list_gl	*tmp;

	while (mlx->cameras)
	{
		tmp = mlx->cameras->next;
		mlx_camera_free_gl(mlx, (t_mlx_camera_gl *)mlx->cameras->content);
		free(mlx->cameras);
		mlx->cameras = tmp;
	}
}

void	mlx_free_gl(t_mlx_gl *mlx)
{
	if (mlx)
	{
		if (mlx->images)
			mlx_free_imgs_gl(mlx);
		if (mlx->objects)
			mlx_free_objects_gl(mlx);
		if (mlx->window)
			mlx_free_win_gl(mlx, mlx->window);
		if (mlx->cameras)
			mlx_free_cameras_gl(mlx);
		if (mlx->ptr)
			(mlx_destroy_display(mlx->ptr), free(mlx->ptr));
		free(mlx);
	}
}
