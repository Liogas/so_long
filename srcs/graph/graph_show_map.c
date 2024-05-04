/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_show_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 10:52:33 by glions            #+#    #+#             */
/*   Updated: 2024/05/04 16:55:10 by glions           ###   ########.fr       */
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

int	graph_draw_map_tile(t_mlx_image_gl *dst, int pos[2], int size[2], int type)
{
	int	i;
	int	j;
	int	color;

	i = -1;
	while (++i < size[0])
	{
		j = -1;
		while (++j < size[1])
		{
			color = -1;
			if (type == 3)
				color = 0x00c0d6;
			else if (type == 4)
				color = 0xd67e00;
			else if (type == 5)
				color = 0x8b02d5;
			else if (type == 2)
				color = 0;
			if (color != -1)
				mlx_image_put_pixel_gl(dst, pos[1] + j, pos[0] + i, color);
		}
	}
	return (1);
}

int	graph_draw_map_tiles(t_game *game, int size_tile[2])
{
	int				i;
	int				j;
	int				pos[2];
	t_mlx_camera_gl	*camera;

	camera = game->graph_data->cameras->content;
	if (!camera)
		return (0);
	i = -1;
	pos[0] = 5;
	while (++i < game->map->height - 2)
	{
		j = -1;
		pos[1] = 5;
		while (++j < game->map->width - 2)
		{
			if (!graph_draw_map_tile(camera->bckgd, (int[2]){i * size_tile[0]
					+ 64, j * size_tile[1] + 64}, size_tile, game->map->tab[i
					+ 1][j + 1]))
				return (0);
			pos[1] += size_tile[1];
		}
		pos[0] += size_tile[0];
	}
	return (1);
}

int	graph_draw_map_bkcgd(t_game *game, int h, int w)
{
	int	i;
	int	j;
	int	size_img[2];

	i = -1;
	while (++i < 5)
	{
		j = -1;
		while (++j < 9)
		{
			size_img[0] = 128;
			size_img[1] = 128;
			if ((i + 1) * 128 > h)
				size_img[0] = 128 - (((i + 1) * 128) - h);
			if ((j + 1) * 128 > w)
				size_img[1] = 128 - (((j + 1)  * 128) - w);
			mlx_image_put_image_limit_gl(((t_mlx_camera_gl *)game->graph_data->cameras->content)->bckgd,
				mlx_get_image_by_name_gl(game->graph_data, "bckgd_map"),
				(int[2]){(i * 128) + 64, (j * 128) + 64}, size_img);
		}
	}
	return (1);
}

int	graph_show_map(t_game *game)
{
	int	width;
	int	height;
	int	size_tile[2];

	width = 1152;
	height = 592;
	size_tile[0] = 584 / (game->map->height - 2);
	size_tile[1] = 1144 / (game->map->width - 2);
	height = size_tile[0] * (game->map->height - 2);
	width = size_tile[1] * (game->map->width - 2);
	if (!graph_draw_map_bkcgd(game, height, width))
		return (0);
	if (!graph_draw_map_tiles(game, size_tile))
		return (0);
	if (!graph_draw_map_border(game, height, width, size_tile))
		return (0);
	return (1);
}
