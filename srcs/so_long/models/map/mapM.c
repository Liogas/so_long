/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapM.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:55:45 by glions            #+#    #+#             */
/*   Updated: 2024/01/04 09:23:30 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	update_grid(int ***grid, char direction, t_player *player)
{
	(*grid)[player->y][player->x] = 5;
	if (direction == 'U')
		(*grid)[player->y + 1][player->x] = 0;
	else if (direction == 'D')
		(*grid)[player->y - 1][player->x] = 0;
	else if (direction == 'L')
		(*grid)[player->y][player->x + 1] = 0;
	else if (direction == 'R')
		(*grid)[player->y][player->x - 1] = 0;
}

t_map	*new_map(char *path_file, int fd)
{
	t_map	*new_map;

	new_map = malloc(sizeof(t_map));
	if (!new_map)
		return (NULL);
	new_map->path_file = path_file;
	new_map->fd = fd;
	new_map->width = 0;
	new_map->height = 0;
	new_map->grid = NULL;
	load_map(&new_map);
	if (!new_map->grid)
		return (free_map(new_map), (NULL));
	return (new_map);
}

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	if (map->grid)
	{
		while (i < map->height)
			free(map->grid[i++]);
		free(map->grid);
	}
	free(map);
}

void	free_lines(char **lines)
{
	int	i;

	i = 0;
	while (lines[i])
		free(lines[i++]);
	free(lines);
}
