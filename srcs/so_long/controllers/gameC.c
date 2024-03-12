/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameC.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:37:42 by glions            #+#    #+#             */
/*   Updated: 2024/01/12 22:54:10 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	game(int fd_map, char *path_file)
{
	t_game		*game;

	game = new_game(fd_map, path_file);
	if (!game)
		return (1);
	show_data_map(game->map);
	show_data_objects(game->objects);
	show_data_player(game->player);
	if (!validator_solong(game))
		return (free_game(game), (1));
	game->state = 1;
	while (game->state == 0)
	{
		ft_printf("Debut du tour->%d\n", game->turn);
		game->state = new_turn(&game);
		show_data_map(game->map);
		show_data_objects(game->objects);
		show_data_player(game->player);
		game->turn += 1;
	}
	free_game(game);
	return (0);
}
