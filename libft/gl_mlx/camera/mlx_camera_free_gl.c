/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_camera_free_gl.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 12:21:28 by glions            #+#    #+#             */
/*   Updated: 2024/04/26 12:54:37 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gl_mlx.h"

void	mlx_camera_free_gl(t_mlx_gl *mlx, t_mlx_camera_gl *camera)
{
	if (!camera || !mlx)
		return ;
	if (camera->bckgd)
		mlx_free_img_gl(mlx, camera->bckgd);
	free(camera);
}
