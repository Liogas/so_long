/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_image_put_image_gl.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 10:15:20 by glions            #+#    #+#             */
/*   Updated: 2024/04/23 11:22:17 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gl_mlx.h"

void	mlx_image_put_image_gl(t_mlx_image_gl *dst, t_mlx_image_gl *src, int x, int y)
{
	int	i;
	int	j;

	i = 1;
	while (++i < src->width)
	{
		j = 0;
		while (++j < src->height)
			mlx_image_put_pixel_gl(dst, x + i, y + j, mlx_image_get_pixel_gl(src, i, j));
	}
}