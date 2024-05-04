/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_show_map_border.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 15:51:53 by glions            #+#    #+#             */
/*   Updated: 2024/05/04 16:55:14 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	draw_border_left_right(t_mlx_image_gl *dst, int h, int w)
{
	int	i;
	int	j;

	i = -1;
	while (++i < h)
	{
		j = -1;
		while (++j < 4)
		{
			mlx_image_put_pixel_gl(dst, 64 + j, i + 64, 0);
			mlx_image_put_pixel_gl(dst, 64 + w - j, i + 64, 0);
		}
	}
}

static void	draw_border_top_bot(t_mlx_image_gl *dst, int h, int w)
{
	int	i;
	int	j;

	i = -1;
	while (++i < w)
	{
		j = -1;
		while (++j < 4)
		{
			mlx_image_put_pixel_gl(dst, i + 64, 64 + j, 0);
			mlx_image_put_pixel_gl(dst, i + 64, 64 + h - j, 0);
		}
	}
}

int	graph_draw_map_border(t_game *game, int h, int w, int size_tile[2])
{
	t_mlx_image_gl	*dst;
	int				i;
	int				j;

	dst = ((t_mlx_camera_gl *)(game->graph_data->cameras->content))->bckgd;
	if (!dst)
		return (0);
	(draw_border_left_right(dst, h, w), draw_border_top_bot(dst, h, w));
	i = size_tile[1] + 5;
	while (i < w)
	{
		j = 4;
		while (++j < h)
			mlx_image_put_pixel_gl(dst, i + 59, j + 59, 0);
		i += size_tile[1];
	}
	i = size_tile[0] + 5;
	while (i < h)
	{
		j = 4;
		while (++j < w)
			mlx_image_put_pixel_gl(dst, j + 59, i + 59, 0);
		i += size_tile[0];
	}
	return (1);
}
