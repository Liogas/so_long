/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_drawimages.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 21:25:31 by glions            #+#    #+#             */
/*   Updated: 2024/04/29 16:07:29 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	graph_drawplayer(int pos[2], t_game *game, t_mlx_image_gl *dst)
{
	t_mlx_image_gl		*image;
	t_mlx_object_gl		*object;
	t_mlx_animation_gl	*animation;

	image = mlx_get_image_by_name_gl(game->graph_data, "floor");
	if (!image)
		return (0);
	mlx_image_put_area_image_gl(dst, image, (int [2]){pos[0] * 192, pos[1]
		* 192}, (int [2]){192, 192});
	object = mlx_get_object_by_name_gl(game->graph_data, "player");
	if (!object)
		return (0);
	if (ft_strcmp(object->curr_anim, "player_moove") != 0)
		update_pos_player(game->player, pos[0] * 192, pos[1] * 192, object);
	animation = mlx_get_animation_by_name_gl(game->graph_data, object->name,
			object->curr_anim);
	if (!animation)
		return (0);
	mlx_animation_put_to_img_gl(game->graph_data, object, animation, dst);
	return (1);
}

int	graph_drawwall(int y, int x, t_game *game, t_mlx_image_gl *dst)
{
	t_mlx_image_gl		*image;
	t_mlx_object_gl		*object;
	t_mlx_animation_gl	*animation;

	image = mlx_get_image_by_name_gl(game->graph_data, "floor");
	if (!image)
		return (0);
	mlx_image_put_area_image_gl(dst, image, (int [2]){y * 192, x * 192},
		(int [2]){192, 192});
	object = mlx_get_object_by_name_gl(game->graph_data, "tree");
	if (!object)
		return (0);
	object->pos_y = 192 * y - 50;
	object->pos_x = 192 * x - 50;
	animation = mlx_get_animation_by_name_gl(game->graph_data, object->name,
			object->curr_anim);
	if (!animation)
		return (0);
	mlx_animation_put_to_img_gl(game->graph_data, object, animation, dst);
	object->pos_y = 192 * y + 10;
	object->pos_x = 192 * x + 20;
	mlx_animation_put_to_img_gl(game->graph_data, object, animation, dst);
	return (1);
}

int	graph_drawexit(int y, int x, t_game *game, t_mlx_image_gl *dst)
{
	t_mlx_image_gl	*image;

	image = mlx_get_image_by_name_gl(game->graph_data, "floor");
	if (!image)
		return (0);
	mlx_image_put_area_image_gl(dst, image, (int [2]){y * 192, x * 192},
		(int [2]){192, 192});
	image = mlx_get_image_by_name_gl(game->graph_data, "tower");
	if (!image)
		return (0);
	mlx_image_put_area_image_gl(dst, image, (int [2]){y * 192 - 128, x * 192
		+ 32}, (int [2]){128, 256});
	return (1);
}

int	graph_drawcollect(int y, int x, t_game *game, t_mlx_image_gl *dst)
{
	t_mlx_image_gl		*image;
	t_mlx_object_gl		*object;
	t_mlx_animation_gl	*animation;

	image = mlx_get_image_by_name_gl(game->graph_data, "floor");
	if (!image)
		return (0);
	mlx_image_put_area_image_gl(dst, image, (int [2]){y * 192, x * 192},
		(int [2]){192, 192});
	object = mlx_get_object_by_name_gl(game->graph_data, "sheep");
	if (!object)
		return (0);
	animation = mlx_get_animation_by_name_gl(game->graph_data, object->name,
			object->curr_anim);
	if (!animation)
		return (0);
	object->pos_x = 192 * x;
	object->pos_y = 192 * y;
	mlx_animation_put_to_img_gl(game->graph_data, object, animation, dst);
	return (1);
}

int	graph_drawfloor(int y, int x, t_game *game, t_mlx_image_gl *dst)
{
	t_mlx_image_gl	*image;

	image = mlx_get_image_by_name_gl(game->graph_data, "floor");
	if (!image)
		return (0);
	mlx_image_put_area_image_gl(dst, image, (int [2]){y * 192, x * 192},
		(int [2]){192, 192});
	return (1);
}
