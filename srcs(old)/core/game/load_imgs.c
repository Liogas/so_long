/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_imgs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 09:20:03 by glions            #+#    #+#             */
/*   Updated: 2024/03/20 10:39:57 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

int	load_img_food(t_game *game)
{
	t_image42	*food;

	food = image42_file_new(16, 16, "./srcs/core/imgs/food.xpm", game->mlx);
	if (!food)
		return (0);
	game->data_draw->img_food = food;
	return (1);
}

int	load_img_exit_player(t_game *game)
{
	t_image42	*exit;
	t_image42	*player;
	t_image42	*floor;

	floor = image42_file_new(64, 64, "./srcs/core/imgs/floor.xpm", game->mlx);
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

int	load_imgs(t_game *game)
{
	if (!load_img_floor(game))
		return (ft_putstr_fd("Can't load floor\n", 2), 0);
	if (!load_imgs_object(game))
		return (ft_putstr_fd("Can't  load objects\n", 2), 0);
	if (!load_imgs_wolf(game))
		return (ft_putstr_fd("Can't load players\n", 2), 0);
	if (!load_img_exit(game))
		return (ft_putstr_fd("Can't load exit\n", 2), 0);
	if (!load_img_exit_player(game))
		return (ft_putstr_fd("Can't load exit with player\n", 2), 0);
	if (!load_img_food(game))
		return (ft_putstr_fd("Can't load food\n", 2), 0);
	return (1);
}
