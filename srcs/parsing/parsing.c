/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 20:44:02 by glions            #+#    #+#             */
/*   Updated: 2024/04/24 23:08:38 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	verif_nb_objects(t_map *map)
{
	int	i;
	int	j;
	int	obj[3];

	obj[0] = 0;
	obj[1] = 0;
	obj[2] = 0;
	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			if ((map->tab)[i][j] == 3)
				obj[0]++;
			else if ((map->tab)[i][j] == 4)
				obj[1]++;
			else if ((map->tab)[i][j] == 5)
				obj[2]++;
		}
	}
	if (obj[0] != 1 || obj[1] != 1 || obj[2] <= 0)
		return (ft_putstr_fd("ERROR : duplicate values\n", 2), 0);
	return (1);
}

static int	conv_value(char c, int nb, int i, int size[2])
{
	if (!c_is_valid(c))
		return (-1);
	if (nb == 0 && nb == size[0] - 1 && i == 0 && i == size[1] && c == '1')
		return (1);
	else if (c == '1')
		return (2);
	else if (c == '0')
		return (0);
	else if (c == 'P')
		return (3);
	else if (c == 'E')
		return (4);
	else if (c == 'C')
		return (5);
	return (-1);
}

static int	verif_line(int ***tab, char *line, t_file_gl *file)
{
	static int	nb;
	static int	width;
	int			line_size;
	int			i;

	line_size = ft_strlen_stop_c(line, '\n');
	if ((width == 0 && line_size == 0) || (width != 0 && line_size != width))
		return (ft_putstr_fd("ERROR : map not rectangle\n", 2), 0);
	width = line_size;
	(*tab)[nb] = malloc(width * sizeof(int));
	if (!(*tab)[nb])
		return (ft_putstr_fd("ERROR : malloc tab(verif_line)\n", 2), 0);
	i = -1;
	while (line[++i] && line[i] != '\n')
	{
		if (((nb == 0 || nb == file->nblines - 1) && line[i] != '1') || ((i == 0
					|| i == line_size - 1) && line[i] != '1'))
			return (ft_putstr_fd("ERROR : border invalid\n", 2), 0);
		(*tab)[nb][i] = conv_value(line[i], nb, i, (int[2]){file->nblines,
				width});
		if ((*tab)[nb][i] == -1)
			return (ft_putstr_fd("ERROR : invalid value on map\n", 2), 0);
	}
	nb++;
	return (1);
}

t_map	*parsing(t_map *map, t_file_gl *file)
{
	t_list_gl	*line;

	line = file->lines;
	while (line)
	{
		if (!verif_line(&map->tab, line->content, file))
			return (free_map(map), free_file_gl(file), NULL);
		line = line->next;
	}
	if (!verif_nb_objects(map))
		return (free_map(map), free_file_gl(file), NULL);
	return (free_file_gl(file), map);
}
