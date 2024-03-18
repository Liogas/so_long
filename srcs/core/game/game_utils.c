/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 11:05:04 by glions            #+#    #+#             */
/*   Updated: 2024/03/18 16:08:53 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

int	load_img_exit_player(t_game *game)
{
	t_image42	*exit;
	t_image42	*player;
	t_image42	*floor;

	floor = image42_file_new(64, 64, "./srcs/core/img/floor.xpm", game->mlx);
	if (!floor)
		return (0);
	exit = image42_file_new(64, 64, "./srcs/core/imgs/exit.xpm", game->mlx);
	if (!exit)
		return (image42_free(floor), 0);
	player = image42_file_new(64, 64, "./srcs/core/imgs/w_down.xpm", game->mlx);
	if (!player)
		return (image42_free(floor), image42_free(exit), 0);
	put_img_to_img(floor, exit, -2, -8);
	put_img_to_img(floor, player, 0, -10);
	mlx_destroy_image(game->mlx, player->ptr);
	free(player);
	mlx_destroy_image(game->mlx, exit->ptr);
	free(exit);
	game->data_draw->img_exit_player = floor;
	return (1);
}

int	load_img_exit(t_game *game)
{
	t_image42	*img;
	t_image42	*floor;

	floor = image42_file_new(64, 64, "./srcs/core/imgs/floor.xpm", game->mlx);
	if (!floor)
		return (0);
	img = image42_file_new(84, 64, "./srcs/core/imgs/exit.xpm", game->mlx);
	if (!img)
		return (image42_free(floor), 0);
	put_img_to_img(floor, img, -2, -8);
	game->data_draw->img_exit = floor;
	mlx_destroy_image(game->mlx, img->ptr);
	free(img);
	return (1);
}

int	load_img_floor(t_game *game)
{
	t_image42	*img;

	img = image42_file_new(64, 64, "./srcs/core/imgs/floor.xpm", game->mlx);
	if (!img)
		return (0);
	game->data_draw->img_floor = img;
	return (1);
}

t_image42	*load_img_wolf(t_game *game, int id)
{
	t_image42	*floor;
	t_image42	*wolf;

	floor = image42_file_new(64, 64, "./srcs/core/imgs/floor.xpm", game->mlx);
	wolf = NULL;
	if (!floor)
		return (printf("fjeijeijfe\n"), NULL);
	if (id == 0)
		wolf = image42_file_new(64, 64, "./srcs/core/imgs/w_down.xpm", game->mlx);
	else if (id == 1)
		wolf = image42_file_new(64, 64, "./srcs/core/imgs/w_top.xpm", game->mlx);
	else if (id == 2)
		wolf = image42_file_new(64, 64, "./srcs/core/imgs/w_left.xpm", game->mlx);
	else if (id == 3)
		wolf = image42_file_new(64, 64, "./srcs/core/imgs/w_right.xpm", game->mlx);
	if (!wolf)
		return (image42_free(floor), NULL);
	put_img_to_img(floor, wolf, 0, -10);
	mlx_destroy_image(game->mlx, wolf->ptr);
	free(wolf);
	return (floor);
}

int	load_imgs_wolf(t_game *game)
{
	t_image42	**images;

	images = malloc(4 * sizeof(t_image42 *));
	if (!images)
		return (0);
	images[0] = load_img_wolf(game, 0);
	if (!images[0])
		return (imgs_free(images, 4), 0);
	images[1] = load_img_wolf(game, 1);
	if (!images[1])
		return (imgs_free(images, 4), 0);
	images[2] = load_img_wolf(game, 2);
	if (!images[2])
		return (imgs_free(images, 4), 0);
	images[3] = load_img_wolf(game, 3);
	if (!images[3])
		return (imgs_free(images, 4), 0);
	game->data_draw->img_wolf = images;
	return (1);
}

t_image42	*load_img_object(t_game *game, int id)
{
	t_image42	*floor;
	t_image42	*object;

	floor = image42_file_new(64, 64, "./srcs/core/imgs/floor.xpm", game->mlx);
	object = NULL;
	if (!floor)
		return (printf("fjeijeijfe\n"), NULL);
	if (id == 0)
		object = image42_file_new(64, 64, "./srcs/core/imgs/s_1.xpm", game->mlx);
	else if (id == 1)
		object = image42_file_new(64, 64, "./srcs/core/imgs/s_2.xpm", game->mlx);
	else if (id == 2)
		object = image42_file_new(64, 64, "./srcs/core/imgs/s_3.xpm", game->mlx);
	if (!object)
		return (printf("Errreur ehufhwegihug\n"), image42_free(floor), NULL);
	put_img_to_img(floor, object, 16, 0);
	mlx_destroy_image(game->mlx, object->ptr);
	free(object);
	return (floor);
}

int	load_imgs_object(t_game *game)
{
	t_image42	**images;

	images = malloc(3 * sizeof(t_image42 *));
	if (!images)
		return (imgs_free(images, 3), 0);
	images[0] = load_img_object(game, 0);
	if (!images[0])
		return (imgs_free(images, 3), 0);
	images[1] = load_img_object(game, 1);
	if (!images[1])
		return (imgs_free(images, 3), 0);
	images[2] = load_img_object(game, 2);
	if (!images[2])
		return (imgs_free(images, 3), 0);
	game->data_draw->img_object = images;
	return (1);
}

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
		mlx_destroy_display(game->mlx), free(game->mlx);
	free(game);
}

int	key_pressed(int keycode, t_game *g)
{
	if (keycode == XK_d || keycode == XK_D)
		moove(g, 3);
	else if (keycode == XK_a || keycode == XK_a || keycode == XK_q || keycode == XK_Q)
		moove(g, 2);
	else if (keycode == XK_w || keycode == XK_W || keycode == XK_z || keycode == XK_Z)
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

int	load_imgs(t_game *game)
{
	if (!load_img_floor(game))
		return (printf("Erreur chargement image floor\n"), 0);
	if (!load_imgs_object(game))
		return (printf("Erreur chargement image object\n"), 0);
	if (!load_imgs_wolf(game))
		return (printf("Erreur chargement image wolf\n"), 0);
	if (!load_img_exit(game))
		return (printf("Erreur chargement image exit\n"), 0);
	if (!load_img_exit_player(game))
		return (printf("Erreur chargement image exit_player\n"), 0);
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
	new->map = p->map;
	new->data_draw = NULL;
	new->player = NULL;
	set_size_map(new);
	new->win = window42_new(new->mlx, new->map->height_g + 150, new->map->width_g + 150);
	if (!new->win)
		return (game_free(new), NULL);
	new->data_draw = draw_new();
	if (!new->data_draw)
		return (printf("Erreur data_draw\n"), game_free(new), NULL);
	if (!load_imgs(new))
		return (printf("Erreur load_imgs\n"), game_free(new), NULL);
	new->player = new_player(new);
	if (!new->player)
		return (printf("Erreur new_player\n"), game_free(new), NULL);
	new->nb_dep = 0;
	new->winner = 0;
	return (new);
}
