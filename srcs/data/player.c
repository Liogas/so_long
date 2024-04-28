/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 15:06:14 by glions            #+#    #+#             */
/*   Updated: 2024/04/28 17:55:11 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_pos_player(t_player *player, int pos_y, int pos_x,
		t_mlx_object_gl *obj)
{
	if (obj)
	{
		obj->pos_x = pos_x;
		obj->pos_y = pos_y;
	}
	player->pos_pixel_y = pos_y;
	player->pos_pixel_x = pos_x;
}

void	free_player(t_player *player)
{
	free(player);
}

t_player	*new_player(int y, int x)
{
	t_player	*new;

	new = malloc(sizeof(t_player));
	if (!new)
		return (NULL);
	new->direction = 0;
	new->pos_x = x;
	new->pos_y = y;
	new->pos_pixel_x = (x - 1) * 192;
	new->pos_pixel_y = (y - 1) * 192;
	return (new);
}
