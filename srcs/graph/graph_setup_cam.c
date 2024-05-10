/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_setup_cam.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:04:28 by glions            #+#    #+#             */
/*   Updated: 2024/05/10 09:35:25 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	set_y(t_game *game, t_mlx_camera_gl *camera)
{
	t_camera	*data;

	data = camera->more_data;
	if (game->player->pos_y < 3 || game->map->height < 5)
	{
		data->start[0] = 1;
		if (game->map->height < 5)
			data->end[0] = game->map->height - 2;
		else
			data->end[0] = 6;
		data->mode_y = 0;
	}
	else if (game->player->pos_y > game->map->height - 4)
	{
		data->start[0] = game->map->height - 6;
		data->end[0] = game->map->height - 1;
		data->mode_y = (192 * 5) - camera->height;
	}
	else
	{
		data->start[0] = game->player->pos_y - 2;
		data->end[0] = game->player->pos_y + 2;
		data->mode_y = ((192 * 2) + (192 / 2)) - (camera->height / 2);
	}
}

static void	set_x(t_game *game, t_mlx_camera_gl *camera)
{
	t_camera	*data;

	data = camera->more_data;
	if (game->player->pos_x < 4 || game->map->width < 7)
	{
		data->start[1] = 1;
		if (game->map->width < 7)
			data->end[1] = game->map->width - 2;
		else
			data->end[1] = 8;
		data->mode_x = 0;
	}
	else if (game->player->pos_x > game->map->width - 5)
	{
		data->start[1] = game->map->width - 8;
		data->end[1] = game->map->width - 1;
		data->mode_x = (192 * 7) - camera->width;
	}
	else
	{
		data->start[1] = game->player->pos_x - 3;
		data->end[1] = game->player->pos_x + 3;
		data->mode_x = ((192 * 3) + (192 / 2)) - (camera->width / 2);
	}
}

int	graph_setup_cam(t_game *game, t_mlx_camera_gl *camera)
{
	t_camera	*data;

	data = camera->more_data;
	set_y(game, camera);
	set_x(game, camera);
	return (1);
}
