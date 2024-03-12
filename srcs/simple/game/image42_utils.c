/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image42_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 11:51:25 by glions            #+#    #+#             */
/*   Updated: 2024/03/12 12:18:04 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

void	image42_free(t_image42 *image)
{
	if (image->ptr)
	{
		mlx_destroy_image(image->mlx, image->ptr);
		free(image->ptr);
	}
	free(image);
}

t_image42	*image42_new(int h, int w, char *path, void *mlx)
{
	t_image42	*new;
	
	new = malloc(sizeof(t_image42));
	if (!new)
		return (printf("Erreur malloc image\n"), NULL);
	new->height = h;
	new->width = w;
	new->mlx = mlx;
	new->ptr = mlx_xpm_file_to_image(mlx, path, &new->width, &new->height);
	if (!new->ptr)
		return (printf("Erreur creation image\n"), free(new), NULL);
	return (new);
}