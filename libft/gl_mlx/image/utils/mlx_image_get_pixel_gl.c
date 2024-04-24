/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_image_get_pixel_gl.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 10:18:39 by glions            #+#    #+#             */
/*   Updated: 2024/04/22 12:32:19 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gl_mlx.h"

unsigned int	mlx_image_get_pixel_gl(t_mlx_image_gl *img, int x, int y)
{
	return (*(unsigned int *)((img->addr + (y * img->line_len) + (x * img->bpp
				/ 8))));
}
