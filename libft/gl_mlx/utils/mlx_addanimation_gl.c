/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_addanimation_gl.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 10:49:35 by glions            #+#    #+#             */
/*   Updated: 2024/05/13 15:15:59 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gl_mlx.h"

int	mlx_addanimation_gl(t_mlx_gl *mlx, char *object_name, char *name,
		t_mlx_animation_gl *animation)
{
	t_mlx_object_gl	*obj;

	if (!mlx || !object_name || !name || !animation)
		return (0);
	obj = mlx_get_object_by_name_gl(mlx, object_name);
	if (!obj)
		return (mlx_free_animation_gl(animation), 0);
	if (!addback_list_gl(&obj->animations, new_element_gl(animation)))
		return (mlx_free_animation_gl(animation), 0);
	return (1);
}
