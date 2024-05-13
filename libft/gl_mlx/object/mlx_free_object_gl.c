/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_free_object_gl.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 22:19:25 by glions            #+#    #+#             */
/*   Updated: 2024/05/13 15:06:39 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gl_mlx.h"

static void	mlx_free_animations_gl(t_mlx_object_gl *object)
{
	t_list_gl	*tmp;

	while (object->animations)
	{
		tmp = object->animations->next;
		mlx_free_animation_gl(object->animations->content);
		free(object->animations);
		object->animations = tmp;
	}
}

void	mlx_free_object_gl(t_mlx_object_gl *object)
{
	if (object)
	{
		if (object->animations)
			mlx_free_animations_gl(object);
		free(object);
	}
}
