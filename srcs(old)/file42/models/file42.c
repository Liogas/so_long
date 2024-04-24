/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file42.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 14:36:45 by glions            #+#    #+#             */
/*   Updated: 2024/03/07 11:49:24 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/file42.h"

void	free_file42(t_file42 *file)
{
	close(file->fd);
	if (file)
		ft_lstclear(&file->lines, free);
	free(file);
}

t_file42	*new_file42(char *pathfile, int __oflag)
{
	t_file42	*new;

	new = malloc(sizeof(t_file42));
	if (!new)
		return (NULL);
	new->pathfile = pathfile;
	new->fd = open(pathfile, __oflag);
	if (new->fd < 0)
		return (free(new), (NULL));
	new->lines = NULL;
	new->nblines = 0;
	return (new);
}

int	read_nextline_file42(t_file42 *file)
{
	char	*line;

	line = get_next_line(file->fd);
	if (!line)
		return (0);
	ft_lstadd_back(&file->lines, ft_lstnew(line));
	file->nblines += 1;
	return (1);
}

void	read_all_file42(t_file42 *file)
{
	int		while_state;
	
	while_state = 1;
	while (while_state)
		while_state = read_nextline_file42(file);
}
