/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_draw_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 18:25:40 by glions            #+#    #+#             */
/*   Updated: 2024/04/28 16:25:14 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	graph_draw_texture(int pos[2], int value, t_game *game,
		t_mlx_image_gl *img)
{
	if (value == 2)
		return (graph_drawwall(pos[0], pos[1], game, img));
	else if (value == 3)
		return (graph_drawplayer((int[2]){pos[0], pos[1]}, game, img));
	else if (value == 4)
		return (graph_drawexit(pos[0], pos[1], game, img));
	else if (value == 5)
		return (graph_drawcollect(pos[0], pos[1], game, img));
	else if (value == 0)
		return (graph_drawfloor(pos[0], pos[1], game, img));
	return (0);
}

static int	graph_draw_first_step(t_game *game, t_mlx_image_gl **dst,
		t_camera *data)
{
	int	i;
	int	j;
	int	k;
	int	l;

	i = -1;
	k = data->start[0];
	while (++i < 5)
	{
		j = -1;
		l = data->start[1];
		while (++j < 7)
		{
			if (!graph_draw_texture((int[2]){i, j}, game->map->tab[k][l], game,
					*dst))
				return (0);
			l++;
		}
		k++;
	}
	return (1);
}

static void	graph_draw_for_camera(t_game *game, t_mlx_camera_gl *camera)
{
	t_camera	*data;

	data = camera->more_data;
	mlx_image_put_area_image2_gl(camera->bckgd, game->graph_data->window->bckgd,
		(int[2]){data->mode_y, data->mode_x}, (int[2]){camera->height, camera->width});
}

int	graph_draw_map(t_game *game, t_mlx_camera_gl *camera)
{
	if (!camera)
		return (0);
	if (!graph_setup_cam(game, camera))
		return (0);
	if (!graph_draw_first_step(game, &game->graph_data->window->bckgd,
			camera->more_data))
		return (ft_putstr_fd("ERROR : draw all map\n", 2), 0);
	graph_draw_for_camera(game, camera);
	mlx_put_image_to_window(game->graph_data->ptr,
		game->graph_data->window->ptr, camera->bckgd->ptr, 0, 0);
	return (1);
}
