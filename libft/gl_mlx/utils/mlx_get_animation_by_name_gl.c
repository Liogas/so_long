/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_get_animation_by_name_gl.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:24:13 by glions            #+#    #+#             */
/*   Updated: 2024/04/22 15:20:33 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gl_mlx.h"

t_mlx_animation_gl	*mlx_get_animation_by_name_gl(t_mlx_gl *mlx,
		char *object_name, char *animation_name)
{
	t_list_gl		*list;
	t_mlx_object_gl	*object;

	object = mlx_get_object_by_name_gl(mlx, object_name);
	if (!object)
		return (NULL);
	list = object->animations;
	while (list)
	{
		if (!ft_strcmp(((t_mlx_animation_gl *)list->content)->sprite_name,
				animation_name))
			return (list->content);
		list = list->next;
	}
	return (NULL);
}
