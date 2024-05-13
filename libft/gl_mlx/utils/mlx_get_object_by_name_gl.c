/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_get_object_by_name_gl.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 10:47:59 by glions            #+#    #+#             */
/*   Updated: 2024/05/13 15:08:16 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gl_mlx.h"

t_mlx_object_gl	*mlx_get_object_by_name_gl(t_mlx_gl *mlx, char *name)
{
	t_list_gl	*list;

	if (!mlx || !name)
		return (NULL);
	list = mlx->objects;
	while (list)
	{
		if (!ft_strcmp(((t_mlx_object_gl *)list->content)->name, name))
			return ((t_mlx_object_gl *)list->content);
		list = list->next;
	}
	return (NULL);
}
