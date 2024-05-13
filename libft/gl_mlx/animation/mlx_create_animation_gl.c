/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_create_animation_gl.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 21:42:32 by glions            #+#    #+#             */
/*   Updated: 2024/05/13 16:24:05 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gl_mlx.h"

t_mlx_animation_gl	*mlx_create_animation_gl(t_mlx_image_gl *img,
		char *sprite_name, int time_delay)
{
	t_mlx_animation_gl	*new;

	if (!img || !sprite_name || time_delay <= 0 || !sprite_name[0])
		return (NULL);
	new = malloc(sizeof(t_mlx_animation_gl));
	if (!new)
		return (NULL);
	new->img = img;
	new->sprite_name = sprite_name;
	new->time_d = time_delay;
	new->time = 0;
	new->cur_f = 0;
	return (new);
}
