/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 11:41:21 by glions            #+#    #+#             */
/*   Updated: 2024/03/25 17:46:37 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

static void	draw_player(t_game *g, int y, int x, int d)
{
	put_img_to_img(g->win->bg, g->data_draw->img_wolf[d], x, y);
}

static void	draw_exit(t_game *g, int y, int x)
{
	put_img_to_img(g->win->bg, g->data_draw->img_exit, x, y);
}

static void	draw_floor(t_game *g, int y, int x)
{
	put_img_to_img(g->win->bg, g->data_draw->img_floor, x, y);
}

static void	draw_exit_player(t_game *g, int y, int x)
{
	put_img_to_img(g->win->bg, g->data_draw->img_exit_player, x, y);
}

void	draw_map(t_game *game, int pos[2])
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->map->height)
	{
		pos[0] = 20 * i;
		pos[1] = (game->win->width - 84) - (31 * (game->map->height - (i + 1)));
		j = game->map->width;
		while (--j >= 0)
		{
			if (game->map->grid[i][j].value == 2)
				draw_obj(game, pos[0], pos[1], game->data_draw);
			else if (game->map->grid[i][j].value == 3)
				draw_exit(game, pos[0], pos[1]);
			else if (game->map->grid[i][j].value == 4)
				draw_player(game, pos[0], pos[1], game->data_draw->d_wolf);
			else if (game->map->grid[i][j].value == 0)
				draw_floor(game, pos[0], pos[1]);
			else if (game->map->grid[i][j].value == 5)
				draw_exit_player(game, pos[0], pos[1]);
			pos[0] += 18;
			pos[1] -= 31;
		}
	}
}
