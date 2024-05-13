/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_image_get_sprite_by_name_gl.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 10:53:39 by glions            #+#    #+#             */
/*   Updated: 2024/05/13 14:47:17 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gl_mlx.h"

t_mlx_sprite_gl	*mlx_image_get_sprite_by_name_gl(t_mlx_image_gl *image,
		char *sprite_name)
{
	t_list_gl	*list;

	if (!image || !sprite_name || !sprite_name[0])
		return (NULL);
	list = image->sprites;
	while (list)
	{
		if (!ft_strcmp(((t_mlx_sprite_gl *)list->content)->name, sprite_name))
			return ((t_mlx_sprite_gl *)list->content);
		list = list->next;
	}
	return (NULL);
}
