/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 12:14:48 by glions            #+#    #+#             */
/*   Updated: 2024/03/20 12:09:56 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

void	free_grid(t_map_pos **g, t_map *m)
{
	int	i;
	int	j;

	if (g)
	{
		i = 0;
		while (i < m->height)
		{
			j = 0;
			while (j < m->width)
			{
				if (g[i][j].coord)
					free(g[i][j].coord);
				j++;
			}
			if (g[i])
				free(g[i]);
			i++;
		}
		free(g);
	}
}

t_map_pos	new_map_pos(char c, int y, int x)
{
	t_map_pos	new;
	t_coord		*coord;

	coord = new_coord(y, x);
	new.coord = coord;
	if (c == '0')
		new.value = 0;
	else if (c == '1')
		new.value = 1;
	else if (c == 'C' || c == 'c')
		new.value = 2;
	else if (c == 'E' || c == 'e')
		new.value = 3;
	else if (c == 'P' || c == 'p')
		new.value = 4;
	return (new);
}

t_map_pos	**init_grid(t_parsing *p, t_map **m)
{
	t_map_pos	**grid;
	int			i;
	int			j;
	t_list		*line;

	grid = malloc((*m)->height * sizeof(t_map_pos *));
	if (!grid)
		return (NULL);
	line = p->file->lines;
	i = -1;
	while (line)
	{
		j = 0 * i++;
		grid[i] = malloc((*m)->width * sizeof(t_map_pos));
		if (!grid[i])
			return (free_grid(grid, *m), NULL);
		while (((char *)line->content)[j] && ((char *)line->content)[j] != '\n'
			&& j < (*m)->width)
		{
			grid[i][j] = new_map_pos(((char *)line->content)[j], i, j);
			j++;
		}
		line = line->next;
	}
	return (grid);
}

t_pos_algo	**set_up_grid(t_parsing *p, t_list *items)
{
	t_pos_algo	**grid;
	int			i;

	grid = malloc(p->map->height * sizeof(t_pos_algo *));
	if (!grid)
		return (NULL);
	i = -1;
	while (++i < p->map->height)
		if (!set_up_line_grid(&grid[i], items, i, p))
			return (free_grid_algo(grid, p), NULL);
	return (grid);
}
