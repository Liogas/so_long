/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_setup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:22:16 by glions            #+#    #+#             */
/*   Updated: 2024/04/30 12:23:12 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	graph_load_images(t_game *game)
{
	if (!graph_addplayer(game))
		return (0);
	if (!graph_addwall(game))
		return (0);
	if (!graph_addexit(game))
		return (0);
	if (!graph_addcollect(game))
		return (0);
	if (!graph_addbackgmap(game))
		return (0);
	if (!mlx_addimage_gl(game->graph_data, mlx_load_img_gl(game->graph_data,
				"./srcs/sprites/grass.xpm", "floor")))
		return (0);
	if (!mlx_addsprite_gl(game->graph_data, "floor",
			mlx_create_sprite_gl("floor", 0, 1, (int [2]){192, 192})))
		return (0);
	return (1);
}

int	graph_gen_camera(t_game *game)
{
	t_mlx_camera_gl	*camera;
	t_camera		*more_data;

	camera = mlx_camera_create_gl("camera_0",
			mlx_get_object_by_name_gl(game->graph_data, "player"), (int [2]){0,
			0}, (int [2]){game->graph_data->window->height,
			game->graph_data->window->width});
	if (!camera)
		return (0);
	more_data = new_camera();
	if (!more_data)
		return (0);
	camera->more_data = more_data;
	game->camera = more_data;
	camera->bckgd = mlx_create_img_gl(game->graph_data, camera->width,
			camera->height, "camera_01_b");
	if (!camera->bckgd)
		return (0);
	if (!mlx_addcamera_gl(game->graph_data, camera))
		return (0);
	return (1);
}

int	graph_setup(t_game *game)
{
	game->graph_data->window = mlx_create_win_gl(game->graph_data, 1280, 720,
			"window");
	mlx_free_img_gl(game->graph_data, game->graph_data->window->bckgd);
	game->graph_data->window->bckgd = mlx_create_img_gl(game->graph_data,
			(game->map->width - 2) * 192, (game->map->height - 2) * 192,
			"all_map");
	if (!game->graph_data->window->bckgd)
		return (ft_putstr_fd("ERROR : create img win\n", 2), 0);
	if (!game->graph_data->window)
		return (ft_putstr_fd("ERROR : create window\n", 2), 0);
	if (!graph_load_images(game))
		return (ft_putstr_fd("ERROR : load images\n", 2), 0);
	if (!graph_gen_camera(game))
		return (ft_putstr_fd("ERROR : gen camera\n", 2), 0);
	return (1);
}
