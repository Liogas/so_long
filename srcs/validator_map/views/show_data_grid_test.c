/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_data_grid_test.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 18:49:57 by glions            #+#    #+#             */
/*   Updated: 2024/02/13 12:58:40 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/validator_map.h"

void	show_data_grid_test(t_validator_map *v)
{
	int				i;
	int				j;
	t_pos_grid2D	*pos;
	t_pos_grid2D	*top;

	if (!v->pos)
	{
		ft_printf("AUCUNE GRILLE\n");
		return ;
	}
	i = -1;
	pos = v->pos;
	while (++i < v->map_h)
	{
		top = pos;
		j = -1;
		while (++j < v->map_w)
		{
			if (pos)
				show_data_pos_grid(pos);
			else
				ft_printf("GRID[%d][%d]-> NULL\n", i, j);
			pos = pos->right;
		}
		pos = top->bottom;
	}
}
