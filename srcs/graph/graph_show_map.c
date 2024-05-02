/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_show_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 10:52:33 by glions            #+#    #+#             */
/*   Updated: 2024/05/02 16:22:15 by glions           ###   ########.fr       */
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
			if (!graph_draw_map_tile(size_tile, (int[2]){(i - 1) * size_tile[0]
					+ 32, (j - 1) * size_tile[1] + 32}, camera->bckgd,
					game->map->tab[i][j]))
				return (0);
		}
	}
	return (1);
}

static int	graph_draw_map(int limit[2], int height, int width, t_game *game)
{
	int	i;
	int	j;
	int	size_img[2];

	printf("limit_y->%d, limit_x->%d\n", limit[0], limit[1]);
	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			size_img[0] = 128;
			size_img[1] = 128;
			printf("%d > %d\n", i, height);
			printf("%d > %d\n", j, width);
			if (j > width)
				size_img[1] = (j - width);
			if (i > height)
				size_img[0] = (i - height);
			printf("size->{%d,%d}\n", size_img[0], size_img[1]);
			mlx_image_put_image_limit_gl(((t_mlx_camera_gl *)game->graph_data->cameras->content)->bckgd,
				mlx_get_image_by_name_gl(game->graph_data, "bckgd_map"),
				(int[2]){i + 32, j + 32}, size_img);
			j += 128;
		}
		i += 128;
	}
	return (1);
}

static int	graph_draw_map_border(int size_tile[2], t_game *game,
		int size_map[2])
{
	int				i;
	t_mlx_image_gl	*dst;
	t_mlx_camera_gl	*cam;

	(void)size_tile;
	cam = game->graph_data->cameras->content;
	dst = cam->bckgd;
	i = 31;
	while (++i < size_map[1] + 32)
	{
		mlx_image_put_pixel_gl(dst, i, 32, 0);
		mlx_image_put_pixel_gl(dst, i, 33, 0);
		mlx_image_put_pixel_gl(dst, i, size_map[0] + 32, 0);
		mlx_image_put_pixel_gl(dst, i, size_map[0] + 32 - 1, 0);
	}
	i = 31;
	while (++i < size_map[0] + 32)
	{
		mlx_image_put_pixel_gl(dst, 32, i, 0);
		mlx_image_put_pixel_gl(dst, 33, i, 0);
		mlx_image_put_pixel_gl(dst, size_map[1] + 32, i, 0);
		mlx_image_put_pixel_gl(dst, size_map[1] + 32 - 1, i, 0);
	}
	return (1);
}

int	graph_show_map(t_game *game)
{
	int	width;
	int	height;
	int	size_tile[2];
	int	nb_tiles[2];

	nb_tiles[0] = (game->graph_data->window->height - (32 * 2)) / 128;
	nb_tiles[1] = (game->graph_data->window->width - (32 * 2)) / 128;
	size_tile[0] = (nb_tiles[0] * 128) / (game->map->height - 2);
	size_tile[1] = (nb_tiles[1] * 128) / (game->map->width - 2);
	width = size_tile[1] * (game->map->width - 2);
	height = size_tile[0] * (game->map->height - 2);
	// printf("taille de map->{%d,%d}\n", game->map->height, game->map->width);
	// printf("size_map->{%d,%d}, size_tile->{%d,%d}, nb_tiles->{%d,%d}\n", height,
		// width, size_tile[0], size_tile[1], nb_tiles[0], nb_tiles[1]);
	if (!graph_draw_map(nb_tiles, height, width, game))
		return (0);
	if (!graph_draw_map_tiles(size_tile, game))
		return (0);
	if (!graph_draw_map_border(size_tile, game, (int[2]){height,
			width}))
		return (0);
	return (1);
}
