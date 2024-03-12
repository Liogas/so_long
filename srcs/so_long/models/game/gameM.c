/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameM.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 01:09:19 by glions            #+#    #+#             */
/*   Updated: 2024/01/07 04:22:27 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	set_data_from_map(t_game **game)
{
	int	x;
	int	y;

	y = 0;
	while (y < (*game)->map->height)
	{
		x = 0;
		while (x < (*game)->map->width)
		{
			if ((*game)->map->grid[y][x] == 5)
			{
				if ((*game)->player->x != -1 || (*game)->player->y != -1)
					return (1);
				set_start_player(y, x, (*game)->player);
			}
			else if ((*game)->map->grid[y][x] == 3)
			{
				if (add_object(&(*game)->objects, y, x))
					return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

t_game	*new_game(int fd, char *path_file)
{
	t_game	*new_game;

	new_game = malloc(sizeof(t_game));
	if (!new_game)
		return (NULL);
	new_game->turn = 0;
	new_game->state = -1;
	new_game->mobs = NULL;
	new_game->player = new_player();
	new_game->objects = NULL;
	if (!new_game->player)
		return (free_game(new_game), (NULL));
	new_game->map = new_map(path_file, fd);
	if (!new_game->map)
		return (free_game(new_game), (NULL));
	if (set_data_from_map(&new_game))
		return (free_game(new_game), (NULL));
	return (new_game);
}

void	free_game(t_game *game)
{
	if (game->mobs)
		free(game->mobs);
	if (game->objects)
		free_objects(game->objects);
	if (game->player)
		free(game->player);
	if (game->map)
	{
		if (game->map->fd)
			close(game->map->fd);
		free_map(game->map);
	}
	free(game);
}
