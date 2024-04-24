/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 15:56:15 by glions            #+#    #+#             */
/*   Updated: 2024/03/20 12:16:48 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

int	verif_mem(int *mem, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		if (mem[i] != 1)
			return (0);
	return (1);
}

int	verif_mems(t_pos_algo **grid, t_map *m, int size)
{
	int	i;
	int	j;

	i = -1;
	while (++i < m->height)
	{
		j = -1;
		while (++j < m->width)
			if (verif_mem(grid[i][j].mem, size))
				return (1);
	}
	return (0);
}

void	set_mem(int **mem, int id, int size)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		if (i == id)
			(*mem)[i] = 1;
		else
			(*mem)[i] = 0;
	}
}

void	update_mem(int **mem, int id)
{
	(*mem)[id] = 1;
}
