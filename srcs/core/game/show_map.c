/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:41:13 by glions            #+#    #+#             */
/*   Updated: 2024/03/25 16:33:27 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

void	draw_score(t_game *game)
{
	char	*nb;

	nb = ft_itoa(game->nb_dep - 1);
	mlx_string_put(game->mlx, game->win->win, 20, game->win->height - 5,
		0x000000, nb);
	free(nb);
	nb = ft_itoa(game->nb_dep);
	mlx_string_put(game->mlx, game->win->win, 20, game->win->height - 5,
		0xFFFFFF, nb);
	free(nb);
}

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

int	show_map(t_game *game)
{
	int	pos[2];

	if (game->winner)
		return (0);
	game->win->bg = image42_new(game->win->width, game->win->height - 15,
			game->mlx);
	if (!game->win->bg)
		return (0);
	draw_map(game, pos);
	draw_score(game);
	mlx_put_image_to_window(game->mlx, game->win->win, game->win->bg->ptr, 0,
		0);
	return (1);
}
