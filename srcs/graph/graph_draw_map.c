/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_draw_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 18:25:40 by glions            #+#    #+#             */
/*   Updated: 2024/04/26 23:30:05 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	graph_draw_all_map(t_game *game, t_mlx_image_gl *dst)
{
	int	i;
	int	j;
	int	e;

	i = -1;
	e = 1;
	printf("Position de mon player{%d,%d}\n", game->player->pos_y, game->player->pos_x);
	printf("Position de mon player{%d,%d}\n", game->player->pos_pixel_y, game->player->pos_pixel_x);
	while (++i < game->map->height && e)
	{
		j = -1;
		while (++j < game->map->width && e)
		{
			if (game->map->tab[i][j] == 2)
				e = graph_drawwall(i - 1, j - 1, game, dst);
			else if (game->map->tab[i][j] == 3)
				e = graph_drawplayer((int [2]){i - 1, j - 1}, game, dst);
			else if (game->map->tab[i][j] == 4)
				e = graph_drawexit(i - 1, j - 1, game, dst);
			else if (game->map->tab[i][j] == 5)
				e = graph_drawcollect(i - 1, j - 1, game, dst);
			else if (game->map->tab[i][j] == 0)
				e = graph_drawfloor(i - 1, j - 1, game, dst);
		}
	}
	return (e);
}

static void	graph_draw_for_camera(t_game *game, t_mlx_camera_gl *camera)
{
	t_camera	*data;

	data = camera->more_data;
	mlx_image_put_area_image2_gl(camera->bckgd, game->graph_data->window->bckgd,
		(int[2]){(data->pos_y)[0], (data->pos_x)[0]}, (int[2]){camera->height,
		camera->width});
}

int	graph_draw_map(t_game *game, t_mlx_camera_gl *camera)
{
	if (!camera)
		return (0);
	graph_setup_cam(game, camera);
	if (!graph_draw_all_map(game, game->graph_data->window->bckgd))
		return (ft_putstr_fd("ERROR : draw all map\n", 2), 0);
	printf("diejifjefjeijifje\n");
	graph_draw_for_camera(game, camera);
	mlx_put_image_to_window(game->graph_data->ptr,
		game->graph_data->window->ptr, camera->bckgd->ptr, 0, 0);
	return (1);
}
