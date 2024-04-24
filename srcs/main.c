/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 19:41:10 by glions            #+#    #+#             */
/*   Updated: 2024/04/24 23:00:55 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	init_game(t_map *map)
{
	if (!map)
		return (0);
	free_map(map);
	return (1);
}

int	main(int ac, char **av)
{
	t_map		*map;
	t_file_gl	*file;

	if (ac != 2)
		return (ft_putstr_fd("ERROR : try ./so_long [map_name]\n", 2), 1);
	if (!verif_extension(av[1], ".ber"))
		return (ft_putstr_fd("ERROR : Extension not valid. try ?.ber\n", 2), 1);
	file = new_file_gl(av[1], O_RDONLY);
	if (!file)
		return (ft_putstr_fd("ERROR : file doesn't exist\n", 2), 0);
	read_all_file_gl(file);
	if (!file->lines)
		return (ft_putstr_fd("ERROR : file empty\n", 2), free_file_gl(file), 1);
	map = new_map(file->nblines, ft_strlen_stop_c((char *)file->lines->content,
				'\n'));
	if (!map)
		return (ft_putstr_fd("ERROR : new_map\n", 2), free_file_gl(file), 1);
	if (!init_game(parsing(map, file)))
		return (ft_putstr_fd("ERROR : init_game\n", 2), 1);
	return (0);
}
