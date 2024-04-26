/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 15:08:56 by glions            #+#    #+#             */
/*   Updated: 2024/04/26 20:02:24 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_game(t_game *game)
{
	if (!game)
		return ;
	if (game->graph_data)
		mlx_free_gl(game->graph_data);
	if (game->map)
		free_map(game->map);
	if (game->player)
		free_player(game->player);
	if (game->camera)
		free_camera(game->camera);
	free(game);
}

t_game	*new_game(t_map *map)
{
	t_game	*new;

	if (!map)
		return (NULL);
	new = malloc(sizeof(t_game));
	if (!new)
		return (NULL);
	new->camera = NULL;
	new->graph_data = mlx_init_gl();
	if (!new->graph_data)
		return (free(new), NULL);
	new->map = map;
	new->player = new_player(map->player_y, map->player_x);
	if (!new->player)
		return (free_game(new), NULL);
	return (new);
}
