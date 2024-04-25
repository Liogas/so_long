/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_setup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:22:16 by glions            #+#    #+#             */
/*   Updated: 2024/04/25 19:40:08 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_listener(int key, t_game *game)
{
	if (key == XK_Escape)
		mlx_loop_end(game->graph_data->ptr);
	return (0);
}

static int	graph_load_images(t_game *game)
{
	if (!graph_addborder(game))
		return (0);
	if (!graph_addplayer(game))
		return (0);
	if (!graph_addwall(game))
		return (0);
	if (!graph_addexit(game))
		return (0);
	if (!graph_addcollect(game))
		return (0);
	return (1);
}

int	graph_setup(t_game *game)
{
	game->graph_data->window = mlx_create_win_gl(game->graph_data, 1280, 720,
			"window");
	if (!game->graph_data->window)
		return (ft_putstr_fd("ERROR : create window\n", 2), 0);
	if (!graph_load_images(game))
		return (ft_putstr_fd("ERROR : load images\n", 2), 0);
	mlx_print_data_gl(game->graph_data);
	mlx_key_hook(game->graph_data->window->ptr, &key_listener, game);
	mlx_loop(game->graph_data->ptr);
	return (1);
}
