/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_setup_cam.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:04:28 by glions            #+#    #+#             */
/*   Updated: 2024/04/26 22:52:14 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	graph_setup_cam(t_game *game, t_mlx_camera_gl *camera)
{
	t_camera	*data;

	data = camera->more_data;
	(data->pxl_center)[0] = game->player->pos_pixel_y + (192 / 2);
	(data->pxl_center)[1] = game->player->pos_pixel_x + (192 / 2); 
	(data->pos_x)[0] = (data->pxl_center)[1] - (camera->width / 2);
	(data->pos_y)[0] = (data->pxl_center)[0] - (camera->height / 2);
	(data->pos_x)[1] = (data->pos_x)[0] + camera->width;
	(data->pos_y)[1] = (data->pos_y)[0] + camera->height;
	if ((data->pos_x)[0] < 0)
		data->pos_x[0] = 0;
	if ((data->pos_y)[0] < 0)
		data->pos_y[0] = 0;
}
