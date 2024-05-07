/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_drawimages2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 17:52:01 by glions            #+#    #+#             */
/*   Updated: 2024/05/07 14:08:23 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	graph_draw_exit_player(int y, int x, t_game *game, t_mlx_image_gl *dst)
{
	t_mlx_image_gl	*image;
	t_mlx_object_gl	*object;

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
	object = mlx_get_object_by_name_gl(game->graph_data, "player");
	if (!object)
		return (0);
	if (game->win)
		update_pos_player(game->player, y * 192 - 150, x * 192, object);
	else
		update_pos_player(game->player, y * 192, x * 192, object);
	mlx_animation_put_to_img_gl(game->graph_data, object,
		mlx_get_animation_by_name_gl(game->graph_data, object->name,
			object->curr_anim), dst);
	return (1);
}
