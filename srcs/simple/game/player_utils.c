/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 14:35:05 by glions            #+#    #+#             */
/*   Updated: 2024/03/17 22:11:43 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

void	verif_win(t_game *g)
{
	int	i;
	int	j;

	i = -1;
	while (++i < g->map->height)
	{
		j = -1;
		while (++j < g->map->width)
			if (g->map->grid[i][j].value == 2)
				return ;
	}
	g->winner = 1;
}

int	moove_right(t_game *g)
{
	if (g->map->grid[g->player->pos->y][g->player->pos->x + 1].value != 1)
	{
		if (g->map->grid[g->player->pos->y][g->player->pos->x].value != 5)
			g->map->grid[g->player->pos->y][g->player->pos->x].value = 0;
		else
			g->map->grid[g->player->pos->y][g->player->pos->x].value = 3;
		if (g->map->grid[g->player->pos->y][g->player->pos->x + 1].value == 0)
			g->map->grid[g->player->pos->y][g->player->pos->x + 1].value = 4;
		else if (g->map->grid[g->player->pos->y][g->player->pos->x + 1].value == 2)
		{
			g->map->grid[g->player->pos->y][g->player->pos->x + 1].value = 4;
			g->nb_obj += 1;
		}
		else if (g->map->grid[g->player->pos->y][g->player->pos->x + 1].value == 3)
		{
			g->map->grid[g->player->pos->y][g->player->pos->x + 1].value = 5;
			verif_win(g);
		}
		g->player->pos->x += 1;
		g->data_draw->d_wolf = 3;
		return (1);
	}
	return (0);
}

int	moove_left(t_game *g)
{
	if (g->map->grid[g->player->pos->y][g->player->pos->x - 1].value != 1)
	{
		if (g->map->grid[g->player->pos->y][g->player->pos->x].value != 5)
			g->map->grid[g->player->pos->y][g->player->pos->x].value = 0;
		else
			g->map->grid[g->player->pos->y][g->player->pos->x].value = 3;
		if (g->map->grid[g->player->pos->y][g->player->pos->x - 1].value == 0)
			g->map->grid[g->player->pos->y][g->player->pos->x - 1].value = 4;
		else if (g->map->grid[g->player->pos->y][g->player->pos->x - 1].value == 2)
		{
			g->map->grid[g->player->pos->y][g->player->pos->x - 1].value = 4;
			g->nb_obj += 1;
		}
		else if (g->map->grid[g->player->pos->y][g->player->pos->x - 1].value == 3)
		{
			g->map->grid[g->player->pos->y][g->player->pos->x - 1].value = 5;
			verif_win(g);
		}
		g->player->pos->x -= 1;
		g->data_draw->d_wolf = 2;
		return (1);
	}
	return (0);
}

int	moove_down(t_game *g)
{
	if (g->map->grid[g->player->pos->y + 1][g->player->pos->x].value != 1)
	{
		if (g->map->grid[g->player->pos->y][g->player->pos->x].value != 5)
			g->map->grid[g->player->pos->y][g->player->pos->x].value = 0;
		else
			g->map->grid[g->player->pos->y][g->player->pos->x].value = 3;
		if (g->map->grid[g->player->pos->y + 1][g->player->pos->x].value == 0)
			g->map->grid[g->player->pos->y + 1][g->player->pos->x].value = 4;
		else if (g->map->grid[g->player->pos->y + 1][g->player->pos->x].value == 2)
		{
			g->map->grid[g->player->pos->y + 1][g->player->pos->x].value = 4;
			g->nb_obj += 1;
		}
		else if (g->map->grid[g->player->pos->y + 1][g->player->pos->x].value == 3)
		{
			g->map->grid[g->player->pos->y + 1][g->player->pos->x].value = 5;
			verif_win(g);
		}
		g->player->pos->y += 1;
		g->data_draw->d_wolf = 0;
		return (1);
	}
	return (0);
}

int	moove_top(t_game *g)
{
	if (g->map->grid[g->player->pos->y - 1][g->player->pos->x].value != 1)
	{
		if (g->map->grid[g->player->pos->y][g->player->pos->x].value != 5)
			g->map->grid[g->player->pos->y][g->player->pos->x].value = 0;
		else
			g->map->grid[g->player->pos->y][g->player->pos->x].value = 3;
		if (g->map->grid[g->player->pos->y - 1][g->player->pos->x].value == 0)
			g->map->grid[g->player->pos->y - 1][g->player->pos->x].value = 4;
		else if (g->map->grid[g->player->pos->y - 1][g->player->pos->x].value == 2)
		{
			g->map->grid[g->player->pos->y - 1][g->player->pos->x].value = 4;
			g->nb_obj += 1;
		}
		else if (g->map->grid[g->player->pos->y - 1][g->player->pos->x].value == 3)
		{
			g->map->grid[g->player->pos->y - 1][g->player->pos->x].value = 5;
			verif_win(g);
		}
		g->player->pos->y -= 1;
		g->data_draw->d_wolf = 1;
		return (1);
	}
	return (0);
}

void	moove(t_game *g, int dir)
{
	int res;
	
	res = 0;
	if (dir == 0)
		res = moove_top(g);
	else if (dir == 1)
		res = moove_down(g);
	else if (dir == 2)
		res = moove_left(g);
	else if (dir == 3)
		res = moove_right(g);
	if (res)
	{
		g->nb_dep += 1;
		if (g->winner)
			printf("BRAVO ! gagne en %d deplacements\n", g->nb_dep);
		else
		{
			printf("Nombre de deplacement : %d\n", g->nb_dep);
			image42_free(g->win->bg);
			show_map(g);
		}
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