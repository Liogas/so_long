/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos_algo_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 14:34:22 by glions            #+#    #+#             */
/*   Updated: 2024/03/20 12:17:22 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

void	free_grid_algo(t_pos_algo **grid, t_parsing *p)
{
	int	i;
	int	j;

	i = -1;
	while (++i < p->map->height)
	{
		j = -1;
		while (++j < p->map->width)
		{
			if (grid[i][j].mem)
				free(grid[i][j].mem);
		}
		free(grid[i]);
	}
	free(grid);
}

int	search_id(t_list *items, t_coord *c)
{
	t_list		*e;
	t_item_algo	*tmp;

	e = items;
	while (e)
	{
		tmp = e->content;
		if (((t_coord *)tmp->open->content)->y == c->y
			&& ((t_coord *)tmp->open->content)->x == c->x)
			return (tmp->id);
		e = e->next;
	}
	return (-1);
}

int	set_up_line_grid(t_pos_algo **line, t_list *items, int i, t_parsing *p)
{
	int	j;
	int	*mem;
	int	id;

	j = -1;
	id = -1;
	*line = malloc(p->map->width * sizeof(t_pos_algo));
	if (!(*line))
		return (0);
	while (++j < p->map->width)
	{
		mem = malloc(size_items(items) * sizeof(int));
		if (!mem)
			return (0);
		if (p->map->grid[i][j].value >= 2 && p->map->grid[i][j].value <= 4)
			id = search_id(items, p->map->grid[i][j].coord);
		set_mem(&mem, id, size_items(items));
		id = -1;
		(*line)[j].mem = mem;
	}
	return (1);
}
