/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_data_file42.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 17:40:31 by glions            #+#    #+#             */
/*   Updated: 2024/02/09 10:56:13 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/file42.h"

void	show_data_file42(t_file42 *file, char *title)
{
	t_list	*tmp_lines;
	int		i;
	
	if (title)
		ft_printf("%s\n", title);
	ft_printf("pathfile->|%s|\n", file->pathfile);
	ft_printf("fd->%d\n", file->fd);
	ft_printf("nblines->%d\n", file->nblines);
	tmp_lines = file->lines;
	i = 1;
	ft_printf("--Lines--\n");
	while (tmp_lines)
	{
		ft_printf("[%d]->|%s|\n", i, tmp_lines->content);
		tmp_lines = tmp_lines->next;
		i++;
	}
}
