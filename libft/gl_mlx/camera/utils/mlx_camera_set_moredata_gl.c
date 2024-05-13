/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_camera_set_moredata_gl.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:18:39 by glions            #+#    #+#             */
/*   Updated: 2024/05/13 14:44:58 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gl_mlx.h"

void	mlx_camera_set_moredata_gl(void *more_data, t_mlx_camera_gl *camera)
{
	camera->more_data = more_data;
}
