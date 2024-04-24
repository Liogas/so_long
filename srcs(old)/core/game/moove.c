/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 09:45:54 by glions            #+#    #+#             */
/*   Updated: 2024/03/26 14:03:09 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

static int	moove_right(t_game *g)
{
	if (g->map->grid[g->player->pos->y][g->player->pos->x + 1].value != 1)
	{
		if (g->map->grid[g->player->pos->y][g->player->pos->x].value != 5)
			g->map->grid[g->player->pos->y][g->player->pos->x].value = 0;
		else
			g->map->grid[g->player->pos->y][g->player->pos->x].value = 3;
		if (g->map->grid[g->player->pos->y][g->player->pos->x + 1].value == 0)
			g->map->grid[g->player->pos->y][g->player->pos->x + 1].value = 4;
		else if (g->map->grid[g->player->pos->y][g->player->pos->x
			+ 1].value == 2)
			g->map->grid[g->player->pos->y][g->player->pos->x + 1].value = 4;
		else if (g->map->grid[g->player->pos->y][g->player->pos->x
			+ 1].value == 3)
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

static int	moove_left(t_game *g)
{
	if (g->map->grid[g->player->pos->y][g->player->pos->x - 1].value != 1)
	{
		if (g->map->grid[g->player->pos->y][g->player->pos->x].value != 5)
			g->map->grid[g->player->pos->y][g->player->pos->x].value = 0;
		else
			g->map->grid[g->player->pos->y][g->player->pos->x].value = 3;
		if (g->map->grid[g->player->pos->y][g->player->pos->x - 1].value == 0)
			g->map->grid[g->player->pos->y][g->player->pos->x - 1].value = 4;
		else if (g->map->grid[g->player->pos->y][g->player->pos->x
			- 1].value == 2)
			g->map->grid[g->player->pos->y][g->player->pos->x - 1].value = 4;
		else if (g->map->grid[g->player->pos->y][g->player->pos->x
			- 1].value == 3)
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

static int	moove_down(t_game *g)
{
	if (g->map->grid[g->player->pos->y + 1][g->player->pos->x].value != 1)
	{
		if (g->map->grid[g->player->pos->y][g->player->pos->x].value != 5)
			g->map->grid[g->player->pos->y][g->player->pos->x].value = 0;
		else
			g->map->grid[g->player->pos->y][g->player->pos->x].value = 3;
		if (g->map->grid[g->player->pos->y + 1][g->player->pos->x].value == 0)
			g->map->grid[g->player->pos->y + 1][g->player->pos->x].value = 4;
		else if (g->map->grid[g->player->pos->y
				+ 1][g->player->pos->x].value == 2)
			g->map->grid[g->player->pos->y + 1][g->player->pos->x].value = 4;
		else if (g->map->grid[g->player->pos->y
				+ 1][g->player->pos->x].value == 3)
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

static int	moove_top(t_game *g)
{
	if (g->map->grid[g->player->pos->y - 1][g->player->pos->x].value != 1)
	{
		if (g->map->grid[g->player->pos->y][g->player->pos->x].value != 5)
			g->map->grid[g->player->pos->y][g->player->pos->x].value = 0;
		else
			g->map->grid[g->player->pos->y][g->player->pos->x].value = 3;
		if (g->map->grid[g->player->pos->y - 1][g->player->pos->x].value == 0)
			g->map->grid[g->player->pos->y - 1][g->player->pos->x].value = 4;
		else if (g->map->grid[g->player->pos->y
				- 1][g->player->pos->x].value == 2)
			g->map->grid[g->player->pos->y - 1][g->player->pos->x].value = 4;
		else if (g->map->grid[g->player->pos->y
				- 1][g->player->pos->x].value == 3)
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
	int	res;

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
			(ft_putstr_fd("GOOD JOB (", 1), ft_putnbr_fd(g->nb_dep, 1),
				ft_putstr_fd(")\n", 1));
		else
		{
			if (BONUS == 0)
				(ft_putnbr_fd(g->nb_dep, 1), ft_putchar_fd('\n', 1));
			(image42_free(g->win->bg), show_map(g));
		}
	}
}
