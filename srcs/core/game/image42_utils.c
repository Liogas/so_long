/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image42_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 11:51:25 by glions            #+#    #+#             */
/*   Updated: 2024/03/18 15:15:25 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

void	imgs_free(t_image42 **imgs, int size)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		if (imgs[i] && imgs[i]->ptr)
		{
			mlx_destroy_image(imgs[i]->mlx, imgs[i]->ptr);
			free(imgs[i]);
		}
	}
	free(imgs);
}

void	image42_free(t_image42 *image)
{
	if (image->ptr)
		mlx_destroy_image(image->mlx, image->ptr);
	free(image);
}

int	draw_img(t_game *g)
{
	g->win->bg = image42_new(g->win->height, g->win->width, g->mlx);
	if (!g->win->bg)
		return (printf("Erreur image de fond\n"), 0);
	if (!show_map(g))
		return (0);
	return (1);
}

void	put_pixel_img(t_image42 *img, int x, int y, int color)
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

unsigned int	get_pixel_img(t_image42 *img, int x, int y)
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

t_image42	*image42_new(int w, int h, void *mlx)
{
	t_image42	*new;

	new = malloc(sizeof(t_image42));
	if (!new)
		return (NULL);
	new->mlx = mlx;
	new->ptr = mlx_new_image(mlx, w, h);
	if (!new->ptr)
		return (printf("Erreur image (image42_new)\n"), free(new), NULL);
	new->addr = mlx_get_data_addr(new->ptr, &(new->bpp), &(new->line_len),
			&(new->endian));
	new->width = w;
	new->height = h;
	return (new);
}

t_image42	*image42_file_new(int h, int w, char *path, void *mlx)
{
	t_image42	*new;

	new = malloc(sizeof(t_image42));
	if (!new)
		return (printf("Erreur malloc image (image42_file_new)\n"), NULL);
	new->height = h;
	new->width = w;
	new->mlx = mlx;
	new->ptr = mlx_xpm_file_to_image(mlx, path, &new->width, &new->height);
	if (!new->ptr)
		return (printf("Erreur creation image\n"), free(new), NULL);
	new->addr = mlx_get_data_addr(new->ptr, &(new->bpp), &(new->line_len),
			&(new->endian));
	return (new);
}
