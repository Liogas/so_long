/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:41:13 by glions            #+#    #+#             */
/*   Updated: 2024/03/17 20:09:19 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

void	calc_pos(t_coord *c, int *y, int *x, t_game *g)
{
	*x = ((g->map->width_g - 84) + (40 * c->y)) - (40 * c->x);
	*y = ((g->map->height_g + 20) + (30 * c->y) + (40 * c->x));
}

void	set_size_map(t_game *game)
{
	game->map->width_g = (64 * game->map->width) - (24 * (game->map->width
				- 1));
	game->map->height_g = (64 * game->map->height) - (20 * (game->map->height
				- 1));
}

void	draw_obj(t_game *g, int y, int x, t_draw *data)
{
	put_img_to_img(g->win->bg, g->data_draw->img_object[data->nb_obj], x, y);
	data->nb_obj += 1;
	if (data->nb_obj >= 3)
		data->nb_obj = 0;
}

void	draw_player(t_game *g, int y, int x, int d)
{
	put_img_to_img(g->win->bg, g->data_draw->img_wolf[d], x, y);
}

void	draw_exit(t_game *g, int y, int x)
{
	put_img_to_img(g->win->bg, g->data_draw->img_exit, x, y);
}

void	draw_floor(t_game *g, int y, int x)
{
	put_img_to_img(g->win->bg, g->data_draw->img_floor, x, y);
}

void	draw_exit_player(t_game *g, int y, int x)
{
	put_img_to_img(g->win->bg, g->data_draw->img_exit_player, x, y);
}

void	draw_map(t_game *game)
{
	int	i;
	int	j;
	int	posx;
	int	posy;

	i = -1;
	while (++i < game->map->height)
	{
		posy = 20 * i;
		posx = (game->win->width - 84) - (30 * (game->map->height - i - 1));
		j = game->map->width;
		while (--j >= 0)
		{
			if (game->map->grid[i][j].value == 2)
				draw_obj(game, posy, posx, game->data_draw);
			else if (game->map->grid[i][j].value == 3)
				draw_exit(game, posy, posx);
			else if (game->map->grid[i][j].value == 4)
				draw_player(game, posy, posx, game->data_draw->d_wolf);
			else if (game->map->grid[i][j].value == 0)
				draw_floor(game, posy, posx);
			else if (game->map->grid[i][j].value == 5)
				draw_exit_player(game, posy, posx);
			posx -= 35;
			posy += 20;
		}
	}
}
int	show_map(t_game *game)
{
	if (game->winner)
		return (0);
	game->win->bg = image42_new(game->win->width, game->win->height, game->mlx);
	if (!game->win->bg)
		return (0);
	draw_map(game);
	mlx_put_image_to_window(game->mlx, game->win->win, game->win->bg->ptr, 0,
		0);
	return (1);
}