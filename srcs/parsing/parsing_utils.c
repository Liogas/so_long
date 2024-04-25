/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 21:07:16 by glions            #+#    #+#             */
/*   Updated: 2024/04/25 14:39:52 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	c_is_valid(char c)
{
	return (c == '0' || c == '1' || c == 'E' || c == 'C' || c == 'P' || c == 'e'
		|| c == 'c' || c == 'p');
}

int	can_go(int c)
{
	return (c == 0 || (c >= 3 && c <= 5));
}

void	set_start_player(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			if ((map->tab)[i][j] == 3)
			{
				map->player_y = i;
				map->player_x = j;
			}
		}
	}
}

void	fill(int **tab, int size[2], int cur[2])
{
	if (cur[0] < 0 || cur[0] >= size[0] || cur[1] < 0 || cur[1] >= size[1]
		|| !can_go(tab[cur[0]][cur[1]]))
		return ;
	tab[cur[0]][cur[1]] = 9;
	fill(tab, size, (int [2]){cur[0], cur[1] - 1});
	fill(tab, size, (int [2]){cur[0], cur[1] + 1});
	fill(tab, size, (int [2]){cur[0] - 1, cur[1]});
	fill(tab, size, (int [2]){cur[0] + 1, cur[1]});
}
