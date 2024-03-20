/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 11:05:04 by glions            #+#    #+#             */
/*   Updated: 2024/03/20 12:19:18 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

void	game_free(t_game *game)
{
	if (game->data_draw)
		draw_free(game->data_draw);
	if (game->player)
		free(game->player);
	if (game->map)
		free_map(game->map);
	if (game->win)
		window42_free(game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	free(game);
}

int	key_pressed(int keycode, t_game *g)
{
	if (keycode == XK_d || keycode == XK_D)
		moove(g, 3);
	else if (keycode == XK_a || keycode == XK_a || keycode == XK_q
		|| keycode == XK_Q)
		moove(g, 2);
	else if (keycode == XK_w || keycode == XK_W || keycode == XK_z
		|| keycode == XK_Z)
		moove(g, 0);
	else if (keycode == XK_s || keycode == XK_S)
		moove(g, 1);
	if (keycode == XK_Escape || g->winner)
		return (mlx_loop_end(g->mlx), 1);
	return (1);
}

int	game_start(t_game *g)
{
	if (!show_map(g))
		return (0);
	mlx_key_hook(g->win->win, &key_pressed, g);
	mlx_loop(g->mlx);
	return (1);
}

int	game_setup(t_game *g)
{
	set_size_map(g);
	g->win = window42_new(g->mlx, g->map->height_g + 150, g->map->width_g
			+ 150);
	if (!g->win)
		return (game_free(g), 0);
	g->data_draw = draw_new();
	if (!g->data_draw)
		return (game_free(g), 0);
	if (!load_imgs(g))
		return (game_free(g), 0);
	g->player = new_player(g);
	if (!g->player)
		return (game_free(g), 0);
	return (1);
}

t_game	*game_new(t_parsing *p)
{
	t_game	*new;

	new = malloc(sizeof(t_game));
	if (!new)
		return (NULL);
	new->mlx = mlx_init();
	if (!new->mlx)
		return (ft_putstr_fd("Connexion with mlx failed\n", 2), free(new),
			NULL);
	new->map = p->map;
	new->data_draw = NULL;
	new->player = NULL;
	new->nb_dep = 0;
	new->winner = 0;
	if (!game_setup(new))
		return (NULL);
	return (new);
}
