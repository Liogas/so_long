/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_create_object_gl.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 22:12:42 by glions            #+#    #+#             */
/*   Updated: 2024/05/13 15:04:54 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gl_mlx.h"

t_mlx_object_gl	*mlx_create_object_gl(char *name, int pos_x, int pos_y,
		void *data)
{
	t_mlx_object_gl	*new;

	if (pos_x < 0 || pos_y < 0 || !name)
		return (NULL);
	new = malloc(sizeof(t_mlx_object_gl));
	if (!new)
		return (NULL);
	new->name = name;
	new->curr_anim = NULL;
	new->animations = NULL;
	new->pos_x = pos_x;
	new->pos_y = pos_y;
	new->data = data;
	return (new);
}
