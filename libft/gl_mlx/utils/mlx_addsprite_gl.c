/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_addsprite_gl.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 10:08:06 by glions            #+#    #+#             */
/*   Updated: 2024/04/22 11:23:28 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gl_mlx.h"

int	mlx_addsprite_gl(t_mlx_gl *mlx, char *img_name, t_mlx_sprite_gl *sprite)
{
	t_mlx_image_gl	*img;

	if (!mlx || !img_name || !img_name[0] || !sprite)
		return (0);
	img = mlx_get_image_by_name_gl(mlx, img_name);
	if (!img)
		return (mlx_free_sprite_gl(sprite), 0);
	if (!addback_list_gl(&img->sprites, new_element_gl(sprite)))
		return (mlx_free_sprite_gl(sprite), 0);
	return (1);
}
