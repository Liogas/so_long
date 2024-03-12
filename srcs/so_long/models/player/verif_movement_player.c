/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_movement_player.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 10:02:39 by glions            #+#    #+#             */
/*   Updated: 2024/01/04 10:10:49 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	can_up_player(t_map *map, t_player **player)
{
	if (map->grid[(*player)->y - 1][(*player)->x] == 1)
		return (0);
	return (1);
}

int	can_down_player(t_map *map, t_player **player)
{
	if (map->grid[(*player)->y + 1][(*player)->x] == 1)
		return (0);
	return (1);
}

int	can_left_player(t_map *map, t_player **player)
{
	if (map->grid[(*player)->y][(*player)->x - 1] == 1)
		return (0);
	return (1);
}

int	can_right_player(t_map *map, t_player **player)
{
	if (map->grid[(*player)->y][(*player)->x + 1] == 1)
		return (0);
	return (1);
}
