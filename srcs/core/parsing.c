/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 19:35:32 by glions            #+#    #+#             */
/*   Updated: 2024/03/20 12:18:11 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/parsing.h"

int	check_path(char *path_file)
{
	int	end;

	end = (int)ft_strlen(path_file) - 1;
	if (path_file[end] != 'r' || path_file[end - 1] != 'e' || path_file[end
			- 2] != 'b' || path_file[end - 3] != '.')
		return (0);
	return (1);
}

t_parsing	*parsing(char *path_file)
{
	t_parsing	*data;
	char		*path;

	if (!check_path(path_file))
		return (write(2, "ERROR\nLe fichier doit etre de format '.ber'\n", 44),
			NULL);
	path = "./srcs/core/maps/";
	path = ft_strjoin(path, path_file);
	if (!path)
		return (NULL);
	data = new_parsing(path);
	if (!data)
		return (free(path), NULL);
	if (data->error)
		return (print_error_msg(data->error_msg), free(path), free_parsing(data,
				1), NULL);
	if (!verif_winnable(data))
		return (write(2, "Error\nImpossible de gagner sur cette map\n", 41),
			free_parsing(data, 1), free(path), NULL);
	free(path);
	return (data);
}
