/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 21:54:03 by glions            #+#    #+#             */
/*   Updated: 2024/04/25 14:42:35 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_map *map)
{
	if (!map)
		return ;
	if (map->tab)
		ft_free_tab2d_int_gl(map->tab, map->height);
	free(map);
}

t_map	*new_map(int height, int width)
{
	t_map	*new;
	int		i;

	new = malloc(sizeof(t_map));
	if (!new)
		return (NULL);
	new->width = width;
	new->height = height;
	new->player_x = -1;
	new->player_y = -1;
	new->tab = malloc(height * sizeof(int *));
	if (!new->tab)
		return (free(new), NULL);
	i = -1;
	while (++i < height)
		new->tab[i] = NULL;
	return (new);
}
