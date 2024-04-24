/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img_to_img.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 12:11:43 by glions            #+#    #+#             */
/*   Updated: 2024/03/20 12:21:16 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

static void	put_pixel_img(t_image42 *img, int x, int y, int color)
{
	char	*dst;

	if (color == (int)0xFF000000)
		return ;
	if (x >= 0 && y >= 0 && x < img->width && y < img->height)
	{
		dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
		*(unsigned int *)dst = color;
	}
}

static unsigned int	get_pixel_img(t_image42 *img, int x, int y)
{
	return (*(unsigned int *)((img->addr + (y * img->line_len) + (x * img->bpp
				/ 8))));
}

void	put_img_to_img(t_image42 *dst, t_image42 *src, int x, int y)
{
	int	i;
	int	j;

	i = 1;
	while (++i < src->width)
	{
		j = 0;
		while (++j < src->height)
			put_pixel_img(dst, x + i, y + j, get_pixel_img(src, i, j));
	}
}
