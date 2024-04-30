/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 15:08:56 by glions            #+#    #+#             */
/*   Updated: 2024/04/30 12:35:10 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	nb_sheep(int **tab, int h, int w)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	c = 0;
	while (++i < h - 1)
	{
		j = 0;
		while (++j < w - 1)
		{
			if (tab[i][j] == 5)
				c++;
		}
	}
	return (c);
}

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
	new->win = 0;
	new->turns = 0;
	new->sheeps = nb_sheep(map->tab, map->height, map->width);
	new->minimap = -1;
	return (new);
}
