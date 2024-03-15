/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 14:35:05 by glions            #+#    #+#             */
/*   Updated: 2024/03/15 11:37:39 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

void	moove_right(t_game *g)
{
	int	value;

	value = g->map->grid[g->player->pos->y][g->player->pos->x + 1].value;
	if (value != 1)
	{
		if (g->map->grid[g->player->pos->y][g->player->pos->x].value != 5)
			g->map->grid[g->player->pos->y][g->player->pos->x].value = 0;
		else
			g->map->grid[g->player->pos->y][g->player->pos->x].value = 3;
		if (value == 0)
			g->map->grid[g->player->pos->y][g->player->pos->x + 1].value = 4;
		else if (value == 3)
			g->map->grid[g->player->pos->y][g->player->pos->x + 1].value = 5;
		g->player->pos->x += 1;
		mlx_destroy_image(g->mlx, g->win->bg->ptr);
		show_map(g);
	}
}

void	moove_left(t_game *g)
{
	int	value;

	value = g->map->grid[g->player->pos->y][g->player->pos->x - 1].value;
	if (value != 1)
	{
		if (g->map->grid[g->player->pos->y][g->player->pos->x].value != 5)
			g->map->grid[g->player->pos->y][g->player->pos->x].value = 0;
		else
			g->map->grid[g->player->pos->y][g->player->pos->x].value = 3;
		if (value == 0)
			g->map->grid[g->player->pos->y][g->player->pos->x - 1].value = 4;
		else if (value == 3)
			g->map->grid[g->player->pos->y][g->player->pos->x - 1].value = 5;
		g->player->pos->x -= 1;
		mlx_destroy_image(g->mlx, g->win->bg->ptr);
		show_map(g);
	}
}

void	moove_down(t_game *g)
{
	int	value;

	value = g->map->grid[g->player->pos->y + 1][g->player->pos->x].value;
	if (value != 1)
	{
		if (g->map->grid[g->player->pos->y][g->player->pos->x].value != 5)
			g->map->grid[g->player->pos->y][g->player->pos->x].value = 0;
		else
			g->map->grid[g->player->pos->y][g->player->pos->x].value = 3;
		if (value == 0)
			g->map->grid[g->player->pos->y + 1][g->player->pos->x].value = 4;
		else if (value == 3)
			g->map->grid[g->player->pos->y + 1][g->player->pos->x].value = 5;
		g->player->pos->y += 1;
		mlx_destroy_image(g->mlx, g->win->bg->ptr);
		show_map(g);
	}
}

void	moove_top(t_game *g)
{
	int	value;

	value = g->map->grid[g->player->pos->y - 1][g->player->pos->x].value;
	if (value != 1)
	{
		if (g->map->grid[g->player->pos->y][g->player->pos->x].value != 5)
			g->map->grid[g->player->pos->y][g->player->pos->x].value = 0;
		else
			g->map->grid[g->player->pos->y][g->player->pos->x].value = 3;
		if (value == 0)
			g->map->grid[g->player->pos->y - 1][g->player->pos->x].value = 4;
		else if (value == 3)
			g->map->grid[g->player->pos->y - 1][g->player->pos->x].value = 5;
		g->player->pos->y -= 1;
		mlx_destroy_image(g->mlx, g->win->bg->ptr);
		show_map(g);
	}
}

t_player	*new_player(t_game *game)
{
	t_player *new;
	int i;
	int j;

	i = 0;
	j = 0;
	new = malloc(sizeof(t_player));
	if (!new)
		return (NULL);
	new->nb_object = 0;
	i = -1;
	while (++i < game->map->height)
	{
		j = -1;
		while (++j < game->map->width)
		{
			if (game->map->grid[i][j].value == 4)
				new->pos = game->map->grid[i][j].coord;
		}
	}
	return (new);
}