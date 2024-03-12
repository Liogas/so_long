/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fileC.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:37:18 by glions            #+#    #+#             */
/*   Updated: 2024/01/02 10:17:46 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	open_map(char *path_file)
{
	int	fd;

	fd = open(path_file, O_RDONLY);
	return (fd);
}

static int	nb_line_on(t_map **map)
{
	char	*line;
	int		i;

	line = NULL;
	i = 0;
	while (i == 0 || line)
	{
		if (line)
			free(line);
		line = get_next_line((*map)->fd);
		if (line)
			i++;
	}
	close((*map)->fd);
	(*map)->fd = open_map((*map)->path_file);
	return (i);
}

char	**read_map(t_map **map)
{
	int		j;
	char	**lines_map;

	(*map)->height = nb_line_on(map);
	if ((*map)->fd < 0)
		return (NULL);
	lines_map = malloc(((*map)->height + 1) * sizeof(char *));
	if (!lines_map)
		return (perror("ERROR_OPEN"), (NULL));
	j = -1;
	while (++j < (*map)->height)
	{
		lines_map[j] = get_next_line((*map)->fd);
		if (!lines_map[j])
			return (free_lines(lines_map), (NULL));
		if (j == 0)
			(*map)->width = (int)ft_strlen(lines_map[j]) - 1;
		else if ((j != (*map)->height - 1
				&& (*map)->width != (int)ft_strlen(lines_map[j]) - 1)
			|| (j == (*map)->height - 1
				&& (*map)->width != (int)ft_strlen(lines_map[j])))
			return (free_lines(lines_map), (NULL));
	}
	lines_map[j] = NULL;
	return (lines_map);
}
