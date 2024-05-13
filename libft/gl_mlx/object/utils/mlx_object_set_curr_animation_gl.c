/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_object_set_curr_animation_gl.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 18:21:31 by glions            #+#    #+#             */
/*   Updated: 2024/05/13 15:06:52 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gl_mlx.h"

int	mlx_object_set_curr_animation_gl(t_mlx_gl *mlx, char *object_name,
		char *animation_name)
{
	t_mlx_object_gl	*obj;

	if (!mlx || !object_name)
		return (0);
	obj = mlx_get_object_by_name_gl(mlx, object_name);
	if (!obj)
		return (0);
	obj->curr_anim = animation_name;
	return (1);
}
