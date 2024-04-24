/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_addobject_gl.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 09:36:32 by glions            #+#    #+#             */
/*   Updated: 2024/04/22 10:02:00 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gl_mlx.h"

int	mlx_addobject_gl(t_mlx_gl *mlx, t_mlx_object_gl *object)
{
	if (!mlx || !object)
		return (0);
	if (!addback_list_gl(&mlx->objects, new_element_gl(object)))
		return (mlx_free_object_gl(object), 0);
	return (1);
}
