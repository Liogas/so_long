/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_moove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 17:00:32 by glions            #+#    #+#             */
/*   Updated: 2024/05/10 09:35:08 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	moove_valid(t_map *map, int pos_y, int pos_x, t_game *game)
{
	if (pos_y <= 0 || pos_y >= map->height - 1 || pos_x <= 0
		|| pos_x >= map->width - 1)
		return (0);
	if (map->tab[pos_y][pos_x] == 1 || map->tab[pos_y][pos_x] == 2)
		return (0);
	game->turns++;
	(ft_putstr_fd("Attempts : ", 1), ft_putnbr_fd(game->turns, 1),
		ft_putchar_fd('\n', 1));
	if (map->tab[pos_y][pos_x] == 5)
		game->sheeps--;
	if (map->tab[pos_y][pos_x] == 4)
	{
		if (game->sheeps == 0)
			game->win = 1;
		map->tab[pos_y][pos_x] = 6;
	}
	else
		map->tab[pos_y][pos_x] = 3;
	return (1);
}

int	game_moove_up(t_game *game)
{
	if (!moove_valid(game->map, game->player->pos_y - 1, game->player->pos_x,
			game))
		return (1);
	if (game->map->tab[game->player->pos_y][game->player->pos_x] == 6)
		game->map->tab[game->player->pos_y][game->player->pos_x] = 4;
	else
		game->map->tab[game->player->pos_y][game->player->pos_x] = 0;
	game->player->pos_y = game->player->pos_y - 1;
	return (1);
}

int	game_moove_down(t_game *game)
{
	if (!moove_valid(game->map, game->player->pos_y + 1, game->player->pos_x,
			game))
		return (1);
	if (game->map->tab[game->player->pos_y][game->player->pos_x] == 6)
		game->map->tab[game->player->pos_y][game->player->pos_x] = 4;
	else
		game->map->tab[game->player->pos_y][game->player->pos_x] = 0;
	game->player->pos_y = game->player->pos_y + 1;
	return (1);
}

int	game_moove_left(t_game *game)
{
	if (!moove_valid(game->map, game->player->pos_y, game->player->pos_x - 1,
			game))
		return (1);
	if (game->map->tab[game->player->pos_y][game->player->pos_x] == 6)
		game->map->tab[game->player->pos_y][game->player->pos_x] = 4;
	else
		game->map->tab[game->player->pos_y][game->player->pos_x] = 0;
	game->player->pos_x = game->player->pos_x - 1;
	return (1);
}

int	game_moove_right(t_game *game)
{
	if (!moove_valid(game->map, game->player->pos_y, game->player->pos_x + 1,
			game))
		return (1);
	if (game->map->tab[game->player->pos_y][game->player->pos_x] == 6)
		game->map->tab[game->player->pos_y][game->player->pos_x] = 4;
	else
		game->map->tab[game->player->pos_y][game->player->pos_x] = 0;
	game->player->pos_x = game->player->pos_x + 1;
	return (1);
}
