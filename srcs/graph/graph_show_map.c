/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_show_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 10:52:33 by glions            #+#    #+#             */
/*   Updated: 2024/04/30 15:30:09 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	graph_addbackgmap(t_game *game)
{
	if (!mlx_addimage_gl(game->graph_data, mlx_load_img_gl(game->graph_data,
				"./srcs/sprites/backg_map.xpm", "bckgd_map")))
		return (0);
	return (1);
}

static int	graph_draw_map_tile(int size[2], int pos[2], t_mlx_image_gl *image,
		int type)
{
	int	i;
	int	j;
	int	color;

	color = -1;
	i = -1;
	while (++i < size[0])
	{
		j = -1;
		while (++j < size[1])
		{
			if (type == 3)
				color = 0x00c0d6;
			else if (type == 4)
				color = 0xd67e00;
			else if (type == 5)
				color = 0x8b02d5;
			else if (type == 2)
				color = 0;
			if (color != -1)
				mlx_image_put_pixel_gl(image, pos[1] + j, pos[0] + i, color);
			color = -1;
		}
	}
	return (1);
}

// static int	graph_draw_map_border(int width, int height, t_mlx_image_gl *image)
// {
// 	int	i;

// 	i = 74;
// 	while (++i < width - 10)
// 	{
// 		mlx_image_put_pixel_gl(image, i, 42, 0);
// 		mlx_image_put_pixel_gl(image, i, 43, 0);
// 		mlx_image_put_pixel_gl(image, i, height - 11, 0);
// 		mlx_image_put_pixel_gl(image, i, height - 10, 0);
// 	}
// 	i = 42;
// 	while (++i < height - 10)
// 	{
// 		mlx_image_put_pixel_gl(image, 74, i, 0);
// 		mlx_image_put_pixel_gl(image, 75, i, 0);
// 		mlx_image_put_pixel_gl(image, width - 10, i, 0);
// 		mlx_image_put_pixel_gl(image, width - 11, i, 0);
// 	}
// 	return (1);
// }

static int	graph_draw_map_tiles(int size_tile[2], t_game *game)
{
	int				i;
	int				j;
	t_mlx_camera_gl	*camera;

	camera = game->graph_data->cameras->content;
	i = 0;
	while (++i < game->map->height - 1)
	{
		j = 0;
		while (++j < game->map->width - 1)
		{
			if (!graph_draw_map_tile(size_tile, (int[2]){i * size_tile[0] + 32,
					j * size_tile[1] + 64}, camera->bckgd,
					game->map->tab[i][j]))
				return (0);
		}
	}
	return (1);
}

static int	graph_draw_map(int width, int height, int size_tile[2],
		t_game *game)
{
	int				i;
	int				j;
	t_mlx_camera_gl	*camera;

	(void)size_tile;
	camera = game->graph_data->cameras->content;
	if (!camera)
		return (printf("de\n"), 0);
	i = 0;
	while (i <= height / 128)
	{
		j = 0;
		while (j < width / 128)
		{
			mlx_image_put_image_gl(camera->bckgd,
				mlx_get_image_by_name_gl(game->graph_data, "bckgd_map"), j * 126
				+ 64, i * 126 + 32);
			j++;
		}
		i++;
	}
	// width = j * 126 + 64;
	// height = i * 126 + 32;
	// if (!graph_draw_map_border(width, height, camera->bckgd))
	// return (0);
	return (1);
}

int	graph_show_map(t_game *game)
{
	int	width;
	int	height;
	int	size_tile[2];

	width = game->graph_data->window->width - (64 * 2);
	height = game->graph_data->window->height - (64 * 2);
	size_tile[0] = width / game->map->width;
	size_tile[1] = height / game->map->height;
	if (!graph_draw_map(width, height, size_tile, game))
		return (0);
	if (!graph_draw_map_tiles(size_tile, game))
		return (0);
	return (1);
}
