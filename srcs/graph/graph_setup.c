/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_setup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:22:16 by glions            #+#    #+#             */
/*   Updated: 2024/04/26 12:59:47 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_listener(int key, t_game *game)
{
	if (key == XK_Escape)
		mlx_loop_end(game->graph_data->ptr);
	return (0);
}

static int	graph_load_images(t_game *game)
{
	if (!graph_addborder(game))
		return (0);
	if (!graph_addplayer(game))
		return (0);
	if (!graph_addwall(game))
		return (0);
	if (!graph_addexit(game))
		return (0);
	if (!graph_addcollect(game))
		return (0);
	if (!mlx_addimage_gl(game->graph_data, mlx_load_img_gl(game->graph_data,
				"./srcs/sprites/grass.xpm", "floor")))
		return (0);
	if (!mlx_addsprite_gl(game->graph_data, "floor",
			mlx_create_sprite_gl("floor", 0, 1, (int[2]){192, 192})))
		return (0);
	return (1);
}

int	graph_draw_map(t_game *game, t_mlx_image_gl *dst)
{
	int	i;
	int	j;
	int	e;

	i = -1;
	e = 1;
	while (++i < game->map->height)
	{
		j = -1;
		while (++j < game->map->width)
		{
			if (game->map->tab[i][j] == 2)
				e = graph_drawwall(i - 1, j - 1, game, dst);
			else if (game->map->tab[i][j] == 3)
				e = graph_drawplayer(i - 1, j - 1, game, dst);
			else if (game->map->tab[i][j] == 4)
				e = graph_drawexit(i - 1, j - 1, game, dst);
			else if (game->map->tab[i][j] == 5)
				e = graph_drawcollect(i - 1, j - 1, game, dst);
			else if (game->map->tab[i][j] == 0)
				e = graph_drawfloor(i - 1, j - 1, game, dst);
			if (!e)
				return (0);
		}
	}
	return (1);
}

int	graph_setup(t_game *game)
{
	t_mlx_camera_gl	*camera;

	game->graph_data->window = mlx_create_win_gl(game->graph_data, 1280, 720,
			"window");
	if (!game->graph_data->window)
		return (ft_putstr_fd("ERROR : create window\n", 2), 0);
	if (!graph_load_images(game))
		return (ft_putstr_fd("ERROR : load images\n", 2), 0);
	camera = mlx_camera_create_gl("camera_0",
			mlx_get_object_by_name_gl(game->graph_data, "player"), (int[2]){0,
			0}, (int[2]){game->graph_data->window->height,
			game->graph_data->window->width});
	if (!camera)
		return (0);
	if (!mlx_addcamera_gl(game->graph_data, camera))
		return (ft_putstr_fd("ERROR : create camera\n", 2), 0);
	camera->bckgd = mlx_create_img_gl(game->graph_data,
			game->graph_data->window->width, game->graph_data->window->width,
			"camera_01_b");
	if (!camera->bckgd)
		return (0);
	if (!graph_draw_map(game, camera->bckgd))
		return (ft_putstr_fd("ERROR : draw map\n", 2), 0);
	mlx_put_image_to_window(game->graph_data->ptr,
		game->graph_data->window->ptr, camera->bckgd->ptr, 0, 0);
	mlx_key_hook(game->graph_data->window->ptr, &key_listener, game);
	mlx_loop(game->graph_data->ptr);
	return (1);
}
