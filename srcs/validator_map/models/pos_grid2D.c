/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos_grid2D.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 09:15:24 by glions            #+#    #+#             */
/*   Updated: 2024/02/13 11:28:39 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/validator_map.h"

void	free_pos_grid2D(t_pos_grid2D *pos)
{
	if (pos->data)
		free_data_pos(pos->data);
	free(pos);
}

void	free_all_pos_grid2D(t_pos_grid2D *first)
{
	t_pos_grid2D	*line_pos;
	t_pos_grid2D	*col_pos;
	t_pos_grid2D	*tmp;

	line_pos = first;
	while (line_pos)
	{
		col_pos = line_pos->right;
		while (col_pos)
		{
			tmp = col_pos->right;
			free_pos_grid2D(col_pos);
			col_pos = tmp;
		}
		tmp = line_pos->bottom;
		free_pos_grid2D(line_pos);
		line_pos = tmp;
	}
}

t_pos_grid2D	*get_pos_grid2D(t_pos_grid2D *first, int y, int x)
{
	int				i;
	t_pos_grid2D	*target;

	i = 0;
	target = first;
	while (i++ < y)
		target = target->bottom;
	i = 0;
	while (i++ < x)
		target = target->right;
	return (target);
}

t_pos_grid2D	*new_pos_grid2D(t_pos_grid2D *top, t_pos_grid2D *left, t_pos_data *data)
{
	t_pos_grid2D	*new;

	new = malloc(sizeof(t_pos_grid2D));
	if (!new)
		return (NULL);
	new->bottom = NULL;
	new->right = NULL;
	new->left = left;
	new->top = top;
	new->data = data;
	if (left)
		left->right = new;
	if (top)
		top->bottom = new;
	return (new);
}
