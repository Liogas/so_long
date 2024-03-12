/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 11:05:04 by glions            #+#    #+#             */
/*   Updated: 2024/03/12 16:51:18 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

void	game_free(t_game *game)
{
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
	if (keycode == XK_Escape)
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

t_game	*game_new(t_parsing *p)
{
	t_game	*new;

	new = malloc(sizeof(t_game));
	if (!new)
		return (printf("Erreur malloc game_new\n"), NULL);
	new->mlx = mlx_init();
	if (!new->mlx)
		return (printf("Erreur mlx_init\n"), free(new), NULL);
	new->win = window42_new(new->mlx, 1000, 1000);
	if (!new->win)
		return (game_free(new), NULL);
	new->map = p->map;
	return (new);
}
