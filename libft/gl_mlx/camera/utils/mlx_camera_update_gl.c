/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_camera_update_gl.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 14:44:48 by glions            #+#    #+#             */
/*   Updated: 2024/05/13 14:44:47 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gl_mlx.h"

void	mlx_camera_update_pos_gl(t_mlx_camera_gl *camera, int new_pos[2])
{
	if (new_pos[0] == -1 || new_pos[1] == -1)
	{
		camera->pos_x = camera->target->pos_x;
		camera->pos_y = camera->target->pos_y;
	}
	else
	{
		camera->pos_x = new_pos[1];
		camera->pos_y = new_pos[0];
	}
}
