/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_addimages.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:44:27 by glions            #+#    #+#             */
/*   Updated: 2024/05/04 16:55:19 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	graph_addborder(t_game *game)
{
	if (!mlx_addobject_gl(game->graph_data,
			mlx_create_object_gl("water_animation", 0, 0, NULL)))
		return (0);
	if (!mlx_addimage_gl(game->graph_data, mlx_load_img_gl(game->graph_data,
				"./srcs/sprites/water/water_animation.xpm", "water_animation")))
		return (0);
	if (!mlx_addsprite_gl(game->graph_data, "water_animation",
			mlx_create_sprite_gl("water_default", 0, 8, (int [2]){192, 192})))
		return (0);
	if (!mlx_addanimation_gl(game->graph_data, "water_animation",
			"water_animation",
			mlx_create_animation_gl(mlx_get_image_by_name_gl(game->graph_data,
					"water_animation"), "water_animation", 3)))
		return (0);
	if (!mlx_addimage_gl(game->graph_data, mlx_load_img_gl(game->graph_data,
				"./srcs/sprites/water/water.xpm", "water")))
		return (0);
	if (!mlx_object_set_curr_animation_gl(game->graph_data, "water_animation",
			"water_animation"))
		return (0);
	return (1);
}

int	graph_addplayer(t_game *game)
{
	if (!mlx_addobject_gl(game->graph_data, mlx_create_object_gl("player", 0, 0,
				game->player)) || !mlx_addimage_gl(game->graph_data,
			mlx_load_img_gl(game->graph_data, "./srcs/sprites/player.xpm",
				"player")))
		return (0);
	if (!mlx_addsprite_gl(game->graph_data, "player",
			mlx_create_sprite_gl("player_default", 0, 6, (int [2]){192, 192}))
		|| !mlx_addsprite_gl(game->graph_data, "player",
			mlx_create_sprite_gl("player_moove", 1, 6, (int [2]){192, 192}))
		|| !mlx_addsprite_gl(game->graph_data, "player",
			mlx_create_sprite_gl("player_attack", 2, 6, (int [2]){192, 192})))
		return (0);
	if (!mlx_addanimation_gl(game->graph_data, "player", "player_default",
			mlx_create_animation_gl(mlx_get_image_by_name_gl(game->graph_data,
					"player"), "player_default", 4))
		|| !mlx_addanimation_gl(game->graph_data, "player", "player_moove",
			mlx_create_animation_gl(mlx_get_image_by_name_gl(game->graph_data,
					"player"), "player_moove", 3))
		|| !mlx_addanimation_gl(game->graph_data, "player", "player_attack",
			mlx_create_animation_gl(mlx_get_image_by_name_gl(game->graph_data,
					"player"), "player_attack", 3))
		|| !mlx_object_set_curr_animation_gl(game->graph_data, "player",
			"player_default"))
		return (0);
	return (1);
}

int	graph_addwall(t_game *game)
{
	if (!mlx_addobject_gl(game->graph_data, mlx_create_object_gl("tree", 0, 0,
				NULL)))
		return (0);
	if (!mlx_addimage_gl(game->graph_data, mlx_load_img_gl(game->graph_data,
				"./srcs/sprites/tree.xpm", "tree_animation")))
		return (0);
	if (!mlx_addsprite_gl(game->graph_data, "tree_animation",
			mlx_create_sprite_gl("tree_default", 0, 4, (int [2]){192, 192})))
		return (0);
	if (!mlx_addanimation_gl(game->graph_data, "tree", "tree_default",
			mlx_create_animation_gl(mlx_get_image_by_name_gl(game->graph_data,
					"tree_animation"), "tree_default", 8)))
		return (0);
	if (!mlx_object_set_curr_animation_gl(game->graph_data, "tree",
			"tree_default"))
		return (0);
	return (1);
}

int	graph_addexit(t_game *game)
{
	if (!mlx_addimage_gl(game->graph_data, mlx_load_img_gl(game->graph_data,
				"./srcs/sprites/tower.xpm", "tower")))
		return (0);
	return (1);
}

int	graph_addcollect(t_game *game)
{
	if (!mlx_addobject_gl(game->graph_data, mlx_create_object_gl("sheep", 0, 0,
				NULL)))
		return (0);
	if (!mlx_addimage_gl(game->graph_data, mlx_load_img_gl(game->graph_data,
				"./srcs/sprites/sheep/sheep.xpm", "sheep_animation")))
		return (0);
	if (!mlx_addsprite_gl(game->graph_data, "sheep_animation",
			mlx_create_sprite_gl("sheep_default", 0, 8, (int [2]){128, 128})))
		return (0);
	if (!mlx_addsprite_gl(game->graph_data, "sheep_animation",
			mlx_create_sprite_gl("sheep_jump", 1, 6, (int [2]){128, 128})))
		return (0);
	if (!mlx_addanimation_gl(game->graph_data, "sheep", "sheep_default",
			mlx_create_animation_gl(mlx_get_image_by_name_gl(game->graph_data,
					"sheep_animation"), "sheep_default", 5)))
		return (0);
	if (!mlx_addanimation_gl(game->graph_data, "sheep", "sheep_jump",
			mlx_create_animation_gl(mlx_get_image_by_name_gl(game->graph_data,
					"sheep_animation"), "sheep_jump", 3)))
		return (0);
	if (!mlx_object_set_curr_animation_gl(game->graph_data, "sheep",
			"sheep_default"))
		return (0);
	return (1);
}
