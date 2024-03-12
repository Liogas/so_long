/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 00:38:20 by glions            #+#    #+#             */
/*   Updated: 2024/01/07 04:24:09 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

/**
 * map_add_line :
 * generates a grid line
 * @param line line read in the map's file
 * @param map map's memory block
 * @param pos position of line in grid
 * @return 0 (ko) or 1 (ok)
*/
static int	map_add_line(char *line, t_map **map, int pos)
{
	int	i;

	(*map)->grid[pos] = malloc((*map)->width * sizeof(int));
	if (!((*map)->grid)[pos])
		return (0);
	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
	{
		if (line[i] == 'C')
			((*map)->grid)[pos][i] = 3;
		else if (line[i] == 'E')
			((*map)->grid)[pos][i] = 4;
		else if (line[i] == 'P')
			((*map)->grid)[pos][i] = 5;
		else
			((*map)->grid)[pos][i] = line[i] - '0';
		i++;
	}
	return (1);
}

int	load_map(t_map	**map)
{
	char	**lines_map;
	int		i;

	lines_map = read_map(map);
	if (!lines_map)
		return (0);
	if (!verif_map(lines_map, (*map)->width, (*map)->height))
		return (free_lines(lines_map), (0));
	i = 0;
	while (lines_map[i])
	{
		ft_printf("%s", lines_map[i]);
		i++;
	}
	(*map)->grid = malloc((*map)->height * sizeof(int *));
	if (!(*map)->grid)
		return (free_lines(lines_map), (0));
	i = -1;
	while (lines_map[++i])
		if (!map_add_line(lines_map[i], map, i))
			return (free_lines(lines_map), (0));
	return (free_lines(lines_map), (1));
}
