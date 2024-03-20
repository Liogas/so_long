/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 14:35:05 by glions            #+#    #+#             */
/*   Updated: 2024/03/20 12:19:42 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

t_player	*new_player(t_game *game)
{
	t_player	*new;
	int			i;
	int			j;

	i = 0;
	j = 0;
	new = malloc(sizeof(t_player));
	if (!new)
		return (NULL);
	new->nb_object = 0;
	i = -1;
	while (++i < game->map->height)
	{
		j = -1;
		while (++j < game->map->width)
		{
			if (game->map->grid[i][j].value == 4)
				new->pos = game->map->grid[i][j].coord;
		}
	}
	return (new);
}
