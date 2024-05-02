/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_image_put_image_gl.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 10:15:20 by glions            #+#    #+#             */
/*   Updated: 2024/05/02 15:03:56 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gl_mlx.h"

void	mlx_image_put_image_gl(t_mlx_image_gl *dst, t_mlx_image_gl *src, int x,
		int y)
{
	int	i;
	int	j;

	i = -1;
	while (++i < src->width)
	{
		j = -1;
		while (++j < src->height)
			mlx_image_put_pixel_gl(dst, x + i, y + j,
				mlx_image_get_pixel_gl(src, i, j));
	}
}

void	mlx_image_put_image_limit_gl(t_mlx_image_gl *dst, t_mlx_image_gl *src,
		int pos[2], int limit[2])
{
	int	i;
	int	j;

	i = 0;
	while (i < src->width && i < limit[1])
	{
		j = 0;
		while (j < src->height && j < limit[0])
		{
			mlx_image_put_pixel_gl(dst, pos[1] + i, pos[0] + j,
				mlx_image_get_pixel_gl(src, i, j));
			j++;
		}
		i++;
	}
}
