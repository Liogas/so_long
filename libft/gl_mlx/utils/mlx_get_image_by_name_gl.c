/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_get_image_by_name_gl.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 10:44:13 by glions            #+#    #+#             */
/*   Updated: 2024/05/13 15:08:07 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gl_mlx.h"

t_mlx_image_gl	*mlx_get_image_by_name_gl(t_mlx_gl *mlx, char *name)
{
	t_list_gl	*list;

	if (!mlx || !name)
		return (NULL);
	list = mlx->images;
	while (list)
	{
		if (!ft_strcmp(((t_mlx_image_gl *)list->content)->name, name))
			return (list->content);
		list = list->next;
	}
	return (NULL);
}
