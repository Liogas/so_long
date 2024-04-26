/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_get_camera_by_name_gl.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 20:05:46 by glions            #+#    #+#             */
/*   Updated: 2024/04/26 20:07:25 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gl_mlx.h"

t_mlx_camera_gl	*mlx_get_camera_by_name_gl(t_mlx_gl *mlx, char *camera_name)
{
	t_list_gl	*list;

	if (!mlx || !camera_name)
		return (NULL);
	list = mlx->cameras;
	while (list)
	{
		if (!ft_strcmp(((t_mlx_camera_gl *)list->content)->name, camera_name))
			return (list->content);
		list = list->next;
	}
	return (NULL);
}
