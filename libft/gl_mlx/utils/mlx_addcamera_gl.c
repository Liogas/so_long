/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_addcamera_gl.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 12:24:57 by glions            #+#    #+#             */
/*   Updated: 2024/05/13 15:16:11 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gl_mlx.h"

static int	already_in(t_list_gl *list, t_mlx_camera_gl *camera)
{
	t_list_gl	*tmp;

	if (!list || !camera)
		return (0);
	tmp = list;
	while (tmp)
	{
		if (((t_mlx_camera_gl *)tmp->content)->name == camera->name)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	mlx_addcamera_gl(t_mlx_gl *mlx, t_mlx_camera_gl *camera)
{
	if (!mlx || !camera)
		return (0);
	if (already_in(mlx->cameras, camera))
		return (mlx_camera_free_gl(mlx, camera), 1);
	if (!addback_list_gl(&mlx->cameras, new_element_gl(camera)))
		return (mlx_camera_free_gl(mlx, camera), 0);
	return (1);
}
