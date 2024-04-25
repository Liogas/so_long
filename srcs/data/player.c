/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 15:06:14 by glions            #+#    #+#             */
/*   Updated: 2024/04/25 15:08:23 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	return (new);
}
