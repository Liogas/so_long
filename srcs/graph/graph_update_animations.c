/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_update_animations.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 15:53:52 by glions            #+#    #+#             */
/*   Updated: 2024/04/29 16:33:41 by glions           ###   ########.fr       */
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

static void	graph_update_animation_player(t_game *game)
{
	if (game->player->pos_pixel_x < game->player->target_x && game->player->target_x != -1 && game->player->target_y == -1)
		update_pos_player(game->player, game->player->pos_pixel_y,
			game->player->pos_pixel_x + 5,
			mlx_get_object_by_name_gl(game->graph_data, "player"));
	else if (game->player->pos_pixel_x > game->player->target_x && game->player->target_x != -1 && game->player->target_y == -1)
		update_pos_player(game->player, game->player->pos_pixel_y,
			game->player->pos_pixel_x - 5,
			mlx_get_object_by_name_gl(game->graph_data, "player"));
	else if (game->player->pos_pixel_y < game->player->target_y && game->player->target_y != -1 && game->player->target_x == -1)
		update_pos_player(game->player, game->player->pos_pixel_y + 5,
			game->player->pos_pixel_x,
			mlx_get_object_by_name_gl(game->graph_data, "player"));
	else if (game->player->pos_pixel_y > game->player->target_y && game->player->target_y != -1 && game->player->target_x == -1)
		update_pos_player(game->player, game->player->pos_pixel_y - 5,
			game->player->pos_pixel_x,
			mlx_get_object_by_name_gl(game->graph_data, "player"));
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
			if (!ft_strcmp(a->sprite_name, "player_moove"))
				graph_update_animation_player(game);
			if (!graph_update_animation(a))
				return (0);
			objects = objects->next;
		}
	}
	return (1);
}
