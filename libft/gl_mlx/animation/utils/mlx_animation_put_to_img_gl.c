/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_animation_put_to_img_gl.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 10:49:26 by glions            #+#    #+#             */
/*   Updated: 2024/04/26 18:18:15 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gl_mlx.h"

void	mlx_animation_put_to_img_gl(t_mlx_gl *mlx, t_mlx_object_gl *object,
		t_mlx_animation_gl *animation, t_mlx_image_gl *dst)
{
	int				i;
	int				j;
	int				x;
	int				y;
	t_mlx_sprite_gl	*sprite;

	if (!dst || !mlx || !object || !animation)
		return ;
	sprite = mlx_image_get_sprite_by_name_gl(animation->img,
			animation->sprite_name);
	if (!sprite)
		return ;
	i = -1;
	x = sprite->width_frame * animation->cur_f;
	y = sprite->height_frame * sprite->pos_y;
	while (++i < sprite->height_frame)
	{
		j = -1;
		while (++j < sprite->width_frame)
			mlx_image_put_pixel_gl(dst, object->pos_x + j, object->pos_y + i,
				mlx_image_get_pixel_gl(animation->img, x + j, y + i));
	}
	return ;
}
