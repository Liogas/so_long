/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_image_put_area_image_gl.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 21:37:26 by glions            #+#    #+#             */
/*   Updated: 2024/05/13 14:48:17 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gl_mlx.h"

void	mlx_image_put_area_image2_gl(t_mlx_image_gl *dst, t_mlx_image_gl *src,
		int pos[2], int size[2])
{
	int	i;
	int	j;

	i = 0;
	while (++i < src->width && i < size[1])
	{
		j = 0;
		while (++j < src->height && j < size[0])
			mlx_image_put_pixel_gl(dst, i, j, mlx_image_get_pixel_gl(src, pos[1]
					+ i, pos[0] + j));
	}
}

void	mlx_image_put_area_image_gl(t_mlx_image_gl *dst, t_mlx_image_gl *src,
		int pos[2], int size[2])
{
	int	i;
	int	j;

	i = 1;
	while (++i < src->width && i < size[0])
	{
		j = 0;
		while (++j < src->height && j < size[1])
			mlx_image_put_pixel_gl(dst, pos[1] + i, pos[0] + j,
				mlx_image_get_pixel_gl(src, i, j));
	}
}
