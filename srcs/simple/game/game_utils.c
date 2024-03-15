/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 11:05:04 by glions            #+#    #+#             */
/*   Updated: 2024/03/15 13:39:17 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

int	load_img_exit(t_game *game)
{
	t_image42	*img;

	img = image42_file_new(64, 64, "./srcs/simple/imgs/water.xpm", game->mlx);
	if (!img)
		return (0);
	game->img_exit = img;
	return (1);
}

int	load_img_floor(t_game *game)
{
	t_image42	*img;

	img = image42_file_new(64, 64, "./srcs/simple/imgs/floor.xpm", game->mlx);
	if (!img)
		return (0);
	game->img_floor = img;
	return (1);
}

int	load_imgs_wolf(t_game *game)
{
	t_image42	**images;
	t_image42	*img;

	images = malloc(4 * sizeof(t_image42 *));
	if (!images)
		return (0);
	img = image42_file_new(64, 64, "./srcs/simple/imgs/w_down.xpm", game->mlx);
	if (!img)
		return (0);
	images[0] = img;
	img = image42_file_new(64, 64, "./srcs/simple/imgs/w_left.xpm", game->mlx);
	if (!img)
		return (0);
	images[1] = img;
	img = image42_file_new(64, 64, "./srcs/simple/imgs/w_right.xpm", game->mlx);
	if (!img)
		return (0);
	images[2] = img;
	img = image42_file_new(64, 64, "./srcs/simple/imgs/w_top.xpm", game->mlx);
	if (!img)
		return (0);
	images[3] = img;
	game->img_wolf = images;
	return (1);
}

int	load_imgs_object(t_game *game)
{
	t_image42	**images;
	t_image42	*img;

	images = malloc(3 * sizeof(t_image42 *));
	if (!images)
		return (0);
	img = image42_file_new(64, 64, "./srcs/simple/imgs/s_1.xpm", game->mlx);
	if (!img)
		return (0);
	images[0] = img;
	img = image42_file_new(64, 64, "./srcs/simple/imgs/s_2.xpm", game->mlx);
	if (!img)
		return (0);
	images[1] = img;
	img = image42_file_new(64, 64, "./srcs/simple/imgs/s_3.xpm", game->mlx);
	if (!img)
		return (0);
	images[2] = img;
	game->img_object = images;
	return (1);
}

void	game_free(t_game *game)
{
	if (game->img_object)
		imgs_free(game->img_object, 3, game->draw);
	if (game->img_wolf)
		imgs_free(game->img_wolf, 4, game->draw);
	if (game->img_exit)
		image42_free(game->img_exit, game->draw);
	if (game->img_floor)
		image42_free(game->img_floor, game->draw);
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
	if (keycode == XK_Escape)
		return (mlx_loop_end(g->mlx), 1);
	// else if (keycode == XK_d || keycode == XK_D)
	// 	return (moove_right(g), 1);
	// else if (keycode == XK_a || keycode == XK_a || keycode == XK_q || keycode == XK_Q)
	// 	return (moove_left(g), 1);
	// else if (keycode == XK_w || keycode == XK_W || keycode == XK_z || keycode == XK_Z)
	// 	return (moove_top(g), 1);
	// else if (keycode == XK_s || keycode == XK_S)
	// 	return (moove_down(g), 1);
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
	if (!load_img_floor(new))
		return (printf("Erreur chargement image floor\n"), game_free(new), NULL);
	if (!load_imgs_object(new))
		return (printf("Erreur chargement image object\n"), game_free(new), NULL);
	if (!load_imgs_wolf(new))
		return (printf("Erreur chargement image wolf\n"), game_free(new), NULL);
	if (!load_img_exit(new))
		return (printf("Erreur chargement image exit\n"), game_free(new), NULL);
	new->player = new_player(new);
	if (!new->player)
		return (printf("Erreur new_player\n"), game_free(new), NULL);
	new->draw = 0;
	return (new);
}
