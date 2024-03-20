/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_imgs2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 09:21:53 by glions            #+#    #+#             */
/*   Updated: 2024/03/20 12:13:47 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

static t_image42	*load_img_object(t_game *game, int id)
{
	t_image42	*floor;
	t_image42	*object;

	floor = image42_file_new(64, 64, "./srcs/core/imgs/floor.xpm", game->mlx);
	object = NULL;
	if (!floor)
		return (NULL);
	if (id == 0)
		object = image42_file_new(64, 64, "./srcs/core/imgs/s_1.xpm",
				game->mlx);
	else if (id == 1)
		object = image42_file_new(64, 64, "./srcs/core/imgs/s_2.xpm",
				game->mlx);
	else if (id == 2)
		object = image42_file_new(64, 64, "./srcs/core/imgs/s_3.xpm",
				game->mlx);
	if (!object)
		return (image42_free(floor), NULL);
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
		return (0);
	images[0] = NULL;
	images[1] = NULL;
	images[2] = NULL;
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

static t_image42	*load_img_wolf(t_game *game, int id)
{
	t_image42	*floor;
	t_image42	*wolf;

	floor = image42_file_new(64, 64, "./srcs/core/imgs/floor.xpm", game->mlx);
	wolf = NULL;
	if (!floor)
		return (NULL);
	if (id == 0)
		wolf = image42_file_new(64, 64, "./srcs/core/imgs/w_down.xpm",
				game->mlx);
	else if (id == 1)
		wolf = image42_file_new(64, 64, "./srcs/core/imgs/w_top.xpm",
				game->mlx);
	else if (id == 2)
		wolf = image42_file_new(64, 64, "./srcs/core/imgs/w_left.xpm",
				game->mlx);
	else if (id == 3)
		wolf = image42_file_new(64, 64, "./srcs/core/imgs/w_right.xpm",
				game->mlx);
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
	images[0] = NULL;
	images[1] = NULL;
	images[2] = NULL;
	images[3] = NULL;
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
