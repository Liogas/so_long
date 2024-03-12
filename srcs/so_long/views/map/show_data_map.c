/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_data_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 01:27:40 by glions            #+#    #+#             */
/*   Updated: 2024/01/04 10:04:38 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	show_grid_map(t_map *map)
{
	int	i;
	int	j;

	ft_printf("Grid :\n");
	i = -1;
	while (++i < map->height)
	{
		j = 0;
		while (j < map->width)
			ft_printf("%2d", map->grid[i][j++]);
		ft_printf("\n");
	}
}

void	show_data_map(t_map *map)
{
	if (map->path_file)
		ft_printf("Path_file->|%s|\n", map->path_file);
	if (map->fd)
		ft_printf("FD->%d\n", map->fd);
	ft_printf("Width->%d\n", map->width);
	ft_printf("Height->%d\n", map->height);
	if (map->grid)
		show_grid_map(map);
	else
		ft_printf("Grid->NULL");
}
