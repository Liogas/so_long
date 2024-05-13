/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_addobject_gl.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 09:36:32 by glions            #+#    #+#             */
/*   Updated: 2024/05/13 15:07:46 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gl_mlx.h"

static int	already_in(t_list_gl *list, t_mlx_object_gl *object)
{
	t_list_gl	*tmp;

	if (!list || !object)
		return (0);
	tmp = list;
	while (tmp)
	{
		if (((t_mlx_object_gl *)tmp->content)->name == object->name)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	mlx_addobject_gl(t_mlx_gl *mlx, t_mlx_object_gl *object)
{
	if (!mlx || !object)
		return (0);
	if (already_in(mlx->objects, object))
		return (mlx_free_object_gl(object), 1);
	if (!addback_list_gl(&mlx->objects, new_element_gl(object)))
		return (mlx_free_object_gl(object), 0);
	return (1);
}
