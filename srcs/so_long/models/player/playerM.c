/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playerM.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 09:05:11 by glions            #+#    #+#             */
/*   Updated: 2024/01/04 10:10:45 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	set_start_player(int y, int x, t_player *player)
{
	player->x = x;
	player->y = y;
}

t_player	*new_player(void)
{
	t_player	*new_player;

	new_player = malloc(sizeof(t_player));
	if (!new_player)
		return (NULL);
	new_player->id = 1;
	new_player->y = -1;
	new_player->x = -1;
	return (new_player);
}

void	free_player(t_player *player)
{
	free(player);
}
