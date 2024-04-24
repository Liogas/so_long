/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_print_object_data_gl.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 19:48:32 by glions            #+#    #+#             */
/*   Updated: 2024/04/22 15:47:05 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gl_mlx.h"

void	mlx_print_object_data_gl(t_mlx_object_gl *object)
{
	t_list_gl	*list;
	
	printf("\n\n-- OBJECT --\n\n");
	printf("POS_X		= %d\n", object->pos_x);
	printf("POS_Y		= %d\n", object->pos_y);
	printf("DATA		= %p\n", object->data);
	printf("NAME		= \"%s\"\n", object->name);
	printf("CURR_ANIM	= \"%s\"\n", object->curr_anim);
	list = object->animations;
	while (list)
	{
		mlx_print_animation_data_gl(list->content);
		list = list->next;
	}
	printf("\n\n------------\n\n");
}