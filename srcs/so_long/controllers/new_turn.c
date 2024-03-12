/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_turn.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 15:39:58 by glions            #+#    #+#             */
/*   Updated: 2024/01/04 14:50:19 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static char	get_direction(void)
{
	char	input;

	input = 'd';
	while (input != 'U' && input != 'D'
		&& input != 'L' && input != 'R')
	{
		ft_printf("Type direction : D or R or L or U\n");
		scanf("%c", &input);
	}
	return (input);
}

static int	verif_exit(t_player *player, t_object *objects)
{
	while (objects)
	{
		if (objects->id_player != player->id)
			return (ft_printf("Tous les objets n'ont pas ete recuperes\n"),
				(0));
		objects = objects->next;
	}
	return (1);
}

static int	test_move(char direction, t_player *player, t_map *map,
			t_object *objects)
{
	if (direction == 'U' && (map->grid[player->y - 1][player->x] == 1
		|| (map->grid[player->y - 1][player->x] == 4
		&& !verif_exit(player, objects))))
		return (ft_printf("Mouvement vers le haut impossible\n"), (0));
	else if (direction == 'D' && (map->grid[player->y + 1][player->x] == 1
		|| (map->grid[player->y + 1][player->x] == 4
		&& !verif_exit(player, objects))))
		return (ft_printf("Mouvement vers le bas impossible\n"), (0));
	else if (direction == 'L' && (map->grid[player->y][player->x - 1] == 1
		|| (map->grid[player->y][player->x - 1] == 4
		&& !verif_exit(player, objects))))
		return (ft_printf("Mouvement vers la gauche impossible\n"), (0));
	else if (direction == 'R' && (map->grid[player->y][player->x + 1] == 1
		|| (map->grid[player->y + 1][player->x + 1] == 4
		&& !verif_exit(player, objects))))
		return (ft_printf("Mouvement vers la droite impossible\n"), (0));
	return (1);
}

int	new_turn(t_game **game)
{
	char	direction;
	int		step;

	step = 0;
	while (step == 0)
	{
		direction = get_direction();
		step += test_move(direction,
				(*game)->player, (*game)->map, (*game)->objects);
	}
	move_player(direction, &(*game)->player);
	verif_object(&(*game)->objects, (*game)->player);
	if ((*game)->map->grid[(*game)->player->y][(*game)->player->x] == 4)
		return (ft_printf("Partie gagnee\n"), (1));
	update_grid(&(*game)->map->grid, direction, (*game)->player);
	return (0);
}
