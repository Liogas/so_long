/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_sprite_put_frame_to_img.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 14:02:30 by glions            #+#    #+#             */
/*   Updated: 2024/04/22 15:19:15 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gl_mlx.h"

int	mlx_sprite_put_frame_to_img(t_mlx_image_gl *dst, t_mlx_image_gl *src,
		t_mlx_sprite_gl *sprite, int pos[2])
{
	int	i;
	int	j;
	int	x;
	int	y;

	if (!dst || !src || !data || dst->width < pos[1] + src->sprites->width_frame
		|| dst->height < pos[0] + src->sprites->height_frame)
		return (0);
	i = -1;
	x = src->sprites->width_frame * data->current;
	y = src->sprites->height_frame * data->pos_y;
	while (++i < src->sprites->height_frame)
	{
		j = -1;
		while (++j < src->sprites->width_frame)
			put_pixel_img(dst, pos[1] + j, pos[0] + i, get_pixel_img(src, x + j,
					y + i));
	}
	return (1);
}
