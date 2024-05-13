/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_update_animations.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 15:53:52 by glions            #+#    #+#             */
/*   Updated: 2024/05/13 11:52:28 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	graph_update_animation(t_mlx_animation_gl *anim)
{
	t_mlx_sprite_gl	*sprite;

	sprite = mlx_image_get_sprite_by_name_gl(anim->img, anim->sprite_name);
	if (!sprite)
		return (0);
	anim->time += 1;
	if (anim->time >= anim->time_d)
	{
		anim->cur_f += 1;
		if (anim->cur_f >= sprite->nb_frames)
			anim->cur_f = 0;
		anim->time = 0;
	}
	return (1);
}

int	graph_update_animations(t_game *game)
{
	t_list_gl			*objects;
	t_mlx_object_gl		*o;
	t_mlx_animation_gl	*a;

	objects = game->graph_data->objects;
	while (objects)
	{
		o = objects->content;
		if (o->animations)
		{
			a = mlx_get_animation_by_name_gl(game->graph_data, o->name,
					o->curr_anim);
			if (!a)
				return (0);
			if (!graph_update_animation(a))
				return (0);
			objects = objects->next;
		}
	}
	return (1);
}
