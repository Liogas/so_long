/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_create_sprite_gl.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:04:18 by glions            #+#    #+#             */
/*   Updated: 2024/04/21 21:29:37 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gl_mlx.h"

t_mlx_sprite_gl	*mlx_create_sprite_gl(char *name, int pos_y, int nb_frame,
		int size_frame[2])
{
	t_mlx_sprite_gl	*new;

	if (!name || pos_y < 0 || nb_frame < 0 || !size_frame)
		return (NULL);
	new = malloc(sizeof(t_mlx_sprite_gl));
	if (!new)
		return (NULL);
	new->height_frame = size_frame[0];
	new->width_frame = size_frame[1];
	new->name = name;
	new->pos_y = pos_y;
	new->nb_frames = nb_frame;
	return (new);
}
