/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 19:35:32 by glions            #+#    #+#             */
/*   Updated: 2024/03/11 12:35:51 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/parsing.h"

int	check_path(char *path_file)
{
	int	end;

	end = (int)ft_strlen(path_file) - 1;
	if (path_file[end] != 'r' || path_file[end - 1] != 'e'
		|| path_file[end - 2] != 'b' || path_file[end - 3] != '.')
		return (0);
	return (1);
}

t_parsing	*parsing(char *path_file)
{
	t_parsing	*data;

	if (!check_path(path_file))
		return (write(2, "ERROR\nLe fichier doit etre de format '.ber'\n", 44),
			NULL);
	data = new_parsing(path_file);
	if (!data)
		return (NULL);
	if (data->error)
		return (print_error_msg(data->error_msg), free_parsing(data), NULL);
	if (!verif_winnable(data))
		return (write(2, "Error\nImpossible de gagner sur cette map\n", 41),
			free_parsing(data), NULL);
	return (data);
}
