/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_camera_create_gl.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 11:46:20 by glions            #+#    #+#             */
/*   Updated: 2024/05/13 15:15:22 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gl_mlx.h"

t_mlx_camera_gl	*mlx_camera_create_gl(char *name, t_mlx_object_gl *target,
		int pos[2], int size[2])
{
	t_mlx_camera_gl	*new;

	if (!target || !name)
		return (NULL);
	new = malloc(sizeof(t_mlx_camera_gl));
	if (!new)
		return (NULL);
	new->name = name;
	new->target = target;
	new->width = size[1];
	new->height = size[0];
	new->more_data = NULL;
	if (target)
	{
		new->pos_y = target->pos_y;
		new->pos_x = target->pos_x;
	}
	else
	{
		new->pos_y = pos[0];
		new->pos_x = pos[1];
	}
	new->bckgd = NULL;
	return (new);
}
